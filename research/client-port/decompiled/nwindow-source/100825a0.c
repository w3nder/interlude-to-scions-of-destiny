
undefined4 * __fastcall packet_100825a0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &UNK_1018599b;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  __0UL2ConsoleWnd__QAE_XZ();
  uStack_8 = 0;
  *param_1 = &UNK_101b3488;
  param_1[0xd] = &UNK_101b3484;
  param_1[0xeea] = 0;
  func_0x1017224d(param_1 + 0xeee,0xc,3,&UNK_1007f670,&UNK_1007f660);
  param_1[0xef7] = 0;
  param_1[0xefa] = 0;
  param_1[0xefd] = 0;
  param_1[0xefe] = 0;
  param_1[0xeff] = 0;
  param_1[0xf02] = 0;
  param_1[0xf04] = 0;
  param_1[0xf05] = 0;
  param_1[0xf06] = 0;
  param_1[0xf08] = 0;
  param_1[0xf09] = 0;
  param_1[0xf0a] = 0;
  param_1[0xf0c] = 0;
  param_1[0xf0d] = 0;
  param_1[0xf0e] = 0;
  param_1[0xf0f] = 0;
  param_1[0xf10] = 0;
  param_1[0xf11] = 1;
  param_1[0xf14] = 0;
  param_1[0xf15] = 0;
  param_1[0xf18] = 0;
  uStack_8 = CONCAT31(uStack_8._1_3_,5);
  param_1[0xf12] = 0;
  param_1[0xf13] = 0;
  param_1[0xf17] = 0;
  param_1[0xf19] = 0x2711;
  param_1[0xf1c] = 0;
  param_1[0xf22] = 0;
  param_1[0xeed] = 0;
  for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {
    iVar1 = iVar3 * 3;
    for (iVar2 = 0; iVar2 < (int)param_1[iVar1 + 0xeef]; iVar2 = iVar2 + 1) {
    }
    param_1[iVar1 + 0xeef] = 0;
    param_1[iVar1 + 0xef0] = 0;
    _Realloc_FArray__IAEXH_Z(4);
  }
  param_1[0xf0b] = 0;
  param_1[0xeec] = 0;
  param_1[0xeeb] = 0;
  *unaff_FS_OFFSET = uStack_10;
  return param_1;
}

