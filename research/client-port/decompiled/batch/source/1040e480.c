
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_1040e480(undefined4 param_1)

{
  uint uVar1;
  undefined4 *unaff_FS_OFFSET;
  int unaff_retaddr;
  undefined1 *puStack_224;
  undefined4 uStack_220;
  undefined1 auStack_210 [504];
  undefined4 uStack_18;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_1075642b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_220 = 10;
  puStack_224 = (undefined1 *)0x1040e4a6;
  func_0x1030218f();
  puStack_224 = auStack_210;
  puStack_8 = (undefined *)0x0;
  func_0x10305079(*(undefined4 *)(unaff_retaddr + 0x48),param_1,&UNK_107c14b4,0x200);
  puStack_224 = auStack_210;
  func_0x103012c1();
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x42c))(&puStack_224);
  uStack_10 = 0xffffffff;
  uVar1 = func_0x10307f3b();
  *unaff_FS_OFFSET = uStack_18;
  return uVar1 & 0xffffff00;
}

