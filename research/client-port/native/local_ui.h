#pragma once
#include <stdint.h>
// Queue a complete plaintext payload (opcode first; FE + word for extended
// packets) into the native Interlude receive queue on any thread.
bool l2k_queue_local_packet(const uint8_t* payload,uint32_t length);
bool l2k_queue_local_html(const uint8_t* payload,uint32_t length);
