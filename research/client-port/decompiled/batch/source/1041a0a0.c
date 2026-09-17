
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_1041a0a0(uint param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_40 [24];
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 auStack_1c [6];
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined1 *puStack_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  int iStack_8;
  
  puStack_c = &UNK_10756728;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  puStack_14 = &stack0xffffffb4;
  iStack_8 = 0;
  func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c6a4c,auStack_1c,&uStack_20,
                  &uStack_24,(int)&param_1 + 3,&uStack_15,&uStack_16,&uStack_28);
  piVar2 = (int *)0x0;
  if (_DAT_109d5e68 != 0) {
    iVar1 = func_0x1030f3bc(auStack_1c);
    piVar2 = (int *)0x0;
    if (iVar1 != 0) {
      piVar2 = (int *)func_0x1030f3bc(auStack_1c);
      if (*piVar2 == 1) {
        piVar2 = (int *)func_0x1030f3bc(auStack_1c);
        if (piVar2[1] != 0) {
          piVar2 = (int *)func_0x1030f3bc(auStack_1c);
          iVar1 = piVar2[1];
          if (iVar1 != 0) {
            func_0x1030218f(10);
            iStack_8._0_1_ = 1;
            func_0x103012c1(uStack_20);
            func_0x103012c1(uStack_24);
            func_0x103012c1(param_1 >> 0x18);
            func_0x103012c1(uStack_15);
            func_0x103012c1(uStack_16);
            func_0x103012c1(uStack_28);
            (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x6a8))
                      (*(undefined4 *)(iVar1 + 0x158),auStack_40);
            _Logf_FOutputDevice__QAAXPBGZZ
                      (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c6a00);
            (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                      (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c6a00);
            iStack_8 = (uint)iStack_8._1_3_ << 8;
            piVar2 = (int *)func_0x10307f3b();
          }
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_10;
  return (uint)piVar2 & 0xffffff00;
}

