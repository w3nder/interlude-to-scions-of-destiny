
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_103f2000(void)

{
  uint uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_2c [24];
  undefined1 *puStack_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  int iStack_8;
  
  puStack_c = &UNK_10755738;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  puStack_14 = &stack0xffffffc8;
  iStack_8 = 0;
  func_0x1030218f(10);
  iStack_8._0_1_ = 1;
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x680))(auStack_2c);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107bcce8);
  (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
            (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107bcce8);
  iStack_8 = (uint)iStack_8._1_3_ << 8;
  uVar1 = func_0x10307f3b();
  *unaff_FS_OFFSET = uStack_10;
  return uVar1 & 0xffffff00;
}

