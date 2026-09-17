
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void packet_1015a6c0(void)

{
  int *unaff_FS_OFFSET;
  undefined4 uStack_30;
  undefined *puStack_2c;
  uint uStack_28;
  undefined1 auStack_24 [4];
  int iStack_20;
  undefined1 auStack_1c [4];
  undefined4 uStack_18;
  undefined1 uStack_10;
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_1020e0c1;
  iStack_c = *unaff_FS_OFFSET;
  uStack_28 = _DAT_103554c4 ^ (uint)auStack_24;
  *unaff_FS_OFFSET = (int)&iStack_c;
  puStack_2c = (undefined *)0x1015a6ec;
  func_0x1003f970();
  uStack_4 = 0;
  puStack_2c = &UNK_10274940;
  uStack_30 = 0x1015a703;
  __0FString__QAE_PBG_Z();
  puStack_8 = (undefined *)CONCAT31(puStack_8._1_3_,1);
  uStack_30 = 0;
  func_0x10040090(auStack_1c);
  uStack_10 = 0;
  __1FString__QAE_XZ();
  if (_DAT_1035786c == 0) {
    func_0x10005270();
  }
  func_0x100d1790(0x3c0,&uStack_30);
  uStack_18 = 0xffffffff;
  func_0x1003fff0();
  *unaff_FS_OFFSET = iStack_20;
  return;
}

