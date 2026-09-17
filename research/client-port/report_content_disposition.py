"""Give every source DAT a disposition and enumerate unavailable source assets."""
import hashlib
import json
from collections import Counter
from pathlib import Path
from extract_asset_tables import ROOT,OUT
from migrate_asset_tables import read
from migrate_content_tables import KEYS,STAGE
from audit_content_tables import MIGRATED

IDENTICAL={'commandname-e':'id','hennagrp-e':'id','recipe-c':'id_mk',
           'symbolname-e':'id','hairaccessorylocgrp':'name'}
NATIVE={'chargrp','classinfo-e','creditgrp-e','eula-e','hairgrp','logongrp',
        'musicinfo','sysstring-e','zonename-e','hairaccessarygrp','helmetgrp'}


def main():
    converted=json.loads((STAGE/'manifest.json').read_text())
    if {r['table'] for r in converted['tables']}!=set(KEYS):raise ValueError('Content migration is not complete')
    inventory=json.loads((ROOT/'reports/content-tables.json').read_text())['inventory']
    dispositions=[]
    for entry in inventory:
        name=entry['name'];row={'table':name}
        if name in MIGRATED:row['disposition']='previously_migrated_items_npcs_skills'
        elif name in KEYS:row['disposition']='migrated_server_content_and_pet_actions'
        elif name in IDENTICAL:
            sh,source=read(OUT/f'source-{name}-C4.tsv');th,target=read(OUT/f'target-{name}-Interlude.tsv')
            key=IDENTICAL[name]
            if key not in sh:raise ValueError('Unreviewed table key: '+name)
            by={r[key]:r for r in target}
            for r in source:
                if r[key] not in by or any(v!=by[r[key]].get(k) for k,v in r.items() if k in th):
                    raise ValueError('Previously identical source row changed: '+name+' '+r[key])
            row.update(disposition='all_source_rows_already_present',source_rows=len(source),key=key)
        elif name in NATIVE:
            row.update(disposition='native_Interlude_configuration_retained',
                       reason='Native UI, geometry, camera, map or regional music configuration; not a server object-ID catalogue.')
            if name in ('hairaccessarygrp','helmetgrp'):
                row['limit']='No DDF available; fixed-record source keys were present in target; target native geometry configuration retained.'
        else:raise ValueError('Unclassified content table: '+name)
        dispositions.append(row)
    assets=json.loads((ROOT/'build/assets-interlude/assets-manifest.json').read_text())
    skills=json.loads((ROOT/'build/skills-interlude/dependencies.json').read_text())
    missing=assets['remaining_references']+skills['unresolved']
    unavailable=[]
    for name in ('L2Killer_Assassin_light.ukx','L2killer_HeadGear.ukx'):
        path=ROOT.parent.parent/'animations'/name;raw=path.read_bytes()
        unavailable.append({'path':'animations/'+name,'bytes':len(raw),'sha256':hashlib.sha256(raw).hexdigest(),
                            'header':raw[:6].hex(),'dependent_references':sum(r['reference'].split('.')[0]==path.stem.casefold() for r in missing)})
    report={'tables':dispositions,'counts':dict(Counter(r['disposition'] for r in dispositions)),
            'converted_content':converted,
            'unreadable_source_containers':unavailable,
            'remaining_asset_references':missing,
            'remaining_reference_count':len(missing),
            'limits':'References are not counts of broken inventory items. Several original NPC skills intentionally or historically reference unavailable icons; exact custom visuals cannot be reconstructed from IDs alone.',
            'required_input_for_exact_missing_visuals':'Readable original packages/exports, or the compatible decoder and key for the two CAFEF00D containers. Supplied executable file-loader evidence is in evidence/file-loader.',
            'validation':'All source DATs have an explicit disposition; shared catalogue rows compared by key; migrated DATs roundtrip and cross-catalogue tests are separate.'}
    (ROOT/'reports/content-disposition.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps({'tables':len(dispositions),'counts':report['counts'],'unavailable_references':len(missing)},indent=2))


if __name__=='__main__':main()
