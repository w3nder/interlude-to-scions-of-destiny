103fdfe0: push -1
103fdfe2: push 0x107558f8
103fdfe7: mov eax, dword ptr fs:[0]
103fdfed: push eax
103fdfee: mov dword ptr fs:[0], esp
103fdff5: sub esp, 0x1c
103fdff8: push esi
103fdff9: mov esi, dword ptr [esp + 0x30]
103fdffd: lea eax, [esp + 0xc]
103fe001: push eax
103fe002: lea ecx, [esp + 8]
103fe006: push ecx
103fe007: mov ecx, dword ptr [esp + 0x3c]
103fe00b: lea edx, [esp + 0x10]
103fe00f: push edx
103fe010: mov edx, dword ptr [esi + 0x48]
103fe013: lea eax, [esp + 0x3c]
103fe017: push eax
103fe018: push 0x107bd8cc
103fe01d: push ecx
103fe01e: push edx
103fe01f: mov dword ptr [esp + 0x20], 0
103fe027: mov dword ptr [esp + 0x28], 0
103fe02f: call 0x10305079
103fe034: mov eax, dword ptr [esi + 0x48]
103fe037: mov ecx, dword ptr [esp + 0x20]
103fe03b: mov dword ptr [eax + 0x4f68], ecx
103fe041: mov eax, dword ptr [esp + 0x24]
103fe045: mov ecx, dword ptr [esi + 0x48]
103fe048: cdq 
103fe049: mov dword ptr [ecx + 0x4f74], eax
103fe04f: or edx, 0x87546ca1
103fe055: mov dword ptr [ecx + 0x4f78], edx
103fe05b: mov eax, dword ptr [esp + 0x24]
103fe05f: mov ecx, dword ptr [esi + 0x48]
103fe062: cdq 
103fe063: mov dword ptr [ecx + 0x4f6c], eax
103fe069: or edx, 0x87546ca1
103fe06f: add esp, 0x1c
103fe072: mov dword ptr [ecx + 0x4f70], edx
103fe078: push 0xa
103fe07a: lea ecx, [esp + 0x14]
103fe07e: call 0x1030218f
103fe083: movsx edx, byte ptr [esp + 0x30]
103fe088: push edx
103fe089: lea ecx, [esp + 0x14]
103fe08d: mov dword ptr [esp + 0x2c], 0
103fe095: call 0x103012c1
103fe09a: mov eax, dword ptr [esp + 0xc]
103fe09e: push eax
103fe09f: lea ecx, [esp + 0x14]
103fe0a3: call 0x103012c1
103fe0a8: mov ecx, dword ptr [0x109d5e68]
103fe0ae: mov ecx, dword ptr [ecx + 0x54]
103fe0b1: mov edx, dword ptr [ecx]
103fe0b3: lea eax, [esp + 0x10]
103fe0b7: push eax
103fe0b8: call dword ptr [edx + 0x33c]
103fe0be: mov ecx, dword ptr [0x142d7944]
103fe0c4: mov edx, dword ptr [ecx]
103fe0c6: mov esi, dword ptr [0x142d7780]
103fe0cc: push 0x107c12bc
103fe0d1: push edx
103fe0d2: call esi
103fe0d4: mov eax, dword ptr [0x10b36bbc]
103fe0d9: mov ecx, dword ptr [eax]
103fe0db: push 0x107c12bc
103fe0e0: push 2
103fe0e2: push eax
103fe0e3: call dword ptr [ecx + 0x2c0]
103fe0e9: mov edx, dword ptr [0x109d5e68]
103fe0ef: mov eax, dword ptr [edx + 0x48]
103fe0f2: mov edx, dword ptr [0x142d7978]
103fe0f8: mov edx, dword ptr [edx]
103fe0fa: mov ecx, dword ptr [eax]
103fe0fc: push edx
103fe0fd: mov edx, dword ptr [0x109d7870]
103fe103: push edx
103fe104: mov edx, dword ptr [0x109d786c]
103fe10a: push edx
103fe10b: mov edx, dword ptr [0x109d7888]
103fe111: push edx
103fe112: mov edx, dword ptr [0x109d7884]
103fe118: push edx
103fe119: push 0x109d788c
103fe11e: push 8
103fe120: push 0x107c12b0
103fe125: push eax
103fe126: call dword ptr [ecx + 0x64]
103fe129: mov eax, dword ptr [0x142d7944]
103fe12e: mov ecx, dword ptr [eax]
103fe130: push 0x107c127c
103fe135: push ecx
103fe136: call esi
103fe138: mov eax, dword ptr [0x10b36bbc]
103fe13d: mov edx, dword ptr [eax]
103fe13f: add esp, 0x40
103fe142: push 0x107c127c
103fe147: push 2
103fe149: push eax
103fe14a: call dword ptr [edx + 0x2c0]
103fe150: add esp, 0xc
103fe153: lea ecx, [esp + 0x10]
103fe157: mov dword ptr [esp + 0x28], 0xffffffff
103fe15f: call 0x10307f3b
103fe164: mov ecx, dword ptr [esp + 0x20]
103fe168: xor al, al
103fe16a: pop esi
103fe16b: mov dword ptr fs:[0], ecx
103fe172: add esp, 0x28
103fe175: ret 
103fe176: nop 
103fe177: nop 
103fe178: nop 
103fe179: nop 
103fe17a: nop 
103fe17b: nop 
103fe17c: nop 
103fe17d: nop 
103fe17e: nop 
103fe17f: nop 
