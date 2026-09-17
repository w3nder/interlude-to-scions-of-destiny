104031c0: mov eax, dword ptr [esp + 8]
104031c4: test al, 7
104031c6: jne 0x104031eb
104031c8: cmp dword ptr [ecx + 0x50b8], 0
104031cf: mov dword ptr [esp + 8], eax
104031d3: je 0x104031e0
104031d5: add ecx, 0x6c3c
104031db: jmp 0x1030a45c
104031e0: add ecx, 0x6c3c
104031e6: jmp 0x10309197
104031eb: ret 8
