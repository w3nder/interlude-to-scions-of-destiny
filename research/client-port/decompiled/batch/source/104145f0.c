
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_104145f0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 unaff_EDI;
  undefined4 uVar6;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107becec,&param_1,&uStack_4,&uStack_8
                  ,&uStack_c);
  iVar1 = _DAT_109d5e68;
  if (_DAT_109d5e68 != 0) {
    iVar2 = func_0x1030f3bc(&param_1);
    if (iVar2 != 0) {
      piVar3 = (int *)func_0x1030f3bc(&param_1);
      if (*piVar3 == 1) {
        iVar2 = func_0x1030f3bc(&param_1);
        if (*(int *)(iVar2 + 4) != 0) {
          iVar2 = func_0x1030f3bc(&param_1);
          uVar4 = *(undefined4 *)(iVar2 + 4);
          goto LAB_1041467a;
        }
      }
    }
  }
  uVar4 = 0;
LAB_1041467a:
  uVar6 = uStack_c;
  (**(code **)(**(int **)(iVar1 + 0x54) + 0x54))(uVar4,uStack_4,uStack_8,uStack_c);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c55a0,uStack_c,
             unaff_EDI,uVar6,uStack_8);
  uVar5 = (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                    (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c5508,uStack_c,unaff_EDI,uVar6,
                     uStack_8);
  return uVar5 & 0xffffff00;
}

