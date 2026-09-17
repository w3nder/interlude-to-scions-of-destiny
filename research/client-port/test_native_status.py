"""Run the original StatusUpdate loops, decoders and experience setters."""
import ctypes as C
import json
import struct
import unittest
from native_emitter_audit import NativeEmitter,ROOT,PROFILES
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import *


class NativeStatusTests(unittest.TestCase):
    def test_every_c4_status_tag_and_unsigned_experience(self):
        lib=C.CDLL(str(ROOT/'build/libl2k_protocol.dylib'))
        thunk=lib.l2k_status_exp_thunk
        thunk.argtypes=[C.c_void_p,C.c_uint32,C.c_uint32,C.c_uint32];thunk.restype=C.c_int
        engines={side:NativeEmitter(side) for side in PROFILES}
        for side,e in engines.items():
            e.top_calls=0;e.inner_formats=[]
            global_address=0x109d5e68 if side=='source' else 0x10b1f538
            e._map_image(e.u,0,global_address,4,0,None);e.put(global_address,e.DATA)
            e.put(e.DATA+0x48,e.DATA+0x1000);e.put(e.DATA+0x54,e.DATA+0x2000)
            e.put(e.DATA+0x2000,e.DATA+0x3000)
            for offset in range(0xb8,0x130,4):
                slot=offset+(0xc0 if side=='target' else 0)
                entry=e.STOP+0x400+offset
                if offset==0xc0:entry=0x1046cf60 if side=='source' else 0x10488600
                e.put(e.DATA+0x3000+slot,entry)
            if side=='target':
                address=e.STOP+0x800;code=C.create_string_buffer(30)
                self.assertEqual(thunk(code,30,0x10300000,address),30)
                e.u.mem_write(address,code.raw)
                e._map_image(e.u,0,0x10426560,4,0,None)
                self.assertEqual(bytes(e.u.mem_read(0x10426560,4)),struct.pack('<I',0x10426523))
                e.put(0x10426560,address)
        expected_slots={tag:0xb8+tag*4 for tag in range(11)}
        expected_slots.update({tag:0xec+(tag-11)*4 for tag in range(11,28)})
        expected_slots.update({33:0xe4,34:0xe8})
        reports=[]
        cases=[[(tag,value)] for tag in range(36) for value in [0,1,0x7fffffff,0x80000000,0xffffffff]]
        cases+=[[(tag,tag*100+17) for tag in range(35)],[],[(2,0xffffffff),(2,1),(9,999)]]
        for rows in cases:
            outputs=[]
            for side,e in engines.items():
                u=e.u;sp=e.STACK+0x20000;user=e.DATA+0x4000;payload=e.DATA+0x8000
                packet=b''.join(struct.pack('<II',tag,value) for tag,value in rows)
                u.mem_write(user,bytes(0x100));u.mem_write(payload,packet or b'\0')
                u.mem_write(sp,bytes(0x100));e.put(sp+0xc,len(rows))
                e.put(e.DATA+0x1000+(0x4e48 if side=='source' else 0x4ef8),payload+len(packet))
                for reg,value in [(UC_X86_REG_ESP,sp),(UC_X86_REG_EBX,e.DATA),(UC_X86_REG_ESI,user),(UC_X86_REG_EDI,payload)]:u.reg_write(reg,value)
                events=[]
                def edge(uc,address,size,unused):
                    if e.STOP+0x4b8<=address<e.STOP+0x530:
                        stack=uc.reg_read(UC_X86_REG_ESP);ret,who,value=struct.unpack('<III',uc.mem_read(stack,12))
                        self.assertEqual(who,user);self.assertEqual(uc.reg_read(UC_X86_REG_ECX),e.DATA+0x2000)
                        events.append((address-e.STOP-0x400,value));uc.reg_write(UC_X86_REG_EAX,1)
                        uc.reg_write(UC_X86_REG_ESP,stack+12);uc.reg_write(UC_X86_REG_EIP,ret)
                hook=u.hook_add(UC_HOOK_CODE,edge)
                start,stop=(0x10415016,0x1041539f) if side=='source' else (0x10426285,0x1042652e)
                try:u.emu_start(start,stop,count=100000)
                finally:u.hook_del(hook)
                self.assertEqual(u.reg_read(UC_X86_REG_EIP),stop)
                self.assertEqual(u.reg_read(UC_X86_REG_ESP),sp)
                self.assertEqual(u.reg_read(UC_X86_REG_EDI),payload+len(packet))
                self.assertEqual(events,[(expected_slots[tag],value) for tag,value in rows if tag in expected_slots and tag!=2])
                experience=int.from_bytes(u.mem_read(user+0x5c,4 if side=='source' else 8),'little')
                self.assertEqual(experience,next((value for tag,value in reversed(rows) if tag==2),0))
                outputs.append((events,experience))
            self.assertEqual(*outputs)
        report={'status':'passed','hashes':{s:p['sha256'] for s,p in PROFILES.items()},'vector_pairs':len(cases),
                'opcode':'0x0E','source_handler':'0x10414f80','target_handler':'0x104261f0',
                'target_switch_slot':'0x10426560','target_original_destination':'0x10426523',
                'change':'Restore C4 tag 2 via native OnExpUpdate(User*, int64); zero-extend unsigned 32-bit experience.',
                'scope':'Actual native decoder, count loop, every C4 status tag, dispatch and native experience setters. Object lookup is pre-established; other UI callbacks observed at their ABI boundary.'}
        (ROOT/'reports/native-status-update.json').write_text(json.dumps(report,indent=2)+'\n')

    def test_thunk_capacity_does_not_write_partial_code(self):
        lib=C.CDLL(str(ROOT/'build/libl2k_protocol.dylib'));fn=lib.l2k_status_exp_thunk
        fn.argtypes=[C.c_void_p,C.c_uint32,C.c_uint32,C.c_uint32];fn.restype=C.c_int
        for capacity in [0,1,29]:
            out=C.create_string_buffer(b'\xa5'*30,30)
            self.assertLess(fn(out,capacity,0x10300000,0x4000000),0);self.assertEqual(out.raw,b'\xa5'*30)
