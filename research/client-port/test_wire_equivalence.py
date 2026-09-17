"""Differential binary evidence tests; no live server or captured payloads."""
import hashlib,json,struct,unittest
from types import SimpleNamespace
import capstone,pefile
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_ESP
from audit_wire_equivalence import Prefix,Unsupported,reachable,SOURCE_HASH,ROOT

class TinyEngine:
    def __init__(self,body,strings=None):
        self.body=body;self.strings=strings or {};self.md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);self.md.detail=True
        self.pe=SimpleNamespace(DIRECTORY_ENTRY_IMPORT=[]);self.raw_sha=SOURCE_HASH
    def data(self,va,n):return self.body[va-0x1000:va-0x1000+n] if 0x1000<=va<0x1000+len(self.body) else b''
    def fmt(self,va):return self.strings.get(va)
    def resolve(self,va):return va

class WireEquivalenceTests(unittest.TestCase):
    def test_reachable_does_not_include_next_function(self):
        e=TinyEngine(bytes.fromhex('31c0c39090e800000000c3'))
        nodes,errors=reachable(e,0x1000);self.assertEqual(list(sorted(nodes)),[0x1000,0x1002]);self.assertEqual(errors,[])
    def test_reachable_follows_both_paths_and_back_edges(self):
        e=TinyEngine(bytes.fromhex('85c0740390ebf9c3'))
        nodes,errors=reachable(e,0x1000);self.assertEqual(set(nodes),{0x1000,0x1002,0x1004,0x1005,0x1007});self.assertEqual(errors,[])
    def test_same_format_different_constant_is_not_equal(self):
        # mov eax,[ecx+48]; mov ecx,[eax]; push value; push opcode;
        # push fmt; push socket; call [ecx+64].
        def contract(value):
            code=bytes.fromhex('8b41488b086a')+bytes([value])+bytes.fromhex('6a14680020000050ff5164')
            e=TinyEngine(code,{0x2000:'cd'});return Prefix(e).contract(0x1000,0x1000+len(code)-3,'cd')
        self.assertNotEqual(contract(1),contract(2));self.assertEqual(contract(1)['arguments'],[20,1])
    def test_unknown_helper_and_control_flow_never_get_wildcard(self):
        for body in [bytes.fromhex('e800000000c3'),bytes.fromhex('7400c3')]:
            with self.assertRaises(Unsupported):Prefix(TinyEngine(body)).contract(0x1000,0x1010,'c')
    def test_native_parameter_stack_helpers_have_same_sequence_contract(self):
        src=pefile.PE(str(ROOT.parent.parent/'system/engine.dll'))
        path=ROOT/'build/interlude-core.dll'
        if not path.exists():path=ROOT.parent.parent.parent.parent/'Downloads/Lineage2_Interlude_Client/system/Core.dll'
        # Use the exact installed Core dependency, not an assumed import behavior.
        if not path.exists():path=__import__('pathlib').Path('/Users/wenderteixeira/Downloads/Lineage2_Interlude_Client/system/Core.dll')
        target=pefile.PE(str(path))
        export=next(e for e in target.DIRECTORY_ENTRY_EXPORT.symbols if e.name==b'?Top@L2ParamStack@@QAEPAXXZ')
        va=target.OPTIONAL_HEADER.ImageBase+export.address
        while target.get_data(va-target.OPTIONAL_HEADER.ImageBase,1)==b'\xe9':va+=5+struct.unpack('<i',target.get_data(va-target.OPTIONAL_HEADER.ImageBase+1,4))[0]
        for pe,entry,cursor,count in [(src,0x1046c7a0,8,12),(target,va,4,8)]:
            for length in [0,1,7]:
                u=Uc(UC_ARCH_X86,UC_MODE_32);page=entry&~0xfff;u.mem_map(page,0x2000);u.mem_write(entry,pe.get_data(entry-pe.OPTIONAL_HEADER.ImageBase,0x100))
                u.mem_map(0,0x1000);u.mem_map(0x200000,0x10000);u.mem_map(0x300000,0x10000);u.mem_map(0x400000,0x1000)
                put=lambda addr,value:u.mem_write(addr,struct.pack('<I',value))
                put(0x300000,0x301000);put(0x300000+cursor,0);put(0x300000+count,length)
                values=[0xA0100000+i for i in range(length)]
                for i,v in enumerate(values):put(0x301000+i*4,v)
                for expected in values+[0,0]:
                    put(0x208000,0x400000);u.reg_write(UC_X86_REG_ESP,0x208000);u.reg_write(UC_X86_REG_ECX,0x300000)
                    u.emu_start(entry,0x400000,count=1000);self.assertEqual(u.reg_read(UC_X86_REG_EAX),expected)
                self.assertEqual(struct.unpack('<I',u.mem_read(0x300000+cursor,4))[0],length)
        report={'source_engine_sha256':hashlib.sha256((ROOT.parent.parent/'system/engine.dll').read_bytes()).hexdigest(),'target_core_sha256':hashlib.sha256(path.read_bytes()).hexdigest(),'target_top_va':hex(va),'tested_counts':[0,1,7],'status':'passed native x86 sequence/cursor/empty checks'}
        (ROOT/'reports/parameter-stack-evidence.json').write_text(json.dumps(report,indent=2)+'\n')
