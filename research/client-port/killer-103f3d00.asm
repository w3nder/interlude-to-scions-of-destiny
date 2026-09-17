103f3d00 push ebx
103f3d01 mov ebx, dword ptr [esp + 8]
103f3d05 push esi
103f3d06 push edi
103f3d07 mov edi, dword ptr [esp + 0x14]
103f3d0b mov eax, dword ptr [edi]
103f3d0d add eax, 7
103f3d10 and eax, 0xfffffff8
103f3d13 mov dword ptr [edi], eax
103f3d15 sar eax, 2
103f3d18 xor esi, esi
103f3d1a xor edx, edx
103f3d1c test eax, eax
103f3d1e jle 0x103f3d28
103f3d20 xor esi, dword ptr [ebx + edx*4]
103f3d23 inc edx
103f3d24 cmp edx, eax
103f3d26 jl 0x103f3d20
103f3d28 mov dword ptr [ebx + edx*4], esi
103f3d2b mov esi, dword ptr [edi]
103f3d2d add esi, 8
103f3d30 mov dword ptr [edi], esi
103f3d32 mov edi, esi
103f3d34 push edi
103f3d35 push ebx
103f3d36 add ecx, 0x592c
103f3d3c call dword ptr [0x142d794c]
103f3d42 pop edi
103f3d43 pop esi
103f3d44 pop ebx
103f3d45 ret 8
103f3d48 nop 
103f3d49 nop 
103f3d4a nop 
103f3d4b nop 
103f3d4c nop 
103f3d4d nop 
103f3d4e nop 
103f3d4f nop 
