"""Reproduce handshake constants from the fingerprinted engines and backend."""
import hashlib
import json
import re
from pathlib import Path

from extract_protocol import Extractor
from handshake_codec import frame

ROOT = Path(__file__).resolve().parent
BACKEND = Path('/Users/wenderteixeira/l2g-client/l2g-backend')
BUILDS = {
    'killer': dict(path=ROOT.parents[1] / 'system/engine.dll',
        sha256='17a8bcacd57d071a3420d278a7570ddf2a13abba2f6d4336bb4eb48afd4e244b',
        block=0x107bc6e8, mask=0x107bc7ec, revision=0x107bcf08,
        version_format=0x107bcf04, key_format=0x107bd8cc, auth_format=0x107c12b0),
    'interlude': dict(path=Path('/Users/wenderteixeira/Desktop/system-1/engine.dll'),
        sha256='508974c711f207402719e92737e211a2f029c95c2f68fc0e1c31fcbb9dbb232d',
        block=0x1087e5e8, mask=0x1087e6ec, revision=0x1087f1f4,
        version_format=0x1087f1ec, key_format=0x108840f8, auth_format=0x108840b8),
}


def main():
    protocol_source = BACKEND / 'internal/protocol/packets/client/protocolversion.go'
    literal = protocol_source.read_text().split('var clientBlock = [256]byte{')[1].split('}')[0]
    bot_block = bytes(int(v,16) for v in re.findall(r'0x([a-fA-F0-9]+)',literal))
    assert len(bot_block) == 256
    login_source = BACKEND / 'internal/login/client.go'
    literal = login_source.read_text().split('var blowfishKey = []byte{')[1].split('}')[0]
    login_key = bytes(int(v,16) for v in re.findall(r'0x([a-fA-F0-9]+)',literal))
    output = {'backend': str(BACKEND), 'scope': 'Offline static evidence, no login attempted', 'builds': {}}
    for name, config in BUILDS.items():
        binary = Extractor(config['path'])
        digest = hashlib.sha256(binary.raw).hexdigest()
        if digest != config['sha256']:
            raise ValueError(f'{name}: unexpected engine hash')
        cstr = lambda address: binary.data(address,1024).split(b'\0',1)[0]
        raw, mask = cstr(config['block']), cstr(config['mask'])
        block = bytes(value ^ mask[i % len(mask)] for i,value in enumerate(raw))
        assert block == bot_block
        key_offset = binary.raw.find(login_key)
        assert key_offset >= 0
        (ROOT / f'{name}-protocol-block.bin').write_bytes(block)
        output['builds'][name] = dict(binary=str(config['path']), sha256=digest,
            revision=cstr(config['revision']).decode(),
            version_format=cstr(config['version_format']).decode(),
            key_response_format=cstr(config['key_format']).decode(),
            game_auth_format=cstr(config['auth_format']).decode(),
            block_sha256=hashlib.sha256(block).hexdigest(), block_matches_backend=True,
            login_static_key_found_va=hex(binary.base+binary.pe.get_rva_from_offset(key_offset)))
    (ROOT / 'killer-protocol-version.frame.bin').write_bytes(frame(b'\x00\x90\x02\x00\x00'+bot_block))
    output['backend_source_sha256'] = {str(path.relative_to(BACKEND)):hashlib.sha256(path.read_bytes()).hexdigest()
        for path in [protocol_source, login_source, BACKEND/'internal/login/packets.go',
                     BACKEND/'internal/netio/crypt.go',BACKEND/'internal/netio/blowfish.go',
                     BACKEND/'internal/session/session.go']}
    (ROOT / 'handshake-evidence.json').write_text(json.dumps(output,indent=2)+'\n')
    print(json.dumps(output['builds'],indent=2))


if __name__ == '__main__':
    main()
