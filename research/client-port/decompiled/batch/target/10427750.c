
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10427750(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  undefined4 uStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x10883d84,&param_1,&iStack_1c,&iStack_18,
                  &iStack_14,&uStack_10);
  iVar1 = _DAT_10b1f538;
  fStack_c = (float)iStack_1c;
  fStack_8 = (float)iStack_18;
  fStack_4 = (float)iStack_14;
  if (_DAT_10b1f538 != 0) {
    iVar2 = func_0x1030d04e(&param_1);
    if (iVar2 != 0) {
      piVar3 = (int *)func_0x1030d04e(&param_1);
      if (*piVar3 == 1) {
        iVar2 = func_0x1030d04e(&param_1);
        if (*(int *)(iVar2 + 4) != 0) {
          iVar2 = func_0x1030d04e(&param_1);
          uVar4 = *(undefined4 *)(iVar2 + 4);
          goto LAB_104277f6;
        }
      }
    }
  }
  uVar4 = 0;
LAB_104277f6:
  (**(code **)(**(int **)(iVar1 + 0x54) + 0x270))(uVar4,fStack_c,fStack_8,fStack_4,uStack_10);
  uVar5 = _Logf_FOutputDevice__QAAXPBGZZ
                    (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x108894b8,uStack_10);
  return uVar5 & 0xffffff00;
}

