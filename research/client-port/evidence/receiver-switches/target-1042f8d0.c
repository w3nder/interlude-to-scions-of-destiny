
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_1042f8d0(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  float fVar5;
  undefined4 uVar6;
  int *piStack_b4;
  int iStack_a4;
  int iStack_a0;
  int iStack_9c;
  undefined4 uStack_98;
  int iStack_94;
  int iStack_90;
  int iStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  undefined4 uStack_74;
  undefined8 uStack_70;
  double dStack_68;
  undefined8 uStack_60;
  double dStack_58;
  short asStack_50 [2];
  short asStack_4c [2];
  undefined1 auStack_48 [12];
  undefined4 uStack_3c;
  undefined4 uStack_20;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;

  uStack_14 = *unaff_FS_OFFSET;
  uStack_c = 0xffffffff;
  uStack_10 = 0x1081013e;
  *unaff_FS_OFFSET = &uStack_14;
  piStack_b4 = &iStack_90;
  func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x1088a894,&iStack_a4,&uStack_98,0x30,
                  auStack_48,&iStack_94,&uStack_84,&uStack_88,&iStack_8c,(int)&uStack_70 + 4,
                  &dStack_68,&dStack_58,asStack_50,&uStack_60,&fStack_80,&fStack_7c,&iStack_9c);
  if (_DAT_10b1f538 != 0) {
    piStack_b4 = &iStack_a4;
    iVar1 = func_0x1030d04e();
    if (iVar1 != 0) {
      piStack_b4 = &iStack_a4;
      piVar2 = (int *)func_0x1030d04e();
      if (*piVar2 == 1) {
        piStack_b4 = &iStack_a4;
        iVar1 = func_0x1030d04e();
        if (*(int *)(iVar1 + 4) != 0) {
          piStack_b4 = &iStack_a4;
          iVar1 = func_0x1030d04e();
          if (*(int *)(iVar1 + 4) != 0) {
            piStack_b4 = &iStack_a4;
            iVar1 = func_0x1030d04e();
            if (((iVar1 == 0) || (piVar2 = (int *)func_0x1030d04e(&stack0xffffff58), *piVar2 != 1))
               || (iVar1 = func_0x1030d04e(&stack0xffffff58), *(int *)(iVar1 + 4) == 0)) {
              iVar1 = 0;
            }
            else {
              iVar1 = func_0x1030d04e(&stack0xffffff58);
              iVar1 = *(int *)(iVar1 + 4);
            }
            *(undefined4 *)(iVar1 + 8) = 1;
            *(undefined4 *)(iVar1 + 0x94) = 0;
            *(int *)(iVar1 + 0x14) = iStack_9c + -1000000;
            if (asStack_4c[0] == 0) {
              iVar3 = func_0x10307a77((int *)(iVar1 + 0x14));
              if (iVar3 != 0) {
                uVar6 = __DFString__QBEPBGXZ();
                func_0x103072f7(uVar6);
                *(undefined4 *)(iVar1 + 400) = *(undefined4 *)(iVar3 + 0x1c);
              }
            }
            else {
              func_0x103072f7(asStack_4c);
            }
            *(int *)(iVar1 + 0x10) = iStack_9c;
            *(undefined8 *)(iVar1 + 0x1c4) = uStack_70;
            *(undefined8 *)(iVar1 + 0x1bc) = uStack_60;
            *(float *)(iVar1 + 0x1cc) = (float)dStack_58;
            *(float *)(iVar1 + 0x1d0) = (float)dStack_68;
            *(undefined4 *)(iVar1 + 0x7c) = uStack_88;
            *(undefined4 *)(iVar1 + 0x80) = uStack_84;
            if (*(int *)(iVar1 + 0x204) != 0) {
              *(float *)(*(int *)(iVar1 + 0x204) + 0x6b0) = (float)*(double *)(iVar1 + 0x1bc);
              *(float *)(*(int *)(iVar1 + 0x204) + 0x6b4) = (float)*(double *)(iVar1 + 0x1c4);
              iVar3 = *(int *)(iVar1 + 0x204);
              if (*(char *)(*(int *)(iVar3 + 0x14d8) + 0x434) == '\x01') {
                fVar5 = *(float *)(iVar3 + 0x6ec);
              }
              else {
                fVar5 = *(float *)(iVar3 + 0x6f0);
              }
              *(float *)(iVar3 + 0x1550) = fVar5 * *(float *)(iVar3 + 0x6b4);
              if (iStack_a4 == 3) {
                switch(uStack_98) {
                case 0:
                  uVar6 = 3;
                  break;
                case 1:
                  uVar6 = 1;
                  break;
                case 2:
                  uVar6 = 2;
                  break;
                case 3:
                  uVar6 = 0;
                  break;
                default:
                  goto LAB_1042fb3e;
                }
                func_0x1030a646(uVar6);
              }
            }
LAB_1042fb3e:
            piVar2 = *(int **)(_DAT_10b1f538 + 0x54);
            uVar6 = 0;
            goto LAB_1042fce5;
          }
        }
      }
    }
  }
  piStack_b4 = (int *)0x1088a868;
  iVar1 = (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(0x314);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = func_0x10313449();
  }
  piVar2 = (int *)(iVar1 + 0x18);
  *piVar2 = unaff_ESI;
  *(undefined4 *)(iVar1 + 8) = 1;
  *(undefined4 *)(iVar1 + 0x94) = 0;
  *(int *)(iVar1 + 0x14) = iStack_a0 + -1000000;
  if (asStack_50[0] == 0) {
    iVar3 = func_0x10307a77((int *)(iVar1 + 0x14));
    if (iVar3 != 0) {
      uVar6 = __DFString__QBEPBGXZ();
      func_0x103072f7(uVar6);
      *(undefined4 *)(iVar1 + 400) = *(undefined4 *)(iVar3 + 0x1c);
    }
  }
  else {
    func_0x103072f7(asStack_50);
  }
  *(int *)(iVar1 + 0x10) = iStack_9c;
  *(undefined8 *)(iVar1 + 0x1c4) = uStack_70;
  *(undefined8 *)(iVar1 + 0x1bc) = uStack_60;
  *(float *)(iVar1 + 0x1cc) = (float)dStack_58;
  *(float *)(iVar1 + 0x1d0) = (float)dStack_68;
  *(undefined4 *)(iVar1 + 0x7c) = uStack_88;
  *(undefined4 *)(iVar1 + 0x80) = uStack_84;
  if ((0 < *piVar2) && (_DAT_10b1f538 != 0)) {
    iVar3 = func_0x1030d04e(piVar2);
    if (iVar3 != 0) {
      func_0x10314fc4(iVar3);
      func_0x10304a34(piVar2);
    }
    piStack_b4 = (int *)(**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(8,0x10853a28);
    if (piStack_b4 == (int *)0x0) {
      piStack_b4 = (int *)0x0;
    }
    else {
      *piStack_b4 = 0;
      piStack_b4[1] = 0;
    }
    uStack_20 = 0xffffffff;
    if (piStack_b4 != (int *)0x0) {
      piStack_b4[1] = iVar1;
      *piStack_b4 = 1;
    }
    func_0x1030a60f(piVar2,&piStack_b4);
  }
  fStack_80 = (float)iStack_8c;
  uVar6 = 1;
  fStack_7c = (float)iStack_90;
  fStack_78 = (float)iStack_94;
  *(undefined4 *)(iVar1 + 0x204) = 0;
  piVar2 = *(int **)(_DAT_10b1f538 + 0x54);
LAB_1042fce5:
  fVar5 = fStack_78;
  (**(code **)(*piVar2 + 0x25c))
            (iVar1,fStack_80,fStack_7c,fStack_78,uStack_74,iStack_a4,uStack_98,uVar6);
  uVar4 = _Logf_FOutputDevice__QAAXPBGZZ
                    (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x1088a798,fVar5,
                     uStack_98,uVar6,unaff_ESI,unaff_EDI,piStack_b4);
  *unaff_FS_OFFSET = uStack_3c;
  return uVar4 & 0xffffff00;
}
