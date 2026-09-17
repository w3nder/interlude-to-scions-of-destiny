
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10411260(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  short unaff_BP;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 auStack_74 [2];
  undefined1 auStack_6c [40];
  undefined2 auStack_44 [2];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 auStack_c [3];
  
  uStack_7c = 0;
  uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x1088518c,0x30,auStack_6c,
                          &uStack_78,auStack_74,&uStack_7c);
  (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x4f0))(auStack_74[0],uStack_78);
  iVar3 = 0;
  if (0 < unaff_BP) {
    do {
      auStack_44[0] = 0xffff;
      uStack_40 = 0;
      uStack_3c = 0;
      uStack_38 = 0;
      uStack_34 = 0;
      uStack_30 = 0;
      uStack_2c = 0;
      uStack_28 = 0;
      uStack_26 = 0;
      uStack_20 = 0;
      uStack_1c = 0;
      uStack_18 = 0xffffffff;
      uStack_14 = 0;
      uStack_10 = 0;
      auStack_c[0] = 0xffffffff;
      uStack_24 = 0;
      uStack_78 = 0xffffffff;
      uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1088494c,&uStack_78);
      uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1088517c,&uStack_40,&uStack_3c
                              ,&uStack_38,auStack_44,&uStack_28,&uStack_26,&uStack_2c,&uStack_24,
                              &uStack_20,&uStack_14,&uStack_10,auStack_c);
      (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x540))(auStack_44);
      iVar3 = iVar3 + 1;
    } while (iVar3 < unaff_BP);
  }
  uVar2 = _Logf_FOutputDevice__QAAXPBGZZ
                    (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10885134);
  return uVar2 & 0xffffff00;
}

