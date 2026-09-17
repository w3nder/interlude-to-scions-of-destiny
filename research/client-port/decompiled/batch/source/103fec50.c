
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_103fec50(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_94 [48];
  undefined1 auStack_64 [24];
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  int iStack_8;
  
  iVar1 = param_1;
  puStack_c = &UNK_10755948;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  puStack_14 = &stack0xffffff60;
  iStack_8 = 0;
  func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c1784,&uStack_18,&param_1,
                  &uStack_24,&uStack_20,&uStack_1c,0x30,auStack_94,&uStack_28,&uStack_2c,&uStack_30,
                  &uStack_34,&uStack_38,&uStack_3c,&uStack_40,&uStack_44,&uStack_48,&uStack_4c);
  *(undefined4 *)(*(int *)(iVar1 + 0x48) + 0x4eb4) = uStack_18;
  *(int *)(*(int *)(iVar1 + 0x48) + 0x4eb8) = param_1;
  *(undefined4 *)(*(int *)(iVar1 + 0x48) + 0x4eec) = uStack_24;
  *(undefined4 *)(*(int *)(iVar1 + 0x48) + 0x4ef0) = uStack_20;
  *(undefined4 *)(*(int *)(iVar1 + 0x48) + 0x4ef4) = uStack_1c;
  *(undefined4 *)(*(int *)(iVar1 + 0x48) + 0x4f1c) = uStack_28;
  *(undefined4 *)(*(int *)(iVar1 + 0x48) + 0x4f20) = uStack_2c;
  *(undefined4 *)(*(int *)(iVar1 + 0x48) + 0x4ef8) = uStack_30;
  *(undefined4 *)(*(int *)(iVar1 + 0x48) + 0x4efc) = uStack_34;
  *(undefined4 *)(*(int *)(iVar1 + 0x48) + 0x4f00) = uStack_38;
  *(undefined4 *)(*(int *)(iVar1 + 0x48) + 0x4f04) = uStack_3c;
  *(undefined4 *)(*(int *)(iVar1 + 0x48) + 0x4f0c) = uStack_40;
  *(undefined4 *)(*(int *)(iVar1 + 0x48) + 0x4f10) = uStack_44;
  *(undefined4 *)(*(int *)(iVar1 + 0x48) + 0x4f14) = uStack_48;
  *(undefined4 *)(*(int *)(iVar1 + 0x48) + 0x4f18) = uStack_4c;
  iVar1 = *(int *)(iVar1 + 0x48);
  *(undefined4 *)(iVar1 + 0x4ef0) = uStack_20;
  *(undefined4 *)(iVar1 + 0x4eb4) = uStack_18;
  *(int *)(iVar1 + 0x4eb8) = param_1;
  *(undefined4 *)(iVar1 + 0x4eec) = uStack_24;
  *(undefined4 *)(iVar1 + 0x4ef4) = uStack_1c;
  func_0x1030218f(10);
  iStack_8._0_1_ = 1;
  func_0x103012c1(param_1);
  func_0x103012c1(auStack_94);
  func_0x103012c1(uStack_28);
  func_0x103012c1(uStack_2c);
  func_0x103012c1(uStack_30);
  func_0x103012c1(uStack_34);
  func_0x103012c1(uStack_38);
  func_0x103012c1(uStack_3c);
  func_0x103012c1(uStack_40);
  func_0x103012c1(uStack_44);
  func_0x103012c1(uStack_48);
  func_0x103012c1(uStack_4c);
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x4e8))(uStack_18,auStack_64);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c1738);
  (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
            (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c1738);
  iStack_8 = (uint)iStack_8._1_3_ << 8;
  uVar2 = func_0x10307f3b();
  *unaff_FS_OFFSET = uStack_10;
  return uVar2 & 0xffffff00;
}

