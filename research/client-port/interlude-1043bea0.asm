1043bea0: push -1
1043bea2: push 0x10810ddf
1043bea7: mov eax, dword ptr fs:[0]
1043bead: push eax
1043beae: mov dword ptr fs:[0], esp
1043beb5: sub esp, 8
1043beb8: push ebx
1043beb9: push esi
1043beba: mov esi, ecx
1043bebc: push edi
1043bebd: mov dword ptr [esp + 0xc], esi
1043bec1: call dword ptr [0x11d8d770]
1043bec7: xor ebx, ebx
1043bec9: mov dword ptr [esp + 0x1c], ebx
1043becd: lea ecx, [esi + 0x4f14]
1043bed3: mov dword ptr [esi], 0x1088b52c
1043bed9: mov dword ptr [esp + 0x10], ecx
1043bedd: call 0x1030197e
1043bee2: mov byte ptr [esp + 0x1c], 2
1043bee7: lea ecx, [esi + 0x4f28]
1043beed: mov dword ptr [esp + 0x10], ecx
1043bef1: call 0x1030c32e
1043bef6: mov byte ptr [esp + 0x1c], 4
1043befb: lea ecx, [esi + 0x4f3c]
1043bf01: mov dword ptr [esp + 0x10], ecx
1043bf05: call 0x1030b573
1043bf0a: mov byte ptr [esp + 0x1c], 6
1043bf0f: lea ecx, [esi + 0x4f50]
1043bf15: mov dword ptr [esp + 0x10], ecx
1043bf19: call 0x10306663
1043bf1e: mov byte ptr [esp + 0x1c], 8
1043bf23: lea ecx, [esi + 0x5024]
1043bf29: mov word ptr [esi + 0x4f6c], bx
1043bf30: mov dword ptr [esi + 0x5010], ebx
1043bf36: mov dword ptr [esi + 0x4f68], 0xffffffff
1043bf40: mov dword ptr [esi + 0x5018], ebx
1043bf46: call 0x1030552e
1043bf4b: mov byte ptr [esp + 0x1c], 9
1043bf50: mov byte ptr [esi + 0x50c0], bl
1043bf56: xor eax, eax
1043bf58: mov dword ptr [esi + 0x50c1], eax
1043bf5e: mov dword ptr [esi + 0x50c5], eax
1043bf64: mov dword ptr [esi + 0x50c9], eax
1043bf6a: mov dword ptr [esi + 0x50cd], eax
1043bf70: mov byte ptr [esi + 0x50d1], bl
1043bf76: mov dword ptr [esi + 0x50d2], eax
1043bf7c: mov dword ptr [esi + 0x50d6], eax
1043bf82: lea edi, [esi + 0x50e4]
1043bf88: mov dword ptr [esi + 0x50da], eax
1043bf8e: mov ecx, edi
1043bf90: mov dword ptr [esi + 0x50de], eax
1043bf96: call 0x10306e1f
1043bf9b: fldz 
1043bf9d: mov eax, dword ptr [esp + 0x24]
1043bfa1: fst dword ptr [esi + 0x4960]
1043bfa7: mov ecx, edi
1043bfa9: fstp dword ptr [esi + 0x4964]
1043bfaf: mov dword ptr [esi + 0x34], eax
1043bfb2: mov dword ptr [esi + 0x38], ebx
1043bfb5: mov dword ptr [esi + 0x4850], ebx
1043bfbb: mov dword ptr [esi + 0x4854], ebx
1043bfc1: mov dword ptr [esi + 0x4958], ebx
1043bfc7: mov dword ptr [esi + 0x495c], ebx
1043bfcd: mov dword ptr [esi + 0x4968], ebx
1043bfd3: mov dword ptr [esi + 0x496c], ebx
1043bfd9: mov dword ptr [esi + 0x4970], ebx
1043bfdf: mov dword ptr [esi + 0x4974], ebx
1043bfe5: mov dword ptr [esi + 0x4978], ebx
1043bfeb: mov dword ptr [esi + 0x497c], ebx
1043bff1: call 0x103022fc
1043bff6: mov dword ptr [esp + 0x1c], 0xffffffff
1043bffe: mov ecx, dword ptr [esp + 0x14]
1043c002: pop edi
1043c003: mov eax, esi
1043c005: pop esi
1043c006: pop ebx
1043c007: mov dword ptr fs:[0], ecx
1043c00e: add esp, 0x14
1043c011: ret 4
