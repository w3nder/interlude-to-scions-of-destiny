"""Restore the C4 back/tattoo display slot in the pinned Interlude NWindow.

Only the visual slot returned for mask 0x2000 changes. Item IDs, DAT body_part,
paperdoll arrays and outgoing equip/unequip arguments retain their native values.
The destination is the Interlude second-hair cell; that extra hair mask is not
handled by the original C4 native slot mapper.
"""
import hashlib
from pathlib import Path

import pefile

ROOT = Path(__file__).resolve().parent
ORIGINAL = 'cb85f7a5de375f1e9156ec6559aae2a0a809b3abac4150142aafb14bbf02b47b'
RVA = 0x14e6b6


def patch(raw):
    if hashlib.sha256(raw).hexdigest() != ORIGINAL:
        raise ValueError('Unsupported NWindow.dll; original file preserved')
    pe = pefile.PE(data=raw)
    offset = pe.get_offset_from_rva(RVA)
    if raw[offset:offset + 8] != bytes.fromhex('b8130000005bc208'):
        raise ValueError('Back-slot branch differs from the audited native code')
    output = bytearray(raw)
    output[offset + 1] = 2
    return bytes(output)


if __name__ == '__main__':
    raise SystemExit('Withdrawn native-only adjustment. Use patch_inventory_interface.py for inventory-script-2.')
