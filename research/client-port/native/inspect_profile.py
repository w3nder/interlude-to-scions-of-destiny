"""Record exact build identity and hook candidates, without patching files."""
import hashlib
import json
import struct
import sys
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parent.parent))
from extract_protocol import Extractor

ROOT=Path(__file__).resolve().parent.parent
x=Extractor('/Users/wenderteixeira/Desktop/system-1/engine.dll')
digest=hashlib.sha256(x.raw).hexdigest()
assert digest=='508974c711f207402719e92737e211a2f029c95c2f68fc0e1c31fcbb9dbb232d'
slots=[]
for kind,base,offsets in [('game',0x1088b52c,[0x68,0x78,0x7c]),
                          ('login',0x1088b69c,[0x68,0x80,0x84])]:
    for offset in offsets:
        thunk=struct.unpack('<I',x.data(base+offset,4))[0]
        fn=x.resolve(thunk)
        slots.append(dict(kind=kind,slot_rva=hex(base+offset-x.base),
            expected_pointer=hex(thunk),handler_rva=hex(fn-x.base),entry_bytes=x.data(fn,16).hex()))
dispatch=[]
for opcode in range(13):
    slot=0x10a572c0+4*opcode;thunk=struct.unpack('<I',x.data(slot,4))[0]
    dispatch.append(dict(opcode=f'0x{opcode:02x}',slot_rva=hex(slot-x.base),
        expected_pointer=hex(thunk),handler_rva=hex(x.resolve(thunk)-x.base)))
profile=dict(status='analysis only; no hook installation authorized by this file',
    build_sha256=digest,preferred_image_base=hex(x.base),socket_slots=slots,
    login_dispatch=dispatch,login_dispatch_call_rva=hex(0x10421b49-x.base),
    login_dispatch_abi='cdecl(handler, payload_without_opcode), caller removes 8 bytes; return AL',
    login_phase_field='UNetworkHandler + 0x50 == 1 selects login table; opcode >= 0x0c selects fallback 0x0c',
    limitations=['Relocated runtime pointers must be checked using actual module base',
                 'Entry bytes are evidence, not a complete instruction-boundary patch plan',
                 'C++ core has no socket lifetime, UI callbacks or hook installation yet'])
(ROOT/'native-integration-profile.json').write_text(json.dumps(profile,indent=2)+'\n')
(ROOT/'login-dispatch.json').write_text(json.dumps(dispatch,indent=2)+'\n')
print('Recorded 6 socket slots and 13 login dispatch entries for verified Interlude build.')
