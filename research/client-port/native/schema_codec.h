#pragma once
#include "protocol_core.h"
// Exact structural recognition; 0 preserves native layout/unrelated packets.
L2K_API int l2k_schema_convert(const uint8_t*,uint32_t,uint8_t*,uint32_t);
