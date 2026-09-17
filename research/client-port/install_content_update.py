"""Install verified server-content tables with atomic rollback backups."""
import argparse
import hashlib
import json
import shutil
from datetime import datetime
from pathlib import Path
from ini_codec import decode
from install_assets_update import atomic
from migrate_content_tables import ROOT, OUT, STAGE, KEYS


def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--client',type=Path,default=Path('/Users/wenderteixeira/Downloads/Lineage2_Interlude_Client'))
    args=parser.parse_args();system=args.client/'system'
    policy=json.loads((ROOT/'outbound-policy.json').read_text())
    if sha(system/'engine.dll')!=policy['target_sha256']:raise ValueError('Unsupported target engine')
    manifest=json.loads((STAGE/'manifest.json').read_text())
    if {r['table'] for r in manifest['tables']}!=set(KEYS):raise ValueError('Incomplete content stage')
    plans=[]
    for entry in manifest['tables']:
        name=entry['table'];src=STAGE/(name+'.dat');dst=system/src.name
        if sha(src)!=entry['sha256']:raise ValueError('Stage hash mismatch: '+name)
        if decode(src.read_bytes())!=(STAGE/(name+'.decoded')).read_bytes():raise ValueError('DAT roundtrip mismatch')
        if sha(dst)==entry['sha256']:continue
        baseline=OUT/f'target-{name}.dat.decoded'
        if decode(dst.read_bytes())!=baseline.read_bytes():raise ValueError('Installed content differs from audited baseline: '+name)
        plans.append((src,dst))
    backup=args.client/('system.before-content-'+datetime.now().strftime('%Y%m%d-%H%M%S'))
    if plans:
        backup.mkdir()
        for _,dst in plans:
            shutil.copy2(dst,backup/dst.name)
            if sha(dst)!=sha(backup/dst.name):raise ValueError('Backup mismatch')
    changed=[]
    try:
        for src,dst in plans:atomic(src,dst);changed.append(dst)
        for entry in manifest['tables']:
            if sha(system/(entry['table']+'.dat'))!=entry['sha256']:raise ValueError('Installed hash mismatch')
    except Exception:
        for dst in reversed(changed):atomic(backup/dst.name,dst)
        raise
    record={'status':'installed','tables':manifest['tables'],'backup':str(backup) if plans else None,
            'activation':'next client start; active game not interrupted','protocol_dll_sha256':sha(system/'L2KProtocolCore.dll')}
    (ROOT/'build/last-content-update.json').write_text(json.dumps(record,indent=2)+'\n')
    (ROOT/'reports/content-migration.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(json.dumps({'installed':len(plans),'verified':len(manifest['tables']),'backup':record['backup']},indent=2))


if __name__=='__main__':main()
