/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall packet_10176880(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;

  iVar6 = 0;
  uVar2 = _DAT_102897f8;
  do {
    iVar4 = param_1[0x20];
    iVar1 = param_1[0x21];
    iVar3 = iVar4 + 7;
    iVar5 = iVar1 + 7;
    switch(iVar6) {
    case 0:
      break;
    case 1:
      iVar3 = iVar4 + 0x2e;
      break;
    case 2:
      iVar3 = iVar4 + 0x55;
      break;
    case 3:
      iVar3 = iVar4 + 0x82;
      break;
    case 4:
      iVar3 = iVar4 + 0xa9;
      break;
    case 5:
      goto code_r0x101768d0;
    case 6:
      iVar3 = iVar4 + 0x2e;
code_r0x101768d0:
      iVar5 = iVar1 + 0x2d;
      break;
    case 7:
      iVar3 = iVar4 + 0x55;
      iVar5 = iVar1 + 0x2d;
      break;
    case 8:
      iVar3 = iVar4 + 0x82;
      iVar5 = iVar1 + 0x2d;
      break;
    case 9:
      iVar3 = iVar4 + 0xa9;
      iVar5 = iVar1 + 0x2d;
      break;
    case 10:
      goto code_r0x10176903;
    case 0xb:
      iVar3 = iVar4 + 0x2e;
      goto code_r0x10176903;
    case 0xc:
      iVar3 = iVar4 + 0x55;
      goto code_r0x10176903;
    case 0xd:
      iVar3 = iVar4 + 0x82;
      goto code_r0x10176903;
    case 0xe:
      iVar3 = iVar4 + 0xa9;
code_r0x10176903:
      iVar5 = iVar1 + 0x53;
      break;
    default:
      goto LAB_10176942;
    }
    iVar4 = (**(code **)(*param_1 + 0x104))(param_2,param_3,iVar3,iVar5,uVar2,uVar2);
    uVar2 = _DAT_102897f8;
    if (iVar4 != 0) {
      return iVar6;
    }
LAB_10176942:
    iVar6 = iVar6 + 1;
    if (0x13 < iVar6) {
      return -1;
    }
  } while( true );
}
