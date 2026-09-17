undefined4 packet_1014e550(uint param_1,int param_2)

{
  int iVar1;

  if (((param_1 & 6) != 0) && (iVar1 = func_0x1014dd00(), iVar1 != 0)) {
    if (*(int *)(iVar1 + 0x9c) == param_2) {
      return 8;
    }
    if (*(int *)(iVar1 + 0xa0) == param_2) {
      return 9;
    }
  }
  if (((param_1 & 0x30) != 0) && (iVar1 = func_0x1014dd00(), iVar1 != 0)) {
    if (*(int *)(iVar1 + 0xa8) == param_2) {
      return 0xd;
    }
    if (*(int *)(iVar1 + 0xac) == param_2) {
      return 0xe;
    }
  }
  if ((int)param_1 < 0x1001) {
    if (param_1 == 0x1000) {
      return 0xc;
    }
    if ((int)param_1 < 0x101) {
      if (param_1 == 0x100) {
        return 7;
      }
      switch(param_1) {
      case 1:
        return 3;
      case 8:
        return 4;
      case 0x40:
        return 1;
      case 0x80:
        return 5;
      }
    }
    else {
      if (param_1 == 0x200) {
        return 10;
      }
      if (param_1 == 0x400) {
        return 6;
      }
      if (param_1 == 0x800) {
        return 0xb;
      }
    }
  }
  else if ((int)param_1 < 0x10001) {
    if (param_1 == 0x10000) {
      return 0;
    }
    if (param_1 == 0x2000) {
      return 0x13;
    }
    if (param_1 == 0x4000) {
      return 0x10;
    }
    if (param_1 == 0x8000) {
      return 0xf;
    }
  }
  else {
    if (param_1 == 0x20000) {
      return 0x11;
    }
    if (param_1 == 0x40000) {
      return 2;
    }
    if (param_1 == 0x80000) {
      return 0x12;
    }
  }
  return 0xffffffff;
}
