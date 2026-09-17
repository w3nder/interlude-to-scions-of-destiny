#include "protocol_core.h"
#include "login_hooks.h"
#include <winsock2.h>
#include <windows.h>
#include <wincrypt.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

namespace {
uintptr_t base;
L2KBlowfish cipher;
using Receive=void (__thiscall*)(void*,uint8_t*,uint32_t);
using Send=void (__cdecl*)(void*,const char*,...);
using Handler=int (__cdecl*)(void*,const uint8_t*);
Receive receive_original;
uint32_t& field(void* p,size_t off){return *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(p)+off);}
void* address(uintptr_t rva){return reinterpret_cast<void*>(base+rva);}
void event(const char* stage,unsigned op,unsigned size){char line[160];snprintf(line,sizeof(line),"login %s; opcode=%02X; bytes=%u",stage,op,size);l2k_log(line);}
void close_login(void* sock,const char* reason){l2k_log(reason);shutdown((SOCKET)field(sock,0x38),SD_BOTH);}

// The native UI stores bounded UTF-16 account fields. No credentials go to logs.
bool credential(uintptr_t rva,unsigned limit,uint8_t* out){
    const wchar_t* in=static_cast<const wchar_t*>(address(rva));unsigned n=0;
    while(n<limit && in[n]) ++n;
    if(!n)return false;
    BOOL substituted=FALSE;
    int result=WideCharToMultiByte(CP_ACP,WC_NO_BEST_FIT_CHARS,in,(int)n,reinterpret_cast<char*>(out),(int)limit,nullptr,&substituted);
    return result>0 && !substituted;
}
int __cdecl init_hook(void* network,const uint8_t* payload){
    void* sock=reinterpret_cast<void*>(field(network,0x4c));
    if(!sock)return 0;
    // Receive hook admits only an exact 9-byte C4 Init before this callback.
    field(network,0x50)=1; memcpy(static_cast<uint8_t*>(network)+0xe4,payload,4);
    uint8_t auth[32]={};auth[31]=8;
    if(!credential(0x820f54,14,auth+1)||!credential(0x820f72,16,auth+15)){
        close_login(sock,"login credentials cannot fit C4 fields");return 0;
    }
    field(sock,0x50bc)=1;
    reinterpret_cast<Send>(address(0x103040))(sock,"b",32,auth);
    SecureZeroMemory(auth,sizeof(auth));l2k_log("login Init accepted; AuthLogin sent");return 0;
}
int __cdecl login_ok_hook(void* network,const uint8_t* payload){
    // The keys occupy the first 8 bytes in C4; avoid Interlude's longer parser.
    memcpy(address(0x820f34),payload,8);
    using RequestList=int (__thiscall*)(void*);
    reinterpret_cast<RequestList>(address(0x103a50))(network);
    l2k_log("login LoginOk accepted; ServerList requested");return 0;
}
void __fastcall seal_hook(void* sock,void*,uint8_t* data,uint32_t* size){
    uint8_t output[8192];
    int n=(*size<=8176)?l2k_login_seal(&cipher,data,*size,output,sizeof(output)):L2K_INVALID;
    if(n<0){*size=0;close_login(sock,"login seal rejected invalid length");return;}
    event("send",data[0],*size);memcpy(data,output,n);*size=(uint32_t)n;SecureZeroMemory(output,sizeof(output));
}
void __fastcall decrypt_hook(void* sock,void*,uint8_t* data,uint32_t size){
    if(l2k_login_decrypt(&cipher,data,size,data,size)<0)close_login(sock,"login decrypt rejected length");
}
bool checksum(const uint8_t* p,unsigned n){
    if(n<8 || n%8)return false;
    uint32_t sum=0;
    for(unsigned i=0;i<n-4;i+=4){uint32_t word;memcpy(&word,p+i,4);sum^=word;}
    return sum==0;
}
void __fastcall receive_hook(void* sock,void*,uint8_t* frame,uint32_t size){
    if(size<3 || size>8192 || (unsigned(frame[0])|(unsigned(frame[1])<<8))!=size){close_login(sock,"login rejected frame length");return;}
    uint8_t plain[8192];memcpy(plain,frame,size);unsigned n=size-2;uint8_t* p=plain+2;
    // Init is plaintext and cannot have the encrypted packets' multiple-of-8 size.
    if(n==9 && p[0]==0 && field(sock,0x50b8)==1){field(sock,0x50b8)=0;event("receive Init",0,n);}
    else {
        if(field(sock,0x50b8)!=0 || l2k_login_decrypt(&cipher,p,n,p,n)<0 || !checksum(p,n)){close_login(sock,"login rejected cipher/checksum");return;}
        unsigned minimum=0;
        switch(p[0]){
            case 1:case 6:minimum=2;break;
            case 2:case 3:case 7:minimum=9;break;
            case 4:minimum=n>=3?3+21u*p[1]:8193;break;
            default:close_login(sock,"login rejected unsupported response opcode");return;
        }
        // Last 8 bytes are checksum/trailer, never semantic payload.
        if(n<8 || minimum>n-8){close_login(sock,"login rejected truncated response");return;}
        event("receive",p[0],n);
        if(p[0]==4)l2k_log("login ServerList received; forwarding to Interlude UI");
    }
    // Native callback copies the plaintext into the UI queue. Skip its decrypt.
    uint32_t saved=field(sock,0x50bc);field(sock,0x50bc)=0;
    receive_original(sock,plain,size);field(sock,0x50bc)=saved;
    SecureZeroMemory(plain,sizeof(plain));
}
struct Patch {uintptr_t rva,expected;void* replacement;};
bool engine_hash(HMODULE module){
    wchar_t path[MAX_PATH];DWORD n=GetModuleFileNameW(module,path,MAX_PATH);if(!n||n>=MAX_PATH)return false;
    HANDLE f=CreateFileW(path,GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);if(f==INVALID_HANDLE_VALUE)return false;
    HCRYPTPROV provider=0;HCRYPTHASH hash=0;bool ok=CryptAcquireContextW(&provider,nullptr,nullptr,PROV_RSA_AES,CRYPT_VERIFYCONTEXT)!=0;
    if(ok)ok=CryptCreateHash(provider,CALG_SHA_256,0,0,&hash)!=0;
    uint8_t buffer[65536];DWORD got=0;
    while(ok){if(!ReadFile(f,buffer,sizeof(buffer),&got,nullptr)){ok=false;break;}if(!got)break;ok=CryptHashData(hash,buffer,got,0)!=0;}
    uint8_t digest[32];DWORD count=32;const uint8_t expected[32]={0x50,0x89,0x74,0xc7,0x11,0xf2,0x07,0x40,0x27,0x19,0xe9,0x27,0x37,0xe2,0x11,0xa2,0xf0,0x29,0xc9,0x5c,0x2f,0x68,0xfc,0x0e,0x1c,0x31,0xfc,0xbb,0x9d,0xbb,0x23,0x2d};
    if(ok)ok=CryptGetHashParam(hash,HP_HASHVAL,digest,&count,0)&&count==32&&!memcmp(digest,expected,32);
    if(hash)CryptDestroyHash(hash);
    if(provider)CryptReleaseContext(provider,0);
    CloseHandle(f);return ok;
}
}
bool l2k_install_login_hooks(){
    HMODULE module=GetModuleHandleW(L"engine.dll");if(!module||!engine_hash(module)){l2k_log("hooks refused: unsupported engine hash");return false;}
    base=reinterpret_cast<uintptr_t>(module);
    static const uint8_t key[]={0x5f,0x3b,0x35,0x2e,0x5d,0x39,0x34,0x2d,0x33,0x31,0x3d,0x3d,0x2d,0x25,0x78,0x54,0x21,0x5e,0x5b,0x24,0};
    if(l2k_bf_init(&cipher,key,sizeof(key))!=0)return false;
    Patch patches[]={
        {0x58b710,0xae93,reinterpret_cast<void*>(receive_hook)},
        {0x58b71c,0xa91b,reinterpret_cast<void*>(seal_hook)},
        {0x58b720,0x94c6,reinterpret_cast<void*>(decrypt_hook)},
        {0x7572c0,0x202c,reinterpret_cast<void*>(init_hook)},
        {0x7572cc,0x91d3,reinterpret_cast<void*>(login_ok_hook)}
    };
    // Expected pointers are RVAs, adjusted for Wine/Windows relocation.
    for(auto& p:patches){if(*static_cast<uintptr_t*>(address(p.rva))!=base+p.expected){l2k_log("hooks refused: pointer precondition mismatch");return false;}}
    DWORD old[5];unsigned prepared=0;
    for(auto& p:patches){if(!VirtualProtect(address(p.rva),4,PAGE_READWRITE,&old[prepared]))break;++prepared;}
    if(prepared!=5){while(prepared){--prepared;DWORD ignored;VirtualProtect(address(patches[prepared].rva),4,old[prepared],&ignored);}return false;}
    receive_original=reinterpret_cast<Receive>(base+0x102f50);
    for(auto& p:patches)InterlockedExchangePointer(reinterpret_cast<void* volatile*>(address(p.rva)),p.replacement);
    // Several entries share pages; restore in reverse order.
    while(prepared){--prepared;DWORD ignored;VirtualProtect(address(patches[prepared].rva),4,old[prepared],&ignored);}
    l2k_log("hooks=login_active; C4 Init/Blowfish/LoginOk integrated; game adapter initialized separately");return true;
}
