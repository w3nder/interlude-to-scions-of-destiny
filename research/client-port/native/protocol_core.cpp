#include "protocol_core.h"
#include <cstring>
#include <utility>
#include "constants.inc"

static uint32_t read32(const uint8_t* p) {
    return uint32_t(p[0]) | uint32_t(p[1])<<8 | uint32_t(p[2])<<16 | uint32_t(p[3])<<24;
}
static void write32(uint8_t* p,uint32_t v) { for(int i=0;i<4;++i)p[i]=uint8_t(v>>(8*i)); }
static uint32_t f(const L2KBlowfish& c,uint32_t x) {
    return ((c.s[0][x>>24]+c.s[1][(x>>16)&255])^c.s[2][(x>>8)&255])+c.s[3][x&255];
}
static void block(const L2KBlowfish& c,uint32_t& l,uint32_t& r,bool decrypt) {
    if(!decrypt) {
        l^=c.p[0];
        for(int i=1;i<16;i+=2) { r^=f(c,l)^c.p[i];l^=f(c,r)^c.p[i+1]; }
        r^=c.p[17];
    } else {
        l^=c.p[17];
        for(int i=16;i>0;i-=2) { r^=f(c,l)^c.p[i];l^=f(c,r)^c.p[i-1]; }
        r^=c.p[0];
    }
    std::swap(l,r);
}
L2K_API uint32_t l2k_abi_version(){ return 1; }
L2K_API uint32_t l2k_login_size(){ return sizeof(L2KLogin); }
L2K_API int l2k_bf_init(L2KBlowfish* c,const uint8_t* key,uint32_t n) {
    if(!c||!key||n<1||n>56)return L2K_INVALID;
    std::memcpy(c->p,initial_p,sizeof(c->p));
    std::memcpy(c->s[0],initial_s0,sizeof(c->s[0]));std::memcpy(c->s[1],initial_s1,sizeof(c->s[1]));
    std::memcpy(c->s[2],initial_s2,sizeof(c->s[2]));std::memcpy(c->s[3],initial_s3,sizeof(c->s[3]));
    uint32_t j=0;
    for(auto& value:c->p) { uint32_t d=0;for(int k=0;k<4;++k){d=(d<<8)|key[j];j=(j+1)%n;}value^=d; }
    uint32_t l=0,r=0;
    for(int i=0;i<18;i+=2){block(*c,l,r,false);c->p[i]=l;c->p[i+1]=r;}
    for(auto& s:c->s)for(int i=0;i<256;i+=2){block(*c,l,r,false);s[i]=l;s[i+1]=r;}
    return 0;
}
L2K_API int l2k_bf_block(const L2KBlowfish* c,const uint8_t* in,uint8_t* out,uint32_t decrypt) {
    if(!c||!in||!out||decrypt>1)return L2K_INVALID;
    uint32_t l=read32(in),r=read32(in+4);block(*c,l,r,decrypt!=0);write32(out,l);write32(out+4,r);return 8;
}
L2K_API int l2k_login_seal(const L2KBlowfish* c,const uint8_t* in,uint32_t n,uint8_t* out,uint32_t cap) {
    if(!c||!in||!out||!n||n>8184)return L2K_INVALID;
    uint32_t aligned=(n+7)&~uint32_t(7),size=aligned+8;
    if(cap<size)return L2K_CAPACITY;
    // memmove supports exact in-place output; clear only the reserved tail.
    std::memmove(out,in,n);std::memset(out+n,0,size-n);
    uint32_t checksum=0;for(uint32_t i=0;i<aligned;i+=4)checksum^=read32(out+i);
    write32(out+aligned,checksum);
    for(uint32_t i=0;i<size;i+=8)l2k_bf_block(c,out+i,out+i,0);
    return int(size);
}
L2K_API int l2k_login_decrypt(const L2KBlowfish* c,const uint8_t* in,uint32_t n,uint8_t* out,uint32_t cap) {
    if(!c||!in||!out||!n||n>8192||n%8)return L2K_INVALID;
    if(cap<n)return L2K_CAPACITY;
    std::memmove(out,in,n);for(uint32_t i=0;i<n;i+=8)l2k_bf_block(c,out+i,out+i,1);
    // Preserve padding: true payload size/checksum policy is packet-specific.
    return int(n);
}
L2K_API int l2k_game_key(L2KGame* c,const uint8_t* p,uint32_t n) {
    if(!c)return L2K_INVALID;
    std::memset(c,0,sizeof(*c));
    if(!p||n!=14||p[0]!=0||p[1]!=1||read32(p+6)!=1)return L2K_INVALID;
    uint32_t seed=read32(p+2);write32(c->tx,seed);
    write32(c->tx+4,(seed&0x80000000)?0xffffffff:0x87546ca1);
    std::memcpy(c->rx,c->tx,8);c->ready=1;return 0;
}
L2K_API int l2k_game_transform(L2KGame* c,uint8_t* p,uint32_t n,uint32_t decrypt) {
    if(!c||!p||!n||n>65533||decrypt>1)return L2K_INVALID;
    if(c->ready!=1)return L2K_PHASE;
    uint8_t* key=decrypt?c->rx:c->tx;uint8_t previous=0;
    for(uint32_t i=0;i<n;++i){uint8_t value=p[i];p[i]^=key[i&7]^previous;previous=decrypt?value:p[i];}
    uint64_t value=uint64_t(read32(key))|(uint64_t(read32(key+4))<<32);value+=n;
    write32(key,uint32_t(value));write32(key+4,uint32_t(value>>32));return int(n);
}
L2K_API int l2k_protocol_version(const uint8_t* in,uint32_t n,uint8_t* out,uint32_t cap) {
    if(!in||!out||n!=265||in[0]!=0||read32(in+1)!=746||std::memcmp(in+5,protocol_block,256))return L2K_INVALID;
    if(cap<261)return L2K_CAPACITY;
    std::memmove(out,in,261);write32(out+1,656);return 261;
}
L2K_API int l2k_login_begin(L2KLogin* c,const uint8_t* user,uint32_t un,const uint8_t* pass,uint32_t pn) {
    if(!c)return L2K_INVALID;
    std::memset(c,0,sizeof(*c));
    if(!user||!pass||!un||un>14||!pn||pn>16)return L2K_INVALID;
    for(uint32_t i=0;i<un;++i)if(!user[i])return L2K_INVALID;
    for(uint32_t i=0;i<pn;++i)if(!pass[i])return L2K_INVALID;
    static const uint8_t key[]={0x5f,0x3b,0x35,0x2e,0x5d,0x39,0x34,0x2d,0x33,0x31,0x3d,0x3d,0x2d,0x25,0x78,0x54,0x21,0x5e,0x5b,0x24,0};
    l2k_bf_init(&c->bf,key,sizeof(key));std::memcpy(c->user,user,un);std::memcpy(c->password,pass,pn);c->phase=1;return 0;
}
L2K_API int l2k_login_step(L2KLogin* c,const uint8_t* p,uint32_t n,uint8_t* out,uint32_t cap) {
    if(!c||!p||!n||n>8192||!out)return L2K_INVALID;
    if(c->phase<1||c->phase>4)return L2K_PHASE;
    if(c->phase>1&&(p[0]==1||p[0]==2||p[0]==6)){c->phase=6;return L2K_REFUSED;}
    uint8_t reply[32]={};int result=0;
    switch(c->phase) {
    case 1:
        if(n!=9||p[0]!=0)return L2K_INVALID;
        std::memcpy(reply+1,c->user,14);std::memcpy(reply+15,c->password,16);reply[31]=8;
        result=l2k_login_seal(&c->bf,reply,32,out,cap);
        if(result>=0){std::memset(c->password,0,16);c->phase=2;}return result;
    case 2:
        if(n<9||p[0]!=3)return L2K_INVALID;
        reply[0]=5;std::memcpy(reply+1,p+1,8);reply[9]=4; // C4 native cddc.
        result=l2k_login_seal(&c->bf,reply,10,out,cap);
        if(result>=0){c->login1=read32(p+1);c->login2=read32(p+5);c->phase=3;}return result;
    case 3: {
        // First server, matching backend policy. Parse all declared entries.
        if(n<3||p[0]!=4||p[1]==0||uint32_t(p[1])>(n-3)/21)return L2K_INVALID;
        const uint8_t* e=p+3;uint32_t port=read32(e+5);
        if(!e[0]||!port||port>65535||e[15]==0)return L2K_INVALID;
        reply[0]=2;write32(reply+1,c->login1);write32(reply+5,c->login2);reply[9]=e[0];
        result=l2k_login_seal(&c->bf,reply,10,out,cap);
        if(result>=0){c->server=e[0];std::memcpy(c->host,e+1,4);c->port=port;c->phase=4;}return result;
    }
    case 4:
        if(n<9||p[0]!=7)return L2K_INVALID;
        c->play1=read32(p+1);c->play2=read32(p+5);c->phase=5;return 0;
    }
    return L2K_PHASE;
}
