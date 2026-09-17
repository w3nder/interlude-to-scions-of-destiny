
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10400880(int param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  uint unaff_EBX;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined1 *puStack_198;
  short *psStack_194;
  undefined1 *puStack_190;
  int *piStack_18c;
  undefined4 uStack_174;
  undefined1 auStack_16c [4];
  undefined1 *puStack_168;
  undefined1 auStack_164 [4];
  undefined1 auStack_160 [4];
  undefined1 auStack_15c [8];
  int iStack_154;
  short asStack_150 [24];
  undefined1 auStack_120 [48];
  undefined1 auStack_f0 [4];
  undefined1 auStack_ec [4];
  undefined1 auStack_e8 [4];
  undefined1 auStack_e4 [4];
  undefined1 auStack_e0 [4];
  undefined1 auStack_dc [4];
  undefined1 auStack_d8 [4];
  undefined1 auStack_d4 [24];
  undefined1 auStack_bc [4];
  short asStack_b8 [24];
  undefined1 auStack_88 [12];
  undefined1 auStack_7c [8];
  undefined1 auStack_74 [4];
  undefined1 auStack_70 [52];
  undefined1 auStack_3c [20];
  undefined4 uStack_28;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_107559db;
  *unaff_FS_OFFSET = &uStack_c;
  piStack_18c = (int *)0x104008a7;
  func_0x10306da2();
  piStack_18c = (int *)auStack_120;
  puStack_190 = (undefined1 *)0x30;
  psStack_194 = asStack_150;
  puStack_198 = (undefined1 *)0x30;
  puVar1 = (undefined1 *)
           func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c1d04,0x30,auStack_3c,
                           &iStack_154);
  if ((iStack_154 != 0) && (asStack_150[0] != 0)) {
    piStack_18c = (int *)auStack_7c;
    puStack_190 = auStack_88;
    psStack_194 = asStack_b8;
    puStack_198 = (undefined1 *)0x30;
    puVar1 = (undefined1 *)
             func_0x10305079(*(undefined4 *)(param_1 + 0x48),puVar1,&UNK_107c1cf4,auStack_d4,
                             auStack_f0,auStack_ec,auStack_e8,auStack_e4,auStack_e0,auStack_dc,
                             auStack_d8,auStack_bc);
  }
  piStack_18c = &iStack_154;
  puStack_190 = (undefined1 *)0x10400982;
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x4fc))();
  puStack_190 = (undefined1 *)0x10400993;
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x500))();
  puStack_190 = &stack0xfffffe80;
  psStack_194 = (short *)&UNK_107bde9c;
  puStack_198 = puVar1;
  uVar2 = func_0x10305079(*(undefined4 *)(param_1 + 0x48));
  iVar3 = 0;
  if (0 < (int)unaff_EBX) {
    do {
      puStack_190 = auStack_15c;
      psStack_194 = (short *)auStack_16c;
      puStack_198 = auStack_164;
      uVar2 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),uVar2,&UNK_107c1cec,0x30,auStack_70,
                              auStack_160,&puStack_168);
      puStack_190 = (undefined1 *)0xa;
      psStack_194 = (short *)0x10400a02;
      func_0x1030218f();
      psStack_194 = (short *)auStack_74;
      uStack_c = 0;
      puStack_198 = (undefined1 *)0x10400a1e;
      func_0x103012c1();
      puStack_198 = puStack_168;
      func_0x103012c1();
      func_0x103012c1(uStack_174);
      func_0x103012c1(uStack_174);
      func_0x103012c1(unaff_EBX);
      func_0x103012c1(uStack_174);
      (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x504))(&puStack_198);
      uStack_28 = 0xffffffff;
      func_0x10307f3b();
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)unaff_EBX);
  }
  *unaff_FS_OFFSET = uStack_10;
  return unaff_EBX & 0xffffff00;
}

