
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10427110(int param_1)

{
  int iVar1;
  uint uVar2;
  
  func_0x1030b249();
  iVar1 = *(int *)(param_1 + 0x48);
  if (*(int *)(iVar1 + 0x38) != 0) {
    closesocket(*(int *)(iVar1 + 0x38));
    DeleteCriticalSection(iVar1 + 0x4efc);
  }
  *(undefined4 *)(iVar1 + 0x38) = 0;
  if (*(int *)(iVar1 + 0x495c) != 0) {
    *(undefined4 *)(iVar1 + 0x495c) = 0;
    _DAT_10b1f53c = 0;
  }
  (**(code **)(*(int *)_DAT_10b1f538[0x15] + 0x2c4))();
  uVar2 = (**(code **)(*_DAT_10b1f538 + 0xd8))(0);
  return uVar2 & 0xffffff00;
}

