#include "status_codec.h"
#include "login_hooks.h"
#include <windows.h>
#include <string.h>

bool l2k_install_status_bridge(){
    // Called after the whole engine SHA256 check in the login installer.
    uintptr_t base=reinterpret_cast<uintptr_t>(GetModuleHandleW(L"engine.dll"));
    if(!base)return false;
    auto slot=reinterpret_cast<void* volatile*>(base+0x126560);
    const uint8_t dispatch[]={0xff,0x24,0x85};
    if(*slot!=reinterpret_cast<void*>(base+0x126523)||
       memcmp(reinterpret_cast<void*>(base+0x1262c0),dispatch,sizeof(dispatch)))return false;
    void* code=VirtualAlloc(nullptr,30,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE);
    if(!code)return false;
    if(l2k_status_exp_thunk(static_cast<uint8_t*>(code),30,base,reinterpret_cast<uintptr_t>(code))!=30){VirtualFree(code,0,MEM_RELEASE);return false;}
    DWORD previous;
    if(!VirtualProtect(code,30,PAGE_EXECUTE_READ,&previous)){
        VirtualFree(code,0,MEM_RELEASE);return false;
    }
    if(!FlushInstructionCache(GetCurrentProcess(),code,30)||!VirtualProtect(const_cast<void**>(slot),4,PAGE_READWRITE,&previous)){
        VirtualFree(code,0,MEM_RELEASE);return false;
    }
    InterlockedExchangePointer(slot,code);
    DWORD ignored;VirtualProtect(const_cast<void**>(slot),4,previous,&ignored);
    l2k_log("status_adapter=active; C4 experience dword forwarded to native Interlude 64-bit update");
    return true;
}
