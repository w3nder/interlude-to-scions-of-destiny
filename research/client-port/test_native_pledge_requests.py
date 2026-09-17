"""Read request contracts by executing the original sender functions to send()."""
import ctypes as C
import struct
import unittest
import pefile
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_ECX
from test_cpp_core import ROOT

class NativePledgeRequestsTests(unittest.TestCase):
    def test_actions_match_original_c4_sender_and_reject_interlude_update(self):
        lib=C.CDLL(str(ROOT/'build/libl2k_protocol.dylib'))
        fn=lib.l2k_outbound_convert
        fn.argtypes=[C.c_void_p,C.c_uint32];fn.restype=C.c_int
        for modern,path,entry,slot in [(False,ROOT.parent.parent/'system/engine.dll',0x103fb950,0x64),(True,ROOT/'build/interlude-engine.dll',0x10409980,0x68)]:
            pe=pefile.PE(data=path.read_bytes(),fast_load=True)
            pe.parse_data_directories(directories=[1])
            for action in ([0,1,2,3,0xffffffff] if not modern else [1,2]):
                u=Uc(UC_ARCH_X86,UC_MODE_32)
                u.mem_map(entry&~0xfff,0x1000)
                u.mem_write(entry,pe.get_data(entry-pe.OPTIONAL_HEADER.ImageBase,0x110))
                for addr in [0x200000,0x300000,0x301000,0x302000,0x303000,0x304000,0x400000]:u.mem_map(addr,0x1000)
                put=lambda addr,value:u.mem_write(addr,struct.pack('<I',value))
                if modern:
                    glog=next(e.address for d in pe.DIRECTORY_ENTRY_IMPORT for e in d.imports if e.name==b'?GLog@@3PAVFOutputDevice@@A')
                    u.mem_map(glog&~0xfff,0x1000);put(glog,0x304000)
                put(0x300048,0x301000);put(0x301000,0x302000);put(0x302000+slot,0x400100)
                u.mem_write(0x303000,bytes(32))
                u.mem_write(0x200800,struct.pack('<IIII',0x400000,77,action,0x303000))
                u.reg_write(UC_X86_REG_ESP,0x200800);u.reg_write(UC_X86_REG_ECX,0x300000)
                u.emu_start(entry,0x400100,count=3000)
                stack=u.reg_read(UC_X86_REG_ESP)
                args=struct.unpack('<8I',u.mem_read(stack,32))
                fmt=pe.get_data(args[2]-pe.OPTIONAL_HEADER.ImageBase,32).split(b'\0')[0]
                expected=b'cdd' if action==1 or (not modern and action==2) else b'cddd' if modern else b'cddb'
                self.assertEqual(fmt,expected);self.assertEqual(args[3:6],(0xc0,77,action))
                extra=struct.pack('<I',args[6]) if modern and action==2 else bytes(32) if not modern and action not in [1,2] else b''
                if not modern and action not in [1,2]:self.assertEqual(args[6:8],(32,0x303000))
                packet=b'\xc0'+struct.pack('<II',77,action)+extra
                buf=C.create_string_buffer(packet);result=fn(buf,len(packet))
                self.assertEqual(bytes(buf)[:len(packet)],packet)
                self.assertEqual(result<0,modern and action==2)
