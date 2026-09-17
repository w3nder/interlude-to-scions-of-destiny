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
            self.assertEqual(self.fn(p,len(p)),0,r['name'])
