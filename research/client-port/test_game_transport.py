import struct
import unittest
from pathlib import Path

from game_transport import C4Cipher, C4GameSocket, C4KeyPacket, FrameDecoder, ProtocolError
from handshake_codec import frame

BLOCK = (Path(__file__).resolve().parent/'interlude-protocol-block.bin').read_bytes()
VERSION = b'\0'+struct.pack('<I',746)+BLOCK+bytes(4)


def key_payload(seed=0x12345678, status=1, enabled=1):
    return b'\0'+struct.pack('<BIII',status,seed,enabled,0)


class GameTransportTests(unittest.TestCase):
    def test_native_seed_sign_extension(self):
        self.assertEqual(C4KeyPacket.parse(key_payload()).native_key().hex(),'78563412a16c5487')
        self.assertEqual(C4KeyPacket.parse(key_payload(0xFEDCBA98)).native_key().hex(),'98badcfeffffffff')

    def test_fragmented_key_and_coalesced_encrypted_packets(self):
        socket=C4GameSocket()
        self.assertEqual(len(socket.protocol_version(VERSION)),263)
        peer=C4Cipher(C4KeyPacket.parse(key_payload()).native_key())
        wire=frame(key_payload())+frame(peer.encrypt(b'\x13one'))+frame(peer.encrypt(b'\x15two'))
        events=[]
        for byte in wire:
            events.extend(socket.receive(bytes([byte])))
        self.assertEqual([e.kind for e in events],['key','payload','payload'])
        self.assertEqual([e.payload for e in events[1:]],[b'\x13one',b'\x15two'])
        other=C4GameSocket();other.protocol_version(VERSION)
        self.assertEqual(other.receive(wire),events)

    def test_tx_rx_and_sockets_are_independent(self):
        a,b=C4GameSocket(),C4GameSocket()
        for socket in (a,b):
            socket.protocol_version(VERSION);socket.receive(frame(key_payload()))
        initial=a.rx.key
        a.send(b'\x08synthetic-auth')
        self.assertEqual(a.rx.key,initial)
        self.assertEqual(b.tx.key,initial)
        self.assertNotEqual(a.tx.key,initial)

    def test_key_carry_updates_high_word(self):
        cipher=C4Cipher(bytes.fromhex('feffffffa16c5487'))
        cipher.encrypt(b'1234')
        self.assertEqual(cipher.key.hex(),'02000000a26c5487')
        cipher=C4Cipher(bytes.fromhex('feffffffffffffff'))
        cipher.encrypt(b'1234')
        self.assertEqual(cipher.key.hex(),'0200000000000000')

    def test_phase_and_malformed_negotiation(self):
        socket=C4GameSocket()
        with self.assertRaises(ProtocolError):socket.send(b'\x08')
        socket.protocol_version(VERSION)
        with self.assertRaises(ProtocolError):socket.protocol_version(VERSION)
        for body in (key_payload()[:-1],key_payload()+b'\0',key_payload(status=0),key_payload(enabled=0)):
            socket=C4GameSocket();socket.protocol_version(VERSION)
            with self.assertRaises(ProtocolError):socket.receive(frame(body))
            self.assertEqual(socket.phase,'failed')
            self.assertIsNone(socket.tx)

    def test_framing_errors_and_eof(self):
        for size in (0,1,2):
            with self.assertRaises(ProtocolError):FrameDecoder().feed(struct.pack('<H',size))
        socket=C4GameSocket();socket.protocol_version(VERSION)
        socket.receive(b'\x10')
        with self.assertRaises(ProtocolError):socket.close()
        self.assertEqual(socket.phase,'closed')

    def test_invalid_send_does_not_advance_key(self):
        socket=C4GameSocket();socket.protocol_version(VERSION);socket.receive(frame(key_payload()))
        key=socket.tx.key
        for payload in (b'',bytes(65534)):
            with self.assertRaises(ProtocolError):socket.send(payload)
            self.assertEqual(socket.tx.key,key)


if __name__=='__main__':unittest.main()
