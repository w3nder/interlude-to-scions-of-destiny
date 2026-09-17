
/* WARNING: Removing unreachable block (ram,0x10401304) */
/* WARNING: Removing unreachable block (ram,0x10401309) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10401220(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  short unaff_retaddr;
  int iStack_6c;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined2 uStack_48;
  undefined2 uStack_46;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 auStack_38 [2];
  undefined1 auStack_30 [48];
  
  iVar1 = param_1;
  uVar2 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c1f04,0x30,auStack_30,
                          &uStack_64,&param_1);
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x52c))(uStack_64);
  iStack_6c = 0;
  if (0 < unaff_retaddr) {
    do {
      uStack_64 = CONCAT22(uStack_64._2_2_,0xffff);
      uStack_60 = 0;
      uStack_5c = 0;
      uStack_58 = 0;
      uStack_54 = 0;
      uStack_50 = 0;
      uStack_4c = 0;
      uStack_44 = 0;
      uStack_48 = 0;
      uStack_46 = 0;
      uStack_40 = 0;
      uStack_3c = 0;
      auStack_38[0] = 0xffffffff;
      uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107c1644,&stack0xffffff90);
      uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107c18a4,&uStack_60,
                              &uStack_5c,&uStack_58,&uStack_64,&uStack_48);
      uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107bde9c,auStack_38);
      (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x530))(&uStack_64);
      iStack_6c = iStack_6c + 1;
    } while (iStack_6c < unaff_retaddr);
  }
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c1e98);
  uVar3 = (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                    (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c1e98);
  return uVar3 & 0xffffff00;
}

