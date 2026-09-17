"""Install verified skill DATs, backup, and refresh the distributable patch."""
import hashlib,json,shutil
from datetime import datetime
from pathlib import Path
from extract_asset_tables import ROOT,OUT
from ini_codec import decode
from migrate_asset_tables import read
from unreal_package_index import Package
TARGET=Path('/Users/wenderteixeira/Downloads/Lineage2_Interlude_Client')
STAGE=ROOT/'build/skills-interlude'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 m=json.loads((STAGE/'manifest.json').read_text());patch=ROOT.parent.parent/'patch'
 pm=json.loads((patch/'manifest.json').read_text())
 assert sha(TARGET/'system/engine.dll')==pm['required_engine_sha256']
 for x in m['tables']:
  name=x['table'];assert sha(STAGE/(name+'.dat'))==x['sha256']
  assert decode((TARGET/'system'/(name+'.dat')).read_bytes())==(OUT/('target-'+name+'.dat.decoded')).read_bytes(),'Installed baseline changed '+name
 # Anti Buff names and visuals are both present, using existing target icons.
 _,names=read(STAGE/'skillname-e.tsv');_,groups=read(STAGE/'skillgrp.tsv')
 icons=Package(TARGET/'systextures/Icon.utx')
 for id_ in ['9709','50012','50050']:
  assert any(x['id']==id_ and x['level']=='1' for x in names)
  row=next(x for x in groups if x['skill_id']==id_ and x['skill_level']=='1')
  leaf=row['icon_name'].split('.',1)[1].casefold();assert leaf in icons.objects or icons.leaves[leaf]==1
 dependencies=json.loads((STAGE/'dependencies.json').read_text());packages=[]
 for source in sorted({x['source_file'] for x in dependencies['unresolved'] if x['source_file']}):
  src=Path(source);relative=str(src.relative_to(ROOT.parent.parent));dest=TARGET/relative
  if dest.exists():raise ValueError('Refusing native package replacement '+relative)
  before=Package(src);assert before.dependencies <= {'Core','Engine'},'Review transitive imports'
  raw=src.read_bytes()
  if before.offset==0:
   key=sum(src.name.lower().encode('ascii'))&255
   encoded='Lineage2Ver121'.encode('utf-16le')+raw.translate(bytes(i^key for i in range(256)))+bytes(20)
   assert encoded[28:-20].translate(bytes(i^key for i in range(256)))==raw
  else:encoded=raw
  stage=STAGE/'files'/relative;stage.parent.mkdir(parents=True,exist_ok=True);stage.write_bytes(encoded)
  after=Package(stage);assert before.exports==after.exports and before.names==after.names
  packages.append((relative,stage))
 backup=TARGET/('system.before-skills-'+datetime.now().strftime('%Y%m%d-%H%M%S'));backup.mkdir()
 installed=[];added=[]
 try:
  for relative,stage in packages:
   dest=TARGET/relative;shutil.copy2(stage,dest);added.append(dest)
  for x in m['tables']:
   filename=x['table']+'.dat';dest=TARGET/'system'/filename
   shutil.copy2(dest,backup/filename);temp=dest.with_suffix('.dat.new');shutil.copyfile(STAGE/filename,temp);temp.replace(dest);installed.append(filename)
   assert sha(dest)==x['sha256']
 except BaseException:
  for filename in installed:shutil.copy2(backup/filename,TARGET/'system'/filename)
  for dest in added:dest.unlink()
  raise
 for x in m['tables']:
  relative='system/'+x['table']+'.dat';dest=patch/relative;shutil.copy2(STAGE/(x['table']+'.dat'),dest)
  pm['files']=[f for f in pm['files'] if f['path']!=relative]+[{'path':relative,'bytes':dest.stat().st_size,'sha256':sha(dest)}]
 for relative,stage in packages:
  dest=patch/relative;dest.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(stage,dest)
  pm['files']=[f for f in pm['files'] if f['path']!=relative]+[{'path':relative,'bytes':dest.stat().st_size,'sha256':sha(dest)}]
 pm['skills_update']='Four skill DATs merged and roundtrip verified; Anti Buff IDs 9709/50012/50050 icons resolve. Live testing pending.'
 (patch/'manifest.json').write_text(json.dumps(pm,indent=2)+'\n')
 result={'backup':str(backup),'tables':m['tables'],'packages_added':[relative for relative,stage in packages],'activation':'Next client start; active session not interrupted','live_validation':'pending'}
 (ROOT/'build/last-skills-update.json').write_text(json.dumps(result,indent=2)+'\n')
 print(json.dumps({'backup':str(backup),'installed':installed},indent=2))
if __name__=='__main__':main()
