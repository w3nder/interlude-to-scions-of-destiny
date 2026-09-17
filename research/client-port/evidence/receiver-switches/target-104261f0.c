
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_104261f0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  code *pcVar6;
  int iStack_c;
  undefined1 auStack_8 [4];
  undefined4 uStack_4;

  iVar1 = param_1;
  uVar2 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x1087ff44,auStack_8,&iStack_c);
  if ((((_DAT_10b1f538 != 0) && (iVar3 = func_0x1030d04e(auStack_8), iVar3 != 0)) &&
      (piVar4 = (int *)func_0x1030d04e(auStack_8), *piVar4 == 1)) &&
     (iVar3 = func_0x1030d04e(auStack_8), *(int *)(iVar3 + 4) != 0)) {
    iVar3 = func_0x1030d04e(auStack_8);
    iVar3 = *(int *)(iVar3 + 4);
    if (iVar3 != 0) {
      while (0 < iStack_c) {
        iStack_c = iStack_c + -1;
        uVar2 = func_0x103034e5(*(undefined4 *)(iVar1 + 0x48),uVar2,0x1087ff44,&uStack_4,&param_1);
        switch(uStack_4) {
        case 0:
          (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x178))(iVar3,param_1);
          goto LAB_10426523;
        case 1:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x17c);
          break;
        default:
          goto LAB_10426523;
        case 3:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x184);
          break;
        case 4:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x188);
          break;
        case 5:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x18c);
          break;
        case 6:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 400);
          break;
        case 7:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x194);
          break;
        case 8:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x198);
          break;
        case 9:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x19c);
          break;
        case 10:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x1a0);
          break;
        case 0xb:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x1ac);
          break;
        case 0xc:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x1b0);
          break;
        case 0xd:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x1b4);
          break;
        case 0xe:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x1b8);
          break;
        case 0xf:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x1bc);
          break;
        case 0x10:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x1c0);
          break;
        case 0x11:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x1c4);
          break;
        case 0x12:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x1c8);
          break;
        case 0x13:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x1cc);
          break;
        case 0x14:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x1d0);
          break;
        case 0x15:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x1d4);
          break;
        case 0x16:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x1d8);
          break;
        case 0x17:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x1dc);
          break;
        case 0x18:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x1e0);
          break;
        case 0x19:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x1e4);
          break;
        case 0x1a:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x1e8);
          break;
        case 0x1b:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x1ec);
          break;
        case 0x21:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x1a4);
          break;
        case 0x22:
          pcVar6 = *(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x1a8);
        }
        (*pcVar6)(iVar3,param_1);
LAB_10426523:
      }
      iStack_c = iStack_c + -1;
    }
  }
  uVar5 = _Logf_FOutputDevice__QAAXPBGZZ
                    (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10889130,iStack_c);
  return uVar5 & 0xffffff00;
}
