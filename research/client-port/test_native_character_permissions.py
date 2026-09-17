"""Compare legacy permission flags using the actual two x86 client methods."""
import ctypes as C
import struct
import unittest
import pefile
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_ECX
from test_cpp_core import ROOT
from test_character_codec import character

class NativeCharacterPermissionsTests(unittest.TestCase):
    def test_every_source_bit_preserves_native_legacy_flags(self):
        lib=C.CDLL(str(ROOT/'build/libl2k_protocol.dylib'))
        fn=lib.l2k_character_convert
        fn.argtypes=[C.c_void_p,C.c_uint32,C.c_void_p,C.c_uint32];fn.restype=C.c_int
        engines=[]
        for path,entry,flags in [(ROOT.parent.parent/'system/engine.dll',0x10353010,0x228),(ROOT/'build/interlude-engine.dll',0x10358a80,0x2d8)]:
            pe=pefile.PE(data=path.read_bytes(),fast_load=True)
            u=Uc(UC_ARCH_X86,UC_MODE_32);u.mem_map(entry&~0xfff,0x1000)
            u.mem_write(entry,pe.get_data(entry-pe.OPTIONAL_HEADER.ImageBase,0x90))
            for address in [0x200000,0x300000,0x400000,0x500000]:u.mem_map(address,0x1000)
            engines.append((u,entry,flags))
        for rights in [bytes(32),bytes([255])*32]+[(1<<bit).to_bytes(32,'little') for bit in range(256)]:
            src=character(True,False,rights=rights);out=C.create_string_buffer(2048)
            n=fn(src,len(src),out,len(out));self.assertGreater(n,0)
            # The suffix starts immediately after the privilege field; it is
            # independently identified by this fixture's fixed trailing fields.
            marker=struct.pack('<HHIH',1,2,3,100)
            self.assertEqual(out.raw[:n].count(marker),1)
            offset=out.raw[:n].index(marker)-4
            mask=struct.unpack_from('<I',out.raw,offset)[0]
            values=[]
            for index,(u,entry,flags) in enumerate(engines):
                u.mem_write(0x300000,bytes(0x1000));u.mem_write(0x500000,rights)
                u.mem_write(0x200800,struct.pack('<II',0x400000,0x500000 if index==0 else mask))
                u.reg_write(UC_X86_REG_ESP,0x200800);u.reg_write(UC_X86_REG_ECX,0x300000)
                u.emu_start(entry,0x400000,count=200)
                values.append(bytes(u.mem_read(0x300000+flags,4)))
                if index:self.assertEqual(bytes(u.mem_read(0x300000+flags+4,3)),bytes(3))
            self.assertEqual(values[0],values[1],rights.hex())
