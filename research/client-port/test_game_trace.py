"""Ensure observers preserve the actual Interlude cipher and calling convention."""
import struct,unittest
import pefile
from unicorn.x86_const import UC_X86_REG_ECX,UC_X86_REG_EAX
import test_login_hooks as harness
from test_cpp_core import ROOT

class GameTraceTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.engine=pefile.PE(str(ROOT/'build/interlude-engine.dll'),fast_load=True)
    def setUp(self):
        self.h=harness.LoginHooksTests(methodName='runTest');self.h.setUp();h=self.h
        self.events=[];self.state=h.sock+0x50c0
        for rva,size in [(0x101fd0,0x80),(0x102070,0x90)]:h.u.mem_write(h.engine+rva,self.engine.get_data(rva,size))
        h.w32(h.symbol('game_trace::encrypt_original'),h.engine+0x101fd0);h.w32(h.symbol('game_trace::decrypt_original'),h.engine+0x102070)
        h.w32(h.symbol('game_trace::receive_original'),h.engine+0x120e60)
        h.callbacks[h.symbol('game_trace::record(')]=self.observe
        h.callbacks[h.engine+0x4a67d9]=self.native_copy
        h.callbacks[h.engine+0x120e60]=self.native_receive
    def native_copy(self):
        h=self.h;dst,cap,src,n=h.args(4);self.assertLessEqual(n,cap);h.u.mem_write(dst,bytes(h.u.mem_read(src,n)));h.ret(value=0)
    def observe(self):
        h=self.h;sock,direction,stage,data,n=h.args(5);self.assertEqual(sock,h.sock)
        self.events.append((bytes(h.u.mem_read(direction,4)).split(b'\0')[0],bytes(h.u.mem_read(stage,32)).split(b'\0')[0],bytes(h.u.mem_read(data,n))))
        h.ret()
    def native_receive(self):
        h=self.h;p,n=h.args(2);h.frames.append(bytes(h.u.mem_read(p,n)));h.ret(8)
    def test_observer_matches_original_cipher_with_evolving_key(self):
        h=self.h;key=bytes.fromhex('aabbccdd01020304feffffffffffffff');h.u.mem_write(self.state,b'\1'+key)
        for decrypt,needle,rva in [(False,'encrypt_observer',0x101fd0),(True,'decrypt_observer',0x102070)]:
            for n in [1,3,21,97,511]:
                payload=bytes((i*17+19)%256 for i in range(n));before=bytes(h.u.mem_read(self.state,17));h.u.mem_write(h.buf,payload)
                # Run the native cipher directly to obtain output and evolved state.
                h.symbols['test_native_cipher']=h.engine+rva;h.call('test_native_cipher',[h.buf,self.state,n],h.sock,12)
                expected=bytes(h.u.mem_read(h.buf,n));state_after=bytes(h.u.mem_read(self.state,17))
                h.u.mem_write(self.state,before);h.u.mem_write(h.buf,payload);h.call(needle,[h.buf,self.state,n],h.sock,12)
                self.assertEqual(bytes(h.u.mem_read(h.buf,n)),expected);self.assertEqual(bytes(h.u.mem_read(self.state,17)),state_after)
                self.assertEqual(self.events[-1][2],expected if decrypt else payload)
                self.assertEqual(self.events[-1][0],b'S2C' if decrypt else b'C2S')
    def test_receive_plaintext_once_and_passthrough(self):
        h=self.h;frame=struct.pack('<H',20)+b'\0'+bytes(range(17));h.u.mem_write(h.buf,frame)
        h.w32(h.sock+0x50bc,0);h.call('receive_observer',[h.buf,len(frame)],h.sock,8)
        self.assertEqual(h.frames,[frame]);self.assertEqual(self.events[0][2],frame[2:])
        h.w32(h.sock+0x50bc,1)
        # Native decryption is already independently compared above; simulate its edge here.
        h.callbacks[h.engine+0x102070]=lambda:h.ret(12)
        h.call('receive_observer',[h.buf,len(frame)],h.sock,8)
        self.assertEqual(h.frames,[frame,frame]);self.assertEqual(len(self.events),2)
    def test_installation_refuses_mismatch_without_changes(self):
        h=self.h;table=[(0x58b594,0xd184),(0x58b5a0,0x89e0),(0x58b5a4,0xe408),(0x58b5a8,0x3116)]
        for slot,target in table:h.w32(h.engine+slot,h.engine+target)
        h.w32(h.engine+table[-1][0],0)
        h.call('l2k_install_game_trace()',[])
        self.assertEqual(h.u.reg_read(UC_X86_REG_EAX),0)
        self.assertEqual(h.r32(h.engine+table[0][0]),h.engine+table[0][1])

    def test_clan_conversion_before_native_ui_queue(self):
        from test_clan_codec import packets
        h=self.h;src,want=packets(9,2);frame=struct.pack('<H',len(src)+2)+src;h.u.mem_write(h.buf,frame);h.w32(h.sock+0x50bc,0)
        h.call('receive_observer',[h.buf,len(frame)],h.sock,8)
        self.assertEqual(h.frames,[struct.pack('<H',len(want)+2)+want]);self.assertEqual(h.r32(h.sock+0x50bc),0)
    def test_send_filter_runs_before_native_encryption_and_send(self):
        h=self.h;h.w32(h.symbol('game_trace::serialize_original'),h.engine+0x68b6);h.w32(h.symbol('game_trace::send_original'),h.engine+0x1029b0)
        sent=[]
        def serialize():
            dst,cap,fmt,args=h.args(4);h.u.mem_write(dst,self.outgoing);h.ret(value=len(self.outgoing))
        def send():
            sock,fmt,n,data=h.args(4);self.assertEqual(sock,h.sock);self.assertEqual(bytes(h.u.mem_read(fmt,2)),b'b\0');sent.append(bytes(h.u.mem_read(data,n)));h.ret()
        h.callbacks[h.engine+0x68b6]=serialize;h.callbacks[h.engine+0x1029b0]=send
        for packet in [b'\xd0\x19\0'+b'ignored',b'\x38'+b'chat',b'\x39'+b'skill',b'\xd0\x01\0'+b'legacy']:
            self.outgoing=packet;h.call('game_trace::send_adapter',[h.sock,h.buf]);
        self.assertEqual(sent,[b'\x38chat',b'\x39skill',b'\xd0\x01\0legacy'])

    def test_schema_conversion_after_single_decrypt_before_queue(self):
        h=self.h;src=b'\x58'+struct.pack('<IIII',1,0,10,1234);want=src+b'\0'
        frame=struct.pack('<H',len(src)+2)+src;h.u.mem_write(h.buf,frame);h.w32(h.sock+0x50bc,1)
        decrypted=[]
        def decrypt():
            decrypted.append(1);h.ret(12)
        h.callbacks[h.engine+0x102070]=decrypt
        h.call('receive_observer',[h.buf,len(frame)],h.sock,8)
        self.assertEqual(decrypted,[1]);self.assertEqual(h.r32(h.sock+0x50bc),1)
        self.assertEqual(h.frames,[struct.pack('<H',len(want)+2)+want])
        self.assertEqual(self.events[-1][1],b'converted_C4_schema')

    def test_structured_frames_and_rejection_keep_cipher_sequence(self):
        from test_structured_codec import d,h as word,s
        h=self.h;decrypted=[]
        def decrypt():
            decrypted.append(h.args(3)[2]);h.ret(12)
        h.callbacks[h.engine+0x102070]=decrypt;h.w32(h.sock+0x50bc,1)
        cases=[(b'\x29'+d(1,2,3,4,5),b'\x29'+d(1,2,3,4,5,0)),
               (b'\x44'+d(2,3,100,8,1),b'\x44'+d(2,3,100,8)+b'\0'+d(1)),
               (b'\x32'+d(99)+s('Clan'),b'\x32'+d(99)+s('Clan')+d(0)),
               (b'\x41'+word(1)+d(57)+word(1)+bytes(32),b'\x41'+word(1)+d(57)+word(1)+bytes(40)),
               (b'\xd0'+d(100,1,1,40,1)+d(7)+b'\0'+word(0,0),b'\xd0'+d(100,1,1,40,1)+d(7,0,0)+b'\0'+word(0,0)),
               (b'\x45'+d(0xffffffff),None),
               (b'\x15'+bytes(280),b'\x15'+bytes(280)),
               (b'\x15'+bytes(288),b'\x15'+bytes(288)),
               (b'\x2d\0',b'\x2d\0')]
        expected=[]
        for src,want in cases:
            frame=word(len(src)+2)+src;h.u.mem_write(h.buf,frame)
            h.call('receive_observer',[h.buf,len(frame)],h.sock,8)
            if want is not None:expected.append(word(len(want)+2)+want)
            self.assertEqual(h.r32(h.sock+0x50bc),1)
        self.assertEqual(decrypted,[len(src) for src,_ in cases]);self.assertEqual(h.frames,expected)

    def test_outbound_layout_conversion_and_unsupported_variants(self):
        from test_structured_codec import d
        h=self.h;sent=[]
        h.w32(h.symbol('game_trace::serialize_original'),h.engine+0x68b6)
        h.w32(h.symbol('game_trace::send_original'),h.engine+0x1029b0)
        def serialize():
            dst,cap,fmt,args=h.args(4);h.u.mem_write(dst,self.outgoing);h.ret(value=len(self.outgoing))
        def send():
            sock,fmt,n,data=h.args(4);sent.append(bytes(h.u.mem_read(data,n)));h.ret()
        h.callbacks[h.engine+0x68b6]=serialize;h.callbacks[h.engine+0x1029b0]=send
        cases=[(b'\x24'+d(123,0),b'\x24'+d(123)),(b'\x24'+d(123,100),None),
               (b'\xa7'+d(100,200,3,0,0),b'\xa7'+d(100,200,3)),
               (b'\xa7'+d(100,200,3,1,0),None),
               (b'\xc5'+d(12,1,999),b'\xc5'+d(12,1)),(b'\xc5\0',None),
               (b'\x71'+d(100,200,20,80),b'\x71'+d(100,200)),
               (b'\xd0\x0e\0'+d(1,999),b'\xd0\x0e\0'+d(1)),
               (b'\xd0\x0e\0'+d(1)+b'\0',None)]
        for packet,_ in cases:
            self.outgoing=packet;h.call('game_trace::send_adapter',[h.sock,h.buf])
        self.assertEqual(sent,[want for _,want in cases if want is not None])

    def test_large_frame_keeps_cipher_progress_and_native_queue(self):
        h=self.h;decrypted=[]
        def decrypt():
            data,state,n=h.args(3);decrypted.append(n);h.ret(12)
        h.callbacks[h.engine+0x102070]=decrypt;h.w32(h.sock+0x50bc,1)
        # A complete frame larger than the old artificial 8 KiB cap is valid.
        p=b'\x0f'+b'x'*8999;frame=struct.pack('<H',len(p)+2)+p
        h.u.mem_write(h.buf,frame);h.call('receive_observer',[h.buf,len(frame)],h.sock,8)
        small=struct.pack('<H',4)+b'\x2d\0';h.u.mem_write(h.buf,small);h.call('receive_observer',[h.buf,len(small)],h.sock,8)
        self.assertEqual(decrypted,[9000,2]);self.assertEqual(h.frames,[frame,small])
        self.assertEqual(h.r32(h.sock+0x50bc),1)

    def test_enterworld_serializer_boundary_preserves_variable_blob(self):
        h=self.h;sent=[];formats=[];blob=bytes(range(32));source=b'\x03'+blob+struct.pack('<IIII',11,22,33,44)
        h.w32(h.symbol('game_trace::serialize_original'),h.engine+0x68b6)
        h.w32(h.symbol('game_trace::send_original'),h.engine+0x1029b0)
        original=b'cbddddbd'+b'c'*20
        h.u.mem_write(h.buf,original+b'\0')
        def serialize():
            dst,cap,fmt,args=h.args(4);f=bytearray()
            while h.u.mem_read(fmt+len(f),1)!=b'\0':f+=h.u.mem_read(fmt+len(f),1)
            formats.append(bytes(f));out=source+bytes(88) if bytes(f)==original else source
            h.u.mem_write(dst,out);h.ret(value=len(out))
        def send():
            sock,fmt,n,data=h.args(4);sent.append(bytes(h.u.mem_read(data,n)));h.ret()
        h.callbacks[h.engine+0x68b6]=serialize;h.callbacks[h.engine+0x1029b0]=send
        h.call('game_trace::send_adapter',[h.sock,h.buf])
        self.assertEqual(formats,[original,b'cbdddd']);self.assertEqual(sent,[source])
