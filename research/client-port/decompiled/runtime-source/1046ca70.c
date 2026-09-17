
undefined4 packet_1046ca70(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  
  if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x158), iVar1 != 0)) {
    if (param_2 == 0) {
      if (*(int *)(iVar1 + 0x660) != 0) {
        piVar2 = (int *)func_0x10310979();
        if (piVar2 != (int *)0x0) {
          piVar2[0x18] = *(int *)(*(int *)(param_1 + 0x158) + 0x60);
          *(int **)(param_1 + 0x158) = piVar2;
          func_0x10304d9a();
          (**(code **)(*piVar2 + 0x1c0))(1,0,0,0,0x3f800000);
        }
      }
    }
    else if (param_3 == 1) {
      if (*(int *)(iVar1 + 0x660) == 0) {
        iVar1 = func_0x103020ea(1,param_4,1);
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0x60) = *(undefined4 *)(*(int *)(param_1 + 0x158) + 0x60);
          *(int *)(param_1 + 0x158) = iVar1;
          func_0x10304d9a();
          return 1;
        }
      }
    }
    else if (param_3 == 2) {
      iVar1 = *(int *)(iVar1 + 0x660);
      if (((iVar1 != 0) && ((*(byte *)(iVar1 + 0x65c) & 1) != 0)) &&
         (*(char *)(iVar1 + 0x664) == '\x01')) {
        iVar1 = func_0x10310979();
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0x60) = *(undefined4 *)(*(int *)(param_1 + 0x158) + 0x60);
          *(int *)(param_1 + 0x158) = iVar1;
          func_0x10304d9a();
        }
      }
      if (*(int *)(*(int *)(param_1 + 0x158) + 0x660) == 0) {
        piVar2 = (int *)func_0x103020ea(2,param_4,1);
        if (piVar2 != (int *)0x0) {
          piVar2[0x18] = *(int *)(*(int *)(param_1 + 0x158) + 0x60);
          *(int **)(param_1 + 0x158) = piVar2;
          func_0x10304d9a();
          (**(code **)(*piVar2 + 0x1c0))(4,0,0,0,0x3f800000);
          return 1;
        }
      }
    }
  }
  return 1;
}

