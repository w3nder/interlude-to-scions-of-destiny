
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_1042aa20(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  undefined1 auStack_1c [6];
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined1 *puStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_c = 0x1080fd50;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  puStack_14 = &stack0xffffffa8;
  uStack_8 = 0;
  piVar2 = (int *)func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x1088a0ec,auStack_1c,
                                  &uStack_38,&iStack_20,&iStack_24,&iStack_28,&uStack_16,&uStack_15)
  ;
  iVar1 = _DAT_10b1f538;
  if (_DAT_10b1f538 != 0) {
    iVar3 = func_0x1030d04e(auStack_1c);
    piVar2 = (int *)0x0;
    if (iVar3 != 0) {
      piVar2 = (int *)func_0x1030d04e(auStack_1c);
      if (*piVar2 == 1) {
        piVar2 = (int *)func_0x1030d04e(auStack_1c);
        if (piVar2[1] != 0) {
          iVar3 = func_0x1030d04e(auStack_1c);
          piVar2 = (int *)0x0;
          if (*(int *)(iVar3 + 4) != 0) {
            fStack_2c = (float)iStack_20;
            fStack_30 = (float)iStack_24;
            fStack_34 = (float)iStack_28;
            (**(code **)(**(int **)(iVar1 + 0x54) + 0x720))
                      (*(undefined4 *)(*(int *)(iVar3 + 4) + 0x204),uStack_38,fStack_2c,fStack_30,
                       fStack_34,uStack_16,uStack_15);
            piVar2 = (int *)_Logf_FOutputDevice__QAAXPBGZZ
                                      (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,
                                       0x1088a0a4);
          }
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_10;
  return (uint)piVar2 & 0xffffff00;
}

