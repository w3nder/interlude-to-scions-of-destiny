#pragma once
#include "protocol_core.h"
struct L2KAssetRecord {uint32_t kind,id,quantity,equipped,body_part,slot,enchant,variant,type1;};
// Read-only, catalogue IDs only. No character names, object IDs or raw payload.
// Positive record count, zero unrelated packet, negative unrecognized layout.
L2K_API int l2k_asset_inspect(const uint8_t*,uint32_t,L2KAssetRecord*,uint32_t);
