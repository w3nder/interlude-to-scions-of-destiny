
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10427590(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uStack_8;
  undefined1 auStack_4 [4];
  
  func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x1088545c,&uStack_8,&param_1,auStack_4);
  iVar1 = _DAT_10b1f538;
  if (_DAT_10b1f538 == 0) {
LAB_10427614:
    uVar7 = 0;
  }
  else {
    iVar2 = func_0x1030d04e(&uStack_8);
    if (iVar2 == 0) goto LAB_10427614;
    piVar3 = (int *)func_0x1030d04e(&uStack_8);
    if (*piVar3 != 4) goto LAB_10427614;
    iVar2 = func_0x1030d04e(&uStack_8);
    if (*(int *)(iVar2 + 4) == 0) goto LAB_10427614;
    iVar2 = func_0x1030d04e(&uStack_8);
    uVar7 = *(undefined4 *)(iVar2 + 4);
  }
  if (iVar1 == 0) {
LAB_10427664:
    uVar6 = 0;
  }
  else {
    iVar2 = func_0x1030d04e(&uStack_8);
    if (iVar2 == 0) goto LAB_10427664;
    piVar3 = (int *)func_0x1030d04e(&uStack_8);
    if (*piVar3 != 2) goto LAB_10427664;
    iVar2 = func_0x1030d04e(&uStack_8);
    if (*(int *)(iVar2 + 4) == 0) goto LAB_10427664;
    iVar2 = func_0x1030d04e(&uStack_8);
    uVar6 = *(undefined4 *)(iVar2 + 4);
  }
  if (iVar1 != 0) {
    iVar2 = func_0x1030d04e(&uStack_8);
    if (iVar2 != 0) {
      piVar3 = (int *)func_0x1030d04e(&uStack_8);
      if (*piVar3 == 1) {
        iVar2 = func_0x1030d04e(&uStack_8);
        if (*(int *)(iVar2 + 4) != 0) {
          iVar2 = func_0x1030d04e(&uStack_8);
          uVar4 = *(undefined4 *)(iVar2 + 4);
          goto LAB_104276b6;
        }
      }
    }
  }
  uVar4 = 0;
LAB_104276b6:
  (**(code **)(**(int **)(iVar1 + 0x54) + 0x26c))(uVar4,uStack_8,uVar6,uVar7,(int)(short)param_1);
  uVar5 = _Logf_FOutputDevice__QAAXPBGZZ
                    (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10889468);
  return uVar5 & 0xffffff00;
}

