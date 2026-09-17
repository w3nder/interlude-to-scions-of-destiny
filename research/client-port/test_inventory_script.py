"""Exercise the installed interface's bytecode and XDAT, not the legacy native UI."""
import copy
import struct
import tempfile
import unittest
from pathlib import Path

from inventory_bytecode import Reader
from patch_inventory_interface import (BASE, FUNCTION, ORIGINAL, XDAT, assignment,
                                       constant, generate, parse_function, sha)
from unreal_package_index import Package


def function(package, raw, name):
    e = next(e for i, e in enumerate(package.exports) if package.object_path(i + 1) == name)
    decoded = raw[package.offset:].translate(package.translate)
    return decoded[e['offset']:e['offset'] + e['size']]


class InventoryScriptTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.temp = tempfile.TemporaryDirectory()
        cls.out = Path(cls.temp.name) / 'interface.u'
        cls.report = generate(BASE / 'interface.u', cls.out)
        cls.original_raw = (BASE / 'interface.u').read_bytes()
        cls.original = Package(BASE / 'interface.u')
        cls.fixed_raw = cls.out.read_bytes()
        cls.fixed = Package(cls.out)
        cls.before = function(cls.original, cls.original_raw, FUNCTION)
        cls.after = function(cls.fixed, cls.fixed_raw, FUNCTION)

    @classmethod
    def tearDownClass(cls):
        cls.temp.cleanup()

    def test_only_selected_index_and_relocated_branches_change(self):
        start, size, p, tops = parse_function(self.before)
        start2, size2, q, newtops = parse_function(self.after)
        edit = assignment(tops, 1)
        self.assertEqual((start2, size2, len(q.nodes)), (start, size + 1, len(p.nodes)))
        self.assertEqual(self.before[start + p.p:], self.after[start2 + q.p:])
        targets = {t['v'] for t in newtops} | {size2}
        for a, b in zip(p.nodes, q.nodes):
            expected = copy.deepcopy(a)
            if a is edit:
                expected.update(op=0x2c, value=3)
            if 'jump' in expected and expected['jump'] != 65535:
                expected['jump'] += int(expected['jump'] > edit['v'])
                self.assertIn(b['jump'], targets)
            # Children are independently checked in parser order; physical and
            # VM offsets necessarily move after the enlarged integer literal.
            ignored = {'children', 'p', 'v', 'end', 'vend', 'jump_p', 'skip_p'}
            self.assertEqual({k: v for k, v in expected.items() if k not in ignored},
                             {k: v for k, v in b.items() if k not in ignored})
        self.assertEqual(constant(assignment(newtops, 1)), 3)
        self.assertEqual(constant(assignment(newtops, 8192)), 0)

    def run_updates(self, payload, order):
        # Small interpreter for these two real case bodies and their shared
        # Clear/AddItem tail. Widget methods are observations, not game actions.
        _, _, parser, tops = parse_function(payload)
        by_vm = {t['v']: i for i, t in enumerate(tops)}
        windows = [[] for _ in range(15)]
        for mask, item in order:
            chosen = next(i for i, t in enumerate(tops) if t['op'] == 10 and t['children']
                          and constant(t['children'][0]) == mask)
            let = tops[chosen + 1]
            handle_ref = let['children'][0]['ref']
            info_ref = next(n['ref'] for n in tops[0]['children'][0]['children'] if n['op'] == 0)
            locals_ = {info_ref: item}
            def evaluate(t, context=None):
                op = t['op']; c = t['children']
                if op in (0x25, 0x26, 0x2c, 0x1d): return constant(t)
                if op == 0: return locals_.get(t['ref'])
                if op == 1: return windows
                if op == 0x1a: return evaluate(c[1])[evaluate(c[0])]
                if op == 0xf: locals_[c[0]['ref']] = evaluate(c[1]); return None
                if op == 0x2a: return None
                if op == 0x77: return evaluate(c[0]) is not evaluate(c[1])
                if op == 0x19: return evaluate(c[1], evaluate(c[0]))
                if op == 0x1b:
                    name = self.fixed.names[t['ref']]
                    if name == 'Clear': context.clear()
                    elif name == 'AddItem': context.append(evaluate(c[0]))
                    else: raise AssertionError(name)
                    return None
                raise AssertionError(hex(op))
            pc = chosen + 1
            for _ in range(20):
                t = tops[pc]
                if t['op'] == 4: break
                if t['op'] == 6: pc = by_vm[t['jump']]; continue
                if t['op'] == 7:
                    if not evaluate(t['children'][0]): pc = by_vm[t['jump']]; continue
                else: evaluate(t)
                pc += 1
            else: self.fail('Script did not return')
            self.assertIsNotNone(locals_[handle_ref])
        return windows

    def test_reproduces_overlap_and_separates_both_update_orders(self):
        for order in [[(1, 27622), (8192, 27307)], [(8192, 27307), (1, 27622)],
                      [(1, 27622), (8192, 27307), (1, 27602)]]:
            before = self.run_updates(self.before, order)
            self.assertEqual(sum(map(len, before)), 1)
            after = self.run_updates(self.after, order)
            self.assertEqual(after[0], [27307])
            self.assertEqual(after[3], [next(item for mask, item in reversed(order) if mask == 1)])
            self.assertEqual(sum(map(len, after)), 2)

    def test_all_other_package_objects_remain_byte_identical(self):
        self.assertEqual(self.original.names, self.fixed.names)
        self.assertEqual(self.original.imports, self.fixed.imports)
        self.assertEqual(len(self.original.exports), len(self.fixed.exports))
        a = self.original_raw[28:].translate(self.original.translate)
        b = self.fixed_raw[28:].translate(self.fixed.translate)
        for i, (old, new) in enumerate(zip(self.original.exports, self.fixed.exports)):
            if i + 1 == self.report['export_index']: continue
            self.assertEqual(old, new)
            self.assertEqual(a[old['offset']:old['offset'] + old['size']],
                             b[new['offset']:new['offset'] + new['size']])

    def test_original_layout_has_separate_third_and_fourth_cells(self):
        b = (BASE / 'interface.xdat').read_bytes()
        self.assertEqual(sha(b), XDAT)
        def string(r):
            n = r.compact(); start = r.p; r.p += abs(n) * (2 if n < 0 else 1)
            return r.b[start:r.p].decode('utf-16le' if n < 0 else 'latin1').rstrip('\0')
        slots = {}; at = 0
        while (at := b.find(b'\x0bItemWindow\0', at)) >= 0:
            r = Reader(b); r.p = at + 12; at = r.p
            name = string(r); parent = string(r); r.num(4); r.num(4)
            owner = string(r); string(r); string(r); r.num(4)
            dimensions = None
            if r.num(4):
                if not r.num(4): r.compact(); r.num(4); r.num(4)
                dimensions = (r.num(4), r.num(4))
            anchor = None
            if r.num(4): anchor = (r.num(4), r.num(4), string(r), r.num(4), r.num(4))
            if owner == 'InventoryWnd': slots[name] = (parent, dimensions, anchor)
        self.assertEqual(slots['EquipItem_Hair2'][0], 'EquipItem_Underwear')
        self.assertEqual(slots['EquipItem_Underwear'][1], (34, 34))
        self.assertEqual(slots['EquipItem_Hair2'][2][-2:], (92, 36))
        self.assertEqual(slots['EquipItem_Underwear'][2][-2:], (137, 36))
        self.assertLess(92 + 34, 137)

    def test_onload_binds_array_three_to_the_visible_hair2_control(self):
        data = function(self.original, self.original_raw, 'InventoryWnd.OnLoad')
        _, _, onload, _ = parse_function(data)
        self.assertTrue(any(n['op'] == 0x1b and self.original.names[n['ref']] == 'InitHandle'
                            for n in onload.nodes))
        data = function(self.original, self.original_raw, 'InventoryWnd.InitHandle')
        _, _, p, _ = parse_function(data)
        found = False
        for t in p.nodes:
            if t['op'] != 0xf or t['children'][0]['op'] != 0x1a: continue
            array = t['children'][0]
            if constant(array['children'][0]) != 3: continue
            strings = [n['value'] for n in p.nodes if t['p'] <= n['p'] < t['end'] and n['op'] == 0x1f]
            if any('EquipItem_Hair2' in s for s in strings): found = True
        self.assertTrue(found)

    def test_unknown_original_rejected(self):
        with self.assertRaises(ValueError): generate(self.out, Path(self.temp.name) / 'other.u')
        self.assertEqual(sha(self.original_raw), ORIGINAL)
