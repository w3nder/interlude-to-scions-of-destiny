1043c080: push -1
1043c082: push 0x10810e26
1043c087: mov eax, dword ptr fs:[0]
1043c08d: push eax
1043c08e: mov dword ptr fs:[0], esp
1043c095: push ecx
1043c096: push esi
1043c097: mov esi, ecx
1043c099: mov dword ptr [esp + 4], esi
1043c09d: call 0x1031178e
1043c0a2: mov dword ptr [esp + 0x10], 0
1043c0aa: lea ecx, [esi + 0x5bf4]
1043c0b0: mov dword ptr [esi], 0x1088b69c
1043c0b6: call dword ptr [0x11d8db38]
1043c0bc: lea ecx, [esi + 0x6c3c]
1043c0c2: call 0x10309acf
1043c0c7: mov eax, 1
1043c0cc: mov byte ptr [esp + 0x10], al
1043c0d0: mov dword ptr [esi + 0x50bc], eax
1043c0d6: mov dword ptr [esi + 0x50b8], eax
1043c0dc: mov dword ptr [esp + 0x10], 0xffffffff
1043c0e4: mov ecx, dword ptr [esp + 8]
1043c0e8: mov eax, esi
1043c0ea: pop esi
1043c0eb: mov dword ptr fs:[0], ecx
1043c0f2: add esp, 0x10
1043c0f5: ret 
