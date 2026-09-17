1043c1d0: push -1
1043c1d2: push 0x10810e86
1043c1d7: mov eax, dword ptr fs:[0]
1043c1dd: push eax
1043c1de: mov dword ptr fs:[0], esp
1043c1e5: push ecx
1043c1e6: mov eax, dword ptr [esp + 0x14]
1043c1ea: push esi
1043c1eb: mov esi, ecx
1043c1ed: push eax
1043c1ee: mov dword ptr [esp + 8], esi
1043c1f2: call 0x1030ddcd
1043c1f7: mov dword ptr [esp + 0x10], 0
1043c1ff: lea ecx, [esi + 0x5bf4]
1043c205: mov dword ptr [esi], 0x1088b69c
1043c20b: call dword ptr [0x11d8db38]
1043c211: lea ecx, [esi + 0x6c3c]
1043c217: call 0x10309acf
1043c21c: mov eax, 1
1043c221: mov byte ptr [esp + 0x10], al
1043c225: mov dword ptr [esi + 0x50bc], eax
1043c22b: mov dword ptr [esi + 0x50b8], eax
1043c231: mov dword ptr [esp + 0x10], 0xffffffff
1043c239: mov ecx, dword ptr [esp + 8]
1043c23d: mov eax, esi
1043c23f: pop esi
1043c240: mov dword ptr fs:[0], ecx
1043c247: add esp, 0x10
1043c24a: ret 4
