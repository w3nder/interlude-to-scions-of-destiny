#include "clan_codec.h"
#include <string.h>
namespace {
struct Cursor {
    const uint8_t* p;uint32_t n,pos=1;
    bool skip(uint32_t k){if(k>n-pos)return false;pos+=k;return true;}
    bool string(){while(n-pos>=2){uint16_t c=p[pos]|uint16_t(p[pos+1])<<8;pos+=2;if(!c)return true;}return false;}
    bool dword(uint32_t& v){if(n-pos<4)return false;v=uint32_t(p[pos])|uint32_t(p[pos+1])<<8|uint32_t(p[pos+2])<<16|uint32_t(p[pos+3])<<24;pos+=4;return true;}
};
struct Layout {uint32_t members,rows;};
bool all(const uint8_t* p,uint32_t n,bool interlude,Layout& result){
    Cursor c{p,n};uint32_t count;
    if(interlude){uint32_t main_or_sub,clan_id,pledge_type;
        if(!c.dword(main_or_sub)||!c.dword(clan_id)||!c.dword(pledge_type)||main_or_sub>1||!clan_id||(main_or_sub==0 && pledge_type!=0))return false;
    }else if(!c.skip(4))return false;
    if(!c.string()||!c.string()||!c.skip(36)||!c.string()||!c.skip(8)||!c.dword(count))return false;
    result={count,c.pos};uint32_t fixed=interlude?24:20;
    if(count>(n-c.pos)/(fixed+2))return false;
    for(uint32_t i=0;i<count;++i)if(!c.string()||!c.skip(fixed))return false;
    return c.pos==n;
}
}
L2K_API int l2k_clan_convert(const uint8_t* p,uint32_t n,uint8_t* out,uint32_t cap){
    if(!p||!out||p==out||!n||n>65533)return L2K_INVALID;
    uint8_t op=p[0];if(op!=0x53&&op!=0x54&&op!=0x55)return 0;
    if(op==0x53){
        Layout source{},target{};bool old=all(p,n,false,source),modern=all(p,n,true,target);
        if(modern)return 0; // Never expand a packet already understood by Interlude.
        if(!old)return L2K_INVALID;
        uint32_t required=n+8+4*source.members;if(required>cap||required>65533)return L2K_CAPACITY;
        out[0]=op;memset(out+1,0,4);memcpy(out+5,p+1,4);memset(out+9,0,4);
        // Main clan=0, pledge type=0; shared header kept byte for byte.
        memcpy(out+13,p+5,source.rows-5);uint32_t dst=source.rows+8;
        Cursor c{p,n,source.rows};
        for(uint32_t i=0;i<source.members;++i){uint32_t start=c.pos;c.string();c.skip(20);uint32_t length=c.pos-start;memcpy(out+dst,p+start,length);dst+=length;memset(out+dst,0,4);dst+=4;}
        return (int)dst; // Added member field: sponsor/apprentice flag=0.
    }
    Cursor c{p,n};if(!c.string())return L2K_INVALID;
    uint32_t extra=op==0x54?8:4;
    if(n-c.pos==20+extra)return 0;
    if(n-c.pos!=20)return L2K_INVALID;
    if(n+extra>cap||n+extra>65533)return L2K_CAPACITY;
    memcpy(out,p,n);memset(out+n,0,extra);return (int)(n+extra);
}
