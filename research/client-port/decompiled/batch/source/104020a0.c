
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_104020a0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined2 auStack_30 [2];
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  undefined2 uStack_12;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_38 = 0;
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x378))();
  iVar1 = param_1;
  uVar2 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c1644,&uStack_38);
  iVar4 = 0;
  if (0 < (short)uStack_38) {
    do {
      uStack_34 = 0;
      param_1 = 0;
      uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107bde54,&uStack_34,&param_1)
      ;
      (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x380))(uStack_34,param_1);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (short)uStack_38);
  }
  uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107c1644,&uStack_38);
  iVar4 = 0;
  if (0 < (short)uStack_38) {
    do {
      auStack_30[0] = 0xffff;
      uStack_4 = 0xffffffff;
      uStack_2c = 0;
      uStack_28 = 0;
      uStack_24 = 0;
      uStack_20 = 0;
      uStack_1c = 0;
      uStack_18 = 0;
      uStack_10 = 0;
      uStack_14 = 0;
      uStack_12 = 0;
      uStack_c = 0;
      uStack_8 = 0;
      uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107becec,&uStack_2c,
                              &uStack_28,&uStack_24,&uStack_18);
      (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 900))(auStack_30);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (short)uStack_38);
  }
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x37c))();
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c21a0,
             (int)(short)uStack_38);
  uVar3 = (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                    (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c2158,(int)(short)uStack_38);
  return uVar3 & 0xffffff00;
}

