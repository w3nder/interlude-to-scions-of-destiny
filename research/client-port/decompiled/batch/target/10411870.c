
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10411870(int param_1,undefined4 param_2)

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
  undefined4 uStack_1c;
  int iStack_18;
  undefined1 *puStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_c = 0x1080ec80;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  puStack_14 = &stack0xffffff8c;
  uStack_8 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x108849f4,&uStack_20,&uStack_1c);
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x2dc))((int)(short)uStack_20);
  for (iStack_18 = 0; iStack_18 < (short)uStack_1c; iStack_18 = iStack_18 + 1) {
    func_0x1030cc7f();
    uStack_48 = 0;
    uStack_24 = 0xffffffff;
    uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1088494c,&uStack_24);
    uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1088517c,&uStack_64,auStack_60,
                            auStack_5c,auStack_68,auStack_4c,auStack_4a,auStack_50,&uStack_48,
                            auStack_44,auStack_38,auStack_34,auStack_30);
    (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x30c))(auStack_68);
    (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x404))(uStack_64);
  }
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x624))();
  uVar2 = _Logf_FOutputDevice__QAAXPBGZZ
                    (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x108852c0,
                     (int)(short)uStack_1c);
  *unaff_FS_OFFSET = uStack_10;
  return uVar2 & 0xffffff00;
}

