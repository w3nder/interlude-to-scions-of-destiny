1040be50: push ebp
1040be51: mov ebp, esp
1040be53: push -1
1040be55: push 0x1080e940
1040be5a: mov eax, dword ptr fs:[0]
1040be60: push eax
1040be61: mov dword ptr fs:[0], esp
1040be68: push ecx
1040be69: mov eax, 0x41e0
1040be6e: call 0x107a69d0
1040be73: push ebx
1040be74: push esi
1040be75: push edi
1040be76: mov dword ptr [ebp - 0x10], esp
1040be79: xor ebx, ebx
1040be7b: mov dword ptr [ebp - 4], ebx
1040be7e: mov esi, dword ptr [ebp + 8]
1040be81: cmp esi, ebx
1040be83: je 0x1040c1d2
1040be89: mov eax, dword ptr [esi + 0x4c]
1040be8c: cmp eax, ebx
1040be8e: je 0x1040c1d2
1040be94: mov edi, 1
1040be99: mov dword ptr [esi + 0x50], edi
1040be9c: mov dword ptr [ebp - 0x30], ebx
1040be9f: lea ecx, [ebp - 0x30]
1040bea2: push ecx
1040bea3: mov edx, dword ptr [0x10b1f538]
1040bea9: add edx, 0xe4
1040beaf: push edx
1040beb0: push 0x1087ff44
1040beb5: mov ecx, dword ptr [ebp + 0xc]
1040beb8: push ecx
1040beb9: push eax
1040beba: call 0x103034e5
1040bebf: add esp, 0x14
1040bec2: mov dword ptr [ebp + 0xc], eax
1040bec5: mov edx, dword ptr [esi + 0x4c]
1040bec8: mov dword ptr [edx + 0x50bc], edi
1040bece: xor eax, eax
1040bed0: mov dword ptr [ebp - 0x64], eax
1040bed3: mov dword ptr [ebp - 0x60], eax
1040bed6: mov dword ptr [ebp - 0x5c], eax
1040bed9: mov dword ptr [ebp - 0x58], eax
1040bedc: mov dword ptr [ebp - 0x54], eax
1040bedf: mov dword ptr [ebp - 0x50], eax
1040bee2: mov dword ptr [ebp - 0x4c], eax
1040bee5: mov dword ptr [ebp - 0x48], eax
1040bee8: mov dword ptr [ebp - 0x44], eax
1040beeb: mov byte ptr [ebp - 0x40], al
1040beee: push ebx
1040beef: push ebx
1040bef0: push 0x25
1040bef2: lea eax, [ebp - 0x62]
1040bef5: push eax
1040bef6: push 0xe
1040bef8: push 0x10b20f54
1040befd: push ebx
1040befe: push ebx
1040beff: mov esi, dword ptr [0x11d8e92c]
1040bf05: call esi
1040bf07: push ebx
1040bf08: push ebx
1040bf09: push 0x15
1040bf0b: lea ecx, [ebp - 0x54]
1040bf0e: push ecx
1040bf0f: push 0x10
1040bf11: push 0x10b20f72
1040bf16: push ebx
1040bf17: push ebx
1040bf18: call esi
1040bf1a: mov edx, dword ptr [0x10b20f94]
1040bf20: mov dword ptr [ebp - 0x44], edx
1040bf23: mov edi, dword ptr [0x11d8dad4]
1040bf29: call edi
1040bf2b: mov ebx, eax
1040bf2d: and ebx, 0x8000007f
1040bf33: jns 0x1040bf3a
1040bf35: dec ebx
1040bf36: or ebx, 0xffffff80
1040bf39: inc ebx
1040bf3a: xor esi, esi
1040bf3c: mov dword ptr [ebp - 0x14], esi
1040bf3f: cmp esi, 0x80
1040bf45: jge 0x1040bf54
1040bf47: call edi
1040bf49: mov byte ptr [esi + 0x10b1b490], al
1040bf4f: add esi, 1
1040bf52: jmp 0x1040bf3c
1040bf54: mov esi, ebx
1040bf56: imul esi, esi, 0x81
1040bf5c: lea edi, [ebp + esi - 0x41f0]
1040bf63: push 0x80
1040bf68: push 0x10b1b490
1040bf6d: push edi
1040bf6e: call 0x107a6260
1040bf73: add esp, 0xc
1040bf76: mov byte ptr [ebp + esi - 0x4170], 0
1040bf7e: cmp ebx, ebx
1040bf80: jne 0x1040bfc4
1040bf82: push 0x80
1040bf87: mov eax, dword ptr [ebp + 0xc]
1040bf8a: push eax
1040bf8b: push edi
1040bf8c: call 0x107a6260
1040bf91: push 0x80
1040bf96: push 0
1040bf98: mov ecx, dword ptr [0x10b1f538]
1040bf9e: add ecx, 0xe8
1040bfa4: push ecx
1040bfa5: call dword ptr [0x11d8d938]
1040bfab: mov eax, dword ptr [0x10b1f538]
1040bfb0: add eax, 0xe8
1040bfb5: push 0x80
1040bfba: push edi
1040bfbb: push eax
1040bfbc: call 0x107a6260
1040bfc1: add esp, 0x24
1040bfc4: mov edi, 0x40
1040bfc9: mov dword ptr [ebp - 0x14], edi
1040bfcc: cmp edi, 0x80
1040bfd2: jge 0x1040bfee
1040bfd4: lea eax, [esi + edi]
1040bfd7: lea eax, [ebp + eax - 0x41f0]
1040bfde: movzx edx, byte ptr [eax - 0x40]
1040bfe2: movzx ecx, byte ptr [eax]
1040bfe5: xor edx, ecx
1040bfe7: mov byte ptr [eax], dl
1040bfe9: add edi, 1
1040bfec: jmp 0x1040bfc9
1040bfee: mov edx, dword ptr [ebp + esi - 0x41bc]
1040bff5: xor dword ptr [ebp + esi - 0x41e3], edx
1040bffc: xor eax, eax
1040bffe: mov dword ptr [ebp - 0x14], eax
1040c001: cmp eax, 0x40
1040c004: jge 0x1040c027
1040c006: lea edi, [esi + eax]
1040c009: lea edi, [ebp + edi - 0x41f0]
1040c010: lea ecx, [ebp + esi - 0x41b0]
1040c017: movzx edx, byte ptr [ecx + eax]
1040c01b: movzx ecx, byte ptr [edi]
1040c01e: xor edx, ecx
1040c020: mov byte ptr [edi], dl
1040c022: add eax, 1
1040c025: jmp 0x1040bffe
1040c027: lea eax, [ebp + esi - 0x41a3]
1040c02e: mov edx, dword ptr [eax]
1040c030: lea ecx, [ebp + esi - 0x41f0]
1040c037: mov esi, dword ptr [ecx]
1040c039: mov dword ptr [eax], esi
1040c03b: mov dword ptr [ecx], edx
1040c03d: mov edx, dword ptr [0x1087f648]
1040c043: mov dword ptr [ebp - 0x38], edx
1040c046: mov ax, word ptr [0x1087f64c]
1040c04c: mov word ptr [ebp - 0x34], ax
1040c050: mov byte ptr [ebp - 0x170], 0
1040c057: push 0x100
1040c05c: push 0
1040c05e: lea ecx, [ebp - 0x16f]
1040c064: push ecx
1040c065: call 0x107a6860
1040c06a: add esp, 0xc
1040c06d: xor ecx, ecx
1040c06f: xor esi, esi
1040c071: mov dword ptr [ebp - 0x18], ecx
1040c074: mov dword ptr [ebp - 0x3c], esi
1040c077: cmp esi, 0x80
1040c07d: jge 0x1040c0dd
1040c07f: mov edx, ebx
1040c081: imul edx, edx, 0x81
1040c087: add edx, esi
1040c089: movzx edx, byte ptr [ebp + edx - 0x41f0]
1040c091: mov eax, edx
1040c093: shr eax, 4
1040c096: cmp al, 9
1040c098: ja 0x1040c09f
1040c09a: add eax, 0x30
1040c09d: jmp 0x1040c0a2
1040c09f: add eax, 0x37
1040c0a2: mov byte ptr [ebp + ecx - 0x170], al
1040c0a9: add ecx, 1
1040c0ac: mov dword ptr [ebp - 0x18], ecx
1040c0af: and dl, 0xf
1040c0b2: movzx eax, dl
1040c0b5: cmp al, 9
1040c0b7: ja 0x1040c0cb
1040c0b9: add eax, 0x30
1040c0bc: mov byte ptr [ebp + ecx - 0x170], al
1040c0c3: add ecx, 1
1040c0c6: add esi, 1
1040c0c9: jmp 0x1040c071
1040c0cb: add eax, 0x37
1040c0ce: mov byte ptr [ebp + ecx - 0x170], al
1040c0d5: add ecx, 1
1040c0d8: add esi, 1
1040c0db: jmp 0x1040c071
1040c0dd: mov eax, dword ptr [0x11d8dad0]
1040c0e2: cmp dword ptr [eax], 0
1040c0e5: je 0x1040c111
1040c0e7: mov ecx, dword ptr [eax]
1040c0e9: mov eax, dword ptr [ecx]
1040c0eb: push 0x24
1040c0ed: lea edx, [ebp - 0x6c]
1040c0f0: push edx
1040c0f1: mov edx, dword ptr [0x10b1f538]
1040c0f7: add edx, 0x64
1040c0fa: push edx
1040c0fb: push 0x24
1040c0fd: lea edx, [ebp - 0x64]
1040c100: push edx
1040c101: lea edx, [ebp - 0x38]
1040c104: push edx
1040c105: lea edx, [ebp - 0x170]
1040c10b: push edx
1040c10c: mov eax, dword ptr [eax + 8]
1040c10f: call eax
1040c111: lea ecx, [ebp - 0x28]
1040c114: push ecx
1040c115: lea edx, [ebp - 0x1c]
1040c118: push edx
1040c119: lea eax, [ebp - 0x20]
1040c11c: push eax
1040c11d: lea ecx, [ebp - 0x24]
1040c120: push ecx
1040c121: push 0x108810b0
1040c126: mov edi, dword ptr [ebp + 0xc]
1040c129: lea edx, [edi + 0x80]
1040c12f: push edx
1040c130: mov esi, dword ptr [ebp + 8]
1040c133: mov eax, dword ptr [esi + 0x4c]
1040c136: push eax
1040c137: call 0x103034e5
1040c13c: push 0x10b1b480
1040c141: push 0x11
1040c143: push 0x10883d08
1040c148: add edi, 0x90
1040c14e: push edi
1040c14f: mov ecx, dword ptr [esi + 0x4c]
1040c152: push ecx
1040c153: call 0x103034e5
1040c158: add esp, 0x30
1040c15b: mov edx, dword ptr [esi + 0x4c]
1040c15e: mov dword ptr [edx + 0x50b8], 0
1040c168: push 0x10
1040c16a: push 0x10b1b480
1040c16f: mov ecx, dword ptr [esi + 0x4c]
1040c172: add ecx, 0x6c3c
1040c178: call 0x10313165
1040c17d: push 3
1040c17f: mov eax, dword ptr [ebp - 0x1c]
1040c182: push eax
1040c183: push eax
1040c184: mov eax, dword ptr [ebp - 0x20]
1040c187: push eax
1040c188: mov ecx, dword ptr [ebp - 0x24]
1040c18b: push ecx
1040c18c: mov edx, dword ptr [0x10b1f538]
1040c192: mov ecx, dword ptr [edx + 0x54]
1040c195: call 0x10310f28
1040c19a: mov eax, dword ptr [0x11d8d6d0]
1040c19f: cmp dword ptr [eax], 0
1040c1a2: je 0x1040c1d2
1040c1a4: mov ecx, dword ptr [ebp - 0x28]
1040c1a7: push ecx
1040c1a8: mov edx, dword ptr [ebp - 0x1c]
1040c1ab: push edx
1040c1ac: mov ecx, dword ptr [ebp - 0x20]
1040c1af: push ecx
1040c1b0: mov edx, dword ptr [ebp - 0x24]
1040c1b3: push edx
1040c1b4: mov ecx, dword ptr [0x10b1f538]
1040c1ba: mov edx, dword ptr [ecx + 0xe4]
1040c1c0: push edx
1040c1c1: push 0x10883cc0
1040c1c6: mov eax, dword ptr [eax]
1040c1c8: push eax
1040c1c9: call dword ptr [0x11d8d6cc]
1040c1cf: add esp, 0x1c
1040c1d2: xor al, al
1040c1d4: mov ecx, dword ptr [ebp - 0xc]
1040c1d7: mov dword ptr fs:[0], ecx
1040c1de: pop edi
1040c1df: pop esi
1040c1e0: pop ebx
1040c1e1: mov esp, ebp
1040c1e3: pop ebp
1040c1e4: ret 
1040c1e5: mov ecx, dword ptr [ebp - 0x68]
1040c1e8: mov dword ptr [ebp - 0x2c], ecx
1040c1eb: push 0x10914c48
1040c1f0: lea edx, [ebp - 0x2c]
1040c1f3: push edx
1040c1f4: call 0x107a5ebf
1040c1f9: push 0x10883c8c
1040c1fe: push 0x10851d80
1040c203: call dword ptr [0x11d8d6bc]
1040c209: add esp, 8
1040c20c: push 0
1040c20e: push 0
1040c210: call 0x107a5ebf
