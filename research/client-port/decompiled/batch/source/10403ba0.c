
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10403ba0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar3;
  undefined1 auStack_54 [24];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  int iStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  uint uStack_8;
  
  puStack_c = &UNK_10755c48;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  puStack_14 = &stack0xffffffa0;
  uStack_8 = 0;
  (**(code **)(*(int *)_DAT_109d5e68[0x15] + 800))();
  uVar1 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107bde9c,&iStack_28);
  iStack_24 = 0;
  do {
    if (iStack_28 <= iStack_24) {
      (**(code **)(*_DAT_109d5e68 + 0x300))();
      _Logf_FOutputDevice__QAAXPBGZZ
                (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c28d8);
      uVar2 = (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                        (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c28d8);
      *unaff_FS_OFFSET = uStack_10;
      return uVar2 & 0xffffff00;
    }
    func_0x1030218f(10);
    uStack_8 = CONCAT31(uStack_8._1_3_,1);
    uVar1 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),uVar1,&UNK_107bde54,&uStack_18,
                            &uStack_1c);
    switch(uStack_18) {
    case 1:
      uVar1 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),uVar1,&UNK_107bde9c,&uStack_20);
      func_0x103012c1(uStack_18);
      func_0x103012c1(uStack_1c);
      uVar3 = uStack_20;
      break;
    case 2:
      uVar1 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),uVar1,&UNK_107bde54,&uStack_2c,
                              &uStack_30);
      func_0x103012c1(uStack_18);
      func_0x103012c1(uStack_1c);
      func_0x103012c1(uStack_2c);
      uVar3 = uStack_30;
      break;
    case 3:
      uVar1 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),uVar1,&UNK_107bde9c,&uStack_34);
      func_0x103012c1(uStack_18);
      func_0x103012c1(uStack_1c);
      uVar3 = uStack_34;
      break;
    case 4:
      uVar1 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),uVar1,&UNK_107bde9c,&uStack_38);
      func_0x103012c1(uStack_18);
      func_0x103012c1(uStack_1c);
      uVar3 = uStack_38;
      break;
    case 5:
      uVar1 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),uVar1,&UNK_107bde9c,&uStack_20);
      func_0x103012c1(uStack_18);
      func_0x103012c1(uStack_1c);
      uVar3 = uStack_20;
      break;
    default:
      goto LAB_10403d72;
    }
    func_0x103012c1(uVar3);
LAB_10403d72:
    uVar1 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),uVar1,&UNK_107bde9c,&uStack_3c);
    func_0x103012c1(uStack_3c);
    (**(code **)(*(int *)_DAT_109d5e68[0x15] + 0x324))(auStack_54);
    uStack_8 = uStack_8 & 0xffffff00;
    func_0x10307f3b();
    iStack_24 = iStack_24 + 1;
  } while( true );
}

