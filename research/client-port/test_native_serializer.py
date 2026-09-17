"""Execute the actual Interlude serializer on both wire contracts, not a reimplementation."""
import hashlib,struct,unittest
import pefile
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EAX,UC_X86_REG_EIP
from test_cpp_core import ROOT
class NativeSerializerTests(unittest.TestCase):
 def test_enterworld_original_and_c4_contract_with_variable_blob(self):
  raw=(ROOT/'build/interlude-engine.dll').read_bytes()
  self.assertEqual(hashlib.sha256(raw).hexdigest(),'508974c711f207402719e92737e211a2f029c95c2f68fc0e1c31fcbb9dbb232d')
  pe=pefile.PE(data=raw,fast_load=True);u=Uc(UC_ARCH_X86,UC_MODE_32)
  u.mem_map(0x10402000,0x1000);u.mem_write(0x10402000,pe.get_data(0x102000,0x1000))
  u.mem_map(0x107a6000,0x1000);u.mem_map(0x200000,0x30000)
  def copy(uc,addr,size,unused):
   if addr!=0x107a6260:return
   sp=u.reg_read(UC_X86_REG_ESP);ret,dst,src,n=struct.unpack('<IIII',u.mem_read(sp,16))
   self.assertLessEqual(n,4096);u.mem_write(dst,bytes(u.mem_read(src,n)))
   u.reg_write(UC_X86_REG_EAX,dst);u.reg_write(UC_X86_REG_ESP,sp+4);u.reg_write(UC_X86_REG_EIP,ret)
  u.hook_add(UC_HOOK_CODE,copy)
  for count in [0,1,4,32,256]:
   blob=bytes((i*37+9)&255 for i in range(count*4));extra=bytes(range(64))
   u.mem_write(0x210000,blob or b'\0');u.mem_write(0x212000,extra)
   values=[3,len(blob),0x210000,11,22,33,44,64,0x212000,0x12345678]+list(range(20))
   u.mem_write(0x214000,struct.pack('<'+'I'*len(values),*values))
   outputs=[]
   for fmt in [b'cbddddbd'+b'c'*20,b'cbdddd']:
    u.mem_write(0x216000,fmt+b'\0');u.mem_write(0x208000,struct.pack('<IIIII',0x220000,0x200000,8190,0x216000,0x214000));u.reg_write(UC_X86_REG_ESP,0x208000)
    try:u.emu_start(0x104021f0,0x220000,count=100000)
    except Exception as e:raise AssertionError(hex(u.reg_read(UC_X86_REG_EIP))) from e
    n=u.reg_read(UC_X86_REG_EAX);self.assertLess(n,8191);outputs.append(bytes(u.mem_read(0x200000,n)))
   expected=b'\x03'+blob+struct.pack('<IIII',11,22,33,44)
   self.assertEqual(outputs[1],expected)
   self.assertEqual(outputs[0],expected+extra+struct.pack('<I',0x12345678)+bytes(range(20)))
   self.assertEqual(len(outputs[0])-len(outputs[1]),88)
