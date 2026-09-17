"""Stage C4 catalogue records in Interlude DAT schemas, retaining source IDs.
Original files and live client are not modified. Requires extracted TSV/DDfs.
"""
import csv,hashlib,json,re,struct
from pathlib import Path
from extract_asset_tables import ROOT,OUT,REF,run_tool,win
from ini_codec import encode,decode
NAMES=['itemname-e','weapongrp','armorgrp','etcitemgrp','npcgrp','npcname-e']
STAGE=ROOT/'build/assets-interlude';STAGE.mkdir(exist_ok=True)
def read(path):
 with path.open(encoding='utf-8',newline='') as f:
  reader=csv.DictReader(f,delimiter='\t',quoting=csv.QUOTE_NONE);rows=list(reader)
  if any(None in r for r in rows):raise ValueError('Unaligned text row '+str(path))
  return reader.fieldnames,rows

def write(path,headers,rows):
 with path.open('w',encoding='utf-8',newline='') as f:
  w=csv.DictWriter(f,headers,delimiter='\t',quoting=csv.QUOTE_NONE,quotechar=None,escapechar=None,lineterminator='\n');w.writeheader();w.writerows(rows)

def main():
 inputs={name:{s:read(OUT/f'{s}-{name}-{v}.tsv') for s,v in [('source','C4'),('target','Interlude')]} for name in NAMES}
 source_items={r['id'] for n in ['weapongrp','armorgrp','etcitemgrp'] for r in inputs[n]['source'][1]}
 fixes=json.loads((OUT/'reference-fixes.json').read_text()) if (OUT/'reference-fixes.json').exists() else []
 replacements={r['source_reference'].casefold():r['replacement'] for r in fixes}
 report=[]
 for name in NAMES:
  sh,srows=inputs[name]['source'];th,trows=inputs[name]['target'];key='tag' if name=='npcgrp' else 'id'
  definition=(OUT/f'target-{name}-Interlude.export.ddf').read_text()
  if name=='npcgrp':
   definition=re.sub(r'(UINT unk1_tab\[unk1_cnt\];\s+SOFT = )5;',r'\g<1>18;',definition)
   at=th.index('unk1_tab[4]')+1;th=th[:at]+[f'unk1_tab[{i}]' for i in range(5,18)]+th[at:]
  ddf=STAGE/(name+'.ddf');ddf.write_text(definition)
  source_ids={r[key] for r in srows};blocked=source_items if name in ['weapongrp','armorgrp','etcitemgrp'] else source_ids
  merged=[{k:r.get(k,'') for k in th} for r in trows if r[key] not in blocked]
  kept=len(merged);defaults={}
  if name=='itemname-e':defaults={k:('a,' if k in ['set_ids','set_bonus_desc','set_extra_id','set_extra_desc','special_enchant_desc'] else '0') for k in th if k not in sh}
  if name=='weapongrp':defaults={k:('-1' if k.startswith('junk3[') else '') for k in th if k not in sh}
  if name=='npcgrp':defaults={'unk0_cnt':'0','unk0_tab':'','rb_effect_on':'0','rb_effect':'','rb_effect_fl':''}
  for r in srows:
   out={k:r.get(k,defaults.get(k,'')) for k in th}
   if name=='armorgrp':out['durability']=str(int(out['durability'])&0xffffffff)
   out={k:replacements.get(v.casefold(),v) for k,v in out.items()}
   merged.append(out)
  txt=STAGE/(name+'.tsv');write(txt,th,merged)
  binary=STAGE/(name+'.decoded');code=run_tool('l2asm',['-d',win(ddf),win(txt),win(binary)],STAGE/(name+'.assemble.log'))
  if code or not binary.exists():raise ValueError('Assembly failed '+name)
  check=STAGE/(name+'.roundtrip.tsv');code=run_tool('l2disasm',['-d',win(ddf),'-o','e',win(binary),win(check)],STAGE/(name+'.roundtrip.log'))
  if code:raise ValueError('Disassembly validation failed '+name)
  h,rows=read(check)
  if h!=th or rows!=merged:
   for idx,(a,b) in enumerate(zip(rows,merged)):
    if a!=b:print('MISMATCH',name,idx,{k:(a.get(k),b.get(k)) for k in set(a)|set(b) if a.get(k)!=b.get(k)});break
   raise ValueError('Round-trip mismatch '+name)
  raw=binary.read_bytes()
  if struct.unpack_from('<I',raw)[0]!=len(merged):raise ValueError('Binary row count mismatch')
  encrypted=encode(raw)
  if decode(encrypted)!=raw:raise ValueError('Encryption roundtrip mismatch')
  dest=STAGE/(name+'.dat');dest.write_bytes(encrypted)
  report.append(dict(table=name,source_rows=len(srows),target_rows=len(trows),target_exclusive_retained=kept,merged_rows=len(merged),source_ids_missing_in_original_target=len(source_ids-{r[key] for r in trows}),source_duplicates_retained_in_original_order=len(srows)-len(source_ids),new_field_defaults=defaults,source_only_fields_omitted=sorted(set(sh)-set(th)),sha256=hashlib.sha256(encrypted).hexdigest(),roundtrip='all columns and rows identical after target assembler/disassembler and RSA413 encode/decode'))
  print(json.dumps(report[-1]),flush=True)
 (STAGE/'tables-manifest.json').write_text(json.dumps({'tables':report,'policy':'Source records retain IDs and original duplicate ordering; source item IDs take priority over target records across item categories. Target-exclusive records retained. C4-only NPC level range/flag metadata omitted; Interlude raid effect disabled for migrated entries.'},indent=2)+'\n')
if __name__=='__main__':main()
