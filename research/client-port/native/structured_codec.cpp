#include "structured_codec.h"
#include <string.h>
namespace {
constexpr uint32_t MAX=65533;
uint32_t le(const uint8_t* p,unsigned k){uint32_t v=0;for(unsigned i=0;i<k;++i)v|=uint32_t(p[i])<<(i*8);return v;}
struct Reader {
    const uint8_t* p;uint32_t n,pos=1;
    bool take(uint32_t k){if(k>n-pos)return false;pos+=k;return true;}
    bool num(uint32_t& v,unsigned k=4){if(k>n-pos)return false;v=le(p+pos,k);pos+=k;return true;}
    bool str(){while(n-pos>=2){uint32_t c=le(p+pos,2);pos+=2;if(!c)return true;}return false;}
    bool format(const char* f){for(;*f;++f){if(*f=='S'){if(!str())return false;}else if(!take(*f=='c'?1:*f=='h'?2:(*f=='f'||*f=='Q')?8:4))return false;}return true;}
};
struct Writer {
    uint8_t* p;uint32_t pos=0;bool ok=true;
    void raw(const uint8_t* v,uint32_t n){if(n>MAX-pos){ok=false;return;}if(p)memcpy(p+pos,v,n);pos+=n;}
    void number(uint32_t v,unsigned n=4){if(n>MAX-pos){ok=false;return;}if(p)for(unsigned i=0;i<n;++i)p[pos+i]=uint8_t(v>>(8*i));pos+=n;}
    void zero(uint32_t n){if(n>MAX-pos){ok=false;return;}if(p)memset(p+pos,0,n);pos+=n;}
};
using Parser=bool(*)(Reader&,Writer&,bool);
bool shortcut(Reader& r,Writer& w,bool modern){
    uint32_t count=1;if(r.p[0]==0x45){if(!r.num(count)||count>(r.n-r.pos)/16)return false;w.raw(r.p,r.pos);}else w.raw(r.p,1);
    for(uint32_t i=0;i<count;++i){uint32_t start=r.pos,type;if(!r.num(type)||type<1||type>5||!r.take(4))return false;
        uint32_t rest=type==1?(modern?24:8):type==2?(modern?13:12):8;
        if(!r.take(rest))return false;
        if(modern||type>=3)w.raw(r.p+start,r.pos-start);
        else if(type==1){w.raw(r.p+start,16);w.number(0xffffffff);w.zero(12);} // no shared reuse group or augmentation
        else {w.raw(r.p+start,16);w.zero(1);w.raw(r.p+start+16,4);}
    }return r.pos==r.n;
}
bool multisell(Reader& r,Writer& w,bool modern){
    if(!r.take(16))return false;
    uint32_t count;if(!r.num(count)||count>(r.n-r.pos)/(modern?17:9))return false;w.raw(r.p,r.pos);
    for(uint32_t i=0;i<count;++i){uint32_t start=r.pos,products,ingredients;
        if(!r.take(modern?13:5)||!r.num(products,2)||!r.num(ingredients,2))return false;
        if(products>32767||ingredients>32767)return false;
        if(modern)w.raw(r.p+start,r.pos-start);else{w.raw(r.p+start,4);w.zero(8);w.raw(r.p+start+4,5);}
        for(unsigned list=0;list<2;++list){uint32_t n=list?ingredients:products,old=list?10:14,size=old+(modern?8:0);
            if(n>(r.n-r.pos)/size)return false;
            for(uint32_t j=0;j<n;++j){w.raw(r.p+r.pos,size);r.take(size);if(!modern)w.zero(8);}
        }
    }return r.pos==r.n;
}
bool gmclan(Reader& r,Writer& w,bool modern){
    uint32_t flag=0,clan,type=0;if(modern&&(!r.num(flag)||flag>1))return false;
    uint32_t gm=r.pos;if(!r.str())return false;uint32_t gmend=r.pos;
    if(!r.num(clan))return false;
    if(modern&&(!r.num(type)||(flag==0&&type!=0)))return false;
    uint32_t names=r.pos;if(!r.str())return false;bool named=r.pos>names+2;if(!r.str())return false;
    if(clan&&named){if(!r.take(36)||!r.str()||!r.take(8))return false;}
    uint32_t count;if(!r.num(count)||count>(r.n-r.pos)/(modern?26:22))return false;
    if(modern)w.raw(r.p,r.pos);else{w.raw(r.p,1);w.zero(4);w.raw(r.p+gm,gmend-gm+4);w.zero(4);w.raw(r.p+names,r.pos-names);}
    for(uint32_t i=0;i<count;++i){uint32_t start=r.pos;if(!r.str()||!r.take(modern?24:20))return false;w.raw(r.p+start,r.pos-start);if(!modern)w.zero(4);}
    return r.pos==r.n;
}
bool gmwarehouse(Reader& r,Writer& w,bool modern){
    uint32_t count;if(!r.str()||!r.take(4)||!r.num(count,2)||count>32767||count>(r.n-r.pos)/22)return false;
    w.raw(r.p,r.pos);
    for(uint32_t i=0;i<count;++i){uint32_t type,start=r.pos;if(!r.num(type,2)||!r.take(16))return false;
        if(type<4){if(!r.take(modern?18:10))return false;}
        uint32_t end=r.pos;if(!r.take(4))return false;
        w.raw(r.p+start,end-start);if(!modern&&type<4)w.zero(8);w.raw(r.p+end,4);
    }return r.pos==r.n;
}
bool character_selection(Reader& r,Writer& w,bool modern){
    uint32_t count;if(!r.num(count)||count>(r.n-r.pos)/280)return false;
    w.raw(r.p,r.pos);
    for(uint32_t i=0;i<count;++i){uint32_t start=r.pos;
        if(!r.format("SdSddddddddddff")||!r.take(4))return false;
        w.raw(r.p+start,r.pos-start);start=r.pos;
        if(!r.take(modern?8:4))return false;
        w.raw(r.p+start,r.pos-start);if(!modern)w.zero(4);
        start=r.pos;if(!r.take(44))return false;w.raw(r.p+start,44);
        for(unsigned group=0;group<2;++group){start=r.pos;if(!r.take(modern?68:64))return false;w.raw(r.p+start,r.pos-start);if(!modern)w.zero(4);}
        start=r.pos;if(!r.format(modern?"dddffdddchh":"dddffdddc"))return false;w.raw(r.p+start,r.pos-start);if(!modern)w.zero(4);
    }return r.pos==r.n;
}
// Quarantined: the live server's 281/289-byte variants do not match this model.
// Retain the draft for research; never route live CharacterSelected through it.
[[maybe_unused]] bool character_selected(Reader& r,Writer& w,bool modern){
    if(!r.format("SdSddddddddddff")||!r.take(4))return false;
    w.raw(r.p,r.pos);uint32_t start=r.pos;
    if(!r.take(modern?8:4))return false;
    w.raw(r.p+start,r.pos-start);if(!modern)w.zero(4);
    start=r.pos;if(!r.take(42*4))return false;
    uint32_t groups;if(!r.num(groups)||groups>MAX/16)return false;
    if(groups){uint32_t bytes;if(!r.num(bytes)||!r.take(bytes)||groups>(r.n-r.pos)/16||!r.take(groups*16))return false;}
    if(!r.take(20))return false;
    if(modern&&!r.take(72))return false;
    w.raw(r.p+start,r.pos-start);if(!modern)w.zero(72);
    return r.pos==r.n;
}
bool message(Reader& r,Writer& w,bool modern){
    uint32_t count;if(!r.take(4)||!r.num(count)||count>(r.n-r.pos)/4)return false;
    for(uint32_t i=0;i<count;++i){uint32_t tag;if(!r.num(tag))return false;
        if(tag==0){if(!r.str())return false;}
        else if(tag==1||tag==2||tag==3||tag==5){if(!r.take(4))return false;}
        else if(tag==4||(modern&&tag==6)||(modern&&tag==8&&r.p[0]==0x64)){if(!r.take(8))return false;}
        else if(modern&&tag==7){if(!r.take(12))return false;}
        else return false;
    }
    if(r.p[0]==0xed){if(modern){if(!r.take(8))return false;}else{w.raw(r.p,r.pos);w.zero(8);}}
    else w.raw(r.p,r.pos);
    return r.pos==r.n;
}
int parsed(const uint8_t* p,uint32_t n,uint8_t* out,uint32_t cap,Parser fn){
    Reader modern{p,n};Writer none{nullptr};if(fn(modern,none,true)&&none.ok)return 0;
    Reader old{p,n};Writer measure{nullptr};if(!fn(old,measure,false))return L2K_INVALID;
    if(!measure.ok||measure.pos>cap)return L2K_CAPACITY;
    Reader again{p,n};Writer output{out};if(!fn(again,output,false)||!output.ok)return L2K_INVALID;return int(output.pos);
}
int padded(const uint8_t* p,uint32_t n,uint8_t* out,uint32_t cap,uint32_t old,uint32_t extra){
    if(n==old+extra)return 0;
    if(n!=old)return L2K_INVALID;
    if(n+extra>cap||n+extra>MAX)return L2K_CAPACITY;
    memcpy(out,p,n);memset(out+n,0,extra);return int(n+extra);
}
int rows(const uint8_t* p,uint32_t n,uint8_t* out,uint32_t cap,uint32_t head,uint32_t old,uint32_t insert,bool mana){
    if(n<head)return L2K_INVALID;
    uint32_t count=le(p+head-2,2),size=old+8;
    if(count>32767||count>(MAX-head)/old)return L2K_INVALID;
    if(n==head+count*size)return 0;
    if(n!=head+count*old)return L2K_INVALID;
    if(head+count*size>cap||head+count*size>MAX)return L2K_CAPACITY;
    memcpy(out,p,head);
    for(uint32_t i=0;i<count;++i){const uint8_t* src=p+head+i*old;uint8_t* dst=out+head+i*size;
        memcpy(dst,src,insert);memset(dst+insert,0,8);if(mana)memset(dst+insert+4,0xff,4);memcpy(dst+insert+8,src+insert,old-insert);
    }return int(head+count*size);
}
}
L2K_API int l2k_structured_convert(const uint8_t* p,uint32_t n,uint8_t* out,uint32_t cap){
    if(!p||!out||p==out||!n||n>MAX)return L2K_INVALID;
    switch(p[0]){
    case 0x13:return parsed(p,n,out,cap,character_selection);
    case 0x15:return 0; // Preserve the previously working native world-entry path.
    case 0x29:return padded(p,n,out,cap,21,4);
    case 0x2a:return padded(p,n,out,cap,17,4);
    case 0xa6:return padded(p,n,out,cap,7,4);
    case 0x4c:return padded(p,n,out,cap,9,4);
    case 0xc5:return padded(p,n,out,cap,29,4);
    case 0xc7:return padded(p,n,out,cap,41,4);
    case 0xcd:return padded(p,n,out,cap,25,4);
    case 0xf3:return padded(p,n,out,cap,21,8);
    case 0x41:case 0x42:return rows(p,n,out,cap,9,32,32,false);
    case 0x94:{Reader r{p,n};if(!r.str())return L2K_INVALID;return rows(p,n,out,cap,r.pos+8,28,28,true);}
    case 0x95:return parsed(p,n,out,cap,gmwarehouse);
    case 0x44:case 0x45:return parsed(p,n,out,cap,shortcut);
    case 0x64:case 0xed:return parsed(p,n,out,cap,message);
    case 0xd0:return parsed(p,n,out,cap,multisell);
    case 0x90:return parsed(p,n,out,cap,gmclan);
    case 0x32:{Reader r{p,n};if(!r.take(4)||!r.str())return L2K_INVALID;uint32_t end=r.pos;
        if(end==n)return padded(p,n,out,cap,n,4);
        uint32_t type;if(!r.num(type))return L2K_INVALID;if(type&&!r.str())return L2K_INVALID;return r.pos==n?0:L2K_INVALID;}
    case 0x16:{Reader r{p,n};if(!r.format("ddddddddddddddddddffffdddcccccSSddddddddccffd"))return L2K_INVALID;return padded(p,n,out,cap,r.pos,4);}
    case 0xb1:{const char* prefix="dddddddddddddddddddffffdddcccccSSddddddddddd";Reader r{p,n};if(!r.format(prefix))return L2K_INVALID;uint32_t at=r.pos;
        Reader modern=r;if(modern.format("QQQddddddddddddddccdd")&&modern.pos==n)return 0;
        if(!r.format("dddddddddddddddddccdd")||r.pos!=n)return L2K_INVALID;
        if(n+12>cap||n+12>MAX)return L2K_CAPACITY;
        memcpy(out,p,at);
        for(unsigned i=0;i<3;++i){memcpy(out+at+i*8,p+at+i*4,4);memset(out+at+i*8+4,0,4);}memcpy(out+at+24,p+at+12,n-at-12);return int(n+12);}
    case 0xfe:{if(n<3)return L2K_INVALID;if(le(p+1,2)!=0x27)return 0;Reader r{p,n,3};if(!r.str())return L2K_INVALID;return padded(p,n,out,cap,r.pos,4);}
    default:return 0;
    }
}
