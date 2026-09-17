"""Cross-catalogue and schema regressions for server-referenced C4 DATs."""
import hashlib
import json
import re
import unittest
from migrate_asset_tables import read
from migrate_content_tables import ROOT, OUT, STAGE, KEYS
from ini_codec import decode


class ContentMigrationTests(unittest.TestCase):
    def test_pet_action_eligibility_uses_source_npc_ids(self):
        source=read(OUT/'source-actionname-e-C4.tsv')[1]
        merged={r['id']:r for r in read(STAGE/'actionname-e.tsv')[1]}
        npcs={r['tag'] for r in read(ROOT/'build/assets-interlude/npcgrp.tsv')[1]}
        for row in source:
            for key,value in row.items():self.assertEqual(merged[row['id']][key],value)
            for i in range(int(row['cat2_cnt'])):
                value=row[f'c[{i}]']
                self.assertTrue(value in npcs or value in ('-1','-2'))
        self.assertEqual(merged['22']['c[0]'],'12006')

    def test_target_roundtrips_and_original_identifiers(self):
        manifest=json.loads((STAGE/'manifest.json').read_text())
        for entry in manifest['tables']:
            name=entry['table']
            with self.subTest(table=name):
                raw=(STAGE/(name+'.dat')).read_bytes()
                self.assertEqual(hashlib.sha256(raw).hexdigest(),entry['sha256'])
                self.assertEqual(decode(raw),(STAGE/(name+'.decoded')).read_bytes())
                self.assertEqual(read(STAGE/(name+'.tsv')),read(STAGE/(name+'.roundtrip.tsv')))
                source=read(OUT/f'source-{name}-C4.tsv')[1]
                merged=read(STAGE/(name+'.tsv'))[1]
                key=lambda row:tuple(row[k] for k in KEYS[name])
                self.assertTrue({key(r) for r in source}<={key(r) for r in merged})

    def test_quest_and_spawn_references_match_migrated_catalogues(self):
        npcs={r['tag'] for r in read(ROOT/'build/assets-interlude/npcgrp.tsv')[1]}
        items={r['id'] for r in read(ROOT/'build/assets-interlude/itemname-e.tsv')[1]}
        quests=read(STAGE/'questname-e.tsv')[1]
        source=read(OUT/'source-questname-e-C4.tsv')[1]
        source_by={(r['quest_id'],r['quest_prog']):r for r in source}
        inherited_missing={(r['quest_id'],r['quest_prog'],r['UNK_3']) for r in source
                           if r['UNK_3'] not in npcs and r['UNK_3']!='0'}
        actual_missing={(r['quest_id'],r['quest_prog'],r['contact_npc_id']) for r in quests
                        if r['contact_npc_id'] not in npcs and r['contact_npc_id']!='0'}
        self.assertEqual(actual_missing,inherited_missing)
        # The shipped source has this special ID, not a newly invented NPC.
        self.assertEqual(inherited_missing,{('246',str(step),'1008740') for step in (4,5,6)})
        for row in quests:
            old=source_by.get((row['quest_id'],row['quest_prog']))
            if old:
                self.assertEqual(row['contact_npc_id'],old['UNK_3'])
                self.assertEqual(row['contact_npc_x'],old['entity_x_?'])
            for field,value in row.items():
                if field.startswith('items[') and value and value!='0':
                    self.assertIn(value,items)
        events=read(OUT/'source-entereventgrp-C4.tsv')[1]
        merged={r['id']:r for r in read(STAGE/'entereventgrp.tsv')[1]}
        for row in events:
            self.assertIn(row['id'],npcs)
            self.assertEqual(merged[row['id']],row)

    def test_system_message_parameter_contracts_and_numeric_references(self):
        source={r['id']:r for r in read(OUT/'source-systemmsg-e-C4.tsv')[1]}
        target={r['id']:r for r in read(OUT/'target-systemmsg-e-Interlude.tsv')[1]}
        merged={r['id']:r for r in read(STAGE/'systemmsg-e.tsv')[1]}
        variables=lambda text:set(re.findall(r'\$[a-z](\d+)',text,re.I))
        differences=[]
        for key,old in source.items():
            row=merged[key]
            self.assertEqual(row['message'],old['message'])
            self.assertNotIn('SystemMsg_',row['sys_msg_ref'])
            self.assertEqual(int(row['rgba[3]'],16),int(old['UNK_1'])&255)
            self.assertLessEqual(variables(row['sub_msg']),variables(old['message']))
            if variables(old['message'])!=variables(target[key]['message']):differences.append(key)
        self.assertIn('1673',differences)
        self.assertEqual(variables(merged['1673']['message']),{'1','2','3'})
        self.assertEqual(variables(target['1673']['message']),{'1','2','3','4'})
        for key in target.keys()-source.keys():self.assertEqual(merged[key],target[key])
