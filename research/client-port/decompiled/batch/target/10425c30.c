
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10425c30(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  
  iVar1 = _DAT_10b1f538;
  if (_DAT_10b1f538 != 0) {
    iVar2 = func_0x1030d04e(&DAT_10b1f530);
    if (iVar2 != 0) {
      piVar3 = (int *)func_0x1030d04e(&DAT_10b1f530);
      if (*piVar3 == 1) {
        iVar2 = func_0x1030d04e(&DAT_10b1f530);
        if (*(int *)(iVar2 + 4) != 0) {
          iVar2 = func_0x1030d04e(&DAT_10b1f530);
          uVar4 = *(undefined4 *)(iVar2 + 4);
          goto LAB_10425c88;
        }
      }
    }
  }
  uVar4 = 0;
LAB_10425c88:
  (**(code **)(**(int **)(iVar1 + 0x54) + 0x14c))(uVar4);
  uVar5 = _Logf_FOutputDevice__QAAXPBGZZ
                    (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10888f44);
  return uVar5 & 0xffffff00;
}

