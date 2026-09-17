"""Compare actual C4/Interlude list emitters and both native serializers offline."""
import ctypes as C
import hashlib
import json
import random
import struct
import unittest
from native_emitter_audit import NativeEmitter, PROFILES, ROOT

# opcode, number of header dwords (last is count), per-row wire fields.
LISTS = {
    'RequestBuyItem': (0x1f, 2, 'dd'),
    'RequestBuySeed': (0xc4, 2, 'dd'),
    'RequestPackageSend': (0x9f, 2, 'dd'),
    'RequestPreviewItem': (0xc6, 3, 'd'),
    'RequestProcureCrop': (0xc3, 2, 'ddd'),
    'RequestRecipeShopListSet': (0xb2, 1, 'dd'),
    'RequestSellItem': (0x1e, 2, 'ddd'),
    'SendPrivateStoreBuyBuyList': (0x96, 2, 'ddhhdd'),
    'SendPrivateStoreBuyList': (0x79, 2, 'ddd'),
    'SendWareHouseDepositList': (0x31, 1, 'dd'),
    'SendWareHouseWithdrawList': (0x32, 1, 'dd'),
    'SetPrivateStoreBuyList': (0x91, 1, 'dhhdd'),
    'SetPrivateStoreList': (0x74, 2, 'ddd'),
}
COUNTS = [0, 1, 2, 17, 100]

class NativeListRequestsTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.engines = {side: NativeEmitter(side) for side in PROFILES}
        cls.core = C.CDLL(str(ROOT / 'build/libl2k_protocol.dylib'))
        cls.convert = cls.core.l2k_outbound_convert
        cls.convert.argtypes = [C.c_void_p, C.c_uint32]
        cls.convert.restype = C.c_int
        rows = json.loads((ROOT / 'reports/wire-equivalence.json').read_text())['outbound']
        cls.methods = {r['name']: r for r in rows}

    def test_list_builders_match_native_c4_bytes_for_generated_vectors(self):
        rows = []
        for name, (opcode, headers, row_format) in LISTS.items():
            methods = self.methods[name]
            cases = []
            for count in COUNTS:
                for pattern in ['distinct', 'bit_boundaries', 'seeded_random']:
                    with self.subTest(name=name, count=count, pattern=pattern):
                        rng = random.Random(opcode * 1000 + count)
                        prefix = [0x12345678, 0x89abcdef][:headers - 1] + [count]
                        data = []
                        edges = [0, 1, 0x7fff, 0x8000, 0xffff, 0x10000, 0x7fffffff, 0x80000000, 0xffffffff]
                        for i in range(count * len(row_format)):
                            data.append(i * 65537 + 123 if pattern == 'distinct' else
                                        edges[i % len(edges)] if pattern == 'bit_boundaries' else rng.getrandbits(32))
                        expected = bytes([opcode]) + struct.pack('<' + 'I' * headers, *prefix)
                        for i, value in enumerate(data):
                            field = row_format[i % len(row_format)]
                            expected += struct.pack('<I', value) if field == 'd' else struct.pack('<H', value & 65535)
                        outputs = []
                        for side, engine in self.engines.items():
                            self.assertEqual(len(methods[side]), 1)
                            output = engine.run(int(methods[side][0]['method_va'], 16), prefix + data)
                            self.assertEqual(output['format'], 'c' + 'd' * headers + 'b')
                            self.assertEqual(output['wire'], expected)
                            self.assertEqual(output['consumed'], len(prefix + data))
                            self.assertEqual(output['top_calls'], len(prefix + data))
                            self.assertEqual(output['inner_formats'], [row_format] * count)
                            outputs.append(output['wire'])
                        self.assertEqual(outputs[0], outputs[1])
                        adapted = C.create_string_buffer(outputs[1])
                        self.assertEqual(self.convert(adapted, len(outputs[1])), 0)
                        self.assertEqual(bytes(adapted)[:len(expected)], expected)
                        cases.append({'count': count, 'pattern': pattern, 'bytes': len(expected),
                                      'synthetic_wire_sha256': hashlib.sha256(expected).hexdigest()})
            rows.append({'name': name, 'opcode': f'0x{opcode:02X}',
                         'source_method': methods['source'][0]['method_va'],
                         'target_method': methods['target'][0]['method_va'],
                         'header_dwords': headers, 'row_format': row_format,
                         'resolution': 'equal_native_output_for_test_vectors', 'cases': cases})
        report = {
            'hashes': {s: p['sha256'] for s, p in PROFILES.items()},
            'status': 'passed', 'method_count': len(rows),
            'vector_pairs': sum(len(r['cases']) for r in rows),
            'scope': 'Synthetic parameter stacks; exact native Top, stack allocation, list loops, row assembly and final serializer. C++ outbound adapter must preserve the matching bytes. VM stops before socket send. C4 UI diagnostic callback is replaced with a no-op.',
            'limits': 'Finite differential tests are not a proof for every input, UI/caller semantics or live server acceptance. No runtime conversion is enabled. Invalid counts and native buffer overflow behavior are not certified.',
            'methods': rows,
        }
        (ROOT / 'reports/native-list-requests.json').write_text(json.dumps(report, indent=2) + '\n')

    def test_macro_strings_and_lines_match_native_c4(self):
        methods = self.methods['RequestMakeMacro']
        cases=[]
        for count in [0, 1, 12]:
            for label in ['', 'Teste', 'Ação 🎯']:
                with self.subTest(count=count, label=label):
                    encoded = [(v + '\0').encode('utf-16le') for v in [label, 'Descrição', 'T']]
                    blobs = {0x10000 + 0x200 * i: b for i, b in enumerate(encoded)}
                    values = [0x12345678] + [NativeEmitter.DATA + 0x10000 + 0x200 * i for i in range(3)] + [3, count]
                    expected = b'\xc1' + struct.pack('<I', 0x12345678) + b''.join(encoded) + bytes([3, count])
                    for row in range(count):
                        command = (f'/target NPC{row}\0').encode('utf-16le')
                        offset = 0x11000 + row * 0x200
                        blobs[offset] = command
                        values += [row, row % 4, 65537 + row, row + 1, NativeEmitter.DATA + offset]
                        expected += struct.pack('<BBIB', row, row % 4, 65537 + row, row + 1) + command
                    for side, engine in self.engines.items():
                        result = engine.run(int(methods[side][0]['method_va'], 16), values, blobs)
                        self.assertEqual(result['wire'], expected)
                        self.assertEqual(result['consumed'], len(values))
                        self.assertEqual(result['top_calls'], len(values))
                        self.assertEqual(result['inner_formats'], ['ccdcS'] * count)
                        adapted = C.create_string_buffer(result['wire'])
                        self.assertEqual(self.convert(adapted, len(expected)), 0)
                        self.assertEqual(bytes(adapted)[:len(expected)], expected)
                    cases.append({'lines':count,'bytes':len(expected),'sha256':hashlib.sha256(expected).hexdigest()})
        (ROOT/'reports/native-macro-requests.json').write_text(json.dumps({'status':'passed',
            'hashes':{s:p['sha256'] for s,p in PROFILES.items()},'method':'RequestMakeMacro','cases':cases,
            'scope':'Exact native macro row construction and serialization; finite strings and 0/1/12 lines.'},indent=2)+'\n')

    def test_repeated_execution_does_not_reuse_previous_list(self):
        for side, engine in self.engines.items():
            entry = int(self.methods['SendWareHouseDepositList'][side][0]['method_va'], 16)
            first = engine.run(entry, [2, 111, 222, 333, 444])
            empty = engine.run(entry, [0])
            again = engine.run(entry, [2, 111, 222, 333, 444])
            self.assertEqual(empty['wire'], b'\x31' + bytes(4))
            self.assertEqual(first, again)
