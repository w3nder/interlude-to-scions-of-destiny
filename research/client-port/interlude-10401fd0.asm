10401fd0: mov ecx, dword ptr [esp + 4]
10401fd4: sub esp, 8
10401fd7: push esi
10401fd8: mov esi, dword ptr [esp + 0x14]
10401fdc: mov al, byte ptr [esi + 1]
10401fdf: xor byte ptr [ecx], al
10401fe1: push edi
10401fe2: mov edi, dword ptr [esp + 0x1c]
10401fe6: mov eax, 1
10401feb: cmp edi, eax
10401fed: jle 0x10402008
10401fef: nop 
10401ff0: mov edx, eax
10401ff2: and edx, 0xf
10401ff5: mov dl, byte ptr [edx + esi + 1]
10401ff9: xor dl, byte ptr [eax + ecx - 1]
10401ffd: add eax, 1
10402000: xor byte ptr [eax + ecx - 1], dl
10402004: cmp eax, edi
10402006: jl 0x10401ff0
10402008: xor eax, eax
1040200a: push 8
1040200c: add esi, 9
1040200f: push esi
10402010: mov dword ptr [esp + 0x10], eax
10402014: mov dword ptr [esp + 0x14], eax
10402018: lea eax, [esp + 0x10]
1040201c: push 8
1040201e: push eax
1040201f: call 0x107a67d9
10402024: mov eax, edi
10402026: cdq 
10402027: add dword ptr [esp + 0x18], eax
1040202b: push 8
1040202d: lea ecx, [esp + 0x1c]
10402031: adc dword ptr [esp + 0x20], edx
10402035: push ecx
10402036: push 8
10402038: push esi
10402039: call 0x107a67d9
1040203e: add esp, 0x20
10402041: pop edi
10402042: pop esi
10402043: add esp, 8
10402046: ret 0xc
