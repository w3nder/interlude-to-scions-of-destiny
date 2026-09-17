(Send)Send Protocol Version:%d
10401dc0: mov eax, dword ptr [esp + 8]
10401dc4: sub esp, 0x808
10401dca: shr eax, 0x10
10401dcd: test ax, ax
10401dd0: push esi
10401dd1: mov esi, ecx
10401dd3: jne 0x10401f46
10401dd9: mov eax, dword ptr [esi + 0x34]
10401ddc: mov ecx, dword ptr [esi + 0x38]
10401ddf: push 0x25
10401de1: push 0x508
10401de6: push eax
10401de7: push ecx
10401de8: call dword ptr [0x11d8eb68]
10401dee: test eax, eax
10401df0: je 0x10401e21
10401df2: call dword ptr [0x11d8eb6c]
10401df8: mov edx, dword ptr [esi + 0x38]
10401dfb: push edx
10401dfc: push eax
10401dfd: push 0x1087f0c0
10401e02: call 0x103121f2
10401e07: add esp, 0xc
10401e0a: add esi, 0x4efc
10401e10: push esi
10401e11: call dword ptr [0x11d8e90c]
10401e17: pop esi
10401e18: add esp, 0x808
10401e1e: ret 8
10401e21: push 0
10401e23: push 0x1087f248
10401e28: push 0x1087f220
10401e2d: call 0x103121f2
10401e32: lea eax, [esp + 0x13]
10401e36: push eax
10401e37: lea ecx, [esp + 0x18]
10401e3b: push ecx
10401e3c: lea edx, [esp + 0x1a]
10401e40: push edx
10401e41: push 0x1087f208
10401e46: push 0x1087f1f4
10401e4b: call 0x107a6942
10401e50: push 0x7ff
10401e55: lea eax, [esp + 0x31]
10401e59: push 0
10401e5b: push eax
10401e5c: mov byte ptr [esp + 0x38], 0
10401e61: call 0x107a6860
10401e66: add esp, 0x2c
10401e69: xor eax, eax
10401e6b: xor ecx, ecx
10401e6d: lea ecx, [ecx]
10401e70: mov dl, byte ptr [ecx + 0x1087e5e8]
10401e76: xor dl, byte ptr [eax + 0x1087e6ec]
10401e7c: add eax, 1
10401e7f: cmp eax, 8
10401e82: mov byte ptr [esp + ecx + 0xc], dl
10401e86: jl 0x10401e8a
10401e88: xor eax, eax
10401e8a: mov dl, byte ptr [ecx + 0x1087e5e9]
10401e90: xor dl, byte ptr [eax + 0x1087e6ec]
10401e96: add eax, 1
10401e99: cmp eax, 8
10401e9c: mov byte ptr [esp + ecx + 0xd], dl
10401ea0: jl 0x10401ea4
10401ea2: xor eax, eax
10401ea4: mov dl, byte ptr [ecx + 0x1087e5ea]
10401eaa: xor dl, byte ptr [eax + 0x1087e6ec]
10401eb0: add eax, 1
10401eb3: cmp eax, 8
10401eb6: mov byte ptr [esp + ecx + 0xe], dl
10401eba: jl 0x10401ebe
10401ebc: xor eax, eax
10401ebe: mov dl, byte ptr [ecx + 0x1087e5eb]
10401ec4: xor dl, byte ptr [eax + 0x1087e6ec]
10401eca: add eax, 1
10401ecd: cmp eax, 8
10401ed0: mov byte ptr [esp + ecx + 0xf], dl
10401ed4: jl 0x10401ed8
10401ed6: xor eax, eax
10401ed8: add ecx, 4
10401edb: cmp ecx, 0x100
10401ee1: jl 0x10401e70
10401ee3: mov eax, dword ptr [0x10c51044]
10401ee8: mov ecx, dword ptr [eax + 0x70]
10401eeb: mov edx, dword ptr [0x10b1f538]
10401ef1: mov esi, dword ptr [edx + 0x48]
10401ef4: mov eax, dword ptr [ecx]
10401ef6: mov edx, dword ptr [eax + 0x78]
10401ef9: push edi
10401efa: mov edi, dword ptr [esi]
10401efc: call edx
10401efe: mov ecx, dword ptr [esp + 0xc]
10401f02: mov edx, dword ptr [edi + 0x68]
10401f05: push eax
10401f06: lea eax, [esp + 0x14]
10401f0a: push eax
10401f0b: push 0x100
10401f10: push ecx
10401f11: push 0
10401f13: push 0x1087f1ec
10401f18: push esi
10401f19: call edx
10401f1b: mov eax, dword ptr [esp + 0x28]
10401f1f: push eax
10401f20: mov dword ptr [0x10a56e8c], eax
10401f25: mov eax, dword ptr [0x11d8dab8]
10401f2a: mov ecx, dword ptr [eax]
10401f2c: push 0x1087f1a0
10401f31: push ecx
10401f32: call dword ptr [0x11d8d8e4]
10401f38: add esp, 0x28
10401f3b: pop edi
10401f3c: pop esi
10401f3d: add esp, 0x808
10401f43: ret 8
10401f46: cmp ax, 0x274d
10401f4a: jne 0x10401f59
10401f4c: push 0x1087f158
10401f51: call 0x103121f2
10401f56: add esp, 4
10401f59: pop esi
10401f5a: add esp, 0x808
10401f60: ret 8
