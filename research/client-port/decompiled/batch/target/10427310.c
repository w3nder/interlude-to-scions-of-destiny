
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10427310(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 auStack_24 [4];
  undefined4 uStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  undefined1 auStack_10 [4];
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x10886c3c,auStack_24,&param_1,&iStack_1c,
                  &iStack_18,&iStack_14,auStack_10);
  iVar1 = _DAT_10b1f538;
  fStack_c = (float)iStack_1c;
  uVar6 = 0;
  fStack_8 = (float)iStack_18;
  fStack_4 = (float)iStack_14;
  if (_DAT_10b1f538 == 0) {
LAB_104273c0:
    uStack_20 = 0;
  }
  else {
    iVar2 = func_0x1030d04e(&param_1);
    if (iVar2 == 0) goto LAB_104273c0;
    piVar3 = (int *)func_0x1030d04e(&param_1);
    if (*piVar3 != 4) goto LAB_104273c0;
    iVar2 = func_0x1030d04e(&param_1);
    if (*(int *)(iVar2 + 4) == 0) goto LAB_104273c0;
    iVar2 = func_0x1030d04e(&param_1);
    uStack_20 = *(undefined4 *)(iVar2 + 4);
  }
  if (iVar1 == 0) {
LAB_10427411:
    uVar7 = 0;
  }
  else {
    iVar2 = func_0x1030d04e(&param_1);
    if (iVar2 == 0) goto LAB_10427411;
    piVar3 = (int *)func_0x1030d04e(&param_1);
    if (*piVar3 != 2) goto LAB_10427411;
    iVar2 = func_0x1030d04e(&param_1);
    if (*(int *)(iVar2 + 4) == 0) goto LAB_10427411;
    iVar2 = func_0x1030d04e(&param_1);
    uVar7 = *(undefined4 *)(iVar2 + 4);
  }
  if (iVar1 != 0) {
    iVar2 = func_0x1030d04e(&param_1);
    if (iVar2 != 0) {
      piVar3 = (int *)func_0x1030d04e(&param_1);
      if (*piVar3 == 1) {
        iVar2 = func_0x1030d04e(&param_1);
        if (*(int *)(iVar2 + 4) != 0) {
          iVar2 = func_0x1030d04e(&param_1);
          uVar6 = *(undefined4 *)(iVar2 + 4);
        }
      }
    }
  }
  if (iVar1 != 0) {
    iVar2 = func_0x1030d04e(auStack_24);
    if (iVar2 != 0) {
      piVar3 = (int *)func_0x1030d04e(auStack_24);
      if (*piVar3 == 1) {
        iVar2 = func_0x1030d04e(auStack_24);
        if (*(int *)(iVar2 + 4) != 0) {
          iVar2 = func_0x1030d04e(auStack_24);
          uVar4 = *(undefined4 *)(iVar2 + 4);
          goto LAB_104274ae;
        }
      }
    }
  }
  uVar4 = 0;
LAB_104274ae:
  uVar8 = uStack_20;
  (**(code **)(**(int **)(iVar1 + 0x54) + 0x268))
            (uVar4,param_1,uVar6,uVar7,uStack_20,fStack_c,fStack_8,fStack_4);
  uVar5 = _Logf_FOutputDevice__QAAXPBGZZ
                    (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x108893e0,uVar8,
                     iStack_1c);
  return uVar5 & 0xffffff00;
}

