
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10400b50(uint param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_58 [4];
  undefined1 auStack_54 [24];
  undefined1 auStack_3c [36];
  undefined4 uStack_18;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uVar1 = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_107559f8;
  *unaff_FS_OFFSET = &uStack_c;
  uVar2 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c1d78,0x30,auStack_3c,
                          &param_1);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c1d10);
  (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
            (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c1d10);
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x508))();
  while (0 < (int)param_1) {
    param_1 = param_1 - 1;
    func_0x1030218f(10);
    puStack_8 = (undefined *)0x0;
    uVar2 = func_0x10305079(*(undefined4 *)(uVar1 + 0x48),uVar2,&UNK_107bde1c,&stack0xffffffa4,
                            auStack_58,auStack_54);
    func_0x103012c1(unaff_ESI);
    func_0x103012c1(unaff_ESI);
    func_0x103012c1(unaff_ESI);
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x50c))(&stack0xffffffa4);
    uStack_18 = 0xffffffff;
    func_0x10307f3b();
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1 & 0xffffff00;
}

