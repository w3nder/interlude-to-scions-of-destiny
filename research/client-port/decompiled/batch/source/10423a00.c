
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10423a00(void)

{
  float fVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  byte *pbVar6;
  int *piVar7;
  int *piVar8;
  uint *puVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  float *pfVar13;
  uint *puVar14;
  uint *unaff_EBX;
  short sVar15;
  undefined4 unaff_EBP;
  int unaff_ESI;
  undefined4 *puVar16;
  int unaff_EDI;
  undefined4 *puVar17;
  undefined4 unaff_retaddr;
  undefined4 *puStack_118;
  undefined *puStack_114;
  undefined4 *puStack_100;
  int *piStack_fc;
  undefined4 *puStack_f8;
  short asStack_f4 [2];
  undefined4 uStack_f0;
  uint *puStack_ec;
  char cStack_e8;
  int iStack_e4;
  undefined4 uStack_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  int iStack_d0;
  undefined4 *puStack_cc;
  int *piStack_c8;
  undefined4 uStack_c4;
  int iStack_c0;
  undefined4 uStack_bc;
  undefined4 *puStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 *puStack_ac;
  undefined4 *puStack_a8;
  int aiStack_a4 [2];
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  int iStack_90;
  int iStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  uint uStack_70;
  uint uStack_6c;
  undefined1 auStack_68 [4];
  undefined1 auStack_64 [4];
  undefined1 auStack_60 [4];
  undefined4 uStack_5c;
  undefined1 auStack_58 [4];
  undefined1 auStack_54 [4];
  undefined4 uStack_50;
  undefined1 auStack_4c [4];
  undefined1 auStack_48 [4];
  undefined1 auStack_44 [4];
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [4];
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [8];
  undefined1 auStack_2c [8];
  double dStack_24;
  double dStack_1c;
  undefined1 auStack_14 [16];
  int iStack_4;
  
  puVar16 = (undefined4 *)0x0;
  puStack_ec = (uint *)0x0;
  puStack_114 = &UNK_107c7c30;
  puStack_118 = (undefined4 *)0x248;
  fStack_dc = 0.0;
  iVar4 = (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)();
  if (iVar4 != 0) {
    puVar16 = (undefined4 *)func_0x10302d06();
  }
  puStack_a8 = puVar16 + 0x14;
  puStack_ac = puVar16 + 0x13;
  puStack_b8 = puVar16 + 7;
  piStack_fc = puVar16 + 6;
  puVar17 = puVar16;
  for (iVar4 = 0x92; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar17 = 0;
    puVar17 = puVar17 + 1;
  }
  puVar14 = puVar16 + 0x25;
  uVar5 = func_0x10305079(*(undefined4 *)(iStack_4 + 0x48),unaff_retaddr,&UNK_107c7bb8,&puStack_cc,
                          &iStack_d0,&iStack_c0,&puStack_f8,piStack_fc,0x30,puStack_b8,puStack_ac,
                          puStack_a8,puVar16 + 0x15,puVar16 + 0x16,puVar16 + 0x17,puVar16 + 0x18,
                          puVar16 + 0x19,puVar16 + 0x1a,puVar16 + 0x1b,puVar16 + 0x1c,puVar16 + 0x1d
                          ,puVar16 + 0x1e,puVar16 + 0x1f,puVar16 + 0x20,puVar16 + 0x21,
                          puVar16 + 0x5a,puVar16 + 0x59,puVar16 + 0x22,puVar16 + 0x23,puVar14,
                          puVar16 + 0x26,puVar16 + 0x27,puVar16 + 0x28,puVar16 + 0x29,puVar16 + 0x2a
                          ,puVar16 + 0x2b,puVar16 + 0x2c,puVar16 + 0x2d,puVar16 + 0x2e,
                          puVar16 + 0x2f,puVar16 + 0x30,puVar16 + 0x31,puVar16 + 0x32,puVar16 + 0x33
                          ,puVar16 + 0x35,&uStack_6c,auStack_68,auStack_64,auStack_60,&uStack_5c,
                          auStack_58,auStack_54,&uStack_50,auStack_4c,auStack_48,auStack_44,
                          auStack_40,auStack_3c,auStack_38,auStack_34,auStack_2c,puVar16 + 0x5d,
                          puVar16 + 0x5e,puVar16 + 0x5f,puVar16 + 0x60,puVar16 + 0x5b,puVar16 + 0x5c
                          ,puVar16 + 0x61,puVar16 + 99,puVar16 + 0x7f,puVar16 + 0x62,puVar16 + 0x3a,
                          puVar16 + 0x3b,puVar16 + 0x3c,puVar16 + 0x3d,puVar16 + 0x3e,puVar16 + 0x3f
                          ,puVar16 + 0x42,puVar16 + 0x43,puVar16 + 0x40,puVar16 + 0x41,&uStack_80,
                          &uStack_88,&dStack_24,&dStack_1c,puVar16 + 100,puVar16 + 0x65,
                          puVar16 + 0x66,puVar16 + 0x68,0x30,puVar16 + 0x69,puVar16 + 0x75,
                          puVar16 + 0x76,puVar16 + 0x77,puVar16 + 0x78,puVar16 + 0x79,
                          &stack0xfffffeff,puVar16 + 0x80,puVar16 + 0x7e,puVar16 + 0x81,
                          puVar16 + 0x82,asStack_f4);
  sVar3 = asStack_f4[0];
  if (0 < sVar3) {
    iStack_e4 = (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)
                          (sVar3 * 2 + 2,&UNK_10792bd0);
    sVar3 = asStack_f4[0];
  }
  sVar15 = 0;
  if (0 < sVar3) {
    do {
      uVar5 = func_0x10305079(*(undefined4 *)(iStack_4 + 0x48),uVar5,&UNK_107c1644,
                              iStack_e4 + sVar15 * 2);
      sVar15 = sVar15 + 1;
    } while (sVar15 < asStack_f4[0]);
  }
  uVar5 = func_0x10305079(*(undefined4 *)(iStack_4 + 0x48),uVar5,&UNK_107bd86c,puVar16 + 0x83);
  uStack_c4 = 0;
  uStack_b0 = 0;
  aiStack_a4[1] = 0;
  pbVar6 = (byte *)func_0x10305079(*(undefined4 *)(iStack_4 + 0x48),uVar5,&UNK_107c1074,&uStack_c4,
                                   &piStack_c8);
  if (0 < (int)puVar16[0x75]) {
    if (puVar16[0x7a] == 0) {
      *(byte *)(puVar16 + 0x8a) = *pbVar6 & 1;
      *(byte *)((int)puVar16 + 0x229) = *pbVar6 >> 1 & 1;
      *(byte *)((int)puVar16 + 0x22a) = *pbVar6 >> 3 & 1;
      *(byte *)((int)puVar16 + 0x22b) = pbVar6[1] >> 2 & 1;
    }
    else {
      *(undefined1 *)(puVar16 + 0x8a) = 1;
      *(undefined1 *)((int)puVar16 + 0x229) = 1;
      *(undefined1 *)((int)puVar16 + 0x22a) = 1;
    }
  }
  uVar5 = func_0x10305079(*(undefined4 *)(iStack_4 + 0x48),pbVar6 + 0x20,&UNK_107c3680,
                          puVar16 + 0x8b,(int)puVar16 + 0x22e,&uStack_b0,puVar16 + 0x8c);
  uVar5 = func_0x10305079(*(undefined4 *)(iStack_4 + 0x48),uVar5,&UNK_107c4840,puVar16 + 0x84,
                          aiStack_a4 + 1,puVar16 + 0x85,puVar16 + 0x86,(int)&uStack_f0 + 3);
  uVar5 = func_0x10305079(*(undefined4 *)(iStack_4 + 0x48),uVar5,&UNK_107bd86c,puVar16 + 0x8e);
  uVar5 = func_0x10305079(*(undefined4 *)(iStack_4 + 0x48),uVar5,&UNK_107c7a2c,puVar16 + 0x7c,
                          puVar16 + 0x8f,puVar16 + 0x90);
  uStack_bc = 0;
  uVar5 = func_0x10305079(*(undefined4 *)(iStack_4 + 0x48),uVar5,&UNK_107bd8cc,&uStack_bc,aiStack_a4
                          ,&iStack_8c,&iStack_90);
  fStack_9c = (float)aiStack_a4[0];
  puVar9 = puVar16 + 0x91;
  fStack_98 = (float)iStack_8c;
  fStack_94 = (float)iStack_90;
  func_0x10305079(*(undefined4 *)(iStack_4 + 0x48),uVar5,&UNK_107bde9c,puVar9);
  piVar10 = piStack_fc;
  *puVar9 = (((byte)*puVar9 | 0xffffff00) << 8 | (uint)*(byte *)((int)puVar16 + 0x245)) << 8 |
            (uint)*(byte *)((int)puVar16 + 0x246);
  puVar16[0x44] = uStack_88;
  puVar16[0x45] = uStack_84;
  puVar16[0x46] = uStack_80;
  puVar16[0x47] = uStack_7c;
  puVar16[0x48] = (float)dStack_24;
  puVar16[0x49] = (float)dStack_1c;
  puVar16[0x8d] = (int)uStack_f0._3_1_;
  if ((((_DAT_109d5e68 == 0) || (iVar4 = func_0x1030f3bc(piStack_fc), iVar4 == 0)) ||
      (piVar7 = (int *)func_0x1030f3bc(piVar10), *piVar7 != 1)) ||
     ((iVar4 = func_0x1030f3bc(piVar10), *(int *)(iVar4 + 4) == 0 ||
      (iVar4 = func_0x1030f3bc(piVar10), *(int *)(iVar4 + 4) == 0)))) {
    iVar4 = 0;
    do {
      if (*puVar14 != 0) {
        puVar9 = (uint *)(**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)
                                   (0x18,&UNK_10792bd0);
        *puVar9 = *puVar14;
        puVar9[1] = *(uint *)(auStack_68 + iVar4 * 4 + -4);
        puVar9[4] = 0;
        puVar9[5] = 0;
        if ((0 < (int)*puVar14) && (_DAT_109d5e68 != 0)) {
          iVar11 = func_0x1030f3bc(puVar14);
          if (iVar11 != 0) {
            (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(iVar11);
            func_0x1030720c(puVar14);
          }
          puStack_f8 = (undefined4 *)
                       (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(8,&UNK_10792bd0)
          ;
          if (puStack_f8 == (undefined4 *)0x0) {
            puStack_f8 = (undefined4 *)0x0;
          }
          else {
            *puStack_f8 = 0;
            puStack_f8[1] = 0;
          }
          if (puStack_f8 != (undefined4 *)0x0) {
            puStack_f8[1] = puVar9;
            *puStack_f8 = 2;
          }
          func_0x1030cb1c(puVar14,&puStack_f8);
        }
      }
      piVar10 = piStack_fc;
      iVar4 = iVar4 + 1;
      puVar14 = puVar14 + 1;
    } while (iVar4 < 0x12);
    iVar4 = *piStack_fc;
    puVar16[2] = 0;
    puVar16[0x24] = 1;
    if ((0 < iVar4) && (_DAT_109d5e68 != 0)) {
      iVar4 = func_0x1030f3bc(piStack_fc);
      if (iVar4 != 0) {
        (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(iVar4);
        func_0x1030720c(piVar10);
      }
      puStack_f8 = (undefined4 *)
                   (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(8,&UNK_10792bd0);
      if (puStack_f8 == (undefined4 *)0x0) {
        puStack_f8 = (undefined4 *)0x0;
      }
      else {
        *puStack_f8 = 0;
        puStack_f8[1] = 0;
      }
      if (puStack_f8 != (undefined4 *)0x0) {
        puStack_f8[1] = puVar16;
        *puStack_f8 = 1;
      }
      func_0x1030cb1c(piVar10,&puStack_f8);
    }
    _DAT_109d5e60 = *piVar10;
    fStack_dc = (float)(int)puStack_cc;
    fStack_d8 = (float)iStack_d0;
    fStack_d4 = (float)iStack_c0;
    if (0 < (int)puStack_f8) {
      if (_DAT_109d5e68 != 0) {
        iVar4 = *(int *)(*(int *)(_DAT_109d5e68 + 0x1a0) +
                        (*(int *)(_DAT_109d5e68 + 0x1a4) - 1U & (uint)puStack_f8) * 4);
        if (iVar4 != -1) {
          iVar11 = *(int *)(_DAT_109d5e68 + 0x194);
          do {
            if (*(undefined4 **)(iVar11 + 4 + iVar4 * 0xc) == puStack_f8) {
              if ((((*(int *)(iVar11 + 8 + iVar4 * 0xc) != 0) &&
                   (piVar10 = (int *)func_0x1030f3bc(&puStack_f8), *piVar10 == 3)) &&
                  (iVar4 = func_0x1030f3bc(&puStack_f8), *(int *)(iVar4 + 4) != 0)) &&
                 (iVar4 = func_0x1030f3bc(&puStack_f8), *(int *)(iVar4 + 4) != 0)) {
                iVar4 = func_0x1030f3bc(&puStack_f8);
                if (((iVar4 == 0) || (piVar10 = (int *)func_0x1030f3bc(&puStack_f8), *piVar10 != 3))
                   || (iVar4 = func_0x1030f3bc(&puStack_f8), *(int *)(iVar4 + 4) == 0)) {
                  iVar4 = 0;
                }
                else {
                  iVar4 = func_0x1030f3bc(&puStack_f8);
                  iVar4 = *(int *)(iVar4 + 4);
                }
                uStack_78 = 0;
                uStack_74 = 0;
                uStack_70 = 0x3f800000;
                pfVar13 = (float *)_RotateAngleAxis_FVector__QBE_AV1_HABV1__Z
                                             (auStack_14,
                                              *(uint *)(*(int *)(iVar4 + 4) + 0x1cc) & 0xffff,
                                              &uStack_78);
                iVar4 = *(int *)(iVar4 + 4);
                fStack_dc = *pfVar13 + *(float *)(iVar4 + 0x1bc);
                fStack_d8 = pfVar13[1] + *(float *)(iVar4 + 0x1c0);
                fStack_d4 = pfVar13[2] + *(float *)(iVar4 + 0x1c4);
                goto LAB_10424c5b;
              }
              break;
            }
            iVar4 = *(int *)(iVar11 + iVar4 * 0xc);
          } while (iVar4 != -1);
        }
      }
      _Logf_FOutputDevice__QAAXPBGZZ
                (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c7b30);
      (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c7b30);
    }
LAB_10424c5b:
    puVar16[0x56] = 0;
    piVar7 = piStack_c8;
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x38))
              (puVar16,fStack_dc,fStack_d8,fStack_d4,0,(int)(char)((uint)unaff_EBX >> 0x18),
               uStack_b0);
    sVar3 = *(short *)(puVar16 + 0x80);
    if (((sVar3 == 1) || (sVar3 == 3)) || ((sVar3 == 5 || ((sVar3 == 7 || (sVar3 == 8)))))) {
      func_0x1030e2c8();
      if (*(short *)(puVar16 + 0x80) == 7) {
        *(undefined4 *)(puVar16[0x56] + 0x578) = 9;
      }
      else {
        *(undefined4 *)(puVar16[0x56] + 0x578) = 8;
      }
      *(undefined4 *)(puVar16[0x56] + 0x588) = puVar16[0x56];
    }
    if ((*(int *)(puVar16[0x56] + 0x660) == 0) || ((short)puStack_114 == 0)) {
      func_0x1030cd56(puStack_114,unaff_EBX);
    }
    *(int *)(puVar16[0x56] + 0x16c0) = iStack_e4;
    *(int *)(puVar16[0x56] + 0x6b0) = (int)cStack_e8;
    uVar5 = func_0x1030554c(uStack_5c);
    *(undefined4 *)(puVar16[0x56] + 0x1714) = uVar5;
    *(undefined4 *)(puVar16[0x56] + 0x171c) = puVar16[0x8d];
    iVar4 = puVar16[0x56];
    *(uint *)(iVar4 + 0x1710) =
         *(uint *)(iVar4 + 0x1710) ^ (*(uint *)(iVar4 + 0x1710) ^ puVar16[0x90]) & 1;
    goto LAB_10424ed0;
  }
  piVar7 = piVar10;
  iVar4 = func_0x1030f3bc();
  if (((iVar4 == 0) || (piVar8 = (int *)func_0x1030f3bc(piVar10), *piVar8 != 1)) ||
     (iVar4 = func_0x1030f3bc(piVar10), *(int *)(iVar4 + 4) == 0)) {
    puStack_b8 = (undefined4 *)0x0;
  }
  else {
    iVar4 = func_0x1030f3bc(piVar10);
    puStack_b8 = *(undefined4 **)(iVar4 + 4);
  }
  uStack_f0 = (int)puStack_b8 - (int)puVar16;
  iStack_e4 = 0;
  do {
    iVar4 = _DAT_109d5e68;
    unaff_EBX = (uint *)(uStack_f0 + (int)puVar14);
    uVar12 = *unaff_EBX;
    puStack_ec = puVar14;
    if ((uVar12 != 0) || (*puVar14 != 0)) {
      if (_DAT_109d5e68 != 0) {
        iVar11 = *(int *)(*(int *)(_DAT_109d5e68 + 0x1a0) +
                         (*(int *)(_DAT_109d5e68 + 0x1a4) - 1U & uVar12) * 4);
        if (iVar11 != -1) {
          iVar2 = *(int *)(_DAT_109d5e68 + 0x194);
          do {
            if (*(uint *)(iVar2 + 4 + iVar11 * 0xc) == uVar12) {
              if (((*(int *)(iVar2 + 8 + iVar11 * 0xc) != 0) &&
                  (piVar10 = (int *)func_0x1030f3bc(unaff_EBX), *piVar10 == 2)) &&
                 (iVar11 = func_0x1030f3bc(unaff_EBX), *(int *)(iVar11 + 4) != 0)) {
                iVar11 = func_0x1030f3bc(unaff_EBX);
                unaff_ESI = *(int *)(iVar11 + 4);
                goto LAB_104240e0;
              }
              break;
            }
            iVar11 = *(int *)(iVar2 + iVar11 * 0xc);
          } while (iVar11 != -1);
        }
      }
      unaff_ESI = 0;
LAB_104240e0:
      puVar14 = puStack_ec;
      if (iVar4 != 0) {
        iVar11 = *(int *)(*(int *)(iVar4 + 0x1a0) + (*(int *)(iVar4 + 0x1a4) - 1U & *puStack_ec) * 4
                         );
        if (iVar11 != -1) {
          iVar4 = *(int *)(iVar4 + 0x194);
          do {
            if (*(uint *)(iVar4 + 4 + iVar11 * 0xc) == *puStack_ec) {
              if (((*(int *)(iVar4 + 8 + iVar11 * 0xc) != 0) &&
                  (piVar10 = (int *)func_0x1030f3bc(puStack_ec), *piVar10 == 2)) &&
                 (iVar4 = func_0x1030f3bc(puVar14), *(int *)(iVar4 + 4) != 0)) {
                iVar4 = func_0x1030f3bc(puVar14);
                iVar4 = *(int *)(iVar4 + 4);
                goto LAB_10424130;
              }
              break;
            }
            iVar11 = *(int *)(iVar4 + iVar11 * 0xc);
          } while (iVar11 != -1);
        }
      }
      iVar4 = 0;
      puVar14 = puStack_ec;
LAB_10424130:
      if (((unaff_ESI == 0) || (iVar4 == 0)) || (puVar14 = puStack_ec, unaff_ESI != iVar4)) {
        if ((*puVar14 != 0) && (iVar4 == 0)) {
          puVar9 = (uint *)(**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)
                                     (0x18,&UNK_10792bd0);
          *puVar9 = *puVar14;
          puVar9[1] = (&uStack_70)[iStack_e4];
          puVar9[4] = 0;
          puVar9[5] = 0;
          if ((0 < (int)*puVar14) && (_DAT_109d5e68 != 0)) {
            iVar4 = func_0x1030f3bc(puVar14);
            if (iVar4 != 0) {
              (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(iVar4);
              func_0x1030720c(puVar14);
            }
            puStack_118 = (undefined4 *)
                          (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)
                                    (8,&UNK_10792bd0);
            if (puStack_118 == (undefined4 *)0x0) {
              puStack_118 = (undefined4 *)0x0;
            }
            else {
              *puStack_118 = 0;
              puStack_118[1] = 0;
            }
            if (puStack_118 != (undefined4 *)0x0) {
              puStack_118[1] = puVar9;
              *puStack_118 = 2;
            }
            func_0x1030cb1c(puVar14,&puStack_118);
          }
        }
        uVar12 = *puVar14;
        if (unaff_ESI == 0) {
          if ((0 < (int)uVar12) && (*unaff_EBX != uVar12)) {
            (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0xa8))((&uStack_70)[iStack_e4]);
          }
        }
        else {
          if (((int)uVar12 < 1) || (*unaff_EBX == uVar12)) {
            if (uVar12 == 0) {
              uVar12 = *(uint *)(unaff_ESI + 4);
              goto LAB_104242e8;
            }
          }
          else {
            uVar12 = (&uStack_70)[iStack_e4];
LAB_104242e8:
            (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0xa8))(uVar12);
          }
          if ((((_DAT_109d5e68 == 0) || (iVar4 = func_0x1030f3bc(unaff_EBX), iVar4 == 0)) ||
              (piVar10 = (int *)func_0x1030f3bc(unaff_EBX), *piVar10 != 2)) ||
             (iVar4 = func_0x1030f3bc(unaff_EBX), *(int *)(iVar4 + 4) == 0)) {
            uVar5 = 0;
          }
          else {
            iVar4 = func_0x1030f3bc(unaff_EBX);
            uVar5 = *(undefined4 *)(iVar4 + 4);
          }
          (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(uVar5);
          if (((_DAT_109d5e68 != 0) && (iVar4 = func_0x1030f3bc(unaff_EBX), iVar4 != 0)) &&
             (piVar10 = (int *)func_0x1030f3bc(unaff_EBX), *piVar10 == 2)) {
            unaff_ESI = **(int **)_GMalloc__3PAVFMalloc__A_exref;
            uVar5 = func_0x1030f3bc(unaff_EBX);
            (**(code **)(unaff_EDI + 8))(uVar5);
            func_0x1030720c(unaff_EBX);
          }
        }
      }
    }
    puVar17 = puStack_b8;
    iStack_e4 = iStack_e4 + 1;
    puVar14 = puStack_ec + 1;
  } while (iStack_e4 < 0x12);
  puVar16[0x56] = puStack_b8[0x56];
  puVar16[0x4a] = puStack_b8[0x4a];
  puVar16[0x4b] = puStack_b8[0x4b];
  puVar16[0x4c] = puStack_b8[0x4c];
  puVar16[0x4d] = puStack_b8[0x4d];
  puVar16[0x4e] = puStack_b8[0x4e];
  puVar16[0x4f] = puStack_b8[0x4f];
  puVar16[0x50] = puStack_b8[0x50];
  puVar16[0x51] = puStack_b8[0x51];
  puVar16[0x52] = puStack_b8[0x52];
  puVar16[0x53] = puStack_b8[0x53];
  puVar16[0x54] = puStack_b8[0x54];
  puVar16[0x55] = puStack_b8[0x55];
  puVar16[0x89] = puStack_b8[0x89];
  puStack_ec = puVar14;
  if (_DAT_109d5e68 != 0) {
    iVar4 = *(int *)(*(int *)(_DAT_109d5e68 + 0x1a0) +
                    (*(int *)(_DAT_109d5e68 + 0x1a4) - 1U & puStack_b8[6]) * 4);
    if (iVar4 != -1) {
      iVar11 = *(int *)(_DAT_109d5e68 + 0x194);
      do {
        if (*(uint *)(iVar11 + 4 + iVar4 * 0xc) == puStack_b8[6]) {
          if (*(int *)(iVar11 + 8 + iVar4 * 0xc) != 0) {
            iVar4 = *(int *)(*(int *)(_DAT_109d5e68 + 0x1a0) +
                            (*(int *)(_DAT_109d5e68 + 0x1a4) - 1U & puStack_b8[6]) * 4);
            if (iVar4 == -1) goto LAB_10424517;
            iVar11 = *(int *)(_DAT_109d5e68 + 0x194);
            goto LAB_10424500;
          }
          break;
        }
        iVar4 = *(int *)(iVar11 + iVar4 * 0xc);
      } while (iVar4 != -1);
    }
  }
  goto LAB_1042454c;
  while (iVar11 = *(int *)(iVar2 + iVar11 * 0xc), iVar11 != -1) {
LAB_104249f0:
    if (*(uint *)(iVar2 + 4 + iVar11 * 0xc) == *unaff_EBX) {
      piVar10 = *(int **)(iVar2 + 8 + iVar11 * 0xc);
      goto LAB_10424a05;
    }
  }
LAB_10424a03:
  piVar10 = (int *)0x0;
LAB_10424a05:
  if ((*piVar10 != 1) || (iVar11 = func_0x1030f3bc(unaff_EBX), *(int *)(iVar11 + 4) == 0))
  goto LAB_104249b5;
  iVar11 = func_0x1030f3bc(unaff_EBX);
  uVar5 = *(undefined4 *)(iVar11 + 4);
  goto LAB_104249b7;
  while (iVar4 = *(int *)(iVar11 + iVar4 * 0xc), iVar4 != -1) {
LAB_10424500:
    if (*(uint *)(iVar11 + 4 + iVar4 * 0xc) == puStack_b8[6]) {
      piVar10 = *(int **)(iVar11 + 8 + iVar4 * 0xc);
      goto LAB_10424519;
    }
  }
LAB_10424517:
  piVar10 = (int *)0x0;
LAB_10424519:
  if (*piVar10 == 1) {
    iVar4 = **(int **)_GMalloc__3PAVFMalloc__A_exref;
    uVar5 = func_0x1030f3bc(puStack_b8 + 6);
    (**(code **)(iVar4 + 8))(uVar5);
    func_0x1030720c(puVar17 + 6);
  }
LAB_1042454c:
  (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(puVar17);
  uVar12 = *unaff_EBX;
  puVar16[2] = 0;
  puVar16[0x24] = 1;
  if ((0 < (int)uVar12) && (_DAT_109d5e68 != 0)) {
    iVar4 = func_0x1030f3bc(unaff_EBX);
    if (iVar4 != 0) {
      (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(iVar4);
      func_0x1030720c(unaff_EBX);
    }
    puStack_100 = (undefined4 *)
                  (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(8,&UNK_10792bd0);
    if (puStack_100 == (undefined4 *)0x0) {
      puStack_100 = (undefined4 *)0x0;
    }
    else {
      *puStack_100 = 0;
      puStack_100[1] = 0;
    }
    if (puStack_100 != (undefined4 *)0x0) {
      puStack_100[1] = puVar16;
      *puStack_100 = 1;
    }
    func_0x1030cb1c(unaff_EBX,&puStack_100);
  }
  if (puVar16[0x56] != 0) {
    *(float *)(puVar16[0x56] + 0x634) = (float)(int)puVar16[0x3c];
    *(float *)(puVar16[0x56] + 0x638) = (float)(int)puVar16[0x3d];
    *(float *)(puVar16[0x56] + 0x63c) = (float)(int)puVar16[0x3e];
    *(float *)(puVar16[0x56] + 0x640) = (float)(int)puVar16[0x3f];
    *(float *)(puVar16[0x56] + 0x644) = (float)(int)puVar16[0x40];
    *(float *)(puVar16[0x56] + 0x648) = (float)(int)puVar16[0x41];
    if ((char)((uint)unaff_ESI >> 0x18) == '\0') {
      func_0x1030e732(puVar16[0x48],puVar16[0x49]);
    }
    iVar4 = *(int *)(puVar16[0x56] + 0x5e8);
    uVar5 = func_0x10307b44(8);
    *(undefined4 *)(puVar16[0x56] + 0x5e8) = uVar5;
    if (*(int *)(puVar16[0x56] + 0x5e8) == 0) {
      uVar5 = func_0x10307b44(9);
      *(undefined4 *)(puVar16[0x56] + 0x5e8) = uVar5;
    }
    if (*(int *)(puVar16[0x56] + 0x5e8) == 0) {
      uVar5 = func_0x10307b44(10);
      *(undefined4 *)(puVar16[0x56] + 0x5e8) = uVar5;
    }
    if (iVar4 != *(int *)(puVar16[0x56] + 0x5e8)) {
      *(int *)(puVar16[0x56] + 0x1718) = iVar4;
      iVar4 = puVar16[0x56];
      if (((-1 < *(int *)(iVar4 + 0x5e8)) && (iVar11 = func_0x1030e421(iVar4 + 0x5e8), iVar11 != 0))
         && (*(int *)(iVar11 + 4) == 0)) {
        if (*(int *)(iVar11 + 0x110) < 0) {
          uVar12 = *(uint *)(iVar4 + 0x1710) & 0xfffffffd;
        }
        else {
          uVar12 = *(uint *)(iVar4 + 0x1710) | 2;
        }
        *(uint *)(iVar4 + 0x1710) = uVar12;
      }
    }
    uVar5 = func_0x10307b44(2);
    *(undefined4 *)(puVar16[0x56] + 0x5ec) = uVar5;
    uVar5 = func_0x10307b44(0xb);
    *(undefined4 *)(puVar16[0x56] + 0x5f0) = uVar5;
    *(float *)(puVar16[0x56] + 0x600) = (float)(int)puVar16[99] * _DAT_107c7a08;
    *(float *)(puVar16[0x56] + 0x604) = (float)(int)puVar16[0x7f] * _DAT_107c7a08;
    *(float *)(puVar16[0x56] + 0x5f8) = (float)*(double *)(puVar16 + 0x44);
    *(float *)(puVar16[0x56] + 0x5fc) = (float)*(double *)(puVar16 + 0x46);
    iVar4 = puVar16[0x56];
    if (*(char *)(*(int *)(iVar4 + 0x13f0) + 0x41c) == '\x01') {
      *(float *)(iVar4 + 0x1468) = *(float *)(iVar4 + 0x634) * *(float *)(iVar4 + 0x5fc);
      iVar4 = puVar16[0x56];
      *(float *)(iVar4 + 0x146c) = *(float *)(iVar4 + 0x63c) * *(float *)(iVar4 + 0x5fc);
      iVar4 = puVar16[0x56];
      fVar1 = *(float *)(iVar4 + 0x644);
    }
    else {
      *(float *)(iVar4 + 0x1468) = *(float *)(iVar4 + 0x638) * *(float *)(iVar4 + 0x5fc);
      iVar4 = puVar16[0x56];
      *(float *)(iVar4 + 0x146c) = *(float *)(iVar4 + 0x640) * *(float *)(iVar4 + 0x5fc);
      iVar4 = puVar16[0x56];
      fVar1 = *(float *)(iVar4 + 0x648);
    }
    *(float *)(iVar4 + 0x1470) = fVar1 * *(float *)(iVar4 + 0x5fc);
    sVar3 = *(short *)(puVar16 + 0x80);
    if (((sVar3 == 1) || (sVar3 == 3)) || ((sVar3 == 5 || ((sVar3 == 7 || (sVar3 == 8)))))) {
      func_0x1030e2c8();
      if (*(short *)(puVar16 + 0x80) == 7) {
        *(undefined4 *)(puVar16[0x56] + 0x578) = 9;
      }
      else {
        *(undefined4 *)(puVar16[0x56] + 0x578) = 8;
      }
      *(undefined4 *)(puVar16[0x56] + 0x588) = puVar16[0x56];
    }
    if ((*(int *)(puVar16[0x56] + 0x660) == 0) || ((short)unaff_EBP == 0)) {
      func_0x1030cd56(unaff_EBP,puStack_f8);
    }
    *(float *)(puVar16[0x56] + 0x16c0) = fStack_d8;
    *(int *)(puVar16[0x56] + 0x6b0) = (int)fStack_dc._0_1_;
    uVar5 = func_0x1030554c(uStack_50);
    *(undefined4 *)(puVar16[0x56] + 0x1714) = uVar5;
    *(undefined4 *)(puVar16[0x56] + 0x171c) = puVar16[0x8d];
    iVar4 = puVar16[0x56];
    *(uint *)(iVar4 + 0x1710) =
         *(uint *)(iVar4 + 0x1710) ^ (*(uint *)(iVar4 + 0x1710) ^ puVar16[0x90]) & 1;
  }
  iVar4 = _DAT_109d5e68;
  if (_DAT_109d5e68 != 0) {
    iVar11 = *(int *)(*(int *)(_DAT_109d5e68 + 0x1a0) +
                     (*(int *)(_DAT_109d5e68 + 0x1a4) - 1U & *unaff_EBX) * 4);
    if (iVar11 != -1) {
      iVar2 = *(int *)(_DAT_109d5e68 + 0x194);
      do {
        if (*(uint *)(iVar2 + 4 + iVar11 * 0xc) == *unaff_EBX) {
          if (*(int *)(iVar2 + 8 + iVar11 * 0xc) != 0) {
            iVar11 = *(int *)(*(int *)(_DAT_109d5e68 + 0x1a0) +
                             (*(int *)(_DAT_109d5e68 + 0x1a4) - 1U & *unaff_EBX) * 4);
            if (iVar11 == -1) goto LAB_10424a03;
            iVar2 = *(int *)(_DAT_109d5e68 + 0x194);
            goto LAB_104249f0;
          }
          break;
        }
        iVar11 = *(int *)(iVar2 + iVar11 * 0xc);
      } while (iVar11 != -1);
    }
  }
LAB_104249b5:
  uVar5 = 0;
LAB_104249b7:
  (**(code **)(**(int **)(iVar4 + 0x54) + 0xb0))(uVar5,0,0);
LAB_10424ed0:
  if (puVar16[0x56] != 0) {
    iVar4 = puVar16[0x8e];
    if (iVar4 == 0) {
      func_0x1030ae89(4);
      func_0x1030ae89(8);
    }
    else if (iVar4 == 1) {
      func_0x1030ae89(4);
      func_0x1030f5dd(8);
    }
    else if (iVar4 == 2) {
      func_0x1030ae89(8);
      func_0x1030f5dd(4);
    }
  }
  if (0 < (int)puVar16[0x75]) {
    func_0x103146af(puVar16[0x75],puVar16[0x76],puVar16[0x77],puVar16[0x78],puVar16[0x7c]);
  }
  puVar16[0x7a] = (uint)puVar16[0x79] >> 6 & 1;
  if ((int)puVar16[0x75] < 1) {
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x4d0))(0);
  }
  else {
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x4d0))(1);
  }
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x4d4))(0 < (int)puVar16[0x77]);
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x4cc))((*(byte *)(puVar16 + 0x79) & 0x18) != 0);
  if (0 < (short)puStack_114) {
    (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(unaff_EBX);
  }
  if (fStack_dc != 0.0) {
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x69c))
              (puVar16[0x56],0,uStack_bc,puStack_b8,uStack_b4);
  }
  fVar1 = fStack_d8;
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c7a98,*piVar7,fStack_d8
             ,*puStack_cc,*piStack_c8,puStack_ec,uStack_f0,uStack_e0);
  uVar12 = (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                     (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c7a98,*piVar7,fVar1,*puStack_cc,
                      *piStack_c8,puStack_ec,uStack_f0,uStack_e0);
  return uVar12 & 0xffffff00;
}

