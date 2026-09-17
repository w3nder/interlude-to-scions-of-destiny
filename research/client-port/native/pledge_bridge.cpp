#include "pledge_bridge.h"
#include <string.h>

namespace {
enum { CLOSED,LIST,WAIT_VIEW,WAIT_EDIT,VIEW,EDIT,SENT };
constexpr uint32_t TIMEOUT=15000;
uint32_t get(const uint8_t* p){return uint32_t(p[0])|(uint32_t(p[1])<<8)|(uint32_t(p[2])<<16)|(uint32_t(p[3])<<24);}
void put(uint8_t* p,uint32_t x){for(unsigned i=0;i<4;++i)p[i]=uint8_t(x>>(i*8));}
bool equal(const uint16_t* a,const uint16_t* b){for(unsigned i=0;i<64;++i){if(a[i]!=b[i])return false;if(!a[i])return true;}return false;}
struct Reader {
    const uint8_t* p;uint32_t n,pos;
    bool skip(uint32_t k){if(pos>n||k>n-pos)return false;pos+=k;return true;}
    bool number(uint32_t& v){if(pos>n||n-pos<4)return false;v=get(p+pos);pos+=4;return true;}
    bool name(uint16_t* out){
        for(unsigned i=0;i<64;++i){if(pos>n||n-pos<2)return false;uint16_t c=p[pos]|uint16_t(p[pos+1])<<8;pos+=2;if(out)out[i]=c;if(!c)return true;}
        return false;
    }
};
bool leader(const L2KPledgeState& s){return s.clan&&s.self_id&&s.self_name[0]&&equal(s.self_name,s.leader);}
void close(L2KPledgeState& s){s.phase=CLOSED;s.selected_id=0;s.selected_name[0]=0;memset(s.rights,0,32);memset(s.original,0,32);++s.nonce;}
bool selected_online(const L2KPledgeState& s){
    if(s.selected_id==s.self_id&&equal(s.selected_name,s.self_name))return s.self_id!=0;
    for(uint32_t i=0;i<s.count;++i)if(s.members[i].id==s.selected_id&&s.selected_id&&equal(s.members[i].name,s.selected_name))return true;
    return false;
}
struct Html {
    L2KPledgeResult& r;uint32_t pos=5;bool ok=true;
    void unit(uint16_t c){if(pos+2>sizeof(r.display)-4){ok=false;return;}r.display[pos++]=uint8_t(c);r.display[pos++]=uint8_t(c>>8);}
    void text(const char* p){for(;*p;++p)unit(uint8_t(*p));}
    void escaped(const uint16_t* p){for(unsigned i=0;i<64&&p[i];++i){switch(p[i]){case '&':text("&amp;");break;case '<':text("&lt;");break;case '>':text("&gt;");break;case '"':text("&quot;");break;case '\'':text("&#39;");break;default:unit(p[i]);}}}
    void number(uint32_t value){char digits[10];unsigned n=0;do{digits[n++]=char('0'+value%10);value/=10;}while(value);while(n)unit(uint8_t(digits[--n]));}
    void begin_link(uint32_t nonce,char action,uint32_t arg){text("<a action=\"bypass -h l2k_priv_");number(nonce);unit('_');unit(uint8_t(action));unit('_');number(arg);text("\">");}
    void link(uint32_t nonce,char action,uint32_t arg,const char* label){begin_link(nonce,action,arg);text(label);text("</a>");}
    void finish(){text("</body></html>");unit(0);if(ok){r.display[0]=0x0f;put(r.display+1,0);put(r.display+pos,0);r.display_size=pos+4;}}
};
void render(L2KPledgeState& s,L2KPledgeResult& r,const char* message=nullptr,uint32_t page=0){
    ++s.nonce;if(!s.nonce)++s.nonce;
    Html h{r};h.text("<html><body><center>Permissoes do Clan</center><br>");
    if(message){h.text(message);h.text("<br><br>");}
    if(s.phase==LIST){
        h.text("Selecione um membro online:<br>");
        // Six rows per page keep the native NPC HTML below its size limit.
        uint32_t begin=page*6;if(page>85||begin>=s.count){begin=0;page=0;}
        for(uint32_t i=begin;i<s.count&&i<begin+6;++i){
            if(!s.members[i].id)continue;
            h.begin_link(s.nonce,'V',i);h.escaped(s.members[i].name);h.text("</a><br>");
        }
        if(begin)h.link(s.nonce,'L',page-1,"Anterior");
        if(begin+6<s.count){h.text(" ");h.link(s.nonce,'L',page+1,"Proxima");}
        h.text("<br>");h.link(s.nonce,'V',512,"Minhas permissoes");
    }else if(s.selected_id){
        h.escaped(s.selected_name);h.text("<br><br>");
        if(s.phase==WAIT_VIEW||s.phase==WAIT_EDIT)h.text("Aguardando resposta do servidor.<br>");
        else if(s.phase==VIEW||s.phase==EDIT||s.phase==SENT){
            const char* labels[]={"Convidar para o clan","Dar titulo","Ver warehouse","Gerenciar crest","Clan hall: entrada","Clan hall: outros direitos","Clan hall: dispensar","Castelo: abrir portas","Castelo: outros direitos","Castelo: dispensar","Guerra de clan"};
            for(unsigned i=0;i<11;++i){
                const bool enabled=(s.rights[i/8]&(1u<<(i%8)))!=0;
                if(s.phase==EDIT)h.link(s.nonce,'T',i,enabled?"[x]":"[ ]");else h.text(enabled?"[x]":"[ ]");
                h.text(" ");h.text(labels[i]);h.text("<br>");
            }
            h.text("<br>");if(s.phase==EDIT){h.link(s.nonce,'A',0,"Aplicar");h.text(" | ");}
        }
        h.link(s.nonce,'R',0,"Recarregar");h.text(" | ");h.link(s.nonce,'L',0,"Membros");
    }else h.link(s.nonce,'L',0,"Membros");
    h.finish();
}
void query(L2KPledgeState& s,uint32_t now,L2KPledgeResult& r){
    if(!s.clan||!selected_online(s)){close(s);s.phase=LIST;render(s,r,"O membro precisa estar online.");return;}
    const bool edit=leader(s);
    if(!edit&&s.selected_id!=s.self_id){close(s);s.phase=LIST;render(s,r,"Somente o lider altera permissoes de outros membros.");return;}
    r.server[0]=0xc0;put(r.server+1,s.selected_id);put(r.server+5,edit?2:1);r.server_size=9;
    s.phase=edit?WAIT_EDIT:WAIT_VIEW;s.since=now;s.pending=1;render(s,r);
}
bool roster_header(Reader& r,uint32_t& clan,uint32_t& count,uint16_t* lead){
    uint32_t main,type;if(!r.number(main)||!r.number(clan)||!r.number(type)||main||type||!clan)return false;
    return r.name(nullptr)&&r.name(lead)&&r.skip(36)&&r.name(nullptr)&&r.skip(8)&&r.number(count)&&count<=512;
}
bool command(const uint8_t* p,uint32_t n,uint32_t start,uint32_t& nonce,char& action,uint32_t& arg){
    Reader r{p,n,start};uint16_t text[64]={};if(!r.name(text)||r.pos!=n)return false;
    const char prefix[]="l2k_priv_";unsigned at=0;for(;at<sizeof(prefix)-1;++at)if(text[at]!=uint8_t(prefix[at]))return false;
    auto number=[&](uint32_t& v){v=0;unsigned start=at;while(at<63&&text[at]>='0'&&text[at]<='9'){unsigned d=text[at++]-'0';if(v>(0xffffffffu-d)/10)return false;v=v*10+d;}return at!=start;};
    if(!number(nonce)||text[at++]!='_'||at>=63)return false;
    action=char(text[at++]);
    return text[at++]=='_'&&number(arg)&&text[at]==0;
}
uint32_t local_prefix(const uint8_t* p,uint32_t n){
    uint32_t start=1;
    // Accommodate HTML dispatchers that preserve the optional hidden flag;
    // neither form of our local command may reach the C4 server.
    if(n>=7&&p[1]=='-'&&!p[2]&&p[3]=='h'&&!p[4]&&p[5]==' '&&!p[6])start=7;
    const char prefix[]="l2k_priv_";
    if(n<start+2*(sizeof(prefix)-1))return 0;
    for(unsigned i=0;i<sizeof(prefix)-1;++i)if(p[start+2*i]!=uint8_t(prefix[i])||p[start+2*i+1])return 0;
    return start;
}
}

L2K_API uint32_t l2k_pledge_state_size(){return sizeof(L2KPledgeState);}
L2K_API void l2k_pledge_reset(L2KPledgeState* s){if(!s)return;uint32_t nonce=s->nonce+1;memset(s,0,sizeof(*s));s->nonce=nonce?nonce:1;}
L2K_API int l2k_pledge_receive(L2KPledgeState* state,const uint8_t* p,uint32_t n,uint32_t now,L2KPledgeResult* out){
    if(!state||!p||!n||n>65533||!out)return L2K_INVALID;
    (void)now;
    out->server_size=out->display_size=0;auto& s=*state;
    if(p[0]==0x15){ // Observe identity only; never change the working world-entry packet.
        l2k_pledge_reset(&s);Reader r{p,n,1};if(!r.name(s.self_name)||!r.number(s.self_id)){s.self_id=0;s.self_name[0]=0;}return 0;
    }
    if(p[0]==0x82){if(n==1){s.count=s.clan=0;s.leader[0]=0;close(s);}return 0;}
    if(p[0]==0x53){
        Reader r{p,n,1};uint32_t clan,count;uint16_t lead[64]={};
        if(!roster_header(r,clan,count,lead))return 0;
        uint32_t start=r.pos;
        for(uint32_t i=0;i<count;++i)if(!r.name(nullptr)||!r.skip(24))return 0;
        if(r.pos!=n)return 0;
        close(s);s.clan=clan;s.count=count;memcpy(s.leader,lead,sizeof(lead));r.pos=start;
        for(uint32_t i=0;i<count;++i){r.name(s.members[i].name);r.skip(16);r.number(s.members[i].id);r.skip(4);}return 0;
    }
    if(p[0]==0x54||p[0]==0x55||p[0]==0x56){
        Reader r{p,n,1};uint16_t name[64]={};uint32_t id=0;
        if(!r.name(name))return 0;
        if(p[0]!=0x56&&(!r.skip(16)||!r.number(id)||!r.skip(p[0]==0x54?8:4)))return 0;
        if(r.pos!=n)return 0;
        uint32_t i=0;while(i<s.count&&!equal(name,s.members[i].name))++i;
        if(p[0]==0x56){if(i<s.count){s.members[i]=s.members[--s.count];}if(equal(name,s.selected_name))close(s);}
        else if(i<512){if(i==s.count)++s.count;memcpy(s.members[i].name,name,sizeof(name));s.members[i].id=id;if(equal(name,s.selected_name)&&id!=s.selected_id)close(s);}
        // A changed list invalidates links whose numeric row may now differ.
        ++s.nonce;return 0;
    }
    if(p[0]==0x30&&n==41){
        // Exact C4 UI ignores the first two dwords. Only our single outstanding
        // member query can consume this legacy 32-byte response.
        if(s.pending&&(s.phase==WAIT_VIEW||s.phase==WAIT_EDIT)&&selected_online(s)){
            bool edit=s.phase==WAIT_EDIT&&leader(s);memcpy(s.rights,p+9,32);memcpy(s.original,p+9,32);s.phase=edit?EDIT:VIEW;render(s,*out);
        }
        s.pending=0;
        return 1; // Never feed a legacy bitset into the Interlude rank-mask UI.
    }
    return 0;
}
L2K_API int l2k_pledge_send(L2KPledgeState* state,const uint8_t* p,uint32_t n,uint32_t now,L2KPledgeResult* out){
    if(!state||!p||!n||n>65533||!out)return L2K_INVALID;
    out->server_size=out->display_size=0;auto& s=*state;
    // C4's UI ignores the response header, so a timeout must never allow a
    // second member query to overtake an outstanding uncorrelated response.
    bool waiting=s.pending!=0;
    if(p[0]==0xc0||(p[0]==0xd0&&n>=3&&p[2]==0&&(p[1]==0x1a||p[1]==0x1b))){
        if(waiting){render(s,*out,uint32_t(now-s.since)>TIMEOUT?"O servidor ainda nao respondeu. Nenhuma nova consulta foi enviada.":nullptr);return 1;}
        if(p[0]==0xd0&&p[1]==0x1b){
            Reader r{p,n,3};uint32_t type;uint16_t name[64]={};
            if(r.number(type)&&!type&&r.name(name)&&r.pos==n){
                if(equal(name,s.self_name)){s.selected_id=s.self_id;memcpy(s.selected_name,name,sizeof(name));query(s,now,*out);return 1;}
                for(uint32_t i=0;i<s.count;++i)if(equal(name,s.members[i].name)){s.selected_id=s.members[i].id;memcpy(s.selected_name,name,sizeof(name));query(s,now,*out);return 1;}
            }
        }
        close(s);s.phase=LIST;render(s,*out,s.clan?"Permissoes por membro.":"A lista do clan ainda nao esta disponivel.");return 1;
    }
    const uint32_t start=p[0]==0x21?local_prefix(p,n):0;
    if(!start)return 0;
    uint32_t nonce,arg;char action;if(!command(p,n,start,nonce,action,arg)||nonce!=s.nonce)return 1;
    if(waiting){render(s,*out);return 1;}
    switch(action){
    case 'L':close(s);s.phase=LIST;render(s,*out,nullptr,arg);break;
    case 'V':
        if(arg==512){s.selected_id=s.self_id;memcpy(s.selected_name,s.self_name,sizeof(s.self_name));}
        else if(arg<s.count){s.selected_id=s.members[arg].id;memcpy(s.selected_name,s.members[arg].name,sizeof(s.selected_name));}
        else break;
        query(s,now,*out);break;
    case 'R':if(s.selected_id)query(s,now,*out);break;
    case 'T':if(s.phase==EDIT&&arg<11&&leader(s)&&selected_online(s)){s.rights[arg/8]^=uint8_t(1u<<(arg%8));render(s,*out);}break;
    case 'A':
        if(s.phase==EDIT&&leader(s)&&selected_online(s)){
            if(!memcmp(s.rights,s.original,32)){render(s,*out,"Nenhuma alteracao.");break;}
            out->server[0]=0xc0;put(out->server+1,s.selected_id);put(out->server+5,3);memcpy(out->server+9,s.rights,32);out->server_size=41;
            s.phase=SENT;render(s,*out,"Pedido enviado. Recarregue para conferir a resposta do servidor.");
        }break;
    default:break;
    }
    return 1;
}
