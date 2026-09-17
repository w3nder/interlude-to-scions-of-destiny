10403040: mov eax, 0x2004
10403045: call 0x107a69d0
1040304a: push ebx
1040304b: push esi
1040304c: mov esi, dword ptr [esp + 0x2010]
10403053: push edi
10403054: lea ebx, [esi + 0x4efc]
1040305a: push ebx
1040305b: call dword ptr [0x11d8e91c]
10403061: mov edi, dword ptr [esp + 0x2018]
10403068: test edi, edi
1040306a: je 0x104030f1
10403070: test esi, esi
10403072: je 0x104030f1
10403074: push 0x2000
10403079: lea eax, [esp + 0x14]
1040307d: push 0
1040307f: push eax
10403080: call 0x107a6860
10403085: lea ecx, [esp + 0x2028]
1040308c: push ecx
1040308d: push edi
1040308e: lea edx, [esp + 0x26]
10403092: push 0x1ffe
10403097: push edx
10403098: call 0x103068b6
1040309d: add esp, 0x1c
104030a0: test eax, eax
104030a2: mov dword ptr [esp + 0xc], eax
104030a6: je 0x104030f1
104030a8: cmp dword ptr [esi + 0x50bc], 0
104030af: je 0x104030cb
104030b1: mov eax, dword ptr [esi]
104030b3: mov eax, dword ptr [eax + 0x80]
104030b9: lea ecx, [esp + 0xc]
104030bd: push ecx
104030be: lea edx, [esp + 0x16]
104030c2: push edx
104030c3: mov ecx, esi
104030c5: call eax
104030c7: mov eax, dword ptr [esp + 0xc]
104030cb: add eax, 2
104030ce: push 0
104030d0: push eax
104030d1: mov ecx, eax
104030d3: lea edx, [esp + 0x18]
104030d7: mov dword ptr [esp + 0x14], eax
104030db: mov byte ptr [esp + 0x18], al
104030df: mov eax, dword ptr [esi + 0x38]
104030e2: push edx
104030e3: sar ecx, 8
104030e6: push eax
104030e7: mov byte ptr [esp + 0x21], cl
104030eb: call dword ptr [0x11d8eb64]
104030f1: push ebx
104030f2: call dword ptr [0x11d8e918]
104030f8: pop edi
104030f9: pop esi
104030fa: pop ebx
104030fb: add esp, 0x2004
10403101: ret 
