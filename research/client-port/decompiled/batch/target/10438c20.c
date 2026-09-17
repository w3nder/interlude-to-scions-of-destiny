
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10438c20(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  short unaff_BP;
  int iVar4;
  undefined4 uStack_10;
  undefined4 uStack_c;
  int iStack_8;
  undefined4 uStack_4;
  
  iVar1 = param_1;
  uStack_10 = 0;
  uVar2 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x1088494c,&uStack_10);
  iVar4 = *(int *)(iVar1 + 0x48);
  *(undefined4 *)(iVar4 + 0x5028) = 0;
  *(undefined4 *)(iVar4 + 0x502c) = 0;
  _Realloc_FArray__IAEXH_Z(0xc);
  *(undefined4 *)(iVar4 + 0x5034) = 8;
  func_0x103064d3();
  _appMemset__YAXPAXHH_Z(iVar4 + 0x5038,0,0x80);
  iVar4 = 0;
  if (0 < (short)uStack_10) {
    do {
      uStack_c = 0;
      param_1 = 0;
      uVar2 = func_0x103034e5(*(undefined4 *)(iVar1 + 0x48),uVar2,0x1087ff44,&uStack_c,&param_1);
      uStack_4 = uStack_c;
      iStack_8 = param_1;
      func_0x10312b34(&uStack_4,&iStack_8);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (short)uStack_10);
  }
  iVar4 = (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(0x80,0x1088b190);
  func_0x103034e5(*(undefined4 *)(iVar1 + 0x48),uVar2,0x10883ef0,0x80,iVar4);
  func_0x107a6260(*(int *)(iVar1 + 0x48) + 0x5038,iVar4,0x80);
  if (iVar4 != 0) {
    (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(iVar4);
  }
  func_0x103095e8();
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x438))();
  uVar3 = _Logf_FOutputDevice__QAAXPBGZZ
                    (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x1088b154,
                     (int)unaff_BP);
  return uVar3 & 0xffffff00;
}

