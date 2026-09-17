
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 packet_104366f0(void)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  short sVar5;
  int iVar6;
  undefined4 uVar7;
  short *psVar8;
  int *piVar9;
  float *pfVar10;
  uint uVar11;
  int iVar12;
  int *piVar13;
  undefined3 unaff_EBX;
  short sVar14;
  int iVar15;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 unaff_retaddr;
  float fVar16;
  char cVar17;
  undefined4 uStack_128;
  undefined4 *puStack_124;
  short sStack_110;
  undefined4 uStack_10c;
  int iStack_108;
  undefined4 uStack_104;
  uint uStack_100;
  uint uStack_fc;
  int iStack_f8;
  undefined4 uStack_f4;
  int iStack_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float fStack_e0;
  undefined4 uStack_dc;
  int iStack_d8;
  int iStack_d4;
  undefined4 uStack_d0;
  int iStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  int iStack_c0;
  int aiStack_bc [5];
  int iStack_a8;
  int iStack_a4;
  undefined4 uStack_a0;
  float fStack_9c;
  undefined1 auStack_98 [4];
  int iStack_94;
  undefined4 uStack_90;
  float fStack_8c;
  float fStack_88;
  uint *puStack_84;
  int iStack_80;
  int iStack_7c;
  undefined1 auStack_78 [4];
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  double dStack_68;
  double dStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined1 auStack_48 [4];
  short asStack_44 [20];
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  int iStack_4;
  
  iStack_4 = -1;
  uStack_8 = 0x1081091f;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iStack_c0 = 0;
  puStack_124 = (undefined4 *)0x1088b0e4;
  uStack_128 = (undefined4 *)0x314;
  iVar6 = (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)();
  if (iVar6 == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = func_0x10313449();
  }
  func_0x107a6860(iVar6,0,0x314);
  iVar12 = iStack_4;
  iStack_cc = 0;
  uStack_c4 = 0;
  uStack_d0 = 0;
  aiStack_bc[2] = 0;
  aiStack_bc[0] = 0;
  uStack_10c = 0;
  iStack_108 = 0;
  piVar1 = (int *)(iVar6 + 0x18);
  uVar7 = func_0x103034e5(*(undefined4 *)(iStack_4 + 0x48),unaff_retaddr,0x10852190,&iStack_d8,
                          &iStack_d4,&iStack_c0,&uStack_100,piVar1,0x30,asStack_44,iVar6 + 0x4c,
                          iVar6 + 0x50,iVar6 + 0x54,iVar6 + 0x98,iVar6 + 0xb0,iVar6 + 0xb4,
                          iVar6 + 0xb8,iVar6 + 0xbc,iVar6 + 0xc0,iVar6 + 0xc4,iVar6 + 200,
                          iVar6 + 0xcc,iVar6 + 0xd0,iVar6 + 0xdc,iVar6 + 0xe0,iVar6 + 0xe8,
                          iVar6 + 0xec,iVar6 + 0x118,iVar6 + 0x11c,iVar6 + 0x120,iVar6 + 0x124,
                          iVar6 + 0x128,iVar6 + 300,iVar6 + 0x130,iVar6 + 0x134,iVar6 + 0x138,
                          iVar6 + 0x13c,iVar6 + 0x140,iVar6 + 0x144,iVar6 + 0x148,iVar6 + 0x14c,
                          iVar6 + 0x150,iVar6 + 0x154,iVar6 + 0x158,iVar6 + 0x15c,iVar6 + 0x170,
                          iVar6 + 0x174,iVar6 + 0x178,iVar6 + 0x17c,iVar6 + 0x194,iVar6 + 0x198,
                          iVar6 + 0x23c,iVar6 + 0x2ac,auStack_98,auStack_48,iVar6 + 0x19c,
                          iVar6 + 0x1a0,iVar6 + 0x1a4,iVar6 + 0x1a8,iVar6 + 0x1b4,iVar6 + 0x1b8,
                          iVar6 + 0x1ac,iVar6 + 0x1b0,&uStack_58,&uStack_50,&dStack_68,&dStack_60,
                          iVar6 + 0x240,iVar6 + 0x244,iVar6 + 0x248,0x30,iVar6 + 0x254,iVar6 + 0x284
                          ,iVar6 + 0x288,iVar6 + 0x28c,iVar6 + 0x290,auStack_98,aiStack_bc,
                          aiStack_bc + 2,&uStack_d0,&uStack_c4,&iStack_cc,&stack0xfffffeef,
                          iVar6 + 0x2b0,&uStack_10c);
  sVar5 = (short)uStack_10c;
  if (0 < sVar5) {
    iStack_108 = (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)
                           ((uint)((ulonglong)(uint)(int)sVar5 * 2) |
                            -(uint)((int)((ulonglong)(uint)(int)sVar5 * 2 >> 0x20) != 0),0x10853a28)
    ;
    sVar5 = (short)uStack_10c;
  }
  sVar14 = 0;
  if (0 < sVar5) {
    do {
      uVar7 = func_0x103034e5(*(undefined4 *)(iVar12 + 0x48),uVar7,0x1088494c,
                              iStack_108 + sVar14 * 2);
      sVar14 = sVar14 + 1;
    } while (sVar14 < (short)uStack_10c);
  }
  uVar7 = func_0x103034e5(*(undefined4 *)(iVar12 + 0x48),uVar7,0x1087f9dc,iVar6 + 700);
  uStack_dc = 0;
  aiStack_bc[3] = 0;
  uStack_90 = 0;
  if (0x1a4 < _DAT_10a56e8c) {
    uVar7 = func_0x103034e5(*(undefined4 *)(iVar12 + 0x48),uVar7,0x1088b074,&uStack_dc,
                            &stack0xfffffeee,iVar6 + 0x2e2,aiStack_bc + 3);
  }
  uVar7 = func_0x103034e5(*(undefined4 *)(iVar12 + 0x48),uVar7,0x10887ec4,iVar6 + 0x2c0,&uStack_90,
                          (int)&uStack_104 + 3);
  uVar7 = func_0x103034e5(*(undefined4 *)(iVar12 + 0x48),uVar7,0x1087f9dc,iVar6 + 0x2ec);
  uVar7 = func_0x103034e5(*(undefined4 *)(iVar12 + 0x48),uVar7,0x1088ae2c,iVar6 + 0x2a0,
                          iVar6 + 0x2f8,iVar6 + 0x2fc);
  aiStack_bc[1] = 0;
  uVar7 = func_0x103034e5(*(undefined4 *)(iVar12 + 0x48),uVar7,0x1087fa3c,aiStack_bc + 1,&iStack_94,
                          &iStack_7c,&iStack_80);
  fStack_ec = (float)iStack_94;
  puVar2 = (uint *)(iVar6 + 0x308);
  fStack_9c = (float)iStack_7c;
  puVar4 = (uint *)(float)iStack_80;
  fStack_8c = fStack_ec;
  fStack_88 = fStack_9c;
  puStack_84 = puVar4;
  uVar7 = func_0x103034e5(*(undefined4 *)(iVar12 + 0x48),uVar7,0x1087ff8c,puVar2);
  *puVar2 = ((*(byte *)puVar2 | 0xffffff00) << 8 | (uint)*(byte *)(iVar6 + 0x309)) << 8 |
            (uint)*(byte *)(iVar6 + 0x30a);
  uVar7 = func_0x103034e5(*(undefined4 *)(iVar12 + 0x48),uVar7,0x1087ff8c,&uStack_c8);
  uVar7 = func_0x103034e5(*(undefined4 *)(iVar12 + 0x48),uVar7,0x1087ff44,iVar6 + 0x30c,
                          iVar6 + 0x310);
  puVar2 = (uint *)(iVar6 + 400);
  uVar7 = func_0x103034e5(*(undefined4 *)(iVar12 + 0x48),uVar7,0x1087ff8c,puVar2);
  *puVar2 = ((*(byte *)puVar2 | 0xffffff00) << 8 | (uint)*(byte *)(iVar6 + 0x191)) << 8 |
            (uint)*(byte *)(iVar6 + 0x192);
  uVar7 = func_0x103034e5(*(undefined4 *)(iVar12 + 0x48),uVar7,0x1087ff8c,(int *)(iVar6 + 0x304));
  func_0x103034e5(*(undefined4 *)(iVar12 + 0x48),uVar7,0x1087ff8c,auStack_78);
  iVar15 = *(int *)(iVar6 + 0x304);
  if ((iVar15 < 1) || (0x13 < iVar15)) {
    uVar7 = 0;
  }
  else {
    uVar7 = 1;
  }
  *(undefined4 *)(iVar6 + 0x300) = uVar7;
  if (*(int *)(iVar6 + 0x23c) * 0x569 + -0xc0f52 == *(int *)(iVar6 + 0x2ac)) {
    iVar6 = *(int *)(iVar12 + 0x48);
    if (*(int *)(iVar6 + 0x38) != 0) {
      closesocket(*(int *)(iVar6 + 0x38));
      DeleteCriticalSection(iVar6 + 0x4efc);
    }
    *(undefined4 *)(iVar6 + 0x38) = 0;
    if (*(int *)(iVar6 + 0x495c) != 0) {
      *(undefined4 *)(iVar6 + 0x495c) = 0;
      _DAT_10b1f53c = 0;
    }
    (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x314))(2);
    uVar7 = 1;
    goto LAB_10437c34;
  }
  *(undefined8 *)(iVar6 + 0x1bc) = uStack_50;
  *(undefined8 *)(iVar6 + 0x1c4) = uStack_58;
  *(float *)(iVar6 + 0x1cc) = (float)dStack_68;
  *(float *)(iVar6 + 0x1d0) = (float)dStack_60;
  *(int *)(iVar6 + 0x2e8) = (int)uStack_104._3_1_;
  if (asStack_44[0] != 0) {
    psVar8 = asStack_44;
    iVar12 = (iVar6 + 0x1c) - (int)psVar8;
    do {
      sVar5 = *psVar8;
      *(short *)(iVar12 + (int)psVar8) = sVar5;
      psVar8 = psVar8 + 1;
    } while (sVar5 != 0);
  }
  if ((((_DAT_10b1f538 != 0) && (iVar12 = func_0x1030d04e(piVar1), iVar12 != 0)) &&
      (piVar9 = (int *)func_0x1030d04e(piVar1), *piVar9 == 1)) &&
     ((iVar12 = func_0x1030d04e(piVar1), *(int *)(iVar12 + 4) != 0 &&
      (iVar12 = func_0x1030d04e(piVar1), *(int *)(iVar12 + 4) != 0)))) {
    iVar12 = func_0x1030d04e(piVar1);
    if ((iVar12 == 0) ||
       ((piVar9 = (int *)func_0x1030d04e(piVar1), *piVar9 != 1 ||
        (iVar12 = func_0x1030d04e(piVar1), *(int *)(iVar12 + 4) == 0)))) {
      iStack_f0 = 0;
    }
    else {
      iVar12 = func_0x1030d04e(piVar1);
      iStack_f0 = *(int *)(iVar12 + 4);
    }
    *(undefined4 *)(iVar6 + 0x204) = *(undefined4 *)(iStack_f0 + 0x204);
    *(undefined4 *)(iVar6 + 0x294) = *(undefined4 *)(iStack_f0 + 0x294);
    uStack_100 = _DAT_10b1f538 + 0x194;
    iVar12 = 0;
    iStack_f8 = 0;
    uStack_f4 = 0;
    if (0 < *(int *)(_DAT_10b1f538 + 0x198)) {
      do {
        iVar12 = iVar12 + 1;
        iStack_f8 = iVar12;
      } while (iVar12 < *(int *)(_DAT_10b1f538 + 0x198));
    }
    uStack_10 = 0xffffffff;
    uStack_fc = uStack_100;
    if (_DAT_10b1f538 != 0) {
      iVar15 = iStack_f0 + 0x18;
      iVar12 = *(int *)(*(int *)(_DAT_10b1f538 + 0x1a0) +
                       (*(int *)(_DAT_10b1f538 + 0x1a4) - 1U & *(uint *)(iStack_f0 + 0x18)) * 4);
      if (iVar12 != -1) {
        iVar3 = *(int *)(_DAT_10b1f538 + 0x194);
        do {
          if (*(uint *)(iVar3 + 4 + iVar12 * 0xc) == *(uint *)(iStack_f0 + 0x18)) {
            if ((*(int *)(iVar3 + 8 + iVar12 * 0xc) != 0) &&
               (piVar9 = (int *)func_0x1030d04e(iVar15), *piVar9 == 1)) {
              uVar7 = func_0x1030d04e(iVar15);
              (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(uVar7);
              func_0x10304a34(iVar15);
            }
            break;
          }
          iVar12 = *(int *)(iVar3 + iVar12 * 0xc);
        } while (iVar12 != -1);
      }
    }
    iVar12 = iStack_f0;
    (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))();
    cVar17 = (char)((uint)iVar12 >> 0x10);
    *(undefined4 *)(iVar6 + 8) = 0;
    *(undefined4 *)(iVar6 + 0x94) = 0;
    uStack_104 = _DAT_10b1f538 + 0x194;
    uVar11 = 0;
    uStack_fc = 0;
    iStack_f8 = 0;
    if (0 < *(int *)(_DAT_10b1f538 + 0x198)) {
      do {
        uVar11 = uVar11 + 1;
        uStack_fc = uVar11;
      } while ((int)uVar11 < *(int *)(_DAT_10b1f538 + 0x198));
    }
    uStack_14 = 0xffffffff;
    if ((0 < (int)*puVar4) && (_DAT_10b1f538 != 0)) {
      iVar12 = *(int *)(*(int *)(_DAT_10b1f538 + 0x1a0) +
                       (*(int *)(_DAT_10b1f538 + 0x1a4) - 1U & *puVar4) * 4);
      uStack_100 = uStack_104;
      if (iVar12 != -1) {
        iVar15 = *(int *)(_DAT_10b1f538 + 0x194);
        do {
          if (*(uint *)(iVar15 + 4 + iVar12 * 0xc) == *puVar4) {
            iVar12 = *(int *)(iVar15 + 8 + iVar12 * 0xc);
            if (iVar12 != 0) {
              (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(iVar12);
              func_0x10304a34(puVar4);
            }
            break;
          }
          iVar12 = *(int *)(iVar15 + iVar12 * 0xc);
        } while (iVar12 != -1);
      }
      uStack_128 = (undefined4 *)
                   (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(8,0x10853a28);
      if (uStack_128 == (undefined4 *)0x0) {
        uStack_128 = (undefined4 *)0x0;
      }
      else {
        *uStack_128 = 0;
        uStack_128[1] = 0;
      }
      uStack_1c = 0xffffffff;
      if (uStack_128 != (undefined4 *)0x0) {
        uStack_128[1] = iVar6;
        *uStack_128 = 1;
      }
      func_0x1030a60f(puVar4,&uStack_128);
    }
    uStack_104 = _DAT_10b1f538 + 0x194;
    uVar11 = 0;
    uStack_fc = 0;
    iStack_f8 = 0;
    if (0 < *(int *)(_DAT_10b1f538 + 0x198)) {
      do {
        uVar11 = uVar11 + 1;
        uStack_fc = uVar11;
      } while ((int)uVar11 < *(int *)(_DAT_10b1f538 + 0x198));
    }
    uStack_14 = 0xffffffff;
    uStack_100 = uStack_104;
    if (*(int *)(iVar6 + 0x204) != 0) {
      iVar12 = *(int *)(*(int *)(iVar6 + 0x204) + 0x6a0);
      uVar7 = func_0x10305394(10);
      *(undefined4 *)(*(int *)(iVar6 + 0x204) + 0x6a0) = uVar7;
      if (*(int *)(*(int *)(iVar6 + 0x204) + 0x6a0) == 0) {
        uVar7 = func_0x10305394(0xb);
        *(undefined4 *)(*(int *)(iVar6 + 0x204) + 0x6a0) = uVar7;
      }
      if (*(int *)(*(int *)(iVar6 + 0x204) + 0x6a0) == 0) {
        uVar7 = func_0x10305394(0xc);
        *(undefined4 *)(*(int *)(iVar6 + 0x204) + 0x6a0) = uVar7;
      }
      if (iVar12 != *(int *)(*(int *)(iVar6 + 0x204) + 0x6a0)) {
        *(int *)(*(int *)(iVar6 + 0x204) + 0x182c) = iVar12;
        iVar12 = *(int *)(iVar6 + 0x204);
        if (-1 < *(int *)(iVar12 + 0x6a0)) {
          iVar15 = *(int *)(_DAT_10b3e0a4[3] +
                           (_DAT_10b3e0a4[4] - 1U & *(uint *)(iVar12 + 0x6a0)) * 4);
          if (iVar15 != -1) {
            iVar3 = *_DAT_10b3e0a4;
            do {
              if (*(uint *)(iVar3 + 4 + iVar15 * 0xc) == *(uint *)(iVar12 + 0x6a0)) {
                iVar15 = *(int *)(iVar3 + 8 + iVar15 * 0xc);
                if ((iVar15 != 0) && (*(int *)(iVar15 + 4) == 0)) {
                  if (*(int *)(iVar15 + 0x168) < 0) {
                    *(uint *)(iVar12 + 0x1820) = *(uint *)(iVar12 + 0x1820) & 0xfffffffd;
                  }
                  else {
                    *(uint *)(iVar12 + 0x1820) = *(uint *)(iVar12 + 0x1820) | 2;
                  }
                }
                break;
              }
              iVar15 = *(int *)(iVar3 + iVar15 * 0xc);
            } while (iVar15 != -1);
          }
        }
      }
      uVar7 = func_0x10305394(2);
      *(undefined4 *)(*(int *)(iVar6 + 0x204) + 0x6a4) = uVar7;
      uVar7 = func_0x10305394(0xd);
      *(undefined4 *)(*(int *)(iVar6 + 0x204) + 0x6a8) = uVar7;
      fVar16 = (float)_DAT_1088ae20;
      *(float *)(*(int *)(iVar6 + 0x204) + 0x6b8) = (float)*(int *)(iVar6 + 0x23c) / fVar16;
      *(float *)(*(int *)(iVar6 + 0x204) + 0x6bc) = (float)*(int *)(iVar6 + 0x2ac) / fVar16;
      *(float *)(*(int *)(iVar6 + 0x204) + 0x6ec) = (float)*(int *)(iVar6 + 0x19c);
      *(float *)(*(int *)(iVar6 + 0x204) + 0x6f0) = (float)*(int *)(iVar6 + 0x1a0);
      *(float *)(*(int *)(iVar6 + 0x204) + 0x6f4) = (float)*(int *)(iVar6 + 0x1a4);
      *(float *)(*(int *)(iVar6 + 0x204) + 0x6f8) = (float)*(int *)(iVar6 + 0x1a8);
      *(float *)(*(int *)(iVar6 + 0x204) + 0x6fc) = (float)*(int *)(iVar6 + 0x1ac);
      *(float *)(*(int *)(iVar6 + 0x204) + 0x700) = (float)*(int *)(iVar6 + 0x1b0);
      if (uStack_128._3_1_ == '\0') {
        func_0x1030c3ab(*(undefined4 *)(iVar6 + 0x1cc),*(undefined4 *)(iVar6 + 0x1d0));
      }
      *(float *)(*(int *)(iVar6 + 0x204) + 0x6b0) = (float)*(double *)(iVar6 + 0x1bc);
      *(float *)(*(int *)(iVar6 + 0x204) + 0x6b4) = (float)*(double *)(iVar6 + 0x1c4);
      iVar12 = *(int *)(iVar6 + 0x204);
      if (*(char *)(*(int *)(iVar12 + 0x14d8) + 0x434) == '\x01') {
        *(float *)(iVar12 + 0x1550) = *(float *)(iVar12 + 0x6ec) * *(float *)(iVar12 + 0x6b4);
        iVar12 = *(int *)(iVar6 + 0x204);
        *(float *)(iVar12 + 0x1554) = *(float *)(iVar12 + 0x6f4) * *(float *)(iVar12 + 0x6b4);
        iVar12 = *(int *)(iVar6 + 0x204);
        fVar16 = *(float *)(iVar12 + 0x6fc);
      }
      else {
        *(float *)(iVar12 + 0x1550) = *(float *)(iVar12 + 0x6f0) * *(float *)(iVar12 + 0x6b4);
        iVar12 = *(int *)(iVar6 + 0x204);
        *(float *)(iVar12 + 0x1554) = *(float *)(iVar12 + 0x6f8) * *(float *)(iVar12 + 0x6b4);
        iVar12 = *(int *)(iVar6 + 0x204);
        fVar16 = *(float *)(iVar12 + 0x700);
      }
      *(float *)(iVar12 + 0x1558) = fVar16 * *(float *)(iVar12 + 0x6b4);
      sVar5 = *(short *)(iVar6 + 0x2b0);
      if ((((sVar5 == 1) || (sVar5 == 3)) || (sVar5 == 5)) || ((sVar5 == 7 || (sVar5 == 8)))) {
        func_0x1030bef6();
        if (*(short *)(iVar6 + 0x2b0) == 7) {
          *(undefined4 *)(*(int *)(iVar6 + 0x204) + 0x62c) = 10;
        }
        else {
          *(undefined4 *)(*(int *)(iVar6 + 0x204) + 0x62c) = 9;
        }
        *(int *)(*(int *)(iVar6 + 0x204) + 0x63c) = *(int *)(iVar6 + 0x204);
      }
      if ((*(short *)(iVar6 + 0x2b0) == 0) && (*(int *)(*(int *)(iVar6 + 0x204) + 0x62c) == 9)) {
        func_0x1030bef6();
      }
      iVar12 = *(int *)(*(int *)(iVar6 + 0x204) + 0x718);
      if ((iVar12 != 0) && ((*(byte *)(iVar12 + 0x714) & 1) != 0)) {
        func_0x1030a871(0,0);
      }
      func_0x1030a871(unaff_EDI,unaff_ESI);
      *(int *)(*(int *)(iVar6 + 0x204) + 0x17d0) = iStack_f8;
      *(int *)(*(int *)(iVar6 + 0x204) + 0x778) = (int)cVar17;
      uVar7 = func_0x10303742(*(undefined4 *)(iVar6 + 200));
      *(undefined4 *)(*(int *)(iVar6 + 0x204) + 0x1828) = uVar7;
      *(undefined4 *)(*(int *)(iVar6 + 0x204) + 0x1830) = *(undefined4 *)(iVar6 + 0x2e8);
      puVar2 = (uint *)(*(int *)(iVar6 + 0x204) + 0x1820);
      *puVar2 = *puVar2 ^ (*(uint *)(*(int *)(iVar6 + 0x204) + 0x1820) ^ *(uint *)(iVar6 + 0x2fc)) &
                          1;
    }
    if (_DAT_10b1f538 != 0) {
      iVar12 = *(int *)(*(int *)(_DAT_10b1f538 + 0x1a0) +
                       (*(int *)(_DAT_10b1f538 + 0x1a4) - 1U & *puVar4) * 4);
      if (iVar12 != -1) {
        iVar15 = *(int *)(_DAT_10b1f538 + 0x194);
        do {
          if (*(uint *)(iVar15 + 4 + iVar12 * 0xc) == *puVar4) {
            if (*(int *)(iVar15 + 8 + iVar12 * 0xc) != 0) {
              iVar12 = *(int *)(*(int *)(_DAT_10b1f538 + 0x1a0) +
                               (*(int *)(_DAT_10b1f538 + 0x1a4) - 1U & *puVar4) * 4);
              goto joined_r0x104374ca;
            }
            break;
          }
          iVar12 = *(int *)(iVar15 + iVar12 * 0xc);
        } while (iVar12 != -1);
      }
    }
    goto LAB_10437488;
  }
  if (iStack_cc == 0) {
    *(undefined4 *)(iVar6 + 8) = 0;
    *(undefined4 *)(iVar6 + 0x94) = 0;
    aiStack_bc[4] = _DAT_10b1f538 + 0x194;
    iVar12 = 0;
    iStack_a4 = 0;
    uStack_a0 = 0;
    if (0 < *(int *)(_DAT_10b1f538 + 0x198)) {
      do {
        iVar12 = iVar12 + 1;
        iStack_a4 = iVar12;
      } while (iVar12 < *(int *)(_DAT_10b1f538 + 0x198));
    }
    uStack_c = 0xffffffff;
    if ((0 < *piVar1) && (_DAT_10b1f538 != 0)) {
      iStack_a8 = aiStack_bc[4];
      iVar12 = func_0x1030d04e(piVar1);
      if (iVar12 != 0) {
        (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(iVar12);
        func_0x10304a34(piVar1);
      }
      puStack_124 = (undefined4 *)
                    (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(8,0x10853a28);
      if (puStack_124 == (undefined4 *)0x0) {
        puStack_124 = (undefined4 *)0x0;
      }
      else {
        *puStack_124 = 0;
        puStack_124[1] = 0;
      }
      uStack_18 = 0xffffffff;
      if (puStack_124 != (undefined4 *)0x0) {
        puStack_124[1] = iVar6;
        *puStack_124 = 1;
      }
      func_0x1030a60f(piVar1,&puStack_124);
    }
    uVar11 = uStack_100;
    iVar12 = _DAT_10b1f538;
    aiStack_bc[4] = _DAT_10b1f538 + 0x194;
    iVar15 = 0;
    iStack_a4 = 0;
    uStack_a0 = 0;
    if (0 < *(int *)(_DAT_10b1f538 + 0x198)) {
      do {
        iVar15 = iVar15 + 1;
        iStack_a4 = iVar15;
      } while (iVar15 < *(int *)(_DAT_10b1f538 + 0x198));
    }
    uStack_c = 0xffffffff;
    fStack_e8 = (float)iStack_d8;
    fStack_e4 = (float)iStack_d4;
    fStack_e0 = (float)iStack_c0;
    iStack_a8 = aiStack_bc[4];
    if (0 < (int)uStack_100) {
      if (_DAT_10b1f538 != 0) {
        piVar9 = (int *)(_DAT_10b1f538 + 0x194);
        iVar15 = *(int *)(*(int *)(_DAT_10b1f538 + 0x1a0) +
                         (*(int *)(_DAT_10b1f538 + 0x1a4) - 1U & uStack_100) * 4);
        if (iVar15 != -1) {
          iVar3 = *piVar9;
          do {
            if (*(uint *)(iVar3 + 4 + iVar15 * 0xc) == uStack_100) {
              if (*(int *)(iVar3 + 8 + iVar15 * 0xc) != 0) {
                iVar15 = *(int *)(*(int *)(_DAT_10b1f538 + 0x1a0) +
                                 (*(int *)(_DAT_10b1f538 + 0x1a4) - 1U & uStack_100) * 4);
                if (iVar15 == -1) goto LAB_104378cb;
                iVar3 = *piVar9;
                goto LAB_104378b4;
              }
              break;
            }
            iVar15 = *(int *)(iVar3 + iVar15 * 0xc);
          } while (iVar15 != -1);
        }
      }
      goto LAB_1043776b;
    }
    goto LAB_10437781;
  }
  goto LAB_10437b1c;
joined_r0x104374ca:
  if (iVar12 == -1) goto LAB_104374e8;
  if (*(uint *)(iVar15 + 4 + iVar12 * 0xc) == *puVar4) {
    piVar9 = *(int **)(iVar15 + 8 + iVar12 * 0xc);
    goto LAB_104374ea;
  }
  iVar12 = *(int *)(iVar15 + iVar12 * 0xc);
  goto joined_r0x104374ca;
LAB_104374e8:
  piVar9 = (int *)0x0;
LAB_104374ea:
  if (*piVar9 == 1) {
    iVar12 = *(int *)(*(int *)(_DAT_10b1f538 + 0x1a0) +
                     (*(int *)(_DAT_10b1f538 + 0x1a4) - 1U & *puVar4) * 4);
    if (iVar12 != -1) {
      iVar15 = *(int *)(_DAT_10b1f538 + 0x194);
      do {
        if (*(uint *)(iVar15 + 4 + iVar12 * 0xc) == *puVar4) {
          iVar12 = *(int *)(iVar15 + 8 + iVar12 * 0xc);
          goto LAB_1043752b;
        }
        iVar12 = *(int *)(iVar15 + iVar12 * 0xc);
      } while (iVar12 != -1);
    }
    iVar12 = 0;
LAB_1043752b:
    if (*(int *)(iVar12 + 4) == 0) goto LAB_10437488;
    iVar12 = *(int *)(*(int *)(_DAT_10b1f538 + 0x1a0) +
                     (*(int *)(_DAT_10b1f538 + 0x1a4) - 1U & *puVar4) * 4);
    uVar7 = uRam00000004;
    if (iVar12 != -1) {
      iVar15 = *(int *)(_DAT_10b1f538 + 0x194);
      do {
        if (*(uint *)(iVar15 + 4 + iVar12 * 0xc) == *puVar4) {
          uVar7 = *(undefined4 *)(*(int *)(iVar15 + 8 + iVar12 * 0xc) + 4);
          break;
        }
        iVar12 = *(int *)(iVar15 + iVar12 * 0xc);
      } while (iVar12 != -1);
    }
  }
  else {
LAB_10437488:
    uVar7 = 0;
  }
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x170))(uVar7,0,0);
  goto LAB_10437b1c;
  while (iVar15 = *(int *)(iVar3 + iVar15 * 0xc), iVar15 != -1) {
LAB_104378b4:
    if (*(uint *)(iVar3 + 4 + iVar15 * 0xc) == uStack_100) {
      piVar13 = *(int **)(iVar3 + 8 + iVar15 * 0xc);
      goto LAB_104378cd;
    }
  }
LAB_104378cb:
  piVar13 = (int *)0x0;
LAB_104378cd:
  if (((*piVar13 == 3) && (iVar15 = func_0x1030d04e(&uStack_100), *(int *)(iVar15 + 4) != 0)) &&
     (iVar15 = func_0x1030d04e(&uStack_100), *(int *)(iVar15 + 4) != 0)) {
    iVar12 = *(int *)(*(int *)(iVar12 + 0x1a0) + (*(int *)(iVar12 + 0x1a4) - 1U & uVar11) * 4);
    if (iVar12 != -1) {
      iVar15 = *piVar9;
      do {
        if (*(uint *)(iVar15 + 4 + iVar12 * 0xc) == uVar11) {
          if (((*(int *)(iVar15 + 8 + iVar12 * 0xc) != 0) &&
              (piVar9 = (int *)func_0x1030d04e(&uStack_100), *piVar9 == 3)) &&
             (iVar12 = func_0x1030d04e(&uStack_100), *(int *)(iVar12 + 4) != 0)) {
            iVar12 = func_0x1030d04e(&uStack_100);
            iVar12 = *(int *)(iVar12 + 4);
            goto LAB_10437939;
          }
          break;
        }
        iVar12 = *(int *)(iVar15 + iVar12 * 0xc);
      } while (iVar12 != -1);
    }
    iVar12 = 0;
LAB_10437939:
    uStack_74 = 0;
    uStack_70 = 0;
    uStack_6c = 0x3f800000;
    pfVar10 = (float *)_RotateAngleAxis_FVector__QBE_AV1_HABV1__Z
                                 (aiStack_bc + 4,*(uint *)(*(int *)(iVar12 + 4) + 0x1cc) & 0xffff,
                                  &uStack_74);
    iVar12 = *(int *)(iVar12 + 4);
    fStack_e8 = *pfVar10 + *(float *)(iVar12 + 0x1bc);
    fStack_e4 = *(float *)(iVar12 + 0x1c0) + pfVar10[1];
    fStack_e0 = *(float *)(iVar12 + 0x1c4) + pfVar10[2] + (float)_DAT_1088afc8;
  }
  else {
LAB_1043776b:
    _Logf_FOutputDevice__QAAXPBGZZ
              (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x1088afd8);
  }
LAB_10437781:
  *(undefined4 *)(iVar6 + 0x204) = 0;
  __0L2ParamStack__QAE_H_Z(10);
  uStack_c = 7;
  _PushBack_L2ParamStack__QAEHPAX_Z(aiStack_bc[0]);
  _PushBack_L2ParamStack__QAEHPAX_Z(aiStack_bc[2]);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_d0);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_c4);
  _PushBack_L2ParamStack__QAEHPAX_Z(0);
  _PushBack_L2ParamStack__QAEHPAX_Z(aiStack_bc[3]);
  _PushBack_L2ParamStack__QAEHPAX_Z((int)(char)((uint3)unaff_EBX >> 0x10));
  fVar16 = fStack_e0;
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x120))
            (iVar6,fStack_e8,fStack_e4,fStack_e0,uStack_c8,&uStack_fc);
  cVar17 = (char)((uint)fVar16 >> 0x10);
  if ((*(int *)(iVar6 + 0x204) != 0) &&
     (((sVar5 = *(short *)(iVar6 + 0x2b0), sVar5 == 1 || (sVar5 == 3)) ||
      ((sVar5 == 5 || ((sVar5 == 7 || (sVar5 == 8)))))))) {
    func_0x1030bef6();
    if (*(short *)(iVar6 + 0x2b0) == 7) {
      *(undefined4 *)(*(int *)(iVar6 + 0x204) + 0x62c) = 10;
    }
    else {
      *(undefined4 *)(*(int *)(iVar6 + 0x204) + 0x62c) = 9;
    }
    *(int *)(*(int *)(iVar6 + 0x204) + 0x63c) = *(int *)(iVar6 + 0x204);
  }
  if ((*(short *)(iVar6 + 0x2b0) == 0) && (*(int *)(*(int *)(iVar6 + 0x204) + 0x62c) == 9)) {
    func_0x1030bef6();
  }
  iVar12 = *(int *)(*(int *)(iVar6 + 0x204) + 0x718);
  if ((iVar12 != 0) && ((*(byte *)(iVar12 + 0x714) & 1) != 0)) {
    func_0x1030a871(0,0);
  }
  func_0x1030a871(puStack_124,unaff_EDI);
  *(uint *)(*(int *)(iVar6 + 0x204) + 0x17d0) = uStack_fc;
  *(int *)(*(int *)(iVar6 + 0x204) + 0x778) = (int)cVar17;
  uVar7 = func_0x10303742(*(undefined4 *)(iVar6 + 200));
  *(undefined4 *)(*(int *)(iVar6 + 0x204) + 0x1828) = uVar7;
  *(undefined4 *)(*(int *)(iVar6 + 0x204) + 0x1830) = *(undefined4 *)(iVar6 + 0x2e8);
  puVar2 = (uint *)(*(int *)(iVar6 + 0x204) + 0x1820);
  *puVar2 = *puVar2 ^ (*(uint *)(*(int *)(iVar6 + 0x204) + 0x1820) ^ *(uint *)(iVar6 + 0x2fc)) & 1;
  uStack_c = 0xffffffff;
  __1L2ParamStack__QAE_XZ();
LAB_10437b1c:
  iVar12 = *(int *)(iVar6 + 0x204);
  if (iVar12 != 0) {
    *(uint *)(iVar12 + 0x1820) =
         *(uint *)(iVar12 + 0x1820) ^ (*(int *)(iVar6 + 0x300) * 4 ^ *(uint *)(iVar12 + 0x1820)) & 4
    ;
    *(undefined4 *)(*(int *)(iVar6 + 0x204) + 0x1824) = *(undefined4 *)(iVar6 + 0x304);
  }
  func_0x103022f7(*(undefined4 *)(iVar6 + 0x2ec));
  if (0 < *(int *)(iVar6 + 0x284)) {
    func_0x10303df5(*(int *)(iVar6 + 0x284),*(undefined4 *)(iVar6 + 0x288),
                    *(undefined4 *)(iVar6 + 0x28c),*(undefined4 *)(iVar6 + 0x290),
                    *(undefined4 *)(iVar6 + 0x2a0),iStack_7c);
  }
  sStack_110 = (short)piVar1;
  if (0 < sStack_110) {
    (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(uStack_10c);
  }
  if (aiStack_bc[0] != 0) {
    (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x720))
              (*(undefined4 *)(iVar6 + 0x204),0,uStack_90,fStack_8c,fStack_88,0,0);
  }
  func_0x1030aa47();
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x1088af30,*piVar1,iVar6 + 0x1c
             ,*(undefined4 *)(iVar6 + 0x4c),*(undefined4 *)(iVar6 + 0x50),uStack_dc,iStack_d8,
             uStack_c4);
  uVar7 = 0;
LAB_10437c34:
  *unaff_FS_OFFSET = uStack_18;
  return uVar7;
}

