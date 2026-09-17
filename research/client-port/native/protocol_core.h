#pragma once
#include <stdint.h>
#include <stddef.h>

#ifdef _WIN32
#define L2K_API extern "C" __declspec(dllexport)
#else
#define L2K_API extern "C" __attribute__((visibility("default")))
#endif

// C ABI, caller owns all memory. Negative return = error, no exceptions cross ABI.
// Buffer functions return bytes written; output capacity is always explicit.
enum { L2K_INVALID=-1, L2K_CAPACITY=-2, L2K_PHASE=-3, L2K_REFUSED=-4 };
struct L2KBlowfish { uint32_t p[18], s[4][256]; };
struct L2KGame { uint8_t tx[8], rx[8]; uint32_t ready; };
struct L2KLogin {
    L2KBlowfish bf;
    uint32_t phase, login1, login2, play1, play2, port;
    uint8_t user[14], password[16], host[4], server;
};

L2K_API uint32_t l2k_abi_version();
L2K_API uint32_t l2k_login_size();
L2K_API int l2k_bf_init(L2KBlowfish*, const uint8_t*, uint32_t);
L2K_API int l2k_bf_block(const L2KBlowfish*, const uint8_t*, uint8_t*, uint32_t decrypt);
L2K_API int l2k_login_seal(const L2KBlowfish*, const uint8_t*, uint32_t, uint8_t*, uint32_t);
L2K_API int l2k_login_decrypt(const L2KBlowfish*, const uint8_t*, uint32_t, uint8_t*, uint32_t);
L2K_API int l2k_game_key(L2KGame*, const uint8_t*, uint32_t);
L2K_API int l2k_game_transform(L2KGame*, uint8_t*, uint32_t, uint32_t decrypt);
L2K_API int l2k_protocol_version(const uint8_t*, uint32_t, uint8_t*, uint32_t);
L2K_API int l2k_login_begin(L2KLogin*, const uint8_t*, uint32_t, const uint8_t*, uint32_t);
// Receive a plaintext C4 login payload, emit encrypted C4 reply without frame.
// Caller handles Init plaintext vs later Blowfish bodies and TCP framing.
// Phase: 1 Init, 2 LoginOk, 3 ServerList, 4 PlayOk, 5 complete, 6 failed.
L2K_API int l2k_login_step(L2KLogin*, const uint8_t*, uint32_t, uint8_t*, uint32_t);
