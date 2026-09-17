
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10407960(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  short asStack_44 [2];
  short asStack_40 [2];
  short asStack_3c [2];
  short asStack_38 [2];
  short asStack_34 [2];
  short asStack_30 [2];
  short asStack_2c [2];
  undefined1 auStack_28 [4];
  undefined4 uStack_24;
  int iStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  int iStack_8;
  undefined1 auStack_4 [4];
  
  iVar1 = param_1;
  uVar2 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c0f44,&uStack_18,
                          &iStack_1c,&iStack_8,auStack_4,&iStack_20);
  if (iStack_1c == 1) {
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x5d8))(uStack_18);
  }
  iVar4 = 0;
  if (0 < iStack_20) {
    do {
      uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107c3690,&uStack_24,&param_1,
                              asStack_44,asStack_40);
      iVar5 = 0;
      if (0 < asStack_44[0]) {
        do {
          uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107c3688,asStack_34,
                                  &uStack_10,asStack_38,&uStack_14,asStack_3c);
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x5dc))
                    (iVar5,(int)(char)param_1,uStack_24,(int)asStack_34[0],uStack_10,
                     (int)asStack_38[0],uStack_14,(int)asStack_3c[0]);
          iVar5 = iVar5 + 1;
        } while (iVar5 < asStack_44[0]);
      }
      iVar5 = 0;
      if (0 < asStack_40[0]) {
        do {
          uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107c3680,asStack_2c,
                                  auStack_28,&uStack_c,asStack_30);
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x5e0))
                    (uStack_24,(int)asStack_2c[0],uStack_c,(int)asStack_30[0]);
          iVar5 = iVar5 + 1;
        } while (iVar5 < asStack_40[0]);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iStack_20);
  }
  if (iStack_8 == 1) {
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x5e4))();
  }
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c3638);
  uVar3 = (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                    (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c3638);
  return uVar3 & 0xffffff00;
}

