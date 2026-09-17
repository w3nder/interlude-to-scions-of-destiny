
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10401060(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  short unaff_BP;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined2 uStack_4c;
  undefined2 uStack_4a;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 auStack_30 [48];
  
  iVar1 = param_1;
  uStack_6c = 0;
  uVar2 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c1e8c,0x30,auStack_30,
                          &param_1,&uStack_68,&uStack_6c);
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x524))(uStack_68,param_1);
  iVar4 = 0;
  if (0 < unaff_BP) {
    do {
      uStack_68 = CONCAT22(uStack_68._2_2_,0xffff);
      uStack_64 = 0;
      uStack_60 = 0;
      uStack_5c = 0;
      uStack_58 = 0;
      uStack_54 = 0;
      uStack_50 = 0;
      uStack_4c = 0;
      uStack_4a = 0;
      uStack_44 = 0;
      uStack_40 = 0;
      uStack_3c = 0xffffffff;
      uStack_48 = 0;
      uStack_6c = 0xffffffff;
      uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107c1644,&uStack_6c);
      uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107c1638,&uStack_64,
                              &uStack_60,&uStack_5c,&uStack_68,&uStack_4c,&uStack_4a,&uStack_50,
                              &uStack_48,&uStack_44);
      (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x528))(&uStack_68);
      iVar4 = iVar4 + 1;
    } while (iVar4 < unaff_BP);
  }
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c1e44);
  uVar3 = (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                    (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c1e18);
  return uVar3 & 0xffffff00;
}

