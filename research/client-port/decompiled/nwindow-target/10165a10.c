
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void packet_10165a10(void)

{
  int iVar1;
  int *unaff_FS_OFFSET;
  uint uStack_38;
  undefined1 auStack_28 [20];
  undefined1 *puStack_14;
  int iStack_10;
  undefined *puStack_c;
  uint uStack_8;
  
  puStack_c = &UNK_102104a8;
  iStack_10 = *unaff_FS_OFFSET;
  uStack_38 = _DAT_103554c4 ^ (uint)&stack0xfffffffc;
  puStack_14 = (undefined1 *)&uStack_38;
  *unaff_FS_OFFSET = (int)&iStack_10;
  uStack_8 = 0;
  func_0x1003f970();
  uStack_8 = CONCAT31(uStack_8._1_3_,1);
  func_0x10005c30(0x992,auStack_28);
  iVar1 = func_0x100d1790();
  if (iVar1 != 0) {
    func_0x10147810(*(undefined4 *)_GIsL2Mark__3HA_exref);
  }
  uStack_8 = uStack_8 & 0xffffff00;
  func_0x1003fff0();
  *unaff_FS_OFFSET = iStack_10;
  return;
}

