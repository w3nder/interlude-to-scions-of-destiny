"""Extract public Blowfish pi tables and the verified protocol block."""
import hashlib
import re
from pathlib import Path

ROOT=Path(__file__).resolve().parent
source=Path('/Users/wenderteixeira/l2g-client/l2g-backend/internal/netio/blowfish.go').read_text()
out=['// Generated mathematical Blowfish constants; source: l2g-backend/internal/netio/blowfish.go.',
     '// Regenerate with generate_constants.py. No credentials or session keys.']
for name,count in [('p',18),('s0',256),('s1',256),('s2',256),('s3',256)]:
    literal=source.split(f'var {name} = [{count}]uint32{{')[1].split('}')[0]
    values=re.findall(r'0x[0-9a-fA-F]+',literal)
    assert len(values)==count
    out.append(f'static const uint32_t initial_{name}[{count}] = {{'+','.join(values)+'};')
block=(ROOT.parent/'killer-protocol-block.bin').read_bytes()
assert hashlib.sha256(block).hexdigest()=='df28882658a7f6fedc9b8b8e70b41e8b02eae264fae0970b15def91cbfc3cd79'
out.append('static const uint8_t protocol_block[256] = {'+','.join(str(b) for b in block)+'};')
(ROOT/'constants.inc').write_text('\n'.join(out)+'\n')
