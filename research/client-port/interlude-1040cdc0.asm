1040cdc0: push ecx
1040cdc1: mov ecx, dword ptr [esp + 0xc]
1040cdc5: push ebx
1040cdc6: mov ebx, dword ptr [esp + 0xc]
1040cdca: mov edx, dword ptr [ebx + 0x4c]
1040cdcd: push esi
1040cdce: push edi
1040cdcf: lea eax, [esp + 0xc]
1040cdd3: push eax
1040cdd4: push 0x1087f9dc
1040cdd9: push ecx
1040cdda: xor edi, edi
1040cddc: push edx
1040cddd: mov dword ptr [esp + 0x1c], edi
1040cde1: call 0x103034e5
1040cde6: mov eax, dword ptr [0x10b1f538]
1040cdeb: mov dword ptr [eax + 0x50], edi
1040cdee: mov ecx, dword ptr [0x10b1f538]
1040cdf4: mov esi, dword ptr [ecx + 0x4c]
1040cdf7: mov eax, dword ptr [esi + 0x38]
1040cdfa: add esp, 0x10
1040cdfd: cmp eax, edi
1040cdff: je 0x1040ce15
1040ce01: push eax
1040ce02: call dword ptr [0x11d8eb60]
1040ce08: lea edx, [esi + 0x4efc]
1040ce0e: push edx
1040ce0f: call dword ptr [0x11d8e90c]
1040ce15: mov dword ptr [esi + 0x38], edi
1040ce18: mov eax, dword ptr [0x10b1f538]
1040ce1d: mov ecx, dword ptr [eax + 0x4c]
1040ce20: mov dword ptr [ecx + 0x38], edi
1040ce23: mov edx, dword ptr [0x10b1f538]
1040ce29: mov eax, dword ptr [edx + 0x4c]
1040ce2c: mov dword ptr [eax + 0x4850], edi
1040ce32: mov ecx, dword ptr [0x10b1f538]
1040ce38: mov edx, dword ptr [ecx + 0x4c]
1040ce3b: mov dword ptr [edx + 0x4854], edi
1040ce41: mov eax, dword ptr [ebx + 0x4c]
1040ce44: mov dword ptr [eax + 0x50b8], 1
1040ce4e: mov ecx, dword ptr [0x10c5104c]
1040ce54: mov edx, dword ptr [ecx]
1040ce56: mov eax, dword ptr [esp + 0xc]
1040ce5a: mov edx, dword ptr [edx + 0x90]
1040ce60: push eax
1040ce61: call edx
1040ce63: mov eax, dword ptr [0x11d8dab8]
1040ce68: mov ecx, dword ptr [eax]
1040ce6a: push 0x10883e18
1040ce6f: push ecx
1040ce70: call dword ptr [0x11d8d8e4]
1040ce76: add esp, 8
1040ce79: pop edi
1040ce7a: pop esi
1040ce7b: xor al, al
1040ce7d: pop ebx
1040ce7e: pop ecx
1040ce7f: ret 
