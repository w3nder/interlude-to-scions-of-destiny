
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10416310(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uStack_4;
  
  func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c5b9c,&uStack_4,&param_1);
  iVar1 = _DAT_109d5e68;
  if (_DAT_109d5e68 == 0) {
LAB_1041638e:
    uVar7 = 0;
  }
  else {
    iVar2 = func_0x1030f3bc(&uStack_4);
    if (iVar2 == 0) goto LAB_1041638e;
    piVar3 = (int *)func_0x1030f3bc(&uStack_4);
    if (*piVar3 != 4) goto LAB_1041638e;
    iVar2 = func_0x1030f3bc(&uStack_4);
    if (*(int *)(iVar2 + 4) == 0) goto LAB_1041638e;
    iVar2 = func_0x1030f3bc(&uStack_4);
    uVar7 = *(undefined4 *)(iVar2 + 4);
  }
  if (iVar1 == 0) {
LAB_104163df:
    uVar6 = 0;
  }
  else {
    iVar2 = func_0x1030f3bc(&uStack_4);
    if (iVar2 == 0) goto LAB_104163df;
    piVar3 = (int *)func_0x1030f3bc(&uStack_4);
    if (*piVar3 != 2) goto LAB_104163df;
    iVar2 = func_0x1030f3bc(&uStack_4);
    if (*(int *)(iVar2 + 4) == 0) goto LAB_104163df;
    iVar2 = func_0x1030f3bc(&uStack_4);
    uVar6 = *(undefined4 *)(iVar2 + 4);
  }
  if (iVar1 != 0) {
    iVar2 = func_0x1030f3bc(&uStack_4);
    if (iVar2 != 0) {
      piVar3 = (int *)func_0x1030f3bc(&uStack_4);
      if (*piVar3 == 1) {
        iVar2 = func_0x1030f3bc(&uStack_4);
        if (*(int *)(iVar2 + 4) != 0) {
          iVar2 = func_0x1030f3bc(&uStack_4);
          uVar4 = *(undefined4 *)(iVar2 + 4);
          goto LAB_10416432;
        }
      }
    }
  }
  uVar4 = 0;
LAB_10416432:
  (**(code **)(**(int **)(iVar1 + 0x54) + 0x1ac))(uVar4,uStack_4,uVar6,uVar7,(int)(short)param_1);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c5b50);
  uVar5 = (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                    (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c5b50);
  return uVar5 & 0xffffff00;
}

