
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall packet_1016f110(int param_1)

{
  int *unaff_FS_OFFSET;
  uint uStack_38;
  undefined1 auStack_28 [20];
  undefined1 *puStack_14;
  int iStack_10;
  undefined *puStack_c;
  int iStack_8;
  
  puStack_c = &UNK_10211e72;
  iStack_10 = *unaff_FS_OFFSET;
  uStack_38 = _DAT_103554c4 ^ (uint)&stack0xfffffffc;
  puStack_14 = (undefined1 *)&uStack_38;
  *unaff_FS_OFFSET = (int)&iStack_10;
  iStack_8 = 0;
  if ((*(int *)_GIsOnlyL2Console__3HA_exref == 0) && (*(int *)_GL2ThaiHtmlMode__3HA_exref == 0)) {
    func_0x1016ab60();
    __0FString__QAE_PBG_Z(&UNK_1022f9f8);
    iStack_8._0_1_ = 1;
    func_0x10005c30(700,auStack_28);
    func_0x100d1790();
    iStack_8._0_1_ = 0;
    __1FString__QAE_XZ();
    (**(code **)(**(int **)(*(int *)(param_1 + 0x50) + 0x60) + 0x4e4))();
    __0FString__QAE_PBG_Z(&UNK_1022f9f8);
    iStack_8._0_1_ = 2;
    func_0x10005c30(0x2d0,auStack_28);
    func_0x100d1790();
    iStack_8 = (uint)iStack_8._1_3_ << 8;
    __1FString__QAE_XZ();
  }
  *unaff_FS_OFFSET = iStack_10;
  return;
}

