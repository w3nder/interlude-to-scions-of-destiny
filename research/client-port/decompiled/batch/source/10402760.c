
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10402760(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 *puStack_58;
  undefined4 uStack_54;
  undefined1 *puStack_50;
  undefined4 auStack_44 [2];
  undefined1 auStack_3c [32];
  undefined4 uStack_1c;
  undefined4 uStack_14;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_10755a98;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  puStack_50 = auStack_3c;
  uStack_54 = 0x30;
  puStack_58 = &param_1;
  func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c23e8);
  puStack_50 = (undefined1 *)0xa;
  uStack_54 = 0x104027a9;
  func_0x1030218f();
  puStack_8 = (undefined *)0x0;
  puStack_58 = (undefined4 *)0x104027bf;
  func_0x103012c1();
  puStack_58 = auStack_44;
  func_0x103012c1();
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x298))(&puStack_58);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c23a0);
  (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
            (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c23a0);
  uStack_14 = 0xffffffff;
  uVar1 = func_0x10307f3b();
  *unaff_FS_OFFSET = uStack_1c;
  return uVar1 & 0xffffff00;
}

