
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10404cd0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined1 *puVar5;
  undefined1 auStack_450 [1024];
  undefined1 auStack_50 [20];
  undefined4 uStack_3c;
  undefined1 auStack_38 [16];
  undefined1 *puStack_28;
  int aiStack_24 [2];
  undefined1 *puStack_1c;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  uint uStack_8;

  iVar1 = param_1;
  puStack_c = &UNK_10755d50;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  puStack_14 = &stack0xfffffba4;
  iVar4 = 0;
  uStack_8 = 0;
  uVar2 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107bde9c,&param_1);
  uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107bde9c,aiStack_24);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c2d00,param_1);
  (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
            (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c2d00,param_1);
  do {
    if (aiStack_24[0] <= iVar4) {
      func_0x1030218f(10);
      uStack_8._0_1_ = 2;
      func_0x103012c1(param_1);
      (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x3b8))(auStack_50);
      uStack_8 = (uint)uStack_8._1_3_ << 8;
      uVar3 = func_0x10307f3b();
      *unaff_FS_OFFSET = uStack_10;
      return uVar3 & 0xffffff00;
    }
    func_0x1030218f(10);
    uStack_8 = CONCAT31(uStack_8._1_3_,1);
    uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107bde9c,&uStack_18);
    func_0x103012c1(uStack_18);
    switch(uStack_18) {
    case 0:
      uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107c14b4,0x400,auStack_450);
      puVar5 = auStack_450;
      break;
    case 1:
    case 2:
    case 3:
    case 5:
      uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107bde9c,&puStack_28);
      puVar5 = puStack_28;
      break;
    case 4:
      uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107bde54,&uStack_3c,
                              &puStack_1c);
      func_0x103012c1(uStack_3c);
      puVar5 = puStack_1c;
      break;
    default:
      goto LAB_10404e29;
    }
    func_0x103012c1(puVar5);
LAB_10404e29:
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x3b4))(auStack_38);
    uStack_8 = uStack_8 & 0xffffff00;
    func_0x10307f3b();
    iVar4 = iVar4 + 1;
  } while( true );
}
