
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_1041c900(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_6c [16];
  undefined1 auStack_5c [16];
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  undefined1 *puStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  uint uStack_8;
  
  uStack_c = 0x1080f702;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  puStack_14 = &stack0xffffff88;
  uStack_8 = 0;
  uStack_28 = 0xffffffff;
  uStack_4c = 0xffffffff;
  uStack_48 = 0xffffffff;
  uStack_24 = 0xffffffff;
  uStack_20 = 0xffffffff;
  uStack_1c = 0xffffffff;
  uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x10887d4c,&uStack_1c,&uStack_20,
                          &uStack_24,&uStack_4c,&uStack_28);
  __0L2ParamStack__QAE_H_Z(10);
  uStack_8 = CONCAT31(uStack_8._1_3_,1);
  _PushBack_L2ParamStack__QAEHPAX_Z(1);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_1c);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_20);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_24);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_4c);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_28);
  _PushBack_L2ParamStack__QAEHPAX_Z(3);
  iStack_2c = 0;
  uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1087ff8c,&iStack_2c);
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x48c))(auStack_5c);
  for (iStack_18 = 0; iStack_18 < iStack_2c; iStack_18 = iStack_18 + 1) {
    uStack_30 = 0xffffffff;
    uStack_34 = 0xffffffff;
    uStack_38 = 0;
    uStack_3c = 0;
    uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x108810b0,&uStack_30,&uStack_34,
                            &uStack_38,&uStack_3c);
    __0L2ParamStack__QAE_H_Z(10);
    uStack_8._0_1_ = 2;
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_30);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_34);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_38);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_3c);
    (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x494))(auStack_6c);
    uStack_8 = CONCAT31(uStack_8._1_3_,1);
    __1L2ParamStack__QAE_XZ();
  }
  _Logf_FOutputDevice__QAAXPBGZZ(*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10887cf8)
  ;
  uStack_8 = uStack_8 & 0xffffff00;
  uVar2 = __1L2ParamStack__QAE_XZ();
  *unaff_FS_OFFSET = uStack_10;
  return uVar2 & 0xffffff00;
}

