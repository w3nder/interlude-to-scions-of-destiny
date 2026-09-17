"""Execute both native float conversions and sender ABIs without networking."""
import ctypes as C
import json
import struct
import unittest
from native_emitter_audit import NativeEmitter, ROOT, PROFILES


class NativeMovementRequestsTests(unittest.TestCase):
    def test_movement_actions_and_drop_item_match_c4_wire(self):
        engines = {side: NativeEmitter(side) for side in PROFILES}
        methods = {r['name']: r for r in json.loads((ROOT/'reports/wire-equivalence.json').read_text())['outbound']}
        lib = C.CDLL(str(ROOT/'build/libl2k_protocol.dylib'))
        convert = lib.l2k_outbound_convert
        convert.argtypes = [C.c_void_p, C.c_uint32]; convert.restype = C.c_int
        vectors = [(0., 0., 0.), (1.75, -2.75, 0.99), (-123456.5, 234567.75, -65535.5),
                   (-0.99, 0.99, -1.01), (2147483520., -2147483648., 65536.5)]
        cases = {}
        for xyz in vectors:
            floating = list(struct.unpack('<III', struct.pack('<fff', *xyz)))
            ints = b''.join(struct.pack('<i', int(v)) for v in xyz)
            for name, opcode, prefix, expected_tail in [
                ('Action', 4, [123], b'\xff'), ('RequestAttack', 4, [123], b''),
                ('GetOnVehicle', 0x42, [123], b''), ('GetOffVehicle', 0x43, [123], b''),
                ('MoveWithDelta', 0x41, [], b''), ('MoveBackwardToLocation', 1, [], ints),
                ('CanNotMoveAnymore', 0x36, [], struct.pack('<I', 777)),
                ('RequestDropItem', 0x12, [123, 42], b''),
                ('RequestDropItemFromPet', 0x12, [123, 42], b'')]:
                expected = bytes([opcode]) + b''.join(struct.pack('<I', v) for v in prefix) + ints + expected_tail
                for side, engine in engines.items():
                    args = prefix + floating
                    if name == 'Action': args += [0x1ff]
                    if name == 'MoveBackwardToLocation': args = floating * 2
                    if name == 'CanNotMoveAnymore': args = [0] + floating + [777, 0]
                    if name.startswith('RequestDropItem'):
                        # Native ItemInfo by value differs in size, but only its
                        # common object ID/count and following FVector go on wire.
                        args = [0, 123, 57, 42] + [0] * (8 if side == 'source' else 11) + floating
                    with self.subTest(method=name, side=side, xyz=xyz):
                        output = engine.run(int(methods[name][side][0]['method_va'], 16), [], direct_arguments=args)
                        self.assertEqual(output['wire'], expected)
                        buffer = C.create_string_buffer(output['wire'])
                        self.assertEqual(convert(buffer, len(expected)), 0)
                        self.assertEqual(buffer.raw[:len(expected)], expected)
                cases[name] = cases.get(name, 0) + 1
        report = {'status': 'passed', 'hashes': {s: p['sha256'] for s,p in PROFILES.items()},
                  'methods': cases, 'vector_pairs': sum(cases.values()),
                  'scope': 'Real x86 senders, float-to-integer helpers and serializers; ItemInfo ABI differences represented explicitly.',
                  'limits': 'Synthetic finite inputs; CanNotMoveAnymore covers the non-vehicle branch only; no socket send or gameplay claim.'}
        (ROOT/'reports/native-movement-requests.json').write_text(json.dumps(report, indent=2)+'\n')
