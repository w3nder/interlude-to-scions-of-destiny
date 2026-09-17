"""Feed GM character conversion into the exact C4 and Interlude native decoders."""
import ctypes as C
import struct
import unittest
from native_emitter_audit import NativeEmitter, ROOT
from test_structured_codec import encode, d
from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_EAX, UC_X86_REG_EIP

class NativeGMInfoTests(unittest.TestCase):
    def test_converted_record_matches_native_decoder_fields_and_cursor(self):
        lib=C.CDLL(str(ROOT/'build/libl2k_protocol.dylib'))
        convert=lib.l2k_structured_convert
        convert.argtypes=[C.c_void_p,C.c_uint32,C.c_void_p,C.c_uint32];convert.restype=C.c_int
        engines={s:NativeEmitter(s) for s in ['source','target']}
        formats={}
        for side,va in [('source',0x107c5998),('target',0x10889278)]:
            e=engines[side]
            formats[side]=e.pe.get_data(va-e.pe.OPTIONAL_HEADER.ImageBase,256).split(b'\0',1)[0].decode('ascii')
        for seed in [5,29,300]:
            source_fields=encode(formats['source'],seed)
            source_fields[10]=d(0xfedcba98)
            source_fields[96:]=[d(88),d(123456),d(65432)]
            source=b'\x8f'+b''.join(source_fields)
            out=C.create_string_buffer(65533)
            n=convert(source,len(source),out,65533)
            self.assertEqual(n,len(source)+100)
            expected=(source_fields[:10]+[source_fields[10]+bytes(4)]+source_fields[11:41]+[bytes(4)]
                      +source_fields[41:57]+[bytes(4)]+[bytes(2)]*34+source_fields[57:97]+[bytes(4)]
                      +source_fields[97:]+[bytes(1),bytes(1),bytes(4),bytes(1),bytes(1),d(0xffffff),d(0xffffff)])
            self.assertEqual(len(expected),len(formats['target']))
            for side,packet,fields in [('source',source,source_fields),('target',out.raw[:n],expected)]:
                e=engines[side];u=e.u;e.top_calls=0;e.inner_formats=[]
                payload=packet[1:];fmt=formats[side]
                u.mem_write(e.DATA+0x8000,payload)
                u.mem_write(e.DATA+0x9000,fmt.encode()+b'\0')
                e.put(e.DATA+(0x4e48 if side=='source' else 0x4ef8),e.DATA+0x8000+len(payload))
                args=[e.STOP,e.DATA,e.DATA+0x8000,e.DATA+0x9000];addresses=[]
                for idx,f in enumerate(fmt):
                    address=e.DATA+0x10000+idx*256;addresses.append(address)
                    u.mem_write(address,b'\xa5'*128)
                    args.extend([128,address] if f=='S' else [address])
                sp=e.STACK+0x30000
                u.mem_write(sp,struct.pack('<'+'I'*len(args),*args));u.reg_write(UC_X86_REG_ESP,sp)
                decoder=e.resolve(0x10305079 if side=='source' else 0x103034e5)
                u.emu_start(decoder,e.STOP,count=2000000)
                self.assertEqual(u.reg_read(UC_X86_REG_EIP),e.STOP)
                self.assertEqual(u.reg_read(UC_X86_REG_EAX),e.DATA+0x8000+len(payload))
                for idx,(field,address) in enumerate(zip(fields,addresses)):
                    self.assertEqual(bytes(u.mem_read(address,len(field))),field,(side,idx,fmt[idx]))
