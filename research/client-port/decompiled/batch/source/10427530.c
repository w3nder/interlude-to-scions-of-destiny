
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10427530(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  short *psStack_164;
  undefined4 *puStack_160;
  undefined4 *puStack_15c;
  uint uStack_14c;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined2 *puStack_134;
  undefined1 auStack_130 [4];
  undefined1 auStack_12c [4];
  undefined2 auStack_128 [2];
  int iStack_124;
  short asStack_120 [24];
  undefined1 auStack_f0 [48];
  undefined1 auStack_c0 [4];
  uint uStack_bc;
  uint uStack_b8;
  undefined1 auStack_b4 [4];
  undefined1 auStack_b0 [4];
  undefined1 auStack_ac [4];
  undefined1 auStack_a8 [4];
  undefined4 auStack_a4 [6];
  undefined2 *puStack_8c;
  undefined2 auStack_88 [24];
  undefined4 uStack_58;
  int iStack_54;
  int iStack_50;
  undefined1 auStack_4c [12];
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [24];
  undefined4 uStack_24;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_10756dcb;
  *unaff_FS_OFFSET = &uStack_c;
  puStack_15c = (undefined4 *)0x10427557;
  func_0x10306da2();
  puStack_15c = (undefined4 *)auStack_f0;
  puStack_160 = (undefined4 *)0x30;
  psStack_164 = asStack_120;
  uVar1 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c2ad0,&iStack_124,0x30);
  if ((iStack_124 != 0) && (asStack_120[0] != 0)) {
    puStack_15c = (undefined4 *)auStack_4c;
    puStack_160 = &uStack_58;
    psStack_164 = auStack_88;
    uVar2 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),uVar1,&UNK_107c1cf4,auStack_a4,
                            auStack_c0,&iStack_54,&iStack_50,auStack_b4,auStack_b0,auStack_ac,
                            auStack_a8,&puStack_8c,0x30);
    uStack_bc = (uint)(0 < iStack_54);
    uStack_b8 = (uint)(0 < iStack_50);
    puStack_15c = (undefined4 *)0x0;
    puStack_160 = (undefined4 *)uStack_58;
    psStack_164 = puStack_8c;
    func_0x103146af(iStack_124,auStack_a4[0]);
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x270))(&uStack_138);
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x278))();
    uVar2 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),uVar2,&UNK_107bde9c,&psStack_164);
    iVar3 = 0;
    uVar1 = uStack_14c;
    if (0 < (int)uStack_14c) {
      do {
        puStack_15c = &puStack_134;
        puStack_160 = &uStack_138;
        psStack_164 = auStack_128;
        uVar2 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),uVar2,&UNK_107c1cec,0x30,auStack_3c,
                                auStack_12c,auStack_130);
        puStack_15c = (undefined4 *)0xa;
        puStack_160 = (undefined4 *)0x104276f8;
        func_0x1030218f();
        puStack_160 = (undefined4 *)auStack_40;
        puStack_8 = (undefined *)0x0;
        psStack_164 = (short *)0x10427714;
        func_0x103012c1();
        psStack_164 = puStack_134;
        func_0x103012c1();
        func_0x103012c1(uStack_13c);
        func_0x103012c1(uStack_138);
        func_0x103012c1(uStack_14c);
        func_0x103012c1(uStack_14c);
        (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x27c))(&psStack_164);
        uStack_24 = 0xffffffff;
        func_0x10307f3b();
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)uStack_14c);
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return uVar1 & 0xffffff00;
}

