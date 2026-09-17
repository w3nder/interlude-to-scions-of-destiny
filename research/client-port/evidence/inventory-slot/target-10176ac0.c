/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall packet_10176ac0(int *param_1,undefined4 param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *unaff_FS_OFFSET;
  int iStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;

  puStack_c = &UNK_10212b30;
  iStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_10;
  iVar3 = 0;
  uStack_8 = 0;
  func_0x1005d6f0(param_2,param_3);
  iVar2 = func_0x10176880(param_3 & 0xffff,param_3 >> 0x10);
  param_1[0x99] = iVar2;
  param_1[0x98] = iVar2;
  do {
    if (param_1[0x76] <= iVar3) {
      param_1[0x73] = -1;
LAB_10176c20:
      if (param_1[0x74] == 0) {
        param_1[0x90] = 1;
        func_0x1014ed50(3);
      }
      else {
        param_1[0x74] = 0;
      }
      func_0x1005d6f0(param_2,param_3);
      *unaff_FS_OFFSET = iStack_10;
      return;
    }
    piVar1 = (int *)(param_1[0x75] + iVar3 * 4);
    iVar2 = (**(code **)(*param_1 + 500))
                      (*(undefined4 *)(*piVar1 + 0x1e6c),*(undefined4 *)(*piVar1 + 0x1e58));
    if (iVar2 == 0x10) {
      func_0x10176850();
      if (param_1[0x98] == 5) {
        func_0x1002cc50();
        param_1[0x73] = iVar3;
        goto LAB_10176c20;
      }
    }
    else if ((iVar2 == 0xf) || (iVar2 == 0x11)) {
      func_0x10176850();
      if (param_1[0x98] == 6) {
        func_0x1002cc50();
        param_1[0x73] = iVar3;
        goto LAB_10176c20;
      }
    }
    else if (iVar2 == 0x12) {
      func_0x10176850();
      if (param_1[0x98] == 0) {
        func_0x1002cc50();
        param_1[0x73] = iVar3;
        goto LAB_10176c20;
      }
    }
    else if (param_1[0x98] == iVar2) {
      func_0x10176850();
      func_0x1002cc50();
      param_1[0x73] = iVar3;
      goto LAB_10176c20;
    }
    iVar3 = iVar3 + 1;
  } while( true );
}
