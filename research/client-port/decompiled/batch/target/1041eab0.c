
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_1041eab0(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_220;
  undefined1 auStack_21c [16];
  undefined1 auStack_20c [508];
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  uStack_8 = 0x1080f8bc;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  __0L2ParamStack__QAE_H_Z(10);
  uStack_4 = 0;
  func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x108843d0,0x200,auStack_20c,&uStack_220);
  _PushBack_L2ParamStack__QAEHPAX_Z(auStack_20c);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_220);
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x4e4))(auStack_21c);
  uStack_8 = 0xffffffff;
  uVar1 = __1L2ParamStack__QAE_XZ();
  *unaff_FS_OFFSET = uStack_10;
  return uVar1 & 0xffffff00;
}

