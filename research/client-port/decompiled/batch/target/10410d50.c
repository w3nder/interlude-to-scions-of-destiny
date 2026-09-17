
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10410d50(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *unaff_FS_OFFSET;
  int iStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined1 auStack_4c [16];
  undefined1 auStack_3c [48];
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  uStack_8 = 0x1080ec49;
  *unaff_FS_OFFSET = &uStack_c;
  uVar2 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x108843d0,0x30,auStack_3c,
                          &iStack_5c);
  _Logf_FOutputDevice__QAAXPBGZZ(*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10885030)
  ;
  uVar3 = (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x520))();
  while (0 < iStack_5c) {
    iStack_5c = iStack_5c + -1;
    __0L2ParamStack__QAE_H_Z(10);
    uStack_4 = 0;
    uVar2 = func_0x103034e5(*(undefined4 *)(iVar1 + 0x48),uVar2,0x10881140,&uStack_58,&uStack_54,
                            &uStack_50,&param_1);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_58);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_54);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_50);
    _PushBack_L2ParamStack__QAEHPAX_Z((int)(char)param_1);
    (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x524))(auStack_4c);
    uStack_4 = 0xffffffff;
    uVar3 = __1L2ParamStack__QAE_XZ();
  }
  *unaff_FS_OFFSET = uStack_c;
  return uVar3 & 0xffffff00;
}

