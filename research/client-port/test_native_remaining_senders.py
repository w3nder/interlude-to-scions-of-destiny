"""Remaining C4 native sender families: login fields, world signal and boats."""
import hashlib
import json
import struct
import unittest
from native_emitter_audit import NativeEmitter, ROOT, PROFILES


def d(*v):return struct.pack('<'+'I'*len(v),*v)
def floats(*v):return list(struct.unpack('<'+'I'*len(v),struct.pack('<'+'f'*len(v),*v)))


class RemainingSenderTests(unittest.TestCase):
    def test_native_login_fields_and_fixed_world_signal(self):
        reports=[]
        for side in PROFILES:
            e=NativeEmitter(side)
            def put_image(address,value):
                e._map_image(e.u,0,address,4,0,None);e.put(address,value)
            session = 0x109d786c if side=='source' else 0x10b20f34
            network = 0x109d5e68 if side=='source' else 0x10b1f538
            game = 0x10b36bb4 if side=='source' else 0x10c51044
            put_image(network,e.DATA)
            put_image(game,e.DATA+0x10000)
            fields={0x4c:e.DATA+0x1000,0xe4:0x12345678}
            for a,b in [(0,0),(1,0xffffffff),(0x12345678,0x89abcdef)]:
                put_image(session,a);put_image(session+4,b)
                result=e.run(0x103f4660 if side=='source' else 0x10403a50,[],direct_arguments=[],object_fields=fields)
                self.assertEqual(result['wire'],b'\x05'+d(a,b)+b'\x04')
                for server in [1,7,255]:
                    result=e.run(0x103f46e0 if side=='source' else 0x10403ab0,[server,111,222],object_fields=fields)
                    self.assertEqual(result['wire'],b'\x02'+d(a,b)+bytes([server]))
            game_data=bytearray(0x400);off=0x360 if side=='source' else 0x36c
            game_data[off:off+16]=d(0,1,0x7fffffff,0xffffffff)
            result=e.run(0x103f41f0 if side=='source' else 0x10403720,[],{0x10000:bytes(game_data)},direct_arguments=[],object_fields=fields)
            self.assertEqual(result['wire'],b'\x07'+d(0x12345678,0,1,0x7fffffff,0xffffffff))

            # Run the unmodified send suffix after supplying the saved this
            # register normally established by the UI/allocation prefix. That
            # prefix's behavior is deliberately not emulated or changed.
            entry=e.STOP+0x400;tail=0x10420d6b if side=='source' else 0x1043276b
            saved_this=b'\x89\xcb' if side=='source' else b'\x89\xcd'
            e.u.mem_write(entry,saved_this+b'\xe9'+struct.pack('<i',tail-(entry+7)))
            result=e.run(entry,[],direct_arguments=[])
            self.assertEqual(result['wire'],b'\x03'+'narcasse\0'.encode('utf-16le'))
            reports.append({'side':side,'sha256':PROFILES[side]['sha256'],'server_list_vectors':3,'server_login_vectors':9,
                            'auth_challenge_vectors':1,'world_signal_send_suffix':hashlib.sha256(result['wire']).hexdigest()})
        (ROOT/'reports/native-login-senders.json').write_text(json.dumps({'status':'passed','results':reports,
            'scope':'Original sender fields and serializers with synthetic session/challenge values. EnterWorld fixed send suffix only; no login/world path rewrite and no network connection.'},indent=2)+'\n')

    def test_move_to_location_non_vehicle_and_vehicle_branches(self):
        engines={side:NativeEmitter(side) for side in PROFILES}
        cases=[]
        for side,e in engines.items():
            e.bind_core_import(b'?RotateAngleAxis@FVector@@QBE?AV1@HABV1@@Z')
            table=0x101e29dc if side=='source' else 0x1023ffd4
            # Explicit cardinal sine table entries are fixture environment,
            # not replacements for the native rotation or coordinate sender.
            for index,value in [(0,0.),(4096,1.),(8192,0.),(12288,-1.)]:
                address=table+index*4;e._map_image(e.u,0,address,4,0,None);e.u.mem_write(address,struct.pack('<f',value))
        for xyz in [(1.75,-2.75,.99),(123456.5,-65432.25,777.75),(-9.,-8.,-7.)]:
            origin=(10.5,20.25,30.75)
            for flag in [0,1]:
                outputs=[]
                for side,e in engines.items():
                    actor=bytearray(0x100)
                    result=e.run(0x10410da0 if side=='source' else 0x104220f0,[],{0x10000:bytes(actor)},
                                 direct_arguments=[e.DATA+0x10000]+floats(*xyz)+floats(*origin)+[0,flag])
                    expected=b'\x01'+struct.pack('<6i',*(int(v) for v in xyz+origin))+d(int(flag==0))
                    self.assertEqual(result['wire'],expected);outputs.append(result['wire'])
                self.assertEqual(*outputs);cases.append({'vehicle':False,'flag':flag,'sha256':hashlib.sha256(outputs[0]).hexdigest()})
            for heading in [0,16384,32768,49152]:
                for flag in [0,1]:
                    outputs=[];stops=[]
                    for side,e in engines.items():
                        boat=bytearray(0x300);actor=bytearray(0x100)
                        boat[0x24:0x28]=d(0x10b12668 if side=='source' else 0x10c2b8e8)
                        boat[0x60:0x64]=d(777);boat[0x1bc:0x1c8]=struct.pack('<fff',100.,-50.,10.)
                        boat[0x1cc:0x1d0]=d(heading);actor[0x40:0x44]=d(e.DATA+0x11000)
                        blobs={0x10000:bytes(actor),0x11000:bytes(boat)}
                        result=e.run(0x10410da0 if side=='source' else 0x104220f0,[],blobs,
                                     direct_arguments=[e.DATA+0x10000]+floats(*xyz)+floats(*origin)+[e.DATA+0x11000,flag])
                        self.assertEqual(result['wire'][:5],b'\x5c'+d(777));self.assertEqual(len(result['wire']),29);outputs.append(result['wire'])
                        stop=e.run(0x104110e0 if side=='source' else 0x104223f0,[],blobs,
                                   direct_arguments=[e.DATA+0x10000]+floats(*xyz)+[123,flag])
                        self.assertEqual(stop['wire'][:5],b'\x5d'+d(777));self.assertEqual(len(stop['wire']),21);stops.append(stop['wire'])
                    self.assertEqual(*outputs);self.assertEqual(*stops)
                    cases.append({'vehicle':True,'heading':heading,'flag':flag,'move_sha256':hashlib.sha256(outputs[0]).hexdigest(),'stop_sha256':hashlib.sha256(stops[0]).hexdigest()})
        (ROOT/'reports/native-vehicle-senders.json').write_text(json.dumps({'status':'passed','hashes':{s:p['sha256'] for s,p in PROFILES.items()},
            'scope':'Native branch selection, class check, position subtraction, Core RotateAngleAxis and serialization; cardinal GMath table entries supplied as fixture state. No network connection.',
            'limits':'Finite cardinal rotations; native global sine-table initialization is outside this test.', 'cases':cases},indent=2)+'\n')
