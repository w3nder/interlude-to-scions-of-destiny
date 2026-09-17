
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_1041e880(int param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 unaff_retaddr;
  undefined4 *puStack_40;
  undefined *puStack_3c;
  undefined4 *puStack_38;
  undefined4 *puStack_34;
  undefined4 auStack_28 [3];
  undefined1 auStack_1c [4];
  undefined4 uStack_18;
  undefined1 auStack_14 [4];
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_10756928;
  *unaff_FS_OFFSET = &uStack_c;
  puStack_34 = auStack_28;
  puStack_38 = &param_1;
  puStack_3c = &UNK_107bde54;
  puStack_40 = param_2;
  func_0x10305079(*(undefined4 *)(param_1 + 0x48));
  if (_DAT_109d5e68 != 0) {
    puStack_34 = &param_1;
    puStack_38 = (undefined4 *)0x1041e8db;
    iVar1 = func_0x1030f3bc();
    if (iVar1 != 0) {
      puStack_34 = &param_1;
      puStack_38 = (undefined4 *)0x1041e8eb;
      piVar2 = (int *)func_0x1030f3bc();
      if (*piVar2 == 4) {
        puStack_34 = &param_1;
        puStack_38 = (undefined4 *)0x1041e8fc;
        iVar1 = func_0x1030f3bc();
        if (*(int *)(iVar1 + 4) != 0) {
          puStack_34 = &param_1;
          puStack_38 = (undefined4 *)0x1041e90d;
          iVar1 = func_0x1030f3bc();
          if (*(int *)(iVar1 + 4) != 0) goto LAB_1041ea4c;
        }
      }
    }
  }
  puStack_34 = (undefined4 *)0xa;
  puStack_38 = (undefined4 *)0x1041e921;
  func_0x1030218f();
  puStack_8 = (undefined *)0x0;
  puStack_3c = (undefined *)0x1041e933;
  puStack_38 = (undefined4 *)unaff_retaddr;
  func_0x103012c1();
  puStack_40 = (undefined4 *)0x1041e941;
  puStack_3c = (undefined *)unaff_EDI;
  func_0x103012c1();
  puStack_40 = (undefined4 *)&stack0xffffffd0;
  iVar1 = (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x1d4))(auStack_28);
  if (iVar1 != 0) {
    puVar3 = (undefined4 *)
             (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(0x18,&UNK_10792bd0);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3[2] = 0;
      puVar3[1] = 0;
      puVar3[5] = 0;
      *puVar3 = 0xffffffff;
      puVar3[3] = 0;
      puVar3[4] = 0;
    }
    *puVar3 = 1;
    puVar3[1] = puStack_3c;
    puVar3[2] = uStack_10;
    puVar3[5] = puStack_38;
    if (_DAT_109d5e68 != 0) {
      iVar1 = func_0x1030f3bc(&uStack_10);
      if (iVar1 != 0) {
        func_0x10306203(iVar1);
        func_0x1030720c(auStack_14);
      }
      puStack_40 = (undefined4 *)
                   (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(8,&UNK_10792bd0);
      if (puStack_40 == (undefined4 *)0x0) {
        puStack_40 = (undefined4 *)0x0;
      }
      else {
        *puStack_40 = 0;
        puStack_40[1] = 0;
      }
      if (puStack_40 != (undefined4 *)0x0) {
        puStack_40[1] = puVar3;
        *puStack_40 = 4;
      }
      func_0x1030cb1c(auStack_1c,&puStack_40);
    }
  }
  uStack_18 = 0xffffffff;
  func_0x10307f3b();
LAB_1041ea4c:
  puStack_34 = (undefined4 *)auStack_28[0];
  puStack_40 = *(undefined4 **)_GNetworkLog__3PAVFOutputDevice__A_exref;
  puStack_38 = (undefined4 *)param_1;
  puStack_3c = &UNK_107c6f78;
  _Logf_FOutputDevice__QAAXPBGZZ();
  uVar4 = (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                    (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c6f78,param_1,auStack_28[0]);
  *unaff_FS_OFFSET = uStack_c;
  return uVar4 & 0xffffff00;
}

