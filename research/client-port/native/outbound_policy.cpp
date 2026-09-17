#include "outbound_policy.h"
namespace {
struct Rule {uint16_t extended;const char* name;};
const Rule denied[]={
#include "outbound_denied.inc"
};
}
L2K_API int l2k_outbound_blocked(const uint8_t* p,uint32_t n){
    if(!p||!n)return L2K_INVALID;
    if(p[0]!=0xd0)return 0;
    if(n<3)return L2K_INVALID;
    uint16_t sub=p[1]|uint16_t(p[2])<<8;
    for(const auto& r:denied)if(sub==r.extended)return 1;
    return 0;
}
L2K_API int l2k_outbound_convert(uint8_t* p,uint32_t n){
    if(!p||!n)return L2K_INVALID;
    switch(p[0]){
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
