
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10400fc0(void)

{
  uint uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_1c [12];
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  uStack_8 = 0x1080e4a9;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  __0L2ParamStack__QAE_H_Z(10);
  uStack_4 = 0;
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x3ac))(auStack_1c);
  _Logf_FOutputDevice__QAAXPBGZZ(*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x1087ec78)
  ;
  uStack_8 = 0xffffffff;
  uVar1 = __1L2ParamStack__QAE_XZ();
  *unaff_FS_OFFSET = uStack_10;
  return uVar1 & 0xffffff00;
}

