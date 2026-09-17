#include "outbound_policy.h"
#include <string.h>
namespace {
struct Rule {uint16_t extended;const char* name;};
const Rule denied[]={
#include "outbound_denied.inc"
};
}
L2K_API int l2k_outbound_blocked(const uint8_t* p,uint32_t n){
    if(!p||!n)return L2K_INVALID;
    if(p[0]==0x45){
        if(n!=10)return L2K_INVALID;
        const uint32_t action=uint32_t(p[1])|uint32_t(p[2])<<8|uint32_t(p[3])<<16|uint32_t(p[4])<<24;
        // Exact actionname-e catalogues: these ten summon commands exist
        // only in Interlude. Ordinary C4 and unknown custom IDs keep their route.
        return action>=1031 && action<=1040 ? 1:0;
    }
    if(p[0]!=0xd0)return 0;
    if(n<3)return L2K_INVALID;
    uint16_t sub=p[1]|uint16_t(p[2])<<8;
    for(const auto& r:denied)if(sub==r.extended)return 1;
    return 0;
}
L2K_API int l2k_outbound_convert(uint8_t* p,uint32_t n){
    if(!p||!n)return L2K_INVALID;
    switch(p[0]){
    case 0xc0: {
        // C4 RequestPledgePower 103fb950: actions 1/2 use cdd;
        // other actions use cddb with exactly 32 raw bytes.
        // Interlude action 2 emits cddd (13 bytes), which is NOT a
        // valid C4 action-2 request. The contextual member bridge runs first;
        // this fallback never forwards an unadapted rank operation.
        if(n<9)return L2K_INVALID;
        uint32_t action=uint32_t(p[5])|(uint32_t(p[6])<<8)|
            (uint32_t(p[7])<<16)|(uint32_t(p[8])<<24);
        return n==((action==1||action==2)?9u:41u)?0:L2K_INVALID;
    }
    case 0xd0:
        if(n<3)return L2K_INVALID;
        if(p[1]!=0x0e||p[2]!=0)return 0;
        // Exact engines: chdd -> chd; retain the first Top() response.
        if(n==7)return 0;
        return n==11?7:L2K_INVALID;
    case 0x71:
        // Exact engines: retain the first two Top() values; C4 has no suffix.
        if(n==9)return 0;
        return n==17?9:L2K_INVALID;
    case 0x24: // RequestJoinPledge: C4 supports only the main clan.
        if(n==5)return 0;
        if(n!=9||p[5]||p[6]||p[7]||p[8])return L2K_INVALID;
        return 5;
    case 0xa7: // list ID, entry ID, amount; no augmentation selection in C4.
        if(n==13)return 0;
        if(n!=21)return L2K_INVALID;
        for(unsigned i=13;i<21;++i)if(p[i])return L2K_INVALID;
        return 13;
    case 0xc5: // message ID and answer; requestor ID is an Interlude extension.
        if(n==9)return 0;
        return n==13?9:L2K_INVALID;
    default:return 0;
    }
}

L2K_API const char* l2k_outbound_serialization_format(const char* format,const uint8_t* p,uint32_t n){
    if(!format||!p||!n)return nullptr;
    // EnterWorld: b has a native length argument, not a length on the wire.
    // Rewrite the serializer contract, never guess the variable blob boundary.
    if(p[0]==0x03 && !strcmp(format,"cbddddbdcccccccccccccccccccc"))return "cbdddd";
    return nullptr;
}
