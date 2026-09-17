
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_1042a1f0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  undefined4 unaff_EDI;
  float fVar9;
  float fVar10;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x10889f60,&param_1,&iStack_10,&iStack_28,
                  &iStack_2c,&iStack_14,&iStack_18,&iStack_24,&iStack_20,&iStack_4,&iStack_8,
                  &iStack_c);
  iVar1 = (iStack_28 * -0x10000) / 0x168;
  iVar2 = (iStack_2c * -0x10000) / 0x168;
  iVar3 = (iStack_24 * 0x10000) / 0x168;
  iVar4 = (iStack_20 * 0x10000) / 0x168;
  iStack_2c = iVar2;
  iStack_28 = iVar1;
  iStack_24 = iVar3;
  iStack_20 = iVar4;
  if (_DAT_10b1f538 != 0) {
    iVar5 = func_0x1030d04e(&param_1);
    if (iVar5 != 0) {
      piVar6 = (int *)func_0x1030d04e(&param_1);
      if (*piVar6 == 1) {
        iVar5 = func_0x1030d04e(&param_1);
        if (*(int *)(iVar5 + 4) != 0) {
          iVar5 = func_0x1030d04e(&param_1);
          uStack_1c = *(undefined4 *)(iVar5 + 4);
          goto LAB_1042a342;
        }
      }
    }
  }
  uStack_1c = 0;
LAB_1042a342:
  fVar10 = (float)iStack_18;
  uVar8 = (uint)(0 < iStack_c);
  uVar7 = (uint)(0 < iStack_8);
  fVar9 = (float)iStack_14;
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x2b4))
            (uStack_1c,(float)iStack_10,iVar1,iVar2,fVar9,fVar10,iVar3,iVar4,0 < iStack_4,uVar7,
             uVar8);
  uVar8 = _Logf_FOutputDevice__QAAXPBGZZ
                    (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10889eb0,iStack_28,
                     unaff_EDI,fVar10,fVar9,uVar8,uVar7);
  return uVar8 & 0xffffff00;
}

