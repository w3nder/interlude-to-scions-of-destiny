10403140: push ebx
10403141: mov ebx, dword ptr [esp + 8]
10403145: push esi
10403146: push edi
10403147: mov edi, dword ptr [esp + 0x14]
1040314b: mov eax, dword ptr [edi]
1040314d: add eax, 7
10403150: and eax, 0xfffffff8
10403153: mov dword ptr [edi], eax
10403155: sar eax, 2
10403158: xor esi, esi
1040315a: xor edx, edx
1040315c: test eax, eax
1040315e: jle 0x1040316a
10403160: xor esi, dword ptr [ebx + edx*4]
10403163: add edx, 1
10403166: cmp edx, eax
10403168: jl 0x10403160
1040316a: mov dword ptr [ebx + edx*4], esi
1040316d: add dword ptr [edi], 8
10403170: cmp dword ptr [ecx + 0x50b8], 0
10403177: push edi
10403178: push ebx
10403179: je 0x1040318c
1040317b: add ecx, 0x6c3c
10403181: call 0x103082e7
10403186: pop edi
10403187: pop esi
10403188: pop ebx
10403189: ret 8
1040318c: add ecx, 0x6c3c
10403192: call 0x10310249
10403197: pop edi
10403198: pop esi
10403199: pop ebx
1040319a: ret 8
