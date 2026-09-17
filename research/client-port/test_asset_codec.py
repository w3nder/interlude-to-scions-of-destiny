import ctypes as C,json,struct,unittest
from test_cpp_core import ROOT
from test_structured_codec import d,h,s,encode
class Record(C.Structure):
 _fields_=[(x,C.c_uint32) for x in ['kind','id','quantity','equipped','body_part','slot','enchant','variant','type1']]
class AssetCodecTests(unittest.TestCase):
 @classmethod
 def setUpClass(cls):
  cls.lib=C.CDLL(str(ROOT/'build/libl2k_protocol.dylib'));cls.fn=cls.lib.l2k_asset_inspect
  cls.fn.argtypes=[C.c_void_p,C.c_uint32,C.POINTER(Record),C.c_uint32];cls.fn.restype=C.c_int
 def inspect(self,p,cap=256):
  out=(Record*256)();before=bytes(out);n=self.fn(p,len(p),out,cap)
  if n<=0:self.assertEqual(bytes(out),before)
  self.assertEqual(bytes(out)[cap*C.sizeof(Record):],before[cap*C.sizeof(Record):])
  return n,[{k:getattr(r,k) for k,_ in Record._fields_} for r in out[:max(n,0)]]
 def test_inventory_named_fields_and_observed_live_sizes(self):
  row=h(0)+d(0x12345678,9057,42)+h(2,0,1)+d(128)+h(16,0)
  for op in [0x1b,0x27]:
   for modern in [False,True]:
    for count in [1,57]:
     item=(h(1) if op==0x27 else b'')+row+(h(0x1234,0x5678)+d(0xffffffff) if modern else b'')
     p=bytes([op])+(h(1) if op==0x1b else b'')+h(count)+item*count
     n,records=self.inspect(p,1);self.assertEqual(n,1)
     self.assertEqual(records[0],dict(kind=1,id=9057,quantity=42,equipped=1,body_part=128,slot=0,enchant=16,variant=6 if modern else 4,type1=0))
     self.assertLess(self.inspect(p[:-1])[0],0)
     if op==0x1b and modern and count==57:self.assertEqual(len(p),2057)
     if op==0x27 and modern and count==1:self.assertEqual(len(p),41)
 def test_npc_ids_are_normalized_without_recording_identity(self):
  fmt='ddddddddddddddddddffffdddcccccSSddddddddccffd';fields=encode(fmt)
  fields[1]=d(1000001)
  for modern in [False,True]:
   p=b'\x16'+b''.join(fields)+(d(0) if modern else b'');n,r=self.inspect(p)
   self.assertEqual((n,r[0]['kind'],r[0]['id'],r[0]['variant']),(1,2,1,6 if modern else 4))
 def test_character_equipment_uses_catalogue_ids_not_object_ids(self):
  for user in [False,True]:
   for modern in [False,True]:
    prefix=(b'\x04' if user else b'\x03')+d(1,2,3,4,0x12345678)+s('Synthetic')
    slots=(17 if modern else 16) if user else (12 if modern else 11)
    ids=[9000+i for i in range(slots)]
    if user:
     prefix+=d(0,0,0,80)+(struct.pack('<Q',0x1234) if modern else d(0x1234))+d(*range(14))+d(*range(0x400000,0x400000+slots))+d(*ids)
     prefix+=(bytes(68) if modern else b'')+bytes(80+32+16)+s('')+bytes(20+3+8)+h(2)
     tail=h(1,2)+b'\0'+d(0)+b'\0'+bytes(4 if modern else 32)+h(1,2)+d(0)+h(100)+d(1,0,1000,999)+b'\0\0'+d(0)+b'\0\0'+b'\0'+d(0,0,0,0xffffff)
     if modern:tail+=b'\0'+d(0,0,0xffffff,0)
    else:
     prefix+=d(0,0,0)+d(*ids)+(bytes(48) if modern else b'')+bytes(56+32+12)+s('')+bytes(20+7)+h(2)
     tail=h(1,2)+b'\0'+d(0)+b'\0'+h(0)+d(0)+d(1,0)+b'\0\0'+d(0)+b'\0\0'+b'\0'+d(0,0,0,0xffffff)+(bytes(24) if modern else b'')
    p=prefix+tail;n,rows=self.inspect(p)
    self.assertEqual(n,slots,(user,modern,len(p)));self.assertEqual([r['id'] for r in rows],ids)
    self.assertTrue(all(r['variant']==(6 if modern else 4) for r in rows))
    self.assertLess(self.inspect(p[:-1])[0],0)
 def test_unrecognized_layout_is_only_a_diagnostic(self):
  self.assertEqual(self.inspect(b'\x15'+bytes(280))[0],0)
  self.assertLess(self.inspect(b'\x04'+bytes(10))[0],0)
