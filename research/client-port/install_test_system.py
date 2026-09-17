"""Install the reviewed diagnostic system, keeping the existing system."""
from pathlib import Path
import hashlib,json,shutil
from datetime import datetime
from ini_codec import decode
ROOT=Path(__file__).resolve().parent
SOURCE=ROOT/'dist/L2Killer-Interlude-LoginTest'
CLIENT=Path('/Users/wenderteixeira/Downloads/Lineage2_Interlude_Client')
def main():
    manifest=json.loads((SOURCE/'manifest.json').read_text())
    for name,digest in manifest['sha256'].items():
        if hashlib.sha256((SOURCE/'system'/name).read_bytes()).hexdigest()!=digest: raise ValueError(name+' hash mismatch')
    if b'ServerAddr=server.l2killer.org' not in decode((SOURCE/'system/l2.ini').read_bytes()): raise ValueError('Server mismatch')
    stamp=datetime.now().strftime('%Y%m%d-%H%M%S'); stage=CLIENT/('system.l2k-staging-'+stamp)
    def copy(src,dst):Path(dst).write_bytes(Path(src).read_bytes());return str(dst)
    shutil.copytree(SOURCE/'system',stage,copy_function=copy)
    for f in (SOURCE/'system').rglob('*'):
        if f.is_file() and hashlib.sha256(f.read_bytes()).digest()!=hashlib.sha256((stage/f.relative_to(SOURCE/'system')).read_bytes()).digest():raise ValueError(str(f))
    target=CLIENT/'system';backup=CLIENT/('system.before-l2k-'+stamp)
    if target.exists():target.rename(backup)
    try:stage.rename(target)
    except BaseException:
        if backup.exists():backup.rename(target)
        raise
    copy(SOURCE/'LEIA-ME.txt',CLIENT/'L2K-LEIA-ME.txt')
    print(json.dumps({'installed':str(target),'backup':str(backup),'exe':str(target/'l2.exe')},indent=2))
if __name__=='__main__':main()
