
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_1041a880(int param_1,undefined4 param_2)

{
  uint uVar1;
  char cVar2;
  undefined4 *unaff_FS_OFFSET;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  undefined1 auStack_1c [12];
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  uStack_8 = 0x1080f539;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x424))();
  iStack_34 = 0;
  iStack_30 = 0;
  iStack_2c = 0;
  iStack_28 = 0;
  iStack_24 = 0;
  iStack_20 = 0;
  iStack_38 = 0;
  func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x108874cc,&iStack_34,&iStack_30,
                  &iStack_2c,&iStack_28,&iStack_24,&iStack_20,&iStack_38);
  cVar2 = 0 < iStack_38;
  if (0 < iStack_34) {
    cVar2 = cVar2 + '\x01';
  }
  if (0 < iStack_30) {
    cVar2 = cVar2 + '\x01';
  }
  if (0 < iStack_2c) {
    cVar2 = cVar2 + '\x01';
  }
  if (0 < iStack_28) {
    cVar2 = cVar2 + '\x01';
  }
  if (0 < iStack_24) {
    cVar2 = cVar2 + '\x01';
  }
  if (0 < iStack_20) {
    cVar2 = cVar2 + '\x01';
  }
  __0L2ParamStack__QAE_H_Z(0xc);
  uStack_4 = 0;
  _PushBack_L2ParamStack__QAEHPAX_Z(cVar2);
  if (0 < iStack_38) {
    _PushBack_L2ParamStack__QAEHPAX_Z(0x13d4);
    _PushBack_L2ParamStack__QAEHPAX_Z(iStack_38);
  }
  if (0 < iStack_34) {
    _PushBack_L2ParamStack__QAEHPAX_Z(0x10af);
    _PushBack_L2ParamStack__QAEHPAX_Z(iStack_34);
  }
  if (0 < iStack_30) {
    _PushBack_L2ParamStack__QAEHPAX_Z(0x10ae);
    _PushBack_L2ParamStack__QAEHPAX_Z(iStack_30);
  }
  if (0 < iStack_2c) {
    _PushBack_L2ParamStack__QAEHPAX_Z(0x10ad);
    _PushBack_L2ParamStack__QAEHPAX_Z(1);
  }
  if (0 < iStack_28) {
    _PushBack_L2ParamStack__QAEHPAX_Z(0x10ac);
    _PushBack_L2ParamStack__QAEHPAX_Z(1);
  }
  if (0 < iStack_24) {
    _PushBack_L2ParamStack__QAEHPAX_Z(0x10ab);
    _PushBack_L2ParamStack__QAEHPAX_Z(1);
  }
  if (0 < iStack_20) {
    _PushBack_L2ParamStack__QAEHPAX_Z(0x13b1);
    _PushBack_L2ParamStack__QAEHPAX_Z(1);
  }
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x428))(auStack_1c);
  _Logf_FOutputDevice__QAAXPBGZZ(*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10887480)
  ;
  uStack_8 = 0xffffffff;
  uVar1 = __1L2ParamStack__QAE_XZ();
  *unaff_FS_OFFSET = uStack_10;
  return uVar1 & 0xffffff00;
}

