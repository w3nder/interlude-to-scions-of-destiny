
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_1040d250(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_428;
  undefined4 uStack_424;
  undefined4 uStack_420;
  undefined1 auStack_41c [12];
  undefined1 auStack_410 [4];
  undefined1 auStack_40c [1020];
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  uStack_8 = 0x1080e9dc;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x10884188,&uStack_424,&uStack_420,
                  &uStack_428,0x400,auStack_40c);
  __0L2ParamStack__QAE_H_Z(10);
  uStack_4 = 0;
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_424);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_420);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_428);
  _PushBack_L2ParamStack__QAEHPAX_Z(auStack_40c);
  (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x5b8))(auStack_41c);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10884100,uStack_428,unaff_ESI
             ,auStack_410);
  uStack_8 = 0xffffffff;
  uVar1 = __1L2ParamStack__QAE_XZ();
  *unaff_FS_OFFSET = uStack_10;
  return uVar1 & 0xffffff00;
}

