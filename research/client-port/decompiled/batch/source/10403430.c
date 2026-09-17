
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10403430(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined2 uStack_1c;
  undefined2 uStack_1a;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 auStack_c [2];
  short sStack_4;
  
  iVar1 = param_1;
  uVar2 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c2780,&uStack_38,
                          &uStack_3c,&param_1);
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x17c))(uStack_38,uStack_3c);
  iVar4 = 0;
  if (0 < sStack_4) {
    do {
      uStack_38 = CONCAT22(uStack_38._2_2_,0xffff);
      auStack_c[0] = 0xffffffff;
      uStack_3c = 0xffffffff;
      uStack_34 = 0;
      uStack_30 = 0;
      uStack_2c = 0;
      uStack_28 = 0;
      uStack_24 = 0;
      uStack_20 = 0;
      uStack_18 = 0;
      uStack_1c = 0;
      uStack_1a = 0;
      uStack_14 = 0;
      uStack_10 = 0;
      uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107c1644,&uStack_3c);
      uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107c17e8,&uStack_34,
                              &uStack_30,&uStack_2c,&uStack_38,&uStack_1c,&uStack_20,&uStack_18,
                              &uStack_1a,&uStack_14,auStack_c);
      (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x180))(&uStack_38);
      iVar4 = iVar4 + 1;
    } while (iVar4 < sStack_4);
  }
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c2728);
  uVar3 = (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                    (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c2728);
  return uVar3 & 0xffffff00;
}

