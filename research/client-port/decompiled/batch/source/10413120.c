
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10413120(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c4b44,&param_1,&iStack_30,
                  &iStack_2c,&iStack_28,&iStack_24,&iStack_20,&iStack_1c);
  iVar1 = _DAT_109d5e68;
  fStack_c = (float)iStack_30;
  fStack_8 = (float)iStack_2c;
  fStack_4 = (float)iStack_28;
  fStack_18 = (float)iStack_24;
  fStack_14 = (float)iStack_20;
  fStack_10 = (float)iStack_1c;
  if (_DAT_109d5e68 != 0) {
    iVar2 = func_0x1030f3bc(&param_1);
    if (iVar2 != 0) {
      piVar3 = (int *)func_0x1030f3bc(&param_1);
      if (*piVar3 == 1) {
        iVar2 = func_0x1030f3bc(&param_1);
        if (*(int *)(iVar2 + 4) != 0) {
          iVar2 = func_0x1030f3bc(&param_1);
          uVar4 = *(undefined4 *)(iVar2 + 4);
          goto LAB_104131e9;
        }
      }
    }
  }
  uVar4 = 0;
LAB_104131e9:
  uVar5 = (**(code **)(**(int **)(iVar1 + 0x54) + 4))
                    (uVar4,fStack_c,fStack_8,fStack_4,fStack_18,fStack_14,fStack_10);
  return uVar5 & 0xffffff00;
}

