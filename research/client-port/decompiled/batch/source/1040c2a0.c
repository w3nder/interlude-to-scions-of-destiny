
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_1040c2a0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_64 [16];
  undefined1 auStack_54 [24];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  uint uStack_8;
  
  iVar1 = param_1;
  puStack_c = &UNK_107562a0;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  puStack_14 = &stack0xffffff90;
  uStack_8 = 0;
  uStack_28 = 0xffffffff;
  uStack_24 = 0xffffffff;
  uStack_20 = 0xffffffff;
  uStack_1c = 0xffffffff;
  uStack_18 = 0xffffffff;
  uVar2 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c0f44,&uStack_18,
                          &uStack_1c,&uStack_20,&uStack_24,&uStack_28);
  func_0x1030218f(10);
  uStack_8 = CONCAT31(uStack_8._1_3_,1);
  func_0x103012c1(1);
  func_0x103012c1(uStack_18);
  func_0x103012c1(uStack_1c);
  func_0x103012c1(uStack_20);
  func_0x103012c1(uStack_24);
  func_0x103012c1(uStack_28);
  iStack_2c = 0;
  uVar2 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),uVar2,&UNK_107bde9c,&iStack_2c);
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x3d4))(auStack_54);
  for (param_1 = 0; param_1 < iStack_2c; param_1 = param_1 + 1) {
    uStack_38 = 0;
    uStack_3c = 0;
    uStack_30 = 0xffffffff;
    uStack_34 = 0xffffffff;
    uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107becec,&uStack_30,&uStack_34,
                            &uStack_38,&uStack_3c);
    func_0x1030218f(10);
    uStack_8._0_1_ = 2;
    func_0x103012c1(uStack_30);
    func_0x103012c1(uStack_34);
    func_0x103012c1(uStack_38);
    func_0x103012c1(uStack_3c);
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x3dc))(auStack_64);
    uStack_8 = CONCAT31(uStack_8._1_3_,1);
    func_0x10307f3b();
  }
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c46c0);
  (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
            (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c46c0);
  uStack_8 = uStack_8 & 0xffffff00;
  uVar3 = func_0x10307f3b();
  *unaff_FS_OFFSET = uStack_10;
  return uVar3 & 0xffffff00;
}

