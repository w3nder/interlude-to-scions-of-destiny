
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10416060(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 auStack_20 [4];
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c0f44,auStack_20,&param_1,
                  &iStack_18,&iStack_14,&iStack_10);
  iVar1 = _DAT_109d5e68;
  fStack_c = (float)iStack_18;
  uVar6 = 0;
  fStack_8 = (float)iStack_14;
  fStack_4 = (float)iStack_10;
  if (_DAT_109d5e68 == 0) {
LAB_1041610b:
    uStack_1c = 0;
  }
  else {
    iVar2 = func_0x1030f3bc(&param_1);
    if (iVar2 == 0) goto LAB_1041610b;
    piVar3 = (int *)func_0x1030f3bc(&param_1);
    if (*piVar3 != 4) goto LAB_1041610b;
    iVar2 = func_0x1030f3bc(&param_1);
    if (*(int *)(iVar2 + 4) == 0) goto LAB_1041610b;
    iVar2 = func_0x1030f3bc(&param_1);
    uStack_1c = *(undefined4 *)(iVar2 + 4);
  }
  if (iVar1 == 0) {
LAB_1041615c:
    uVar7 = 0;
  }
  else {
    iVar2 = func_0x1030f3bc(&param_1);
    if (iVar2 == 0) goto LAB_1041615c;
    piVar3 = (int *)func_0x1030f3bc(&param_1);
    if (*piVar3 != 2) goto LAB_1041615c;
    iVar2 = func_0x1030f3bc(&param_1);
    if (*(int *)(iVar2 + 4) == 0) goto LAB_1041615c;
    iVar2 = func_0x1030f3bc(&param_1);
    uVar7 = *(undefined4 *)(iVar2 + 4);
  }
  if (iVar1 != 0) {
    iVar2 = func_0x1030f3bc(&param_1);
    if (iVar2 != 0) {
      piVar3 = (int *)func_0x1030f3bc(&param_1);
      if (*piVar3 == 1) {
        iVar2 = func_0x1030f3bc(&param_1);
        if (*(int *)(iVar2 + 4) != 0) {
          iVar2 = func_0x1030f3bc(&param_1);
          uVar6 = *(undefined4 *)(iVar2 + 4);
        }
      }
    }
  }
  if (iVar1 != 0) {
    iVar2 = func_0x1030f3bc(auStack_20);
    if (iVar2 != 0) {
      piVar3 = (int *)func_0x1030f3bc(auStack_20);
      if (*piVar3 == 1) {
        iVar2 = func_0x1030f3bc(auStack_20);
        if (*(int *)(iVar2 + 4) != 0) {
          iVar2 = func_0x1030f3bc(auStack_20);
          uVar4 = *(undefined4 *)(iVar2 + 4);
          goto LAB_104161fa;
        }
      }
    }
  }
  uVar4 = 0;
LAB_104161fa:
  uVar8 = uStack_1c;
  (**(code **)(**(int **)(iVar1 + 0x54) + 0x1a8))
            (uVar4,param_1,uVar6,uVar7,uStack_1c,fStack_c,fStack_8,fStack_4);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c5ac8,uVar8,uStack_1c);
  uVar5 = (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                    (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c5ac8,uVar8,uStack_1c);
  return uVar5 & 0xffffff00;
}

