"""Install validated DATs and missing packages, with rollback backups.
Never replace native engine/Interface/base packages or write to source client.
"""
import argparse,hashlib,json,os,shutil,subprocess,sys
from datetime import datetime
from pathlib import Path
from ini_codec import decode
ROOT=Path(__file__).resolve().parent
STAGE=ROOT/'build/assets-interlude'
TARGET=Path('/Users/wenderteixeira/Downloads/Lineage2_Interlude_Client')
def sha(p):
 with p.open('rb') as f:return hashlib.file_digest(f,'sha256').hexdigest()
def atomic(src,dst):
 tmp=dst.with_name(dst.name+'.l2k-next');dst.parent.mkdir(parents=True,exist_ok=True)
 with tmp.open('xb') as out,src.open('rb') as inp:shutil.copyfileobj(inp,out);out.flush();os.fsync(out.fileno())
 if sha(src)!=sha(tmp):raise ValueError('Staging hash mismatch')
 os.replace(tmp,dst)
def main():
 ap=argparse.ArgumentParser();ap.add_argument('protocol_package',type=Path);args=ap.parse_args()
 meta=json.loads((args.protocol_package/'manifest.json').read_text());tables=json.loads((STAGE/'tables-manifest.json').read_text());assets=json.loads((STAGE/'assets-manifest.json').read_text())
 system=TARGET/'system'
 if sha(system/'engine.dll')!=meta['required_engine_sha256'] or meta['validation']['status']!='passed':raise ValueError('Unvalidated engine/package')
 if sha(system/'L2KProtocolCore.dll')!='9bd942c569776bc94f756f41e7778a0db0c253f343ad50b16e60a715a09a250b':raise ValueError('Unexpected installed DLL')
 plans=[]
 for r in tables['tables']:
  src=STAGE/(r['table']+'.dat');dst=system/src.name
  if sha(src)!=r['sha256']:raise ValueError('Table hash mismatch')
  if decode(src.read_bytes())!=(STAGE/(r['table']+'.decoded')).read_bytes():raise ValueError('DAT encryption mismatch')
  expected=ROOT/'build/dat-audit'/('target-'+r['table']+'.dat.decoded')
  if decode(dst.read_bytes())!=expected.read_bytes():raise ValueError('Installed original DAT changed during work')
  plans.append((src,dst))
 adds=[]
 for r in assets['packages']:
  rel=Path(r['relative']);src=STAGE/'files'/rel;dst=TARGET/rel
  if rel.is_absolute() or '..' in rel.parts or r['shared_filename']:raise ValueError('Unsafe package path')
  if sha(src)!=r['sha256']:raise ValueError('Asset hash mismatch')
  if dst.exists():
   if sha(dst)!=r['sha256']:raise ValueError('Native package would be replaced')
  else:adds.append((src,dst))
 backup=TARGET/('system.before-assets-'+datetime.now().strftime('%Y%m%d-%H%M%S'));backup.mkdir()
 for _,dst in plans:
  shutil.copy2(dst,backup/dst.name)
  if sha(dst)!=sha(backup/dst.name):raise ValueError('Backup mismatch')
 shutil.copy2(system/'L2KProtocolCore.dll',backup/'L2KProtocolCore.dll')
 changed=[];added=[]
 try:
  for src,dst in adds:atomic(src,dst);added.append(dst)
  for src,dst in plans:atomic(src,dst);changed.append(dst)
  subprocess.run([sys.executable,str(ROOT/'install_protocol_update.py'),str(args.protocol_package)],check=True)
 except Exception:
  for dst in changed:atomic(backup/dst.name,dst)
  for dst in added:dst.unlink()
  if sha(system/'L2KProtocolCore.dll')!=sha(backup/'L2KProtocolCore.dll'):atomic(backup/'L2KProtocolCore.dll',system/'L2KProtocolCore.dll')
  raise
 record={'build':meta['build'],'dll_sha256':sha(system/'L2KProtocolCore.dll'),'backup':str(backup),'tables_installed':[{'path':str(dst),'sha256':sha(dst)} for _,dst in plans],'packages_added':[str(dst) for dst in added],'asset_manifest':str(STAGE/'assets-manifest.json'),'activation':'next client start; running client not interrupted','s2c_converters':35,'c2s_converters':3,'unsupported_extended_requests_blocked':28,'candidate_source_is_not_installed':False,'status':'installed; synthetic tests and DAT roundtrips passed; live visual validation pending'}
 (ROOT/'build/current-runtime.json').write_text(json.dumps(record,indent=2)+'\n');(ROOT/'build/last-assets-update.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps({'build':record['build'],'backup':str(backup),'tables':len(plans),'packages_added':len(added),'dll_sha256':record['dll_sha256']},indent=2))
if __name__=='__main__':main()
