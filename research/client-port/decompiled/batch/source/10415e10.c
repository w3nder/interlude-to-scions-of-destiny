
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10415e10(int param_1)

{
  int iVar1;
  uint uVar2;
  
  func_0x1030d6e3();
  iVar1 = *(int *)(param_1 + 0x48);
  if (*(int *)(iVar1 + 0x38) != 0) {
    Ordinal_3(*(int *)(iVar1 + 0x38));
    DeleteCriticalSection(iVar1 + 0x4e4c);
  }
  *(undefined4 *)(iVar1 + 0x38) = 0;
  if (*(int *)(iVar1 + 0x495c) != 0) {
    *(undefined4 *)(iVar1 + 0x495c) = 0;
    _DAT_109d5e6c = 0;
  }
  (**(code **)(*(int *)_DAT_109d5e68[0x15] + 0x208))();
  uVar2 = (**(code **)(*_DAT_109d5e68 + 0xd4))(0);
  return uVar2 & 0xffffff00;
}

