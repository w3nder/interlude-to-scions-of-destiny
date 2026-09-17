"""Join binary and native execution evidence for every C4 send method."""
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parent


def load_evidence(filename,policy):
    report=json.loads((ROOT/'reports'/filename).read_text())
    hashes=report.get('hashes') or {r['side']:r['sha256'] for r in report.get('results',[])}
    if report.get('status')!='passed' or any(hashes.get(side)!=policy[side+'_sha256'] for side in ('source','target')):
        raise ValueError('Failed/stale native evidence: '+filename)
    return report


def enrich(items,policy):
    branches=load_evidence('native-branch-requests.json',policy)
    login=load_evidence('native-login-senders.json',policy)
    vehicles=load_evidence('native-vehicle-senders.json',policy)
    macro=load_evidence('native-macro-requests.json',policy)
    legacy=load_evidence('native-legacy-abi.json',policy)
    for item in items:
        if item['direction']!='C2S':continue
        name=item['name'];proof=[]
        if name in branches['methods']:
            proof.append({'file':'native-branch-requests.json','vector_pairs':len(branches['methods'][name]),'limits':branches['limits']})
        if name in ('RequestServerList','RequestServerLogin','ResponseAuthGameGuard','EnterWorld'):
            proof.append({'file':'native-login-senders.json','scope':login['scope']})
        if name in ('MoveToLocation','CanNotMoveAnymore'):
            proof.append({'file':'native-vehicle-senders.json','vector_pairs':len(vehicles['cases']),'limits':vehicles['limits']})
        if name==macro['method']:
            proof.append({'file':'native-macro-requests.json','vector_pairs':len(macro['cases']),'scope':macro['scope']})
        if proof:
            item['additional_native_evidence']=proof
        if item['implementation']=='passthrough' and (proof or item.get('native_vector_audit') or item.get('native_movement_audit')):
            item['implementation']='native_differentially_checked_passthrough'
            item['test_coverage']='native byte comparisons on documented finite inputs; not universal UI or server validation'
        if name=='EnterWorld':
            item['implementation']='native_world_signal_suffix_checked'
            item['test_coverage']='fixed send suffix matches; complete entry path also user-observed working, not exhaustively emulated'
        if name in legacy['methods']:
            item['implementation']='inherited_native_vararg_quirk'
            item['test_coverage']=legacy['scope']+' '+legacy['limits']
    return {'branch_methods':branches['method_count'],'branch_vector_pairs':branches['vector_pairs'],
            'macro_vector_pairs':len(macro['cases']),'vehicle_vector_pairs':len(vehicles['cases']),
            'inherited_abi_quirks':legacy['methods']}
