
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_104123c0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_68 [4];
  undefined4 uStack_64;
  undefined1 auStack_60 [4];
  undefined1 auStack_5c [12];
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [2];
  undefined1 auStack_4a [2];
  undefined4 uStack_48;
  undefined1 auStack_44 [12];
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [4];
  undefined1 auStack_30 [12];
  undefined4 uStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_c = 0x1080ecb0;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  puStack_14 = &stack0xffffff8c;
  uStack_8 = 0;
  uStack_20 = 0;
  uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x1088494c,&uStack_20);
  for (iStack_1c = 0; iStack_1c < (short)uStack_20; iStack_1c = iStack_1c + 1) {
    func_0x1030cc7f();
    uStack_48 = 0;
    uStack_18 = 0xffffffff;
    uStack_24 = 0xffffffff;
    uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x108849f4,&uStack_18,&uStack_24);
    uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1088517c,&uStack_64,auStack_60,
                            auStack_5c,auStack_68,auStack_4c,auStack_4a,auStack_50,&uStack_48,
                            auStack_44,auStack_38,auStack_34,auStack_30);
    (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x2e0))((int)(short)uStack_18,auStack_68);
    if (((short)uStack_18 == 2) || ((short)uStack_18 == 3)) {
      (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x404))(uStack_64);
    }
  }
  uVar2 = _Logf_FOutputDevice__QAAXPBGZZ
                    (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x1088558c);
  *unaff_FS_OFFSET = uStack_10;
  return uVar2 & 0xffffff00;
}

