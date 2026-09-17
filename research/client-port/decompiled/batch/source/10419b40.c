
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10419b40(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  undefined1 *puStack_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  puStack_c = &UNK_107566e0;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  puStack_14 = &stack0xffffffbc;
  uStack_8 = 0;
  piVar2 = (int *)func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c0f44,&param_1,
                                  &uStack_24,&iStack_20,&iStack_1c,&iStack_18);
  iVar1 = _DAT_109d5e68;
  if (_DAT_109d5e68 != 0) {
    iVar3 = func_0x1030f3bc(&param_1);
    piVar2 = (int *)0x0;
    if (iVar3 != 0) {
      piVar2 = (int *)func_0x1030f3bc(&param_1);
      if (*piVar2 == 1) {
        piVar2 = (int *)func_0x1030f3bc(&param_1);
        if (piVar2[1] != 0) {
          iVar3 = func_0x1030f3bc(&param_1);
          piVar2 = (int *)0x0;
          if (*(int *)(iVar3 + 4) != 0) {
            (**(code **)(**(int **)(iVar1 + 0x54) + 0x69c))
                      (*(undefined4 *)(*(int *)(iVar3 + 4) + 0x158),uStack_24,(float)iStack_20,
                       (float)iStack_1c,(float)iStack_18);
            _Logf_FOutputDevice__QAAXPBGZZ
                      (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c686c);
            piVar2 = (int *)(**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                                      (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c686c);
          }
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_10;
  return (uint)piVar2 & 0xffffff00;
}

