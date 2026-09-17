"""Index DAT object references and Unreal package exports without loading a client."""
import csv,json,re
from pathlib import Path
from collections import defaultdict
from unreal_package_index import Package
from extract_asset_tables import ROOT,OUT
FOLDERS=['system','systextures','textures','animations','staticmeshes','sounds']
EXTS={'.utx','.ukx','.usk','.u','.usx','.uax'}
TARGET=Path('/Users/wenderteixeira/Downloads/Lineage2_Interlude_Client')
def index(base):
 out={}
 for directory in FOLDERS:
  for p in (base/directory).iterdir():
   if p.suffix.casefold() in EXTS:
    out.setdefault(p.stem.casefold(),[]).append(p)
 return out

def references():
 out=defaultdict(list)
 for n in ['weapongrp','armorgrp','etcitemgrp','npcgrp']:
  for r in csv.DictReader((OUT/f'source-{n}-C4.tsv').open(),delimiter='\t',quoting=csv.QUOTE_NONE):
   for k,v in r.items():
    if v and re.match(r'^[A-Za-z_][A-Za-z_0-9]*\.',v):out[v.casefold()].append({'table':n,'id':r.get('id',r.get('tag')),'field':k,'reference':v})
 return out

def main():
 src=index(ROOT.parent.parent);dst=index(TARGET);refs=references();cache={};errors={}
 def package(p):
  if p not in cache:
   try:cache[p]=Package(p)
   except Exception as e:cache[p]=None;errors[str(p)]=str(e)
  return cache[p]
 def exists(paths,obj):
  for p in paths or []:
   pkg=package(p)
   if pkg and (obj in pkg.objects or ('.' not in obj and pkg.leaves[obj]==1)):return p
  return None
 missing=[];need=set();already=0
 for ref,uses in refs.items():
  root,obj=ref.split('.',1)
  if exists(dst.get(root),obj):already+=1;continue
  source_path=exists(src.get(root),obj)
  if source_path:need.add(source_path);missing.append({'reference':ref,'source_package':str(source_path),'resolution':'source_package_required' if root not in dst else 'source_export_missing_in_target','uses':uses})
  else:missing.append({'reference':ref,'resolution':'not_found_in_source_or_target','uses':uses})
 direct=set(need);queue=list(need)
 while queue:
  path=queue.pop();pkg=package(path)
  if not pkg:continue
  for dep in pkg.dependencies:
   dep=dep.casefold()
   if dep in src and dep not in dst:
    for p in src[dep]:
     if p not in need:need.add(p);queue.append(p)
 result={'references':len(refs),'resolved_by_target':already,'packages_needed':[{ 'name':p.stem.casefold(),'source':str(p),'relative':str(p.relative_to(ROOT.parent.parent)),'shared_filename':any(x.suffix.casefold()==p.suffix.casefold() for x in dst.get(p.stem.casefold(),[])),'bytes':p.stat().st_size,'transitive':p not in direct} for p in sorted(need)],'unresolved_or_source_required':missing,'index_errors':errors,'scope':'Export/path or unique leaf resolution; imported object compatibility and visual rendering still require client validation.'}
 (OUT/'dependencies.json').write_text(json.dumps(result,indent=2)+'\n')
 print(json.dumps({'references':len(refs),'resolved_by_target':already,'needed_packages':len(need),'required_bytes':sum(p.stat().st_size for p in need),'shared_packages':[str(p) for p in need if p.stem.casefold() in dst],'missing_references':sum(r['resolution']=='not_found_in_source_or_target' for r in missing),'errors':errors},indent=2))
if __name__=='__main__':main()
