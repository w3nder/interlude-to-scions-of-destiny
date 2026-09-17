
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void packet_10165b90(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  int *unaff_FS_OFFSET;
  uint uStack_48;
  undefined1 auStack_38 [12];
  undefined1 auStack_2c [20];
  int iStack_18;
  undefined1 *puStack_14;
  int iStack_10;
  undefined *puStack_c;
  uint uStack_8;
  
  puStack_c = &UNK_10210523;
  iStack_10 = *unaff_FS_OFFSET;
  uStack_48 = _DAT_103554c4 ^ (uint)&stack0xfffffffc;
  puStack_14 = (undefined1 *)&uStack_48;
  *unaff_FS_OFFSET = (int)&iStack_10;
  uStack_8 = 0;
  func_0x1003f970();
  pcVar4 = _Top_L2ParamStack__QAEPAXXZ_exref;
  uStack_8._0_1_ = 1;
  uVar2 = _Top_L2ParamStack__QAEPAXXZ();
  __0FString__QAE_PBG_Z(&UNK_10284490);
  uStack_8._0_1_ = 2;
  func_0x10040090(auStack_38,uVar2);
  uStack_8._0_1_ = 1;
  __1FString__QAE_XZ();
  uVar2 = _Top_L2ParamStack__QAEPAXXZ();
  __0FString__QAE_PBG_Z(&UNK_10274014);
  uStack_8._0_1_ = 3;
  func_0x10040090(auStack_38,uVar2);
  uStack_8 = CONCAT31(uStack_8._1_3_,1);
  __1FString__QAE_XZ();
  iStack_18 = 0;
  while (iVar1 = iStack_18, iStack_18 < 0x20) {
    uVar2 = (*pcVar4)();
    uVar3 = _Printf_FString__SA_AV1_PBGZZ(auStack_38,&UNK_10284410,iVar1);
    uStack_8._0_1_ = 4;
    func_0x10040090(uVar3,uVar2);
    uStack_8 = CONCAT31(uStack_8._1_3_,1);
    __1FString__QAE_XZ();
    pcVar4 = _Top_L2ParamStack__QAEPAXXZ_exref;
    iStack_18 = iVar1 + 1;
  }
  func_0x10005c30(0x172,auStack_2c);
  func_0x100d1790();
  uStack_8 = uStack_8 & 0xffffff00;
  func_0x1003fff0();
  *unaff_FS_OFFSET = iStack_10;
  return;
}

