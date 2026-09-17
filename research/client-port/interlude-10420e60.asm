10420e60: push ebx
10420e61: push ebp
10420e62: mov ebp, ecx
10420e64: mov eax, dword ptr [ebp + 0x50f0]
10420e6a: mov ecx, dword ptr [0x10ddd7e0]
10420e70: push esi
10420e71: push edi
10420e72: lea ecx, [ecx + eax*4]
10420e75: rdtsc 
10420e77: sub dword ptr [ecx], eax
10420e79: cmp dword ptr [ebp + 0x50bc], 0
10420e80: mov edi, dword ptr [esp + 0x18]
10420e84: mov ebx, dword ptr [esp + 0x14]
10420e88: je 0x10420ea3
10420e8a: mov edx, dword ptr [ebp]
10420e8d: mov edx, dword ptr [edx + 0x7c]
10420e90: lea eax, [edi - 2]
10420e93: push eax
10420e94: lea ecx, [ebp + 0x50d1]
10420e9a: push ecx
10420e9b: lea eax, [ebx + 2]
10420e9e: push eax
10420e9f: mov ecx, ebp
10420ea1: call edx
10420ea3: mov al, byte ptr [ebx + 2]
10420ea6: cmp al, 0xfe
10420ea8: mov byte ptr [esp + 0x18], al
10420eac: jne 0x10420efc
10420eae: movzx eax, word ptr [ebx + 3]
10420eb2: mov dword ptr [esp + 0x14], eax
10420eb6: lea eax, [edi - 4]
10420eb9: test eax, eax
10420ebb: ja 0x10420ed1
10420ebd: push 0x1087f400
10420ec2: call 0x103121f2
10420ec7: add esp, 4
10420eca: pop edi
10420ecb: pop esi
10420ecc: pop ebp
10420ecd: pop ebx
10420ece: ret 8
10420ed1: mov ecx, dword ptr [0x11d8d6a0]
10420ed7: mov ecx, dword ptr [ecx]
10420ed9: mov edx, dword ptr [ecx]
10420edb: push 0x1087f3f0
10420ee0: push eax
10420ee1: mov eax, dword ptr [edx]
10420ee3: call eax
10420ee5: lea ecx, [edi - 5]
10420ee8: push ecx
10420ee9: add ebx, 5
10420eec: mov esi, eax
10420eee: push ebx
10420eef: push esi
10420ef0: call 0x107a6260
10420ef5: mov byte ptr [esi + edi - 5], 0
10420efa: jmp 0x10420f34
10420efc: lea eax, [edi - 2]
10420eff: test eax, eax
10420f01: mov dword ptr [esp + 0x14], 0xffff
10420f09: jbe 0x10420ebd
10420f0b: mov edx, dword ptr [0x11d8d6a0]
10420f11: mov ecx, dword ptr [edx]
10420f13: mov edx, dword ptr [ecx]
10420f15: push 0x1087f3f0
10420f1a: push eax
10420f1b: mov eax, dword ptr [edx]
10420f1d: call eax
10420f1f: lea ecx, [edi - 3]
10420f22: push ecx
10420f23: add ebx, 3
10420f26: mov esi, eax
10420f28: push ebx
10420f29: push esi
10420f2a: call 0x107a6260
10420f2f: mov byte ptr [esi + edi - 3], 0
10420f34: mov edx, dword ptr [0x11d8d6a0]
10420f3a: mov ecx, dword ptr [edx]
10420f3c: mov eax, dword ptr [ecx]
10420f3e: mov edx, dword ptr [eax]
10420f40: add esp, 0xc
10420f43: push 0x1087f3d8
10420f48: push 0xc
10420f4a: call edx
10420f4c: mov cl, byte ptr [esp + 0x18]
10420f50: mov dx, word ptr [esp + 0x14]
10420f55: add edi, -3
10420f58: mov byte ptr [eax], cl
10420f5a: mov word ptr [eax + 2], dx
10420f5e: mov dword ptr [eax + 4], edi
10420f61: mov dword ptr [eax + 8], esi
10420f64: mov ecx, dword ptr [0x10b1f538]
10420f6a: test ecx, ecx
10420f6c: je 0x10420f79
10420f6e: mov edx, dword ptr [ecx]
10420f70: push eax
10420f71: mov eax, dword ptr [edx + 0x84]
10420f77: call eax
10420f79: add dword ptr [ebp + 0x4850], 1
10420f80: mov ecx, dword ptr [ebp + 0x50f0]
10420f86: mov edx, dword ptr [0x10ddd7e0]
10420f8c: lea ecx, [edx + ecx*4]
10420f8f: rdtsc 
10420f91: pop edi
10420f92: pop esi
10420f93: add eax, -0xc
10420f96: add dword ptr [ecx], eax
10420f98: pop ebp
10420f99: pop ebx
10420f9a: ret 8
