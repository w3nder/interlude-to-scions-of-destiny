#!/bin/zsh
export WINEPREFIX='/Users/wenderteixeira/Library/Application Support/L2Killer/WineRecovery-20260917'
export WINEDLLOVERRIDES='winemenubuilder.exe=d'
export WINEDEBUG='+seh,+loaddll'
unset WINE_D3D_CONFIG
cd '/Users/wenderteixeira/Downloads/Lineage2_Interlude_Client/system' || exit 1
exec '/Users/wenderteixeira/Documents/L2Killer/research/client-port/build/wine-runtime/Wine Stable.app/Contents/Resources/wine/bin/wine' l2.exe >> '/Users/wenderteixeira/Documents/L2Killer/research/client-port/build/wine-client.log' 2>&1
