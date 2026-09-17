
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_103fe1f0(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 *puVar2;
  undefined1 *puVar3;
  undefined4 uStack_430;
  undefined1 *puStack_42c;
  undefined4 uStack_428;
  undefined1 auStack_424 [4];
  undefined1 auStack_420 [4];
  undefined1 auStack_41c [16];
  undefined1 auStack_40c [1000];
  undefined4 uStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_1075591b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  puStack_42c = auStack_40c;
  uStack_430 = 0x400;
  func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c1400,auStack_424,auStack_420,
                  &uStack_428);
  puStack_42c = (undefined1 *)0xa;
  uStack_430 = 0x103fe24f;
  func_0x1030218f();
  uStack_430 = uStack_428;
  puStack_8 = (undefined *)0x0;
  func_0x103012c1();
  func_0x103012c1(uStack_428);
  func_0x103012c1(uStack_428);
  puVar3 = auStack_41c;
  func_0x103012c1(puVar3);
  puVar2 = &uStack_430;
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x30))(puVar2);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c1378,puVar3,puVar2,
             auStack_424);
  (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
            (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c12f0,puVar3,puVar2,auStack_424);
  uStack_1c = 0xffffffff;
  uVar1 = func_0x10307f3b();
  *unaff_FS_OFFSET = uStack_24;
  return uVar1 & 0xffffff00;
}

