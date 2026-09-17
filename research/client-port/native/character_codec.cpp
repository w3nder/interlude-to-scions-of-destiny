#include "character_codec.h"
#include "asset_codec.h"
#include <string.h>
namespace {
struct Copy {
 const uint8_t* p;uint8_t* out;uint32_t in=1,pos=1;
 void raw(uint32_t n){if(out)memcpy(out+pos,p+in,n);in+=n;pos+=n;}
 void zero(uint32_t n){if(out)memset(out+pos,0,n);pos+=n;}
 void number(uint32_t v){if(out)for(unsigned i=0;i<4;++i)out[pos+i]=uint8_t(v>>(i*8));pos+=4;}
 void str(){uint32_t start=in;while(p[in]||p[in+1])in+=2;in+=2;uint32_t n=in-start;in=start;raw(n);}
 void fmt(const char* f){for(;*f;++f)if(*f=='S')str();else raw(*f=='c'?1:*f=='h'?2:*f=='f'||*f=='Q'?8:4);}
};
uint32_t convert(const uint8_t* p,uint32_t n,uint8_t* out){
 Copy c{p,out};if(out)out[0]=p[0];c.raw(20);c.str();
 if(p[0]==0x04){
  c.raw(16);c.raw(4);c.zero(4); // zero-extend C4 experience to Q
  c.raw(56);c.raw(64);c.zero(4);c.raw(64);c.zero(4);c.zero(68); // new face slots + augmentation
  c.fmt("ddddddddddddddddddddffffddddSdddddcccddh");
  uint32_t cubes=p[c.in-2]|uint32_t(p[c.in-1])<<8;c.raw(cubes*2);c.fmt("cdc");
  // Preserve the four legacy UI flags consumed by User::SetPledgePower.
  // Exact C4 bits 0,1,3,10 become Interlude bits 1,2,7,5.
  // Other Interlude permissions have no flag in the C4 User handler.
  uint32_t permissions=((p[c.in]&1)?2u:0u)|((p[c.in]&2)?4u:0u)|
      ((p[c.in]&8)?128u:0u)|((p[c.in+1]&4)?32u:0u);
  c.in+=32;c.number(permissions);c.raw(n-c.in);
  c.zero(1);c.number(0);c.number(0);c.number(0xffffff);c.number(0);
 }else{
  c.raw(12);c.raw(44);c.zero(4);c.zero(48);c.raw(n-c.in);
  // Interlude-only clan rank/type, title color, cursed weapon/reputation fields.
  c.zero(12);c.number(0xffffff);c.zero(8);
 }
 return c.pos;
}
}
L2K_API int l2k_character_convert(const uint8_t* p,uint32_t n,uint8_t* out,uint32_t cap){
 if(!p||!n||n>65533||!out||p==out)return L2K_INVALID;
 if(p[0]!=0x03&&p[0]!=0x04)return 0;
 // Reuse the bounded, complete layout recognizer. Unknown/hybrid variants
 // retain their existing path; never guess offsets or reject world entry.
 L2KAssetRecord records[32];int count=l2k_asset_inspect(p,n,records,32);
 if(count<=0||records[0].variant!=4)return 0;
 uint32_t need=convert(p,n,nullptr);
 if(need>cap||need>65533)return L2K_CAPACITY;
 convert(p,n,out);
 L2KAssetRecord check[32];int result=l2k_asset_inspect(out,need,check,32);
 if(result<=0||check[0].variant!=6)return L2K_INVALID;
 return int(need);
}
