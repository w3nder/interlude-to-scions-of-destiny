(Send)Send Protocol Version:%d
103f2880: push ebp
103f2881: mov ebp, esp
103f2883: and esp, 0xfffffff8
103f2886: sub esp, 0x80c
103f288c: mov eax, dword ptr [ebp + 0xc]
103f288f: push ebx
103f2890: push esi
103f2891: shr eax, 0x10
103f2894: test ax, ax
103f2897: push edi
103f2898: mov esi, ecx
103f289a: jne 0x103f2a0e
103f28a0: mov eax, dword ptr [esi + 0x34]
103f28a3: mov ecx, dword ptr [esi + 0x38]
103f28a6: push 0x25
103f28a8: push 0x503
103f28ad: push eax
103f28ae: push ecx
103f28af: call dword ptr [0x142d8930]
103f28b5: test eax, eax
103f28b7: je 0x103f28e7
103f28b9: call dword ptr [0x142d8934]
103f28bf: mov edx, dword ptr [esi + 0x38]
103f28c2: push edx
103f28c3: push eax
103f28c4: push 0x107bcdd4
103f28c9: call 0x10314137
103f28ce: add esp, 0xc
103f28d1: add esi, 0x4e4c
103f28d7: push esi
103f28d8: call dword ptr [0x142d873c]
103f28de: pop edi
103f28df: pop esi
103f28e0: pop ebx
103f28e1: mov esp, ebp
103f28e3: pop ebp
103f28e4: ret 8
103f28e7: push 0
103f28e9: push 0x107bcf5c
103f28ee: push 0x107bcf34
103f28f3: call 0x10314137
103f28f8: lea eax, [esp + 0x23]
103f28fc: push eax
103f28fd: lea ecx, [esp + 0x20]
103f2901: push ecx
103f2902: lea edx, [esp + 0x23]
103f2906: push edx
103f2907: push 0x107bcf1c
103f290c: push 0x107bcf08
103f2911: call dword ptr [0x142d87f0]
103f2917: xor eax, eax
103f2919: mov byte ptr [esp + 0x38], 0
103f291e: mov ecx, 0x1ff
103f2923: lea edi, [esp + 0x39]
103f2927: rep stosd dword ptr es:[edi], eax
103f2929: stosw word ptr es:[edi], ax
103f292b: stosb byte ptr es:[edi], al
103f292c: mov eax, 0x107bc7ec
103f2931: add esp, 0x20
103f2934: xor edi, edi
103f2936: lea edx, [eax + 1]
103f2939: lea esp, [esp]
103f2940: mov cl, byte ptr [eax]
103f2942: inc eax
103f2943: test cl, cl
103f2945: jne 0x103f2940
103f2947: sub eax, edx
103f2949: mov ebx, eax
103f294b: mov eax, 0x107bc6e8
103f2950: xor edx, edx
103f2952: lea esi, [eax + 1]
103f2955: mov cl, byte ptr [eax]
103f2957: inc eax
103f2958: test cl, cl
103f295a: jne 0x103f2955
103f295c: sub eax, esi
103f295e: test eax, eax
103f2960: jle 0x103f2991
103f2962: mov cl, byte ptr [edi + 0x107bc7ec]
103f2968: mov al, byte ptr [edx + 0x107bc6e8]
103f296e: xor al, cl
103f2970: inc edi
103f2971: cmp edi, ebx
103f2973: mov byte ptr [esp + edx + 0x18], al
103f2977: jl 0x103f297b
103f2979: xor edi, edi
103f297b: mov eax, 0x107bc6e8
103f2980: inc edx
103f2981: lea esi, [eax + 1]
103f2984: mov cl, byte ptr [eax]
103f2986: inc eax
103f2987: test cl, cl
103f2989: jne 0x103f2984
103f298b: sub eax, esi
103f298d: cmp edx, eax
103f298f: jl 0x103f2962
103f2991: mov eax, 0x107bc6e8
103f2996: lea edx, [eax + 1]
103f2999: lea esp, [esp]
103f29a0: mov cl, byte ptr [eax]
103f29a2: inc eax
103f29a3: test cl, cl
103f29a5: jne 0x103f29a0
103f29a7: mov ecx, dword ptr [0x109d5e68]
103f29ad: mov ecx, dword ptr [ecx + 0x48]
103f29b0: sub eax, edx
103f29b2: mov edx, dword ptr [ecx]
103f29b4: lea esi, [esp + 0x18]
103f29b8: push esi
103f29b9: push eax
103f29ba: mov eax, dword ptr [esp + 0x18]
103f29be: push eax
103f29bf: push 0
103f29c1: push 0x107bcf04
103f29c6: push ecx
103f29c7: call dword ptr [edx + 0x64]
103f29ca: mov eax, dword ptr [esp + 0x28]
103f29ce: mov ecx, dword ptr [0x142d7944]
103f29d4: push eax
103f29d5: mov dword ptr [0x10925300], eax
103f29da: mov edx, dword ptr [ecx]
103f29dc: push 0x107bceb8
103f29e1: push edx
103f29e2: call dword ptr [0x142d7780]
103f29e8: mov edx, dword ptr [esp + 0x34]
103f29ec: mov eax, dword ptr [0x10b36bbc]
103f29f1: mov ecx, dword ptr [eax]
103f29f3: push edx
103f29f4: push 0x107bceb8
103f29f9: push 2
103f29fb: push eax
103f29fc: call dword ptr [ecx + 0x2c0]
103f2a02: add esp, 0x34
103f2a05: pop edi
103f2a06: pop esi
103f2a07: pop ebx
103f2a08: mov esp, ebp
103f2a0a: pop ebp
103f2a0b: ret 8
103f2a0e: cmp ax, 0x274d
103f2a12: jne 0x103f2a21
103f2a14: push 0x107bce70
103f2a19: call 0x10314137
103f2a1e: add esp, 4
103f2a21: pop edi
103f2a22: pop esi
103f2a23: pop ebx
103f2a24: mov esp, ebp
103f2a26: pop ebp
103f2a27: ret 8
103f2a2a: nop 
103f2a2b: nop 
103f2a2c: nop 
103f2a2d: nop 
103f2a2e: nop 
103f2a2f: nop 
