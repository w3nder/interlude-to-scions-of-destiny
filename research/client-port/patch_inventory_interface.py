"""Separate C4 tattoos in the original Interlude InventoryWnd script."""
import argparse
import hashlib
import json
import os
import struct
from datetime import datetime
from pathlib import Path

from inventory_bytecode import Reader, Parser
from unreal_package_index import Package

ROOT = Path(__file__).resolve().parent
BASE = ROOT.parent.parent / 'base/C6_System_Win10Supported'
ORIGINAL = '4ca40e2936138d9551412767c695b6e54e8f2843daf437536811705704b91019'
XDAT = 'ee755d9865e548398d822493b9536a40b3f7483108b582723d89b03eeb803c55'
NWINDOW = 'cb85f7a5de375f1e9156ec6559aae2a0a809b3abac4150142aafb14bbf02b47b'
OLD_NWINDOW = 'c4be7ace2ab15652d919c7f1dac99e223d963c2528aa6638c8aaa2629f66f678'
FUNCTION = 'InventoryWnd.EquipItemUpdate'


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def compact(v):
    if v < 0:
        raise ValueError('Negative export offset/size')
    out = bytearray([v & 63]); v >>= 6
    if v:
        out[0] |= 64
    while v:
        b = v & 127; v >>= 7
        out.append(b | (128 if v else 0))
    return out


def parse_function(raw):
    r = Reader(raw)
    for _ in range(7):
        r.compact()
    r.num(4); r.num(4)
    size = r.num(4)
    p = Parser(raw[r.p:])
    tops = p.script(size)
    return r.p, size, p, tops


def constant(node):
    if node['op'] == 0x25:
        return 0
    if node['op'] == 0x26:
        return 1
    if node['op'] in (0x1d, 0x24, 0x2c):
        return node['value']
    raise ValueError('Not an integer constant')


def assignment(tops, mask):
    for i, node in enumerate(tops):
        if node['op'] == 10 and node['children'] and constant(node['children'][0]) == mask:
            let = tops[i + 1]
            if let['op'] != 0x0f or let['children'][1]['op'] != 0x1a:
                raise ValueError('Unexpected inventory case body')
            return let['children'][1]['children'][0]
    raise ValueError('Missing inventory case')


def replace_function(raw):
    start, size, parser, tops = parse_function(raw)
    index = assignment(tops, 1)
    if index['op'] != 0x25 or constant(assignment(tops, 8192)) != 0:
        raise ValueError('Tattoo branches differ from the audited function')
    script = bytearray(raw[start:start + parser.p])
    boundaries = {t['v'] for t in tops} | {size}
    for node in parser.nodes:
        if 'jump' in node and node['jump'] != 65535:
            if node['op'] not in (6, 7, 10) or node['jump'] not in boundaries:
                raise ValueError('Unverified control-flow target')
            if node['jump'] > index['v']:
                struct.pack_into('<H', script, node['jump_p'], node['jump'] + 1)
        if node['op'] in (0x12, 0x19) and node['v'] < index['v'] < node['vend']:
            raise ValueError('Edit would change an enclosing context skip')
    script[index['p']:index['end']] = b'\x2c\x03'
    prefix = bytearray(raw[:start])
    struct.pack_into('<I', prefix, start - 4, size + 1)
    result = bytes(prefix + script + raw[start + parser.p:])
    _, newsize, after, newtops = parse_function(result)
    if newsize != size + 1 or len(after.nodes) != len(parser.nodes):
        raise ValueError('Script roundtrip failed')
    if constant(assignment(newtops, 1)) != 3 or constant(assignment(newtops, 8192)) != 0:
        raise ValueError('Incorrect tattoo destinations')
    return result


def generate(source, output):
    original = source.read_bytes()
    if sha(original) != ORIGINAL:
        raise ValueError('Unsupported Interface.u')
    package = Package(source)
    decoded = original[package.offset:].translate(package.translate)
    index = next(i for i, e in enumerate(package.exports) if package.object_path(i + 1) == FUNCTION)
    entry = package.exports[index]
    new_function = replace_function(decoded[entry['offset']:entry['offset'] + entry['size']])
    # Append the edited function and a new export table. All other objects keep
    # their original bytes, offsets, names, flags, imports and package GUID.
    r = Reader(decoded)
    r.p = struct.unpack_from('<I', decoded, 24)[0]
    table = bytearray()
    for i in range(len(package.exports)):
        begin = r.p
        r.compact(); r.compact(); r.num(4); r.compact(); r.num(4)
        size_at = r.p
        oldsize = r.compact()
        if oldsize:
            r.compact()
        if i == index:
            table += decoded[begin:size_at] + compact(len(new_function)) + compact(len(decoded))
        else:
            table += decoded[begin:r.p]
    result = bytearray(decoded + new_function + table)
    struct.pack_into('<I', result, 24, len(decoded) + len(new_function))
    encrypted = original[:package.offset] + bytes(result).translate(package.translate)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_bytes(encrypted)
    check = Package(output)
    for i, (a, b) in enumerate(zip(package.exports, check.exports)):
        if i != index and a != b:
            raise ValueError('Unrelated export changed')
    if package.names != check.names or package.imports != check.imports:
        raise ValueError('Package tables changed unexpectedly')
    return dict(build='inventory-script-2', interface_sha256=sha(encrypted),
                original_interface_sha256=ORIGINAL, required_xdat_sha256=XDAT,
                function=FUNCTION, export_index=index + 1,
                left_tattoo=dict(mask=1, control='EquipItem_Hair2', x=92, y=36),
                aio_tattoo=dict(mask=8192, control='EquipItem_Underwear', x=137, y=36),
                dimensions=[34, 34], wire_changes=False, dat_changes=False,
                live_visual_validation='pending', native_slot_patch='withdrawn; original NWindow restored')


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--install', type=Path)
    args = ap.parse_args()
    stage = ROOT / 'build/inventory-script'
    candidate = stage / 'interface.u'
    report = generate(BASE / 'interface.u', candidate)
    native = (BASE / 'NWindow.dll').read_bytes()
    if sha(native) != NWINDOW:
        raise ValueError('Wrong native baseline')
    if args.install:
        system = args.install
        if sha((system / 'interface.xdat').read_bytes()) != XDAT:
            raise ValueError('This update requires the original Interlude interface layout')
        updates = [('interface.u', candidate.read_bytes(), {ORIGINAL, report['interface_sha256']}),
                   ('NWindow.dll', native, {NWINDOW, OLD_NWINDOW})]
        for name, data, allowed in updates:
            if sha((system / name).read_bytes()) not in allowed:
                raise ValueError('Unrecognized installed ' + name)
        backup = system.parent / ('system.before-inventory-script-' + datetime.now().strftime('%Y%m%d-%H%M%S'))
        backup.mkdir()
        originals = {}
        try:
            for name, data, _ in updates:
                dest = system / name
                originals[name] = dest.read_bytes()
                (backup / name).write_bytes(originals[name])
                if (backup / name).read_bytes() != originals[name]:
                    raise ValueError('Backup verification failed')
                temp = system / (name + '.inventory-next')
                with temp.open('xb') as f:
                    f.write(data); f.flush(); os.fsync(f.fileno())
                if temp.read_bytes() != data:
                    raise ValueError('Staging verification failed')
                os.replace(temp, dest)
        except BaseException:
            for name, data in originals.items():
                temp = system / (name + '.inventory-rollback')
                temp.write_bytes(data); os.replace(temp, system / name)
            raise
        report.update(system=str(system), backup=str(backup), activation='next client start')
    (ROOT / 'reports/inventory-script.json').write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report, indent=2))


if __name__ == '__main__':
    main()
