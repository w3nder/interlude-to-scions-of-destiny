
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_104342f0(void)

{
  uint ****ppppuVar1;
  uint ***pppuVar2;
  int iVar3;
  longlong lVar4;
  float fVar5;
  int iVar6;
  uint ***pppuVar7;
  undefined4 uVar8;
  uint **ppuVar9;
  int *piVar10;
  uint *puVar11;
  int iVar12;
  float *pfVar13;
  uint *puVar14;
  uint uVar15;
  short sVar16;
  undefined4 unaff_EBP;
  uint ****ppppuVar17;
  uint *unaff_ESI;
  short unaff_DI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 unaff_retaddr;
  uint ***pppuVar18;
  uint ****ppppuStack_13c;
  undefined4 *puStack_138;
  undefined4 *puStack_134;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  int iStack_118;
  uint *puStack_114;
  uint ***pppuStack_110;
  float fStack_10c;
  int iStack_108;
  undefined4 uStack_104;
  int iStack_100;
  float fStack_fc;
  undefined4 *puStack_f8;
  float fStack_f4;
  float fStack_f0;
  uint ***pppuStack_ec;
  undefined4 uStack_e8;
  uint ****ppppuStack_e4;
  int iStack_e0;
  uint ***pppuStack_dc;
  int iStack_d8;
  uint ***pppuStack_d4;
  uint ***pppuStack_d0;
  int iStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  int iStack_c0;
  int iStack_bc;
  int iStack_b8;
  uint ****ppppuStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  undefined4 uStack_a4;
  uint ***pppuStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  uint ***apppuStack_94 [3];
  uint uStack_88;
  int iStack_84;
  undefined4 uStack_80;
  undefined1 auStack_7c [4];
  undefined1 auStack_78 [4];
  undefined1 auStack_74 [4];
  undefined4 uStack_70;
  undefined1 auStack_6c [4];
  undefined1 auStack_68 [4];
  undefined1 auStack_64 [4];
  undefined1 auStack_60 [4];
  undefined1 auStack_5c [4];
  undefined1 auStack_58 [4];
  undefined1 auStack_54 [4];
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [12];
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [8];
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined8 uStack_2c;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_c;
  undefined4 uStack_8;
  int iStack_4;
  
  iStack_4 = -1;
  uStack_8 = 0x10810894;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pppuStack_dc = (uint ***)CONCAT31(pppuStack_dc._1_3_,1);
  pppuStack_110 = (uint ***)0x0;
  puStack_134 = (undefined4 *)0x1088aed8;
  puStack_138 = (undefined4 *)0x314;
  iStack_100 = 0;
  ppppuStack_13c = (uint ****)0x1043433a;
  iVar6 = (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)();
  if (iVar6 == 0) {
    pppuVar7 = (uint ***)0x0;
  }
  else {
    ppppuStack_13c = (uint ****)0x10434345;
    pppuVar7 = (uint ***)func_0x10313449();
  }
  ppppuStack_13c = (uint ****)0x314;
  func_0x107a6860(pppuVar7,0);
  iVar6 = iStack_4;
  pppuStack_d0 = pppuVar7 + 0x14;
  pppuStack_dc = pppuVar7 + 0x13;
  pppuStack_d4 = pppuVar7 + 7;
  ppppuVar1 = (uint ****)(pppuVar7 + 6);
  uVar8 = func_0x103034e5(*(undefined4 *)(iStack_4 + 0x48),unaff_retaddr,0x1088ae38,&iStack_e0,
                          &iStack_cc,&iStack_d8,&pppuStack_110,ppppuVar1,0x30,pppuStack_d4,
                          pppuStack_dc,pppuStack_d0,pppuVar7 + 0x15,pppuVar7 + 0x16,pppuVar7 + 0x17,
                          pppuVar7 + 0x19,pppuVar7 + 0x1a,pppuVar7 + 0x1b,pppuVar7 + 0x1c,
                          pppuVar7 + 0x1d,pppuVar7 + 0x1e,pppuVar7 + 0x1f,pppuVar7 + 0x20,
                          pppuVar7 + 0x21,pppuVar7 + 0x22,pppuVar7 + 0x86,pppuVar7 + 0x85,
                          pppuVar7 + 0x23,pppuVar7 + 0x24,pppuVar7 + 0x26,pppuVar7 + 0x27,
                          pppuVar7 + 0x28,pppuVar7 + 0x29,pppuVar7 + 0x2a,pppuVar7 + 0x2b,
                          pppuVar7 + 0x2c,pppuVar7 + 0x2d,pppuVar7 + 0x2e,pppuVar7 + 0x2f,
                          pppuVar7 + 0x30,pppuVar7 + 0x31,pppuVar7 + 0x32,pppuVar7 + 0x33,
                          pppuVar7 + 0x34,pppuVar7 + 0x37,pppuVar7 + 0x38,&iStack_84,&uStack_80,
                          auStack_7c,auStack_78,auStack_74,&uStack_70,auStack_6c,auStack_68,
                          auStack_64,auStack_60,auStack_5c,auStack_58,auStack_54,auStack_50,
                          auStack_4c,auStack_40,auStack_3c,pppuVar7 + 0x3a,pppuVar7 + 0x3b,
                          pppuVar7 + 0x3c,pppuVar7 + 0x3d,pppuVar7 + 0x3e,pppuVar7 + 0x3f,
                          pppuVar7 + 0x40,pppuVar7 + 0x41,pppuVar7 + 0x42,pppuVar7 + 0x43,
                          pppuVar7 + 0x44,pppuVar7 + 0x45,pppuVar7 + 0x46,pppuVar7 + 0x47,
                          pppuVar7 + 0x48,pppuVar7 + 0x49,pppuVar7 + 0x4a,pppuVar7 + 0x4b,
                          pppuVar7 + 0x4c,pppuVar7 + 0x4d,pppuVar7 + 0x4e,pppuVar7 + 0x4f,
                          pppuVar7 + 0x50,pppuVar7 + 0x51,pppuVar7 + 0x52,pppuVar7 + 0x53,
                          pppuVar7 + 0x54,pppuVar7 + 0x55,pppuVar7 + 0x56,pppuVar7 + 0x57,
                          pppuVar7 + 0x5c,pppuVar7 + 0x5d,pppuVar7 + 0x5e,pppuVar7 + 0x5f,
                          pppuVar7 + 0x89,pppuVar7 + 0x8a,pppuVar7 + 0x8b,pppuVar7 + 0x8c,
                          pppuVar7 + 0x87,pppuVar7 + 0x88,pppuVar7 + 0x8d,pppuVar7 + 0x8f,
                          pppuVar7 + 0xab,pppuVar7 + 0x8e,pppuVar7 + 0x65,pppuVar7 + 0x66,
                          pppuVar7 + 0x67,pppuVar7 + 0x68,pppuVar7 + 0x69,pppuVar7 + 0x6a,
                          pppuVar7 + 0x6d,pppuVar7 + 0x6e,pppuVar7 + 0x6b,pppuVar7 + 0x6c,&uStack_2c
                          ,&uStack_1c,&uStack_34,&uStack_24,pppuVar7 + 0x90,pppuVar7 + 0x91,
                          pppuVar7 + 0x92,pppuVar7 + 0x94);
  if (0 < (short)iStack_118) {
    lVar4 = (ulonglong)((int)(short)iStack_118 + 1) * 2;
    ppppuStack_13c = (uint ****)0x10853a28;
    iStack_108 = (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)
                           ((uint)lVar4 | -(uint)((int)((ulonglong)lVar4 >> 0x20) != 0));
  }
  sVar16 = 0;
  if (0 < (short)iStack_118) {
    do {
      ppppuStack_13c = (uint ****)(iStack_108 + sVar16 * 2);
      uVar8 = func_0x103034e5(*(undefined4 *)(iVar6 + 0x48),uVar8,0x1088494c);
      sVar16 = sVar16 + 1;
    } while (sVar16 < (short)iStack_118);
  }
  ppppuStack_13c = (uint ****)(pppuVar7 + 0xaf);
  uVar8 = func_0x103034e5(*(undefined4 *)(iVar6 + 0x48),uVar8,0x1087f9dc);
  uStack_e8 = 0;
  uStack_c8 = 0;
  uStack_a4 = 0;
  uVar8 = func_0x103034e5(*(undefined4 *)(iVar6 + 0x48),uVar8,0x10883f30,&uStack_e8,&pppuStack_ec);
  uVar8 = func_0x103034e5(*(undefined4 *)(iVar6 + 0x48),uVar8,0x1087ff8c,&ppppuStack_b4);
  if (0 < (int)pppuVar7[0xa1]) {
    ppppuStack_13c = (uint ****)0xa;
    __0L2ParamStack__QAE_H_Z();
    uStack_c = 0;
    ppppuStack_13c = ppppuStack_b4;
    _PushBack_L2ParamStack__QAEHPAX_Z();
    ppppuStack_13c = apppuStack_94;
    (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x3cc))();
    uStack_c = 0xffffffff;
    ppppuStack_13c = (uint ****)0x1043487e;
    __1L2ParamStack__QAE_XZ();
  }
  ppppuStack_13c = (uint ****)(pppuVar7 + 0xb9);
  uVar8 = func_0x103034e5(*(undefined4 *)(iVar6 + 0x48),uVar8,0x1088ae30,pppuVar7 + 0xb8,
                          (int)pppuVar7 + 0x2e2,&uStack_c8);
  uVar8 = func_0x103034e5(*(undefined4 *)(iVar6 + 0x48),uVar8,0x10887e80,pppuVar7 + 0xb0,&uStack_a4,
                          pppuVar7 + 0xb1,pppuVar7 + 0xb2,(int)&uStack_104 + 3);
  uVar8 = func_0x103034e5(*(undefined4 *)(iVar6 + 0x48),uVar8,0x1087f9dc,pppuVar7 + 0xbb);
  ppppuStack_13c = (uint ****)(pppuVar7 + 0xbf);
  uVar8 = func_0x103034e5(*(undefined4 *)(iVar6 + 0x48),uVar8,0x1088ae2c,pppuVar7 + 0xa8,
                          pppuVar7 + 0xbe);
  uStack_c4 = 0;
  uVar8 = func_0x103034e5(*(undefined4 *)(iVar6 + 0x48),uVar8,0x1087fa3c,&uStack_c4,&iStack_b8,
                          &iStack_bc,&iStack_c0);
  fStack_b0 = (float)iStack_b8;
  pppuVar18 = pppuVar7 + 0xc2;
  fStack_fc = (float)iStack_bc;
  fStack_10c = (float)iStack_c0;
  fStack_ac = fStack_fc;
  fStack_a8 = fStack_10c;
  uVar8 = func_0x103034e5(*(undefined4 *)(iVar6 + 0x48),uVar8,0x1087ff8c,pppuVar18);
  ppppuStack_13c = (uint ****)&ppppuStack_e4;
  uVar8 = func_0x103034e5(*(undefined4 *)(iVar6 + 0x48),uVar8,0x1087f9dc);
  uVar8 = func_0x103034e5(*(undefined4 *)(iVar6 + 0x48),uVar8,0x1087ff44,pppuVar7 + 0xc3,
                          pppuVar7 + 0xc4);
  pppuVar2 = pppuVar7 + 100;
  uVar8 = func_0x103034e5(*(undefined4 *)(iVar6 + 0x48),uVar8,0x1087ff8c,pppuVar2);
  *pppuVar2 = (uint **)(((*(byte *)pppuVar2 | 0xffffff00) << 8 |
                        (uint)*(byte *)((int)pppuVar7 + 0x191)) << 8 |
                       (uint)*(byte *)((int)pppuVar7 + 0x192));
  func_0x103034e5(*(undefined4 *)(iVar6 + 0x48),uVar8,0x1087ff8c,pppuVar7 + 0xc1);
  ppuVar9 = pppuVar7[0xc1];
  if (((int)ppuVar9 < 1) || (0x13 < (int)ppuVar9)) {
    ppuVar9 = (uint **)0x0;
  }
  else {
    ppuVar9 = (uint **)0x1;
  }
  pppuVar7[0xc0] = ppuVar9;
  pppuVar7[0x25] = (uint **)0x1;
  *pppuVar18 = (uint **)(((*(byte *)pppuVar18 | 0xffffff00) << 8 |
                         (uint)*(byte *)((int)pppuVar7 + 0x309)) << 8 |
                        (uint)*(byte *)((int)pppuVar7 + 0x30a));
  *(ulonglong *)(pppuVar7 + 0x6f) = CONCAT44(uStack_18,uStack_1c);
  *(undefined8 *)(pppuVar7 + 0x71) = uStack_2c;
  pppuVar7[0x73] = (uint **)(float)(double)CONCAT44(uStack_30,uStack_34);
  pppuVar7[0x74] = (uint **)(float)(double)CONCAT44(uStack_20,uStack_24);
  pppuVar7[0xba] = (uint **)(int)uStack_104._3_1_;
  if (_DAT_10b1f538 != 0) {
    iVar6 = *(int *)(*(int *)(_DAT_10b1f538 + 0x1a0) +
                    (*(int *)(_DAT_10b1f538 + 0x1a4) - 1U & (uint)*ppppuVar1) * 4);
    if (iVar6 != -1) {
      iVar12 = *(int *)(_DAT_10b1f538 + 0x194);
      do {
        if (*(uint ****)(iVar12 + 4 + iVar6 * 0xc) == *ppppuVar1) {
          if ((((*(int *)(iVar12 + 8 + iVar6 * 0xc) != 0) &&
               (ppppuStack_13c = ppppuVar1, piVar10 = (int *)func_0x1030d04e(), *piVar10 == 1)) &&
              (ppppuStack_13c = ppppuVar1, iVar6 = func_0x1030d04e(), *(int *)(iVar6 + 4) != 0)) &&
             (ppppuStack_13c = ppppuVar1, iVar6 = func_0x1030d04e(), *(int *)(iVar6 + 4) != 0)) {
            ppppuStack_13c = ppppuVar1;
            iVar6 = func_0x1030d04e();
            if (((iVar6 == 0) || (piVar10 = (int *)func_0x1030d04e(ppppuVar1), *piVar10 != 1)) ||
               (iVar6 = func_0x1030d04e(ppppuVar1), *(int *)(iVar6 + 4) == 0)) {
              pppuStack_110 = (uint ***)0x0;
            }
            else {
              iVar6 = func_0x1030d04e(ppppuVar1);
              pppuStack_110 = *(uint ****)(iVar6 + 4);
            }
            uStack_120 = pppuStack_110 + 0x26;
            iStack_100 = (int)pppuVar7 - (int)pppuStack_110;
            uStack_104 = (uint *)0x0;
            goto LAB_10434c80;
          }
          break;
        }
        iVar6 = *(int *)(iVar12 + iVar6 * 0xc);
      } while (iVar6 != -1);
    }
  }
  puStack_114 = (uint *)0x0;
  ppppuVar17 = (uint ****)(pppuVar7 + 0x26);
  do {
    if (*ppppuVar17 != (uint ***)0x0) {
      ppppuStack_13c = (uint ****)0x10853a28;
      piVar10 = (int *)(**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(0x18);
      *piVar10 = (int)*ppppuVar17;
      piVar10[1] = (&iStack_84)[(int)puStack_114];
      piVar10[4] = 0;
      piVar10[5] = 0;
      if ((0 < (int)*ppppuVar17) && (_DAT_10b1f538 != 0)) {
        ppppuStack_13c = ppppuVar17;
        iVar6 = func_0x1030d04e();
        if (iVar6 != 0) {
          (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(iVar6);
          func_0x10304a34(ppppuVar17);
        }
        puStack_134 = (undefined4 *)
                      (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(8,0x10853a28);
        if (puStack_134 == (undefined4 *)0x0) {
          puStack_134 = (undefined4 *)0x0;
        }
        else {
          *puStack_134 = 0;
          puStack_134[1] = 0;
        }
        uStack_18 = 0xffffffff;
        if (puStack_134 != (undefined4 *)0x0) {
          puStack_134[1] = piVar10;
          *puStack_134 = 2;
        }
        func_0x1030a60f(ppppuVar17,&puStack_134);
      }
    }
    puStack_114 = (uint *)((int)puStack_114 + 1);
    ppppuVar17 = ppppuVar17 + 1;
  } while ((int)puStack_114 < 0x14);
  pppuVar7[2] = (uint **)0x0;
  pppuVar7[0x25] = (uint **)0x1;
  if ((0 < (int)*ppppuVar1) && (_DAT_10b1f538 != 0)) {
    ppppuStack_13c = ppppuVar1;
    iVar6 = func_0x1030d04e();
    if (iVar6 != 0) {
      (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(iVar6);
      func_0x10304a34(ppppuVar1);
    }
    puStack_134 = (undefined4 *)
                  (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(8,0x10853a28);
    if (puStack_134 == (undefined4 *)0x0) {
      puStack_134 = (undefined4 *)0x0;
    }
    else {
      *puStack_134 = 0;
      puStack_134[1] = 0;
    }
    uStack_18 = 0xffffffff;
    if (puStack_134 != (undefined4 *)0x0) {
      puStack_134[1] = pppuVar7;
      *puStack_134 = 1;
    }
    func_0x1030a60f(ppppuVar1,&puStack_134);
  }
  puStack_f8 = (undefined4 *)(float)iStack_e0;
  _DAT_10b1f530 = *ppppuVar1;
  fStack_f4 = (float)iStack_cc;
  fStack_f0 = (float)iStack_d8;
  if (0 < (int)pppuStack_110) {
    if (_DAT_10b1f538 != 0) {
      iVar6 = *(int *)(*(int *)(_DAT_10b1f538 + 0x1a0) +
                      (*(int *)(_DAT_10b1f538 + 0x1a4) - 1U & (uint)pppuStack_110) * 4);
      if (iVar6 != -1) {
        iVar12 = *(int *)(_DAT_10b1f538 + 0x194);
        do {
          if (*(uint ****)(iVar12 + 4 + iVar6 * 0xc) == pppuStack_110) {
            if (*(int *)(iVar12 + 8 + iVar6 * 0xc) != 0) {
              ppppuStack_13c = &pppuStack_110;
              piVar10 = (int *)func_0x1030d04e();
              if (*piVar10 == 3) {
                ppppuStack_13c = &pppuStack_110;
                iVar6 = func_0x1030d04e();
                if (*(int *)(iVar6 + 4) != 0) {
                  ppppuStack_13c = &pppuStack_110;
                  iVar6 = func_0x1030d04e();
                  if (*(int *)(iVar6 + 4) != 0) {
                    ppppuStack_13c = &pppuStack_110;
                    iVar6 = func_0x1030d04e();
                    if (iVar6 == 0) {
LAB_10435ad0:
                      iVar6 = 0;
                    }
                    else {
                      ppppuStack_13c = &pppuStack_110;
                      piVar10 = (int *)func_0x1030d04e();
                      if (*piVar10 != 3) goto LAB_10435ad0;
                      ppppuStack_13c = &pppuStack_110;
                      iVar6 = func_0x1030d04e();
                      if (*(int *)(iVar6 + 4) == 0) goto LAB_10435ad0;
                      ppppuStack_13c = &pppuStack_110;
                      iVar6 = func_0x1030d04e();
                      iVar6 = *(int *)(iVar6 + 4);
                    }
                    pppuStack_a0 = (uint ***)0x0;
                    ppppuStack_13c = &pppuStack_a0;
                    uStack_9c = 0;
                    uStack_98 = 0x3f800000;
                    pfVar13 = (float *)_RotateAngleAxis_FVector__QBE_AV1_HABV1__Z
                                                 (apppuStack_94,
                                                  *(uint *)(*(int *)(iVar6 + 4) + 0x1cc) & 0xffff);
                    iVar6 = *(int *)(iVar6 + 4);
                    puStack_f8 = (undefined4 *)(*pfVar13 + *(float *)(iVar6 + 0x1bc));
                    fStack_f4 = *(float *)(iVar6 + 0x1c0) + pfVar13[1];
                    fStack_f0 = *(float *)(iVar6 + 0x1c4) + pfVar13[2];
                    goto LAB_10435993;
                  }
                }
              }
            }
            break;
          }
          iVar6 = *(int *)(iVar12 + iVar6 * 0xc);
        } while (iVar6 != -1);
      }
    }
    ppppuStack_13c = (uint ****)0x1088ad98;
    _Logf_FOutputDevice__QAAXPBGZZ(*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref);
  }
LAB_10435993:
  pppuVar7[0x81] = (uint **)0x0;
  ppppuStack_13c = ppppuStack_e4;
  pppuVar18 = pppuStack_ec;
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x124))
            (pppuVar7,puStack_f8,fStack_f4,fStack_f0,0,(int)uStack_120._3_1_,uStack_c8);
  sVar16 = *(short *)(pppuVar7 + 0xac);
  if ((((sVar16 == 1) || (sVar16 == 3)) || (sVar16 == 5)) || ((sVar16 == 7 || (sVar16 == 8)))) {
    func_0x1030bef6();
    if (*(short *)(pppuVar7 + 0xac) == 7) {
      pppuVar7[0x81][0x18b] = (uint *)0xa;
    }
    else {
      pppuVar7[0x81][0x18b] = (uint *)0x9;
    }
    pppuVar7[0x81][399] = (uint *)pppuVar7[0x81];
  }
  if ((*(short *)(pppuVar7 + 0xac) == 0) && (pppuVar7[0x81][0x18b] == (uint *)0x9)) {
    func_0x1030bef6();
  }
  if ((pppuVar7[0x81][0x1c6] != (uint *)0x0) && ((pppuVar7[0x81][0x1c6][0x1c5] & 1) != 0)) {
    func_0x1030a871(0,0);
  }
  func_0x1030a871(ppppuStack_13c,unaff_ESI);
  pppuVar7[0x81][0x5f4] = puStack_114;
  pppuVar7[0x81][0x1de] = (uint *)(int)(char)iStack_118;
  puVar14 = (uint *)func_0x10303742(uStack_80);
  pppuVar7[0x81][0x60a] = puVar14;
  pppuVar7[0x81][0x60c] = (uint *)pppuVar7[0xba];
  ppuVar9 = pppuVar7[0x81] + 0x608;
  *ppuVar9 = (uint *)((uint)*ppuVar9 ^ ((uint)pppuVar7[0x81][0x608] ^ (uint)pppuVar7[0xbf]) & 1);
  goto LAB_10435c34;
LAB_10434c80:
  ppuVar9 = *uStack_120;
  if ((ppuVar9 != (uint **)0x0) || (*(int *)(iStack_100 + (int)uStack_120) != 0)) {
    if (_DAT_10b1f538 != 0) {
      iVar6 = *(int *)(*(int *)(_DAT_10b1f538 + 0x1a0) +
                      (*(int *)(_DAT_10b1f538 + 0x1a4) - 1U & (uint)ppuVar9) * 4);
      if (iVar6 != -1) {
        iVar12 = *(int *)(_DAT_10b1f538 + 0x194);
        do {
          if (*(uint ***)(iVar12 + 4 + iVar6 * 0xc) == ppuVar9) {
            if (*(int *)(iVar12 + 8 + iVar6 * 0xc) != 0) {
              iVar6 = *(int *)(*(int *)(_DAT_10b1f538 + 0x1a0) +
                              (*(int *)(_DAT_10b1f538 + 0x1a4) - 1U & (uint)ppuVar9) * 4);
              goto joined_r0x10434e38;
            }
            break;
          }
          iVar6 = *(int *)(iVar12 + iVar6 * 0xc);
        } while (iVar6 != -1);
      }
    }
    goto LAB_10434cd8;
  }
  goto LAB_104350ec;
joined_r0x10434e38:
  if (iVar6 == -1) goto LAB_10434e54;
  if (*(uint ***)(iVar12 + 4 + iVar6 * 0xc) == ppuVar9) {
    piVar10 = *(int **)(iVar12 + 8 + iVar6 * 0xc);
    goto LAB_10434e56;
  }
  iVar6 = *(int *)(iVar12 + iVar6 * 0xc);
  goto joined_r0x10434e38;
LAB_10434e54:
  piVar10 = (int *)0x0;
LAB_10434e56:
  if ((*piVar10 == 2) && (iVar6 = func_0x1030d04e(uStack_120), *(int *)(iVar6 + 4) != 0)) {
    iVar6 = func_0x1030d04e(uStack_120);
    iStack_118 = *(int *)(iVar6 + 4);
  }
  else {
LAB_10434cd8:
    iStack_118 = 0;
  }
  if (_DAT_10b1f538 != 0) {
    puVar14 = (uint *)(iStack_100 + (int)uStack_120);
    uVar15 = *puVar14;
    iVar6 = *(int *)(*(int *)(_DAT_10b1f538 + 0x1a0) +
                    (*(int *)(_DAT_10b1f538 + 0x1a4) - 1U & uVar15) * 4);
    if (iVar6 != -1) {
      iVar12 = *(int *)(_DAT_10b1f538 + 0x194);
      do {
        if (*(uint *)(iVar12 + 4 + iVar6 * 0xc) == uVar15) {
          if (*(int *)(iVar12 + 8 + iVar6 * 0xc) != 0) {
            iVar6 = *(int *)(*(int *)(_DAT_10b1f538 + 0x1a0) +
                            (*(int *)(_DAT_10b1f538 + 0x1a4) - 1U & uVar15) * 4);
            goto joined_r0x10434eae;
          }
          break;
        }
        iVar6 = *(int *)(iVar12 + iVar6 * 0xc);
      } while (iVar6 != -1);
    }
  }
LAB_10434d38:
  iVar6 = 0;
LAB_10434d3a:
  if (((iStack_118 == 0) || (iVar6 == 0)) || (iStack_118 != iVar6)) {
    puVar14 = (uint *)(iStack_100 + (int)uStack_120);
    if ((*(int *)(iStack_100 + (int)uStack_120) != 0) && (iVar6 == 0)) {
      puVar11 = (uint *)(**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)
                                  (0x18,0x10853a28);
      *puVar11 = *puVar14;
      puVar11[1] = (&uStack_88)[(int)uStack_104];
      puVar11[4] = 0;
      puVar11[5] = 0;
      if ((0 < (int)*puVar14) && (_DAT_10b1f538 != 0)) {
        iVar6 = func_0x1030d04e(puVar14);
        if (iVar6 != 0) {
          (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(iVar6);
          func_0x10304a34(puVar14);
        }
        puStack_138 = (undefined4 *)
                      (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(8,0x10853a28);
        if (puStack_138 == (undefined4 *)0x0) {
          puStack_138 = (undefined4 *)0x0;
        }
        else {
          *puStack_138 = 0;
          puStack_138[1] = 0;
        }
        uStack_1c = 0xffffffff;
        if (puStack_138 != (undefined4 *)0x0) {
          puStack_138[1] = puVar11;
          *puStack_138 = 2;
        }
        func_0x1030a60f(puVar14,&puStack_138);
      }
    }
    ppuVar9 = (uint **)*puVar14;
    if (iStack_118 == 0) {
      if ((0 < (int)ppuVar9) && (*uStack_120 != ppuVar9)) {
        (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x168))((&uStack_88)[(int)uStack_104]);
      }
    }
    else {
      if (((int)ppuVar9 < 1) || (*uStack_120 == ppuVar9)) {
        if (ppuVar9 == (uint **)0x0) {
          (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x168))(*(undefined4 *)(iStack_118 + 4));
        }
      }
      else {
        (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x168))((&uStack_88)[(int)uStack_104]);
      }
      if (_DAT_10b1f538 != 0) {
        iVar6 = *(int *)(*(int *)(_DAT_10b1f538 + 0x1a0) +
                        (*(int *)(_DAT_10b1f538 + 0x1a4) - 1U & (uint)*uStack_120) * 4);
        if (iVar6 != -1) {
          iVar12 = *(int *)(_DAT_10b1f538 + 0x194);
          do {
            if (*(uint ***)(iVar12 + 4 + iVar6 * 0xc) == *uStack_120) {
              if (((*(int *)(iVar12 + 8 + iVar6 * 0xc) != 0) &&
                  (piVar10 = (int *)func_0x1030d04e(uStack_120), *piVar10 == 2)) &&
                 (iVar6 = func_0x1030d04e(uStack_120), *(int *)(iVar6 + 4) != 0)) {
                iVar6 = func_0x1030d04e(uStack_120);
                uVar8 = *(undefined4 *)(iVar6 + 4);
                goto LAB_10434fc9;
              }
              break;
            }
            iVar6 = *(int *)(iVar12 + iVar6 * 0xc);
          } while (iVar6 != -1);
        }
      }
      uVar8 = 0;
LAB_10434fc9:
      (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(uVar8);
      if (_DAT_10b1f538 != 0) {
        iVar6 = *(int *)(*(int *)(_DAT_10b1f538 + 0x1a0) +
                        (*(int *)(_DAT_10b1f538 + 0x1a4) - 1U & (uint)*uStack_120) * 4);
        if (iVar6 != -1) {
          iVar12 = *(int *)(_DAT_10b1f538 + 0x194);
          do {
            if (*(uint ***)(iVar12 + 4 + iVar6 * 0xc) == *uStack_120) {
              if ((*(int *)(iVar12 + 8 + iVar6 * 0xc) != 0) &&
                 (piVar10 = (int *)func_0x1030d04e(uStack_120), *piVar10 == 2)) {
                uVar8 = func_0x1030d04e(uStack_120);
                (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(uVar8);
                func_0x10304a34(uStack_120);
              }
              break;
            }
            iVar6 = *(int *)(iVar12 + iVar6 * 0xc);
          } while (iVar6 != -1);
        }
      }
    }
  }
LAB_104350ec:
  uStack_104 = (uint *)((int)uStack_104 + 1);
  uStack_120 = uStack_120 + 1;
  if (0x13 < (int)uStack_104) goto code_r0x1043510b;
  goto LAB_10434c80;
joined_r0x10434eae:
  if (iVar6 == -1) goto LAB_10434ec4;
  if (*(uint *)(iVar12 + 4 + iVar6 * 0xc) == uVar15) {
    piVar10 = *(int **)(iVar12 + 8 + iVar6 * 0xc);
    goto LAB_10434ec6;
  }
  iVar6 = *(int *)(iVar12 + iVar6 * 0xc);
  goto joined_r0x10434eae;
LAB_10434ec4:
  piVar10 = (int *)0x0;
LAB_10434ec6:
  if ((*piVar10 == 2) && (iVar6 = func_0x1030d04e(puVar14), *(int *)(iVar6 + 4) != 0)) {
    iVar6 = func_0x1030d04e(puVar14);
    iVar6 = *(int *)(iVar6 + 4);
    goto LAB_10434d3a;
  }
  goto LAB_10434d38;
code_r0x1043510b:
  pppuVar7[0x81] = pppuStack_110[0x81];
  pppuVar7[0x75] = pppuStack_110[0x75];
  pppuVar7[0x76] = pppuStack_110[0x76];
  pppuVar7[0x77] = pppuStack_110[0x77];
  pppuVar7[0x78] = pppuStack_110[0x78];
  pppuVar7[0x79] = pppuStack_110[0x79];
  pppuVar7[0x7a] = pppuStack_110[0x7a];
  pppuVar7[0x7b] = pppuStack_110[0x7b];
  pppuVar7[0x7c] = pppuStack_110[0x7c];
  pppuVar7[0x7d] = pppuStack_110[0x7d];
  pppuVar7[0x7e] = pppuStack_110[0x7e];
  pppuVar7[0x7f] = pppuStack_110[0x7f];
  pppuVar7[0x80] = pppuStack_110[0x80];
  pppuVar7[0xb5] = pppuStack_110[0xb5];
  if (_DAT_10b1f538 != 0) {
    ppuVar9 = pppuStack_110[6];
    pppuVar18 = pppuStack_110 + 6;
    iVar6 = *(int *)(*(int *)(_DAT_10b1f538 + 0x1a0) +
                    (*(int *)(_DAT_10b1f538 + 0x1a4) - 1U & (uint)ppuVar9) * 4);
    if (iVar6 != -1) {
      iVar12 = *(int *)(_DAT_10b1f538 + 0x194);
      do {
        if (*(uint ***)(iVar12 + 4 + iVar6 * 0xc) == ppuVar9) {
          if (*(int *)(iVar12 + 8 + iVar6 * 0xc) != 0) {
            iVar6 = *(int *)(*(int *)(_DAT_10b1f538 + 0x1a0) +
                            (*(int *)(_DAT_10b1f538 + 0x1a4) - 1U & (uint)ppuVar9) * 4);
            goto joined_r0x10435221;
          }
          break;
        }
        iVar6 = *(int *)(iVar12 + iVar6 * 0xc);
      } while (iVar6 != -1);
    }
  }
  goto LAB_1043526b;
joined_r0x10435221:
  if (iVar6 == -1) goto LAB_1043523b;
  if (*(uint ***)(iVar12 + 4 + iVar6 * 0xc) == ppuVar9) {
    piVar10 = *(int **)(iVar12 + 8 + iVar6 * 0xc);
    goto LAB_1043523d;
  }
  iVar6 = *(int *)(iVar12 + iVar6 * 0xc);
  goto joined_r0x10435221;
joined_r0x104357a5:
  if (iVar12 == -1) goto LAB_104357c4;
  if (*(uint *)(iVar3 + 4 + iVar12 * 0xc) == *unaff_ESI) {
    piVar10 = *(int **)(iVar3 + 8 + iVar12 * 0xc);
    goto LAB_104357c6;
  }
  iVar12 = *(int *)(iVar3 + iVar12 * 0xc);
  goto joined_r0x104357a5;
LAB_104357c4:
  piVar10 = (int *)0x0;
LAB_104357c6:
  if ((*piVar10 != 1) || (iVar12 = func_0x1030d04e(unaff_ESI), *(int *)(iVar12 + 4) == 0))
  goto LAB_10435764;
  iVar12 = func_0x1030d04e(unaff_ESI);
  uVar8 = *(undefined4 *)(iVar12 + 4);
  goto LAB_10435766;
LAB_1043523b:
  piVar10 = (int *)0x0;
LAB_1043523d:
  if (*piVar10 == 1) {
    uVar8 = func_0x1030d04e(pppuVar18);
    (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(uVar8);
    func_0x10304a34(pppuVar18);
  }
LAB_1043526b:
  pppuVar18 = pppuStack_110;
  (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))();
  uVar15 = *unaff_ESI;
  pppuVar7[2] = (uint **)0x0;
  pppuVar7[0x25] = (uint **)0x1;
  if ((0 < (int)uVar15) && (_DAT_10b1f538 != 0)) {
    iVar6 = func_0x1030d04e(unaff_ESI);
    if (iVar6 != 0) {
      (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(iVar6);
      func_0x10304a34(unaff_ESI);
    }
    ppppuStack_13c =
         (uint ****)(**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(8,0x10853a28);
    if (ppppuStack_13c == (uint ****)0x0) {
      ppppuStack_13c = (uint ****)0x0;
    }
    else {
      *ppppuStack_13c = (uint ***)0x0;
      ppppuStack_13c[1] = (uint ***)0x0;
    }
    uStack_20 = 0xffffffff;
    if (ppppuStack_13c != (uint ****)0x0) {
      ppppuStack_13c[1] = pppuVar7;
      *ppppuStack_13c = (uint ***)0x1;
    }
    func_0x1030a60f(unaff_ESI,&ppppuStack_13c);
  }
  if (pppuVar7[0x81] != (uint **)0x0) {
    pppuVar7[0x81][0x1bb] = (uint *)(float)(int)pppuVar7[0x67];
    pppuVar7[0x81][0x1bc] = (uint *)(float)(int)pppuVar7[0x68];
    pppuVar7[0x81][0x1bd] = (uint *)(float)(int)pppuVar7[0x69];
    pppuVar7[0x81][0x1be] = (uint *)(float)(int)pppuVar7[0x6a];
    pppuVar7[0x81][0x1bf] = (uint *)(float)(int)pppuVar7[0x6b];
    pppuVar7[0x81][0x1c0] = (uint *)(float)(int)pppuVar7[0x6c];
    if ((char)((uint)unaff_EBP >> 0x18) == '\0') {
      func_0x1030c3ab(pppuVar7[0x73],pppuVar7[0x74]);
    }
    puVar14 = pppuVar7[0x81][0x1a8];
    puVar11 = (uint *)func_0x10305394(10);
    pppuVar7[0x81][0x1a8] = puVar11;
    if (pppuVar7[0x81][0x1a8] == (uint *)0x0) {
      puVar11 = (uint *)func_0x10305394(0xb);
      pppuVar7[0x81][0x1a8] = puVar11;
    }
    if (pppuVar7[0x81][0x1a8] == (uint *)0x0) {
      puVar11 = (uint *)func_0x10305394(0xc);
      pppuVar7[0x81][0x1a8] = puVar11;
    }
    if (puVar14 != pppuVar7[0x81][0x1a8]) {
      pppuVar7[0x81][0x60b] = puVar14;
      ppuVar9 = pppuVar7[0x81];
      if (((-1 < (int)ppuVar9[0x1a8]) && (iVar6 = func_0x1030c04a(ppuVar9 + 0x1a8), iVar6 != 0)) &&
         (*(int *)(iVar6 + 4) == 0)) {
        if (*(int *)(iVar6 + 0x168) < 0) {
          ppuVar9[0x608] = (uint *)((uint)ppuVar9[0x608] & 0xfffffffd);
        }
        else {
          ppuVar9[0x608] = (uint *)((uint)ppuVar9[0x608] | 2);
        }
      }
    }
    puVar14 = (uint *)func_0x10305394(2);
    pppuVar7[0x81][0x1a9] = puVar14;
    puVar14 = (uint *)func_0x10305394(0xd);
    pppuVar7[0x81][0x1aa] = puVar14;
    fVar5 = (float)_DAT_1088ae20;
    pppuVar7[0x81][0x1ae] = (uint *)((float)(int)pppuVar7[0x8f] / fVar5);
    pppuVar7[0x81][0x1af] = (uint *)((float)(int)pppuVar7[0xab] / fVar5);
    pppuVar7[0x81][0x1ac] = (uint *)(float)*(double *)(pppuVar7 + 0x6f);
    ppppuStack_13c = (uint ****)(float)*(double *)(pppuVar7 + 0x71);
    pppuVar7[0x81][0x1ad] = (uint *)ppppuStack_13c;
    *(undefined1 *)(pppuVar7[0x81][0x536] + 0x10d) = puStack_f8._0_1_;
    ppuVar9 = pppuVar7[0x81];
    if ((char)ppuVar9[0x536][0x10d] == '\x01') {
      ppuVar9[0x554] = (uint *)((float)ppuVar9[0x1bb] * (float)ppuVar9[0x1ad]);
      ppuVar9 = pppuVar7[0x81];
      ppuVar9[0x555] = (uint *)((float)ppuVar9[0x1bd] * (float)ppuVar9[0x1ad]);
      ppuVar9 = pppuVar7[0x81];
      puVar14 = ppuVar9[0x1bf];
    }
    else {
      ppuVar9[0x554] = (uint *)((float)ppuVar9[0x1bc] * (float)ppuVar9[0x1ad]);
      ppuVar9 = pppuVar7[0x81];
      ppuVar9[0x555] = (uint *)((float)ppuVar9[0x1be] * (float)ppuVar9[0x1ad]);
      ppuVar9 = pppuVar7[0x81];
      puVar14 = ppuVar9[0x1c0];
    }
    ppuVar9[0x556] = (uint *)((float)puVar14 * (float)ppuVar9[0x1ad]);
    sVar16 = *(short *)(pppuVar7 + 0xac);
    if (((sVar16 == 1) || (sVar16 == 3)) || ((sVar16 == 5 || ((sVar16 == 7 || (sVar16 == 8)))))) {
      func_0x1030bef6();
      if (*(short *)(pppuVar7 + 0xac) == 7) {
        pppuVar7[0x81][0x18b] = (uint *)0xa;
      }
      else {
        pppuVar7[0x81][0x18b] = (uint *)0x9;
      }
      pppuVar7[0x81][399] = (uint *)pppuVar7[0x81];
    }
    if ((*(short *)(pppuVar7 + 0xac) == 0) && (pppuVar7[0x81][0x18b] == (uint *)0x9)) {
      func_0x1030bef6();
    }
    if ((pppuVar7[0x81][0x1c6] != (uint *)0x0) && ((pppuVar7[0x81][0x1c6][0x1c5] & 1) != 0)) {
      func_0x1030a871(0,0);
    }
    func_0x1030a871(unaff_ESI,uStack_11c);
    pppuVar7[0x81][0x5f4] = uStack_104;
    pppuVar7[0x81][0x1de] = (uint *)(int)(char)iStack_108;
    puVar14 = (uint *)func_0x10303742(uStack_70);
    pppuVar7[0x81][0x60a] = puVar14;
    pppuVar7[0x81][0x60c] = (uint *)pppuVar7[0xba];
    ppuVar9 = pppuVar7[0x81] + 0x608;
    *ppuVar9 = (uint *)((uint)*ppuVar9 ^ ((uint)pppuVar7[0x81][0x608] ^ (uint)pppuVar7[0xbf]) & 1);
  }
  iVar6 = _DAT_10b1f538;
  if (_DAT_10b1f538 != 0) {
    iVar12 = *(int *)(*(int *)(_DAT_10b1f538 + 0x1a0) +
                     (*(int *)(_DAT_10b1f538 + 0x1a4) - 1U & *unaff_ESI) * 4);
    if (iVar12 != -1) {
      iVar3 = *(int *)(_DAT_10b1f538 + 0x194);
      do {
        if (*(uint *)(iVar3 + 4 + iVar12 * 0xc) == *unaff_ESI) {
          if (*(int *)(iVar3 + 8 + iVar12 * 0xc) != 0) {
            iVar12 = *(int *)(*(int *)(_DAT_10b1f538 + 0x1a0) +
                             (*(int *)(_DAT_10b1f538 + 0x1a4) - 1U & *unaff_ESI) * 4);
            goto joined_r0x104357a5;
          }
          break;
        }
        iVar12 = *(int *)(iVar3 + iVar12 * 0xc);
      } while (iVar12 != -1);
    }
  }
LAB_10435764:
  uVar8 = 0;
LAB_10435766:
  (**(code **)(**(int **)(iVar6 + 0x54) + 0x170))(uVar8,0,0);
LAB_10435c34:
  ppuVar9 = pppuVar7[0x81];
  if (ppuVar9 != (uint **)0x0) {
    ppuVar9[0x608] =
         (uint *)((uint)ppuVar9[0x608] ^ ((int)pppuVar7[0xc0] * 4 ^ (uint)ppuVar9[0x608]) & 4);
    pppuVar7[0x81][0x609] = (uint *)pppuVar7[0xc1];
  }
  func_0x103022f7(pppuVar7[0xbb]);
  if (0 < (int)pppuVar7[0xa1]) {
    func_0x10303df5(pppuVar7[0xa1],pppuVar7[0xa2],pppuVar7[0xa3],pppuVar7[0xa4],pppuVar7[0xa8],
                    0x80000000);
  }
  pppuVar7[0xa6] = (uint **)((uint)pppuVar7[0xa5] >> 6 & 1);
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x4ec))();
  if (0 < unaff_DI) {
    (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(uStack_120);
  }
  if (pppuStack_dc != (uint ***)0x0) {
    (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x720))
              (pppuVar7[0x81],0,uStack_c8,uStack_c4,iStack_c0,0,0);
  }
  func_0x1030aa47();
  func_0x103095e8();
  (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x6f0))(pppuVar7);
  uVar15 = _Logf_FOutputDevice__QAAXPBGZZ
                     (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x1088ad00,*pppuVar18,
                      fStack_f0,*puStack_f8,*pppuStack_ec,fStack_fc,uStack_e8,fStack_f4);
  *unaff_FS_OFFSET = uStack_30;
  return uVar15 & 0xffffff00;
}

