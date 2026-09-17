"""Account for all statically registered slots, without a packet-name filter."""
import hashlib
import re
import struct
import unittest
from extract_protocol import Extractor
from native_emitter_audit import PROFILES


class RegistrationCatalogueTests(unittest.TestCase):
    def test_constructor_vtables_recover_unexported_senders(self):
        expected = {'source':{'ValidatePosition':('0x48','cddddd'),'VoteSociality':('0xB9','cd')},
                    'target':{'ValidatePosition':('0x48','cddddd'),'StartRotating':('0x4A','cdd'),'VoteSociality':('0xB9','cd')}}
        for side, profile in PROFILES.items():
            extractor = Extractor(profile['path'])
            self.assertEqual(len(extractor.network_vtable()),303 if side=='source' else 336)
            recovered = {r['name']:(r['opcode'],r['format']) for r in extractor.outbound() if r.get('recovery')}
            self.assertEqual(recovered,expected[side])

    def test_every_table_handler_assignment_has_a_catalogue_entry(self):
        for side, profile in PROFILES.items():
            with self.subTest(side=side):
                extractor = Extractor(profile['path'])
                self.assertEqual(hashlib.sha256(extractor.raw).hexdigest(), profile['sha256'])
                rows = extractor.inbound()
                keys = {(r['table'], int(r['opcode'], 16)) for r in rows}
                self.assertEqual(len(keys), len(rows))
                self.assertEqual(len(rows), 304 if side == 'source' else 348)
                anchors = {r['table']: int(r['table_name_base_va'], 16) for r in rows}
                pet = next(r for r in rows if r['table']=='primary' and r['opcode']=='0xB3')
                self.assertEqual([s['format'] for s in pet['decode_segments']], ['h','hh','dddhhhdhh'])

                assignments = set()
                for match in re.finditer(rb'(?=\xc7\x05(.{8}))', extractor.raw, re.DOTALL):
                    address, handler = struct.unpack('<II', match[1])
                    if not extractor.base <= handler < extractor.base + extractor.pe.OPTIONAL_HEADER.SizeOfImage:
                        continue
                    for table, base in anchors.items():
                        delta = address + 4 - base
                        if 0 <= delta < 260 * 256 and delta % 260 == 0:
                            assignments.add((table, delta // 260))
                # The first handler in each table is a static PE initializer.
                for table, base in anchors.items():
                    initial = struct.unpack('<I', extractor.data(base-4, 4))[0]
                    self.assertTrue(extractor.base <= initial < extractor.base + extractor.pe.OPTIONAL_HEADER.SizeOfImage)
                    assignments.add((table, 0))
                    row = next(r for r in rows if r['table'] == table and r['opcode'] == '0x00')
                    self.assertEqual(int(row['handler_va'], 16), extractor.resolve(initial))
                self.assertEqual(assignments, keys)
                if side == 'target':
                    named = {r['opcode']: r['name'] for r in rows if r['table'] == 'extended'}
                    self.assertEqual(named['0x3C'], 'PledgeReceivePowerInfo')
                    self.assertEqual(named['0x41'], 'PledgeReceiveUpdatePower')
                    self.assertEqual(named['0x43'], 'ShowPCCafeCouponShowUI')
