undefined4 packet_10093d50(uint param_1,int param_2)

{
  int iVar1;

  if ((param_1 & 6) != 0) {
    iVar1 = func_0x10073f30();
    if (iVar1 != 0) {
      if (*(int *)(iVar1 + 0x98) == param_2) {
        return 8;
      }
      if (*(int *)(iVar1 + 0x9c) == param_2) {
        return 9;
      }
    }
  }
  if ((param_1 & 0x30) != 0) {
    iVar1 = func_0x10073f30();
    if (iVar1 != 0) {
      if (*(int *)(iVar1 + 0xa4) == param_2) {
        return 0xd;
      }
      if (*(int *)(iVar1 + 0xa8) == param_2) {
        return 0xe;
      }
    }
  }
  if ((int)param_1 < 0x801) {
    if (param_1 == 0x800) {
      return 0xb;
    }
    if ((int)param_1 < 0x81) {
      if (param_1 == 0x80) {
        return 5;
      }
      if (param_1 == 1) {
        return 0;
      }
      if (param_1 == 8) {
        return 4;
      }
      if (param_1 == 0x40) {
        return 1;
      }
    }
    else {
      if (param_1 == 0x100) {
        return 7;
      }
      if (param_1 == 0x200) {
        return 10;
      }
      if (param_1 == 0x400) {
        return 6;
      }
    }
  }
  else if ((int)param_1 < 0x8001) {
    if (param_1 == 0x8000) {
      return 0xf;
    }
    if (param_1 == 0x1000) {
      return 0xc;
    }
    if (param_1 == 0x2000) {
      return 2;
    }
    if (param_1 == 0x4000) {
      return 0x10;
    }
  }
  else {
    if (param_1 == 0x10000) {
      return 3;
    }
    if (param_1 == 0x20000) {
      return 0x11;
    }
  }
  return 0xffffffff;
}
