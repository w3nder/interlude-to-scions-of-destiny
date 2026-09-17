
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void packet_10156b70(void)

{
  undefined4 uVar1;
  int *unaff_FS_OFFSET;
  uint uStack_50;
  undefined1 auStack_40 [12];
  undefined1 auStack_34 [12];
  undefined1 auStack_28 [20];
  undefined1 *puStack_14;
  int iStack_10;
  undefined *puStack_c;
  int iStack_8;
  
  puStack_c = &UNK_1020d4ac;
  iStack_10 = *unaff_FS_OFFSET;
  uStack_50 = _DAT_103554c4 ^ (uint)&stack0xfffffffc;
  puStack_14 = (undefined1 *)&uStack_50;
  *unaff_FS_OFFSET = (int)&iStack_10;
  iStack_8 = 0;
  _Restart_L2ParamStack__QAEXXZ();
  func_0x1003f970();
  iStack_8._0_1_ = 1;
  uVar1 = _Top_L2ParamStack__QAEPAXXZ();
  __0FString__QAE_PBG_Z(uVar1);
  iStack_8._0_1_ = 2;
  __0FString__QAE_PBG_Z(&UNK_1028306c);
  iStack_8._0_1_ = 3;
  func_0x10040230(auStack_34,auStack_40);
  iStack_8._0_1_ = 2;
  __1FString__QAE_XZ();
  iStack_8._0_1_ = 1;
  __1FString__QAE_XZ();
  __0FString__QAE_PBG_Z(&UNK_10283058);
  iStack_8._0_1_ = 4;
  uVar1 = _Top_L2ParamStack__QAEPAXXZ();
  func_0x10040090(auStack_40,uVar1);
  iStack_8._0_1_ = 1;
  __1FString__QAE_XZ();
  __0FString__QAE_PBG_Z(&UNK_10282fa4);
  iStack_8._0_1_ = 5;
  uVar1 = _Top_L2ParamStack__QAEPAXXZ();
  func_0x10040090(auStack_40,uVar1);
  iStack_8._0_1_ = 1;
  __1FString__QAE_XZ();
  func_0x10005c30(0x56e,auStack_28);
  func_0x100d1790();
  iStack_8 = (uint)iStack_8._1_3_ << 8;
  func_0x1003fff0();
  *unaff_FS_OFFSET = iStack_10;
  return;
}

