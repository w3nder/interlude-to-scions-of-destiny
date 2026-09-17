
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int packet_1042b820(int param_1)

{
  int *piVar1;
  
  if ((((-1 < param_1) && (_DAT_10b1f538 != 0)) &&
      (piVar1 = (int *)func_0x1030d04e(&param_1), piVar1 != (int *)0x0)) &&
     ((*piVar1 == 1 && (piVar1[1] != 0)))) {
    return piVar1[1];
  }
  return 0;
}

