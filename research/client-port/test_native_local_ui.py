"""Compare local HTML queueing with the original Interlude receive/queue code."""
import struct
import unittest
import pefile
import test_login_hooks as harness
from test_cpp_core import ROOT
from test_structured_codec import d,s
from unicorn.x86_const import UC_X86_REG_ECX,UC_X86_REG_EAX

class NativeLocalUITests(unittest.TestCase):
    def setUp(self):
        self.h=harness.LoginHooksTests(methodName='runTest');self.h.setUp();h=self.h
        self.engine=pefile.PE(data=(ROOT/'build/interlude-engine.dll').read_bytes(),fast_load=True)
        h.u.mem_map(0x600000,0x100000)
        h.u.mem_map(h.engine+0x1a8d000,0x2000)
        h.u.mem_map(h.engine+0xadd000,0x1000)
        self.allocator=0x600000;self.network=0x610000;self.heap=0x620000
        self.events=[];self.allocated=[];self.freed=[];self.fail_at=None
        h.w32(h.engine+0x1a8d6a0,0x600080);h.w32(0x600080,self.allocator)
        h.w32(self.allocator,0x600100);h.w32(0x600100,0x400e00);h.w32(0x600108,0x400e10)
        h.callbacks[0x400e00]=self.allocate;h.callbacks[0x400e10]=self.release
        h.w32(h.engine+0x81f538,self.network);h.w32(self.network,0x610200)
        h.w32(0x610284,h.engine+0x12b7d0);h.w32(self.network+0x3c,0x680000)
        h.w32(h.engine+0x1a8e91c,0x400e20);h.w32(h.engine+0x1a8e918,0x400e30)
        h.w32(h.engine+0x1a8d8b0,0x400e40)
        h.callbacks[0x400e20]=lambda:self.lock('enter')
        h.callbacks[0x400e30]=lambda:self.lock('leave')
        h.callbacks[0x400e40]=self.array_add
        h.callbacks[h.engine+0x4a6260]=self.copy
        h.w32(h.engine+0xadd7e0,0x600200);h.w32(h.sock+0x50f0,0)
        for rva,size in [(0x120e60,0x140),(0x12b7d0,0x40)]:
            h.u.mem_write(h.engine+rva,self.engine.get_data(rva,size))
        h.symbols['test_original_receive']=h.engine+0x120e60
    def allocate(self):
        h=self.h;n,label=h.args(2);self.assertEqual(h.u.reg_read(UC_X86_REG_ECX),self.allocator)
        if self.fail_at==len(self.allocated):h.ret(8,0);return
        address=self.heap;self.heap+=(n+15)&~15;self.allocated.append((address,n));h.u.mem_write(address,bytes([0xa5])*n);h.ret(8,address)
    def release(self):
        h=self.h;self.freed.append(h.args(1)[0]);h.ret(4)
    def lock(self,event):
        h=self.h;self.assertEqual(h.args(1),[self.network+0x16c]);self.events.append(event);h.ret(4)
    def array_add(self):
        h=self.h;self.assertEqual(h.u.reg_read(UC_X86_REG_ECX),self.network+0x3c);self.assertEqual(h.args(2),[1,4]);self.events.append('append');h.ret(8,0)
    def copy(self):
        h=self.h;dst,src,n=h.args(3);h.u.mem_write(dst,bytes(h.u.mem_read(src,n)));h.ret(value=dst)
    def queued(self):
        h=self.h;packet=h.r32(0x680000);header=bytes(h.u.mem_read(packet,12));op=header[0];ext=struct.unpack_from('<H',header,2)[0];n,p=struct.unpack_from('<II',header,4)
        return op,ext,n,bytes(h.u.mem_read(p,n+1))
    def test_same_owned_descriptor_and_native_locked_queue_without_cipher_mutation(self):
        h=self.h;payload=b'\x0f'+d(0)+s('<html><body>Clã &amp; direitos</body></html>')+d(0)
        frame=struct.pack('<H',len(payload)+2)+payload;h.u.mem_write(h.buf,frame);h.w32(h.sock+0x50bc,0)
        h.call('test_original_receive',[h.buf,len(frame)],h.sock,8);expected=self.queued()
        self.assertEqual(self.events,['enter','append','leave']);self.events=[]
        h.w32(h.sock+0x50bc,1);h.u.mem_write(h.sock+0x50c0,bytes(range(64)));before=bytes(h.u.mem_read(h.sock+0x50bc,68))
        h.u.mem_write(h.buf,payload);h.call('l2k_queue_local_html(',[h.buf,len(payload)])
        self.assertEqual(h.u.reg_read(UC_X86_REG_EAX),1);self.assertEqual(self.queued(),expected)
        self.assertEqual(self.events,['enter','append','leave']);self.assertEqual(bytes(h.u.mem_read(h.sock+0x50bc,68)),before)
        self.assertEqual(self.allocated[-2:][0][1],len(payload));self.assertEqual(self.allocated[-1][1],12)
    def test_extended_local_packet_matches_original_receive_descriptor(self):
        h=self.h
        for payload in [b'\xfe\x3d\x00'+d(0)+s('Member')+s('')+d(0)+s('')+s(''),b'\xfe\x3d\x00'+d(0)+s('A'*63)+s('')+d(0)+s('')+s(''),b'\x0f'+d(0)+s('<html/>')+d(0)]:
            with self.subTest(opcode=payload[:3].hex()):
                # Zero the bytes after the frame: the native copy over-reads them for FE packets.
                frame=struct.pack('<H',len(payload)+2)+payload;h.u.mem_write(h.buf,frame+bytes(4));h.w32(h.sock+0x50bc,0)
                h.call('test_original_receive',[h.buf,len(frame)],h.sock,8);expected=self.queued();sizes=[n for _,n in self.allocated[-2:]];self.events=[]
                h.w32(h.sock+0x50bc,1);before=bytes(h.u.mem_read(h.sock+0x50bc,68))
                h.u.mem_write(h.buf,payload+bytes(4));h.call('l2k_queue_local_packet(',[h.buf,len(payload)])
                self.assertEqual(h.u.reg_read(UC_X86_REG_EAX),1);self.assertEqual(self.queued(),expected)
                self.assertEqual([n for _,n in self.allocated[-2:]],sizes)
                self.assertEqual(self.events,['enter','append','leave']);self.events=[]
                self.assertEqual(bytes(h.u.mem_read(h.sock+0x50bc,68)),before)
    def test_extended_local_packet_rejects_short_or_oversized_input(self):
        h=self.h;count=len(self.allocated)
        for payload in [b'',b'\xfe',b'\xfe\x3d',b'\x0f'+bytes(8190)]:
            h.u.mem_write(h.buf,payload or b'\0');h.call('l2k_queue_local_packet(',[h.buf,len(payload)])
            self.assertEqual(h.u.reg_read(UC_X86_REG_EAX),0)
        self.assertEqual(len(self.allocated),count)
    def test_failed_descriptor_allocation_releases_body_and_never_queues(self):
        h=self.h;self.fail_at=1;payload=b'\x0f'+d(0)+s('<html/>')+d(0);h.u.mem_write(h.buf,payload)
        h.call('l2k_queue_local_html(',[h.buf,len(payload)])
        self.assertEqual(h.u.reg_read(UC_X86_REG_EAX),0);self.assertEqual(self.freed,[self.allocated[0][0]]);self.assertEqual(self.events,[])
