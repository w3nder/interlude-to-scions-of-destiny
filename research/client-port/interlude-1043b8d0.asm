1043b8d0: push -1
1043b8d2: push 0x10810c0f
1043b8d7: mov eax, dword ptr fs:[0]
1043b8dd: push eax
1043b8de: mov dword ptr fs:[0], esp
1043b8e5: sub esp, 8
1043b8e8: push ebx
1043b8e9: push esi
1043b8ea: mov esi, ecx
1043b8ec: push edi
1043b8ed: mov dword ptr [esp + 0xc], esi
1043b8f1: call dword ptr [0x11d8d770]
1043b8f7: xor ebx, ebx
1043b8f9: mov dword ptr [esp + 0x1c], ebx
1043b8fd: lea ecx, [esi + 0x4f14]
1043b903: mov dword ptr [esi], 0x1088b52c
1043b909: mov dword ptr [esp + 0x10], ecx
1043b90d: call 0x1030197e
1043b912: mov byte ptr [esp + 0x1c], 2
1043b917: lea ecx, [esi + 0x4f28]
1043b91d: mov dword ptr [esp + 0x10], ecx
1043b921: call 0x1030c32e
1043b926: mov byte ptr [esp + 0x1c], 4
1043b92b: lea ecx, [esi + 0x4f3c]
1043b931: mov dword ptr [esp + 0x10], ecx
1043b935: call 0x1030b573
1043b93a: mov byte ptr [esp + 0x1c], 6
1043b93f: lea ecx, [esi + 0x4f50]
1043b945: mov dword ptr [esp + 0x10], ecx
1043b949: call 0x10306663
1043b94e: mov byte ptr [esp + 0x1c], 8
1043b953: lea ecx, [esi + 0x5024]
1043b959: mov word ptr [esi + 0x4f6c], bx
1043b960: mov dword ptr [esi + 0x5010], ebx
1043b966: mov dword ptr [esi + 0x4f68], 0xffffffff
1043b970: mov dword ptr [esi + 0x5018], ebx
1043b976: call 0x1030552e
1043b97b: mov byte ptr [esp + 0x1c], 9
1043b980: mov byte ptr [esi + 0x50c0], bl
1043b986: xor eax, eax
1043b988: mov dword ptr [esi + 0x50c1], eax
1043b98e: mov dword ptr [esi + 0x50c5], eax
1043b994: mov dword ptr [esi + 0x50c9], eax
1043b99a: mov dword ptr [esi + 0x50cd], eax
1043b9a0: mov byte ptr [esi + 0x50d1], bl
1043b9a6: mov dword ptr [esi + 0x50d2], eax
1043b9ac: mov dword ptr [esi + 0x50d6], eax
1043b9b2: lea edi, [esi + 0x50e4]
1043b9b8: mov dword ptr [esi + 0x50da], eax
1043b9be: mov ecx, edi
1043b9c0: mov dword ptr [esi + 0x50de], eax
1043b9c6: call 0x10306e1f
1043b9cb: lea eax, [esi + 0x4efc]
1043b9d1: push eax
1043b9d2: mov dword ptr [esi + 0x50bc], ebx
1043b9d8: mov dword ptr [esi + 0x4ef0], ebx
1043b9de: mov dword ptr [esi + 0x4ef4], ebx
1043b9e4: call dword ptr [0x11d8e930]
1043b9ea: mov ecx, edi
1043b9ec: call 0x103022fc
1043b9f1: mov dword ptr [esi + 0x4ef8], ebx
1043b9f7: mov dword ptr [esp + 0x1c], 0xffffffff
1043b9ff: mov ecx, dword ptr [esp + 0x14]
1043ba03: pop edi
1043ba04: mov eax, esi
1043ba06: pop esi
1043ba07: pop ebx
1043ba08: mov dword ptr fs:[0], ecx
1043ba0f: add esp, 0x14
1043ba12: ret 
