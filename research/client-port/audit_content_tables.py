"""Inventory and decode remaining C4/Interlude DAT tables without installation."""
import concurrent.futures
import hashlib
import json
from pathlib import Path
from extract_asset_tables import ROOT, REF, OUT, extract

MIGRATED = {'itemname-e','weapongrp','armorgrp','etcitemgrp','npcgrp','npcname-e',
            'skillname-e','skillgrp','skillsoundgrp','mobskillanimgrp'}


def main():
    source = ROOT.parent.parent/'system'
    target = Path('/Users/wenderteixeira/Downloads/Lineage2_Interlude_Client/system')
    OUT.mkdir(exist_ok=True)
    inventory = []
    jobs = []
    for file in sorted(source.glob('*.dat')):
        name = file.stem
        definitions = {side:REF/'DAT_defs'/version/(name+'.ddf') for side,version in [('source','C4'),('target','Interlude')]}
        item = {'name':name,'already_migrated':name in MIGRATED,'target_present':(target/file.name).exists(),
                'definitions':{side:p.exists() for side,p in definitions.items()}}
        inventory.append(item)
        if name not in MIGRATED and item['target_present'] and all(item['definitions'].values()):
            for side,version in [('source','C4'),('target','Interlude')]:
                jobs.append((side,name,version))
    def run(job):
        try:
            result = extract(*job)
            if result['exit_code']:
                result['status']='disassembler_error'
            else:
                result['status']='decoded'
                result['tsv_sha256']=hashlib.sha256(Path(result['text']).read_bytes()).hexdigest()
            return result
        except Exception as error:
            return {'side':job[0],'name':job[1],'status':'decode_error','error':str(error)}
    with concurrent.futures.ThreadPoolExecutor(max_workers=3) as pool:
        results = list(pool.map(run,jobs))
    report = {'scope':'Read-only DAT inventory; a decoded table is not automatically safe to replace.',
              'definition_repository':'L2Miko/L2FileEdit','definition_commit':'b83fdcfff8eec0edc93125481db0281ff25a2beb',
              'inventory':inventory,'extractions':results}
    (ROOT/'reports/content-tables.json').write_text(json.dumps(report,indent=2)+'\n')
    print('Tables:',len(inventory),'additional extractions:',len(results),'failed:',sum(r['status']!='decoded' for r in results),flush=True)


if __name__=='__main__':
    main()
