
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10400b30(void)

{
  uint uVar1;
  
  uVar1 = (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x200))();
  return uVar1 & 0xffffff00;
}

