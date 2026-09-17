
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10415450(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *unaff_FS_OFFSET;
  int iStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 auStack_1c [16];
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  uStack_8 = 0x1080f079;
  *unaff_FS_OFFSET = &uStack_c;
  uVar2 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x1087ff8c,&iStack_2c);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10886288,iStack_2c);
  (**(code **)(*(int *)_DAT_10b1f538[0x15] + 0x45c))();
  while (0 < iStack_2c) {
    iStack_2c = iStack_2c + -1;
    __0L2ParamStack__QAE_H_Z(10);
    uStack_4 = 0;
    uVar2 = func_0x103034e5(*(undefined4 *)(iVar1 + 0x48),uVar2,0x10881140,&uStack_28,&uStack_24,
                            &uStack_20,&param_1);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_28);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_24);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_20);
    _PushBack_L2ParamStack__QAEHPAX_Z((int)(char)param_1);
    (**(code **)(*(int *)_DAT_10b1f538[0x15] + 0x464))(auStack_1c);
    uStack_4 = 0xffffffff;
    __1L2ParamStack__QAE_XZ();
  }
  iStack_2c = iStack_2c + -1;
  uVar3 = (**(code **)(*_DAT_10b1f538 + 0x338))();
  *unaff_FS_OFFSET = uStack_c;
  return uVar3 & 0xffffff00;
}

