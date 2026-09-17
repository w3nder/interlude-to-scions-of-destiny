"""Atomically replace only the adapter DLL; preserve the running inode and backup."""
import argparse,hashlib,json,os
from datetime import datetime
from pathlib import Path
import pefile
ROOT=Path(__file__).resolve().parent
BASELINE='98dffa5f4388bebcdd014515747ed863a716a7e00244494c49c7135659f230a8'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    ap=argparse.ArgumentParser();ap.add_argument('package',type=Path);ap.add_argument('--system',type=Path,default=Path('/Users/wenderteixeira/Downloads/Lineage2_Interlude_Client/system'));args=ap.parse_args()
    meta=json.loads((args.package/'manifest.json').read_text());system=args.system
    if meta.get('validation',{}).get('status')!='passed':raise SystemExit('Package has no passing validation')
    if sha(system/'engine.dll')!=meta['required_engine_sha256']:raise SystemExit('Unsupported engine')
    pe=pefile.PE(data=(system/'l2.exe').read_bytes())
    if not any(d.dll.lower()==b'l2kprotocolcore.dll' for d in pe.DIRECTORY_ENTRY_IMPORT):raise SystemExit('Executable lacks bootstrap import')
    source=args.package/'L2KProtocolCore.dll';current=system/source.name
    if meta['dll_sha256']=='6f710c50cac23556bc6a8212718be31ab01705dc69851b7fd50f369e953e25dc':raise SystemExit('Withdrawn build: CharacterSelected world-entry regression')
    if sha(source)!=meta['dll_sha256']:raise SystemExit('Package hash mismatch')
    old_hash=sha(current)
    if old_hash==meta['dll_sha256']:print('Already installed');return
    if old_hash not in (BASELINE,'dec548b422f90a05c8e2279155e27fc72ee23682fa3307ec2d1e55eb8cc73c3d','ec355d32587c3b516d228011d76ead08a0592e0a018e46aedf63c03dd6a079d0','055de034de5d394040f50866ea5c5d544922dd41d37c4360c011fe3947b71f02','d7e10bcc6392f0d0a0d9586c3f6ab9f31f790458403bdcb14302194d95f5a52e','41f8f3308f86009c06209c2f4f582612e48f6a6f72cbe62d0ba65db2710a47ac','3fcef81e7f3d07f97f94a7f02b9fc29f558339f8df0e1f27c5ccd8097a30b706','f88387f99dc84d3c5e5ad4a83af3546afaaddd7de97c0c8688c8feaeef222f9c','c9c3bd7dd27b947e2859d8ca1c0054ecccd003e9ad1c5940cb0b11fdbfd32920','834676a5f178374ef062b5592b472625ee153b53852b2bacf2061196965fd8a5','9bd942c569776bc94f756f41e7778a0db0c253f343ad50b16e60a715a09a250b'):raise SystemExit('Current DLL differs from the validated baseline; preserve it for review')
    stamp=datetime.now().strftime('%Y%m%d-%H%M%S');backup=system/('L2KProtocolCore.before-protocol-'+stamp+'.dll')
    backup.write_bytes(current.read_bytes())
    if sha(backup)!=old_hash:raise SystemExit('Backup mismatch')
    staging=system/'L2KProtocolCore.next.dll'
    if staging.exists():raise SystemExit('Staging file already exists')
    with staging.open('xb') as f:f.write(source.read_bytes());f.flush();os.fsync(f.fileno())
    if sha(staging)!=meta['dll_sha256']:raise SystemExit('Staged hash mismatch')
    os.replace(staging,current)
    if sha(current)!=meta['dll_sha256']:raise SystemExit('Installed hash mismatch')
    record={'installed':str(current),'build':meta['build'],'sha256':sha(current),'backup':str(backup),'activation':'next client process; running game is not modified'}
    (ROOT/'build/last-update.json').write_text(json.dumps(record,indent=2)+'\n');print(json.dumps(record,indent=2))
if __name__=='__main__':main()
