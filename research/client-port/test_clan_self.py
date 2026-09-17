"""Missing C4 self row, packet order, duplicates, session isolation and capacity."""
import ctypes as C
import unittest
from test_cpp_core import ROOT
from test_pledge_bridge import roster
from test_structured_codec import d,s

def identity(name='Self',oid=100):return b'\x15'+s(name)+d(oid)
def info(name='Self',oid=100,level=80,klass=88):
    return b'\x04'+d(1,2,3,4,oid)+s(name)+d(1,0,klass,level)+bytes(520)
def member(op=0x55,level=80,klass=88):
    return bytes([op])+s('Self')+d(level,klass,0,1,100,0)+ (d(0) if op==0x54 else b'')

class ClanSelfTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.lib=C.CDLL(str(ROOT/'build/libl2k_protocol.dylib'))
        cls.lib.l2k_clan_self_size.restype=C.c_uint32
        cls.fn=cls.lib.l2k_clan_self_receive
        cls.fn.argtypes=[C.c_void_p,C.c_void_p,C.c_uint32,C.c_uint32,C.c_void_p,C.c_uint32]
        cls.fn.restype=C.c_int
    def setUp(self):self.state=C.create_string_buffer(self.lib.l2k_clan_self_size())
    def receive(self,p,legacy=0,cap=160):
        out=C.create_string_buffer(b'\xa5'*164,164)
        n=self.fn(self.state,p,len(p),legacy,out,cap)
        self.assertEqual(out.raw[cap:],b'\xa5'*(164-cap))
        return n,out.raw[:max(0,n)]
    def test_real_order_roster_before_userinfo_adds_once(self):
        self.receive(identity());self.assertEqual(self.receive(roster([('Friend',200)]),1)[0],0)
        self.assertEqual(self.receive(info())[1],member())
        for _ in range(10):self.assertEqual(self.receive(info())[0],0)
    def test_userinfo_before_roster_and_roster_refresh(self):
        self.receive(identity());self.receive(info())
        for _ in range(3):self.assertEqual(self.receive(roster([('Friend',200)]),1)[1],member())
    def test_existing_self_by_name_or_id_and_modern_roster_not_duplicated(self):
        for entries,legacy in [([('Self',100)],1),([('Self',0)],1),([('Renamed',100)],1),([('Friend',200)],0)]:
            self.setUp();self.receive(identity());self.receive(info())
            self.assertEqual(self.receive(roster(entries),legacy)[0],0)
            self.assertEqual(self.receive(info(level=81))[0],0)
    def test_level_class_updates_use_update_and_server_row_takes_precedence(self):
        self.receive(identity());self.receive(roster([],clan=77),1);self.receive(info())
        self.assertEqual(self.receive(info(level=81,klass=89))[1],member(0x54,81,89))
        self.receive(member(0x54,82,90))
        self.assertEqual(self.receive(info(level=83))[0],0)
    def test_removal_leave_new_character_and_mismatched_identity(self):
        for event in [b'\x56'+s('Self'),b'\x82',identity('Other',300)]:
            self.setUp();self.receive(identity());self.receive(roster([]),1);self.receive(info())
            self.receive(event);self.assertEqual(self.receive(info())[0],0)
        self.setUp();self.receive(identity());self.receive(roster([]),1)
        self.assertEqual(self.receive(info('Other',100))[0],0)
        self.assertEqual(self.receive(info('Self',200))[0],0)
    def test_truncated_roster_and_prefix_never_create_member(self):
        self.receive(identity());p=roster([('Friend',200)])
        for n in range(1,len(p)):self.assertEqual(self.receive(p[:n],1)[0],0)
        self.assertEqual(self.receive(info())[0],0)
        self.setUp();self.receive(identity());self.receive(p,1)
        q=info();prefix=21+len(s('Self'))+16
        for n in range(1,prefix):self.assertEqual(self.receive(q[:n])[0],0)
        self.assertEqual(self.receive(q)[1],member())
    def test_capacity_failure_retries_without_marking_row_present(self):
        self.receive(identity());self.receive(roster([]),1)
        self.assertEqual(self.receive(info(),cap=len(member())-1)[0],-2)
        self.assertEqual(self.receive(info())[1],member())
        self.assertEqual(self.receive(info(level=81),cap=len(member(0x54))-1)[0],-2)
        self.assertEqual(self.receive(info(level=81))[1],member(0x54,81))

if __name__=='__main__':unittest.main()
