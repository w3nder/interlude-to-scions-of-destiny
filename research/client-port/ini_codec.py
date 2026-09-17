"""Ver413 codec. Format reference: ritsuwastaken/open-l2encdec src/rsa.cpp."""
import struct
import zlib
HEADER='Lineage2Ver413'.encode('utf-16le')
MOD=int('75b4d6de5c016544068a1acf125869f43d2e09fc55b8b1e289556daf9b8757635593446288b3653da1ce91c87bb1a5c18f16323495c55d7d72c0890a83f69bfd1fd9434eb1c02f3e4679edfa43309319070129c267c85604d87bb65bae205de3707af1d2108881abb567c3b3d069ae67c3a4c6a3aa93d26413d4c66094ae2039',16)
ENC=int('30b4c2d798d47086145c75063c8e841e719776e400291d7838d3e6c4405b504c6a07f8fca27f32b86643d2649d1d5f124cdd0bf272f0909dd7352fe10a77b34d831043d9ae541f8263c6fe3d1c14c2f04e43a7253a6dda9a8c1562cbd493c1b631a1957618ad5dfe5ca28553f746e2fc6f2db816c7db223ec91e955081c1de65',16)
def decode(raw):
    if not raw.startswith(HEADER) or (len(raw)-48)%128: raise ValueError('Unsupported ini format')
    payload=bytearray()
    for i in range(28,len(raw)-20,128):
        block=pow(int.from_bytes(raw[i:i+128],'big'),29,MOD).to_bytes(128,'big')
        n=int.from_bytes(block[:4],'big')
        if not 0<n<=124: raise ValueError('Invalid RSA block')
        offset=128-((n+3)&~3)
        payload.extend(block[offset:offset+n])
    size=struct.unpack_from('<I',payload)[0]
    dec=zlib.decompressobj(); result=dec.decompress(payload[4:])+dec.flush()
    if not dec.eof or dec.unused_data or len(result)!=size: raise ValueError('Incomplete ini')
    return result

def encode(data):
    payload=struct.pack('<I',len(data))+zlib.compress(data)
    out=bytearray(HEADER)
    for i in range(0,len(payload),124):
        chunk=payload[i:i+124]; n=len(chunk); block=bytearray(128); block[3]=n
        offset=128-((n+3)&~3); block[offset:offset+n]=chunk
        out.extend(pow(int.from_bytes(block,'big'),ENC,MOD).to_bytes(128,'big'))
    tail=bytearray(20); struct.pack_into('<I',tail,12,zlib.crc32(out)); return bytes(out+tail)
