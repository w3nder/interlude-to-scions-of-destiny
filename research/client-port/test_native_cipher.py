"""Compare the model with actual x86 instructions, with no OS or network access."""
import hashlib
import random
import struct
import unittest
from pathlib import Path

import pefile
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_ESP

from game_transport import C4Cipher, C4KeyPacket
from test_cpp_core import api, BF
import ctypes as C

ROOT=Path(__file__).resolve().parent
SOURCE=ROOT.parents[1]/'system/engine.dll'


class NativeOracle:
    def __init__(self):
        raw=SOURCE.read_bytes()
        if hashlib.sha256(raw).hexdigest()!='17a8bcacd57d071a3420d278a7570ddf2a13abba2f6d4336bb4eb48afd4e244b':
            raise ValueError('Unexpected C4 engine build')
        pe=pefile.PE(data=raw)
        self.uc=Uc(UC_ARCH_X86,UC_MODE_32)
        # Only the cipher code and key initializer are executable inputs.
        for address,size in [(0x103f2000,0x2000),(0x103fe000,0x1000)]:
            self.uc.mem_map(address,size)
            self.uc.mem_write(address,pe.get_data(address-pe.OPTIONAL_HEADER.ImageBase,size))
        for address,size in [(0x200000,0x20000),(0x300000,0x1000),(0x400000,0x20000)]:
            self.uc.mem_map(address,size)

    def transform(self,payload,key,decrypt=False):
        uc=self.uc
        uc.mem_write(0x400000,payload)
        uc.mem_write(0x410000,key)
        uc.mem_write(0x210000,struct.pack('<IIII',0x300000,0x400000,0x410000,len(payload)))
        uc.reg_write(UC_X86_REG_ESP,0x210000)
        uc.emu_start(0x103f2b10 if decrypt else 0x103f2aa0,0x300000,count=1000000)
        if uc.reg_read(UC_X86_REG_ESP)!=0x210010:
            raise AssertionError('Native function did not return with expected stack cleanup')
        return bytes(uc.mem_read(0x400000,len(payload))),bytes(uc.mem_read(0x410000,8))

    def initialize_key(self,seed):
        self.uc.reg_write(UC_X86_REG_EAX,seed)
        self.uc.reg_write(UC_X86_REG_ECX,0x400000)
        self.uc.emu_start(0x103fe048,0x103fe05b,count=10)
        return bytes(self.uc.mem_read(0x404f74,8))

    def checksum(self,payload):
        aligned=(len(payload)+7)&~7
        self.uc.mem_write(0x400000,payload+bytes(aligned+8-len(payload)))
        self.uc.mem_write(0x410000,struct.pack('<I',len(payload)))
        self.uc.mem_write(0x210000,struct.pack('<III',0x300000,0x400000,0x410000))
        self.uc.reg_write(UC_X86_REG_ESP,0x210000)
        # Stop before the original call to the external Blowfish implementation.
        self.uc.emu_start(0x103f3d00,0x103f3d34,count=100000)
        size=struct.unpack('<I',self.uc.mem_read(0x410000,4))[0]
        return bytes(self.uc.mem_read(0x400000,size))


class NativeCipherTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):cls.oracle=NativeOracle()

    def test_seed_initializer_matches_native_including_sign_bit(self):
        for seed in [0,1,0x7FFFFFFF,0x80000000,0xFFFFFFFF,0x12345678]:
            with self.subTest(seed=hex(seed)):
                self.assertEqual(C4KeyPacket(1,seed,1,0).native_key(),self.oracle.initialize_key(seed))

    def test_encrypt_and_decrypt_match_native_across_packets_and_carry(self):
        rng=random.Random(656)
        keys=[bytes(8),bytes.fromhex('78563412a16c5487'),
              bytes.fromhex('feffffffa16c5487'),bytes.fromhex('feffffffffffffff'),rng.randbytes(8)]
        for decrypt in (False,True):
            for key in keys:
                model=C4Cipher(key);native_key=key
                for length in [1,2,7,8,9,15,16,17,31,256,8190]:
                    payload=rng.randbytes(length)
                    with self.subTest(decrypt=decrypt,key=key.hex(),length=length):
                        expected,native_key=self.oracle.transform(payload,native_key,decrypt)
                        actual=model.decrypt(payload) if decrypt else model.encrypt(payload)
                        self.assertEqual(actual,expected)
                        self.assertEqual(model.key,native_key)

    def test_cpp_login_checksum_matches_original_x86(self):
        lib=api();bf=BF();key=bytes.fromhex('5f3b352e5d39342d33313d3d2d257854215e5b2400')
        self.assertEqual(lib.l2k_bf_init(C.byref(bf),key,len(key)),0)
        for length in list(range(1,81))+[8184]:
            with self.subTest(length=length):
                payload=bytes((i*19+133)&255 for i in range(length))
                expected=self.oracle.checksum(payload)
                out=C.create_string_buffer(8192);plain=C.create_string_buffer(8192)
                n=lib.l2k_login_seal(C.byref(bf),payload,length,out,8192)
                self.assertGreater(n,0)
                self.assertEqual(lib.l2k_login_decrypt(C.byref(bf),out,n,plain,8192),n)
                self.assertEqual(plain.raw[:n],expected)


if __name__=='__main__':unittest.main()
