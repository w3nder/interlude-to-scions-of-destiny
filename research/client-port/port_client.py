"""Repeatable profile pipeline: build, generated tests, coverage, patch artifact.
No server connections and no gameplay automation are performed by this command.
"""
import argparse,csv,hashlib,json,re,shutil,subprocess,sys
from collections import Counter,defaultdict
from datetime import datetime,timezone
from pathlib import Path
ROOT=Path(__file__).resolve().parent
PLEDGE_REQUESTS={'RequestPledgePower','RequestPledgePowerGradeList','RequestPledgeMemberPowerInfo'}

def read(name):return json.loads((ROOT/name).read_text())
def write(path,data):path.write_text(json.dumps(data,indent=2,ensure_ascii=False)+'\n')
def summarize_trace(path):
    groups=defaultdict(lambda:{'count':0,'lengths':set()})
    with path.open(encoding='utf-8') as stream:
        for row in csv.DictReader(stream,delimiter='\t'):
            try:
                key=(row['direction'],row['stage'],int(row['opcode'],16),int(row['extended']));n=int(row['bytes'])
                if key[0] not in ('C2S','S2C') or not 1<=n<=65533:continue
            except (ValueError,TypeError,KeyError):continue # An active file may end in a partial row.
            groups[key]['count']+=1;groups[key]['lengths'].add(n)
    return [dict(direction=k[0],stage=k[1],opcode=f'0x{k[2]:02X}',extended=k[3],count=v['count'],lengths=sorted(v['lengths'])) for k,v in sorted(groups.items())]

def report(validation=None,trace=None):
    comparison=read('comparison.json');policy=read('outbound-policy.json');items=[]
    structured=read('structured-inbound.json')['rules'];outbound=read('outbound-schemas.json')['rules']
    schemas=read('schema-inbound.json')['converters']+structured
    converted_keys={(r['table'],r['opcode']) for r in schemas if r.get('kind','converter')=='converter'}|{('primary',op) for op in ('0x53','0x54','0x55')}
    validated_keys={(r['table'],r['opcode']) for r in structured if r['kind']=='validator'}
    outbound_names={r['name'] for r in outbound}
    outbound_validators=read('outbound-schemas.json').get('validators',[])
    validator_names={r['name'] for r in outbound_validators}
    audit=read('reports/handler-audit.json') if (ROOT/'reports/handler-audit.json').exists() else {}
    wire=read('reports/wire-equivalence.json') if (ROOT/'reports/wire-equivalence.json').exists() else {}
    native_lists=read('reports/native-list-requests.json') if (ROOT/'reports/native-list-requests.json').exists() else {}
    if native_lists and (native_lists.get('status')!='passed' or any(native_lists.get('hashes',{}).get(side)!=policy[side+'_sha256'] for side in ('source','target'))):
        raise ValueError('Native list evidence is stale or failed; rerun test_native_list_requests.py')
    native_list_methods={r['name']:r for r in native_lists.get('methods',[])}
    native_movement=read('reports/native-movement-requests.json') if (ROOT/'reports/native-movement-requests.json').exists() else {}
    if native_movement and (native_movement.get('status')!='passed' or any(native_movement.get('hashes',{}).get(side)!=policy[side+'_sha256'] for side in ('source','target'))):
        raise ValueError('Native movement evidence is stale or failed; rerun test_native_movement_requests.py')

    wire_out={r['name']:r for r in wire.get('outbound',[])}
    wire_in={(r['table'],r['opcode']):r for r in wire.get('inbound',[])}
    ignored={(r['table'],r['opcode']) for r in audit.get('empty_layout_audit',[]) if r['resolution']=='both_handlers_ignore_payload'}
    for r in comparison['outbound']:
        blocked=[p for p in policy['denied'] if p['name']==r['name']]
        items.append(dict(direction='C2S',name=r['name'],static_status=r['status'],implementation='blocked_by_profile' if blocked else 'Interlude_to_C4_converter' if r['name'] in outbound_names else 'bounded_outbound_validator' if r['name'] in validator_names else 'passthrough',test_coverage='selector policy tested' if blocked else 'native send hook fixtures' if r['name'] in outbound_names else 'exact native sender action contracts and pre-send rejection tests' if r['name'] in validator_names else 'not validated per packet'))
    for r in comparison['inbound']:
        source=r.get('source') or {};target=r.get('target') or {};converted=(r['table'],r['opcode']) in converted_keys;validated=(r['table'],r['opcode']) in validated_keys
        items.append(dict(direction='S2C',table=r['table'],opcode=r['opcode'],name=target.get('name',source.get('name','unknown')),static_status=r['status'],implementation='strict_C4_to_Interlude_converter' if converted else 'bounded_layout_validator' if validated else 'passthrough',test_coverage='synthetic structure/bounds fixtures; representative native hook integration; gameplay pending' if converted or validated else 'not validated per packet'))
    for item in items:
        if (item['direction']=='C2S' and item['name'] in PLEDGE_REQUESTS) or (item['direction']=='S2C' and (item['table'],item['opcode'])==('primary','0x30')):
            item['implementation']='contextual_C4_member_permissions_bridge'
            item['test_coverage']='native C4 request serialization, native Interlude queue ABI, state/roster and hook integration; live UI pending'
        if item['direction']=='C2S' and item['name'] in native_movement.get('methods',{}):
            item['native_movement_audit']={'vector_pairs':native_movement['methods'][item['name']], 'evidence':'native-movement-requests.json','limits':native_movement['limits']}
            if item['implementation']=='passthrough':
                item['test_coverage']='matching native C4/Interlude bytes on finite movement and item-drop vectors; branch limits in native-movement-requests.json'
        if item['direction']=='C2S' and item['name'] in native_list_methods:
            native=native_list_methods[item['name']]
            item['native_vector_audit']={'resolution':native['resolution'],'vector_pairs':len(native['cases']),'row_format':native['row_format'],'evidence':'native-list-requests.json'}
            if item['implementation']=='passthrough':
                item['test_coverage']='matching native C4/Interlude bytes on generated lists; finite vectors, not full semantic proof'
        evidence=wire_out.get(item['name']) if item['direction']=='C2S' else wire_in.get((item['table'],item['opcode']))
        if evidence:
            item['wire_audit']=evidence['resolution']
            if item['direction']=='C2S' and item['implementation']=='passthrough' and evidence['resolution']=='same_serializer_argument_contract':
                item['implementation']='native_same_serializer_contract';item['test_coverage']='binary argument dataflow; native parameter-stack helper checks; caller/UI semantics outside this proof'
        if item['direction']=='S2C' and (item['table'],item['opcode']) in ignored:
            item['implementation']='native_handlers_ignore_payload';item['test_coverage']='both exact engine bodies return without reading payload'
    out={'profile':'L2Killer-C4_to_Interlude-508974c7','generated_utc':datetime.now(timezone.utc).isoformat(),
         'source_sha256':policy['source_sha256'],'target_sha256':policy['target_sha256'],
         'validation':validation or {'status':'not run by this invocation'},
         'limits':'Static similarity is not semantic compatibility. Unknown layouts do not produce automatic rewrites. Assets/dat files excluded.',
         'user_observed_working':['login','enter_world','movement','skill_use','chat','clan_information','warehouse'],
         'user_observed_failure':[],
         'schema_converters':schemas,
         'outbound_schema_converters':outbound,
         'outbound_structural_validators':outbound_validators,
         'catalogue_contract':'Opcode equality or matching format strings does not establish compatibility. Conditional reads, raw blocks, field semantics, repetitions and packet direction must be checked against exact engine handlers.',
         'counts':dict(Counter(i['implementation'] for i in items)),
         'release_complete':False,
         'pending_semantic_validation':sum(i['implementation']=='passthrough' for i in items),
         'handler_audit':audit,
         'wire_equivalence_summary':{k:wire.get(k,{}) for k in ('summary','inbound_summary')},
         'native_movement_validation':native_movement,
         'native_list_validation':{k:native_lists.get(k) for k in ('status','method_count','vector_pairs','scope','limits')},
         'runtime_installation':read('build/current-runtime.json') if (ROOT/'build/current-runtime.json').exists() else {'status':'not inspected'},
         'member_permissions_bridge':{'requests':sorted(PLEDGE_REQUESTS),'response':'0x30 C4 32-byte bitset','evidence':'pledge-members-build12.md','rank_semantics':'local per-member editor; no fabricated C4 ranks'},
         'blocked_features':[p for p in policy['denied'] if p['name'] not in PLEDGE_REQUESTS],
         'fallback_policy_guards':policy['denied'],'packets':items}
    if trace:out['observed_game_trace']=summarize_trace(trace)
    directory=ROOT/'reports';directory.mkdir(exist_ok=True);write(directory/'coverage.json',out)
    lines=['# Migração automática — perfil Killer C4 → Interlude','',
           'O gerador aplica somente regras explícitas deste par de builds. Sem teste individual por pacote, sem afirmar compatibilidade total.','',
           f"Verificação desta execução: {out['validation'].get('status')}",
           f"Unidades inventariadas: {len(items)} (métodos de envio + slots de recepção; não é contagem de schemas únicos).",'',
           '## Regras implementadas','',
           '- Login C4 integrado; já validado em jogo na build anterior.',
           '- Recepção 0x53, 0x54 e 0x55: listas/membros de clã C4 convertidos ao layout Interlude.',
           '- Pacotes de clã que já têm o layout Interlude são preservados.',
           f"- {len(out['blocked_features'])} solicitações exclusivas do Interlude bloqueadas antes da cifra/envio; outras duas são atendidas pela interface local de permissões por membro.",
           f"- {len(converted_keys)} conversores S2C, {len(outbound)} conversores C2S e {len(validated_keys)} validador estrutural. Detalhes e variantes em schema-inbound.json, structured-inbound.json e outbound-schemas.json.",
           '- Testes estruturais não validam por si só significado de campos nem comportamento de todas as telas.',
           '- Permissões de clã: C0/D0:1A/D0:1B abrem consulta/edição por membro; o envio usa C0 C4 e preserva o bitset de 32 bytes. Resposta 30 legada alimenta a interface local. Veja pledge-members-build12.md.',
           '- Cifra nativa de game preservada; trace registra apenas opcode, tamanho e decisão.',
           '- Demais pacotes continuam no caminho original. Nenhuma conversão baseada apenas no tamanho.',
           f"- Auditoria dos argumentos C2S: {wire.get('summary',{}).get('same_serializer_argument_contract',0)} métodos equivalentes no serializador; não precisam de conversão nesse limite.",
           f"- Listas C2S: {native_lists.get('method_count',0)} métodos comparados nos dois binários em {native_lists.get('vector_pairs',0)} pares de vetores; bytes iguais nos casos testados, sem nova conversão. Evidência: native-list-requests.json.",
           '- Evidências completas em wire-equivalence.json. Mesmos decoders S2C não provam condições, repetições ou semântica iguais.',
           '- Contagem de conversores descreve o código candidato; consulte runtime_installation para a DLL realmente instalada.','',
           '## Categorias da extração estática (não são contagens de falhas)','', '| Categoria estática | Quantidade |','|---|---|']
    for status,n in sorted(Counter(i['static_status'] for i in items).items()):lines.append(f'| {status} | {n} |')
    lines+=['','Detalhamento por pacote em coverage.json. Tráfego observado prova ocorrência, não correção semântica.',
            'Funções novas sem regra confirmada permanecem pendentes; o catálogo estático não é prova de ausência no C4.','']
    (directory/'coverage.md').write_text('\n'.join(lines));return out

def run(args):
    print('+ '+' '.join(map(str,args)),flush=True);subprocess.run(args,cwd=ROOT.parent.parent,check=True)

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('action',choices=['report','check','package']);parser.add_argument('--trace',type=Path);parser.add_argument('--require-complete',action='store_true',help='Refuse release while any packet lacks verified semantic coverage');args=parser.parse_args()
    validation=None
    if args.action in ('check','package'):
        run([sys.executable,ROOT/'derive_outbound_policy.py']);run([sys.executable,ROOT/'native/build.py'])
        test=subprocess.run([sys.executable,'-m','unittest','discover','-s',str(ROOT),'-p','test_*.py','-v'],cwd=ROOT.parent.parent,text=True,capture_output=True)
        output=test.stdout+test.stderr;(ROOT/'build/test-results.txt').write_text(output);print(output,flush=True)
        if test.returncode:raise SystemExit(test.returncode)
        match=re.search(r'Ran (\d+) tests',output);validation={'status':'passed','unittest_cases':int(match[1]) if match else None,'results':'build/test-results.txt'}
        run([sys.executable,ROOT/'audit_handlers.py']);run([sys.executable,ROOT/'audit_wire_equivalence.py'])
    coverage=report(validation,args.trace)
    if args.require_complete and not coverage['release_complete']:
        raise SystemExit('Complete release refused: unresolved packet semantics remain; see coverage.json')
    if args.action=='package':
        build_hash=hashlib.sha256((ROOT/'build/L2KProtocolCore.dll').read_bytes()).hexdigest();dest=ROOT/'dist'/('L2Killer-ProtocolPatch-'+build_hash[:8]);dest.mkdir(parents=True,exist_ok=True)
        for src,name in [(ROOT/'build/L2KProtocolCore.dll','L2KProtocolCore.dll'),(ROOT/'reports/coverage.json','coverage.json'),(ROOT/'reports/coverage.md','coverage.md'),(ROOT/'outbound-policy.json','outbound-policy.json'),(ROOT/'schema-inbound.json','schema-inbound.json'),(ROOT/'structured-inbound.json','structured-inbound.json'),(ROOT/'outbound-schemas.json','outbound-schemas.json')]:shutil.copyfile(src,dest/name)
        write(dest/'manifest.json',{'build':'protocol-hooks-12-clan-members','dll_sha256':build_hash,'required_engine_sha256':coverage['target_sha256'],'requires':'existing l2.exe autoload bootstrap from LoginTest build','validation':validation})
        (dest/'LEIA-ME.txt').write_text('Atualizacao para a system LoginTest ja instalada.\nA DLL inclui conversores S2C/C2S e validacao de parametros de mensagens; bloqueia 26 pedidos exclusivos do Interlude e atende duas consultas de permissao pela interface local de membros. Consulte os catalogos incluidos para estruturas, condicoes e limitacoes.\nCifra do jogo preservada. Limite: academias/subunidades e demais recursos novos nao passam a existir no servidor C4.\nO gerador ainda nao adapta todos os pacotes. Consulte coverage.json.\nO trace L2KGameTrace-<PID>-<tick>.tsv permite classificar o trafego sem gravar payloads/credenciais/chat.\nA instalacao atomica pelo install_protocol_update.py preserva a DLL anterior; vale na proxima abertura.\n')
        archive=shutil.make_archive(str(dest),'zip',dest.parent,dest.name);print('PACKAGE '+archive)
    print('REPORT '+str(ROOT/'reports/coverage.md'))
if __name__=='__main__':main()
