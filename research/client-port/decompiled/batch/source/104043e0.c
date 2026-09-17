
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_104043e0(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 *puStack_68;
  undefined1 *puStack_64;
  undefined1 *puStack_60;
  undefined1 auStack_5c [4];
  undefined1 auStack_58 [4];
  undefined1 auStack_54 [4];
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [16];
  undefined4 uStack_2c;
  undefined4 uStack_24;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &UNK_10755ca8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  puStack_60 = auStack_50;
  puStack_64 = auStack_54;
  puStack_68 = auStack_58;
  func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c1cec,0x30,auStack_3c,&param_1,
                  auStack_5c);
  puStack_60 = (undefined1 *)0xa;
  puStack_64 = (undefined1 *)0x1040443d;
  func_0x1030218f();
  puStack_64 = auStack_40;
  puStack_8 = (undefined *)0x0;
  puStack_68 = (undefined1 *)0x10404453;
  func_0x103012c1();
  puStack_68 = puStack_4;
  func_0x103012c1();
  func_0x103012c1(puStack_68);
  func_0x103012c1(puStack_68);
  func_0x103012c1(puStack_68);
  func_0x103012c1(puStack_68);
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x280))(&puStack_68);
  uStack_24 = 0xffffffff;
  uVar1 = func_0x10307f3b();
  *unaff_FS_OFFSET = uStack_2c;
  return uVar1 & 0xffffff00;
}

