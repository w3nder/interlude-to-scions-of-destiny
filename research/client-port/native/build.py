"""Build the protocol library, not an installable game patch."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys

ROOT=Path(__file__).resolve().parent
BUILD=ROOT.parent/'build';BUILD.mkdir(exist_ok=True)
# Public constants are versioned; regeneration is optional and uses the original backend.
if not (ROOT/'constants.inc').exists():
    subprocess.run([sys.executable,str(ROOT/'generate_constants.py')],check=True)
common=['-std=c++17','-O2','-Wall','-Wextra','-Werror','-fno-exceptions','-fno-rtti',str(ROOT/'protocol_core.cpp'),str(ROOT/'clan_codec.cpp'),str(ROOT/'schema_codec.cpp'),str(ROOT/'structured_codec.cpp'),str(ROOT/'outbound_policy.cpp'),str(ROOT/'asset_codec.cpp'),str(ROOT/'character_codec.cpp')]
subprocess.run(['clang++',*common,'-dynamiclib','-o',str(BUILD/'libl2k_protocol.dylib')],check=True)
subprocess.run(['i686-w64-mingw32-g++',*common,str(ROOT/'bootstrap.cpp'),str(ROOT/'login_hooks.cpp'),str(ROOT/'game_trace.cpp'),'-shared','-static-libgcc','-static-libstdc++',
                '-ladvapi32','-lws2_32','-Wl,--no-insert-timestamp','-o',str(BUILD/'L2KProtocolCore.dll')],check=True)
artifacts={p.name:hashlib.sha256(p.read_bytes()).hexdigest() for p in
           [BUILD/'libl2k_protocol.dylib',BUILD/'L2KProtocolCore.dll']}
(BUILD/'manifest.json').write_text(json.dumps(dict(status='experimental library; automatic loading available; login hooks enabled; game metadata trace; original game transport preserved',
    abi=1,artifacts=artifacts),indent=2)+'\n')
print(json.dumps(artifacts,indent=2))
