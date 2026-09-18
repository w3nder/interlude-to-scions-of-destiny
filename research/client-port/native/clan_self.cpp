#include "clan_self.h"
#include <string.h>
namespace {
uint32_t get(const uint8_t* p){return uint32_t(p[0])|uint32_t(p[1])<<8|uint32_t(p[2])<<16|uint32_t(p[3])<<24;}
void put(uint8_t* p,uint32_t v){for(unsigned i=0;i<4;++i)p[i]=uint8_t(v>>(8*i));}
struct R {
 const uint8_t* p;uint32_t n,pos=1;
 bool skip(uint32_t k){if(pos>n||k>n-pos)return false;pos+=k;return true;}
 bool num(uint32_t& v){if(!skip(4))return false;v=get(p+pos-4);return true;}
 bool str(uint16_t* out=nullptr){for(unsigned i=0;i<64;++i){if(!skip(2))return false;uint16_t c=p[pos-2]|uint16_t(p[pos-1])<<8;if(out)out[i]=c;if(!c)return true;}return false;}
};
bool same(const uint16_t* a,const uint16_t* b){for(unsigned i=0;i<64;++i){if(a[i]!=b[i])return false;if(!a[i])return true;}return false;}
}
L2K_API uint32_t l2k_clan_self_size(){return sizeof(L2KClanSelf);}
L2K_API void l2k_clan_self_reset(L2KClanSelf* s){if(s)memset(s,0,sizeof(*s));}
L2K_API int l2k_clan_self_receive(L2KClanSelf* state,const uint8_t* p,uint32_t n,
                                uint32_t legacy,uint8_t* out,uint32_t cap){
 if(!state||!p||!n||n>65533||!out||p==out)return L2K_INVALID;
 const auto before=*state;auto& s=*state;R r{p,n};bool changed=false;
 if(p[0]==0x15){
  l2k_clan_self_reset(&s);
  if(!r.str(s.name)||!r.num(s.id)||!s.name[0])l2k_clan_self_reset(&s);
  return 0; // Identity observation only; world-entry bytes remain untouched.
 }
 if(p[0]==0x82){if(n==1)s.eligible=s.present=s.owned=0;return 0;}
 if(p[0]==0x04){
  uint16_t name[64]={};uint32_t id,race,sex,klass,level;
  // The prefix through level is identical in both engines, including hybrid
  // packets whose later equipment/experience layout we do not rewrite.
  if(!r.skip(16)||!r.num(id)||!r.str(name)||!r.num(race)||!r.num(sex)||!r.num(klass)||!r.num(level))return 0;
  if(!s.id||!id||!same(name,s.name)||race>4||sex>1||!level||level>255)return 0;
  // CharacterSelected carries a different identifier on the live C4 server.
  // UserInfo is authoritative for the in-world object ID; the name must match.
  changed=!s.ready||s.id!=id||s.race!=race||s.sex!=sex||s.klass!=klass||s.level!=level;
  s.id=id;s.race=race;s.sex=sex;s.klass=klass;s.level=level;s.ready=1;
 }else if(p[0]==0x53){
  uint32_t main,clan,type,count;bool found=false;
  if(!r.num(main)||!r.num(clan)||!r.num(type)||main||!clan||type||!r.str()||!r.str()||!r.skip(36)||!r.str()||!r.skip(8)||!r.num(count))return 0;
  if(count>(n-r.pos)/26)return 0;
  for(uint32_t i=0;i<count;++i){uint16_t name[64]={};uint32_t id;
   if(!r.str(name)||!r.skip(16)||!r.num(id)||!r.skip(4))return 0;
   if((s.ready&&s.id&&id==s.id)||(s.name[0]&&same(name,s.name)))found=true;
  }
  if(r.pos!=n)return 0;
  s.eligible=legacy!=0;s.present=found;s.owned=0;
 }else if(p[0]==0x54||p[0]==0x55||p[0]==0x56){
  uint16_t name[64]={};if(!r.str(name))return 0;
  if(p[0]!=0x56&&!r.skip(p[0]==0x54?28:24))return 0;
  if(r.pos!=n||!same(name,s.name))return 0;
  if(p[0]==0x56)s.eligible=s.present=s.owned=0;
  else{s.present=1;s.owned=0;}
  return 0;
 }else return 0;
 if(!s.eligible||!s.ready||!s.id||!s.name[0]||(s.present&&(!s.owned||!changed)))return 0;
 unsigned units=0;while(units<64&&s.name[units])++units;
 const bool update=s.present!=0;uint32_t need=1+2*(units+1)+(update?28:24);
 if(need>cap){s=before;return L2K_CAPACITY;}
 out[0]=update?0x54:0x55;uint32_t pos=1;
 for(unsigned i=0;i<=units;++i){out[pos++]=uint8_t(s.name[i]);out[pos++]=uint8_t(s.name[i]>>8);}
 const uint32_t values[]={s.level,s.klass,s.sex,s.race,s.id,0u};
 for(uint32_t v:values){put(out+pos,v);pos+=4;}
 if(update){put(out+pos,0);pos+=4;}
 s.present=s.owned=1;return int(pos);
}
