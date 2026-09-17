#include "schema_codec.h"
#include <string.h>
namespace {
uint32_t d(const uint8_t* p){return uint32_t(p[0])|(uint32_t(p[1])<<8)|(uint32_t(p[2])<<16)|(uint32_t(p[3])<<24);}
uint32_t string_end(const uint8_t* p,uint32_t n,uint32_t at){
    while(at+1<n){if(!p[at]&&!p[at+1])return at+2;at+=2;}return 0;
}
int copy_pad(const uint8_t* p,uint32_t n,uint8_t* out,uint32_t cap,uint32_t extra){
    if(n+extra>cap||n+extra>65533)return L2K_CAPACITY;
    memcpy(out,p,n);memset(out+n,0,extra);return int(n+extra);
}
}
L2K_API int l2k_schema_convert(const uint8_t* p,uint32_t n,uint8_t* out,uint32_t cap){
    if(!p||!n||n>65533||!out||p==out)return L2K_INVALID;
    uint32_t head=1,oldrow=0,newrow=0;
    if(p[0]==0x1b||p[0]==0x27){
        head=p[0]==0x1b?5:3;oldrow=p[0]==0x1b?28:30;newrow=oldrow+8;
        if(n<head)return L2K_INVALID;
        uint32_t count=p[head-2]|uint32_t(p[head-1])<<8;
        if(count>(65533-head)/oldrow)return L2K_INVALID;
        if(n==head+count*newrow)return 0;
        if(n!=head+count*oldrow)return L2K_INVALID;
        uint32_t size=head+count*newrow;if(size>cap||size>65533)return L2K_CAPACITY;
        memcpy(out,p,head);
        for(uint32_t i=0;i<count;++i){
            uint8_t* row=out+head+i*newrow;memcpy(row,p+head+i*oldrow,oldrow);
            memset(row+oldrow,0,4); // No augmentation on C4 items.
            memset(row+oldrow+4,0xff,4); // No shadow-item lifetime (-1).
        }
        return int(size);
    }
    if(p[0]==0x58||p[0]==0x91){
        if(p[0]==0x91){head=string_end(p,n,1);if(!head)return L2K_INVALID;}
        oldrow=12;newrow=13; // C4 has no per-skill disabled flag.
    }else if(p[0]==0xfe){
        if(n<3)return L2K_INVALID;
        uint32_t sub=p[1]|uint32_t(p[2])<<8;head=3;
        uint32_t oldsize=0,extra=0;
        if(sub==0x13){oldsize=23;extra=2;} // No night lure or ranking UI.
        if(sub==0x15){oldsize=17;extra=1;} // No deceptive fishing mode.
        if(sub==0x16){oldsize=22;extra=1;} // Normal HP bar.
        if(oldsize){if(n==oldsize+extra)return 0;if(n!=oldsize)return L2K_INVALID;return copy_pad(p,n,out,cap,extra);}
        if(sub==0x18){
            // id, level, SP, XP, success rate, requirement count, 4-dword requirements.
            if(n>=31&&(n-31)%16==0&&d(p+27)==(n-31)/16)return 0;
            if(n<27||(n-27)%16!=0||d(p+23)!=(n-27)/16)return L2K_INVALID;
            if(n+4>cap||n+4>65533)return L2K_CAPACITY;
            memcpy(out,p,19);memset(out+19,0,4);memcpy(out+23,p+19,n-19);return int(n+4);
        }
        if(sub==0x17){oldrow=16;newrow=20;} // XP cost expands from unsigned dword to qword.
        else return 0;
    }else if(p[0]==0xb5){
        head=string_end(p,n,21);if(!head)return L2K_INVALID;
        if(n==head+52)return 0;
        if(n!=head+40)return L2K_INVALID;
        if(n+12>cap||n+12>65533)return L2K_CAPACITY;
        memcpy(out,p,head+28);
        for(uint32_t i=0;i<3;++i){memcpy(out+head+28+i*8,p+head+28+i*4,4);memset(out+head+32+i*8,0,4);}
        return int(n+12);
    }else return 0;
    if(n<head+4)return L2K_INVALID;
    uint32_t count=d(p+head);head+=4;
    if(count>(65533-head)/oldrow)return L2K_INVALID;
    if(n==head+count*newrow)return 0;
    if(n!=head+count*oldrow)return L2K_INVALID;
    uint32_t size=head+count*newrow;if(size>cap||size>65533)return L2K_CAPACITY;
    memcpy(out,p,head);
    for(uint32_t i=0;i<count;++i){memcpy(out+head+i*newrow,p+head+i*oldrow,oldrow);memset(out+head+i*newrow+oldrow,0,newrow-oldrow);}
    return int(size);
}
