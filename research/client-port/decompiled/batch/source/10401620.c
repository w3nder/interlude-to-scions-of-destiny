
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10401620(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined2 auStack_58 [2];
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined2 uStack_3c;
  undefined2 uStack_3a;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  iVar1 = param_1;
  puStack_c = &UNK_10755a30;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  puStack_14 = &stack0xffffff9c;
  uStack_8 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uVar2 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c16ec,&uStack_1c,
                          &uStack_18);
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x230))((int)(short)uStack_1c);
  for (param_1 = 0; param_1 < (short)uStack_18; param_1 = param_1 + 1) {
    auStack_58[0] = 0xffff;
    uStack_2c = 0xffffffff;
    uStack_20 = 0xffffffff;
    uStack_54 = 0;
    uStack_50 = 0;
    uStack_4c = 0;
    uStack_48 = 0;
    uStack_44 = 0;
    uStack_40 = 0;
    uStack_3c = 0;
    uStack_3a = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_38 = 0;
    uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107c1644,&uStack_20);
    uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107c1638,&uStack_54,&uStack_50,
                            &uStack_4c,auStack_58,&uStack_3c,&uStack_3a,&uStack_40,&uStack_38,
                            &uStack_34);
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x25c))(auStack_58);
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x328))(uStack_54);
  }
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x5f0))();
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c1fb8,
             (int)(short)uStack_18);
  uVar3 = (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                    (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c1fb8,(int)(short)uStack_18);
  *unaff_FS_OFFSET = uStack_10;
  return uVar3 & 0xffffff00;
}

