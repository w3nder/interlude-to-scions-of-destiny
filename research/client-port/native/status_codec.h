#pragma once
#include "protocol_core.h"
// Pinned x86 StatusUpdate case 2: original stack/register frame, d -> Q.
L2K_API int l2k_status_exp_thunk(uint8_t*,uint32_t,uint32_t,uint32_t);
bool l2k_install_status_bridge();
