"""Offline per-game-socket C4 transport model for a future native adapter.

No networking, credentials, login-server Blowfish or installation hooks here.
Application packet conversion remains a separate stage.
"""
from dataclasses import dataclass
import struct

from handshake_codec import frame, interlude_protocol_version_to_killer


class ProtocolError(ValueError):
    pass


@dataclass(frozen=True)
class C4KeyPacket:
    status: int
    seed: int
    cipher_enabled: int
    extra: int

    @classmethod
    def parse(cls, payload):
        # Opcode + the native handler's cddd segment. A short bot packet is
        # not evidence that missing fields are safe for the graphical client.
        if len(payload) != 14 or payload[0] != 0:
            raise ProtocolError('Expected exact C4 key response: opcode + cddd (14 bytes)')
        return cls(*struct.unpack('<BIII', payload[1:]))

    def native_key(self):
        # C4 handler uses CDQ then OR, including sign extension of the seed.
        high = 0xFFFFFFFF if self.seed & 0x80000000 else 0x87546CA1
        return struct.pack('<II', self.seed, high)


class C4Cipher:
    def __init__(self, key):
        if len(key) != 8:
            raise ProtocolError('C4 requires an 8-byte key')
        self._key = bytes(key)

    @property
    def key(self):
        return self._key

    def _transform(self, payload, decrypt):
        if not payload:
            raise ProtocolError('Empty game payload')
        result = bytearray(len(payload))
        previous = 0
        for i, value in enumerate(payload):
            result[i] = value ^ self._key[i & 7] ^ previous
            previous = value if decrypt else result[i]
        # Verified ADD/ADC in both native C4 functions, not the bot's u32 wrap.
        value = (int.from_bytes(self._key, 'little') + len(payload)) & 0xFFFFFFFFFFFFFFFF
        self._key = value.to_bytes(8, 'little')
        return bytes(result)

    def encrypt(self, payload):
        return self._transform(payload, False)

    def decrypt(self, payload):
        return self._transform(payload, True)


class FrameDecoder:
    def __init__(self):
        self.buffer = bytearray()

    def feed(self, chunk):
        self.buffer.extend(chunk)
        result = []
        while len(self.buffer) >= 2:
            size = int.from_bytes(self.buffer[:2], 'little')
            if size < 3:
                self.buffer.clear()
                raise ProtocolError('Invalid frame size: no opcode payload')
            if len(self.buffer) < size:
                break
            result.append(bytes(self.buffer[2:size]))
            del self.buffer[:size]
        return result

    def finish(self):
        if self.buffer:
            raise ProtocolError('EOF inside a game frame')


@dataclass(frozen=True)
class Received:
    kind: str
    payload: bytes
    key_packet: C4KeyPacket | None = None


class C4GameSocket:
    """One independent session. Callers must serialize access to this object."""
    def __init__(self):
        self.phase = 'new'
        self.decoder = FrameDecoder()
        self.tx = None
        self.rx = None

    def protocol_version(self, interlude_payload):
        if self.phase != 'new':
            raise ProtocolError('ProtocolVersion is only allowed on a new game socket')
        converted = interlude_protocol_version_to_killer(interlude_payload)
        self.phase = 'waiting_key'
        return frame(converted)

    def receive(self, chunk):
        if self.phase not in ('waiting_key', 'ready'):
            raise ProtocolError('Unexpected data for this socket phase')
        events = []
        try:
            for payload in self.decoder.feed(chunk):
                if self.phase == 'waiting_key':
                    packet = C4KeyPacket.parse(payload)
                    # This profile supports the successful encrypted path only.
                    # Refusal and alternative enable modes must not silently
                    # initialize a cipher and appear to be successful.
                    if packet.status != 1 or packet.cipher_enabled != 1:
                        raise ProtocolError('Unsupported/refused key negotiation')
                    self.tx = C4Cipher(packet.native_key())
                    self.rx = C4Cipher(packet.native_key())
                    self.phase = 'ready'
                    events.append(Received('key', payload, packet))
                else:
                    events.append(Received('payload', self.rx.decrypt(payload)))
        except (ValueError, struct.error):
            self.phase = 'failed'
            self.tx = self.rx = None
            raise
        return events

    def send(self, c4_plaintext_payload):
        if self.phase != 'ready':
            raise ProtocolError('Game cipher is not ready')
        # Validate framing bounds before mutating the cipher state.
        if not 1 <= len(c4_plaintext_payload) <= 65533:
            raise ProtocolError('Invalid payload length')
        return frame(self.tx.encrypt(c4_plaintext_payload))

    def close(self):
        try:
            self.decoder.finish()
        finally:
            self.phase = 'closed'
            self.tx = self.rx = None
