#pragma once
#include "protocol_core.h"

// Session-local metadata only. Never persisted or sent to the server.
struct L2KClanSelf {
    uint16_t name[64];
    uint32_t id,race,sex,klass,level;
    uint32_t ready,eligible,present,owned;
};
L2K_API uint32_t l2k_clan_self_size();
L2K_API void l2k_clan_self_reset(L2KClanSelf*);
// Observe the converted packet. legacy_roster is true ONLY when 53 was
// expanded from the C4 layout. Return a local 55/add or 54/update payload.
L2K_API int l2k_clan_self_receive(L2KClanSelf*,const uint8_t*,uint32_t,
                                uint32_t legacy_roster,uint8_t*,uint32_t);
