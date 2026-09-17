"""Check shared packet field encodings against both original decoder machines."""
import json
import struct
import unittest
from native_emitter_audit import NativeEmitter,ROOT,PROFILES
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EAX,UC_X86_REG_EIP


class CommonDecoderTests(unittest.TestCase):
    def test_every_common_reachable_format_consumes_identical_fields(self):
        wire=json.loads((ROOT/'reports/wire-equivalence.json').read_text())
        rows=[r for r in wire['inbound'] if r['resolution']=='same_reachable_decoder_sites_not_semantic_proof']
        # ServerObjectInfo's state switch occurs after a single identical decode.
        rows+=[r for r in wire['inbound'] if r['table']=='primary' and r['opcode']=='0x8C']
        formats={c['format'] for r in rows for c in r['source']['reachable_decoder_calls']}
        self.assertNotIn(None,formats)
        engines={side:NativeEmitter(side) for side in PROFILES}
        for e in engines.values():e.top_calls=0;e.inner_formats=[]
        for fmt in sorted(formats):
            self.assertLessEqual(set(fmt),set('cdhfS'))
            for variant in range(3):
                fields=[]
                for i,kind in enumerate(fmt):
                    if kind=='S':value=['','Teste界','Ação 🎯'][variant];field=(value+'\0').encode('utf-16le')
                    elif kind=='f':field=struct.pack('<d',[0.,-123456.75,2.**45+.5][variant])
                    else:
                        size={'c':1,'h':2,'d':4}[kind]
                        value=[0,0xffffffff,0x80001234+i][variant]&((1<<(size*8))-1)
                        field=value.to_bytes(size,'little')
                    fields.append(field)
                payload=b''.join(fields)
                for side,e in engines.items():
                    with self.subTest(format=fmt,variant=variant,side=side):
                        u=e.u;packet=e.DATA+0x8000;format_address=e.DATA+0x9000
                        u.mem_write(packet,payload);u.mem_write(format_address,fmt.encode()+b'\0')
                        e.put(e.DATA+(0x4e48 if side=='source' else 0x4ef8),packet+len(payload))
                        args=[e.STOP,e.DATA,packet,format_address];destinations=[]
                        for index,kind in enumerate(fmt):
                            address=e.DATA+0x10000+index*256;destinations.append(address);u.mem_write(address,b'\xa5'*128)
                            args.extend([128,address] if kind=='S' else [address])
                        sp=e.STACK+0x30000;u.mem_write(sp,struct.pack('<'+'I'*len(args),*args));u.reg_write(UC_X86_REG_ESP,sp)
                        entry=e.resolve(0x10305079 if side=='source' else 0x103034e5)
                        u.emu_start(entry,e.STOP,count=100000)
                        self.assertEqual(u.reg_read(UC_X86_REG_EIP),e.STOP)
                        self.assertEqual(u.reg_read(UC_X86_REG_EAX),packet+len(payload))
                        for field,address in zip(fields,destinations):self.assertEqual(bytes(u.mem_read(address,len(field))),field)
        report={'status':'passed','hashes':{s:p['sha256'] for s,p in PROFILES.items()},
                'unique_formats':len(formats),'vector_pairs':len(formats)*3,
                'packets':[{'table':r['table'],'opcode':r['opcode'],'formats':[c['format'] for c in r['source']['reachable_decoder_calls']]} for r in rows],
                'scope':'Native decoder field contents, primitive widths, UTF-16 strings, signed/unsigned bit patterns, double precision and end cursor for every shared reachable format.',
                'limits':'Full handler branch conditions, row counts, raw reads and UI callbacks are not exercised by this format-level test.'}
        (ROOT/'reports/native-common-decoders.json').write_text(json.dumps(report,indent=2)+'\n')
