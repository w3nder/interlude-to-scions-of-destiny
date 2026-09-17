
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10425930(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 unaff_EDI;
  float fVar6;
  float fVar7;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iStack_24 = 0;
  iStack_20 = 0;
  iStack_1c = 0;
  func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x108874cc,&param_1,&uStack_10,&uStack_14,
                  &uStack_18,&iStack_24,&iStack_20,&iStack_1c);
  iVar1 = _DAT_10b1f538;
  if (_DAT_10b1f538 != 0) {
    iVar2 = func_0x1030d04e(&param_1);
    if (iVar2 != 0) {
      piVar3 = (int *)func_0x1030d04e(&param_1);
      if (*piVar3 == 1) {
        iVar2 = func_0x1030d04e(&param_1);
        if (*(int *)(iVar2 + 4) != 0) {
          iVar2 = func_0x1030d04e(&param_1);
          uVar4 = *(undefined4 *)(iVar2 + 4);
          goto LAB_104259e0;
        }
      }
    }
  }
  uVar4 = 0;
LAB_104259e0:
  fStack_c = (float)iStack_24;
  fVar6 = (float)iStack_20;
  fVar7 = (float)iStack_1c;
  fStack_8 = fVar6;
  fStack_4 = fVar7;
  (**(code **)(**(int **)(iVar1 + 0x54) + 0x140))
            (uVar4,uStack_10,uStack_14,uStack_18,fStack_c,fVar6,fVar7);
  uVar5 = _Logf_FOutputDevice__QAAXPBGZZ
                    (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10888e40,uStack_18,
                     unaff_EDI,fVar7,fVar6);
  return uVar5 & 0xffffff00;
}

