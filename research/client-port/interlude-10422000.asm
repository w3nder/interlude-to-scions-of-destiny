10422000: xor eax, eax
10422002: push esi
10422003: mov dword ptr [0x10b20f54], eax
10422008: mov dword ptr [0x10b20f58], eax
1042200d: mov dword ptr [0x10b20f5c], eax
10422012: mov word ptr [0x10b20f60], ax
10422018: mov byte ptr [0x10b20f62], al
1042201d: mov dword ptr [0x10b20f72], eax
10422022: mov dword ptr [0x10b20f76], eax
10422027: mov dword ptr [0x10b20f7a], eax
1042202c: mov dword ptr [0x10b20f7e], eax
10422031: mov byte ptr [0x10b20f82], al
10422036: mov eax, dword ptr [esp + 8]
1042203a: push 0xe
1042203c: push eax
1042203d: push 0x10b20f54
10422042: mov esi, ecx
10422044: call 0x107a6f73
10422049: mov ecx, dword ptr [esp + 0x18]
1042204d: push 0x10
1042204f: push ecx
10422050: push 0x10b20f72
10422055: call 0x107a6f73
1042205a: mov edx, dword ptr [esp + 0x28]
1042205e: mov dword ptr [0x10b20f94], edx
10422064: mov eax, dword ptr [esi + 0x4c]
10422067: mov dword ptr [eax + 0x50bc], 1
10422071: mov ecx, dword ptr [esi + 0x4c]
10422074: add esp, 0x18
10422077: mov dword ptr [ecx + 0x50b8], 1
10422081: mov ecx, dword ptr [esi + 0x4c]
10422084: push 0x83a
10422089: lea edx, [ecx + 0x4858]
1042208f: push edx
10422090: call 0x10311c70
10422095: mov dword ptr [esi + 0x50], 1
1042209c: mov eax, dword ptr [0x11d8dab8]
104220a1: mov ecx, dword ptr [eax]
104220a3: push 0x10888824
104220a8: push ecx
104220a9: call dword ptr [0x11d8d8e4]
104220af: add esp, 8
104220b2: mov eax, 1
104220b7: pop esi
104220b8: ret 0xc
