#include "game_trace.h"
#include "clan_codec.h"
#include "clan_self.h"
#include "schema_codec.h"
#include "structured_codec.h"
#include "asset_codec.h"
#include "character_codec.h"
#include "pledge_bridge.h"
#include "local_ui.h"
#include "outbound_policy.h"
#include <stdarg.h>
#include "login_hooks.h"
#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

namespace game_trace {
using Cipher=void (__thiscall*)(void*,uint8_t*,uint8_t*,uint32_t);
using Receive=void (__thiscall*)(void*,uint8_t*,uint32_t);
Cipher encrypt_original,decrypt_original;
Receive receive_original;
HANDLE trace_file=INVALID_HANDLE_VALUE;
HANDLE asset_file=INVALID_HANDLE_VALUE;
L2KAssetRecord asset_seen[4096];
uint32_t asset_count=0;
bool asset_unknown[256]={};
CRITICAL_SECTION trace_lock;
CRITICAL_SECTION pledge_lock;
L2KPledgeState pledge_state{};
L2KClanSelf clan_self{};
void* pledge_socket=nullptr;
uint32_t pledge_socket_id=0;
uint32_t sequence=0;
constexpr uint32_t limit=50000;

// Metadata only: never persist payload, chat, account names or cipher keys.
void record(void* socket,const char* direction,const char* stage,const uint8_t* data,uint32_t length){
    const DWORD saved=GetLastError();
    if(trace_file!=INVALID_HANDLE_VALUE && data && length && length<=65533){
        EnterCriticalSection(&trace_lock);
        if(sequence<limit){
            unsigned opcode=data[0];int extended=-1;
            if(length>=3 && ((direction[0]=='S' && opcode==0xfe)||(direction[0]=='C' && opcode==0xd0)))extended=data[1]|(unsigned(data[2])<<8);
            uint32_t socket_id;memcpy(&socket_id,static_cast<uint8_t*>(socket)+0x38,4);
            char line[256];int n=snprintf(line,sizeof(line),"%lu\t%lu\t%lu\t%s\t%s\t%02X\t%d\t%lu\r\n",(unsigned long)++sequence,(unsigned long)GetTickCount(),(unsigned long)socket_id,direction,stage,opcode,extended,(unsigned long)length);
            if(n>0 && n<(int)sizeof(line)){DWORD written;WriteFile(trace_file,line,(DWORD)n,&written,nullptr);}
            if(sequence==limit)l2k_log("game trace reached 50000 events; gameplay continues without further trace");
        }
        LeaveCriticalSection(&trace_lock);
    }
    SetLastError(saved);
}
void record_assets(void* socket,const uint8_t* data,uint32_t length){
    if(asset_file==INVALID_HANDLE_VALUE)return;
    const DWORD saved_error=GetLastError();
    L2KAssetRecord rows[256];int n=l2k_asset_inspect(data,length,rows,256);
    if(n<0){
        if(!asset_unknown[data[0]]){asset_unknown[data[0]]=true;record(socket,"S2C","asset_layout_unrecognized",data,length);}
        SetLastError(saved_error);return; // Diagnostics never reject or modify a packet.
    }
    EnterCriticalSection(&trace_lock);
    for(int i=0;i<n&&asset_count<4096;++i){
        const auto& r=rows[i];if(!r.id)continue;bool seen=false;
        for(uint32_t j=0;j<asset_count;++j)if(asset_seen[j].kind==r.kind&&asset_seen[j].id==r.id&&asset_seen[j].variant==r.variant){seen=true;break;}
        if(seen)continue;
        asset_seen[asset_count++]=r;
        char line[256];int bytes=snprintf(line,sizeof(line),"%u\t%02X\t%lu\t%lu\t%lu\t%lu\t%lu\t%lu\t%lu\t%lu\t%lu\t%lu\r\n",asset_count,data[0],(unsigned long)length,(unsigned long)r.kind,(unsigned long)r.id,(unsigned long)r.quantity,(unsigned long)r.equipped,(unsigned long)r.body_part,(unsigned long)r.slot,(unsigned long)r.enchant,(unsigned long)r.variant,(unsigned long)r.type1);
        if(bytes>0&&bytes<(int)sizeof(line)){DWORD written;WriteFile(asset_file,line,bytes,&written,nullptr);}
    }
    LeaveCriticalSection(&trace_lock);
    SetLastError(saved_error);
}
void __fastcall encrypt_observer(void* socket,void*,uint8_t* data,uint8_t* state,uint32_t length){
    record(socket,"C2S","before_encrypt",data,length);
    encrypt_original(socket,data,state,length);
}
void __fastcall decrypt_observer(void* socket,void*,uint8_t* data,uint8_t* state,uint32_t length){
    decrypt_original(socket,data,state,length);
    record(socket,"S2C","after_decrypt",data,length);
}
using Send=void (__cdecl*)(void*,const char*,...);
using Serialize=int (__cdecl*)(uint8_t*,uint32_t,const char*,va_list);
Send send_original;
Serialize serialize_original;
void pledge_session(void* socket){
    uint32_t id;memcpy(&id,static_cast<uint8_t*>(socket)+0x38,4);
    if(socket!=pledge_socket||id!=pledge_socket_id){l2k_pledge_reset(&pledge_state);l2k_clan_self_reset(&clan_self);pledge_socket=socket;pledge_socket_id=id;}
}
bool pledge_outgoing(void* socket,const uint8_t* p,uint32_t n){
    L2KPledgeResult result{};
    EnterCriticalSection(&pledge_lock);pledge_session(socket);
    int handled=l2k_pledge_send(&pledge_state,p,n,GetTickCount(),&result);
    if(result.display_size&&!l2k_queue_local_html(result.display,result.display_size))l2k_log("local clan UI could not be queued");
    LeaveCriticalSection(&pledge_lock);
    if(handled<=0)return false;
    if(result.server_size&&l2k_outbound_convert(result.server,result.server_size)>=0){
        record(socket,"C2S","converted_C4_pledge",result.server,result.server_size);
        send_original(socket,"b",result.server_size,result.server);
    }else record(socket,"C2S","local_C4_pledge",p,n);
    return true;
}
bool pledge_incoming(void* socket,const uint8_t* p,uint32_t n,bool legacy,uint8_t* member,int& member_size){
    L2KPledgeResult result{};
    EnterCriticalSection(&pledge_lock);pledge_session(socket);
    int handled=l2k_pledge_receive(&pledge_state,p,n,GetTickCount(),&result);
    member_size=l2k_clan_self_receive(&clan_self,p,n,legacy,member,160);
    if(member_size>0){L2KPledgeResult ignored{};l2k_pledge_receive(&pledge_state,member,member_size,GetTickCount(),&ignored);}
    if(result.display_size&&!l2k_queue_local_html(result.display,result.display_size))l2k_log("local clan UI could not be queued");
    LeaveCriticalSection(&pledge_lock);
    if(handled>0)record(socket,"S2C","local_C4_pledge",p,n);
    return handled>0;
}
void __cdecl send_adapter(void* socket,const char* format,...){
    uint8_t payload[8190];va_list args;va_start(args,format);
    int n=serialize_original(payload,sizeof(payload),format,args);va_end(args);
    if(n<=0||n>(int)sizeof(payload)){l2k_log("outbound rejected: serialization failed");return;}
    if(pledge_outgoing(socket,payload,(uint32_t)n))return;
    const char* source_format=l2k_outbound_serialization_format(format,payload,(uint32_t)n);
    if(source_format){
        const int previous=n;
        va_start(args,format);n=serialize_original(payload,sizeof(payload),source_format,args);va_end(args);
        // Verified extra b[64], d and twenty c fields occupy exactly 88 bytes.
        if(n<17 || n+88!=previous || payload[0]!=0x03){
            l2k_log("outbound rejected: EnterWorld serializer contract mismatch");return;
        }
        record(socket,"C2S","converted_C4_serializer",payload,n);
    }
    int decision=l2k_outbound_blocked(payload,(uint32_t)n);
    if(decision!=0){record(socket,"C2S","blocked_unsupported",payload,n);return;}
    int converted=l2k_outbound_convert(payload,(uint32_t)n);
    if(converted<0){record(socket,"C2S","blocked_unsupported_layout",payload,n);return;}
    if(converted>0){n=converted;record(socket,"C2S","converted_C4_schema",payload,n);}
    // Original sender retains its critical section, framing, cipher and send path.
    send_original(socket,"b",n,payload);
}
void __fastcall receive_observer(void* socket,void*,uint8_t* frame,uint32_t length){
    unsigned declared=frame&&length>=2 ? unsigned(frame[0])|(unsigned(frame[1])<<8) : 0;
    if(!frame || length<3 || length>65535 || declared!=length){
        char reason[128];snprintf(reason,sizeof(reason),"game rejected invalid frame: supplied=%lu declared=%u",(unsigned long)length,declared);l2k_log(reason);return;
    }
    uint32_t* enabled=reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(socket)+0x50bc);
    uint32_t saved=*enabled;
    if(saved)decrypt_observer(socket,nullptr,frame+2,static_cast<uint8_t*>(socket)+0x50d1,length-2);
    else record(socket,"S2C","plaintext",frame+2,length-2);
    record_assets(socket,frame+2,length-2);
    uint8_t converted[65535];int n=l2k_clan_convert(frame+2,length-2,converted+2,sizeof(converted)-2);
    bool clan=n!=0;
    if(!n)n=l2k_schema_convert(frame+2,length-2,converted+2,sizeof(converted)-2);
    if(!n)n=l2k_structured_convert(frame+2,length-2,converted+2,sizeof(converted)-2);
    if(!n)n=l2k_character_convert(frame+2,length-2,converted+2,sizeof(converted)-2);
    if(n<0){record(socket,"S2C",clan?"rejected_clan_layout":"rejected_schema_layout",frame+2,length-2);return;}
    uint8_t* current=frame;uint32_t current_size=length;
    if(n>0){current_size=(uint32_t)n+2;converted[0]=(uint8_t)current_size;converted[1]=(uint8_t)(current_size>>8);current=converted;record(socket,"S2C",clan?"converted_C4_clan":"converted_C4_schema",converted+2,n);}
    uint8_t member[162];int member_size=0;
    if(pledge_incoming(socket,current+2,current_size-2,clan&&n>0&&frame[2]==0x53,member+2,member_size))return;
    // Native receive copies the selected plaintext into the normal UI queue.
    *enabled=0;receive_original(socket,current,current_size);
    if(member_size>0){
        unsigned total=unsigned(member_size)+2;member[0]=uint8_t(total);member[1]=uint8_t(total>>8);
        record(socket,"S2C","local_C4_clan_self",member+2,member_size);
        receive_original(socket,member,total);
    }
    *enabled=saved;
}
struct Patch {uintptr_t slot,expected;void* observer;};
}

bool l2k_install_game_trace(){
    using namespace game_trace;
    // Called only after login installer has checked the complete engine SHA256.
    uintptr_t base=reinterpret_cast<uintptr_t>(GetModuleHandleW(L"engine.dll"));if(!base)return false;
    Patch patches[]={
        {0x58b594,0xd184,reinterpret_cast<void*>(send_adapter)},
        {0x58b5a0,0x89e0,reinterpret_cast<void*>(receive_observer)},
        {0x58b5a4,0xe408,reinterpret_cast<void*>(encrypt_observer)},
        {0x58b5a8,0x3116,reinterpret_cast<void*>(decrypt_observer)}
    };
    for(auto& p:patches)if(*reinterpret_cast<uintptr_t*>(base+p.slot)!=base+p.expected){l2k_log("game trace skipped: pointer mismatch; original game path retained");return false;}
    wchar_t path[MAX_PATH];DWORD n=GetModuleFileNameW(nullptr,path,MAX_PATH);if(!n||n>=MAX_PATH)return false;
    wchar_t* slash=wcsrchr(path,L'\\');if(!slash || (slash-path)+48>=MAX_PATH)return false;
    swprintf(slash+1,48,L"L2KGameTrace-%lu-%lu.tsv",(unsigned long)GetCurrentProcessId(),(unsigned long)GetTickCount());
    trace_file=CreateFileW(path,GENERIC_WRITE,FILE_SHARE_READ,nullptr,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,nullptr);if(trace_file==INVALID_HANDLE_VALUE)return false;
    InitializeCriticalSection(&trace_lock);
    InitializeCriticalSection(&pledge_lock);l2k_pledge_reset(&pledge_state);
    swprintf(slash+1,48,L"L2KAssetAudit-%lu-%lu.tsv",(unsigned long)GetCurrentProcessId(),(unsigned long)GetTickCount());
    asset_file=CreateFileW(path,GENERIC_WRITE,FILE_SHARE_READ,nullptr,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,nullptr);
    if(asset_file!=INVALID_HANDLE_VALUE){
        const char columns[]="sequence\topcode\tbytes\tkind\tcatalogue_id\tquantity\tequipped\tbody_part\tslot\tenchant\tlayout\ttype1\r\n";
        DWORD wrote;WriteFile(asset_file,columns,sizeof(columns)-1,&wrote,nullptr);
    }
    const char header[]="sequence\ttick_ms\tsocket\tdirection\tstage\topcode\textended\tbytes\r\n";DWORD written;WriteFile(trace_file,header,sizeof(header)-1,&written,nullptr);
    DWORD old[4];unsigned prepared=0;
    for(auto& p:patches){if(!VirtualProtect(reinterpret_cast<void*>(base+p.slot),4,PAGE_READWRITE,&old[prepared]))break;++prepared;}
    if(prepared!=4){
        while(prepared){--prepared;DWORD ignored;VirtualProtect(reinterpret_cast<void*>(base+patches[prepared].slot),4,old[prepared],&ignored);}
        if(asset_file!=INVALID_HANDLE_VALUE){CloseHandle(asset_file);asset_file=INVALID_HANDLE_VALUE;}
        CloseHandle(trace_file);trace_file=INVALID_HANDLE_VALUE;DeleteCriticalSection(&pledge_lock);DeleteCriticalSection(&trace_lock);return false;
    }
    send_original=reinterpret_cast<Send>(base+0x1029b0);serialize_original=reinterpret_cast<Serialize>(base+0x68b6);
    receive_original=reinterpret_cast<Receive>(base+0x120e60);
    encrypt_original=reinterpret_cast<Cipher>(base+0x101fd0);decrypt_original=reinterpret_cast<Cipher>(base+0x102070);
    for(auto& p:patches)InterlockedExchangePointer(reinterpret_cast<void* volatile*>(base+p.slot),p.observer);
    while(prepared){--prepared;DWORD ignored;VirtualProtect(reinterpret_cast<void*>(base+patches[prepared].slot),4,old[prepared],&ignored);}
    l2k_log("game_adapter=active; original game cipher; clan and schema converters; 26 unsupported Interlude requests and 10 summon action IDs blocked; local clan permissions; metadata trace");return true;
}
