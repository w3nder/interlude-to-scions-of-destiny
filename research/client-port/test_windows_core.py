"""Execute the compiled Windows x86 game-cipher export in an emulator."""
import random
import struct
import unittest
from pathlib import Path
import pefile
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EAX,UC_X86_REG_EIP
from game_transport import C4Cipher

ROOT=Path(__file__).resolve().parent


class WindowsCoreTests(unittest.TestCase):
    def test_compiled_x86_export_matches_transport_model(self):
        pe=pefile.PE(str(ROOT/'build/L2KProtocolCore.dll'))
        self.assertEqual(pe.FILE_HEADER.Machine,0x14c)
        exports={s.name.decode():s.address for s in pe.DIRECTORY_ENTRY_EXPORT.symbols if s.name}
        self.assertIn('l2k_login_step',exports)
        base=pe.OPTIONAL_HEADER.ImageBase
        uc=Uc(UC_ARCH_X86,UC_MODE_32)
        uc.mem_map(base,(pe.OPTIONAL_HEADER.SizeOfImage+4095)&~4095)
        uc.mem_write(base,pe.get_memory_mapped_image())
        for addr,size in [(0x200000,0x20000),(0x300000,4096),(0x400000,0x20000)]:uc.mem_map(addr,size)
        rng=random.Random(656746)
        for decrypt in (0,1):
            key=bytes.fromhex('feffffffa16c5487');model=C4Cipher(key)
            uc.mem_write(0x410000,key+key+struct.pack('<I',1))
            for length in [1,2,7,8,9,16,31,256,8190]:
                with self.subTest(decrypt=decrypt,length=length):
                    payload=rng.randbytes(length);uc.mem_write(0x400000,payload)
                    uc.mem_write(0x210000,struct.pack('<IIIII',0x300000,0x410000,0x400000,length,decrypt))
                    uc.reg_write(UC_X86_REG_ESP,0x210000)
                    uc.emu_start(base+exports['l2k_game_transform'],0x300000,count=1000000)
                    self.assertEqual(uc.reg_read(UC_X86_REG_EIP),0x300000)
                    self.assertEqual(uc.reg_read(UC_X86_REG_EAX),length)
                    self.assertEqual(uc.reg_read(UC_X86_REG_ESP),0x210004) # cdecl caller cleanup
                    expected=model.decrypt(payload) if decrypt else model.encrypt(payload)
                    self.assertEqual(bytes(uc.mem_read(0x400000,length)),expected)
                    self.assertEqual(bytes(uc.mem_read(0x410000+8*decrypt,8)),model.key)


if __name__=='__main__':unittest.main()
