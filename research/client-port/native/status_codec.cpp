#include "status_codec.h"
#include <string.h>

L2K_API int l2k_status_exp_thunk(uint8_t* out,uint32_t cap,uint32_t base,uint32_t address){
    if(!out||!base||!address)return L2K_INVALID;
    if(cap<30)return L2K_CAPACITY;
    // eax = decoded C4 experience, ecx = FL2NetNotify, esi = resolved User.
    // Invoke the existing OnExpUpdate(User*, int64), then resume the native
    // loop. Zero extension matches the unsigned experience in C4 UserInfo.
    uint8_t code[30]={0x8b,0x44,0x24,0x1c,0x8b,0x15,0,0,0,0,
        0x8b,0x4a,0x54,0x8b,0x11,0x6a,0,0x50,0x56,
        0xff,0x92,0x80,0x01,0,0,0xe9,0,0,0,0};
    uint32_t global=base+0x81f538,relative=(base+0x126523)-(address+sizeof(code));
    memcpy(code+6,&global,4);memcpy(code+26,&relative,4);memcpy(out,code,sizeof(code));
    return sizeof(code);
}
