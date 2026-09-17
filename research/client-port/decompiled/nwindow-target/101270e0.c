
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void packet_101270e0(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *unaff_FS_OFFSET;
  uint uStack_58;
  undefined1 auStack_48 [12];
  undefined1 auStack_3c [12];
  undefined1 auStack_30 [20];
  int iStack_1c;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  int iStack_10;
  undefined *puStack_c;
  int iStack_8;
  
  iVar3 = param_1;
                    /* 0x1270e0  1319  ?execGetQuestItem@UUIDATA_QUEST@@QAEXAAUFFrame@@QAX@Z */
  puStack_c = &UNK_10206823;
  iStack_10 = *unaff_FS_OFFSET;
  uStack_58 = _DAT_103554c4 ^ (uint)&stack0xfffffffc;
  puStack_14 = (undefined1 *)&uStack_58;
  *unaff_FS_OFFSET = (int)&iStack_10;
  iStack_8 = 0;
  uStack_18 = 0;
  bVar1 = **(byte **)(param_1 + 0xc);
  *(byte **)(param_1 + 0xc) = *(byte **)(param_1 + 0xc) + 1;
  (**(code **)(_GNatives__3PAP8UObject__AEXAAUFFrame__QAX_ZA_exref + (uint)bVar1 * 4))
            (param_1,&uStack_18);
  param_1 = 0;
  bVar1 = **(byte **)(iVar3 + 0xc);
  *(byte **)(iVar3 + 0xc) = *(byte **)(iVar3 + 0xc) + 1;
  (**(code **)(_GNatives__3PAP8UObject__AEXAAUFFrame__QAX_ZA_exref + (uint)bVar1 * 4))
            (iVar3,&param_1);
  *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;
  if (**(char **)(iVar3 + 0xc) == 'B') {
    *(char **)(iVar3 + 0xc) = *(char **)(iVar3 + 0xc) + 1;
    (**(code **)(_GNatives__3PAP8UObject__AEXAAUFFrame__QAX_ZA_exref + 0x108))(iVar3,0);
  }
  func_0x10126480(uStack_18,param_1);
  iVar3 = func_0x101b6910();
  func_0x1003f970();
  iStack_8._0_1_ = 1;
  if (iVar3 != 0) {
    __0FString__QAE_PBG_Z(&UNK_10274940);
    iStack_8._0_1_ = 2;
    func_0x10040090(auStack_3c,*(undefined4 *)(iVar3 + 0x38));
    iStack_8._0_1_ = 1;
    __1FString__QAE_XZ();
    iStack_1c = 0;
    while (iVar2 = iStack_1c, iStack_1c < *(int *)(iVar3 + 0x38)) {
      uVar4 = _Printf_FString__SA_AV1_PBGZZ(auStack_3c,&UNK_10277730,iStack_1c);
      iStack_8._0_1_ = 3;
      func_0x10040090(uVar4,*(undefined4 *)(*(int *)(iVar3 + 0x34) + iVar2 * 4));
      iStack_8._0_1_ = 1;
      __1FString__QAE_XZ();
      uVar4 = _Printf_FString__SA_AV1_PBGZZ(auStack_48,&UNK_10277718,iVar2);
      iStack_8._0_1_ = 4;
      func_0x10040090(uVar4,*(undefined4 *)(*(int *)(iVar3 + 0x40) + iVar2 * 4));
      iStack_8._0_1_ = 1;
      __1FString__QAE_XZ();
      iStack_1c = iVar2 + 1;
    }
    __4FString__QAEAAV0_ABV0__Z(auStack_30);
  }
  iStack_8 = (uint)iStack_8._1_3_ << 8;
  func_0x1003fff0();
  *unaff_FS_OFFSET = iStack_10;
  return;
}

