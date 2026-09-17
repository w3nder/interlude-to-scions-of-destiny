"""Join whitelisted live catalogue IDs with the migrated DATs; no raw packets."""
import argparse,csv,json
from collections import defaultdict
from pathlib import Path
ROOT=Path(__file__).resolve().parent
STAGE=ROOT/'build/assets-interlude'
SYSTEM=Path('/Users/wenderteixeira/Downloads/Lineage2_Interlude_Client/system')
def table(name,key):
 d=defaultdict(list)
 with (STAGE/(name+'.tsv')).open() as f:
  for r in csv.DictReader(f,delimiter='\t',quoting=csv.QUOTE_NONE):d[int(r[key])].append(r)
 return d

def main():
 ap=argparse.ArgumentParser();ap.add_argument('--trace',type=Path);args=ap.parse_args()
 traces=list(SYSTEM.glob('L2KAssetAudit-*.tsv'));trace=args.trace or (max(traces,key=lambda p:p.stat().st_mtime) if traces else None)
 if not trace:print('No asset audit yet; installed DLL starts this log on next game launch.');return
 names=table('itemname-e','id');npcs=table('npcname-e','id');npcmodels=table('npcgrp','tag')
 groups={n:table(n,'id') for n in ['weapongrp','armorgrp','etcitemgrp']};rows=[]
 with trace.open() as f:
  for r in csv.DictReader(f,delimiter='\t'):
   try:kind=int(r['kind']);id_=int(r['catalogue_id']);int(r['layout'])
   except (ValueError,KeyError,TypeError):continue
   if kind==2:
    result={'observation':r,'names':[a['name'] for a in npcs.get(id_,[])],'models':[{'class':a['class'],'mesh':a['mesh']} for a in npcmodels.get(id_,[])],'missing_name':id_ not in npcs,'missing_model':id_ not in npcmodels}
   else:
    candidates=[{'table':name,'icon':a['icon[0]']} for name,g in groups.items() for a in g.get(id_,[])]
    result={'observation':r,'names':[a['name'] for a in names.get(id_,[])],'candidates':candidates,'missing_name':id_ not in names,'missing_group':not candidates,'blank_icons':bool(candidates) and all(not a['icon'] for a in candidates)}
   rows.append(result)
 report={'trace':str(trace),'observations':len(rows),'catalogue_missing':sum(any(r.get(k,False) for k in ['missing_name','missing_model','missing_group','blank_icons']) for r in rows),'rows':rows,'scope':'Catalogue lookup only. Multiple source definitions retained; class/type and live rendering determine selected entry. No screenshot/rendering validation is claimed.'}
 (ROOT/'reports/live-assets.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k!='rows'},indent=2))
if __name__=='__main__':main()
