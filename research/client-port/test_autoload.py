import unittest,struct
from pathlib import Path
import pefile
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import *
from ini_codec import decode,encode
from make_autoload_package import patch,SOURCE,ROOT
class AutoloadTests(unittest.TestCase):
    def test_ini(self):
        for label,path in [('killer',ROOT.parent.parent/'system'),('system-1',SOURCE),('interlude-reference',Path('/Users/wenderteixeira/Desktop/C6_System_Win10Supported'))]:
            raw=(path/'l2.ini').read_bytes(); decoded=decode(raw)
            self.assertEqual(decode(encode(decoded)),decoded)
            (ROOT/(label+'-l2.ini.decoded')).write_bytes(decoded)
    def test_imports_and_stub(self):
        raw=(SOURCE/'l2.exe').read_bytes(); original=pefile.PE(data=raw); result=patch(raw); pe=pefile.PE(data=result)
        def imports(p): return [(e.dll,[(i.name,i.ordinal,i.address) for i in e.imports]) for e in p.DIRECTORY_ENTRY_IMPORT]
        self.assertEqual(imports(original),imports(pe)[:-1]);self.assertEqual(pe.DIRECTORY_ENTRY_IMPORT[-1].imports[0].name,b'l2k_bootstrap')
        dll=pefile.PE(str(ROOT/'build/L2KProtocolCore.dll'))
        self.assertIn(b'l2k_bootstrap',[s.name for s in dll.DIRECTORY_ENTRY_EXPORT.symbols])
        for base in [original.OPTIONAL_HEADER.ImageBase,0x20000000]:
            u=Uc(UC_ARCH_X86,UC_MODE_32);u.mem_map(base,pe.OPTIONAL_HEADER.SizeOfImage)
            u.mem_write(base,pe.get_memory_mapped_image());u.mem_map(0x30000000,0x10000);u.mem_map(0x40000000,0x1000);u.mem_write(0x40000000,b'\xc3')
            iat=pe.DIRECTORY_ENTRY_IMPORT[-1].imports[0].address-pe.OPTIONAL_HEADER.ImageBase
            u.mem_write(base+iat,struct.pack('<I',0x40000000))
            regs=[UC_X86_REG_EAX,UC_X86_REG_EBX,UC_X86_REG_ECX,UC_X86_REG_EDX,UC_X86_REG_ESI,UC_X86_REG_EDI,UC_X86_REG_EBP]
            for j,r in enumerate(regs):u.reg_write(r,0x123400+j)
            u.reg_write(UC_X86_REG_ESP,0x30008000);u.reg_write(UC_X86_REG_EFLAGS,0x246)
            calls=[]
            def hook(uc,address,size,user):
                if address==0x40000000:
                    calls.append(address)
                    for r in regs:uc.reg_write(r,0xdeadbeef)
                    uc.reg_write(UC_X86_REG_EFLAGS,0x202)
            u.hook_add(UC_HOOK_CODE,hook)
            u.emu_start(base+pe.OPTIONAL_HEADER.AddressOfEntryPoint,base+original.OPTIONAL_HEADER.AddressOfEntryPoint,count=100)
            self.assertEqual(len(calls),1)
            self.assertEqual(u.reg_read(UC_X86_REG_EIP),base+original.OPTIONAL_HEADER.AddressOfEntryPoint)
            for j,r in enumerate(regs):self.assertEqual(u.reg_read(r),0x123400+j)
            self.assertEqual(u.reg_read(UC_X86_REG_ESP),0x30008000);self.assertEqual(u.reg_read(UC_X86_REG_EFLAGS),0x246)
        with self.assertRaises(ValueError):patch(result)
if __name__=='__main__':unittest.main()
