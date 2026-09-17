import ctypes as C,random,struct,unittest
from test_cpp_core import ROOT

def d(*v):return struct.pack('<'+'I'*len(v),*v)
def s(v):return v.encode('utf-16le')+b'\0\0'
def packets(seed,count):
    rng=random.Random(seed);clan_id=rng.randrange(1,2**32);members=[]
    for i in range(count):members.append(s('Membro'+str(i)+'界')+d(*(rng.getrandbits(32) for _ in range(5))))
    middle=s('Clã Ω')+s('Líder')+d(*(rng.getrandbits(32) for _ in range(9)))+s('Aliança')+d(rng.getrandbits(32),rng.getrandbits(32))+d(count)
    source=b'\x53'+d(clan_id)+middle+b''.join(members)
    target=b'\x53'+d(0,clan_id,0)+middle+b''.join(m+d(0) for m in members)
    return source,target

class ClanCodecTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.lib=C.CDLL(str(ROOT/'build/libl2k_protocol.dylib'));cls.fn=cls.lib.l2k_clan_convert;cls.fn.argtypes=[C.c_void_p,C.c_uint32,C.c_void_p,C.c_uint32];cls.fn.restype=C.c_int
    def convert(self,p,cap=8190):
        out=C.create_string_buffer(b'\xa5'*8192,8192);n=self.fn(p,len(p),out,cap);self.assertEqual(out.raw[8190:],b'\xa5\xa5');return n,out.raw
    def test_generated_clans_preserve_every_field(self):
        for seed in range(20):
            for count in [0,1,2,30,100]:
                src,want=packets(seed,count);n,out=self.convert(src);self.assertEqual(n,len(want));self.assertEqual(out[:n],want)
                n,_=self.convert(want);self.assertEqual(n,0)
    def test_member_updates_and_additions(self):
        for op,extra in [(0x54,2),(0x55,1)]:
            for name in ['','Ana','戦士','😀']:
                p=bytes([op])+s(name)+d(80,88,1,2,0xaabbccdd);want=p+d(*([0]*extra));n,out=self.convert(p);self.assertEqual(out[:n],want);self.assertEqual(self.convert(want)[0],0)
    def test_truncated_oversized_and_capacity_rejected(self):
        src,want=packets(123,3)
        for size in range(1,len(src)):
            self.assertLess(self.convert(src[:size])[0],0)
        self.assertLess(self.convert(src+b'\0')[0],0)
        self.assertEqual(self.convert(src,len(want)-1)[0],-2)
        bad=bytearray(src); # Member count immediately before first name.
        pos=src.index(s('Membro0界'));bad[pos-4:pos]=d(0xffffffff);self.assertLess(self.convert(bytes(bad))[0],0)
    def test_unrelated_packets_untouched(self):
        for op in range(256):
            if op not in [0x53,0x54,0x55]:self.assertEqual(self.convert(bytes([op])+b'anything')[0],0)
