
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10414f40(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined1 auStack_4c [16];
  undefined1 auStack_3c [44];
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  uStack_8 = 0x1080f039;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x1088500c,0x30,auStack_3c,&param_1,
                  &uStack_60,&uStack_5c,&uStack_58,&uStack_54,&uStack_50);
  __0L2ParamStack__QAE_H_Z(10);
  uStack_4 = 0;
  _PushBack_L2ParamStack__QAEHPAX_Z(auStack_3c);
  _PushBack_L2ParamStack__QAEHPAX_Z(param_1);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_60);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_5c);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_58);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_54);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_50);
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x344))(auStack_4c);
  _Logf_FOutputDevice__QAAXPBGZZ(*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10886138)
  ;
  uStack_8 = 0xffffffff;
  uVar1 = __1L2ParamStack__QAE_XZ();
  *unaff_FS_OFFSET = uStack_10;
  return uVar1 & 0xffffff00;
}

