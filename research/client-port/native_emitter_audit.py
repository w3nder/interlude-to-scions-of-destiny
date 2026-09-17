"""Offline differential execution of list-building senders in fingerprinted engines.

Only synthetic inputs are used. The VM stops at the virtual sender; it has no
network/OS implementation. Equal vectors are evidence, not a universal proof.
"""
import hashlib
import struct
from pathlib import Path
import pefile
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_MEM_UNMAPPED, UC_HOOK_CODE
from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_EBX, UC_X86_REG_ECX,
                               UC_X86_REG_EDX, UC_X86_REG_ESI, UC_X86_REG_EDI,
                               UC_X86_REG_EBP, UC_X86_REG_ESP, UC_X86_REG_EIP,
                               UC_X86_REG_EFLAGS)

ROOT = Path(__file__).resolve().parent
PROFILES = {
    'source': {'path': ROOT.parent.parent / 'system/engine.dll',
               'sha256': '17a8bcacd57d071a3420d278a7570ddf2a13abba2f6d4336bb4eb48afd4e244b',
               'top': 0x1046c7a0, 'serializer_thunk': 0x10308f2b, 'slot': 0x64},
    'target': {'path': ROOT / 'build/interlude-engine.dll',
               'sha256': '508974c711f207402719e92737e211a2f029c95c2f68fc0e1c31fcbb9dbb232d',
               'top': 0x1015b5c0, 'serializer_thunk': 0x103068b6, 'slot': 0x68},
}

class NativeEmitter:
    STACK = 0x02000000
    DATA = 0x03000000
    STOP = 0x04000000
    SEND = STOP + 0x100

    def __init__(self, side):
        self.side = side
        self.profile = PROFILES[side]
        raw = self.profile['path'].read_bytes()
        if hashlib.sha256(raw).hexdigest() != self.profile['sha256']:
            raise ValueError('Unsupported engine hash')
        self.pe = pefile.PE(data=raw)
        self.images = [self.pe]
        self.u = Uc(UC_ARCH_X86, UC_MODE_32)
        self.mapped = set()
        self.u.mem_map(0, 0x1000, 3)  # Minimal synthetic TEB/SEH chain.
        self.u.mem_map(self.STACK, 0x40000)
        self.u.mem_map(self.DATA, 0x40000)
        self.u.mem_map(self.STOP, 0x1000)
        self.u.hook_add(UC_HOOK_MEM_UNMAPPED, self._map_image)
        self.u.hook_add(UC_HOOK_CODE, self._instruction)
        if side == 'target':
            core_path = ROOT / 'build/interlude-core.dll'
            if not core_path.exists():
                core_path = Path('/Users/wenderteixeira/Downloads/Lineage2_Interlude_Client/system/Core.dll')
            core_raw = core_path.read_bytes()
            import json
            evidence = json.loads((ROOT / 'reports/parameter-stack-evidence.json').read_text())
            if hashlib.sha256(core_raw).hexdigest() != evidence['target_core_sha256']:
                raise ValueError('Unverified Core dependency')
            self.images.append(pefile.PE(data=core_raw))
            self.profile = dict(self.profile, top=int(evidence['target_top_va'], 16))
            top_iat = next(i.address for d in self.pe.DIRECTORY_ENTRY_IMPORT for i in d.imports
                           if i.name == b'?Top@L2ParamStack@@QAEPAXXZ')
            self._map_image(self.u, 0, top_iat, 4, 0, None)
            self.put(top_iat, self.profile['top'])
        if side == 'source':
            crt_raw = (ROOT.parent.parent / 'system/MSVCR70.dll').read_bytes()
            if hashlib.sha256(crt_raw).hexdigest() != '579741e17cf50df43b53d69c29992d6f23b8ac9e522a2a489dabf1688092f365':
                raise ValueError('Unverified C4 CRT dependency')
            crt = pefile.PE(data=crt_raw)
            self.images.append(crt)
            wcslen = next(s.address for s in crt.DIRECTORY_ENTRY_EXPORT.symbols if s.name == b'wcslen')
            iat = next(i.address for d in self.pe.DIRECTORY_ENTRY_IMPORT for i in d.imports if i.name == b'wcslen')
            self._map_image(self.u, 0, iat, 4, 0, None)
            self.put(iat, crt.OPTIONAL_HEADER.ImageBase + wcslen)
        self.u.mem_write(self.STOP + 0x200, bytes.fromhex('31c0c3'))  # cdecl diagnostic callback only
        self.serializer = self.resolve(self.profile['serializer_thunk'])

    def resolve(self, address):
        for _ in range(8):
            b = self.pe.get_data(address - self.pe.OPTIONAL_HEADER.ImageBase, 5)
            if b[:1] != b'\xe9':
                return address
            address += 5 + struct.unpack('<i', b[1:])[0]
        raise ValueError('Thunk loop')

    def _map_image(self, u, access, address, size, value, opaque):
        for pe in self.images:
            base = pe.OPTIONAL_HEADER.ImageBase
            if base <= address and address + size <= base + pe.OPTIONAL_HEADER.SizeOfImage:
                for page in range(address & ~4095, (address + size + 4095) & ~4095, 4096):
                    if page not in self.mapped:
                        u.mem_map(page, 4096)
                        u.mem_write(page, bytes(pe.get_data(page - base, 4096)))
                        self.mapped.add(page)
                return True
        return False

    def _instruction(self, u, address, size, opaque):
        if address == (0x103f30a0 if self.side == 'source' else 0x10402610):
            sp = u.reg_read(UC_X86_REG_ESP)
            fmt = struct.unpack('<I', u.mem_read(sp + 16, 4))[0]
            self.inner_formats.append(self.pe.get_data(fmt - self.pe.OPTIONAL_HEADER.ImageBase, 64).split(b'\0', 1)[0].decode('ascii'))
        if address == self.profile['top']:
            self.top_calls += 1
            if self.top_calls > 10000:
                raise ValueError('Parameter-stack limit')
        if address == self.SEND:
            self.send_stack = u.reg_read(UC_X86_REG_ESP)
            u.emu_stop()

    def put(self, address, value):
        self.u.mem_write(address, struct.pack('<I', value & 0xffffffff))

    def bind_core_import(self, name):
        """Bind an actual, fingerprinted Core export; never emulate its result."""
        if self.side == 'source' and not any(p.OPTIONAL_HEADER.ImageBase == 0x10100000 for p in self.images):
            raw = (ROOT.parent.parent/'system/Core.dll').read_bytes()
            if hashlib.sha256(raw).hexdigest() != 'b3b367b7b8fea00641d789b8d7acfb9e520ef9f88bd46ea834736e0017c4643f':
                raise ValueError('Unverified C4 Core dependency')
            self.images.append(pefile.PE(data=raw))
        core = next(p for p in self.images if p.OPTIONAL_HEADER.ImageBase == 0x10100000)
        entry = next(s for s in core.DIRECTORY_ENTRY_EXPORT.symbols if s.name == name)
        slot = next(i.address for d in self.pe.DIRECTORY_ENTRY_IMPORT for i in d.imports if i.name == name)
        self._map_image(self.u, 0, slot, 4, 0, None)
        self.put(slot, core.OPTIONAL_HEADER.ImageBase + entry.address)

    def run(self, entry, values, blobs=None, *, direct_arguments=None, object_fields=None):
        if len(values) > 1024:
            raise ValueError('Synthetic parameter stack exceeds reserved region')
        u = self.u
        u.mem_write(0, bytes(0x1000))
        u.mem_write(self.STACK, bytes(0x40000))
        u.mem_write(self.DATA, bytes(0x40000))
        for reg in [UC_X86_REG_EAX, UC_X86_REG_EBX, UC_X86_REG_ECX,
                    UC_X86_REG_EDX, UC_X86_REG_ESI, UC_X86_REG_EDI, UC_X86_REG_EBP]:
            u.reg_write(reg, 0)
        u.reg_write(UC_X86_REG_EFLAGS, 2)
        obj, socket, vtable, params, array = [self.DATA + k for k in [0, 0x1000, 0x2000, 0x3000, 0x4000]]
        self.put(obj + 0x48, socket)
        self.put(socket, vtable)
        self.put(socket + 0x38, 1)  # Synthetic connected handle; no OS socket exists.
        self.put(vtable + self.profile['slot'], self.SEND)
        for offset, value in (object_fields or {}).items():
            if not 0x4c <= offset <= 0xffc:
                raise ValueError('Synthetic field overlaps sender ABI or another object')
            self.put(obj + offset, value)
        if self.side == 'source':
            # Original C4 list builders print each row via GL2Console. No UI is run.
            self._map_image(u, 0, 0x10b36bbc, 4, 0, None)
            self.put(0x10b36bbc, self.DATA + 0x5000)
            self.put(self.DATA + 0x5000, self.DATA + 0x6000)
            self.put(self.DATA + 0x6000 + 0x2c0, self.STOP + 0x200)
        self.put(params, array)
        cursor, count = (8, 12) if self.side == 'source' else (4, 8)
        self.put(params + cursor, 0)
        self.put(params + count, len(values))
        for i, v in enumerate(values):
            self.put(array + 4 * i, v)
        for offset, data in (blobs or {}).items():
            if not 0x10000 <= offset or offset + len(data) > 0x20000:
                raise ValueError('Synthetic blob outside reserved region')
            u.mem_write(self.DATA + offset, data)
        stack = self.STACK + 0x30000
        self.put(stack, self.STOP)
        if direct_arguments is None:
            self.put(stack + 4, params)
        else:
            if len(direct_arguments) > 1024:
                raise ValueError('Direct argument limit')
            for i, value in enumerate(direct_arguments):
                self.put(stack + 4 + i * 4, value)
        u.reg_write(UC_X86_REG_ESP, stack)
        u.reg_write(UC_X86_REG_ECX, obj)
        self.top_calls = 0
        self.inner_formats = []
        self.send_stack = None
        try:
            u.emu_start(entry, self.STOP, count=2000000)
        except Exception as e:
            raise RuntimeError(f'{self.side} emitter {entry:x} stopped at {u.reg_read(UC_X86_REG_EIP):x}: {e}') from e
        if self.send_stack is None:
            raise ValueError('No send reached within instruction budget')
        send_stack = self.send_stack
        _, sock, fmt = struct.unpack('<III', u.mem_read(send_stack, 12))
        if sock != socket:
            raise ValueError('Unexpected sender receiver')
        self._map_image(u, 0, fmt, 64, 0, None)
        text = bytes(u.mem_read(fmt, 64)).split(b'\0', 1)[0].decode('ascii')
        consumed = struct.unpack('<I', u.mem_read(params + cursor, 4))[0]
        # Run the actual native serializer with the sender's untouched varargs.
        call_stack = self.STACK + 0x10000
        output = self.DATA + 0x20000
        u.mem_write(call_stack, struct.pack('<IIIII', self.STOP, output, 65533, fmt, send_stack + 12))
        u.reg_write(UC_X86_REG_ESP, call_stack)
        u.emu_start(self.serializer, self.STOP, count=2000000)
        if u.reg_read(UC_X86_REG_EIP) != self.STOP:
            raise ValueError('Serializer instruction budget exceeded')
        length = u.reg_read(UC_X86_REG_EAX)
        if length > 65533:
            raise ValueError(f'Serializer rejected input: {length}')
        return {'format': text, 'consumed': consumed, 'top_calls': self.top_calls,
                'wire': bytes(u.mem_read(output, length)), 'inner_formats': self.inner_formats}
