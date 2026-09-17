#pragma once
#include "protocol_core.h"
// 0 = keep, 1 = block a known unsupported feature; no packet mutations.
L2K_API int l2k_outbound_blocked(const uint8_t*,uint32_t);
// In-place conversion: 0 unchanged, positive new size, negative invalid/unsupported.
L2K_API int l2k_outbound_convert(uint8_t*,uint32_t);

// Verified serializer-level conversion; nullptr preserves original format.
L2K_API const char* l2k_outbound_serialization_format(const char*,const uint8_t*,uint32_t);
