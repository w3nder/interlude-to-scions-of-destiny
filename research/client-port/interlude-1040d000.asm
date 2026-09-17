1040d000: push -1
1040d002: push 0x1080e9b9
1040d007: mov eax, dword ptr fs:[0]
1040d00d: push eax
1040d00e: mov dword ptr fs:[0], esp
1040d015: sub esp, 0x48
1040d018: push ebx
1040d019: push esi
1040d01a: push edi
1040d01b: mov edi, dword ptr [esp + 0x64]
1040d01f: lea eax, [esp + 0x10]
1040d023: push eax
1040d024: lea ecx, [esp + 0x10]
1040d028: push ecx
1040d029: mov ecx, dword ptr [esp + 0x70]
1040d02d: lea edx, [esp + 0x24]
1040d031: push edx
1040d032: mov edx, dword ptr [edi + 0x48]
1040d035: lea eax, [esp + 0x70]
1040d039: push eax
1040d03a: push 0x108840f8
1040d03f: push ecx
1040d040: xor ebx, ebx
1040d042: push edx
1040d043: mov dword ptr [esp + 0x30], 0x19327c8
1040d04b: mov dword ptr [esp + 0x34], 0x97316ca1
1040d053: mov dword ptr [esp + 0x28], ebx
1040d057: mov dword ptr [esp + 0x2c], ebx
1040d05b: call 0x103034e5
1040d060: mov eax, dword ptr [edi + 0x48]
1040d063: mov ecx, dword ptr [esp + 0x28]
1040d067: mov dword ptr [eax + 0x50bc], ecx
1040d06d: add esp, 0x1c
1040d070: xor eax, eax
1040d072: mov byte ptr [esp + 0x24], bl
1040d076: mov dword ptr [esp + 0x25], eax
1040d07a: mov dword ptr [esp + 0x29], eax
1040d07e: mov dword ptr [esp + 0x2d], eax
1040d082: mov word ptr [esp + 0x31], ax
1040d087: mov byte ptr [esp + 0x33], al
1040d08b: mov byte ptr [esp + 0x34], bl
1040d08f: mov dword ptr [esp + 0x35], eax
1040d093: mov dword ptr [esp + 0x39], eax
1040d097: mov dword ptr [esp + 0x3d], eax
1040d09b: mov word ptr [esp + 0x41], ax
1040d0a0: mov byte ptr [esp + 0x43], al
1040d0a4: mov cl, byte ptr [esp + eax + 0x1c]
1040d0a8: mov byte ptr [esp + eax + 0x24], cl
1040d0ac: mov byte ptr [esp + eax + 0x34], cl
1040d0b0: mov cl, byte ptr [esp + eax + 0x14]
1040d0b4: mov byte ptr [esp + eax + 0x2c], cl
1040d0b8: mov byte ptr [esp + eax + 0x3c], cl
1040d0bc: add eax, 1
1040d0bf: cmp eax, 8
1040d0c2: jb 0x1040d0a4
1040d0c4: mov esi, dword ptr [edi + 0x48]
1040d0c7: push 0x10
1040d0c9: lea edx, [esp + 0x28]
1040d0cd: push edx
1040d0ce: add esi, 0x50d1
1040d0d4: lea eax, [esi + 1]
1040d0d7: push 0x10
1040d0d9: push eax
1040d0da: call 0x107a67d9
1040d0df: mov byte ptr [esi], 1
1040d0e2: mov esi, dword ptr [edi + 0x48]
1040d0e5: push 0x10
1040d0e7: lea ecx, [esp + 0x48]
1040d0eb: push ecx
1040d0ec: add esi, 0x50c0
1040d0f2: lea edx, [esi + 1]
1040d0f5: push 0x10
1040d0f7: push edx
1040d0f8: call 0x107a67d9
1040d0fd: add esp, 0x20
1040d100: push 0xa
1040d102: lea ecx, [esp + 0x48]
1040d106: mov byte ptr [esi], 1
1040d109: call dword ptr [0x11d8dac0]
1040d10f: mov dword ptr [esp + 0x5c], ebx
1040d113: movsx eax, byte ptr [esp + 0x64]
1040d118: mov esi, dword ptr [0x11d8daec]
1040d11e: push eax
1040d11f: lea ecx, [esp + 0x48]
1040d123: call esi
1040d125: mov ecx, dword ptr [esp + 0x10]
1040d129: push ecx
1040d12a: lea ecx, [esp + 0x48]
1040d12e: call esi
1040d130: mov edx, dword ptr [0x10b1f538]
1040d136: mov ecx, dword ptr [edx + 0x54]
1040d139: mov eax, dword ptr [ecx]
1040d13b: mov eax, dword ptr [eax + 0x418]
1040d141: lea edx, [esp + 0x44]
1040d145: push edx
1040d146: call eax
1040d148: mov ecx, dword ptr [0x11d8dab8]
1040d14e: mov edx, dword ptr [ecx]
1040d150: mov esi, dword ptr [0x11d8d8e4]
1040d156: push 0x108840c4
1040d15b: push edx
1040d15c: call esi
1040d15e: mov edx, dword ptr [0x11d8dacc]
1040d164: mov edx, dword ptr [edx]
1040d166: mov eax, dword ptr [0x10b1f538]
1040d16b: mov eax, dword ptr [eax + 0x48]
1040d16e: mov ecx, dword ptr [eax]
1040d170: push edx
1040d171: mov edx, dword ptr [0x10b20f38]
1040d177: push edx
1040d178: mov edx, dword ptr [0x10b20f34]
1040d17e: push edx
1040d17f: mov edx, dword ptr [0x10b20f50]
1040d185: push edx
1040d186: mov edx, dword ptr [0x10b20f4c]
1040d18c: push edx
1040d18d: push 0x10b20f54
1040d192: push 8
1040d194: push 0x108840b8
1040d199: push eax
1040d19a: mov eax, dword ptr [ecx + 0x68]
1040d19d: call eax
1040d19f: mov ecx, dword ptr [0x11d8dab8]
1040d1a5: mov edx, dword ptr [ecx]
1040d1a7: push 0x10884084
1040d1ac: push edx
1040d1ad: call esi
1040d1af: add esp, 0x34
1040d1b2: mov dword ptr [esp + 0x5c], 0xffffffff
1040d1ba: lea ecx, [esp + 0x44]
1040d1be: call dword ptr [0x11d8dabc]
1040d1c4: pop edi
1040d1c5: pop esi
1040d1c6: xor al, al
1040d1c8: pop ebx
1040d1c9: mov ecx, dword ptr [esp + 0x48]
1040d1cd: mov dword ptr fs:[0], ecx
1040d1d4: add esp, 0x54
1040d1d7: ret 
