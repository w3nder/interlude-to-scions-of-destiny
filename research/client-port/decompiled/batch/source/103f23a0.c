
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_103f23a0(void)

{
  uint uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  puStack_c = &UNK_107557b0;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  uStack_8 = 0;
  uVar1 = (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x418))();
  *unaff_FS_OFFSET = uStack_10;
  return uVar1 & 0xffffff00;
}

