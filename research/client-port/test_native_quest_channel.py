"""Offline evidence for the pinned quest callback and channel wire layouts."""
import ctypes as C
import hashlib
import struct
import unittest

import pefile
from native_emitter_audit import NativeEmitter, ROOT
from test_structured_codec import d, h, s
from unicorn.x86_const import UC_X86_REG_ECX, UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_EAX


class NativeQuestChannelTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.engines = {side: NativeEmitter(side) for side in ['source', 'target']}
        lib = C.CDLL(str(ROOT / 'build/libl2k_protocol.dylib'))
        cls.convert = lib.l2k_structured_convert
        cls.convert.argtypes = [C.c_void_p, C.c_uint32, C.c_void_p, C.c_uint32]
        cls.convert.restype = C.c_int
        cls.blocked = lib.l2k_outbound_blocked
        cls.blocked.argtypes = [C.c_void_p, C.c_uint32]

    def test_c4_quest_item_callback_reaches_native_noop(self):
        raw = (ROOT.parent.parent / 'system/NWindow.dll').read_bytes()
        self.assertEqual(hashlib.sha256(raw).hexdigest(),
                         '1fdcf9b455ef7ff93dfedeb9667e61a9874e31fe125982437d98c4d0adea3cce')
        ui = pefile.PE(data=raw)
        # Actual NConsoleWnd constructor installs this vtable; its quest-item
        # slot is 2b8. Relocate for the offline VM, as the real loader must do.
        self.assertEqual(ui.get_data(0x825e6, 6), bytes.fromhex('c70688341b10'))
        self.assertEqual(ui.get_data(0x1b3488 + 0x2b8, 4), d(0x100023f0))
        ui.relocate_image(0x20000000)
        e = self.engines['source']; e.images.append(ui)
        game, console, item = e.DATA + 0x1000, e.DATA + 0x5000, e.DATA + 0x10000
        e.put(game + 0x34, console); e.put(console, 0x201b3488)
        e.u.mem_write(item, bytes(range(64)))
        before = bytes(e.u.mem_read(e.DATA, 0x20000))
        sp = e.STACK + 0x30000
        e.u.mem_write(sp, d(e.STOP, item))
        e.u.reg_write(UC_X86_REG_ESP, sp); e.u.reg_write(UC_X86_REG_ECX, game)
        e.top_calls = 0; e.inner_formats = []
        e.u.emu_start(0x1046e470, e.STOP, count=100)
        self.assertEqual(e.u.reg_read(UC_X86_REG_EIP), e.STOP)
        self.assertEqual(e.u.reg_read(UC_X86_REG_ESP), sp + 8)
        self.assertEqual(bytes(e.u.mem_read(e.DATA, 0x20000)), before)

    def decode(self, side, payload, fmt_va):
        e = self.engines[side]; e.top_calls = 0; e.inner_formats = []
        fmt = e.pe.get_data(fmt_va - 0x10300000, 32).split(b'\0', 1)[0].decode()
        e.u.mem_write(e.DATA + 0x8000, payload)
        e.put(e.DATA + (0x4e48 if side == 'source' else 0x4ef8), e.DATA + 0x8000 + len(payload))
        args = [e.STOP, e.DATA, e.DATA + 0x8000, fmt_va]
        addresses = []
        for idx, field in enumerate(fmt):
            address = e.DATA + 0x18000 + idx * 512
            addresses.append(address); e.u.mem_write(address, bytes(512))
            args.extend([256, address] if field == 'S' else [address])
        sp = e.STACK + 0x30000
        e.u.mem_write(sp, d(*args)); e.u.reg_write(UC_X86_REG_ESP, sp)
        e.u.emu_start(e.resolve(0x10305079 if side == 'source' else 0x103034e5), e.STOP, count=100000)
        self.assertEqual(e.u.reg_read(UC_X86_REG_EIP), e.STOP)
        used = e.u.reg_read(UC_X86_REG_EAX) - (e.DATA + 0x8000)
        fields = []
        for field, address in zip(fmt, addresses):
            if field == 'S':
                data = bytes(e.u.mem_read(address, 256)); end = 0
                while data[end:end+2] != b'\0\0': end += 2
                fields.append(data[:end+2])
            else:
                fields.append(bytes(e.u.mem_read(address, 4)))
        return fields, used

    def test_channel_native_decoders_preserve_every_leader_and_count(self):
        for count in [0, 1, 9]:
            header = s('Líder界') + d(count * 9, count)
            rows = [s(f'Grupo{i}') + d(i + 1) for i in range(count)]
            old = b'\xfe\x30\0' + header + b''.join(rows)
            output = C.create_string_buffer(65533)
            n = self.convert(old, len(old), output, len(output))
            self.assertEqual(n, len(old) + 4 + count * 4)
            source, source_used = self.decode('source', old[3:], 0x107c3954)
            target, target_used = self.decode('target', output.raw[3:n], 0x10884368)
            self.assertEqual(source, [target[0], target[2], target[3]])
            self.assertEqual(target[1], d(0))
            for _ in range(count):
                a, used_a = self.decode('source', old[3+source_used:], 0x107c1d78)
                b, used_b = self.decode('target', output.raw[3+target_used:n], 0x1088424c)
                self.assertEqual(a, [b[0], b[2]]); self.assertEqual(b[1], d(0))
                source_used += used_a; target_used += used_b
            self.assertEqual(source_used + 3, len(old)); self.assertEqual(target_used + 3, n)

    def test_name_based_channel_actions_and_unavailable_details(self):
        for source, target, sub in [(0x103f92d0, 0x10407910, 13), (0x103f93d0, 0x104079d0, 15)]:
            for name in ['Leader', 'Líder界']:
                text = s(name)
                for side, entry in [('source', source), ('target', target)]:
                    e = self.engines[side]
                    result = e.run(entry, [e.DATA + 0x10000], {0x10000: text})
                    self.assertEqual(result['wire'], b'\xd0' + h(sub) + text)
                    self.assertEqual(self.blocked(result['wire'], len(result['wire'])), 0)
        for object_id in [0, 12345, 0xffffffff]:
            request = b'\xd0\x26\0' + d(object_id)
            self.assertEqual(self.blocked(request, len(request)), 1)

    def test_pet_inventory_rows_need_no_wire_conversion(self):
        # C4 initializes locals after pushing its hh format. The old static
        # extractor missed this call and incorrectly reported a difference.
        formats = {
            'source': (0x107c1644, 0x107c16ec, 0x107c1638),
            'target': (0x1088494c, 0x108849f4, 0x10884940),
        }
        for count in [0, 1, 3, 64]:
            rows = [h(1+i%3, i%4)+d(1000+i, 500+i, 0xf0000000+i)
                    +h(2, 1, i)+d(0x400)+h(20, 0) for i in range(count)]
            payload = h(count)+b''.join(rows)
            results = {}
            for side, (header_fmt, action_fmt, item_fmt) in formats.items():
                header, cursor = self.decode(side, payload, header_fmt)
                self.assertEqual(header, [d(count)])
                decoded = []
                for i in range(count):
                    action, used = self.decode(side, payload[cursor:], action_fmt)
                    cursor += used
                    fields, used = self.decode(side, payload[cursor:], item_fmt)
                    cursor += used
                    self.assertEqual(action, [d(1+i%3), d(i%4)])
                    self.assertEqual(fields, [d(1000+i),d(500+i),d(0xf0000000+i),
                                             d(2),d(1),d(i),d(0x400),d(20),d(0)])
                    decoded.append((action, fields))
                self.assertEqual(cursor, len(payload))
                results[side] = decoded
            self.assertEqual(results['source'], results['target'])
