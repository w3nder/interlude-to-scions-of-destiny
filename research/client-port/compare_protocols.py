"""Compare static evidence, preserving unknowns instead of claiming compatibility."""
import json
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent


def read(name):
    return json.loads((ROOT / name).read_text())


def signature(rows):
    return sorted(set((r['opcode'], r['format']) for r in rows))


def segments(row):
    return [s['format'] for s in row.get('decode_segments', [])]


def main():
    original = read('L2Killer-opcodes.json')
    source = read('killer-reextracted.json')
    target = read('system-1-opcodes.json')
    assert original['engine_sha256'] == source['engine_sha256']
    old_out = {r['call_va']:r for r in original['outbound_call_sites']}
    new_out = {r['call_va']:r for r in source['outbound_call_sites']}
    assert all(k in old_out and signature([r]) == signature([old_out[k]]) for k,r in new_out.items())
    inbound = lambda d: {(r['table'],r['opcode']):r for r in d['inbound_registrations']}
    old_in, src_in, dst_in = map(inbound, (original,source,target))
    assert len(dst_in) == len(target['inbound_registrations'])
    assert old_in.keys() == src_in.keys()
    assert all(old_in[k]['name'] == src_in[k]['name'] for k in old_in)
    validation = dict(
        source_hash_matches=True,
        outbound_reproduced=len(new_out), outbound_catalog_total=len(old_out),
        outbound_not_recovered_by_export_scan=[old_out[k] for k in sorted(old_out.keys()-new_out.keys())],
        inbound_registration_matches=len(src_in),
        decoder_segment_disagreements=[dict(table=k[0],opcode=k[1],name=old_in[k]['name'],
            original=old_in[k]['decode_segments'], reextracted=src_in[k]['decode_segments'])
            for k in sorted(src_in) if old_in[k]['decode_segments'] and
            {(s['call_va'],s['format']) for s in old_in[k]['decode_segments']} !=
            {(s['call_va'],s['format']) for s in src_in[k]['decode_segments']}])
    src_groups, dst_groups = defaultdict(list), defaultdict(list)
    for r in original['outbound_call_sites']:
        # Export spelling is stable across engines; retain the old display name.
        src_groups[new_out.get(r['call_va'],r)['name']].append(r)
    for r in target['outbound_call_sites']:
        dst_groups[r['name']].append(r)
    outgoing=[]
    for name in sorted(src_groups.keys() | dst_groups.keys()):
        a,b=src_groups[name],dst_groups[name]
        if not a: status='target_only_in_extraction'
        elif not b: status='source_only_in_extraction'
        elif any(r['opcode']=='0xD0' for r in a+b): status='extended_subopcode_unresolved'
        elif signature(a)==signature(b): status='same_observed_opcode_and_format'
        else: status='different_observed_opcode_or_format'
        outgoing.append(dict(name=name,status=status,source=a,target=b))
    incoming=[]
    for k in sorted(src_in.keys() | dst_in.keys()):
        a,b=src_in.get(k),dst_in.get(k)
        if not a: status='target_only_slot'
        elif not b: status='source_only_slot'
        elif a['name']!=b['name']: status='renamed_slot_requires_review'
        elif not segments(a) or not segments(b): status='decode_layout_unresolved'
        elif segments(a)==segments(b): status='same_observed_decode_segments'
        else: status='different_observed_decode_segments'
        incoming.append(dict(table=k[0],opcode=k[1],status=status,source=a,target=b))
    report=dict(scope='Static comparison; no row establishes wire compatibility. Matching names, opcodes or type strings do not prove field semantics. No binaries patched and no live session tested.',
        validation=validation, outbound_summary=dict(Counter(r['status'] for r in outgoing)),
        inbound_summary=dict(Counter(r['status'] for r in incoming)),outbound=outgoing,inbound=incoming)
    (ROOT/'comparison.json').write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps({k:report[k] for k in ['outbound_summary','inbound_summary']},indent=2))
    lines=['# Comparação estática: L2Killer → system-1','',
        'Objetivo: adaptar somente o cliente de destino para o servidor atual do Killer.',
        'Nenhuma alteração de binário ou validação de conexão foi realizada.','',
        '## Cobertura e conferência','',
        f'- Origem: SHA-256 confirmado; {len(old_out)} pontos de envio no catálogo original.',
        f'- Reextração: {len(new_out)} envios reproduzidos com opcode/formato idênticos; '
        'ValidatePosition e VoteSociality não foram recuperados pelo percurso dos exports.',
        f'- Os {len(src_in)} registros de recepção do catálogo foram reproduzidos, com os mesmos nomes e slots.',
        f'- Destino: {len(target["outbound_call_sites"])} pontos de envio e {len(dst_in)} registros de recepção (255 primários, 86 estendidos).',
        f'- {len(validation["decoder_segment_disagreements"])} handlers da origem têm divergências de segmentos em relação ao catálogo antigo; evidência detalhada em comparison.json.',
        '- Exemplo confirmado: o segmento antigo de MoveToLocation em 0x104132ba fica numa rotina posterior, iniciada em 0x10413280 e separada por padding INT3. Não deve ser concatenado ao handler 0x10413120.',
        '- Os limites de função são heurísticos (exports e padding); helpers e formatos construídos dinamicamente podem ficar fora da extração.',
        '- Q lê 8 bytes no decoder do destino: caso 0x1040279b, duas cópias de dword e avanço do cursor por 8. Evidência em decoder-Q-evidence.txt; o significado do campo ainda precisa ser resolvido.',
        '- Ghidra decompilou os handlers UIPacket (0x104342f0) e CIPacket (0x104366f0); arquivos em decompiled/. A inferência de tipos/assinaturas ainda é incompleta.',
        '', '## Referência Interlude fornecida depois', '',
        '`/Users/wenderteixeira/Desktop/C6_System_Win10Supported` foi fornecida pelo usuário como referência original do Interlude.',
        'A engine.dll é idêntica byte por byte à system-1 (SHA-256 508974c711f207402719e92737e211a2f029c95c2f68fc0e1c31fcbb9dbb232d). Os dois catálogos extraídos são idênticos, desconsiderando o caminho de origem.',
        'L2.exe, Core.dll, IpDrv.dll, interface.u e interface.xdat também são idênticos. nwindow.dll difere em dois bytes; Fire.dll tem tamanho e conteúdo diferentes. Isso não autentica nenhuma pasta como distribuição oficial sem alterações.',
        'Inventário detalhado: interlude-reference-inventory.json. Nenhuma das duas pastas foi modificada.', '',
        '## Envios prioritários','',
        '| Método | Killer (opcode: formato) | system-1 (opcode: formato) |',
        '|---|---|---|']
    for name in ['RequestServerList','RequestServerLogin','RequestGameStart','RequestEnterWorldPacket','MoveBackwardToLocation','Action','Atk','RequestUseItem','Say2','ValidatePosition']:
        r=next((r for r in outgoing if r['name']==name),None)
        if r:
            describe=lambda rows: '<br>'.join(f'{op}: `{fmt}`' for op,fmt in signature(rows)) or 'não recuperado'
            lines.append(f'| {name} | {describe(r["source"])} | {describe(r["target"])} |')
    lines += ['', 'Igualdade de opcode e formato é um candidato a reutilização; ainda faltam fase da sessão e significado dos campos.', '',
        'Dos métodos agrupados por nome de export: 172 têm o mesmo opcode/formato observado; 6 têm diferenças; 19 envolvem subopcode estendido ainda não resolvido. Há 32 nomes só na extração do destino e 7 só na origem, o que não prova ausência real de funcionalidade.', '',
        'Os seis métodos com formatos diferentes são ConfirmDlg, RequestEnterWorldPacket, RequestJoinPartyRoom, RequestJoinPledge, RequestMultiSellChoose e RequestPledgePower.', '',
        '## Recepção prioritária','', '| Slot primário | Origem → destino | Formatos observados |','|---|---|---|']
    for op in ['0x01','0x03','0x04','0x13','0x15','0x16','0x1B','0x21','0x27']:
        a,b=src_in.get(('primary',op)),dst_in.get(('primary',op))
        if a and b:
            label='diferentes' if segments(a)!=segments(b) else ('iguais' if segments(a) else 'não resolvidos')
            lines.append(f'| {op} | {a["name"]} → {b["name"]} | {label} |')
    lines += ['', 'MTLPacket, NSPacket, CIPacket e UIPacket são nomes abreviados do destino. A associação pelo slot é uma hipótese de correspondência, não validação de equivalência.', '',
        '## Próximo marco de implementação','',
        '1. Identificar versão enviada, framing, criptografia e transição login/game nas duas engines.',
        '2. Resolver os campos de CharacterSelectionInfo (0x13), CharacterSelected (0x15) e UserInfo/UIPacket (0x04).',
        '3. Localizar interceptação de payload após decriptação e antes do dispatch, e envio antes de encriptação.',
        '4. Implementar e testar conversores com amostras conhecidas; só depois testar login/seleção/entrada no mundo.',
        '5. Prosseguir com CharInfo, NPCs, inventário e movimento; recursos visuais também dependem dos assets do cliente correspondente.', '',
        'Não copiar endereços, vtables ou estruturas de memória do patch C4 para a engine de destino.','']
    (ROOT/'COMPARISON.md').write_text('\n'.join(lines))


if __name__=='__main__':
    main()
