import ctypes as C,json,random,struct,unittest
from test_cpp_core import ROOT

def d(*v):return struct.pack('<'+'I'*len(v),*v)
def h(*v):return struct.pack('<'+'H'*len(v),*v)
def s(v):return v.encode('utf-16le')+b'\0\0'
def encode(fmt,seed=99):
    rng=random.Random(seed);fields=[]
    for f in fmt:
        fields.append(s('Teste界') if f=='S' else rng.randbytes({'d':4,'c':1,'h':2,'f':8,'Q':8}[f]))
    return fields
class StructuredCodecTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.lib=C.CDLL(str(ROOT/'build/libl2k_protocol.dylib'));cls.fn=cls.lib.l2k_structured_convert
        cls.fn.argtypes=[C.c_void_p,C.c_uint32,C.c_void_p,C.c_uint32];cls.fn.restype=C.c_int
    def convert(self,p,cap=65533):
        out=C.create_string_buffer(b'\xa5'*65535,65535);n=self.fn(p,len(p),out,cap)
        self.assertEqual(out.raw[cap:],b'\xa5'*(65535-cap))
        if n<=0:self.assertEqual(out.raw,b'\xa5'*65535)
        return n,out.raw[:max(n,0)]
    def pair(self,old,new):
        if old==new:self.assertEqual(self.convert(old)[0],0);return
        self.assertEqual(self.convert(old),(len(new),new));self.assertEqual(self.convert(new)[0],0)
        self.assertEqual(self.convert(old,len(new)-1)[0],-2)
    def test_gm_character_fields_equipment_cp_and_modern_passthrough(self):
        wire=json.loads((ROOT/'reports/wire-equivalence.json').read_text())
        row=next(r for r in wire['inbound'] if r['table']=='primary' and r['opcode']=='0x8F')
        fmt=row['source']['reachable_decoder_calls'][0]['format']
        self.assertEqual(fmt, 'd'*5+'S'+'d'*71+'f'*4+'d'*4+'S'+'d'*3+'c'*3+'d'*2+'h'*2+'d'*3)
        for seed in [0,1,7,99]:
            fields=encode(fmt,seed)
            fields[10]=d(0xfedcba98) # unsigned C4 experience
            fields[96]=d(88);fields[97]=d(123456);fields[98]=d(65432)
            old=b'\x8f'+b''.join(fields)
            modern=(b'\x8f'+b''.join(fields[:11])+d(0)+b''.join(fields[11:41])+d(0)
                    +b''.join(fields[41:57])+d(0)+bytes(68)+b''.join(fields[57:97])+d(0)
                    +b''.join(fields[97:])+bytes(8)+d(0xffffff,0xffffff))
            self.assertEqual(len(modern)-len(old),100)
            self.pair(old,modern)
            for size in range(1,len(old)):
                self.assertEqual(self.convert(old[:size])[0],0)
            self.assertEqual(self.convert(old+b'\x99')[0],0)

    def test_command_channel_names_and_counts_with_unavailable_member_ids(self):
        for count in [0,1,2,20]:
            old=b'\xfe\x30\0'+s('Líder')+d(count*9,count)
            modern=b'\xfe\x30\0'+s('Líder')+d(0,count*9,count)
            for i in range(count):
                old+=s(f'Grupo{i}')+d(i+1)
                modern+=s(f'Grupo{i}')+d(0,i+1)
            self.pair(old,modern)
            for size in range(3,len(old)):
                self.assertLess(self.convert(old[:size])[0],0)
        # Existing Interlude IDs/loot policy must survive unchanged.
        packet=b'\xfe\x30\0'+s('Leader')+d(2,9,1)+s('Party')+d(12345,9)
        self.assertEqual(self.convert(packet)[0],0)

    def test_quest_list_preserves_states_without_fabricating_completion_bits(self):
        for count in [0,1,25]:
            head=b'\x80'+h(count)+b''.join(d(100+i,0x80000000+i) for i in range(count))
            modern=head+bytes(128)
            self.pair(head,modern)
            for items in [0,1,8,100]:
                old=head+h(items)+b''.join(d(500+i,1000+i,3+i,0) for i in range(items))
                self.pair(old,modern)
                if items:
                    self.assertLess(self.convert(old[:-1])[0],0)
            self.assertEqual(self.convert(head+bytes(range(128)))[0],0)
        for bad in [b'\x80',b'\x80\x01',b'\x80'+h(0x8000),b'\x80'+h(2)+d(1,2),b'\x80'+h(0)+b'\0']:
            self.assertLess(self.convert(bad)[0],0)

    def test_fixed_extensions(self):
        for op,size,extra in [(0x86,17,12),(0x29,21,4),(0x2a,17,4),(0xa6,7,4),(0x4c,9,4),(0xc5,29,4),(0xc7,41,4),(0xcd,25,4),(0xf3,21,8)]:
            p=bytes([op])+bytes(range(size-1));self.pair(p,p+b'\0'*extra)
            for n in range(1,len(p)):self.assertLess(self.convert(p[:n])[0],0)
    def test_status_count_matches_complete_pairs_before_native_dispatch(self):
        for count in [0,1,35,8190]:
            p=b'\x0e'+d(777,count)+b''.join(d(i%35,i*123) for i in range(count))
            self.assertEqual(self.convert(p)[0],0)
            if count:self.assertLess(self.convert(p[:-1])[0],0)
            self.assertLess(self.convert(p+b'\0')[0],0)
        for p in [b'\x0e',b'\x0e'+d(777),b'\x0e'+d(777,0xffffffff)]:
            self.assertLess(self.convert(p)[0],0)
    def test_character_selection_equipment_and_experience(self):
        comparison=json.loads((ROOT/'comparison.json').read_text())
        row=next(r for r in comparison['inbound'] if r['table']=='primary' and r['opcode']=='0x13')
        fmt=row['source']['decode_segments'][1]['format']
        old=[];new=[]
        for i in range(5):
            fields=encode(fmt,seed=i)
            old.append(b''.join(fields))
            # Two paperdoll arrays gain their seventeenth slot. Experience is Q.
            new.append(b''.join(fields[:17])+d(0)+b''.join(fields[17:44])+d(0)+b''.join(fields[44:60])+d(0)+b''.join(fields[60:])+h(0,0))
        for count in [0,1,5]:
            self.pair(b'\x13'+d(count)+b''.join(old[:count]),b'\x13'+d(count)+b''.join(new[:count]))
        self.assertLess(self.convert(b'\x13'+d(0xffffffff))[0],0)
    def test_character_selected_unrecognized_live_variants_preserve_native_path(self):
        # Lengths recorded by metadata trace during the world-entry regression.
        # Synthetic contents: no captured identity/payload data is persisted.
        for size in [281,289]:
            for fill in [0,0xA5,0xFF]:
                p=b'\x15'+bytes([fill])*(size-1)
                self.assertEqual(self.convert(p)[0],0)
    def test_invitation_optional_subunit_name(self):
        p=b'\x32'+d(1234)+s('Clã');self.pair(p,p+d(0))
        self.assertEqual(self.convert(p+d(100)+s('Sub'))[0],0)
        self.assertLess(self.convert(p+d(100))[0],0)
        p=b'\xfe\x27\0'+s('Líder');self.pair(p,p+d(0))
    def test_warehouse_and_gm_inventory(self):
        rng=random.Random(72)
        for op in [0x41,0x42,0x94]:
            for count in [0,1,15,220]:
                head=bytes([op])+(h(1)+d(123)+h(count) if op!=0x94 else s('GM界')+d(123)+h(0,count))
                rows=[rng.randbytes(32 if op!=0x94 else 28) for _ in range(count)]
                self.pair(head+b''.join(rows),head+b''.join(row+d(0,0xffffffff if op==0x94 else 0) for row in rows))
        for types in [[0],[4],[0,1,2,3,4,5,0xffff]]:
            head=b'\x95'+s('GM')+d(0)+h(len(types));old=[];new=[]
            for t in types:
                base=h(t)+rng.randbytes(16);body=rng.randbytes(10) if t<4 else b'';end=d(997)
                old.append(base+body+end);new.append(base+body+(d(0,0) if t<4 else b'')+end)
            self.pair(head+b''.join(old),head+b''.join(new))
    def test_shortcut_types_and_mixed_pages(self):
        old=[];new=[]
        for slot,t in enumerate([1,2,3,4,5]*10):
            row=d(t,slot,1000+slot)+(d(80) if t==2 else b'')+d(1);old.append(row)
            target=row+d(0xffffffff,0,0,0) if t==1 else row[:-4]+b'\0'+row[-4:] if t==2 else row;new.append(target)
            self.pair(b'\x44'+row,b'\x44'+target)
        self.pair(b'\x45'+d(len(old))+b''.join(old),b'\x45'+d(len(new))+b''.join(new))
        self.assertLess(self.convert(b'\x45'+d(0xffffffff))[0],0)
    def test_nested_multisell_and_malformed_counts(self):
        for count in [1,2,30]:
            old=[];new=[]
            for entry in range(count):
                products=[h(100+i)+d(7)+h(2)+d(19)+h(3) for i in range(entry%5)]
                ingredients=[h(57,4)+d(1000)+h(0)]*(entry%3)
                tail=b'\1'+h(len(products),len(ingredients));head=d(entry+1)
                old.append(head+tail+b''.join(products+ingredients))
                new.append(head+d(0,0)+tail+b''.join(row+d(0,0) for row in products+ingredients))
            prefix=b'\xd0'+d(100,1,1,40,count);a=prefix+b''.join(old);b=prefix+b''.join(new);self.pair(a,b)
            for n in range(1,len(a)):self.assertLessEqual(self.convert(a[:n])[0],0)
        self.assertLess(self.convert(b'\xd0'+d(1,1,1,40,0xffffffff))[0],0)
    def test_gm_clan_with_and_without_clan(self):
        for clan in [0,123]:
            for count in [0,1,5]:
                names=s('Clã' if clan else '')+s('Leader' if clan else '')
                middle=d(*range(9))+s('Ally')+d(55,66) if clan else b''
                rows=[s('Player'+str(i))+d(1,2,3,4,5) for i in range(count)]
                old=b'\x90'+s('GM')+d(clan)+names+middle+d(count)+b''.join(rows)
                new=b'\x90'+d(0)+s('GM')+d(clan,0)+names+middle+d(count)+b''.join(row+d(0) for row in rows)
                self.pair(old,new)
    def test_message_parameter_tags_and_confirmation_tail(self):
        params=d(0)+s('Texto')+b''.join(d(t,123) for t in [1,2,3,5])+d(4,100,2)
        for op in [0x64,0xed]:
            p=bytes([op])+d(123,6)+params
            self.pair(p,p+(d(0,0) if op==0xed else b''))
            self.assertLess(self.convert(p[:-1])[0],0)
        modern=b'\x64'+d(12,3)+d(6)+struct.pack('<Q',2**45)+d(7,11,22,33)+d(8,100)+h(12,34)
        self.assertEqual(self.convert(modern)[0],0)
    def test_npc_and_pet_full_catalogue_layout(self):
        comparison=json.loads((ROOT/'comparison.json').read_text())
        for op in ['0x16','0xB1']:
            row=next(r for r in comparison['inbound'] if r['table']=='primary' and r['opcode']==op)
            fmt=''.join(s['format'] for s in row['source']['decode_segments']);target=''.join(s['format'] for s in row['target']['decode_segments'])
            fields=encode(fmt);p=bytes([int(op,16)])+b''.join(fields)
            if op=='0x16':want=p+d(0)
            else:want=bytes([int(op,16)])+b''.join(v+(d(0) if b=='Q' and a=='d' else b'') for a,b,v in zip(fmt,target,fields))
            self.pair(p,want)
            self.assertLess(self.convert(p[:-1])[0],0)
    def test_random_untrusted_packets_do_not_overwrite_on_rejection(self):
        rng=random.Random(410)
        for i in range(1000):
            op=rng.choice([0x44,0x45,0x64,0x90,0x94,0x95,0xd0,0xed]);p=bytes([op])+rng.randbytes(rng.randrange(0,300))
            self.convert(p,512)
