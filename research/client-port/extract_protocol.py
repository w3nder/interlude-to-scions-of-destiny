"""Static x86 packet evidence extractor. Does not execute or modify the client.

Requires capstone==5.0.9 and pefile==2024.8.26. Formats describe individual
serialization calls, never a complete schema or proof of wire compatibility.
"""
import argparse
import bisect
import hashlib
import json
import re
import struct
from collections import Counter
from pathlib import Path

import capstone as cs
import pefile
from capstone.x86 import X86_OP_IMM


class Extractor:
    def __init__(self, path):
        self.path = Path(path)
        self.raw = self.path.read_bytes()
        self.pe = pefile.PE(data=self.raw)
        self.base = self.pe.OPTIONAL_HEADER.ImageBase
        self.md = cs.Cs(cs.CS_ARCH_X86, cs.CS_MODE_32)
        self.md.detail = True
        self.exports = {}
        for e in self.pe.DIRECTORY_ENTRY_EXPORT.symbols:
            if e.name:
                self.exports[e.name.decode(errors='replace')] = self.resolve(self.base + e.address)
        self.starts = sorted(set(self.exports.values()))

    def data(self, va, size=256):
        if not self.base <= va < self.base + self.pe.OPTIONAL_HEADER.SizeOfImage:
            return b''
        return self.pe.get_data(va - self.base, size)

    def resolve(self, va):
        seen = set()
        while va not in seen:
            seen.add(va)
            b = self.data(va, 5)
            if len(b) != 5 or b[0] != 0xE9:
                break
            va = va + 5 + struct.unpack_from('<i', b, 1)[0]
        return va

    def body(self, va):
        n = bisect.bisect_right(self.starts, va)
        size = min(0x20000, self.starts[n] - va) if n < len(self.starts) else 0x20000
        b = self.data(va, size)
        pad = re.search(b'\xcc{8,}', b)
        if pad:
            b = b[:pad.start()]
        return list(self.md.disasm(b, va))

    @staticmethod
    def immediate(i):
        if len(i.operands) == 1 and i.operands[0].type == X86_OP_IMM:
            return i.operands[0].imm & 0xFFFFFFFF

    def fmt(self, va):
        b = self.data(va, 256).split(b'\0', 1)[0]
        return b.decode('ascii') if re.fullmatch(rb'[chdfSsbQ]+', b) else None

    def format_calls(self, ins):
        for j, i in enumerate(ins):
            v = self.immediate(i)
            if i.mnemonic != 'push' or v is None:
                continue
            fmt = self.fmt(v)
            if not fmt:
                continue
            # Compilers can initialize locals between pushing a format and
            # calling the decoder (C4 PetInventoryUpdate does this). Stop at
            # control flow, not an arbitrary eleven-instruction window.
            for call in ins[j+1:]:
                if call.mnemonic in ('ret', 'jmp') or call.mnemonic.startswith('j'):
                    break
                if call.mnemonic == 'call':
                    yield j, fmt, call
                    break

    def outbound(self):
        result = []
        for name, va in self.exports.items():
            if '@UNetworkHandler@@' not in name or not name.startswith('?'):
                continue
            ins = self.body(va)
            for j, fmt, call in self.format_calls(ins):
                if not fmt.startswith('c') or j == 0:
                    continue
                previous = next((i for i in reversed(ins[max(0,j-6):j])
                                 if i.mnemonic in ('push', 'call', 'jmp', 'ret')), None)
                op = self.immediate(previous) if previous else None
                if previous is None or previous.mnemonic != 'push' or op is None or op > 255:
                    continue
                result.append(dict(direction='C -> S', name=name.split('@')[0][1:],
                    export=name, method_va=hex(va), call_va=hex(call.address),
                    opcode=f'0x{op:02X}', format=fmt, call_target=call.op_str,
                    confidence='static immediate opcode and format; session phase and field semantics unresolved'))
        return sorted(result, key=lambda r: int(r['call_va'], 16))

    def inbound(self):
        candidates = []
        names = {}
        for m in re.finditer(rb'(?:[A-Za-z0-9_]\x00){3,80}', self.raw):
            name = m.group().decode('utf-16le')
            # Names are diagnostic labels, not a protocol classifier. Several
            # real registrations (e.g. PledgeReceivePowerInfo) have neither a
            # Packet suffix nor an Ex prefix. Table address/stride below is
            # the structural filter; do not discard them by spelling.
            rva = self.pe.get_rva_from_offset(m.start())
            if rva is not None:
                names[self.base + rva] = name
        # Index push immediates once, including overlapping matches. Searching
        # the complete image separately for every label was quadratic.
        for ref in re.finditer(rb'(?=\x68(.{4}))', self.raw, re.DOTALL):
            name = names.get(struct.unpack('<I', ref.group(1))[0])
            if name is None:
                continue
            rva = self.pe.get_rva_from_offset(ref.start())
            if rva is None:
                continue
            addr = self.base + rva
            ins = list(self.md.disasm(self.data(addr, 48), addr))
            dest = None
            for i in ins[1:5]:
                if i.mnemonic == 'call':
                    break
                if i.mnemonic == 'push' and self.immediate(i) is not None:
                    dest = self.immediate(i)
                    break
            if dest is not None and self.base <= dest < self.base + self.pe.OPTIONAL_HEADER.SizeOfImage:
                candidates.append(dict(name=name, registration_va=hex(addr), name_storage_va=dest))
        # Native descriptor layout: handler pointer, 256-byte name storage.
        # Anchor by explicit names, then require exact stride and bounded slot.
        anchors = [(r['name_storage_va'], 'primary') for r in candidates if r['name'] == 'VersionCheckPacket']
        anchors += [(r['name_storage_va'], 'extended') for r in candidates if r['name'] == 'ExDummyPacket']
        result = []
        for r in candidates:
            slot = r['name_storage_va']
            hits = [(base, table, (slot-base)//260) for base, table in anchors
                    if 0 <= slot-base < 256*260 and (slot-base) % 260 == 0]
            if len(hits) != 1:
                continue
            base, table, op = hits[0]
            row = dict(direction='S -> C', table=table, opcode=f'0x{op:02X}', **r)
            row['name_storage_va'] = hex(slot)
            row['table_name_base_va'] = hex(base)
            stores = list(re.finditer(re.escape(b'\xc7\x05' + struct.pack('<I', slot-4)), self.raw))
            handlers = set()
            for store in stores:
                thunk = struct.unpack_from('<I', self.raw, store.start()+6)[0]
                if self.base <= thunk < self.base + self.pe.OPTIONAL_HEADER.SizeOfImage:
                    handlers.add(thunk)
            # Slot zero is initialized in PE data rather than by the runtime
            # C7 05 stores used for subsequent registrations.
            if not handlers:
                initial = struct.unpack('<I', self.data(slot-4, 4))[0]
                if self.base <= initial < self.base + self.pe.OPTIONAL_HEADER.SizeOfImage:
                    handlers.add(initial)
            if len(handlers) == 1:
                thunk = handlers.pop()
                handler = self.resolve(thunk)
                row.update(thunk_va=hex(thunk), handler_va=hex(handler))
                row['decode_segments'] = [dict(call_va=hex(call.address), format=fmt,
                    call_target=call.op_str, layout_complete=False)
                    for _, fmt, call in self.format_calls(self.body(handler))]
            else:
                row['decode_segments'] = []
                row['handler_resolution'] = 'missing or ambiguous static assignment'
            result.append(row)
        # Eliminate format-like pointers used by unrelated APIs (including the
        # first ASCII byte of a UTF-16 string). Keep the dominant direct decoder.
        targets = Counter(s['call_target'] for r in result for s in r['decode_segments']
                          if s['call_target'].startswith('0x'))
        decoder = targets.most_common(1)[0][0] if targets else None
        for row in result:
            row['decode_segments'] = [s for s in row['decode_segments'] if s['call_target'] == decoder]
            row['decoder_target'] = decoder
        return sorted(result, key=lambda r: (r['table'], int(r['opcode'], 16)))

    def run(self):
        return dict(binary=str(self.path), engine_sha256=hashlib.sha256(self.raw).hexdigest(),
            image_base=hex(self.base), scope='Static evidence only. Session phases, semantic field mapping, extended outbound subopcodes and runtime compatibility are not established. Decode segments may be conditional or repeated; matching formats do not establish matching semantics.',
            outbound_call_sites=self.outbound(), inbound_registrations=self.inbound())


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('binary')
    parser.add_argument('output')
    args = parser.parse_args()
    result = Extractor(args.binary).run()
    Path(args.output).write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({k:len(v) for k,v in result.items() if isinstance(v,list)}))
