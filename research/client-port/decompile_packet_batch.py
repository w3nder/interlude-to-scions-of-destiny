"""Export evidence for every changed or unresolved shared inbound handler."""
import json,os,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parent
GHIDRA='/opt/homebrew/opt/ghidra/libexec/support/analyzeHeadless'
def main():
    comparison=json.loads((ROOT/'comparison.json').read_text())
    audit=json.loads((ROOT/'reports/handler-audit.json').read_text())
    ignored={(r['table'],r['opcode']) for r in audit['empty_layout_audit'] if r['resolution']=='both_handlers_ignore_payload'}
    selected=[r for r in comparison['inbound'] if r['source'] and r['target'] and r['status']!='same_observed_decode_segments' and (r['table'],r['opcode']) not in ignored]
    dest=ROOT/'decompiled/batch';dest.mkdir(parents=True,exist_ok=True)
    (dest/'index.json').write_text(json.dumps(selected,indent=2)+'\n')
    env=os.environ.copy();env['JAVA_HOME']='/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home'
    for side,project,binary in [('source','SourcePort',ROOT.parent.parent/'system/engine.dll'),('target','ClientPort',ROOT/'build/interlude-engine.dll')]:
        output=dest/side;output.mkdir(exist_ok=True)
        addresses=sorted({r[side]['handler_va'][2:] for r in selected if r[side].get('handler_va') and not (output/(r[side]['handler_va'][2:]+'.c')).exists()})
        if not addresses:continue
        operation=['-process','engine.dll'] if (ROOT/'ghidra'/(project+'.gpr')).exists() and (side=='target' or (dest/'source-imported.ok').exists()) else ['-import',str(binary)]
        command=[GHIDRA,str(ROOT/'ghidra'),project,*operation,'-noanalysis','-scriptPath',str(ROOT/'ghidra-scripts'),'-postScript','ExportPacketEvidence.java',str(output),*addresses,'-log',str(dest/(side+'.log'))]
        if side=='source' and operation[0]=='-import':command.insert(3,'-overwrite')
        print(side, len(addresses),'handlers',flush=True)
        subprocess.run(command,env=env,check=True)
        if side=='source':(dest/'source-imported.ok').write_text('import completed\n')
if __name__=='__main__':main()
