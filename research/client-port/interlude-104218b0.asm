104218b0 push ebp
104218b1 mov ebp, esp
104218b3 push -1
104218b5 push 0x1080fbe0
104218ba mov eax, dword ptr fs:[0]
104218c0 push eax
104218c1 mov dword ptr fs:[0], esp
104218c8 sub esp, 0x24
104218cb push ebx
104218cc push esi
104218cd push edi
104218ce mov dword ptr [ebp - 0x10], esp
104218d1 mov esi, ecx
104218d3 mov dword ptr [ebp - 0x2c], esi
104218d6 xor ebx, ebx
104218d8 mov dword ptr [ebp - 4], ebx
104218db wait 
104218dc mov eax, dword ptr [0x10ddd7ec]
104218e1 mov ecx, dword ptr [0x10ddd91c]
104218e7 mov edx, dword ptr [eax + ecx*4]
104218ea fild dword ptr [eax + ecx*4]
104218ed test edx, edx
104218ef jge 0x104218f7
104218f1 fadd qword ptr [0x10888818]
104218f7 mov eax, dword ptr [0x11d8db1c]
104218fc fmul qword ptr [eax]
104218fe fstp dword ptr [ebp - 0x14]
10421901 fldz 
10421903 fcom dword ptr [esi + 0x18c]
10421909 fnstsw ax
1042190b test ah, 0x44
1042190e jnp 0x10421929
10421910 fld dword ptr [esi + 0x18c]
10421916 fmul qword ptr [0x10888808]
1042191c fld dword ptr [ebp - 0x14]
1042191f fmul qword ptr [0x108887f8]
10421925 faddp st(1)
10421927 jmp 0x1042192c
10421929 fld dword ptr [ebp - 0x14]
1042192c fstp dword ptr [esi + 0x18c]
10421932 mov ecx, dword ptr [0x10b1f538]
10421938 cmp dword ptr [ecx + 0x50], 2
1042193c jne 0x10421af5
10421942 mov eax, dword ptr [esi + 0x48]
10421945 cmp eax, ebx
10421947 je 0x10421af5
1042194d fld dword ptr [eax + 0x4960]
10421953 fld dword ptr [ebp + 8]
10421956 fld st(0)
10421958 faddp st(2)
1042195a fxch st(1)
1042195c fstp dword ptr [eax + 0x4960]
10421962 mov eax, dword ptr [esi + 0x48]
10421965 fadd dword ptr [eax + 0x4964]
1042196b fstp dword ptr [eax + 0x4964]
10421971 mov ecx, dword ptr [esi + 0x48]
10421974 mov edx, dword ptr [ecx + 0x4970]
1042197a fild dword ptr [ecx + 0x4970]
10421980 test edx, edx
10421982 jge 0x1042198a
10421984 fadd qword ptr [0x10888818]
1042198a fdiv dword ptr [ecx + 0x4960]
10421990 fnstcw word ptr [ebp - 0x12]
10421993 movzx eax, word ptr [ebp - 0x12]
10421997 or eax, 0xc00
1042199c mov dword ptr [ebp - 0x18], eax
1042199f fldcw word ptr [ebp - 0x18]
104219a2 fistp qword ptr [ebp - 0x1c]
104219a5 fldcw word ptr [ebp - 0x12]
104219a8 mov eax, dword ptr [ebp - 0x1c]
104219ab mov ecx, dword ptr [ecx + 0x50f4]
104219b1 mov edx, dword ptr [0x10ddd7e0]
104219b7 mov dword ptr [edx + ecx*4], eax
104219ba mov ecx, dword ptr [esi + 0x48]
104219bd mov eax, dword ptr [ecx + 0x4978]
104219c3 fild dword ptr [ecx + 0x4978]
104219c9 test eax, eax
104219cb jge 0x104219d3
104219cd fadd qword ptr [0x10888818]
104219d3 fdiv dword ptr [ecx + 0x4960]
104219d9 fnstcw word ptr [ebp - 0x12]
104219dc movzx eax, word ptr [ebp - 0x12]
104219e0 or eax, 0xc00
104219e5 mov dword ptr [ebp - 0x18], eax
104219e8 fldcw word ptr [ebp - 0x18]
104219eb fistp qword ptr [ebp - 0x1c]
104219ee fldcw word ptr [ebp - 0x12]
104219f1 mov edx, dword ptr [ebp - 0x1c]
104219f4 mov eax, dword ptr [ecx + 0x50fc]
104219fa mov ecx, dword ptr [0x10ddd7e0]
10421a00 mov dword ptr [ecx + eax*4], edx
10421a03 mov ecx, dword ptr [esi + 0x48]
10421a06 fld1 
10421a08 fcomp dword ptr [ecx + 0x4964]
10421a0e fnstsw ax
10421a10 test ah, 0x41
10421a13 jp 0x10421ac3
10421a19 mov edx, dword ptr [ecx + 0x4974]
10421a1f fild dword ptr [ecx + 0x4974]
10421a25 test edx, edx
10421a27 jge 0x10421a2f
10421a29 fadd qword ptr [0x10888818]
10421a2f fdiv dword ptr [ecx + 0x4964]
10421a35 fnstcw word ptr [ebp - 0x12]
10421a38 movzx eax, word ptr [ebp - 0x12]
10421a3c or eax, 0xc00
10421a41 mov dword ptr [ebp - 0x18], eax
10421a44 fldcw word ptr [ebp - 0x18]
10421a47 fistp qword ptr [ebp - 0x1c]
10421a4a fldcw word ptr [ebp - 0x12]
10421a4d mov eax, dword ptr [ebp - 0x1c]
10421a50 cmp eax, dword ptr [ecx + 0x4968]
10421a56 jbe 0x10421a5e
10421a58 mov dword ptr [ecx + 0x4968], eax
10421a5e mov ecx, dword ptr [esi + 0x48]
10421a61 mov eax, dword ptr [ecx + 0x497c]
10421a67 fild dword ptr [ecx + 0x497c]
10421a6d test eax, eax
10421a6f jge 0x10421a77
10421a71 fadd qword ptr [0x10888818]
10421a77 fdiv dword ptr [ecx + 0x4964]
10421a7d fnstcw word ptr [ebp - 0x12]
10421a80 movzx eax, word ptr [ebp - 0x12]
10421a84 or eax, 0xc00
10421a89 mov dword ptr [ebp - 0x18], eax
10421a8c fldcw word ptr [ebp - 0x18]
10421a8f fistp qword ptr [ebp - 0x1c]
10421a92 fldcw word ptr [ebp - 0x12]
10421a95 mov eax, dword ptr [ebp - 0x1c]
10421a98 cmp eax, dword ptr [ecx + 0x496c]
10421a9e jbe 0x10421aa6
10421aa0 mov dword ptr [ecx + 0x496c], eax
10421aa6 mov ecx, dword ptr [esi + 0x48]
10421aa9 fstp dword ptr [ecx + 0x4964]
10421aaf mov edx, dword ptr [esi + 0x48]
10421ab2 mov dword ptr [edx + 0x4974], ebx
10421ab8 mov eax, dword ptr [esi + 0x48]
10421abb mov dword ptr [eax + 0x497c], ebx
10421ac1 jmp 0x10421ac5
10421ac3 fstp st(0)
10421ac5 mov eax, dword ptr [esi + 0x48]
10421ac8 mov ecx, dword ptr [eax + 0x50f8]
10421ace mov edx, dword ptr [eax + 0x4968]
10421ad4 mov eax, dword ptr [0x10ddd7e0]
10421ad9 mov dword ptr [eax + ecx*4], edx
10421adc mov eax, dword ptr [esi + 0x48]
10421adf mov ecx, dword ptr [eax + 0x5100]
10421ae5 mov edx, dword ptr [eax + 0x496c]
10421aeb mov eax, dword ptr [0x10ddd7e0]
10421af0 mov dword ptr [eax + ecx*4], edx
10421af3 jmp 0x10421af7
10421af5 fstp st(0)
10421af7 lea edi, [esi + 0x38]
10421afa mov edx, dword ptr [esi]
10421afc push edi
10421afd mov ecx, esi
10421aff mov eax, dword ptr [edx + 0x80]
10421b05 call eax
10421b07 test eax, eax
10421b09 je 0x10421d87
10421b0f mov ecx, dword ptr [0x10b1f538]
10421b15 mov eax, dword ptr [ecx + 0x50]
10421b18 cmp eax, 1
10421b1b jne 0x10421b83
10421b1d mov eax, dword ptr [edi]
10421b1f cmp byte ptr [eax], 0xc
10421b22 jb 0x10421b27
10421b24 mov byte ptr [eax], 0xc
10421b27 mov eax, dword ptr [edi]
10421b29 mov edx, dword ptr [eax + 8]
10421b2c add edx, dword ptr [eax + 4]
10421b2f mov eax, dword ptr [esi + 0x4c]
10421b32 mov dword ptr [eax + 0x4ef8], edx
10421b38 mov eax, dword ptr [edi]
10421b3a movzx ecx, byte ptr [eax]
10421b3d mov edx, dword ptr [eax + 8]
10421b40 push edx
10421b41 push esi
10421b42 mov eax, dword ptr [ecx*4 + 0x10a572c0]
10421b49 call eax
10421b4b add esp, 8
10421b4e mov ecx, dword ptr [esi + 0x4c]
10421b51 mov dword ptr [ecx + 0x4ef8], ebx
10421b57 mov edx, dword ptr [0x11d8d6a0]
10421b5d mov ecx, dword ptr [edx]
10421b5f mov eax, dword ptr [ecx]
10421b61 mov edx, dword ptr [edi]
10421b63 mov edx, dword ptr [edx + 8]
10421b66 push edx
10421b67 mov eax, dword ptr [eax + 8]
10421b6a call eax
10421b6c mov ecx, dword ptr [0x11d8d6a0]
10421b72 mov ecx, dword ptr [ecx]
10421b74 mov eax, dword ptr [edi]
10421b76 mov edx, dword ptr [ecx]
10421b78 push eax
10421b79 mov edx, dword ptr [edx + 8]
10421b7c call edx
10421b7e jmp 0x10421af7
10421b83 cmp eax, 2
10421b86 je 0x10421b95
10421b88 mov eax, dword ptr [0x11d8db18]
10421b8d cmp dword ptr [eax], ebx
10421b8f je 0x10421af7
10421b95 mov ecx, dword ptr [0x11d8db14]
10421b9b cmp dword ptr [ecx], ebx
10421b9d je 0x10421bcf
10421b9f mov eax, dword ptr [0x10c51044]
10421ba4 cmp dword ptr [eax + 0x198], ebx
10421baa je 0x10421bcf
10421bac mov ecx, dword ptr [eax + 0x198]
10421bb2 call 0x1030fc95
10421bb7 cmp eax, 2
10421bba jne 0x10421bcf
10421bbc mov edx, dword ptr [edi]
10421bbe push edx
10421bbf mov eax, dword ptr [0x10c51044]
10421bc4 mov ecx, dword ptr [eax + 0x198]
10421bca call 0x1030780b
10421bcf mov eax, dword ptr [edi]
10421bd1 cmp byte ptr [eax], 0xff
10421bd4 jb 0x10421bd9
10421bd6 mov byte ptr [eax], 0xff
10421bd9 mov ecx, dword ptr [edi]
10421bdb mov cl, byte ptr [ecx]
10421bdd mov eax, dword ptr [esi + 0x48]
10421be0 cmp cl, 0xfe
10421be3 jne 0x10421ccd
10421be9 cmp dword ptr [eax + 0x4ef0], ebx
10421bef je 0x10421c20
10421bf1 mov edx, dword ptr [eax + 0x58fc]
10421bf7 mov eax, dword ptr [0x10ddd7e0]
10421bfc lea ecx, [eax + edx*4]
10421bff rdtsc 
10421c01 sub dword ptr [ecx], eax
10421c03 mov ecx, dword ptr [edi]
10421c05 movsx edx, word ptr [ecx + 2]
10421c09 mov eax, dword ptr [esi + 0x48]
10421c0c mov ecx, dword ptr [eax + edx*4 + 0x5a74]
10421c13 mov edx, dword ptr [0x10ddd7e0]
10421c19 lea ecx, [edx + ecx*4]
10421c1c rdtsc 
10421c1e sub dword ptr [ecx], eax
10421c20 mov eax, dword ptr [edi]
10421c22 mov ecx, dword ptr [eax + 8]
10421c25 add ecx, dword ptr [eax + 4]
10421c28 mov edx, dword ptr [esi + 0x48]
10421c2b mov dword ptr [edx + 0x4ef8], ecx
10421c31 mov eax, dword ptr [edi]
10421c33 movsx ecx, word ptr [eax + 2]
10421c37 imul ecx, ecx, 0x104
10421c3d mov edx, dword ptr [eax + 8]
10421c40 push edx
10421c41 push esi
10421c42 mov eax, dword ptr [ecx + 0x10a67610]
10421c48 call eax
10421c4a add esp, 8
10421c4d mov ecx, dword ptr [esi + 0x48]
10421c50 mov dword ptr [ecx + 0x4ef8], ebx
10421c56 mov eax, dword ptr [esi + 0x48]
10421c59 cmp eax, ebx
10421c5b je 0x10421d5c
10421c61 cmp dword ptr [eax + 0x4ef0], ebx
10421c67 je 0x10421d5c
10421c6d mov edx, dword ptr [edi]
10421c6f movzx ecx, byte ptr [edx]
10421c72 lea eax, [eax + ecx*4 + 0x4980]
10421c79 add dword ptr [eax], 1
10421c7c mov edx, dword ptr [edi]
10421c7e movzx eax, byte ptr [edx]
10421c81 mov ecx, dword ptr [esi + 0x48]
10421c84 mov edx, dword ptr [ecx + eax*4 + 0x5504]
10421c8b mov eax, dword ptr [0x10ddd7e0]
10421c90 lea ecx, [eax + edx*4]
10421c93 rdtsc 
10421c95 add eax, -0xc
10421c98 add dword ptr [ecx], eax
10421c9a mov ecx, dword ptr [edi]
10421c9c movsx edx, word ptr [ecx + 2]
10421ca0 mov eax, dword ptr [esi + 0x48]
10421ca3 lea eax, [eax + edx*4 + 0x4d7c]
10421caa add dword ptr [eax], 1
10421cad mov ecx, dword ptr [edi]
10421caf movsx edx, word ptr [ecx + 2]
10421cb3 mov eax, dword ptr [esi + 0x48]
10421cb6 mov ecx, dword ptr [eax + edx*4 + 0x5a74]
10421cbd mov edx, dword ptr [0x10ddd7e0]
10421cc3 lea ecx, [edx + ecx*4]
10421cc6 rdtsc 
10421cc8 jmp 0x10421d57
10421ccd cmp dword ptr [eax + 0x4ef0], ebx
10421cd3 je 0x10421ceb
10421cd5 movzx ecx, cl
10421cd8 mov edx, dword ptr [eax + ecx*4 + 0x5504]
10421cdf mov eax, dword ptr [0x10ddd7e0]
10421ce4 lea ecx, [eax + edx*4]
10421ce7 rdtsc 
10421ce9 sub dword ptr [ecx], eax
10421ceb mov eax, dword ptr [edi]
10421ced mov ecx, dword ptr [eax + 8]
10421cf0 add ecx, dword ptr [eax + 4]
10421cf3 mov edx, dword ptr [esi + 0x48]
10421cf6 mov dword ptr [edx + 0x4ef8], ecx
10421cfc mov eax, dword ptr [edi]
10421cfe movzx ecx, byte ptr [eax]
10421d01 imul ecx, ecx, 0x104
10421d07 mov edx, dword ptr [eax + 8]
10421d0a push edx
10421d0b push esi
10421d0c mov eax, dword ptr [ecx + 0x10a57310]
10421d12 call eax
10421d14 add esp, 8
10421d17 mov ecx, dword ptr [esi + 0x48]
10421d1a mov dword ptr [ecx + 0x4ef8], ebx
10421d20 mov eax, dword ptr [esi + 0x48]
10421d23 cmp eax, ebx
10421d25 je 0x10421d5c
10421d27 cmp dword ptr [eax + 0x4ef0], ebx
10421d2d je 0x10421d5c
10421d2f mov edx, dword ptr [edi]
10421d31 movzx ecx, byte ptr [edx]
10421d34 lea eax, [eax + ecx*4 + 0x4980]
10421d3b add dword ptr [eax], 1
10421d3e mov edx, dword ptr [edi]
10421d40 movzx eax, byte ptr [edx]
10421d43 mov ecx, dword ptr [esi + 0x48]
10421d46 mov edx, dword ptr [ecx + eax*4 + 0x5504]
10421d4d mov eax, dword ptr [0x10ddd7e0]
10421d52 lea ecx, [eax + edx*4]
10421d55 rdtsc 
10421d57 add eax, -0xc
10421d5a add dword ptr [ecx], eax
10421d5c mov ecx, dword ptr [0x11d8d6a0]
10421d62 mov ecx, dword ptr [ecx]
10421d64 mov edx, dword ptr [ecx]
10421d66 mov eax, dword ptr [edi]
10421d68 mov eax, dword ptr [eax + 8]
10421d6b push eax
10421d6c mov edx, dword ptr [edx + 8]
10421d6f call edx
10421d71 mov eax, dword ptr [0x11d8d6a0]
10421d76 mov ecx, dword ptr [eax]
10421d78 mov eax, dword ptr [edi]
10421d7a mov edx, dword ptr [ecx]
10421d7c push eax
10421d7d mov edx, dword ptr [edx + 8]
10421d80 call edx
10421d82 jmp 0x10421af7
10421d87 mov eax, dword ptr [esi]
10421d89 push ecx
10421d8a fld dword ptr [ebp + 8]
10421d8d fstp dword ptr [esp]
10421d90 mov ecx, esi
10421d92 mov edx, dword ptr [eax + 0x530]
10421d98 call edx
10421d9a mov eax, dword ptr [0x10b1f538]
10421d9f cmp dword ptr [eax + 0x50], 2
10421da3 jne 0x10421dfe
10421da5 cmp dword ptr [esi + 0x48], ebx
10421da8 je 0x10421dfe
10421daa xor eax, eax
10421dac mov dword ptr [ebp - 0x20], eax
10421daf cmp eax, 0xff
10421db4 jge 0x10421dd5
10421db6 mov ecx, dword ptr [esi + 0x48]
10421db9 mov edx, dword ptr [ecx + eax*4 + 0x5108]
10421dc0 mov ecx, dword ptr [ecx + eax*4 + 0x4980]
10421dc7 mov edi, dword ptr [0x10ddd7e0]
10421dcd mov dword ptr [edi + edx*4], ecx
10421dd0 add eax, 1
10421dd3 jmp 0x10421dac
10421dd5 xor eax, eax
10421dd7 mov dword ptr [ebp - 0x24], eax
10421dda cmp eax, 0x5d
10421ddd jge 0x10421dfe
10421ddf mov ecx, dword ptr [esi + 0x48]
10421de2 mov edx, dword ptr [ecx + eax*4 + 0x5900]
10421de9 mov ecx, dword ptr [ecx + eax*4 + 0x4d7c]
10421df0 mov edi, dword ptr [0x10ddd7e0]
10421df6 mov dword ptr [edi + edx*4], ecx
10421df9 add eax, 1
10421dfc jmp 0x10421dd7
10421dfe wait 
10421dff mov dword ptr [ebp - 4], 0xffffffff
10421e06 mov ecx, dword ptr [ebp - 0xc]
10421e09 mov dword ptr fs:[0], ecx
10421e10 pop edi
10421e11 pop esi
10421e12 pop ebx
10421e13 mov esp, ebp
10421e15 pop ebp
10421e16 ret 4
10421e19 mov edx, dword ptr [ebp - 0x30]
10421e1c mov dword ptr [ebp - 0x28], edx
10421e1f push 0x10914c48
10421e24 lea eax, [ebp - 0x28]
10421e27 push eax
10421e28 call 0x107a5ebf
10421e2d push 0x108887c4
10421e32 push 0x10851d80
10421e37 mov esi, dword ptr [0x11d8d6bc]
10421e3d call esi
10421e3f add esp, 8
10421e42 mov ecx, dword ptr [ebp - 0x2c]
10421e45 mov eax, dword ptr [ecx + 0x38]
10421e48 mov cl, byte ptr [eax]
10421e4a cmp cl, 0xfe
10421e4d jne 0x10421e60
10421e4f movsx eax, word ptr [eax + 2]
10421e53 imul eax, eax, 0x104
10421e59 add eax, 0x10a67614
10421e5e jmp 0x10421e6e
10421e60 movzx eax, cl
10421e63 imul eax, eax, 0x104
10421e69 add eax, 0x10a57314
10421e6e push eax
10421e6f push 0x1088879c
10421e74 call esi
10421e76 add esp, 8
10421e79 xor ebx, ebx
10421e7b push ebx
10421e7c push ebx
10421e7d call 0x107a5ebf
