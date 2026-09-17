import ctypes as C,json,struct,unittest
from test_cpp_core import ROOT
class OutboundPolicyTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.lib=C.CDLL(str(ROOT/'build/libl2k_protocol.dylib'));cls.fn=cls.lib.l2k_outbound_blocked;cls.fn.argtypes=[C.c_void_p,C.c_uint32];cls.fn.restype=C.c_int
    def test_every_extended_selector_has_exact_policy(self):
        policy=json.loads((ROOT/'outbound-policy.json').read_text());denied={r['extended'] for r in policy['denied']}
        for sub in range(65536):
            p=b'\xd0'+struct.pack('<H',sub);self.assertEqual(self.fn(p,len(p)),int(sub in denied))
    def test_observed_c4_requests_remain_allowed(self):
        policy=json.loads((ROOT/'outbound-policy.json').read_text())
        for r in policy['source_selectors']:
            if r['opcode']==0xd0 and r['extended'] is None:continue
            p=bytes([r['opcode']])+(struct.pack('<H',r['extended']) if r['opcode']==0xd0 else b'')+b'\0'*32
            if r['opcode']==0x45:p=p[:10]
            self.assertEqual(self.fn(p,len(p)),0,r['name'])
    def test_action_catalogue_blocks_only_interlude_summon_commands(self):
        from migrate_asset_tables import read
        from extract_asset_tables import OUT
        source=read(OUT/'source-actionname-e-C4.tsv')[1]
        target=read(OUT/'target-actionname-e-Interlude.tsv')[1]
        ids={int(r['id']) for r in source}
        extras={int(r['id']) for r in target}-{int(r['id']) for r in source}
        self.assertEqual(extras,{57,58,59,60,*range(1031,1041)})
        for action in ids|extras|{50012,0xffffffff}:
            for flag in [0,1,255]:
                p=b'\x45'+struct.pack('<IIB',action,0x80000000,flag)
                self.assertEqual(self.fn(p,len(p)),int(1031<=action<=1040))
        for size in [1,5,9,11,100]:self.assertLess(self.fn(b'\x45'+bytes(size-1),size),0)
