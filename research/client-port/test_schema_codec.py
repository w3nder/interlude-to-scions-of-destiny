import ctypes as C,random,struct,unittest
from test_cpp_core import ROOT

def d(*v):return struct.pack('<'+'I'*len(v),*v)
def s(v):return v.encode('utf-16le')+b'\0\0'
class SchemaCodecTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.lib=C.CDLL(str(ROOT/'build/libl2k_protocol.dylib'));cls.fn=cls.lib.l2k_schema_convert
        cls.fn.argtypes=[C.c_void_p,C.c_uint32,C.c_void_p,C.c_uint32];cls.fn.restype=C.c_int
    def convert(self,p,cap=8190):
        out=C.create_string_buffer(b'\xa5'*8192,8192);n=self.fn(p,len(p),out,cap)
        self.assertEqual(out.raw[max(cap,0):],b'\xa5'*(8192-max(cap,0)))
        return n,out.raw
    def check_pair(self,p,want):
        n,out=self.convert(p);self.assertEqual(n,len(want));self.assertEqual(out[:n],want)
        self.assertEqual(self.convert(want)[0],0)
        self.assertEqual(self.convert(p,len(want)-1)[0],-2)
    def test_generated_skill_and_enchant_lists(self):
        rng=random.Random(213)
        for prefix,words,pad in [(b'\x58',3,1),(b'\x91'+s('Mago界'),3,1),(b'\xfe\x17\0',4,4)]:
            for count in [1,2,10,100,300]:
                rows=[d(*(rng.getrandbits(32) for _ in range(words))) for _ in range(count)]
                p=prefix+d(count)+b''.join(rows);want=prefix+d(count)+b''.join(r+b'\0'*pad for r in rows)
                self.check_pair(p,want)
                for size in range(len(prefix),len(p)):
                    self.assertLess(self.convert(p[:size])[0],0)
            self.assertEqual(self.convert(prefix+d(0))[0],0)
            self.assertLess(self.convert(prefix+d(0xffffffff))[0],0)
    def test_pet_xp_unsigned_expansion(self):
        for name in ['', 'Pet😀']:
            p=b'\xb5'+d(1,2,3,4,5)+s(name)+d(*range(7))+d(0,0x80000000,0xffffffff)
            want=p[:-12]+struct.pack('<QQQ',0,0x80000000,0xffffffff);self.check_pair(p,want)
            for size in range(1,len(p)):self.assertLess(self.convert(p[:size])[0],0)
    def test_fishing_and_modern_passthrough(self):
        for sub,size,extra in [(0x13,23,2),(0x15,17,1),(0x16,22,1)]:
            p=b'\xfe'+struct.pack('<H',sub)+bytes(range(size-3));self.check_pair(p,p+b'\0'*extra)
            modern=p+b'\x01'*extra;self.assertEqual(self.convert(modern)[0],0)
            for n in range(3,size):self.assertLess(self.convert(p[:n])[0],0)
    def test_unknown_scope_and_output_limit(self):
        self.assertEqual(self.convert(b'\x29'+b'\0'*20)[0],0)
        self.assertEqual(self.convert(b'\xfe\x99\0')[0],0)
        p=b'\x58'+d(630)+d(0,1,2)*630
        self.assertEqual(self.convert(p)[0],-2)

    def test_enchant_info_preserves_requirements_and_rate(self):
        for count in [0,1,2,100]:
            p=b'\xfe\x18\0'+d(123,101,500,0xffffffff,85,count)+d(1,57,999,0)*count
            want=p[:19]+d(0)+p[19:];self.check_pair(p,want)
            # A C4 prefix can itself be a complete modern packet: preserve, never expand.
            for n in range(3,len(p)):self.assertLessEqual(self.convert(p[:n])[0],0)

    def test_inventory_rows_preserve_item_properties(self):
        rng=random.Random(7)
        for op,size in [(0x1b,28),(0x27,30)]:
            for count in [1,2,50,200]:
                prefix=bytes([op])+(b'\x01\0' if op==0x1b else b'')+struct.pack('<H',count)
                rows=[rng.randbytes(size) for _ in range(count)]
                source=prefix+b''.join(rows);target=prefix+b''.join(row+d(0,0xffffffff) for row in rows)
                self.check_pair(source,target)
                for n in [len(prefix)-1,len(source)-1]:self.assertLess(self.convert(source[:n])[0],0)
