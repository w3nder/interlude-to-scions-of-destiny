"""Restore the C4 back/tattoo display slot in the pinned Interlude NWindow.

Only the visual slot returned for mask 0x2000 changes. Item IDs, DAT body_part,
paperdoll arrays and outgoing equip/unequip arguments retain their native values.
The destination is the Interlude second-hair cell; that extra hair mask is not
handled by the original C4 native slot mapper.
"""
import argparse
import hashlib
import json
import os
from datetime import datetime
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


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--install', type=Path, help='Client system directory')
    args = parser.parse_args()
    raw = (ROOT / 'build/target-nwindow.dll').read_bytes()
    result = patch(raw)
    digest = hashlib.sha256(result).hexdigest()
    stage = ROOT / 'build/inventory-slot'
    stage.mkdir(exist_ok=True)
    (stage / 'NWindow.dll').write_bytes(result)
    report = dict(build='inventory-slot-1', original_sha256=ORIGINAL,
                  patched_sha256=digest, changed_bytes=1, branch_rva=hex(RVA),
                  mask=8192, original_visual_slot=19, patched_visual_slot=2,
                  regular_tattoo_visual_slot=3, wire_changes=False,
                  scope='C4 equipment; Interlude-only second-hair items are not supported by this slot reservation',
                  activation='next client process; running process is preserved')
    if args.install:
        destination = args.install / 'NWindow.dll'
        current = destination.read_bytes()
        if current != result:
            if hashlib.sha256(current).hexdigest() != ORIGINAL:
                raise ValueError('Installed NWindow.dll is not the pinned original')
            backup = args.install / ('NWindow.before-inventory-' + datetime.now().strftime('%Y%m%d-%H%M%S') + '.dll')
            with backup.open('xb') as handle:
                handle.write(current)
            if backup.read_bytes() != current:
                raise ValueError('Backup verification failed')
            temporary = args.install / 'NWindow.inventory-next.dll'
            with temporary.open('xb') as handle:
                handle.write(result)
                handle.flush()
                os.fsync(handle.fileno())
            if temporary.read_bytes() != result:
                raise ValueError('Staging verification failed')
            os.replace(temporary, destination)
            report['backup'] = str(backup)
        if destination.read_bytes() != result:
            raise ValueError('Installed file verification failed')
        report['installed'] = str(destination)
    (ROOT / 'reports/inventory-slot.json').write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report, indent=2))


if __name__ == '__main__':
    main()
