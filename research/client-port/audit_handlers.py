"""Close selector/name gaps and identify literal no-op handlers, without guessing layouts."""
import hashlib,json,struct
from collections import Counter,defaultdict
from pathlib import Path
import pefile
ROOT=Path(__file__).resolve().parent

def classify(pe,va):
    if not va:return {'kind':'unresolved_address'}
    rva=int(va,16)-pe.OPTIONAL_HEADER.ImageBase;raw=pe.get_data(rva,32)
    # Only classify instruction sequences that cannot read packet memory.
    patterns=[bytes.fromhex(h) for h in ['32c0c3','33c0c3','b000c3','c3']]
    for pattern in patterns:
        if raw.startswith(pattern):return {'kind':'proven_no_payload_read','bytes':pattern.hex(),'rva':hex(rva)}
    return {'kind':'requires_control_flow_review','entry_bytes':raw[:16].hex(),'rva':hex(rva)}

def main():
    comparison=json.loads((ROOT/'comparison.json').read_text());policy=json.loads((ROOT/'outbound-policy.json').read_text())
    engines={}
    for side,path in [('source',ROOT.parent.parent/'system/engine.dll'),('target',ROOT/'build/interlude-engine.dll')]:
        raw=path.read_bytes()
        if hashlib.sha256(raw).hexdigest()!=policy[side+'_sha256']:raise ValueError('Unsupported '+side)
        engines[side]=pefile.PE(data=raw,fast_load=True)
    no_layout=[]
    for row in comparison['inbound']:
        if row['status']=='decode_layout_unresolved':
            d={'table':row['table'],'opcode':row['opcode'],'name':row['target']['name']}
            for side in engines:d[side]=classify(engines[side],row[side].get('handler_va'))
            d['resolution']='both_handlers_ignore_payload' if all(d[k]['kind']=='proven_no_payload_read' for k in engines) else 'pending'
            no_layout.append(d)
    ext_source=defaultdict(set);ext_target=defaultdict(set)
    for side,index in [('source_selectors',ext_source),('target_selectors',ext_target)]:
        for row in policy[side]:
            if row['opcode']==0xd0:index[row['name']].add(row['extended'])
    extended=[]
    for name in sorted(ext_source.keys()&ext_target.keys()):
        extended.append({'name':name,'source':sorted(ext_source[name]),'target':sorted(ext_target[name]),'resolved':None not in ext_source[name]|ext_target[name],'same_selector':ext_source[name]==ext_target[name]})
    # Alias candidates by exact wire signature only; do not upgrade semantic status.
    aliases=[]
    for row in comparison['outbound']:
        if row['status']!='source_only_in_extraction':continue
        sig={(r['opcode'],r['format']) for r in row['source']}
        candidates=[r['name'] for r in comparison['outbound'] if sig and sig<={(t['opcode'],t['format']) for t in r['target']}]
        aliases.append({'source':row['name'],'target_candidates':candidates,'status':'wire_signature_candidate' if candidates else 'unresolved'})
    result={'hashes':{k:policy[k+'_sha256'] for k in engines},'empty_layout_audit':no_layout,'extended_selectors':extended,'outbound_aliases':aliases,'summary':dict(Counter(r['resolution'] for r in no_layout))}
    path=ROOT/'reports/handler-audit.json';path.parent.mkdir(exist_ok=True);path.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({k:v for k,v in result.items() if k not in ['empty_layout_audit']},indent=2))
if __name__=='__main__':main()
