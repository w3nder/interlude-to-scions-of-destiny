"""Verify the actual Interlude mount functions' zero-coordinate sentinel."""
import struct
import unittest

from native_emitter_audit import NativeEmitter
from unicorn.x86_const import UC_X86_REG_ECX, UC_X86_REG_ESP, UC_X86_REG_EIP


class NativeRideTests(unittest.TestCase):
    def test_zero_coordinates_keep_current_location_on_mount_and_dismount(self):
        e = NativeEmitter('target')
        core = e.images[1]
        name = b'??8FVector@@QBEHABV0@@Z'
        symbol = next(s for s in core.DIRECTORY_ENTRY_EXPORT.symbols if s.name == name)
        iat = next(i.address for d in e.pe.DIRECTORY_ENTRY_IMPORT for i in d.imports if i.name == name)
        e._map_image(e.u, 0, iat, 4, 0, None)
        e.put(iat, core.OPTIONAL_HEADER.ImageBase + symbol.address)
        location = struct.pack('<fff', 123.25, -456.5, 789.75)
        explicit = struct.pack('<fff', -500.5, 2.25, 99.75)
        for entry, stop, prefix in [(0x106290e0, 0x1062914d, [1, 12526, 1]),
                                    (0x1061c960, 0x1061c9e9, [])]:
            for coordinates in [bytes(12), explicit]:
                with self.subTest(entry=hex(entry), coordinates=coordinates):
                    e.u.mem_write(0, bytes(4096))
                    pawn = e.DATA + 0x1000
                    e.put(pawn + 0x718, e.DATA + 0x3000)
                    e.u.mem_write(pawn + 0x1bc, location)
                    sp = e.STACK + 0x30000
                    args = [e.STOP] + prefix
                    e.u.mem_write(sp, struct.pack('<' + 'I' * len(args), *args) + coordinates)
                    e.u.reg_write(UC_X86_REG_ESP, sp)
                    e.u.reg_write(UC_X86_REG_ECX, pawn)
                    e.top_calls = 0
                    e.inner_formats = []
                    e.u.emu_start(entry, stop, count=10000)
                    self.assertEqual(e.u.reg_read(UC_X86_REG_EIP), stop)
                    actual = bytes(e.u.mem_read(sp + len(args) * 4, 12))
                    self.assertEqual(actual, location if coordinates == bytes(12) else explicit)
