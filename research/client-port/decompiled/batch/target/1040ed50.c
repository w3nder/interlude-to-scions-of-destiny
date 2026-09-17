
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_1040ed50(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_a8 [56];
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 auStack_2c [16];
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  int iStack_8;
  
  uStack_c = 0x1080eb89;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  puStack_14 = &stack0xffffff4c;
  iStack_8 = 0;
  func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x10884a8c,&uStack_18,&uStack_1c,
                  &uStack_38,&uStack_40,&uStack_3c,0x30,auStack_a8,&uStack_4c,&uStack_54,&uStack_50,
                  &uStack_48,&uStack_30,&uStack_44,&uStack_34,&uStack_68,&uStack_70,&uStack_60);
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f64) = uStack_18;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f68) = uStack_1c;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f9c) = uStack_38;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4fa0) = uStack_40;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4fa4) = uStack_3c;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4fd8) = uStack_4c;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4fdc) = uStack_54;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4fa8) = uStack_50;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4fac) = uStack_48;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4fb0) = uStack_30;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4fb4) = uStack_44;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4fbc) = uStack_34;
  iVar1 = *(int *)(param_1 + 0x48);
  *(undefined4 *)(iVar1 + 0x4fc0) = uStack_68;
  *(undefined4 *)(iVar1 + 0x4fc4) = uStack_64;
  iVar1 = *(int *)(param_1 + 0x48);
  *(undefined4 *)(iVar1 + 0x4fc8) = uStack_70;
  *(undefined4 *)(iVar1 + 0x4fcc) = uStack_6c;
  iVar1 = *(int *)(param_1 + 0x48);
  *(undefined4 *)(iVar1 + 0x4fd0) = uStack_60;
  *(undefined4 *)(iVar1 + 0x4fd4) = uStack_5c;
  func_0x1030c00e(uStack_18,uStack_1c,uStack_38,uStack_40,uStack_3c);
  __0L2ParamStack__QAE_H_Z(10);
  iStack_8._0_1_ = 1;
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_1c);
  _PushBack_L2ParamStack__QAEHPAX_Z(auStack_a8);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_4c);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_54);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_50);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_48);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_30);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_44);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_34);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_68);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_70);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_60);
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x500))(uStack_18,auStack_2c);
  _Logf_FOutputDevice__QAAXPBGZZ(*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10884a40)
  ;
  iStack_8 = (uint)iStack_8._1_3_ << 8;
  uVar2 = __1L2ParamStack__QAE_XZ();
  *unaff_FS_OFFSET = uStack_10;
  return uVar2 & 0xffffff00;
}

