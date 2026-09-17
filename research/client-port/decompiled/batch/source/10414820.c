
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10414820(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  
  iVar1 = _DAT_109d5e68;
  if (_DAT_109d5e68 != 0) {
    iVar2 = func_0x1030f3bc(0x109d5e60);
    if (iVar2 != 0) {
      piVar3 = (int *)func_0x1030f3bc(0x109d5e60);
      if (*piVar3 == 1) {
        iVar2 = func_0x1030f3bc(0x109d5e60);
        if (*(int *)(iVar2 + 4) != 0) {
          iVar2 = func_0x1030f3bc(0x109d5e60);
          uVar4 = *(undefined4 *)(iVar2 + 4);
          goto LAB_10414879;
        }
      }
    }
  }
  uVar4 = 0;
LAB_10414879:
  (**(code **)(**(int **)(iVar1 + 0x54) + 0x60))(uVar4);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c5664);
  uVar5 = (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                    (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c5664);
  return uVar5 & 0xffffff00;
}

