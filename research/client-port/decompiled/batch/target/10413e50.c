
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10413e50(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uStack_48;
  undefined4 uStack_44;
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
  undefined4 uStack_c;
  short sStack_4;
  
  iVar1 = param_1;
  uVar2 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x10885d20,&uStack_44,&uStack_48,
                          &param_1);
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x23c))(uStack_44,uStack_48);
  iVar4 = 0;
  if (0 < sStack_4) {
    do {
      uStack_44 = CONCAT22(uStack_44._2_2_,0xffff);
      uStack_40 = 0;
      uStack_3c = 0;
      uStack_38 = 0;
      uStack_34 = 0;
      uStack_30 = 0;
      uStack_2c = 0;
      uStack_24 = 0;
      uStack_28 = 0;
      uStack_26 = 0;
      uStack_20 = 0;
      uStack_1c = 0;
      uStack_18 = 0xffffffff;
      uStack_14 = 0;
      uStack_10 = 0;
      uStack_c = 0xffffffff;
      uStack_48 = 0xffffffff;
      uVar2 = func_0x103034e5(*(undefined4 *)(iVar1 + 0x48),uVar2,0x1088494c,&uStack_48);
      uVar2 = func_0x103034e5(*(undefined4 *)(iVar1 + 0x48),uVar2,0x10885d10,&uStack_40,&uStack_3c,
                              &uStack_38,&uStack_44,&uStack_28,&uStack_2c,&uStack_24,&uStack_26,
                              &uStack_20,&uStack_18,&uStack_14,&uStack_10);
      (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x240))(&uStack_44);
      iVar4 = iVar4 + 1;
    } while (iVar4 < sStack_4);
  }
  uVar3 = _Logf_FOutputDevice__QAAXPBGZZ
                    (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10885cb8);
  return uVar3 & 0xffffff00;
}

