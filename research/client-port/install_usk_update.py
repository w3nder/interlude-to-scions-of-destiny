"""Recover the verified skill-10615 USK package without replacing native files."""
from pathlib import Path
import sys,json,hashlib
sys.path.insert(0,str(Path(__file__).resolve().parent))
from unreal_package_index import Package
from install_assets_update import atomic
from ini_codec import decode
def main():
    root=Path(__file__).resolve().parent;client=Path('/Users/wenderteixeira/Downloads/Lineage2_Interlude_Client');rel=Path('animations/viRUS_Share_Skill2.usk');src=root.parent.parent/rel
    assert hashlib.sha256((client/'system/engine.dll').read_bytes()).hexdigest()=='508974c711f207402719e92737e211a2f029c95c2f68fc0e1c31fcbb9dbb232d'
    raw=src.read_bytes();digest=hashlib.sha256(raw).hexdigest();q=Package(src)
    assert 'virus_icon.l2_11023_skill_i00' in q.objects
    assert b'Paths=../Animations/*.usk' in decode((client/'system/l2.ini').read_bytes())
    assert (client/'animations/LineageEffectMeshes.ukx').is_file()
    for base in [client,root.parent.parent/'patch']:
     dst=base/rel
     if dst.exists():assert hashlib.sha256(dst.read_bytes()).hexdigest()==digest
     else:atomic(src,dst)
     assert Package(dst).objects==q.objects
    entry={'relative':str(rel),'sha256':digest,'bytes':len(raw),'verified_export':'virus_icon.l2_11023_skill_i00','skill_id':10615,'container':'Lineage2Ver121; unchanged source bytes','dependencies':sorted(q.dependencies),'loader_path':'../Animations/*.usk','inherited_missing_imports':['LineageEffectMeshes.warpPointlineUP'],'limits':'Icon export verified; unrelated original mesh import missing in both clients; full rendering not certified'}
    (root/'reports/usk-asset-recovery.json').write_text(json.dumps(entry,indent=2)+'\n');print(json.dumps(entry,indent=2))

if __name__=='__main__':main()
