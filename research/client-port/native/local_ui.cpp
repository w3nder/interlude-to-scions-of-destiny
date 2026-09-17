#include "local_ui.h"
#include <windows.h>
#include <string.h>

namespace {
struct Packet {uint8_t opcode,padding;uint16_t extended;uint32_t length;uint8_t* data;};
static_assert(sizeof(Packet)==12,"Pinned Interlude x86 queue ABI");
using Alloc=void* (__thiscall*)(void*,uint32_t,const wchar_t*);
using Free=void (__thiscall*)(void*,void*);
using Queue=int (__thiscall*)(void*,Packet*);
}
bool l2k_queue_local_html(const uint8_t* p,uint32_t n){
    if(!p||n<11||n>8190||!(n&1)||p[0]!=0x0f||p[n-6]||p[n-5])return false;
    const uintptr_t base=reinterpret_cast<uintptr_t>(GetModuleHandleW(L"engine.dll"));
    if(!base)return false;
    // Exactly the allocations/descriptor used by ReceivePacket 10420e60,
    // followed by its thread-safe AddNetworkQueue 1042b7d0. No cipher flag or
    // socket state is changed, including when called on the UI/send thread.
    void** allocator_global=*reinterpret_cast<void***>(base+0x1a8d6a0);
    void* network=*reinterpret_cast<void**>(base+0x81f538);
    if(!allocator_global||!*allocator_global||!network)return false;
    void* allocator=*allocator_global;void** vt=*reinterpret_cast<void***>(allocator);
    auto alloc=reinterpret_cast<Alloc>(vt[0]);auto release=reinterpret_cast<Free>(vt[2]);
    uint8_t* body=static_cast<uint8_t*>(alloc(allocator,n,L"L2KLocalHtml"));
    if(!body)return false;
    Packet* packet=static_cast<Packet*>(alloc(allocator,sizeof(Packet),L"L2KLocalPacket"));
    if(!packet){release(allocator,body);return false;}
    memcpy(body,p+1,n-1);body[n-1]=0;
    packet->opcode=0x0f;packet->padding=0;packet->extended=0xffff;packet->length=n-1;packet->data=body;
    reinterpret_cast<Queue>(base+0x12b7d0)(network,packet);
    return true;
}
