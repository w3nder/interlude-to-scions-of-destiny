"""Execute actual x86 hook bodies; mock only OS calls and native UI/socket edges."""
import ctypes as C
import struct,subprocess,unittest
import pefile
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import *
from test_cpp_core import api,BF,KEY,ROOT

class LoginHooksTests(unittest.TestCase):
    def setUp(self):
        self.pe=pefile.PE(str(ROOT/'build/L2KProtocolCore.dll'));self.base=self.pe.OPTIONAL_HEADER.ImageBase
        lines=subprocess.check_output(['i686-w64-mingw32-nm','-C',str(ROOT/'build/L2KProtocolCore.dll')],text=True).splitlines()
        self.symbols={line.split(' ',2)[2]:int(line.split()[0],16) for line in lines if len(line.split(' ',2))==3 and line[0]!=' '}
        self.u=Uc(UC_ARCH_X86,UC_MODE_32);u=self.u
        u.mem_map(self.base,(self.pe.OPTIONAL_HEADER.SizeOfImage+4095)&~4095);u.mem_write(self.base,self.pe.get_memory_mapped_image())
        self.engine=0x10300000;u.mem_map(self.engine,0x900000)
        u.mem_map(0x200000,0x40000);u.mem_map(0x400000,0x1000);u.mem_map(0x500000,0x30000)
        self.sock=0x500000;self.network=0x510000;self.buf=0x520000;self.logs=[];self.frames=[];self.closed=[];self.auth=[];self.list_requests=[]
        self.w32(self.symbol('(anonymous namespace)::base'),self.engine)
        self.w32(self.symbol('(anonymous namespace)::receive_original'),self.engine+0x102f50)
        lib=api();bf=BF();lib.l2k_bf_init(C.byref(bf),KEY,len(KEY));self.bf=bf;self.lib=lib
        u.mem_write(self.symbol('(anonymous namespace)::cipher'),bytes(bf))
        self.w32(self.sock+0x38,123);self.w32(self.sock+0x50b8,1);self.w32(self.sock+0x50bc,1);self.w32(self.network+0x4c,self.sock)
        self.callbacks={self.symbol('l2k_log(char const*)'):self.log,
            self.symbol('__mingw_snprintf'):lambda:self.ret(value=0),
            self.engine+0x102f50:self.receive,self.engine+0x103040:self.send,self.engine+0x103a50:self.request_list}
        for entry in self.pe.DIRECTORY_ENTRY_IMPORT:
            for imp in entry.imports:
                name=imp.name.decode() if imp.name else str(imp.ordinal)
                address=0x400100+len(self.callbacks)*16
                self.w32(imp.address,address)
                self.callbacks[address]=lambda name=name:self.oscall(name)
        u.hook_add(UC_HOOK_CODE,self.hook)
    def symbol(self,needle):return next(v for k,v in self.symbols.items() if needle in k)
    def w32(self,a,n):self.u.mem_write(a,struct.pack('<I',n))
    def r32(self,a):return struct.unpack('<I',self.u.mem_read(a,4))[0]
    def args(self,n):return [self.r32(self.u.reg_read(UC_X86_REG_ESP)+4+4*i) for i in range(n)]
    def ret(self,n=0,value=0):
        sp=self.u.reg_read(UC_X86_REG_ESP);self.u.reg_write(UC_X86_REG_EAX,value);self.u.reg_write(UC_X86_REG_EIP,self.r32(sp));self.u.reg_write(UC_X86_REG_ESP,sp+4+n)
    def hook(self,u,address,size,user):
        if address in self.callbacks:self.callbacks[address]()
    def log(self):
        p=self.args(1)[0];data=bytes(self.u.mem_read(p,256)).split(b'\0')[0];self.logs.append(data);self.ret()
    def receive(self):
        p,n=self.args(2);self.assertEqual(self.r32(self.sock+0x50bc),0);self.frames.append(bytes(self.u.mem_read(p,n)));self.ret(8)
    def send(self):
        sock,fmt,n,p=self.args(4);self.assertEqual(sock,self.sock);self.assertEqual(bytes(self.u.mem_read(fmt,2)),b'b\0');self.auth.append(bytes(self.u.mem_read(p,n)));self.ret()
    def request_list(self):self.list_requests.append(bytes(self.u.mem_read(self.engine+0x820f34,8)));self.ret(value=1)
    def oscall(self,name):
        if name=='shutdown':self.closed.append(self.args(2));self.ret(8)
        elif name=='WideCharToMultiByte':
            cp,flags,src,n,dst,cap,default,used=self.args(8);s=bytes(self.u.mem_read(src,n*2)).decode('utf-16le').encode('ascii');self.u.mem_write(dst,s);self.w32(used,0);self.ret(32,len(s))
        elif name in ('memcpy','memmove'):
            dst,src,n=self.args(3);self.u.mem_write(dst,bytes(self.u.mem_read(src,n)));self.ret(value=dst)
        elif name=='memcmp':
            a,b,n=self.args(3);self.ret(value=0 if self.u.mem_read(a,n)==self.u.mem_read(b,n) else 1)
        elif name=='memset':
            dst,value,n=self.args(3);self.u.mem_write(dst,bytes([value&255])*n);self.ret(value=dst)
        elif name=='GetModuleHandleW':self.ret(4,self.engine)
        elif name=='GetModuleFileNameW':
            module,path,cap=self.args(3);self.u.mem_write(path,'engine.dll\0'.encode('utf-16le'));self.ret(12,10)
        elif name=='CreateFileW':self.ret(28,42)
        elif name=='CryptAcquireContextW':self.w32(self.args(5)[0],1);self.ret(20,1)
        elif name=='CryptCreateHash':self.w32(self.args(5)[4],2);self.ret(20,1)
        elif name=='ReadFile':self.w32(self.args(5)[3],0);self.ret(20,1)
        elif name=='CryptGetHashParam':
            a=self.args(5);self.u.mem_write(a[2],bytes.fromhex('508974c711f207402719e92737e211a2f029c95c2f68fc0e1c31fcbb9dbb232d'));self.ret(20,1)
        elif name=='CryptDestroyHash':self.ret(4,1)
        elif name=='CryptReleaseContext':self.ret(8,1)
        elif name=='CloseHandle':self.ret(4,1)
        elif name=='VirtualProtect':self.w32(self.args(4)[3],0x20);self.ret(16,1)
        else:raise AssertionError('Unexpected OS/CRT call '+name)
    def call(self,needle,args,ecx=0,cleanup=0):
        sp=0x230000;self.u.mem_write(sp,struct.pack('<'+'I'*(len(args)+1),0x400000,*args));self.u.reg_write(UC_X86_REG_ESP,sp);self.u.reg_write(UC_X86_REG_ECX,ecx);self.u.reg_write(UC_X86_REG_EDX,0)
        # Ignore printf formatting; its result is only used to emit a diagnostic line.
        for entry in self.pe.DIRECTORY_ENTRY_IMPORT:
            for imp in entry.imports:
                if imp.name and imp.name.decode() in ('__stdio_common_vsnprintf_s','__stdio_common_vsprintf'):
                    self.callbacks[self.r32(imp.address)]=lambda:self.ret(value=0)
        self.u.emu_start(self.symbol(needle),0x400000,count=3000000)
        self.assertEqual(self.u.reg_read(UC_X86_REG_EIP),0x400000);self.assertEqual(self.u.reg_read(UC_X86_REG_ESP),sp+4+cleanup)
    def incoming(self,p):
        frame=struct.pack('<H',len(p)+2)+p;self.u.mem_write(self.buf,frame);self.call('receive_hook',[self.buf,len(frame)],self.sock,8)
    def sealed(self,p):
        out=C.create_string_buffer(8192);n=self.lib.l2k_login_seal(C.byref(self.bf),p,len(p),out,len(out));return out.raw[:n]
    def test_init_auth_and_ui_keys(self):
        self.incoming(b'\0'+struct.pack('<II',0xaabbccdd,0x785a));self.assertEqual(len(self.frames),1)
        self.u.mem_write(self.engine+0x820f54,'tester\0'.encode('utf-16le'));self.u.mem_write(self.engine+0x820f72,'testpass\0'.encode('utf-16le'))
        self.u.mem_write(self.buf,self.frames[0][3:]);self.call('::init_hook',[self.network,self.buf])
        self.assertEqual(self.auth,[b'\0'+b'tester'.ljust(14,b'\0')+b'testpass'.ljust(16,b'\0')+b'\x08'])
        self.assertEqual(self.r32(self.network+0xe4),0xaabbccdd)
        keys=struct.pack('<II',0xab000001,0xcd000002);self.incoming(self.sealed(b'\x03'+keys));self.u.mem_write(self.buf,keys);self.call('::login_ok_hook',[self.network,self.buf]);self.assertEqual(self.list_requests,[keys]);self.assertFalse(self.closed)
    def test_server_list_and_reject_truncation_checksum(self):
        self.w32(self.sock+0x50b8,0)
        row=b'\x01'+bytes([127,0,0,1])+struct.pack('<I',7777)+b'\0\1'+struct.pack('<HH',1,100)+b'\1'+struct.pack('<I',0)+b'\0'
        payload=b'\x04\1\1'+row;self.incoming(self.sealed(payload));self.assertEqual(self.frames[-1][2:2+len(payload)],payload)
        count=len(self.frames);self.incoming(self.sealed(b'\x04\xff\1'));self.assertEqual(len(self.frames),count);self.assertTrue(self.closed)
        bad=bytearray(self.sealed(payload));bad[7]^=1;self.incoming(bytes(bad));self.assertEqual(len(self.frames),count)
    def test_native_seal_abi_and_cipher(self):
        payload=b'\x05'+struct.pack('<II',123,456)+b'\x04';self.u.mem_write(self.buf,payload);self.w32(self.buf+8192,len(payload));self.call('seal_hook',[self.buf,self.buf+8192],self.sock,8)
        n=self.r32(self.buf+8192);self.assertEqual(bytes(self.u.mem_read(self.buf,n)),self.sealed(payload))

    def test_installation_checks_pointers_before_mutation(self):
        table=[(0x58b710,0xae93),(0x58b71c,0xa91b),(0x58b720,0x94c6),(0x7572c0,0x202c),(0x7572cc,0x91d3)]
        for slot,expected in table:self.w32(self.engine+slot,self.engine+expected)
        self.w32(self.engine+table[-1][0],0)
        self.call('l2k_install_login_hooks()',[])
        self.assertEqual(self.u.reg_read(UC_X86_REG_EAX),0)
        self.assertEqual(self.r32(self.engine+table[0][0]),self.engine+table[0][1])
        self.w32(self.engine+table[-1][0],self.engine+table[-1][1])
        self.call('l2k_install_login_hooks()',[])
        self.assertEqual(self.u.reg_read(UC_X86_REG_EAX),1)
        for slot,expected in table:self.assertTrue(self.base<=self.r32(self.engine+slot)<self.base+self.pe.OPTIONAL_HEADER.SizeOfImage)
