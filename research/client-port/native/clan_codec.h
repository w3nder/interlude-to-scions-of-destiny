#pragma once
#include "protocol_core.h"
// Positive: converted C4 packet; zero: already Interlude or out of scope.
// Negative: recognized clan packet is malformed/ambiguous or exceeds capacity.
// Payload includes opcode; no ciphertext or TCP header. Distinct buffers required.
L2K_API int l2k_clan_convert(const uint8_t*,uint32_t,uint8_t*,uint32_t);
