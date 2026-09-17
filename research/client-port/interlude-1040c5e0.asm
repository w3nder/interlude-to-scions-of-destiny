1040c5e0: sub esp, 8
1040c5e3: mov edx, dword ptr [esp + 0x10]
1040c5e7: push ebx
1040c5e8: mov ebx, dword ptr [esp + 0x10]
1040c5ec: push esi
1040c5ed: push edi
1040c5ee: lea eax, [esp + 0xc]
1040c5f2: push eax
1040c5f3: mov eax, dword ptr [ebx + 0x4c]
1040c5f6: lea ecx, [esp + 0x14]
1040c5fa: push ecx
1040c5fb: push 0x1087ff44
1040c600: push edx
1040c601: xor edi, edi
1040c603: push eax
1040c604: mov dword ptr [esp + 0x24], edi
1040c608: mov dword ptr [esp + 0x20], edi
1040c60c: call 0x103034e5
1040c611: mov ecx, dword ptr [0x10b1f538]
1040c617: mov dword ptr [ecx + 0x50], edi
1040c61a: mov edx, dword ptr [0x10b1f538]
1040c620: mov esi, dword ptr [edx + 0x4c]
1040c623: mov eax, dword ptr [esi + 0x38]
1040c626: add esp, 0x14
1040c629: cmp eax, edi
1040c62b: je 0x1040c641
1040c62d: push eax
1040c62e: call dword ptr [0x11d8eb60]
1040c634: lea eax, [esi + 0x4efc]
1040c63a: push eax
1040c63b: call dword ptr [0x11d8e90c]
1040c641: mov dword ptr [esi + 0x38], edi
1040c644: mov ecx, dword ptr [0x10b1f538]
1040c64a: mov edx, dword ptr [ecx + 0x4c]
1040c64d: mov dword ptr [edx + 0x38], edi
1040c650: mov eax, dword ptr [0x10b1f538]
1040c655: mov ecx, dword ptr [eax + 0x4c]
1040c658: mov dword ptr [ecx + 0x4850], edi
1040c65e: mov edx, dword ptr [0x10b1f538]
1040c664: mov eax, dword ptr [edx + 0x4c]
1040c667: mov dword ptr [eax + 0x4854], edi
1040c66d: mov ecx, dword ptr [ebx + 0x4c]
1040c670: mov dword ptr [ecx + 0x50b8], 1
1040c67a: mov ecx, dword ptr [0x10c5104c]
1040c680: mov edx, dword ptr [ecx]
1040c682: mov eax, dword ptr [esp + 0xc]
1040c686: mov edx, dword ptr [edx + 0x544]
1040c68c: push eax
1040c68d: call edx
1040c68f: test eax, eax
1040c691: pop edi
1040c692: pop esi
1040c693: pop ebx
1040c694: je 0x1040c69d
1040c696: push 0x10883e60
1040c69b: jmp 0x1040c6b7
1040c69d: mov ecx, dword ptr [0x10c5104c]
1040c6a3: mov edx, dword ptr [ecx]
1040c6a5: mov eax, dword ptr [esp + 4]
1040c6a9: mov edx, dword ptr [edx + 0x540]
1040c6af: push eax
1040c6b0: call edx
1040c6b2: push 0x10883e18
1040c6b7: mov eax, dword ptr [0x11d8dab8]
1040c6bc: mov ecx, dword ptr [eax]
1040c6be: push ecx
1040c6bf: call dword ptr [0x11d8d8e4]
1040c6c5: add esp, 8
1040c6c8: xor al, al
1040c6ca: add esp, 8
1040c6cd: ret 
