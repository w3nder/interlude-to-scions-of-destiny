"""Wrap newly added plaintext UTX packages in Lineage2Ver121; preserve payload."""
import hashlib,json,shutil
from datetime import datetime
from pathlib import Path
from unreal_package_index import Package
ROOT=Path(__file__).resolve().parent
STAGE=ROOT/'build/assets-interlude'
TARGET=Path('/Users/wenderteixeira/Downloads/Lineage2_Interlude_Client')
def digest(b):return hashlib.sha256(b).hexdigest()
def main():
 manifest=STAGE/'assets-manifest.json';m=json.loads(manifest.read_text());changes=[]
 backup=TARGET/('textures.before-ver121-'+datetime.now().strftime('%Y%m%d-%H%M%S'))
 for entry in m['packages']:
  relative=entry['relative'];p=TARGET/relative
  if p.suffix.lower()!='.utx':continue
  raw=p.read_bytes()
  if raw[:4]!=bytes.fromhex('c1832a9e'):continue
  assert digest(raw)==entry['sha256'],str(p)
  before=Package(p);key=sum(p.name.lower().encode('ascii'))&255
  table=bytes(i^key for i in range(256))
  encoded='Lineage2Ver121'.encode('utf-16le')+raw.translate(table)+bytes(20)
  assert encoded[28:-20].translate(table)==raw
  dest=backup/relative;dest.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(p,dest)
  tmp=p.with_suffix('.utx.tmp');tmp.write_bytes(encoded)
  # Filename-dependent decoder must use the final filename.
  tmp.replace(p)
  after=Package(p)
  assert before.exports==after.exports and before.imports==after.imports and before.names==after.names
  staged=STAGE/'files'/relative;staged.write_bytes(encoded)
  entry['source_sha256']=digest(raw);entry['sha256']=digest(encoded);entry['bytes']=len(encoded);entry['container_conversion']='plaintext to Lineage2Ver121; unchanged payload; 20-byte footer'
  changes.append({'relative':relative,'before':digest(raw),'after':digest(encoded)})
 manifest.write_text(json.dumps(m,indent=2)+'\n')
 report={'backup':str(backup),'changes':changes,'validation':'XOR roundtrip and all name/import/export tables identical; live loader validation pending'}
 (ROOT/'build/last-texture-wrapper-update.json').write_text(json.dumps(report,indent=2)+'\n')
 print(json.dumps(report,indent=2))
if __name__=='__main__':main()
