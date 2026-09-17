
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10418e60(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 unaff_EDI;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
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
  
  func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c4b44,&param_1,&iStack_1c,
                  &iStack_20,&iStack_24,&iStack_28,&iStack_2c,&iStack_30);
  iVar1 = _DAT_109d5e68;
  fStack_c = (float)iStack_1c;
  fStack_8 = (float)iStack_20;
  fStack_4 = (float)iStack_24;
  fStack_18 = (float)iStack_28;
  fStack_14 = (float)iStack_2c;
  fStack_10 = (float)iStack_30;
  if (_DAT_109d5e68 != 0) {
    iVar2 = func_0x1030f3bc(&param_1);
    if (iVar2 != 0) {
      piVar3 = (int *)func_0x1030f3bc(&param_1);
      if (*piVar3 == 1) {
        iVar2 = func_0x1030f3bc(&param_1);
        if (*(int *)(iVar2 + 4) != 0) {
          iVar2 = func_0x1030f3bc(&param_1);
          uVar4 = *(undefined4 *)(iVar2 + 4);
          goto LAB_10418f29;
        }
      }
    }
  }
  uVar4 = 0;
LAB_10418f29:
  fVar6 = fStack_8;
  fVar7 = fStack_4;
  fVar8 = fStack_18;
  fVar9 = fStack_14;
  fVar10 = fStack_10;
  (**(code **)(**(int **)(iVar1 + 0x54) + 0x20))
            (uVar4,fStack_c,fStack_8,fStack_4,fStack_18,fStack_14,fStack_10);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c65c0,fStack_18,
             unaff_EDI,fVar10,fVar9,fVar8,fVar7,fVar6);
  uVar5 = (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                    (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c65c0,fStack_18,unaff_EDI,fVar10,
                     fVar9,fVar8,fVar7,fVar6);
  return uVar5 & 0xffffff00;
}

