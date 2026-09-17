import ctypes as C
import random
import struct
import unittest
from pathlib import Path

from game_transport import C4Cipher, C4KeyPacket
from handshake_codec import interlude_protocol_version_to_killer

ROOT=Path(__file__).resolve().parent
KEY=bytes.fromhex('5f3b352e5d39342d33313d3d2d257854215e5b2400')


class BF(C.Structure):_fields_=[('p',C.c_uint32*18),('s',(C.c_uint32*256)*4)]
class Game(C.Structure):_fields_=[('tx',C.c_ubyte*8),('rx',C.c_ubyte*8),('ready',C.c_uint32)]
class Login(C.Structure):
    _fields_=[('bf',BF)]+[(n,C.c_uint32) for n in ['phase','login1','login2','play1','play2','port']]+[
        ('user',C.c_ubyte*14),('password',C.c_ubyte*16),('host',C.c_ubyte*4),('server',C.c_ubyte)]


def api():
    lib=C.CDLL(str(ROOT/'build/libl2k_protocol.dylib'))
    ptr=C.c_void_p;u=C.c_uint32
    signatures={'l2k_bf_init':[ptr,ptr,u],'l2k_bf_block':[ptr,ptr,ptr,u],
        'l2k_login_seal':[ptr,ptr,u,ptr,u],'l2k_login_decrypt':[ptr,ptr,u,ptr,u],
        'l2k_game_key':[ptr,ptr,u],'l2k_game_transform':[ptr,ptr,u,u],
        'l2k_protocol_version':[ptr,u,ptr,u],'l2k_login_begin':[ptr,ptr,u,ptr,u],
        'l2k_login_step':[ptr,ptr,u,ptr,u]}
    for name,types in signatures.items():getattr(lib,name).argtypes=types;getattr(lib,name).restype=C.c_int
    return lib


class CppCoreTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):cls.lib=api()

    def cipher(self):
        bf=BF();self.assertEqual(self.lib.l2k_bf_init(C.byref(bf),KEY,len(KEY)),0);return bf

    def decrypt(self,bf,data):
        out=C.create_string_buffer(len(data))
        self.assertEqual(self.lib.l2k_login_decrypt(C.byref(bf),data,len(data),out,len(out)),len(data))
        return out.raw

    def test_blowfish_matches_backend_known_vector(self):
        bf=self.cipher();out=C.create_string_buffer(8)
        self.assertEqual(self.lib.l2k_bf_block(C.byref(bf),bytes(range(8)),out,0),8)
        self.assertEqual(out.raw.hex(),'76b8d908443a6a97')
        self.assertEqual(self.decrypt(bf,out.raw),bytes(range(8)))

    def test_seal_preserves_short_payload_and_places_checksum_after_alignment(self):
        bf=self.cipher()
        for size in [1,9,10,16,17,31,32,33,8184]:
            with self.subTest(size=size):
                payload=bytes((i*17+129)&255 for i in range(size));out=C.create_string_buffer(8193)
                out[8192]=b'Z'
                n=self.lib.l2k_login_seal(C.byref(bf),payload,size,out,8192)
                aligned=(size+7)&~7;self.assertEqual(n,aligned+8)
                plain=self.decrypt(bf,out.raw[:n]);self.assertEqual(plain[:size],payload)
                self.assertEqual(plain[size:aligned],bytes(aligned-size))
                xor=0
                for (value,) in struct.iter_unpack('<I',plain[:aligned]):xor^=value
                self.assertEqual(plain[aligned:],struct.pack('<II',xor,0))
                self.assertEqual(out[8192],b'Z')
        out=C.create_string_buffer(b'unchanged')
        self.assertEqual(self.lib.l2k_login_seal(C.byref(bf),b'123456789',9,out,9),-2)
        self.assertEqual(out.value,b'unchanged')

    def test_cpp_game_matches_validated_python_model(self):
        rng=random.Random(746)
        for seed in [0,0x12345678,0x7ffffffe,0x80000000,0xfffffffe]:
            packet=b'\0'+struct.pack('<BIII',1,seed,1,0);ctx=Game()
            self.assertEqual(self.lib.l2k_game_key(C.byref(ctx),packet,len(packet)),0)
            key=C4KeyPacket.parse(packet).native_key()
            for decrypt in (0,1):
                model=C4Cipher(key)
                for length in [1,7,8,9,16,31,256,8190]:
                    data=rng.randbytes(length);out=C.create_string_buffer(data,length)
                    self.assertEqual(self.lib.l2k_game_transform(C.byref(ctx),out,length,decrypt),length)
                    self.assertEqual(out.raw,model.decrypt(data) if decrypt else model.encrypt(data))
                    self.assertEqual(bytes(ctx.rx if decrypt else ctx.tx),model.key)

    def test_protocol_version_and_bounds(self):
        block=(ROOT/'interlude-protocol-block.bin').read_bytes()
        payload=b'\0'+struct.pack('<I',746)+block+bytes.fromhex('12345678');out=C.create_string_buffer(261)
        self.assertEqual(self.lib.l2k_protocol_version(payload,len(payload),out,261),261)
        self.assertEqual(out.raw,interlude_protocol_version_to_killer(payload))
        self.assertEqual(self.lib.l2k_protocol_version(payload,len(payload),out,260),-2)
        self.assertEqual(self.lib.l2k_protocol_version(payload[:-1],264,out,261),-1)

    def test_complete_synthetic_login(self):
        ctx=Login();self.assertEqual(self.lib.l2k_login_size(),C.sizeof(Login))
        self.assertEqual(self.lib.l2k_login_begin(C.byref(ctx),b'test',4,b'example',7),0)
        out=C.create_string_buffer(8192)
        def step(payload):
            n=self.lib.l2k_login_step(C.byref(ctx),payload,len(payload),out,len(out))
            self.assertGreaterEqual(n,0)
            return self.decrypt(ctx.bf,out.raw[:n]) if n else b''
        auth=step(b'\0'+struct.pack('<II',123,0x785a))
        self.assertEqual(auth[:32],b'\0'+b'test'.ljust(14,b'\0')+b'example'.ljust(16,b'\0')+b'\x08')
        self.assertEqual(bytes(ctx.password),bytes(16));self.assertEqual(ctx.phase,2)
        request=step(b'\x03'+struct.pack('<II',0xdeadbeef,0xfedcba98))
        self.assertEqual(request[:10],b'\x05'+struct.pack('<II',0xdeadbeef,0xfedcba98)+b'\x04')
        # Nonzero upper key byte detects the backend's short-buffer overwrite.
        self.assertEqual(request[8],0xfe)
        entry=bytes([7,127,0,0,1])+struct.pack('<I',7777)+bytes([0,1])+struct.pack('<HH',12,2000)+b'\1'+struct.pack('<I',0)+b'\0'
        self.assertEqual(len(entry),21)
        play=step(b'\x04\x01\x00'+entry)
        self.assertEqual(play[:10],b'\x02'+struct.pack('<II',0xdeadbeef,0xfedcba98)+b'\x07')
        self.assertEqual(ctx.port,7777);self.assertEqual(bytes(ctx.host),bytes([127,0,0,1]))
        self.assertEqual(step(b'\x07'+struct.pack('<II',101,202)),b'')
        self.assertEqual((ctx.phase,ctx.play1,ctx.play2),(5,101,202))

    def test_login_rejections_and_retry_after_capacity_error(self):
        ctx=Login();self.lib.l2k_login_begin(C.byref(ctx),b'test',4,b'example',7)
        out=C.create_string_buffer(64);init=b'\0'+struct.pack('<II',123,0x785a)
        self.assertEqual(self.lib.l2k_login_step(C.byref(ctx),init,9,out,39),-2)
        self.assertEqual(ctx.phase,1)
        self.assertEqual(self.lib.l2k_login_step(C.byref(ctx),init,9,out,64),40)
        self.assertEqual(self.lib.l2k_login_step(C.byref(ctx),b'\x01\x02',2,out,64),-4)
        self.assertEqual(ctx.phase,6)
        self.assertEqual(self.lib.l2k_login_step(C.byref(ctx),init,9,out,64),-3)


if __name__=='__main__':unittest.main()
