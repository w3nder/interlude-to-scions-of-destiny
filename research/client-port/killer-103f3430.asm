103f3430: mov eax, 0x2000
103f3435: call 0x10740e10
103f343a: push esi
103f343b: mov esi, dword ptr [esp + 0x2008]
103f3442: mov eax, dword ptr [esi + 0x38]
103f3445: test eax, eax
103f3447: je 0x103f3504
103f344d: push edi
103f344e: lea edi, [esi + 0x4e4c]
103f3454: push edi
103f3455: call dword ptr [0x142d8764]
103f345b: mov eax, dword ptr [esp + 0x2010]
103f3462: test eax, eax
103f3464: je 0x103f34fc
103f346a: push ebx
103f346b: lea ecx, [esp + 0x2018]
103f3472: push ecx
103f3473: push eax
103f3474: lea edx, [esp + 0x16]
103f3478: push 0x1ffe
103f347d: push edx
103f347e: call 0x10308f2b
103f3483: mov ebx, eax
103f3485: add esp, 0x10
103f3488: test ebx, ebx
103f348a: je 0x103f34eb
103f348c: add ebx, 2
103f348f: mov eax, ebx
103f3491: sar eax, 8
103f3494: mov byte ptr [esp + 0xd], al
103f3498: mov eax, dword ptr [esi + 0x4f68]
103f349e: test eax, eax
103f34a0: mov byte ptr [esp + 0xc], bl
103f34a4: je 0x103f34bd
103f34a6: mov edx, dword ptr [esi]
103f34a8: lea eax, [ebx - 2]
103f34ab: push eax
103f34ac: lea ecx, [esi + 0x4f6c]
103f34b2: push ecx
103f34b3: lea eax, [esp + 0x16]
103f34b7: push eax
103f34b8: mov ecx, esi
103f34ba: call dword ptr [edx + 0x74]
103f34bd: mov edx, dword ptr [esi + 0x38]
103f34c0: push 0
103f34c2: push ebx
103f34c3: lea ecx, [esp + 0x14]
103f34c7: push ecx
103f34c8: push edx
103f34c9: call dword ptr [0x142d892c]
103f34cf: mov ecx, dword ptr [esi + 0x4978]
103f34d5: mov eax, dword ptr [esi + 0x497c]
103f34db: add ecx, ebx
103f34dd: add eax, ebx
103f34df: mov dword ptr [esi + 0x4978], ecx
103f34e5: mov dword ptr [esi + 0x497c], eax
103f34eb: push edi
103f34ec: call dword ptr [0x142d8748]
103f34f2: pop ebx
103f34f3: pop edi
103f34f4: pop esi
103f34f5: add esp, 0x2000
103f34fb: ret 
103f34fc: push edi
103f34fd: call dword ptr [0x142d8748]
103f3503: pop edi
103f3504: pop esi
103f3505: add esp, 0x2000
103f350b: ret 
103f350c: nop 
103f350d: nop 
103f350e: nop 
103f350f: nop 
