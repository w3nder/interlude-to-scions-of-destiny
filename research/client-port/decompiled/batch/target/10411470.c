
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10411470(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  short unaff_BX;
  undefined4 uStack_7c;
  int iStack_78;
  undefined4 uStack_70;
  undefined1 auStack_6c [44];
  undefined2 auStack_40 [2];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x1088520c,0x30,auStack_6c,
                          &uStack_70,&uStack_7c);
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x544))(uStack_70);
  iStack_78 = 0;
  if (0 < unaff_BX) {
    do {
      auStack_40[0] = 0xffff;
      uStack_3c = 0;
      uStack_38 = 0;
      uStack_34 = 0;
      uStack_30 = 0;
      uStack_2c = 0;
      uStack_28 = 0;
      uStack_20 = 0;
      uStack_24 = 0;
      uStack_22 = 0;
      uStack_1c = 0;
      uStack_18 = 0;
      uStack_14 = 0xffffffff;
      uStack_10 = 0;
      uStack_c = 0;
      uStack_8 = 0xffffffff;
      uStack_7c = 0xffffffff;
      uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1088494c,&uStack_7c);
      uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x10884bac,&uStack_3c,&uStack_38
                              ,&uStack_34,auStack_40,&uStack_24);
      if ((ushort)uStack_7c < 4) {
        uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x10885204,&uStack_28,
                                &uStack_20,&uStack_22,&uStack_1c,&uStack_10,&uStack_c);
      }
      uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1087ff8c,&uStack_14);
      (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x548))(auStack_40);
      iStack_78 = iStack_78 + 1;
    } while (iStack_78 < unaff_BX);
  }
  uVar2 = _Logf_FOutputDevice__QAAXPBGZZ
                    (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10885198);
  return uVar2 & 0xffffff00;
}

