"""Execute actual C4/Interlude slot mapping with synthetic equipment identities."""
import hashlib
import struct
import unittest

import pefile
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_ECX, UC_X86_REG_EAX, UC_X86_REG_EIP

from patch_inventory_slot import ROOT, patch


class SlotMachine:
    def __init__(self, raw, side):
        self.u = u = Uc(UC_ARCH_X86, UC_MODE_32)
        pe = pefile.PE(data=raw)
        base = pe.OPTIONAL_HEADER.ImageBase
        u.mem_map(base, (pe.OPTIONAL_HEADER.SizeOfImage + 4095) & ~4095)
        u.mem_write(base, pe.get_memory_mapped_image())
        u.mem_map(0x20000000, 0x10000)
        self.entry = 0x10074590 if side == 'source' else 0x1014e550
        lookup = 0x10073f30 if side == 'source' else 0x1014dd00
        offset = 0x98 if side == 'source' else 0x9c
        u.mem_write(0x20001000 + offset, struct.pack('<5I', 101, 102, 0, 103, 104))

        def callback(vm, address, size, data):
            if address == lookup:
                sp = vm.reg_read(UC_X86_REG_ESP)
                ret = struct.unpack('<I', vm.mem_read(sp, 4))[0]
                vm.reg_write(UC_X86_REG_EAX, 0x20001000)
                vm.reg_write(UC_X86_REG_ESP, sp + 4)
                vm.reg_write(UC_X86_REG_EIP, ret)
        u.hook_add(UC_HOOK_CODE, callback)

    def slot(self, mask, identity=200):
        u = self.u
        u.mem_write(0x20008000, struct.pack('<3I', 0x2000f000, mask, identity))
        u.reg_write(UC_X86_REG_ESP, 0x20008000)
        u.reg_write(UC_X86_REG_ECX, 0x20002000)
        u.emu_start(self.entry, 0x2000f000, count=1000)
        assert u.reg_read(UC_X86_REG_EIP) == 0x2000f000
        assert u.reg_read(UC_X86_REG_ESP) == 0x2000800c
        return u.reg_read(UC_X86_REG_EAX)

    def hit(self, x, y):
        # Actual target hit-test, its actual vtable rectangle function and x87
        # conversion helper. No mocked rectangle logic or game UI execution.
        u = self.u
        u.mem_write(0x20002000, struct.pack('<I', 0x10289ab4))
        u.mem_write(0x20002080, bytes(8))
        u.mem_write(0x20008000, struct.pack('<3I', 0x2000f000, x, y))
        u.reg_write(UC_X86_REG_ESP, 0x20008000)
        u.reg_write(UC_X86_REG_ECX, 0x20002000)
        u.emu_start(0x10176880, 0x2000f000, count=10000)
        assert u.reg_read(UC_X86_REG_EIP) == 0x2000f000
        assert u.reg_read(UC_X86_REG_ESP) == 0x2000800c
        return u.reg_read(UC_X86_REG_EAX)


class InventorySlotTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.original = (ROOT / 'build/target-nwindow.dll').read_bytes()
        source = (ROOT / 'build/source-nwindow.dll').read_bytes()
        assert hashlib.sha256(source).hexdigest() == '1fdcf9b455ef7ff93dfedeb9667e61a9874e31fe125982437d98c4d0adea3cce'
        cls.source = SlotMachine(source, 'source')
        cls.target = SlotMachine(cls.original, 'target')
        cls.fixed = SlotMachine(patch(cls.original), 'target')

    def test_back_tattoo_restores_drawable_c4_cell_without_underwear_collision(self):
        self.assertEqual(self.source.slot(8192), 2)
        self.assertEqual(self.target.slot(8192), 19)
        self.assertEqual(self.fixed.slot(8192), 2)
        self.assertEqual(self.fixed.slot(1), 3)
        self.assertNotEqual(self.fixed.slot(8192), self.fixed.slot(1))

    def test_every_other_mask_and_jewelry_identity_keeps_native_result(self):
        masks = [0, 1, 2, 4, 6, 8, 16, 32, 48] + [1 << bit for bit in range(6, 32)]
        for mask in masks:
            for identity in [0, 101, 102, 103, 104, 200]:
                if mask != 8192:
                    self.assertEqual(self.fixed.slot(mask, identity), self.target.slot(mask, identity), (mask, identity))

    def test_native_click_rectangles_select_two_separate_tattoos(self):
        for x, y, mask in [(86, 8, 8192), (101, 23, 8192), (116, 38, 8192),
                           (131, 8, 1), (146, 23, 1), (161, 38, 1)]:
            self.assertEqual(self.fixed.hit(x, y), self.fixed.slot(mask))
        self.assertEqual(self.fixed.hit(250, 180), 0xffffffff)

    def test_only_one_byte_changes_and_unknown_binaries_are_rejected(self):
        output = patch(self.original)
        self.assertEqual(len(output), len(self.original))
        self.assertEqual(sum(a != b for a, b in zip(output, self.original)), 1)
        with self.assertRaises(ValueError):
            patch(output)
        with self.assertRaises(ValueError):
            patch(b'unknown')
