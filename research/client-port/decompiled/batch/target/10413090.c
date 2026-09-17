
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10413090(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *unaff_FS_OFFSET;
  int iStack_84;
  undefined4 uStack_80;
  undefined1 auStack_7c [16];
  undefined1 auStack_6c [48];
  undefined1 auStack_3c [44];
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  uStack_8 = 0x1080edf9;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x10885760,&uStack_80,0x30,
                          auStack_6c,&iStack_84);
  __0L2ParamStack__QAE_H_Z(10);
  uStack_4 = 0;
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_80);
  _PushBack_L2ParamStack__QAEHPAX_Z(auStack_6c);
  _PushBack_L2ParamStack__QAEHPAX_Z(iStack_84);
  if (iStack_84 != 0) {
    func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x108847bc,0x30,auStack_3c);
    _PushBack_L2ParamStack__QAEHPAX_Z(auStack_3c);
  }
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x364))(auStack_7c);
  _Logf_FOutputDevice__QAAXPBGZZ(*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x108858b8)
  ;
  uStack_8 = 0xffffffff;
  uVar2 = __1L2ParamStack__QAE_XZ();
  *unaff_FS_OFFSET = uStack_10;
  return uVar2 & 0xffffff00;
}

