"""Merge C4 skill catalogues by ID + level, and verify Interlude roundtrips."""
import hashlib,json,struct
from extract_asset_tables import ROOT,OUT,run_tool,win
from migrate_asset_tables import read,write
from ini_codec import encode,decode
STAGE=ROOT/'build/skills-interlude'
NAMES=['skillname-e','skillgrp','skillsoundgrp','mobskillanimgrp']
def main():
 STAGE.mkdir(exist_ok=True);report=[]
 for name in NAMES:
  sh,srows=read(OUT/f'source-{name}-C4.tsv');th,trows=read(OUT/f'target-{name}-Interlude.tsv')
  if sh!=th:raise ValueError('Explicit schema conversion required: '+name)
  keys=th[:2]
  key=lambda row:tuple(row[k] for k in keys)
  skeys={key(r) for r in srows};tkeys={key(r) for r in trows}
  rows=[r for r in trows if key(r) not in skeys]+srows
  ddf=STAGE/(name+'.ddf');ddf.write_bytes((OUT/f'target-{name}-Interlude.export.ddf').read_bytes())
  txt=STAGE/(name+'.tsv');write(txt,th,rows)
  binary=STAGE/(name+'.decoded')
  if run_tool('l2asm',['-d',win(ddf),win(txt),win(binary)],STAGE/(name+'.assemble.log')):raise ValueError(name+' assembly')
  check=STAGE/(name+'.roundtrip.tsv')
  if run_tool('l2disasm',['-d',win(ddf),'-o','e',win(binary),win(check)],STAGE/(name+'.roundtrip.log')):raise ValueError(name+' disassembly')
  headers,restored=read(check)
  assert headers==th and restored==rows,name+' table roundtrip'
  raw=binary.read_bytes();assert struct.unpack_from('<I',raw)[0]==len(rows)
  encrypted=encode(raw);assert decode(encrypted)==raw
  (STAGE/(name+'.dat')).write_bytes(encrypted)
  report.append(dict(table=name,keys=keys,source_rows=len(srows),original_target_rows=len(trows),merged_rows=len(rows),source_keys_missing_in_target=len(skeys-tkeys),source_duplicate_keys=len(srows)-len(skeys),sha256=hashlib.sha256(encrypted).hexdigest(),validation='All fields/rows identical after Interlude assembly/disassembly and RSA413 roundtrip'))
  print(json.dumps(report[-1]),flush=True)
 (STAGE/'manifest.json').write_text(json.dumps({'tables':report,'policy':'C4 records take precedence by composite key; original C4 duplicates/order retained; target-exclusive keys retained. No protocol changes.'},indent=2)+'\n')
if __name__=='__main__':main()
