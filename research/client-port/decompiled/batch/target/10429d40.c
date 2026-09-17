
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10429d40(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  undefined4 uVar11;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x10883f24,&param_1,&iStack_20,&iStack_24,
                  &iStack_28,&iStack_2c,&iStack_30,&iStack_34,&uStack_1c);
  iVar1 = _DAT_10b1f538;
  fStack_c = (float)iStack_20;
  fStack_8 = (float)iStack_24;
  fStack_4 = (float)iStack_28;
  fStack_18 = (float)iStack_2c;
  fStack_14 = (float)iStack_30;
  fStack_10 = (float)iStack_34;
  if (_DAT_10b1f538 != 0) {
    iVar2 = func_0x1030d04e(&param_1);
    if (iVar2 != 0) {
      piVar3 = (int *)func_0x1030d04e(&param_1);
      if (*piVar3 == 1) {
        iVar2 = func_0x1030d04e(&param_1);
        if (*(int *)(iVar2 + 4) != 0) {
          iVar2 = func_0x1030d04e(&param_1);
          uVar4 = *(undefined4 *)(iVar2 + 4);
          goto LAB_10429e0d;
        }
      }
    }
  }
  uVar4 = 0;
LAB_10429e0d:
  fVar6 = fStack_8;
  fVar7 = fStack_4;
  fVar8 = fStack_18;
  fVar9 = fStack_14;
  fVar10 = fStack_10;
  uVar11 = uStack_1c;
  (**(code **)(**(int **)(iVar1 + 0x54) + 0x10c))
            (uVar4,fStack_c,fStack_8,fStack_4,fStack_18,fStack_14,fStack_10,uStack_1c);
  uVar5 = _Logf_FOutputDevice__QAAXPBGZZ
                    (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10889df8,uStack_1c,
                     uVar11,fVar10,fVar9,fVar8,fVar7,fVar6);
  return uVar5 & 0xffffff00;
}

