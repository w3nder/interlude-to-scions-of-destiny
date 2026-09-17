"""Check skill icon/sound package exports without modifying native packages."""
import json,re
from collections import defaultdict
from audit_asset_dependencies import index,TARGET
from extract_asset_tables import ROOT,OUT
from migrate_asset_tables import read
from unreal_package_index import Package

def main():
 src=index(ROOT.parent.parent);dst=index(TARGET);cache={};errors={}
 def has(paths,obj):
  for p in paths or []:
   if p not in cache:
    try:cache[p]=Package(p)
    except Exception as e:cache[p]=None;errors[str(p)]=str(e)
   q=cache[p]
   if q and (obj in q.objects or ('.' not in obj and q.leaves[obj]==1)):return p
 refs=defaultdict(list)
 for name in ['skillgrp','skillsoundgrp']:
  _,rows=read(OUT/f'source-{name}-C4.tsv')
  for row in rows:
   for field,value in row.items():
    if name=='skillgrp' and field!='icon_name':continue
    if re.match(r'^[A-Za-z_][A-Za-z_0-9]*\.',value):refs[value.casefold()].append({'table':name,'id':row['skill_id'],'level':row['skill_level'],'field':field})
 missing=[];resolved=0
 for ref,uses in refs.items():
  stem,obj=ref.split('.',1)
  if has(dst.get(stem),obj):resolved+=1;continue
  found=has(src.get(stem),obj)
  missing.append({'reference':ref,'uses':uses,'source_file':str(found) if found else None,'target_same_package_exists':stem in dst})
 result={'references':len(refs),'resolved_in_installed_client':resolved,'unresolved':missing,'errors':errors,'scope':'Icon and sound export lookup only; skill effect descriptor semantics and rendering not validated.'}
 (ROOT/'build/skills-interlude/dependencies.json').write_text(json.dumps(result,indent=2)+'\n')
 print(json.dumps({'references':len(refs),'resolved':resolved,'unresolved':len(missing),'source_files':sorted({x['source_file'] for x in missing if x['source_file']}),'errors':errors},indent=2))
if __name__=='__main__':main()
