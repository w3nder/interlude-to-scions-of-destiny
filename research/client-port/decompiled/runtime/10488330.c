
undefined4
packet_10488330(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    return 1;
  }
  iVar1 = *(int *)(param_1 + 0x204);
  if (iVar1 == 0) {
    return 1;
  }
  if (param_2 == 0) {
    if (*(int *)(iVar1 + 0x718) == 0) {
      return 1;
    }
    piVar2 = (int *)func_0x10313c0a(param_5,param_6,param_7);
    if (piVar2 == (int *)0x0) {
      return 1;
    }
    piVar2[0x18] = *(int *)(*(int *)(param_1 + 0x204) + 0x60);
    *(int **)(param_1 + 0x204) = piVar2;
    func_0x10314583();
    uVar3 = 1;
  }
  else {
    if (param_3 == 1) {
      if (*(int *)(iVar1 + 0x718) != 0) {
        return 1;
      }
      iVar1 = func_0x1030e06b(1,param_4,1,param_5,param_6,param_7);
      if (iVar1 == 0) {
        return 1;
      }
      *(undefined4 *)(iVar1 + 0x60) = *(undefined4 *)(*(int *)(param_1 + 0x204) + 0x60);
      *(int *)(param_1 + 0x204) = iVar1;
      func_0x10314583();
      return 1;
    }
    if (param_3 != 2) {
      return 1;
    }
    iVar1 = *(int *)(iVar1 + 0x718);
    if ((((iVar1 != 0) && ((*(byte *)(iVar1 + 0x714) & 1) != 0)) &&
        (*(char *)(iVar1 + 0x71c) == '\x01')) &&
       (iVar1 = func_0x10313c0a(param_5,param_6,param_7), iVar1 != 0)) {
      *(undefined4 *)(iVar1 + 0x60) = *(undefined4 *)(*(int *)(param_1 + 0x204) + 0x60);
      *(int *)(param_1 + 0x204) = iVar1;
      func_0x10314583();
    }
    if (*(int *)(*(int *)(param_1 + 0x204) + 0x718) != 0) {
      return 1;
    }
    piVar2 = (int *)func_0x1030e06b(2,param_4,1,param_5,param_6,param_7);
    if (piVar2 == (int *)0x0) {
      return 1;
    }
    piVar2[0x18] = *(int *)(*(int *)(param_1 + 0x204) + 0x60);
    *(int **)(param_1 + 0x204) = piVar2;
    func_0x10314583();
    uVar3 = 4;
  }
  (**(code **)(*piVar2 + 0x1c8))(uVar3,0,0,0,0x3f800000);
  return 1;
}

