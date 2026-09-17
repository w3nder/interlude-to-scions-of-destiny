
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_104038a0(undefined4 param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  int unaff_retaddr;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [4];
  undefined4 auStack_24 [3];
  undefined4 uStack_18;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_10755c28;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  func_0x1030218f(10);
  puStack_8 = (undefined *)0x0;
  uVar1 = func_0x10305079(*(undefined4 *)(unaff_retaddr + 0x48),param_1,&UNK_107bde54,
                          &stack0xffffffc0,&uStack_3c);
  switch(unaff_ESI) {
  case 1:
    uVar1 = func_0x10305079(*(undefined4 *)(unaff_retaddr + 0x48),uVar1,&UNK_107bde9c,&uStack_38);
    func_0x103012c1(unaff_ESI);
    func_0x103012c1(unaff_ESI);
    uStack_30 = unaff_ESI;
    break;
  case 2:
    uVar1 = func_0x10305079(*(undefined4 *)(unaff_retaddr + 0x48),uVar1,&UNK_107bde54,&uStack_34,
                            &uStack_30);
    func_0x103012c1(unaff_ESI);
    func_0x103012c1(unaff_ESI);
    func_0x103012c1(uStack_3c);
    uStack_30 = uStack_38;
    break;
  case 3:
    uVar1 = func_0x10305079(*(undefined4 *)(unaff_retaddr + 0x48),uVar1,&UNK_107bde9c,auStack_2c);
    func_0x103012c1(unaff_ESI);
    func_0x103012c1(unaff_ESI);
    uStack_30 = uStack_34;
    break;
  case 4:
    uVar1 = func_0x10305079(*(undefined4 *)(unaff_retaddr + 0x48),uVar1,&UNK_107bde9c,auStack_28);
    func_0x103012c1(unaff_ESI);
    func_0x103012c1(unaff_ESI);
    break;
  case 5:
    uVar1 = func_0x10305079(*(undefined4 *)(unaff_retaddr + 0x48),uVar1,&UNK_107bde9c,&uStack_38);
    func_0x103012c1(unaff_ESI);
    func_0x103012c1(unaff_ESI);
    uStack_30 = unaff_ESI;
    break;
  default:
    goto LAB_10403a53;
  }
  func_0x103012c1(uStack_30);
LAB_10403a53:
  func_0x10305079(*(undefined4 *)(unaff_retaddr + 0x48),uVar1,&UNK_107bde9c,auStack_24);
  func_0x103012c1(auStack_24[0]);
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x324))(auStack_24);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c2830);
  (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
            (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c2830);
  uStack_10 = 0xffffffff;
  uVar2 = func_0x10307f3b();
  *unaff_FS_OFFSET = uStack_18;
  return uVar2 & 0xffffff00;
}

