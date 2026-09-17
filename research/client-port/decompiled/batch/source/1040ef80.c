
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_1040ef80(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_244 [256];
  undefined1 auStack_144 [260];
  undefined1 auStack_40 [16];
  undefined1 auStack_30 [16];
  undefined4 uStack_20;
  undefined4 auStack_1c [2];
  undefined1 *puStack_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  uint uStack_8;
  
  iVar1 = param_1;
  puStack_c = &UNK_107564f0;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  puStack_14 = &stack0xfffffdb0;
  uStack_8 = 0;
  uVar2 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c3954,0x100,auStack_144,
                          &uStack_20,&param_1);
  func_0x1030218f(10);
  uStack_8 = CONCAT31(uStack_8._1_3_,1);
  func_0x103012c1(auStack_144);
  func_0x103012c1(param_1);
  func_0x103012c1(uStack_20);
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x6ac))(auStack_30);
  for (iVar4 = 0; iVar4 < param_1; iVar4 = iVar4 + 1) {
    uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107c1d78,0x100,auStack_244,
                            auStack_1c);
    func_0x1030218f(10);
    uStack_8._0_1_ = 2;
    func_0x103012c1(auStack_244);
    func_0x103012c1(auStack_1c[0]);
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x6b0))(auStack_40);
    uStack_8 = CONCAT31(uStack_8._1_3_,1);
    func_0x10307f3b();
  }
  uStack_8 = uStack_8 & 0xffffff00;
  uVar3 = func_0x10307f3b();
  *unaff_FS_OFFSET = uStack_10;
  return uVar3 & 0xffffff00;
}

