
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10404a00(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [12];
  undefined4 uStack_18;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  iVar1 = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_10755d08;
  *unaff_FS_OFFSET = &uStack_c;
  uVar2 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107bde9c,&param_1);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c2ba0,param_1);
  (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
            (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c2b54,param_1);
  (**(code **)(*(int *)_DAT_109d5e68[0x15] + 0x3a0))();
  while (0 < param_1) {
    param_1 = param_1 + -1;
    func_0x1030218f(10);
    puStack_8 = (undefined *)0x0;
    uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107bde1c,&stack0xffffffd4,
                            auStack_28,auStack_24);
    func_0x103012c1(unaff_ESI);
    func_0x103012c1(unaff_ESI);
    func_0x103012c1(unaff_ESI);
    (**(code **)(*(int *)_DAT_109d5e68[0x15] + 0x3a4))(&stack0xffffffd4);
    uStack_18 = 0xffffffff;
    func_0x10307f3b();
  }
  param_1 = param_1 + -1;
  uVar3 = (**(code **)(*_DAT_109d5e68 + 0x300))();
  *unaff_FS_OFFSET = uStack_c;
  return uVar3 & 0xffffff00;
}

