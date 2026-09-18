"""C4 member permissions: state, local HTML and exact outbound wire contracts."""
import ctypes as C
import re
import struct
import unittest
from test_cpp_core import ROOT
from test_structured_codec import d,s

class Result(C.Structure):
    _fields_=[('server_size',C.c_uint32),('display_size',C.c_uint32),
              ('server',C.c_ubyte*41),('display',C.c_ubyte*8190),
              ('local_size',C.c_uint32),('local',C.c_ubyte*160)]

def member_info(name):
    # Interlude PledgeReceiveMemberInfo FE:3D dSSdSS with neutral C4 values.
    return b'\xfe\x3d\x00'+d(0)+s(name)+s('')+d(0)+s('')+s('')

def roster(members,leader='Leader',clan=77):
    return (b'\x53'+d(0,clan,0)+s('Clan')+s(leader)+d(*([0]*9))+s('Ally')+d(0,0,len(members))
            +b''.join(s(name)+d(80,88,0,1,oid,0) for name,oid in members))

class PledgeBridgeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.lib=C.CDLL(str(ROOT/'build/libl2k_protocol.dylib'))
        cls.lib.l2k_pledge_state_size.restype=C.c_uint32
        for name in ['l2k_pledge_receive','l2k_pledge_send']:
            f=getattr(cls.lib,name);f.argtypes=[C.c_void_p,C.c_void_p,C.c_uint32,C.c_uint32,C.POINTER(Result)];f.restype=C.c_int
        cls.lib.l2k_pledge_reset.argtypes=[C.c_void_p]
    def setUp(self):
        self.state=C.create_string_buffer(self.lib.l2k_pledge_state_size())
        self.lib.l2k_pledge_reset(self.state);self.now=1000;self.html='';self.wire=b''
    def call(self,p,receive=False):
        out=Result();f=self.lib.l2k_pledge_receive if receive else self.lib.l2k_pledge_send
        result=f(self.state,p,len(p),self.now,C.byref(out))
        self.wire=bytes(out.server[:out.server_size]);display=bytes(out.display[:out.display_size])
        self.local=bytes(out.local[:out.local_size])
        if display:
            self.assertLessEqual(len(display),8190);self.assertEqual(display[:5],b'\x0f'+d(0));self.assertEqual(display[-6:],bytes(6))
            self.html=display[5:-6].decode('utf-16le');self.assertTrue(self.html.endswith('</body></html>'))
        return result,display
    def setup_clan(self,name='Leader',members=None):
        self.call(b'\x15'+s(name)+d(100),True)
        self.call(roster(members or [('Member',200),('Offline',0)]),True)
    def request(self,name='Member'):
        return self.call(b'\xd0\x1b\0'+d(0)+s(name))
    def click(self,action,arg=0):
        command=re.search(r'l2k_priv_\d+_'+action+'_'+str(arg)+r'(?=")',self.html)
        self.assertIsNotNone(command,(action,arg,self.html))
        return self.call(b'\x21'+s(command[0]))
    def response(self,rights):
        return self.call(b'\x30'+d(0,0)+rights,True)
    def test_leader_reads_toggles_and_explicitly_applies_exact_c4_bitset(self):
        self.setup_clan();self.request();self.assertEqual(self.wire,b'\xc0'+d(200,2))
        rights=bytes(range(32));self.response(rights);self.assertEqual(self.wire,b'')
        self.click('T',10);self.assertEqual(self.wire,b'')
        self.click('T',0);self.assertEqual(self.wire,b'')
        self.click('A');wanted=bytearray(rights);wanted[1]^=4;wanted[0]^=1
        self.assertEqual(self.wire,b'\xc0'+d(200,3)+wanted)
        self.assertIn('Pedido enviado',self.html);self.assertNotIn('_A_',self.html)
        self.click('R');self.assertEqual(self.wire,b'\xc0'+d(200,2))
        self.response(bytes(wanted));self.click('A');self.assertEqual(self.wire,b'')
    def test_self_permissions_use_world_id_and_invalidate_old_selection(self):
        from test_clan_self import info
        self.setup_clan('Self');self.call(info(oid=777),True)
        self.request('Self');self.assertEqual(self.wire,b'\xc0'+d(777,1))
        self.call(info(oid=888),True)
        result,display=self.response(bytes(32));self.assertEqual(display,b'')
        self.request('Self');self.assertEqual(self.wire,b'\xc0'+d(888,1))
        self.call(info('Other',999),True)
        self.response(bytes(32));self.request('Self');self.assertEqual(self.wire,b'\xc0'+d(888,1))

    def test_member_info_request_is_answered_locally_for_known_names(self):
        self.setup_clan('Leader',[('Member',200),('Offline',0)])
        for name in ['Member','Offline','Leader']:
            self.assertEqual(self.call(b'\xd0\x1d\0'+d(0)+s(name))[0],1)
            self.assertEqual(self.wire,b'');self.assertEqual(self.local,member_info(name));self.assertEqual(self.html,'')
        self.call(b'\x54'+s('Joined')+d(80,88,0,1,300,0,0),True)
        self.assertEqual(self.call(b'\xd0\x1d\0'+d(0)+s('Joined'))[0],1);self.assertEqual(self.local,member_info('Joined'))
        self.call(b'\x56'+s('Member'),True)
        self.assertEqual(self.call(b'\xd0\x1d\0'+d(0)+s('Member'))[0],0);self.assertEqual(self.local,b'')
    def test_member_info_for_unknown_names_subpledges_or_bad_layout_keeps_fallback_policy(self):
        self.setup_clan()
        request=b'\xd0\x1d\0'+d(0)+s('Member')
        for p in [b'\xd0\x1d\0'+d(0)+s('Stranger'),b'\xd0\x1d\0'+d(100)+s('Member'),b'\xd0\x1d\0'+d(0)+s('member'),request+b'\0',b'\xd0\x1d\1'+d(0)+s('Member')]+[request[:n] for n in range(3,len(request))]:
            self.assertEqual(self.call(p)[0],0,p);self.assertEqual(self.local,b'');self.assertEqual(self.wire,b'')
        self.setUp();self.assertEqual(self.call(request)[0],0)
        self.call(b'\x15'+s('Solo')+d(100),True)
        self.assertEqual(self.call(b'\xd0\x1d\0'+d(0)+s('Solo'))[0],1);self.assertEqual(self.local,member_info('Solo'))
    def test_member_info_uses_longest_name_and_never_touches_permission_state(self):
        long=chr(0x41)*63;self.setup_clan('Leader',[(long,200)])
        self.request(long);self.assertEqual(self.wire,b'\xc0'+d(200,2))
        self.assertEqual(self.call(b'\xd0\x1d\0'+d(0)+s(long))[0],1);self.assertEqual(self.local,member_info(long))
        self.assertEqual(len(self.local),3+4+128+2+4+2+2)
        self.response(bytes(32));self.assertIn('Dar titulo',self.html)
    def test_nonleader_can_read_self_but_not_edit_another_member(self):
        self.setup_clan('Other');self.request();self.assertEqual(self.wire,b'');self.assertIn('Somente o lider',self.html)
        self.request('Other');self.assertEqual(self.wire,b'\xc0'+d(100,1))
        self.response(bytes(32));self.assertNotIn('_A_',self.html);self.assertNotIn('_T_',self.html)
    def test_rank_requests_open_member_editor_without_sending_rank_to_c4(self):
        self.setup_clan()
        for p in [b'\xd0\x1a\0',b'\xc0'+d(3,1),b'\xc0'+d(3,2,0xffffffff)]:
            self.assertEqual(self.call(p)[0],1);self.assertEqual(self.wire,b'');self.assertIn('Selecione um membro',self.html)
        self.click('V',0);self.assertEqual(self.wire,b'\xc0'+d(200,2))
    def test_only_one_uncorrelated_query_even_after_timeout(self):
        self.setup_clan(members=[('Member',200),('Another',300)])
        self.request();self.now+=60000;self.request('Another');self.assertEqual(self.wire,b'')
        self.response(bytes(32));self.assertIn('Member',self.html);self.assertNotIn('Another',self.html)
        self.request('Another');self.assertEqual(self.wire,b'\xc0'+d(300,2))
    def test_offline_delete_roster_and_world_switch_invalidate_old_buttons(self):
        for event in [b'\x54'+s('Member')+d(80,88,0,1,0,0,0),b'\x56'+s('Member'),b'\x82',roster([('Other',300)]),b'\x15'+s('Other')+d(400)]:
            with self.subTest(event=event[0]):
                self.setUp();self.setup_clan();self.request();self.response(bytes(32))
                self.click('T',0);old=re.search(r'l2k_priv_\d+_A_0',self.html)[0]
                self.call(event,True);self.call(b'\x21'+s(old));self.assertEqual(self.wire,b'')
    def test_late_response_after_roster_change_cannot_edit_a_new_target(self):
        self.setup_clan();self.request();self.call(roster([('Another',300)]),True)
        self.request('Another');self.assertEqual(self.wire,b'')
        result,display=self.response(bytes([255])*32);self.assertEqual(result,1);self.assertEqual(display,b'')
        self.request('Another');self.assertEqual(self.wire,b'\xc0'+d(300,2))
    def test_html_escapes_names_and_paginates_worst_case_names(self):
        names=[('<&"\''*15+str(i),i+200) for i in range(12)]
        self.setup_clan(members=names);self.call(b'\xd0\x1a\0')
        self.assertIn('&lt;&amp;&quot;&#39;',self.html);self.assertNotIn('<&',self.html)
        self.click('L',1);self.assertIn('Anterior',self.html)
        self.click('V',6);self.assertEqual(self.wire,b'\xc0'+d(206,2))
    def test_malformed_stale_and_unrelated_requests_never_leak_local_commands(self):
        self.setup_clan();self.call(b'\xd0\x1a\0')
        for command in ['l2k_priv_0_A_0','l2k_priv_42949672960_A_0','l2k_priv_1_A_0junk','l2k_priv_1_T_999']:
            self.assertEqual(self.call(b'\x21'+s(command))[0],1);self.assertEqual(self.wire,b'')
        for packet in [b'\x21'+s('npc_123_Chat 0'),b'\x38chat',b'\xd0\x19\0']:
            self.assertEqual(self.call(packet)[0],0)
        self.assertEqual(self.call(b'\x30'+d(1,2,3),True)[0],0)
        self.assertEqual(self.response(bytes(32))[0],1)
        self.call(b'\xd0\x1a\0');command=re.search(r'l2k_priv_\d+_V_0',self.html)[0]
        self.call(b'\x21'+s('-h '+command));self.assertEqual(self.wire,b'\xc0'+d(200,2))
    def test_truncated_rosters_cannot_replace_valid_member_context(self):
        self.setup_clan();packet=roster([('Another',300)])
        for n in range(1,len(packet)):self.call(packet[:n],True)
        self.request();self.assertEqual(self.wire,b'\xc0'+d(200,2))
