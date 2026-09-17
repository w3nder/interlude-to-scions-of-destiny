104029b0: mov eax, 0x2000
104029b5: call 0x107a69d0
104029ba: push esi
104029bb: mov esi, dword ptr [esp + 0x2008]
104029c2: cmp dword ptr [esi + 0x38], 0
104029c6: je 0x10402a74
104029cc: push edi
104029cd: lea edi, [esi + 0x4efc]
104029d3: push edi
104029d4: call dword ptr [0x11d8e91c]
104029da: mov eax, dword ptr [esp + 0x2010]
104029e1: test eax, eax
104029e3: je 0x10402a6c
104029e9: push ebx
104029ea: lea ecx, [esp + 0x2018]
104029f1: push ecx
104029f2: push eax
104029f3: lea edx, [esp + 0x16]
104029f7: push 0x1ffe
104029fc: push edx
104029fd: call 0x103068b6
10402a02: mov ebx, eax
10402a04: add esp, 0x10
10402a07: test ebx, ebx
10402a09: je 0x10402a5b
10402a0b: add ebx, 2
10402a0e: mov eax, ebx
10402a10: sar eax, 8
10402a13: cmp dword ptr [esi + 0x50bc], 0
10402a1a: mov byte ptr [esp + 0xc], bl
10402a1e: mov byte ptr [esp + 0xd], al
10402a22: je 0x10402a3d
10402a24: mov edx, dword ptr [esi]
10402a26: mov edx, dword ptr [edx + 0x78]
10402a29: lea eax, [ebx - 2]
10402a2c: push eax
10402a2d: lea ecx, [esi + 0x50c0]
10402a33: push ecx
10402a34: lea eax, [esp + 0x16]
10402a38: push eax
10402a39: mov ecx, esi
10402a3b: call edx
10402a3d: mov ecx, dword ptr [esi + 0x38]
10402a40: push 0
10402a42: push ebx
10402a43: lea eax, [esp + 0x14]
10402a47: push eax
10402a48: push ecx
10402a49: call dword ptr [0x11d8eb64]
10402a4f: add dword ptr [esi + 0x4978], ebx
10402a55: add dword ptr [esi + 0x497c], ebx
10402a5b: push edi
10402a5c: call dword ptr [0x11d8e918]
10402a62: pop ebx
10402a63: pop edi
10402a64: pop esi
10402a65: add esp, 0x2000
10402a6b: ret 
10402a6c: push edi
10402a6d: call dword ptr [0x11d8e918]
10402a73: pop edi
10402a74: pop esi
10402a75: add esp, 0x2000
10402a7b: ret 
