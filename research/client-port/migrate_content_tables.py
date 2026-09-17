"""Stage server-referenced C4 content in Interlude schemas; never install here."""
import hashlib
import json
import re
from pathlib import Path
from extract_asset_tables import ROOT, OUT, run_tool, win
from migrate_asset_tables import read, write
from ini_codec import decode, encode

STAGE = ROOT/'build/content-interlude'
KEYS = {'systemmsg-e':['id'], 'questname-e':['quest_id','quest_prog'],
        'entereventgrp':['id'], 'staticobject-e':['id'],
        'servername-e':['server_id'], 'castlename-e':['tag','id'], 'actionname-e':['id']}
QUEST_RENAMES = {'UNK_npc1_?':'lvl_min','UNK_npc2_?':'lvl_max','UNK_npc3_?':'quest_type',
                 'UNK_0':'get_item_in_quest','UNK_3':'contact_npc_id',
                 'entity_x_?':'contact_npc_x','entity_y_?':'contact_npc_y','entity_z_?':'contact_npc_z',
                 'race_restricion':'restricions'}
GROUP_TYPES = {'1':'battle','2':'server','3':'damage','4':'popup','5':'error','6':'petition','7':'useitems'}


def quest_field(name):
    if name.startswith('tab1['): return name.replace('tab1[','items[',1)
    if name.startswith('tab2['): return name.replace('tab2[','num_items[',1)
    return QUEST_RENAMES.get(name,name)


def convert_row(name, source, target, headers):
    # Every source key exists in the pinned target except NPC entry events.
    # Missing base rows in differing schemas need explicit new-field rules.
    if target is None and name in ('questname-e','systemmsg-e'):
        raise ValueError('New source key requires target defaults: '+name)
    out = {field:(target or {}).get(field,'') for field in headers}
    if name=='actionname-e':
        # Source replaces the counted eligibility list, including its padding.
        # Do not retain extra target entries beyond the source count.
        for field in headers:
            if field.startswith('c['):out[field]=''
    for key,value in source.items():
        dest = quest_field(key) if name=='questname-e' else key
        if name=='systemmsg-e':
            if key.startswith('rgb['): dest=key.replace('rgb[','rgba[',1)
            if key=='UNK_1': dest='rgba[3]'; value=f'{int(value)&255:X}'
            if key=='sys_msg_ref':
                value=re.sub(r'^(a,|u,)SystemMsg_[ek]\.',r'\1',value)
        if dest not in out:
            # Exported TSV matrix padding can differ with observed maximum
            # count. An actual value may never be discarded as mere padding.
            if value: raise ValueError(f'Unmapped content field {name}.{key}')
            continue
        out[dest]=value
    if name=='systemmsg-e':
        if source['group'] in GROUP_TYPES:
            out['type']='a,'+GROUP_TYPES[source['group']]+'\\0'
        elif source['group']=='0' and target['group']!='0':
            out['type']='a,none\\0'
        source_vars=set(re.findall(r'\$[a-z](\d+)',source['message'],re.I))
        extra_vars=set(re.findall(r'\$[a-z](\d+)',out['sub_msg'],re.I))
        if not extra_vars <= source_vars:
            out['sub_msg']='a,'
            for i in range(5):out[f'UNK_1[{i}]']='0'
    return out


def main():
    STAGE.mkdir(exist_ok=True)
    reports=[]
    for name,keys in KEYS.items():
        sh,srows=read(OUT/f'source-{name}-C4.tsv')
        th,trows=read(OUT/f'target-{name}-Interlude.tsv')
        key=lambda row:tuple(row[field] for field in keys)
        source_keys={key(row) for row in srows}
        target_by={key(row):row for row in trows}
        if len(target_by)!=len(trows):raise ValueError('Ambiguous target key: '+name)
        converted=[convert_row(name,row,target_by.get(key(row)),th) for row in srows]
        rows=[row for row in trows if key(row) not in source_keys]+converted
        ddf=STAGE/(name+'.ddf');definition=(OUT/f'target-{name}-Interlude.export.ddf').read_bytes()
        if name=='actionname-e':
            # The disassembler exports matrix padding at the largest observed
            # count; merged C4 pet eligibility is 769, original Interlude 772.
            width=max(int(row['cat2_cnt']) for row in rows)
            dropped=[field for field in th if re.fullmatch(r'c\[\d+\]',field) and int(field[2:-1])>=width]
            if any(row[field] for row in rows for field in dropped):raise ValueError('Nonempty action padding')
            th=[field for field in th if field not in dropped]
            rows=[{field:row[field] for field in th} for row in rows]
            definition=re.sub(rb'(INT c\[cat2_cnt\];\s+SOFT = )\d+;',lambda m:m[1]+str(width).encode()+b';',definition)
        same_definition=ddf.exists() and ddf.read_bytes()==definition
        ddf.write_bytes(definition)
        text=STAGE/(name+'.tsv');write(text,th,rows)
        binary=STAGE/(name+'.decoded')
        check=STAGE/(name+'.roundtrip.tsv')
        wrapped_path=STAGE/(name+'.dat')
        cached=(same_definition and binary.exists() and check.exists() and wrapped_path.exists()
                and read(check)==(th,rows) and decode(wrapped_path.read_bytes())==binary.read_bytes())
        if not cached:
            if run_tool('l2asm',['-d',win(ddf),win(text),win(binary)],STAGE/(name+'.assemble.log')):
                raise ValueError('Assembly failed: '+name)
            if run_tool('l2disasm',['-d',win(ddf),'-o','e',win(binary),win(check)],STAGE/(name+'.roundtrip.log')):
                raise ValueError('Disassembly failed: '+name)
        headers,restored=read(check)
        if headers!=th or restored!=rows:raise ValueError('Target roundtrip changed content: '+name)
        raw=binary.read_bytes();wrapped=encode(raw)
        if decode(wrapped)!=raw:raise ValueError('RSA roundtrip failed: '+name)
        (STAGE/(name+'.dat')).write_bytes(wrapped)
        result={'table':name,'keys':keys,'source_rows':len(srows),'target_rows':len(trows),
                'merged_rows':len(rows),'source_keys_added':len(source_keys-set(target_by)),
                'sha256':hashlib.sha256(wrapped).hexdigest(),
                'source_tsv_sha256':hashlib.sha256((OUT/f'source-{name}-C4.tsv').read_bytes()).hexdigest(),
                'target_tsv_sha256':hashlib.sha256((OUT/f'target-{name}-Interlude.tsv').read_bytes()).hexdigest(),
                'validation':'all target columns/rows and RSA413 roundtrip match; source IDs retained'}
        reports.append(result);print(json.dumps(result),flush=True)
    (STAGE/'manifest.json').write_text(json.dumps({'tables':reports,
        'scope':'C4 server message templates, quest steps/NPC references, NPC entry events, static object/castle/server names and pet/summon action eligibility. Native Interlude window layout, character geometry and world-map configuration retained.',
        'quest_field_mapping':QUEST_RENAMES,
        'system_message_mapping':'RGB + signed alpha to RGBA; SystemMsg_e./SystemMsg_k. references to numeric Interlude form; retain compatible modern presentation metadata.'},indent=2)+'\n')


if __name__=='__main__':main()
