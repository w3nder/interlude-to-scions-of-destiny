10402070: sub esp, 8
10402073: push ebp
10402074: mov ebp, dword ptr [esp + 0x18]
10402078: push esi
10402079: mov esi, dword ptr [esp + 0x14]
1040207d: mov dl, byte ptr [esi]
1040207f: push edi
10402080: mov edi, dword ptr [esp + 0x1c]
10402084: mov al, byte ptr [edi + 1]
10402087: xor al, dl
10402089: mov byte ptr [esi], al
1040208b: mov eax, 1
10402090: cmp ebp, eax
10402092: jle 0x104020b2
10402094: push ebx
10402095: mov cl, byte ptr [eax + esi]
10402098: mov ebx, eax
1040209a: and ebx, 0xf
1040209d: mov bl, byte ptr [ebx + edi + 1]
104020a1: xor bl, cl
104020a3: xor bl, dl
104020a5: mov byte ptr [eax + esi], bl
104020a8: add eax, 1
104020ab: cmp eax, ebp
104020ad: mov dl, cl
104020af: jl 0x10402095
104020b1: pop ebx
104020b2: push 8
104020b4: lea esi, [edi + 9]
104020b7: push esi
104020b8: xor eax, eax
104020ba: lea ecx, [esp + 0x14]
104020be: push 8
104020c0: push ecx
104020c1: mov dword ptr [esp + 0x1c], eax
104020c5: mov dword ptr [esp + 0x20], eax
104020c9: call 0x107a67d9
104020ce: mov eax, ebp
104020d0: cdq 
104020d1: add dword ptr [esp + 0x1c], eax
104020d5: push 8
104020d7: adc dword ptr [esp + 0x24], edx
104020db: lea edx, [esp + 0x20]
104020df: push edx
104020e0: push 8
104020e2: push esi
104020e3: call 0x107a67d9
104020e8: add esp, 0x20
104020eb: pop edi
104020ec: pop esi
104020ed: pop ebp
104020ee: add esp, 8
104020f1: ret 0xc
