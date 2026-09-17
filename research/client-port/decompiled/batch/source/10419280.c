
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10419280(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  float fVar9;
  float fVar10;
  int iVar11;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c6728,&param_1,&iStack_14,
                  &iStack_24,&iStack_28,&iStack_18,&iStack_1c,&iStack_10,&iStack_20,&iStack_8,
                  &iStack_c);
  iVar11 = _DAT_109d5e68;
  iVar1 = (iStack_24 * -0x10000) / 0x168;
  iVar2 = (iStack_28 * -0x10000) / 0x168;
  iVar3 = (iStack_10 * 0x10000) / 0x168;
  iStack_20 = (iStack_20 * 0x10000) / 0x168;
  iStack_28 = iVar2;
  iStack_24 = iVar1;
  iStack_10 = iVar3;
  if (_DAT_109d5e68 != 0) {
    iVar4 = func_0x1030f3bc(&param_1);
    if (iVar4 != 0) {
      piVar5 = (int *)func_0x1030f3bc(&param_1);
      if (*piVar5 == 1) {
        iVar4 = func_0x1030f3bc(&param_1);
        if (*(int *)(iVar4 + 4) != 0) {
          iVar4 = func_0x1030f3bc(&param_1);
          uVar6 = *(undefined4 *)(iVar4 + 4);
          goto LAB_104193b6;
        }
      }
    }
  }
  uVar6 = 0;
LAB_104193b6:
  fVar10 = (float)iStack_1c;
  iStack_4 = **(int **)(iVar11 + 0x54);
  uVar7 = (uint)(0 < iStack_c);
  uVar8 = (uint)(0 < iStack_8);
  fVar9 = (float)iStack_18;
  iVar11 = iStack_20;
  (**(code **)(iStack_4 + 500))
            (uVar6,(float)iStack_14,iVar1,iVar2,fVar9,fVar10,iVar3,iStack_20,uVar8,uVar7);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c6678,iStack_24,uVar7,
             fVar10,fVar9,uVar8,iVar11);
  uVar7 = (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                    (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c6678,iStack_24,uVar7,fVar10,fVar9
                     ,uVar8,iVar11);
  return uVar7 & 0xffffff00;
}

