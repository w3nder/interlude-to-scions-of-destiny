#include "asset_codec.h"
namespace {
uint32_t get(const uint8_t* p,unsigned n=4){uint32_t v=0;for(unsigned i=0;i<n;++i)v|=uint32_t(p[i])<<(8*i);return v;}
struct R{const uint8_t* p;uint32_t n,pos=1;
 bool take(uint32_t k){if(k>n-pos)return false;pos+=k;return true;}
 bool str(){while(n-pos>=2){uint32_t v=get(p+pos,2);pos+=2;if(!v)return true;}return false;}
 bool fmt(const char* f){for(;*f;++f)if(*f=='S'){if(!str())return false;}else if(!take(*f=='c'?1:*f=='h'?2:*f=='f'||*f=='Q'?8:4))return false;return true;}
};
bool character(R& r,bool modern,bool user,uint32_t& equipment,unsigned& slots){
 if(!r.take(20)||!r.str())return false;
 if(user){
  if(!r.take(16+(modern?8:4)+56+(modern?68:64)))return false;
  equipment=r.pos;slots=modern?17:16;
  if(!r.take(slots*4)|| (modern&&!r.take(68)) ||!r.fmt("ddddddddddddddddddddffffddddSdddddcccddh"))return false;
 }else{
  if(!r.take(12))return false;
  equipment=r.pos;slots=modern?12:11;
  if(!r.take(slots*4)||(modern&&!r.take(48))||!r.fmt("ddddddddddddddffffdddSdddddccccccch"))return false;
 }
 uint32_t cubes=get(r.p+r.pos-2,2);if(cubes>32767||!r.take(cubes*2))return false;
 if(user){
  if(!r.fmt("cdc")||!r.take(modern?4:32)||!r.fmt("hhdhddddccdcccdddd"))return false;
  if(modern&&!r.fmt("cdddd"))return false;
 }else{
  if(!r.fmt("cdchdddccdcccdddd"))return false;
  if(modern&&!r.take(24))return false;
 }
 return r.pos==r.n;
}
}
L2K_API int l2k_asset_inspect(const uint8_t* p,uint32_t n,L2KAssetRecord* out,uint32_t cap){
 if(!p||!n||n>65533||!out||!cap)return L2K_INVALID;
 if(p[0]==0x1b||p[0]==0x27){
  uint32_t head=p[0]==0x1b?5:3,change=p[0]==0x27?2:0;
  if(n<head)return L2K_INVALID;
  uint32_t count=get(p+head-2,2),stride=28+change,variant=4;
  if(n==head+count*(stride+8)){stride+=8;variant=6;}else if(n!=head+count*stride)return L2K_INVALID;
  uint32_t num=count<cap?count:cap;
  for(uint32_t i=0;i<num;++i){const uint8_t* row=p+head+i*stride+change;
   out[i]={1,get(row+6),get(row+10),get(row+18,2),get(row+20),i,get(row+24,2),variant,get(row,2)};}
  return int(num);
 }
 if(p[0]==0x16){
  R r{p,n};if(!r.fmt("ddddddddddddddddddffffdddcccccSSddddddddccffd"))return L2K_INVALID;
  uint32_t variant=n==r.pos?4:n==r.pos+4?6:0;if(!variant)return L2K_INVALID;
  uint32_t raw=get(p+5);out[0]={2,raw>=1000000?raw-1000000:raw,0,0,0,0,0,variant,0};return 1;
 }
 if(p[0]==0x03||p[0]==0x04){
  bool user=p[0]==0x04;R old{p,n},modern{p,n};uint32_t a=0,b=0;unsigned as=0,bs=0;
  bool va=character(old,false,user,a,as),vb=character(modern,true,user,b,bs);
  if(va==vb)return L2K_INVALID; // No ambiguous or guessed ID offsets.
  uint32_t at=vb?b:a,slots=vb?bs:as,num=slots<cap?slots:cap;
  for(uint32_t i=0;i<num;++i)out[i]={user?3u:4u,get(p+at+4*i),0,0,0,i,0,vb?6u:4u,0};
  return int(num);
 }
 return 0;
}
