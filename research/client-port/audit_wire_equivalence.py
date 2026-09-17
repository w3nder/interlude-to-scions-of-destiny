"""Conservative binary audit. Compare serializer arguments, not only type strings.
Unknown instructions/calls/control flow remain review items, never wildcards.
No client execution, server access or packet payload capture.
"""
import hashlib,json
from collections import Counter
from pathlib import Path
from capstone.x86 import X86_OP_REG,X86_OP_IMM,X86_OP_MEM
from extract_protocol import Extractor
ROOT=Path(__file__).resolve().parent
TOP='?Top@L2ParamStack@@QAEPAXXZ'
class Unsupported(Exception):pass

def add(a,b):
    if b==0:return a
    if isinstance(a,int) and isinstance(b,int):return (a+b)&0xffffffff
    if isinstance(a,tuple) and a[0]=='stack' and isinstance(b,int):return ('stack',a[1]+b)
    return ('add',a,b)

class Prefix:
    def __init__(self,engine):
        self.e=engine;self.imports={i.address:i.name.decode() for d in engine.pe.DIRECTORY_ENTRY_IMPORT for i in d.imports if i.name}
        self.reg={r:('entry',r) for r in ['eax','ebx','ecx','edx','esi','edi','ebp']};self.reg['esp']=('stack',0)
        self.mem={};self.pops={};self.events=[]
    def register(self,name):
        if name not in self.reg:raise Unsupported('partial/unknown register '+name)
        return self.reg[name]
    def addr(self,i,o):
        if o.mem.segment:raise Unsupported('segment memory')
        v=o.mem.disp
        if o.mem.base:v=add(self.register(i.reg_name(o.mem.base)),v)
        if o.mem.index:
            idx=self.register(i.reg_name(o.mem.index));v=add(v,('mul',idx,o.mem.scale))
        return v
    def load(self,addr,size=4):
        if addr in self.mem:return self.mem[addr]
        if isinstance(addr,tuple) and addr[0]=='stack':
            if addr[1]<4:raise Unsupported('read uninitialized local/return address')
            return ('argument',addr[1],size)
        if isinstance(addr,int) and addr in self.imports:return ('import',self.imports[addr])
        return ('load',addr,size)
    def read(self,i,o):
        if o.type==X86_OP_IMM:return o.imm&0xffffffff
        if o.type==X86_OP_REG:return self.register(i.reg_name(o.reg))
        if o.type==X86_OP_MEM:return self.load(self.addr(i,o),o.size)
        raise Unsupported('operand')
    def write(self,i,o,v):
        if o.type==X86_OP_REG:
            name=i.reg_name(o.reg)
            if name not in self.reg:raise Unsupported('partial register write')
            self.reg[name]=v
        elif o.type==X86_OP_MEM:
            addr=self.addr(i,o)
            if not (isinstance(addr,tuple) and addr[0]=='stack'):raise Unsupported('nonlocal memory write')
            self.mem[addr]=v
        else:raise Unsupported('destination')
    def push(self,v):
        self.reg['esp']=add(self.reg['esp'],-4);self.mem[self.reg['esp']]=v
    def call(self,i):
        target=self.read(i,i.operands[0]);source_top=self.e.resolve(0x10303a12)
        known=(target==('import',TOP) or (isinstance(target,int) and self.e.resolve(target)==source_top and self.e.raw_sha==SOURCE_HASH))
        if not known:raise Unsupported('unmodeled helper call '+i.op_str)
        receiver=self.reg['ecx'];k=self.pops.get(receiver,0);self.pops[receiver]=k+1
        self.events.append(('Top',receiver,k));self.reg['eax']=('Top',receiver,k)
        self.reg['ecx']=('clobbered','ecx',len(self.events));self.reg['edx']=('clobbered','edx',len(self.events))
    def contract(self,method,call,fmt):
        pc=method
        for _ in range(512):
            ins=list(self.e.md.disasm(self.e.data(pc,15),pc,count=1))
            if not ins:raise Unsupported('decode failure')
            i=ins[0];op=i.operands;m=i.mnemonic
            if pc==call:
                if m!='call':raise Unsupported('catalogue is not call')
                sp=self.reg['esp'];arg=lambda n:self.load(add(sp,n*4))
                ptr=arg(1)
                if not isinstance(ptr,int) or self.e.fmt(ptr)!=fmt:raise Unsupported('format argument mismatch')
                # Raw b buffers, doubles and Q use additional ABI arguments.
                if any(x in fmt for x in 'bfQ'):raise Unsupported('buffer/64-bit ABI needs separate contract')
                values=[arg(2+k) for k in range(len(fmt))]
                if any('clobbered' in repr(v) for v in values):raise Unsupported('volatile argument value')
                if arg(0)!=('load',('add',('entry','ecx'),72),4):raise Unsupported('unexpected socket argument')
                slot=0x64 if self.e.raw_sha==SOURCE_HASH else 0x68
                expected=('load',('add',('load',arg(0),4),slot),4)
                if self.read(i,op[0])!=expected:raise Unsupported('unexpected serializer target')
                return {'format':fmt,'arguments':values,'parameter_stack_reads':self.events}
            if m=='push':self.push(self.read(i,op[0]))
            elif m=='pop':
                self.write(i,op[0],self.load(self.reg['esp']));self.reg['esp']=add(self.reg['esp'],4)
            elif m in ('mov','movzx'):
                value=self.read(i,op[1]);self.write(i,op[0],('zero_extend',op[1].size,value) if m=='movzx' else value)
            elif m=='lea':self.write(i,op[0],self.addr(i,op[1]))
            elif m in ('add','sub') and op[1].type==X86_OP_IMM:
                delta=op[1].imm*(1 if m=='add' else -1);self.write(i,op[0],add(self.read(i,op[0]),delta))
            elif m=='xor' and op[0].type==X86_OP_REG and op[1].type==X86_OP_REG and op[0].reg==op[1].reg:self.write(i,op[0],0)
            elif m=='call':self.call(i)
            elif m=='nop':pass
            else:raise Unsupported('control flow/instruction requires review: '+m)
            pc+=i.size
        raise Unsupported('instruction limit')

SOURCE_HASH='17a8bcacd57d071a3420d278a7570ddf2a13abba2f6d4336bb4eb48afd4e244b'
def reachable(engine,entry):
    """Follow edges, never linear-scan beyond RET into the next function."""
    pending=[entry];seen={};errors=[]
    while pending:
        pc=pending.pop()
        if pc in seen:continue
        if len(seen)>12000 or not entry-0x1000<=pc<entry+0x20000:
            errors.append('control-flow limit');break
        ins=list(engine.md.disasm(engine.data(pc,15),pc,count=1))
        if not ins:errors.append('undecodable instruction');continue
        i=ins[0];seen[pc]=i;m=i.mnemonic
        if m.startswith('ret'):continue
        if m in ('int3','ud2'):errors.append('trap/unreachable padding');continue
        if m.startswith('j') or m.startswith('loop'):
            if len(i.operands)!=1 or i.operands[0].type!=X86_OP_IMM:
                errors.append('indirect jump/switch');continue
            pending.append(i.operands[0].imm&0xffffffff)
            if m=='jmp':continue
        pending.append(pc+i.size)
    return seen,sorted(set(errors))

def inbound_evidence(engine,row):
    if not row.get('handler_va'):return {'pending_reason':'handler address unresolved'}
    entry=int(row['handler_va'],16);ins,errors=reachable(engine,entry)
    decoder=engine.resolve(int(row['decoder_target'],16));calls=[]
    observed={int(r['call_va'],16):r['format'] for r in row.get('decode_segments',[])}
    predecessors={}
    for address,i in ins.items():
        if not i.mnemonic.startswith('ret') and i.mnemonic!='jmp':predecessors.setdefault(address+i.size,[]).append(address)
        if i.mnemonic.startswith(('j','loop')) and i.operands[0].type==X86_OP_IMM:predecessors.setdefault(i.operands[0].imm&0xffffffff,[]).append(address)
    def decoder_format(call):
        pc=call;pushes=0
        for _ in range(32):
            pred=predecessors.get(pc,[])
            if len(pred)!=1:return None
            i=ins[pred[0]];pc=i.address
            if i.mnemonic in ('call','pop') or i.mnemonic.startswith(('j','ret','loop')):return None
            if i.mnemonic=='push':
                pushes+=1
                if pushes==3:return engine.fmt(i.operands[0].imm&0xffffffff) if i.operands[0].type==X86_OP_IMM else None
            elif 'esp' in [i.reg_name(r) for r in i.regs_access()[1]]:return None
        return None
    for va,i in sorted(ins.items()):
        if i.mnemonic=='call' and i.operands[0].type==X86_OP_IMM and engine.resolve(i.operands[0].imm&0xffffffff)==decoder:
            fmt=decoder_format(va)
            calls.append({'call_va':hex(va),'format':fmt,'catalogue_format':observed.get(va),'recovered_missing_format':bool(fmt and va not in observed)})
    # Positive evidence is intentionally narrow: no stack/frame memory access,
    # LEA or branches; consequently the entry packet argument is not retrieved.
    # This does NOT imply callbacks or UI behavior are semantically equivalent.
    no_arg=not errors and not calls
    for i in ins.values():
        if i.mnemonic.startswith(('j','loop')) or i.mnemonic in ('lea','leave','enter'):no_arg=False
        for o in i.operands:
            if o.type==X86_OP_MEM and (i.reg_name(o.mem.base) in ('esp','ebp') or i.reg_name(o.mem.index) in ('esp','ebp')):no_arg=False
            if o.type==X86_OP_REG and i.reg_name(o.reg)=='esp' and i.mnemonic not in ('add','sub'):no_arg=False
    return {'handler_va':row['handler_va'],'reachable_instructions':len(ins),'control_flow_errors':errors,'reachable_decoder_calls':calls,'discarded_unreachable_catalogue_calls':[hex(va) for va in observed if va not in ins], 'entry_packet_argument_not_retrieved':no_arg,'limits':'No direct stack/frame argument access is a triage fact, not proof of callback behavior. Decoder calls alone omit raw reads/helpers.'}

def main():
    comparison=json.loads((ROOT/'comparison.json').read_text());policy=json.loads((ROOT/'outbound-policy.json').read_text())
    engines={}
    for side,path in [('source',ROOT.parent.parent/'system/engine.dll'),('target',ROOT/'build/interlude-engine.dll')]:
        e=Extractor(path);e.raw_sha=hashlib.sha256(e.raw).hexdigest()
        if e.raw_sha!=policy[side+'_sha256']:raise ValueError('Engine hash mismatch')
        engines[side]=e
    rows=[]
    for row in comparison['outbound']:
        if not row['source'] or not row['target']:continue
        result={'name':row['name'],'static_status':row['status'],'source':[],'target':[]}
        for side in engines:
            for site in row[side]:
                item={'call_va':site['call_va'],'method_va':site['method_va']}
                try:item['contract']=Prefix(engines[side]).contract(int(site['method_va'],16),int(site['call_va'],16),site['format'])
                except Unsupported as err:item['pending_reason']=str(err)
                result[side].append(item)
        complete=all('contract' in site for side in engines for site in result[side])
        if complete:
            sig=lambda side:sorted(json.dumps(site['contract'],sort_keys=True) for site in result[side])
            result['resolution']='same_serializer_argument_contract' if sig('source')==sig('target') else 'different_serializer_argument_contract'
        else:result['resolution']='requires_deeper_analysis'
        rows.append(result)
    incoming=[]
    for row in comparison['inbound']:
        if not row['source'] or not row['target']:continue
        d={'table':row['table'],'opcode':row['opcode'],'name':row['source']['name'],'static_status':row['status']}
        for side in engines:d[side]=inbound_evidence(engines[side],row[side])
        if all(d[s].get('entry_packet_argument_not_retrieved') for s in engines):d['resolution']='neither_entry_retrieves_packet_argument'
        elif any(d[s].get('pending_reason') or d[s].get('control_flow_errors') for s in engines):d['resolution']='control_flow_or_handler_unresolved'
        else:
            formats=lambda s:[c['format'] for c in d[s]['reachable_decoder_calls']]
            if any(None in formats(s) for s in engines):d['resolution']='reachable_decoder_format_missing'
            elif formats('source')==formats('target'):d['resolution']='same_reachable_decoder_sites_not_semantic_proof'
            else:d['resolution']='different_reachable_decoder_sites'
        incoming.append(d)
    proof=json.loads((ROOT/'reports/parameter-stack-evidence.json').read_text())
    core=Path('/Users/wenderteixeira/Downloads/Lineage2_Interlude_Client/system/Core.dll')
    if proof['source_engine_sha256']!=SOURCE_HASH or proof['target_core_sha256']!=hashlib.sha256(core.read_bytes()).hexdigest():raise ValueError('Parameter-stack dependency evidence is stale; run native tests')
    result={'hashes':{k:e.raw_sha for k,e in engines.items()},'parameter_stack_evidence':proof,'scope':'Exact serializer argument expressions for supported straight-line prefixes. No semantic claim for callers/UI, unmodeled helpers, variable buffers or control flow. No runtime transformations are enabled by this report.','summary':dict(Counter(r['resolution'] for r in rows)),'inbound_summary':dict(Counter(r['resolution'] for r in incoming)),'outbound':rows,'inbound':incoming}
    (ROOT/'reports/wire-equivalence.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result['summary'],indent=2))
if __name__=='__main__':main()
