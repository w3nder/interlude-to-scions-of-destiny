"""Decode local DATs to isolated research files with l2disasm; no game mutation."""
import concurrent.futures,json,os,subprocess,sys
from pathlib import Path
from ini_codec import decode
ROOT=Path(__file__).resolve().parent
REF=ROOT/'references/l2fileedit';OUT=ROOT/'build/dat-audit'
NAMES=['itemname-e','weapongrp','armorgrp','etcitemgrp','npcgrp','npcname-e']
WINE=ROOT/'build/wine-runtime/Wine Stable.app/Contents/Resources/wine/bin/wine'
def win(p):return 'Z:'+str(p.resolve()).replace('/','\\')
def run_tool(tool,args,log):
 env=os.environ.copy();env.update(WINEPREFIX=str(ROOT/'build/dat-wine-prefix'),WINEDEBUG='-all',MVK_CONFIG_LOG_LEVEL='0')
 r=subprocess.run([str(WINE),str(REF/(tool+'.exe')),*args],env=env,capture_output=True,timeout=60)
 log.write_bytes(r.stdout+b'\nSTDERR\n'+r.stderr)
 return r.returncode

def extract(side,name,version):
 base=ROOT.parent.parent/'system' if side=='source' else Path('/Users/wenderteixeira/Downloads/Lineage2_Interlude_Client/system')
 binary=OUT/(side+'-'+name+'.dat.decoded');binary.write_bytes(decode((base/(name+'.dat')).read_bytes()))
 definition=OUT/(version+'-'+name+'.ddf')
 text=(REF/'DAT_defs'/version/(name+'.ddf')).read_text();text=text.replace('UNICODE tex1[cnt_tex2]','UNICODE tex2[cnt_tex2]');definition.write_text(text)
 prefix=side+'-'+name+'-'+version;txt=OUT/(prefix+'.tsv');ddf=OUT/(prefix+'.export.ddf')
 rc=run_tool('l2disasm',['-d',win(definition),'-o','e','-e',win(ddf),win(binary),win(txt)],OUT/(prefix+'.log'))
 result=dict(side=side,name=name,version=version,exit_code=rc,text=str(txt),definition=str(ddf),rows=len(txt.read_text().splitlines())-1 if txt.exists() else None)
 print(json.dumps(result),flush=True);return result

def main():
 OUT.mkdir(exist_ok=True)
 jobs=[(side,name,'C4' if side=='source' else 'Interlude') for side in ['source','target'] for name in NAMES]
 with concurrent.futures.ThreadPoolExecutor(max_workers=3) as pool:results=list(pool.map(lambda args:extract(*args),jobs))
 (OUT/'extraction.json').write_text(json.dumps(results,indent=2)+'\n')
if __name__=='__main__':main()
