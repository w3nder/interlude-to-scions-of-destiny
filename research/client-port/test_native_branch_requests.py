"""Compare conditional C4/Interlude emitters, including native list/string ABI."""
import ctypes as C
import hashlib
import json
import struct
import unittest
from native_emitter_audit import NativeEmitter, ROOT, PROFILES


def d(*values):
    return struct.pack('<'+'I'*len(values), *values)


def s(text):
    return (text+'\0').encode('utf-16le')


class NativeBranchRequestsTests(unittest.TestCase):
    def test_conditional_requests_match_original_c4(self):
        engines = {side: NativeEmitter(side) for side in PROFILES}
        methods = {r['name']: r for r in json.loads((ROOT/'reports/wire-equivalence.json').read_text())['outbound']}
        lib = C.CDLL(str(ROOT/'build/libl2k_protocol.dylib'))
        convert = lib.l2k_outbound_convert
        convert.argtypes = [C.c_void_p, C.c_uint32]; convert.restype = C.c_int
        cases = {}

        def check(name, expected, values=(), blobs=None, args=None, object_fields=None):
            for side, engine in engines.items():
                with self.subTest(method=name, side=side, length=len(expected)):
                    actual = engine.run(int(methods[name][side][0]['method_va'], 16), list(values), blobs, direct_arguments=args, object_fields=object_fields)
                    self.assertEqual(actual['wire'], expected)
                    buffer = C.create_string_buffer(expected)
                    self.assertEqual(convert(buffer, len(expected)), 0)
                    self.assertEqual(buffer.raw[:len(expected)], expected)
            cases.setdefault(name, []).append({'bytes':len(expected), 'synthetic_wire_sha256':hashlib.sha256(expected).hexdigest()})

        for name, wire in [('RequestManorList', b'\xd0\x08\0'),
                           ('RequestOlympiadMatchList', b'\xd0\x13\0'),
                           ('RequestOlympiadObserverEnd', b'\xd0\x12\0'),
                           ('RequestReload', b'\xcf')]:
            check(name, wire, args=[])

        pointer = NativeEmitter.DATA+0x10000
        for text in ['', 'Teste', 'Ação 漢字 🎯', 'x'*512]:
            blob = s(text)
            for name, opcode in [('SetPrivateStoreMsg',0x77), ('SetPrivateStoreBuyMsg',0x94), ('RequestRecipeShopMessageSet',0xb1)]:
                check(name, bytes([opcode])+blob, blobs={0x10000:blob}, args=[pointer])
            for action in range(5):
                expected = b'\xa0'+d(action)+(blob if action<2 else b'')
                check('RequestBlock', expected, [action,pointer], {0x10000:blob})
            for channel in [0,1,2,3,4,8,9,17,18]:
                recipient = s('Recipient')
                expected = b'\x38'+blob+d(channel)+(recipient if channel==2 else b'')
                check('Say2', expected, [channel,pointer,pointer+0x2000], {0x10000:blob,0x12000:recipient})

        for n in [0,1,16,256,768,4096]:
            data = bytes(i%256 for i in range(n))
            for name, prefix in [('RequestSetPledgeCrest', b'\x53'), ('RequestExSetPledgeCrestLarge', b'\xd0\x11\0'), ('RequestSetAllyCrest', b'\x87')]:
                check(name, prefix+d(n)+data, blobs={0x10000:data}, args=[n,pointer])

        for value in [0,1,0x7fffffff,0x80000000,0xffffffff]:
            for kind in [2,3]:
                fields = [value,kind,0x12345678,0x89abcdef]+([value] if kind==3 else [])
                check('RequestTeleport', b'\x1a'+d(*fields), args=[value,kind,0x12345678,0x89abcdef,value])
            check('RequestShortCutDel', b'\x35'+d(value), [value])

        for count in [0,1,2,17,100]:
            for name, selector, header, rowfmt in [('RequestProcureCropList',9,[], 'dddd'), ('RequestSetSeed',10,[7], 'ddd'), ('RequestSetCrop',11,[7], 'dddc')]:
                edges = [0,1,0x7f,0x80,0xff,0x100,0x7fffffff,0x80000000,0xffffffff]
                values = [edges[i%len(edges)] for i in range(count*len(rowfmt))]
                payload = b''.join(d(v) if rowfmt[i%len(rowfmt)]=='d' else bytes([v&255]) for i,v in enumerate(values))
                prefix = header+[count]
                check(name, b'\xd0'+struct.pack('<H',selector)+d(*prefix)+payload, prefix+values)

        for side, engine in engines.items():
            engine.bind_core_import(b'??DFString@@QBEPBGXZ')
            slot = 0x142d7964 if side=='source' else 0x11d8dae0
            engine._map_image(engine.u,0,slot,4,0,None)
            engine.put(slot,pointer)
        for text in ['', 'Hero', 'Ação 漢字 🎯']:
            blob = s(text)
            check('RequestWriteHeroWords',b'\xd0\x0c\0'+blob,blobs={0x10000:blob},args=[pointer,len(blob)//2,len(blob)//2])
        for interval, rate in [(0.,0),(.25,4),(1.,1),(-1.,0xffffffff),(.0625,16)]:
            field = struct.unpack('<I',struct.pack('<f',interval))[0]
            check('NetPing',b'\xa8'+d(123,rate,256),blobs={0x10000:struct.pack('<f',.125)},args=[123],object_fields={0x18c:field})

        # Three target methods are not exported. Their addresses are reached
        # through the constructor-installed UNetworkHandler vtables; tests of
        # that inventory are independent of opcode/format-name matching.
        for name, src, dst in [('Attack',0x103f4a30,0x10403da0),('SendAppearingPacket',0x103f4cd0,0x10403f50),
                              ('ValidatePosition',0x103f4ee0,0x104040f0),('StartRotating',0x103f4f50,0x10404150),
                              ('VoteSociality',0x103fb9f0,0x10409ab0)]:
            methods[name]={'source':[{'method_va':hex(src)}],'target':[{'method_va':hex(dst)}]}
        check('SendAppearingPacket',b'\x30',args=[])
        for value in [0,1,0x7fffffff,0x80000000,0xffffffff]:
            check('VoteSociality',b'\xb9'+d(value),args=[value])
            check('StartRotating',b'\x4a'+d(value,0x89abcdef),args=[value,0x89abcdef])
        for xyz in [(0.,0.,0.),(1.75,-2.75,.99),(-123456.5,234567.75,-65535.5)]:
            floats = list(struct.unpack('<III',struct.pack('<fff',*xyz)))
            coords = struct.pack('<iii',*(int(v) for v in xyz))
            check('ValidatePosition',b'\x48'+coords+d(0x12345678,777),args=floats+[0x12345678,777])
            for flag in [0,1,0xff,0x1ff]:
                check('Attack',b'\x0a'+d(123)+coords+bytes([flag&255]),args=[123]+floats+[flag])

        report = {'status':'passed','hashes':{side:p['sha256'] for side,p in PROFILES.items()},
                  'method_count':len(cases),'vector_pairs':sum(map(len,cases.values())), 'methods':cases,
                  'scope':'Native senders and serializers; valid branch selectors, Unicode strings, crest buffers, manor loops and narrowing conversions. No socket connection.',
                  'limits':'Finite differential inputs. Null string pointers/invalid action selectors do not represent valid user requests; exception paths and UI semantics are not certified.'}
        (ROOT/'reports/native-branch-requests.json').write_text(json.dumps(report,indent=2)+'\n')

    def test_legacy_implicit_varargs_are_the_same_abi_quirk_not_user_fields(self):
        # These original methods push only opcode despite cd/cS formats. The
        # following vararg is the caller return address, not a missing user ID.
        # Keep this evidence separate from field-equivalence certification.
        methods = {r['name']: r for r in json.loads((ROOT/'reports/wire-equivalence.json').read_text())['outbound']}
        for side in PROFILES:
            engine = NativeEmitter(side)
            for name, expected in [('RequestHennaItemList', b'\xba'+d(engine.STOP)),
                                   ('RequestHennaUnequipList', b'\xbd'+d(engine.STOP)),
                                   ('RequestPetitionCancel', b'\x80\0\0')]:
                result = engine.run(int(methods[name][side][0]['method_va'],16), [], direct_arguments=[])
                self.assertEqual(result['wire'], expected)
        (ROOT/'reports/native-legacy-abi.json').write_text(json.dumps({'status':'passed',
            'hashes':{s:p['sha256'] for s,p in PROFILES.items()},
            'methods':['RequestHennaItemList','RequestHennaUnequipList','RequestPetitionCancel'],
            'scope':'Both original emitters read an implicit caller return-address vararg. Synthetic identical return site reproduces matching bytes.',
            'limits':'Caller addresses differ in the real programs. This documents inherited behavior, not semantic equivalence or proof of server acceptance.'},indent=2)+'\n')
