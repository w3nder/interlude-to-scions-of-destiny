
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void packet_1016cf50(void)

{
  int iVar1;
  int iVar2;
  int *unaff_FS_OFFSET;
  int unaff_retaddr;
  int in_stack_0000136c;
  
  func_0x101c2730();
  *unaff_FS_OFFSET = (int)&stack0x00001380;
  _Restart_L2ParamStack__QAEXXZ();
  func_0x1003f970();
  iVar1 = _Top_L2ParamStack__QAEPAXXZ();
  __0FString__QAE_PBG_Z();
  func_0x10040090();
  __1FString__QAE_XZ();
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      _Top_L2ParamStack__QAEPAXXZ();
      _Top_L2ParamStack__QAEPAXXZ();
      iVar1 = func_0x10164870();
      if (iVar1 != 0) {
        func_0x10164870();
        _appStrcpy__YAPAGPAGPBG_Z();
      }
      iVar1 = func_0x10164900();
      if (iVar1 != 0) {
        func_0x10164900();
        _appStrcpy__YAPAGPAGPBG_Z();
      }
      iVar1 = func_0x10164990();
      if (iVar1 != 0) {
        func_0x10164990();
        _appStrcpy__YAPAGPAGPBG_Z();
      }
      _Printf_FString__SA_AV1_PBGZZ();
      func_0x10040090();
      __1FString__QAE_XZ();
      _Printf_FString__SA_AV1_PBGZZ();
      func_0x10040090();
      __1FString__QAE_XZ();
      _Printf_FString__SA_AV1_PBGZZ();
      func_0x10040090();
      __1FString__QAE_XZ();
      __0FString__QAE_PBG_Z();
      _Printf_FString__SA_AV1_PBGZZ();
      func_0x10040230();
      __1FString__QAE_XZ();
      __1FString__QAE_XZ();
      __0FString__QAE_PBG_Z();
      _Printf_FString__SA_AV1_PBGZZ();
      func_0x10040230();
      __1FString__QAE_XZ();
      __1FString__QAE_XZ();
      __0FString__QAE_PBG_Z();
      _Printf_FString__SA_AV1_PBGZZ();
      func_0x10040230();
      __1FString__QAE_XZ();
      __1FString__QAE_XZ();
      iVar2 = iVar2 + 1;
    } while (iVar2 < unaff_retaddr);
  }
  if (_DAT_1035786c == 0) {
    func_0x10005270();
  }
  func_0x100d1790();
  func_0x1003fff0();
  *unaff_FS_OFFSET = in_stack_0000136c;
  func_0x101c16c2();
  return;
}

