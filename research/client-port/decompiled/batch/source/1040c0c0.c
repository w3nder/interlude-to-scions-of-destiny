
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_1040c0c0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_40 [24];
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  undefined1 *puStack_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  int iStack_8;
  
  iVar1 = param_1;
  puStack_c = &UNK_10756278;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  puStack_14 = &stack0xffffffb4;
  iStack_8 = 0;
  iStack_18 = 0;
  uVar2 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107bde9c,&iStack_18);
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x3d0))();
  for (param_1 = 0; param_1 < iStack_18; param_1 = param_1 + 1) {
    uStack_24 = 0xffffffff;
    uStack_28 = 0xffffffff;
    uStack_20 = 0xffffffff;
    uStack_1c = 0xffffffff;
    uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107becec,&uStack_1c,&uStack_20,
                            &uStack_24,&uStack_28);
    func_0x1030218f(10);
    iStack_8._0_1_ = 1;
    func_0x103012c1(1);
    func_0x103012c1(uStack_1c);
    func_0x103012c1(uStack_20);
    func_0x103012c1(uStack_24);
    func_0x103012c1(uStack_28);
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x3d8))(auStack_40);
    iStack_8 = (uint)iStack_8._1_3_ << 8;
    func_0x10307f3b();
  }
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c4630);
  uVar3 = (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                    (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c4630);
  *unaff_FS_OFFSET = uStack_10;
  return uVar3 & 0xffffff00;
}

