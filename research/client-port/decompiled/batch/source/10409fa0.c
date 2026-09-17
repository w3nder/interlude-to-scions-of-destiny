
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10409fa0(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int aiStack_30 [2];
  undefined1 auStack_28 [20];
  undefined4 uStack_14;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_10756128;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x350))();
  iStack_40 = 0;
  iStack_3c = 0;
  iStack_38 = 0;
  iStack_34 = 0;
  aiStack_30[0] = 0;
  func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c0f44,&iStack_40,&iStack_3c,
                  &iStack_38,&iStack_34,aiStack_30);
  if (0 < iStack_40) {
    func_0x1030218f(10);
    puStack_8 = (undefined *)0x0;
    func_0x103012c1(0x10af);
    func_0x103012c1(unaff_EDI);
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x354))(&iStack_38);
    uStack_14 = 0xffffffff;
    func_0x10307f3b();
  }
  if (0 < iStack_3c) {
    func_0x1030218f(10);
    puStack_8 = (undefined *)0x1;
    func_0x103012c1(0x10ae);
    func_0x103012c1(unaff_ESI);
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x354))(&iStack_38);
    uStack_14 = 0xffffffff;
    func_0x10307f3b();
  }
  if (0 < iStack_38) {
    func_0x1030218f(10);
    puStack_8 = (undefined *)0x2;
    func_0x103012c1(0x10ad);
    func_0x103012c1(1);
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x354))(&iStack_38);
    uStack_14 = 0xffffffff;
    func_0x10307f3b();
  }
  if (0 < iStack_34) {
    func_0x1030218f(10);
    puStack_8 = (undefined *)0x3;
    func_0x103012c1(0x10ac);
    func_0x103012c1(1);
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x354))(&iStack_38);
    uStack_14 = 0xffffffff;
    func_0x10307f3b();
  }
  if (0 < aiStack_30[0]) {
    func_0x1030218f(10);
    puStack_8 = (undefined *)0x4;
    func_0x103012c1(0x10ab);
    func_0x103012c1(1);
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x354))(auStack_28);
    uStack_14 = 0xffffffff;
    func_0x10307f3b();
  }
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c3dc0);
  uVar1 = (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                    (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c3d74);
  *unaff_FS_OFFSET = uStack_c;
  return uVar1 & 0xffffff00;
}

