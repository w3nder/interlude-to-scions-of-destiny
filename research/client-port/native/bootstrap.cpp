#include "protocol_core.h"
#include "login_hooks.h"
#include "game_trace.h"
#include "status_codec.h"
#include <windows.h>
#include <stdio.h>
#include <string.h>

void l2k_log(const char* message) {
    wchar_t path[MAX_PATH];DWORD n=GetModuleFileNameW(nullptr,path,MAX_PATH);
    if(!n||n>=MAX_PATH)return;
    wchar_t* slash=wcsrchr(path,L'\\');
    if(!slash || (slash-path)+21>=MAX_PATH)return;
    wcscpy(slash+1,L"L2KProtocol.log");
    HANDLE file=CreateFileW(path,FILE_APPEND_DATA,FILE_SHARE_READ|FILE_SHARE_WRITE,nullptr,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,nullptr);
    if(file==INVALID_HANDLE_VALUE)return;
    DWORD written;WriteFile(file,message,(DWORD)strlen(message),&written,nullptr);
    WriteFile(file,"\r\n",2,&written,nullptr);CloseHandle(file);
}
// Called after Windows initializes imported DLLs, before the original entrypoint.
L2K_API void l2k_bootstrap() {
    const DWORD saved=GetLastError();
    l2k_log("DLL loaded; build=protocol-hooks-16-clan-member-info; ABI=1");
    if(!l2k_install_login_hooks()) {
        l2k_log("FATAL: hooks not installed; client startup stopped");
        MessageBoxW(nullptr,L"L2K: engine incompatível ou falha ao instalar hooks. Consulte L2KProtocol.log.",L"L2K Protocol",MB_OK|MB_ICONERROR);
        ExitProcess(1);
    }
    if(!l2k_install_game_trace())l2k_log("game_trace=unavailable; login remains active");
    if(!l2k_install_status_bridge())l2k_log("status_adapter=unavailable; original StatusUpdate retained");
    SetLastError(saved);
}
