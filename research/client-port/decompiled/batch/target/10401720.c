
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10401720(void)

{
  uint uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_1c [12];
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  uStack_8 = 0x1080e599;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  __0L2ParamStack__QAE_H_Z(10);
  uStack_4 = 0;
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x4dc))(auStack_1c);
  uStack_8 = 0xffffffff;
  uVar1 = __1L2ParamStack__QAE_XZ();
  *unaff_FS_OFFSET = uStack_10;
  return uVar1 & 0xffffff00;
}

