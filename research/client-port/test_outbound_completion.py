import ctypes as C,struct,unittest
from test_cpp_core import ROOT
class OutboundCompletionTests(unittest.TestCase):
 @classmethod
 def setUpClass(cls):
  cls.lib=C.CDLL(str(ROOT/'build/libl2k_protocol.dylib'))
  cls.convert=cls.lib.l2k_outbound_convert;cls.convert.argtypes=[C.c_void_p,C.c_uint32];cls.convert.restype=C.c_int
  cls.format=cls.lib.l2k_outbound_serialization_format;cls.format.argtypes=[C.c_char_p,C.c_void_p,C.c_uint32];cls.format.restype=C.c_char_p
 def test_exact_remaining_straight_line_contracts(self):
  for head,old_fields,new_fields in [(b'\x71',2,4),(b'\xd0\x0e\0',1,2)]:
   for values in [(0,0,0,0),(1,0x12345678,0xffffffff,97)]:
    original=head+struct.pack('<'+'I'*new_fields,*values[:new_fields]);buf=C.create_string_buffer(original)
    length=self.convert(buf,len(original));self.assertEqual(length,len(head)+4*old_fields)
    self.assertEqual(buf.raw[:length],head+struct.pack('<'+'I'*old_fields,*values[:old_fields]))
    self.assertEqual(self.convert(buf,length),0)
   for n in range(1,len(head)+new_fields*4+4):
    if n in [len(head)+old_fields*4,len(head)+new_fields*4]:continue
    data=(head+bytes(40))[:n];self.assertLess(self.convert(C.create_string_buffer(data),n),0)
 def test_extended_selector_isolation(self):
  for sub in [0,1,13,15,0x10e,0xffff]:
   p=b'\xd0'+struct.pack('<H',sub)+bytes(8);b=C.create_string_buffer(p);self.assertEqual(self.convert(b,len(p)),0);self.assertEqual(b.raw[:len(p)],p)
 def test_enterworld_rewrites_only_exact_serializer(self):
  fmt=b'cbddddbd'+b'c'*20
  for blob_size in [0,4,32,128]:
   data=b'\x03'+bytes(blob_size+16+88)
   self.assertEqual(self.format(fmt,data,len(data)),b'cbdddd')
  for fmt2,op in [(b'cbdddd',3),(fmt,4),(fmt+b'd',3),(b'cbddddb',3)]:
   self.assertIsNone(self.format(fmt2,bytes([op])+bytes(104),105))

 def test_pledge_actions_require_complete_c4_layout(self):
  for action in [0,1,2,3,0xffffffff]:
   expected=9 if action in [1,2] else 41
   for n in range(1,46):
    packet=(b'\xc0'+struct.pack('<II',77,action)+bytes(50))[:n]
    buf=C.create_string_buffer(packet)
    self.assertEqual(self.convert(buf,n)<0,n!=expected,(action,n))
    self.assertEqual(buf.raw[:n],packet)
