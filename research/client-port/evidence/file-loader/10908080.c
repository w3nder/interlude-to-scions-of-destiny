
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

FArchive * __thiscall FUN_10908080(void *this,undefined **param_1,byte param_2,int param_3)

{
  undefined **ppuVar1;
  HANDLE hFile;
  void *pvVar2;
  DWORD DVar3;
  FArchive *pFVar4;
  int iVar5;
  FArchive *pFVar6;
  FOutputDevice *this_00;
  char *pcVar7;
  ushort *puVar8;
  undefined **ppuVar9;
  wchar_t *pwVar10;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  ppuVar1 = param_1;
  puStack_c = &LAB_10921cf0;
  local_10 = ExceptionList;
  local_8 = 0;
  if (*(int *)GUnicodeOS_exref == 0) {
    ExceptionList = &local_10;
    iVar5 = winGetSizeANSI((ushort *)param_1);
    if (iVar5 == 0) {
      pcVar7 = (char *)0x0;
    }
    else {
      winGetSizeANSI((ushort *)ppuVar1);
      pcVar7 = &stack0xffffffd4;
    }
    iVar5 = winGetSizeANSI((ushort *)ppuVar1);
    pcVar7 = winToANSI(pcVar7,(ushort *)ppuVar1,iVar5);
    hFile = CreateFileA(pcVar7,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  }
  else {
    ExceptionList = &local_10;
    hFile = CreateFileW((LPCWSTR)param_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0)
    ;
  }
  if (hFile == (HANDLE)0xffffffff) {
    if ((param_2 & 1) != 0) {
      if (*(int *)GLanguageType_exref == 0) {
        puVar8 = *(ushort **)GError_exref;
        pwVar10 =
        L"%s을(를) 읽을 수 없습니다.\r\nFull Check를 하시고 다시 실행하시기 바랍니다."
        ;
        this_00 = (FOutputDevice *)GLanguageType_exref;
      }
      else {
        puVar8 = *(ushort **)GError_exref;
        pwVar10 = L"%s cannot be read.\r\nPlease perform a Full Check and try running it again.";
        this_00 = (FOutputDevice *)GError_exref;
      }
      FOutputDevice::Logf(this_00,puVar8,pwVar10,ppuVar1);
    }
    ExceptionList = local_10;
    return (FArchive *)0x0;
  }
  pvVar2 = (void *)(**(code **)**(undefined4 **)GMalloc_exref)(0x48,L"L2DecryptFileReader");
  if (pvVar2 == (void *)0x0) {
    pFVar4 = (FArchive *)0x0;
  }
  else {
    ppuVar9 = ppuVar1;
    DVar3 = GetFileSize(hFile,(LPDWORD)0x0);
    pFVar4 = thunk_FUN_10908430(pvVar2,hFile,param_3,DVar3,(wchar_t *)ppuVar9);
  }
  iVar5 = appStricmp((ushort *)L"L2.ini",(ushort *)ppuVar1);
  if (iVar5 == 0) {
    if (pFVar4 != (FArchive *)0x0) {
      *(undefined4 *)((int)this + 4) = *(undefined4 *)(pFVar4 + 0x3c);
    }
    if (*(int *)(pFVar4 + 0x3c) != 0x19d) {
      ExceptionList = local_10;
      return pFVar4;
    }
    FCodec::FCodec((FCodec *)&param_1);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  else {
    iVar5 = appStricmp((ushort *)L"User.ini",(ushort *)ppuVar1);
    if (iVar5 != 0) {
      iVar5 = appStricmp((ushort *)L"option.ini",(ushort *)ppuVar1);
      if (iVar5 != 0) {
        ExceptionList = local_10;
        return pFVar4;
      }
      if (pFVar4 == (FArchive *)0x0) {
        ExceptionList = local_10;
        return (FArchive *)0x0;
      }
      *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(pFVar4 + 0x3c);
      ExceptionList = local_10;
      return pFVar4;
    }
    if (pFVar4 != (FArchive *)0x0) {
      *(undefined4 *)((int)this + 8) = *(undefined4 *)(pFVar4 + 0x3c);
    }
    if (*(int *)(pFVar4 + 0x3c) != 0x19d) {
      ExceptionList = local_10;
      return pFVar4;
    }
    FCodec::FCodec((FCodec *)&param_1);
    local_8 = CONCAT31(local_8._1_3_,2);
  }
  param_1 = &PTR_LAB_10926b78;
  pvVar2 = (void *)(**(code **)**(undefined4 **)GMalloc_exref)(0x48,L"L2MemArchive");
  if (pvVar2 == (void *)0x0) {
    pFVar6 = (FArchive *)0x0;
  }
  else {
    iVar5 = (**(code **)(*(int *)pFVar4 + 0x2c))();
    pFVar6 = thunk_FUN_10907e30(pvVar2,iVar5);
  }
  thunk_FUN_10904900((int *)pFVar4);
  *(undefined4 *)(pFVar6 + 0x44) = 0;
  *(undefined4 *)(pFVar6 + 0x3c) = 0;
  *(undefined4 *)(pFVar6 + 0x10) = 1;
  *(undefined4 *)(pFVar6 + 0x14) = 0;
  (*(code *)**(undefined4 **)pFVar4)(1);
  ExceptionList = local_10;
  return pFVar6;
}
