1040ccd0: push ecx
1040ccd1: mov ecx, dword ptr [esp + 0xc]
1040ccd5: push ebx
1040ccd6: mov ebx, dword ptr [esp + 0xc]
1040ccda: mov edx, dword ptr [ebx + 0x4c]
1040ccdd: push esi
1040ccde: push edi
1040ccdf: lea eax, [esp + 0xc]
1040cce3: push eax
1040cce4: push 0x1087f9dc
1040cce9: push ecx
1040ccea: xor edi, edi
1040ccec: push edx
1040cced: mov dword ptr [esp + 0x1c], edi
1040ccf1: call 0x103034e5
1040ccf6: mov eax, dword ptr [0x10b1f538]
1040ccfb: mov dword ptr [eax + 0x50], edi
1040ccfe: mov ecx, dword ptr [0x10b1f538]
1040cd04: mov esi, dword ptr [ecx + 0x4c]
1040cd07: mov eax, dword ptr [esi + 0x38]
1040cd0a: add esp, 0x10
1040cd0d: cmp eax, edi
1040cd0f: je 0x1040cd25
1040cd11: push eax
1040cd12: call dword ptr [0x11d8eb60]
1040cd18: lea edx, [esi + 0x4efc]
1040cd1e: push edx
1040cd1f: call dword ptr [0x11d8e90c]
1040cd25: mov dword ptr [esi + 0x38], edi
1040cd28: mov eax, dword ptr [0x10b1f538]
1040cd2d: mov ecx, dword ptr [eax + 0x4c]
1040cd30: mov dword ptr [ecx + 0x38], edi
1040cd33: mov edx, dword ptr [0x10b1f538]
1040cd39: mov eax, dword ptr [edx + 0x4c]
1040cd3c: mov dword ptr [eax + 0x4850], edi
1040cd42: mov ecx, dword ptr [0x10b1f538]
1040cd48: mov edx, dword ptr [ecx + 0x4c]
1040cd4b: mov dword ptr [edx + 0x4854], edi
1040cd51: mov eax, dword ptr [ebx + 0x4c]
1040cd54: mov dword ptr [eax + 0x50b8], 1
1040cd5e: mov ecx, dword ptr [0x10c5104c]
1040cd64: mov edx, dword ptr [ecx]
1040cd66: mov eax, dword ptr [esp + 0xc]
1040cd6a: mov edx, dword ptr [edx + 0x90]
1040cd70: push eax
1040cd71: call edx
1040cd73: mov eax, dword ptr [0x11d8dab8]
1040cd78: mov ecx, dword ptr [eax]
1040cd7a: push 0x10883fe8
1040cd7f: push ecx
1040cd80: call dword ptr [0x11d8d8e4]
1040cd86: add esp, 8
1040cd89: pop edi
1040cd8a: pop esi
1040cd8b: xor al, al
1040cd8d: pop ebx
1040cd8e: pop ecx
1040cd8f: ret 
