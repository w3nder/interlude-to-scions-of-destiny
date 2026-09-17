"""Complete character fixtures with distinct fields, no captured player data."""
import ctypes as C
import unittest
from test_cpp_core import ROOT
from test_structured_codec import d,h,s

def character(user, modern, cubes=2, rights=None):
    name=s('Synthetic'); title=s('Test title')
    prefix=bytes([4 if user else 3])+d(101,202,303,404,0x12345678)+name
    if user:
        prefix+=d(1,0,88,80)+d(0xf1234567)+(d(0) if modern else b'')
        prefix+=d(*range(14))
        prefix+=d(*range(0x400000,0x400010))+(d(0) if modern else b'')
        prefix+=d(*range(9000,9016))+(d(0) if modern else b'')
        prefix+=(bytes(68) if modern else b'')+bytes(80+32+16)+title+bytes(20+3+8)+h(cubes)
        permissions=(d(0xa2) if modern else d(0x409)+bytes(28)) if rights is None else rights
        tail=b''.join(h(i+1) for i in range(cubes))+b'\0'+d(42)+b'\0'+permissions
        tail+=h(1,2)+d(3)+h(100)+d(1,0,1000,999)+b'\0\0'+d(4)+b'\0\0\0'+d(5,6,7,0xabcdef)
        if modern:tail+=b'\0'+d(0,0,0xffffff,0)
    else:
        prefix+=d(1,0,88)+d(*range(9000,9011))+(d(0)+bytes(48) if modern else b'')
        prefix+=bytes(56+32+12)+title+bytes(20+7)+h(cubes)
        tail=b''.join(h(i+1) for i in range(cubes))+b'\0'+d(42)+b'\0'+h(9)+d(3,1,0)
        tail+=b'\0\0'+d(4)+b'\0\0\0'+d(5,6,7,0xabcdef)
        if modern:tail+=d(0,0,0,0xffffff,0,0)
    return prefix+tail

class CharacterCodecTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.lib=C.CDLL(str(ROOT/'build/libl2k_protocol.dylib'))
        cls.fn=cls.lib.l2k_character_convert
        cls.fn.argtypes=[C.c_void_p,C.c_uint32,C.c_void_p,C.c_uint32]
        cls.fn.restype=C.c_int
    def call(self,p,cap=65533):
        out=C.create_string_buffer(b'\xa5'*65534)
        n=self.fn(p,len(p),out,cap)
        self.assertEqual(out.raw[max(n,0):65534],b'\xa5'*(65534-max(n,0)))
        return n,out.raw[:max(n,0)]
    def test_complete_fields_and_zero_extended_experience(self):
        for user in [False,True]:
            for cubes in [0,1,32]:
                expected=character(user,True,cubes)
                n,out=self.call(character(user,False,cubes))
                self.assertEqual(n,len(expected));self.assertEqual(out,expected)
    def test_modern_variants_are_not_converted_twice(self):
        for user in [False,True]:
            self.assertEqual(self.call(character(user,True))[0],0)
    def test_capacity_is_transactional(self):
        for user in [False,True]:
            old=character(user,False); size=len(character(user,True))
            self.assertLess(self.call(old,size-1)[0],0)
            self.assertEqual(self.call(old,size)[0],size)
    def test_truncations_and_unknown_suffixes_do_not_guess(self):
        for user in [False,True]:
            p=character(user,False)
            for length in range(1,len(p)):
                self.assertEqual(self.call(p[:length])[0],0,(user,length))
            for suffix in [b'\0',d(1),bytes(128)]:
                self.assertEqual(self.call(p+suffix)[0],0)
