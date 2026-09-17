
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_1040fde0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 unaff_EBX;
  int iVar5;
  undefined4 unaff_EBP;
  int iVar6;
  int iStack_424;
  int iStack_420;
  int iStack_41c;
  int iStack_418;
  undefined4 uStack_414;
  undefined1 auStack_410 [4];
  undefined1 auStack_40c [4];
  undefined4 uStack_408;
  undefined1 auStack_404 [4];
  undefined1 auStack_400 [4];
  undefined1 auStack_3fc [4];
  undefined1 auStack_3f8 [4];
  undefined1 auStack_3f4 [4];
  undefined1 auStack_3f0 [4];
  undefined1 auStack_3ec [4];
  undefined1 auStack_3e8 [4];
  undefined1 auStack_3e4 [4];
  undefined1 auStack_3e0 [4];
  undefined1 auStack_3dc [4];
  undefined1 auStack_3d8 [4];
  undefined1 auStack_3d4 [4];
  undefined1 auStack_3d0 [4];
  undefined1 auStack_3cc [4];
  undefined1 auStack_3c8 [4];
  undefined1 auStack_3c4 [4];
  undefined1 auStack_3c0 [4];
  undefined1 auStack_3bc [4];
  undefined1 auStack_3b8 [4];
  undefined1 auStack_3b4 [4];
  undefined1 auStack_3b0 [4];
  undefined1 auStack_3ac [4];
  undefined1 auStack_3a8 [4];
  undefined1 auStack_3a4 [4];
  undefined1 auStack_3a0 [8];
  undefined1 auStack_398 [4];
  undefined1 auStack_394 [8];
  undefined1 auStack_38c [4];
  undefined1 auStack_388 [4];
  undefined1 auStack_384 [4];
  undefined1 auStack_380 [4];
  undefined1 auStack_37c [8];
  undefined1 uStack_374;
  undefined1 auStack_373 [71];
  undefined4 uStack_32c;
  undefined1 auStack_318 [48];
  undefined1 auStack_2e8 [4];
  undefined4 uStack_2e4;
  undefined1 auStack_2e0 [4];
  undefined1 auStack_2dc [12];
  undefined1 auStack_2d0 [4];
  undefined1 auStack_2cc [4];
  undefined1 auStack_2c8 [4];
  undefined1 auStack_2c4 [4];
  undefined1 auStack_2c0 [4];
  undefined1 auStack_2bc [8];
  undefined4 uStack_2b4;
  undefined4 uStack_2ac;
  undefined4 uStack_2a0;
  undefined1 auStack_29c [4];
  undefined1 auStack_298 [4];
  undefined1 auStack_294 [4];
  undefined1 auStack_290 [4];
  undefined1 auStack_28c [4];
  undefined1 auStack_288 [4];
  undefined1 auStack_284 [4];
  undefined1 auStack_280 [4];
  undefined1 auStack_27c [4];
  undefined1 auStack_278 [4];
  undefined1 auStack_274 [4];
  undefined1 auStack_270 [4];
  undefined1 auStack_26c [4];
  undefined1 auStack_268 [4];
  undefined1 auStack_264 [12];
  undefined1 auStack_258 [484];
  undefined1 auStack_74 [84];
  undefined1 auStack_20 [32];
  
  if (*(int *)(_DAT_10c51044 + 0x74) != 0) {
    uVar1 = (**(code **)(**(int **)(_DAT_10c51044 + 0x70) + 0x78))();
    uVar2 = _StaticLoadClass_UObject__SAPAVUClass__PAV2_PAV1_PBG2KPAVUPackageMap___Z
                      (&_PrivateStaticClass_UL2OrcMove__0VUClass__A,0,0x10884e34,0,1,0);
    uVar3 = _GetTransientPackage_UObject__SAPAVUPackage__XZ
                      (0,0,0,*(undefined4 *)_GError__3PAVFOutputDeviceError__A_exref,0);
    uVar2 = _StaticConstructObject_UObject__SAPAV1_PAVUClass__PAV1_VFName__K1PAVFOutputDevice__1_Z
                      (uVar2,uVar3);
    *(undefined4 *)(_DAT_10c51044 + 0x70) = uVar2;
    (**(code **)(**(int **)(_DAT_10c51044 + 0x70) + 0x7c))(uVar1);
  }
  uStack_374 = 0;
  func_0x107a6860(auStack_373,0,0x3f);
  iStack_424 = 0;
  iStack_420 = 0;
  iStack_41c = 0;
  iVar5 = 0;
  func_0x10313449();
  uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x10884de8,0x30,auStack_318,
                          auStack_3b0,0x1e,auStack_20,auStack_3b8,auStack_3c0,auStack_3c8,
                          &uStack_408,auStack_2e8,auStack_2e0,auStack_3d0,auStack_3f8,&uStack_414,
                          auStack_400,auStack_3a0,auStack_394,auStack_3d8,auStack_37c,auStack_2dc,
                          auStack_3e0,auStack_3e8,auStack_2d0,auStack_2cc,auStack_2c8,auStack_2c4,
                          auStack_2c0,auStack_2bc,auStack_3ec,auStack_3b4,auStack_388,auStack_3bc,
                          auStack_398,auStack_3c4,auStack_384,auStack_3f0,auStack_3a4,auStack_3d4,
                          auStack_380,auStack_3dc,auStack_3ac,auStack_3e4,auStack_38c,auStack_3cc,
                          auStack_29c,auStack_298,auStack_294,auStack_290,auStack_28c,auStack_288,
                          auStack_284,auStack_280,auStack_27c,auStack_278,auStack_274,auStack_270,
                          auStack_26c,auStack_268,auStack_264,auStack_258,auStack_410,&iStack_424);
  if (0 < iStack_424) {
    uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1087ff8c,&iStack_420);
    if (0 < iStack_420) {
      iVar5 = (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(iStack_420,0x10884dc8);
      uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x10883ef0,unaff_EBX,iVar5);
    }
    iStack_41c = (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)
                           (iStack_424 << 4,0x10884da0);
    iStack_418 = 0;
    if (0 < iStack_424) {
      iVar6 = iStack_41c + 8;
      do {
        uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x108810b0,iVar6 + -8,
                                iVar6 + -4,iVar6,iVar6 + 4);
        iStack_418 = iStack_418 + 1;
        iVar6 = iVar6 + 0x10;
      } while (iStack_418 < iStack_424);
    }
  }
  uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1087ff8c,auStack_74);
  uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x108810b0,auStack_3f4,auStack_3fc,
                          auStack_404,auStack_40c);
  uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1087ff8c,auStack_3a8);
  uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1087ff8c,auStack_258);
  func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x10883ef0,0x40,&uStack_374);
  uStack_2a0 = 0;
  uStack_2b4 = func_0x107a6660();
  uStack_2ac = func_0x107a6660();
  uStack_2e4 = uStack_408;
  uStack_32c = 0;
  iVar6 = **(int **)(_DAT_10b1f538 + 0x54);
  uVar1 = func_0x107a6660(iStack_420,iVar5,iStack_424,iStack_41c);
  uVar1 = func_0x107a6660(uVar1);
  uVar1 = func_0x107a6660(uVar1);
  (**(code **)(iVar6 + 0x300))(uVar1);
  if (iVar5 != 0) {
    (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(iVar5);
  }
  _Logf_FOutputDevice__QAAXPBGZZ(*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10884d50)
  ;
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x444))(unaff_EBP);
  func_0x10310f28(uStack_414,iStack_41c,iStack_424,unaff_EBP,1);
  uVar4 = (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0xe8))(auStack_3a8);
  return uVar4 & 0xffffff00;
}

