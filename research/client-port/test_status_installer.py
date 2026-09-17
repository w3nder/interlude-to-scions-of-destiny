"""Execute compiled Windows installer, including failure-before-publication paths."""
import unittest
import test_login_hooks as harness
from unicorn.x86_const import UC_X86_REG_EAX


class StatusInstallerTests(unittest.TestCase):
    def test_pinned_slot_install_and_failure_paths(self):
        for failure in [None,'precondition','allocation','protection','flush']:
            with self.subTest(failure=failure):
                h=harness.LoginHooksTests(methodName='runTest');h.setUp()
                slot=h.engine+0x126560;original=h.engine+0x126523;code=0x522000
                h.w32(slot,original if failure!='precondition' else original+1)
                h.u.mem_write(h.engine+0x1262c0,b'\xff\x24\x85')
                frees=[];allocations=[];old_oscall=h.oscall
                def oscall(name):
                    if name=='VirtualAlloc':allocations.append(h.args(4));h.ret(16,0 if failure=='allocation' else code)
                    elif name=='VirtualFree':frees.append(h.args(3));h.ret(12,1)
                    elif name=='GetCurrentProcess':h.ret(value=0xffffffff)
                    elif name=='FlushInstructionCache':
                        self.assertEqual(h.args(3),[0xffffffff,code,30]);h.ret(12,0 if failure=='flush' else 1)
                    elif name=='VirtualProtect' and failure=='protection':h.ret(16,0)
                    else:old_oscall(name)
                h.oscall=oscall
                h.call('l2k_install_status_bridge(',[])
                self.assertEqual(h.u.reg_read(UC_X86_REG_EAX),int(failure is None))
                if failure is None:
                    self.assertEqual(h.r32(slot),code)
                    self.assertEqual(bytes(h.u.mem_read(code,4)),b'\x8b\x44\x24\x1c')
                    self.assertEqual(h.r32(code+6),h.engine+0x81f538)
                    self.assertEqual((code+30+h.r32(code+26))&0xffffffff,original)
                    self.assertFalse(frees)
                else:
                    self.assertEqual(h.r32(slot),original+int(failure=='precondition'))
                    self.assertEqual(bool(frees),failure in ('protection','flush'))
                if failure=='precondition':self.assertFalse(allocations)
