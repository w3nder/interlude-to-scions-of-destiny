"""Verify the distributed patch, or files copied to a client directory."""
import hashlib,json,sys
from pathlib import Path
root=Path(__file__).resolve().parent
base=Path(sys.argv[1]) if len(sys.argv)>1 else root
manifest=json.loads((root/'manifest.json').read_text())
failures=[]
for item in manifest['files']:
 p=base/item['path']
 if not p.is_file() or hashlib.sha256(p.read_bytes()).hexdigest()!=item['sha256']:
  failures.append(item['path'])
engine=base/'system/engine.dll'
if engine.exists() and hashlib.sha256(engine.read_bytes()).hexdigest()!=manifest['required_engine_sha256']:
 failures.append('system/engine.dll (unsupported client base)')
xdat=base/'system/interface.xdat'
if xdat.exists() and manifest.get('required_interface_xdat_sha256') and hashlib.sha256(xdat.read_bytes()).hexdigest()!=manifest['required_interface_xdat_sha256']:
 failures.append('system/interface.xdat (inventory-script-2 requires original Interlude layout)')
if failures:
 print('Verification failed:\n'+'\n'.join(failures));sys.exit(1)
print(f"OK: {len(manifest['files'])} patch files verified.")
