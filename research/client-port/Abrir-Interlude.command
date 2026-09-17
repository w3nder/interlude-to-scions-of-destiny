#!/bin/zsh
export WINEPREFIX='/Users/wenderteixeira/Documents/L2Killer/research/client-port/build/wine-prefix'
cd '/Users/wenderteixeira/Downloads/Lineage2_Interlude_Client/system' || exit 1
exec '/Users/wenderteixeira/Documents/L2Killer/research/client-port/build/wine-runtime/Wine Stable.app/Contents/Resources/wine/bin/wine' l2.exe >> '/Users/wenderteixeira/Documents/L2Killer/research/client-port/build/wine-client.log' 2>&1
