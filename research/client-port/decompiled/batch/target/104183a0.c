
uint packet_104183a0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  short asStack_60 [2];
  short asStack_5c [2];
  short asStack_58 [2];
  short asStack_54 [2];
  short asStack_50 [2];
  short asStack_4c [2];
  short asStack_48 [2];
  undefined1 auStack_44 [4];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  int iStack_8;
  undefined1 auStack_4 [4];
  
  iVar1 = param_1;
  uVar2 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x10883d84,&uStack_28,&iStack_2c,
                          &iStack_8,auStack_4,&iStack_30);
  if (iStack_2c == 1) {
    func_0x1030e0cf(uStack_28);
  }
  iStack_34 = 0;
  if (0 < iStack_30) {
    do {
      uVar2 = func_0x103034e5(*(undefined4 *)(iVar1 + 0x48),uVar2,0x10886d54,&uStack_38,&uStack_3c,
                              &uStack_40,&param_1,asStack_60,asStack_5c);
      iVar4 = 0;
      if (0 < asStack_60[0]) {
        do {
          uVar2 = func_0x103034e5(*(undefined4 *)(iVar1 + 0x48),uVar2,0x10886d48,asStack_50,
                                  &uStack_18,asStack_54,&uStack_1c,asStack_58,&uStack_20,&uStack_24)
          ;
          func_0x1031358e(iVar4,(int)(char)param_1,uStack_38,uStack_3c,uStack_40,(int)asStack_50[0],
                          uStack_18,(int)asStack_54[0],uStack_1c,(int)asStack_58[0],uStack_20,
                          uStack_24);
          iVar4 = iVar4 + 1;
        } while (iVar4 < asStack_60[0]);
      }
      iVar4 = 0;
      if (0 < asStack_5c[0]) {
        do {
          uVar2 = func_0x103034e5(*(undefined4 *)(iVar1 + 0x48),uVar2,0x10886d40,asStack_48,
                                  auStack_44,&uStack_c,asStack_4c,&uStack_10,&uStack_14);
          func_0x10309610(uStack_38,uStack_3c,uStack_40,(int)asStack_48[0],uStack_c,
                          (int)asStack_4c[0],uStack_10,uStack_14);
          iVar4 = iVar4 + 1;
        } while (iVar4 < asStack_5c[0]);
      }
      iStack_34 = iStack_34 + 1;
    } while (iStack_34 < iStack_30);
  }
  if (iStack_8 == 1) {
    func_0x1030f6a5();
  }
  uVar3 = _Logf_FOutputDevice__QAAXPBGZZ
                    (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10886cf8);
  return uVar3 & 0xffffff00;
}

