
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_103f1b10(void)

{
  uint uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 auStack_20 [3];
  undefined4 uStack_14;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_107556e8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  auStack_20[0] = 10;
  func_0x1030218f();
  puStack_8 = (undefined *)0x0;
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x310))(auStack_20);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107bcac0);
  (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
            (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107bcac0);
  uStack_c = 0xffffffff;
  uVar1 = func_0x10307f3b();
  *unaff_FS_OFFSET = uStack_14;
  return uVar1 & 0xffffff00;
}

