#pragma once
#include "protocol_core.h"

// Volatile client state. Names and permissions are never written to a trace.
struct L2KPledgeMember { uint16_t name[64]; uint32_t id; };
struct L2KPledgeState {
    L2KPledgeMember members[512];
    uint32_t count,clan,self_id,selected_id,phase,nonce,since,pending;
    uint16_t self_name[64],leader[64],selected_name[64];
    uint8_t rights[32],original[32];
};
struct L2KPledgeResult {
    uint32_t server_size,display_size;
    uint8_t server[41],display[8190];
    // Interlude packet answered locally without any C4 request (FE:3D member info).
    uint32_t local_size;uint8_t local[160];
};
L2K_API uint32_t l2k_pledge_state_size();
L2K_API void l2k_pledge_reset(L2KPledgeState*);
// S2C observes the already converted clan roster. Return 1 consumes a legacy
// permission response; unrelated packets return 0 and retain the native path.
L2K_API int l2k_pledge_receive(L2KPledgeState*,const uint8_t*,uint32_t,uint32_t,L2KPledgeResult*);
// Return 1 handles a local UI action or replaces an incompatible rank request.
// Generated C4 requests must use the original sender/framing/cipher.
L2K_API int l2k_pledge_send(L2KPledgeState*,const uint8_t*,uint32_t,uint32_t,L2KPledgeResult*);
