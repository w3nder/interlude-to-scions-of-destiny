"""Offline ProtocolVersion converter for the two fingerprinted engine builds.

Input/output are plaintext payloads, without the two-byte TCP frame header.
This is not a socket hook or an implementation of the complete handshake.
"""
import hashlib
import struct

CLIENT_BLOCK_SHA256 = 'df28882658a7f6fedc9b8b8e70b41e8b02eae264fae0970b15def91cbfc3cd79'


def interlude_protocol_version_to_killer(payload):
    if len(payload) != 265:
        raise ValueError('Expected Interlude cdbd payload: 265 bytes')
    if payload[0] != 0 or struct.unpack_from('<I', payload, 1)[0] != 746:
        raise ValueError('Expected opcode 0x00 and Interlude revision 746')
    block = payload[5:261]
    if hashlib.sha256(block).hexdigest() != CLIENT_BLOCK_SHA256:
        raise ValueError('Unknown 256-byte client block')
    # C4 cdb has no slot for the final Interlude dword. Its semantic meaning
    # remains unresolved; dropping it here is limited to this packet shape.
    return b'\x00' + struct.pack('<I', 656) + block


def frame(payload):
    if not payload or len(payload) > 65533:
        raise ValueError('Payload must have 1..65533 bytes')
    return struct.pack('<H', len(payload) + 2) + payload
