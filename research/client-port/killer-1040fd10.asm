1040fd10: sub esp, 8
1040fd13: mov dword ptr [esp + 4], ecx
1040fd17: mov eax, dword ptr [ecx + 0x4f88]
1040fd1d: mov ecx, dword ptr [0x10cc2110]
1040fd23: lea ecx, [ecx + eax*4]
1040fd26: rdtsc 
1040fd28: sub dword ptr [ecx], eax
1040fd2a: mov ecx, dword ptr [esp + 4]
1040fd2e: mov eax, dword ptr [ecx + 0x4f68]
1040fd34: test eax, eax
1040fd36: je 0x1040fd54
1040fd38: mov eax, dword ptr [esp + 0x10]
1040fd3c: mov edx, dword ptr [ecx]
1040fd3e: add eax, -2
1040fd41: push eax
1040fd42: lea eax, [ecx + 0x4f74]
1040fd48: push eax
1040fd49: mov eax, dword ptr [esp + 0x14]
1040fd4d: add eax, 2
1040fd50: push eax
1040fd51: call dword ptr [edx + 0x78]
1040fd54: mov eax, dword ptr [esp + 0xc]
1040fd58: mov cl, byte ptr [eax + 2]
1040fd5b: push ebx
1040fd5c: push ebp
1040fd5d: push esi
1040fd5e: mov byte ptr [esp + 0xf], cl
1040fd62: cmp cl, 0xfe
1040fd65: mov ecx, dword ptr [esp + 0x1c]
1040fd69: push edi
1040fd6a: jne 0x1040fdeb
1040fd6c: mov bx, word ptr [eax + 3]
1040fd70: lea eax, [ecx - 4]
1040fd73: test eax, eax
1040fd75: ja 0x1040fdae
1040fd77: mov eax, dword ptr [0x10b36bbc]
1040fd7c: mov edx, dword ptr [eax]
1040fd7e: push 0x2c2e
1040fd83: push 0x107bd2c0
1040fd88: push ecx
1040fd89: push 0x107bd248
1040fd8e: push 2
1040fd90: push eax
1040fd91: call dword ptr [edx + 0x2c0]
1040fd97: push 0x107bd218
1040fd9c: call 0x10314137
1040fda1: add esp, 0x1c
1040fda4: pop edi
1040fda5: pop esi
1040fda6: pop ebp
1040fda7: pop ebx
1040fda8: add esp, 8
1040fdab: ret 8
1040fdae: mov ecx, dword ptr [0x142d83b4]
1040fdb4: mov ecx, dword ptr [ecx]
1040fdb6: mov edx, dword ptr [ecx]
1040fdb8: push 0x107bd208
1040fdbd: push eax
1040fdbe: call dword ptr [edx]
1040fdc0: mov ecx, dword ptr [esp + 0x20]
1040fdc4: mov esi, dword ptr [esp + 0x1c]
1040fdc8: add ecx, -5
1040fdcb: mov ebp, eax
1040fdcd: mov eax, ecx
1040fdcf: shr ecx, 2
1040fdd2: add esi, 5
1040fdd5: mov edi, ebp
1040fdd7: rep movsd dword ptr es:[edi], dword ptr [esi]
1040fdd9: mov ecx, eax
1040fddb: and ecx, 3
1040fdde: rep movsb byte ptr es:[edi], byte ptr [esi]
1040fde0: mov ecx, dword ptr [esp + 0x20]
1040fde4: mov byte ptr [ecx + ebp - 5], 0
1040fde9: jmp 0x1040fe69
1040fdeb: lea eax, [ecx - 2]
1040fdee: test eax, eax
1040fdf0: mov ebx, 0xffff
1040fdf5: ja 0x1040fe2e
1040fdf7: mov eax, dword ptr [0x10b36bbc]
1040fdfc: mov edx, dword ptr [eax]
1040fdfe: push 0x2c3b
1040fe03: push 0x107bd2c0
1040fe08: push ecx
1040fe09: push 0x107bd248
1040fe0e: push 2
1040fe10: push eax
1040fe11: call dword ptr [edx + 0x2c0]
1040fe17: push 0x107bd218
1040fe1c: call 0x10314137
1040fe21: add esp, 0x1c
1040fe24: pop edi
1040fe25: pop esi
1040fe26: pop ebp
1040fe27: pop ebx
1040fe28: add esp, 8
1040fe2b: ret 8
1040fe2e: mov ecx, dword ptr [0x142d83b4]
1040fe34: mov ecx, dword ptr [ecx]
1040fe36: mov edx, dword ptr [ecx]
1040fe38: push 0x107bd208
1040fe3d: push eax
1040fe3e: call dword ptr [edx]
1040fe40: mov ecx, dword ptr [esp + 0x20]
1040fe44: mov esi, dword ptr [esp + 0x1c]
1040fe48: add ecx, -3
1040fe4b: mov ebp, eax
1040fe4d: mov eax, ecx
1040fe4f: shr ecx, 2
1040fe52: add esi, 3
1040fe55: mov edi, ebp
1040fe57: rep movsd dword ptr es:[edi], dword ptr [esi]
1040fe59: mov ecx, eax
1040fe5b: and ecx, 3
1040fe5e: rep movsb byte ptr es:[edi], byte ptr [esi]
1040fe60: mov ecx, dword ptr [esp + 0x20]
1040fe64: mov byte ptr [ecx + ebp - 3], 0
1040fe69: mov edx, dword ptr [0x142d83b4]
1040fe6f: mov ecx, dword ptr [edx]
1040fe71: mov eax, dword ptr [ecx]
1040fe73: push 0x107bd1f0
1040fe78: push 0xc
1040fe7a: call dword ptr [eax]
1040fe7c: mov cl, byte ptr [esp + 0x13]
1040fe80: mov byte ptr [eax], cl
1040fe82: mov word ptr [eax + 2], bx
1040fe86: mov edx, dword ptr [esp + 0x20]
1040fe8a: add edx, -3
1040fe8d: mov dword ptr [eax + 4], edx
1040fe90: mov dword ptr [eax + 8], ebp
1040fe93: mov ecx, dword ptr [0x109d5e68]
1040fe99: test ecx, ecx
1040fe9b: je 0x1040fea6
1040fe9d: mov edx, dword ptr [ecx]
1040fe9f: push eax
1040fea0: call dword ptr [edx + 0x80]
1040fea6: mov eax, dword ptr [esp + 0x14]
1040feaa: inc dword ptr [eax + 0x4850]
1040feb0: mov eax, dword ptr [esp + 0x14]
1040feb4: mov ecx, dword ptr [eax + 0x4f88]
1040feba: mov edx, dword ptr [0x10cc2110]
1040fec0: lea ecx, [edx + ecx*4]
1040fec3: rdtsc 
1040fec5: mov edx, dword ptr [ecx]
1040fec7: pop edi
1040fec8: pop esi
1040fec9: add eax, -0xc
1040fecc: add edx, eax
1040fece: pop ebp
1040fecf: mov dword ptr [ecx], edx
1040fed1: pop ebx
1040fed2: add esp, 8
1040fed5: ret 8
1040fed8: nop 
1040fed9: nop 
1040feda: nop 
1040fedb: nop 
1040fedc: nop 
1040fedd: nop 
1040fede: nop 
1040fedf: nop 
