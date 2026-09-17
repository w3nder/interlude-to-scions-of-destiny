import hashlib
import struct
import unittest
from pathlib import Path

from handshake_codec import interlude_protocol_version_to_killer, frame

ROOT = Path(__file__).resolve().parent


class ProtocolVersionTests(unittest.TestCase):
    def setUp(self):
        self.source_block = (ROOT / 'killer-protocol-block.bin').read_bytes()
        self.target_block = (ROOT / 'interlude-protocol-block.bin').read_bytes()

    def test_independently_extracted_blocks_match_backend(self):
        self.assertEqual(len(self.source_block), 256)
        self.assertEqual(self.source_block, self.target_block)
        self.assertEqual(hashlib.sha256(self.source_block).hexdigest(),
                         'df28882658a7f6fedc9b8b8e70b41e8b02eae264fae0970b15def91cbfc3cd79')

    def test_converted_frame_matches_c4_layout(self):
        # Synthetic trailing value makes accidental retention visible.
        incoming = b'\x00' + struct.pack('<I', 746) + self.target_block + bytes.fromhex('78563412')
        expected = bytes.fromhex('07010090020000') + self.source_block
        result = frame(interlude_protocol_version_to_killer(incoming))
        self.assertEqual(result, expected)
        self.assertEqual(len(result), 263)
        self.assertEqual(struct.unpack_from('<H', result)[0], len(result))

    def test_rejects_unknown_packet_shapes(self):
        valid = b'\x00' + struct.pack('<I', 746) + self.target_block + bytes(4)
        cases = [valid[:-1], valid+bytes(1), b'\x01'+valid[1:],
                 b'\x00'+struct.pack('<I', 656)+valid[5:],
                 valid[:5]+bytes([valid[5]^1])+valid[6:]]
        for payload in cases:
            with self.subTest(length=len(payload), prefix=payload[:6].hex()):
                with self.assertRaises(ValueError):
                    interlude_protocol_version_to_killer(payload)

    def test_frame_rejects_empty_and_overflow(self):
        for payload in [b'', bytes(65534)]:
            with self.assertRaises(ValueError):
                frame(payload)


if __name__ == '__main__':
    unittest.main()
