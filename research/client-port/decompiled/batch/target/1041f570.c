
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_1041f570(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_258 [256];
  undefined1 auStack_158 [264];
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [16];
  undefined4 uStack_30;
  undefined4 auStack_2c [2];
  undefined4 uStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  int iStack_18;
  undefined1 *puStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  uint uStack_8;
  
  uStack_c = 0x1080f992;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  puStack_14 = &stack0xfffffd9c;
  uStack_8 = 0;
  uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x10884368,0x100,auStack_158,
                          &uStack_24,&uStack_30,&iStack_1c);
  __0L2ParamStack__QAE_H_Z(10);
  uStack_8 = CONCAT31(uStack_8._1_3_,1);
  _PushBack_L2ParamStack__QAEHPAX_Z(auStack_158);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_24);
  _PushBack_L2ParamStack__QAEHPAX_Z(iStack_1c);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_30);
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x730))(auStack_40);
  for (iStack_18 = 0; iStack_18 < iStack_1c; iStack_18 = iStack_18 + 1) {
    uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1088424c,0x100,auStack_258,
                            auStack_2c,&uStack_20);
    __0L2ParamStack__QAE_H_Z(10);
    uStack_8._0_1_ = 2;
    _PushBack_L2ParamStack__QAEHPAX_Z(auStack_258);
    _PushBack_L2ParamStack__QAEHPAX_Z(auStack_2c[0]);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_20);
    (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x734))(auStack_50);
    uStack_8 = CONCAT31(uStack_8._1_3_,1);
    __1L2ParamStack__QAE_XZ();
  }
  uStack_8 = uStack_8 & 0xffffff00;
  uVar2 = __1L2ParamStack__QAE_XZ();
  *unaff_FS_OFFSET = uStack_10;
  return uVar2 & 0xffffff00;
}

