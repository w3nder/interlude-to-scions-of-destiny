
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 packet_10422390(void)

{
  int *piVar1;
  uint *puVar2;
  float fVar3;
  int iVar4;
  code *pcVar5;
  undefined4 *puVar6;
  short sVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  int *piVar11;
  int *piVar12;
  uint uVar13;
  float *pfVar14;
  int iVar15;
  short sVar16;
  uint3 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 *puVar17;
  undefined4 *unaff_FS_OFFSET;
  undefined4 unaff_retaddr;
  char cVar18;
  char cVar19;
  uint *puVar20;
  undefined4 *puStack_108;
  undefined4 uStack_104;
  int iStack_100;
  int iStack_fc;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  int iStack_e8;
  int iStack_e4;
  int aiStack_e0 [2];
  undefined4 *puStack_d8;
  int aiStack_d4 [3];
  undefined4 *puStack_c8;
  int aiStack_c4 [7];
  int *piStack_a8;
  undefined4 uStack_a0;
  int iStack_9c;
  undefined1 auStack_98 [4];
  int iStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  int iStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  double dStack_64;
  double dStack_5c;
  undefined1 auStack_54 [4];
  undefined1 auStack_50 [8];
  undefined4 uStack_48;
  short asStack_44 [22];
  undefined4 uStack_18;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  pcVar5 = _GMalloc__3PAVFMalloc__A_exref;
  uStack_c = *unaff_FS_OFFSET;
  iStack_4 = -1;
  puStack_8 = &UNK_10756d6b;
  *unaff_FS_OFFSET = &uStack_c;
  iVar8 = (**(code **)**(undefined4 **)pcVar5)(0x248,&UNK_107c7a7c);
  if (iVar8 == 0) {
    puVar9 = (undefined4 *)0x0;
  }
  else {
    puVar9 = (undefined4 *)func_0x10302d06();
  }
  puVar17 = puVar9;
  for (iVar8 = 0x92; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar17 = 0;
    puVar17 = puVar17 + 1;
  }
  puVar20 = (uint *)(uint)unaff_EBP;
  aiStack_d4[0] = 0;
  aiStack_d4[1] = 0;
  aiStack_c4[1] = 0;
  aiStack_d4[2] = 0;
  aiStack_c4[3] = 0;
  iStack_100 = 0;
  iStack_fc = 0;
  puStack_d8 = puVar9 + 0x14;
  puStack_c8 = puVar9 + 0x13;
  piVar1 = puVar9 + 6;
  uVar10 = func_0x10305079(*(undefined4 *)(iStack_4 + 0x48),unaff_retaddr,&UNK_107c7a38,aiStack_e0,
                           &iStack_e8,&iStack_e4,&puStack_108,piVar1,0x30,asStack_44,puStack_c8,
                           puStack_d8,puVar9 + 0x15,puVar9 + 0x25,puVar9 + 0x2b,puVar9 + 0x2c,
                           puVar9 + 0x2d,puVar9 + 0x2e,puVar9 + 0x2f,puVar9 + 0x30,puVar9 + 0x31,
                           puVar9 + 0x32,puVar9 + 0x33,puVar9 + 0x35,puVar9 + 0x3a,puVar9 + 0x3b,
                           puVar9 + 99,puVar9 + 0x7f,auStack_98,auStack_54,puVar9 + 0x3c,
                           puVar9 + 0x3d,puVar9 + 0x3e,puVar9 + 0x3f,puVar9 + 0x42,puVar9 + 0x43,
                           puVar9 + 0x40,puVar9 + 0x41,&uStack_80,&uStack_78,&dStack_64,&dStack_5c,
                           puVar9 + 100,puVar9 + 0x65,puVar9 + 0x66,0x30,puVar9 + 0x69,puVar9 + 0x75
                           ,puVar9 + 0x76,puVar9 + 0x77,puVar9 + 0x78,auStack_98,aiStack_c4 + 3,
                           aiStack_d4 + 2,aiStack_c4 + 1,aiStack_d4 + 1,aiStack_d4,&stack0xfffffef3,
                           puVar9 + 0x80,&iStack_100);
  sVar7 = (short)iStack_100;
  if (0 < sVar7) {
    iStack_fc = (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)
                          ((int)sVar7 << 1,&UNK_10792bd0);
    sVar7 = (short)iStack_100;
  }
  sVar16 = 0;
  if (0 < sVar7) {
    do {
      uVar10 = func_0x10305079(*(undefined4 *)(iStack_4 + 0x48),uVar10,&UNK_107c1644,
                               iStack_fc + sVar16 * 2);
      sVar16 = sVar16 + 1;
    } while (sVar16 < (short)iStack_100);
  }
  iVar8 = iStack_4;
  uVar10 = func_0x10305079(*(undefined4 *)(iStack_4 + 0x48),uVar10,&UNK_107bd86c,puVar9 + 0x83);
  aiStack_e0[1] = 0;
  aiStack_c4[2] = 0;
  uStack_a0 = 0;
  if (0x1a4 < _DAT_10925300) {
    uVar10 = func_0x10305079(*(undefined4 *)(iVar8 + 0x48),uVar10,&UNK_107c7a30,aiStack_e0 + 1,
                             &stack0xfffffef2,(int)puVar9 + 0x22e,aiStack_c4 + 2);
  }
  uVar10 = func_0x10305079(*(undefined4 *)(iVar8 + 0x48),uVar10,&UNK_107c4884,puVar9 + 0x84,
                           &uStack_a0,(int)&uStack_104 + 3);
  uVar10 = func_0x10305079(*(undefined4 *)(iVar8 + 0x48),uVar10,&UNK_107bd86c,puVar9 + 0x8e);
  uVar10 = func_0x10305079(*(undefined4 *)(iVar8 + 0x48),uVar10,&UNK_107c7a2c,puVar9 + 0x7c,
                           puVar9 + 0x8f,puVar9 + 0x90);
  if ((double)(int)puVar9[0x7f] == (double)(int)puVar9[99] * _DAT_107c7a20 - _DAT_107c7a10) {
    iVar8 = *(int *)(iVar8 + 0x48);
    if (*(int *)(iVar8 + 0x38) != 0) {
      Ordinal_3(*(int *)(iVar8 + 0x38));
      DeleteCriticalSection(iVar8 + 0x4e4c);
    }
    *(undefined4 *)(iVar8 + 0x38) = 0;
    if (*(int *)(iVar8 + 0x495c) != 0) {
      *(undefined4 *)(iVar8 + 0x495c) = 0;
      _DAT_109d5e6c = 0;
    }
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x264))(2);
    uVar10 = 1;
    goto LAB_1042355a;
  }
  aiStack_c4[0] = 0;
  uVar10 = func_0x10305079(*(undefined4 *)(iVar8 + 0x48),uVar10,&UNK_107bd8cc,aiStack_c4,&iStack_94,
                           &iStack_9c,&iStack_84);
  fStack_88 = (float)iStack_84;
  fStack_8c = (float)iStack_9c;
  fStack_90 = (float)iStack_94;
  puVar2 = puVar9 + 0x91;
  func_0x10305079(*(undefined4 *)(iVar8 + 0x48),uVar10,&UNK_107bde9c,puVar2);
  *puVar2 = (((byte)*puVar2 | 0xffffff00) << 8 | (uint)*(byte *)((int)puVar9 + 0x245)) << 8 |
            (uint)*(byte *)((int)puVar9 + 0x246);
  puVar9[0x44] = uStack_78;
  puVar9[0x45] = uStack_74;
  puVar9[0x46] = uStack_80;
  puVar9[0x47] = uStack_7c;
  puVar9[0x48] = (float)dStack_64;
  puVar9[0x49] = (float)dStack_5c;
  puVar9[0x8d] = (int)uStack_104._3_1_;
  if (asStack_44[0] != 0) {
    wcscpy(puVar9 + 7,asStack_44);
  }
  if ((((_DAT_109d5e68 != 0) && (iVar8 = func_0x1030f3bc(piVar1), iVar8 != 0)) &&
      (piVar11 = (int *)func_0x1030f3bc(piVar1), *piVar11 == 1)) &&
     ((iVar8 = func_0x1030f3bc(piVar1), *(int *)(iVar8 + 4) != 0 &&
      (iVar8 = func_0x1030f3bc(piVar1), *(int *)(iVar8 + 4) != 0)))) {
    piVar11 = piVar1;
    iVar8 = func_0x1030f3bc();
    if ((iVar8 == 0) ||
       ((piVar12 = (int *)func_0x1030f3bc(piVar1), *piVar12 != 1 ||
        (iVar8 = func_0x1030f3bc(piVar1), *(int *)(iVar8 + 4) == 0)))) {
      iVar8 = 0;
    }
    else {
      iVar8 = func_0x1030f3bc(piVar1);
      iVar8 = *(int *)(iVar8 + 4);
    }
    puVar9[0x56] = *(undefined4 *)(iVar8 + 0x158);
    puVar9[0x79] = *(undefined4 *)(iVar8 + 0x1e4);
    iVar15 = 0;
    if (0 < *(int *)(_DAT_109d5e68 + 0x198)) {
      do {
        iVar15 = iVar15 + 1;
      } while (iVar15 < *(int *)(_DAT_109d5e68 + 0x198));
    }
    if (_DAT_109d5e68 != 0) {
      iVar15 = *(int *)(*(int *)(_DAT_109d5e68 + 0x1a0) +
                       (*(int *)(_DAT_109d5e68 + 0x1a4) - 1U & *(uint *)(iVar8 + 0x18)) * 4);
      if (iVar15 != -1) {
        iVar4 = *(int *)(_DAT_109d5e68 + 0x194);
        do {
          if (*(uint *)(iVar4 + 4 + iVar15 * 0xc) == *(uint *)(iVar8 + 0x18)) {
            if (*(int *)(iVar4 + 8 + iVar15 * 0xc) != 0) {
              iVar15 = iVar8 + 0x18;
              piVar12 = (int *)func_0x1030f3bc(iVar15);
              if (*piVar12 == 1) {
                piStack_a8 = *(int **)_GMalloc__3PAVFMalloc__A_exref;
                iStack_fc = *piStack_a8;
                uVar10 = func_0x1030f3bc(iVar15);
                (**(code **)(iStack_100 + 8))(uVar10);
                func_0x1030720c(iVar15);
              }
            }
            break;
          }
          iVar15 = *(int *)(iVar4 + iVar15 * 0xc);
        } while (iVar15 != -1);
      }
    }
    (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(iVar8);
    puVar9[2] = 0;
    puVar9[0x24] = 0;
    iVar8 = 0;
    if (0 < *(int *)(_DAT_109d5e68 + 0x198)) {
      do {
        iVar8 = iVar8 + 1;
      } while (iVar8 < *(int *)(_DAT_109d5e68 + 0x198));
    }
    uVar13 = *puVar20;
    if ((0 < (int)uVar13) && (_DAT_109d5e68 != 0)) {
      iVar8 = *(int *)(*(int *)(_DAT_109d5e68 + 0x1a0) +
                      (*(int *)(_DAT_109d5e68 + 0x1a4) - 1U & uVar13) * 4);
      if (iVar8 != -1) {
        iVar15 = *(int *)(_DAT_109d5e68 + 0x194);
        do {
          if (*(uint *)(iVar15 + 4 + iVar8 * 0xc) == uVar13) {
            iVar8 = *(int *)(iVar15 + 8 + iVar8 * 0xc);
            if (iVar8 != 0) {
              (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(iVar8);
              func_0x1030720c(puVar20);
            }
            break;
          }
          iVar8 = *(int *)(iVar15 + iVar8 * 0xc);
        } while (iVar8 != -1);
      }
      puStack_108 = (undefined4 *)
                    (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(8,&UNK_10792bd0);
      if (puStack_108 == (undefined4 *)0x0) {
        puStack_108 = (undefined4 *)0x0;
      }
      else {
        *puStack_108 = 0;
        puStack_108[1] = 0;
      }
      if (puStack_108 != (undefined4 *)0x0) {
        puStack_108[1] = puVar9;
        *puStack_108 = 1;
      }
      func_0x1030cb1c(puVar20,&puStack_108);
    }
    iVar8 = 0;
    if (0 < *(int *)(_DAT_109d5e68 + 0x198)) {
      do {
        iVar8 = iVar8 + 1;
      } while (iVar8 < *(int *)(_DAT_109d5e68 + 0x198));
    }
    if (puVar9[0x56] != 0) {
      iVar8 = *(int *)(puVar9[0x56] + 0x5e8);
      uVar10 = func_0x10307b44(8);
      *(undefined4 *)(puVar9[0x56] + 0x5e8) = uVar10;
      if (*(int *)(puVar9[0x56] + 0x5e8) == 0) {
        uVar10 = func_0x10307b44(9);
        *(undefined4 *)(puVar9[0x56] + 0x5e8) = uVar10;
      }
      if (*(int *)(puVar9[0x56] + 0x5e8) == 0) {
        uVar10 = func_0x10307b44(10);
        *(undefined4 *)(puVar9[0x56] + 0x5e8) = uVar10;
      }
      if (iVar8 != *(int *)(puVar9[0x56] + 0x5e8)) {
        *(int *)(puVar9[0x56] + 0x1718) = iVar8;
        iVar8 = puVar9[0x56];
        uVar13 = *(uint *)(iVar8 + 0x5e8);
        if ((-1 < (int)uVar13) &&
           (iVar15 = *(int *)(_DAT_109f49d0[3] + (_DAT_109f49d0[4] - 1U & uVar13) * 4), iVar15 != -1
           )) {
          iVar4 = *_DAT_109f49d0;
          do {
            if (*(uint *)(iVar4 + 4 + iVar15 * 0xc) == uVar13) {
              iVar15 = *(int *)(iVar4 + 8 + iVar15 * 0xc);
              if ((iVar15 != 0) && (*(int *)(iVar15 + 4) == 0)) {
                if (*(int *)(iVar15 + 0x110) < 0) {
                  uVar13 = *(uint *)(iVar8 + 0x1710) & 0xfffffffd;
                }
                else {
                  uVar13 = *(uint *)(iVar8 + 0x1710) | 2;
                }
                *(uint *)(iVar8 + 0x1710) = uVar13;
              }
              break;
            }
            iVar15 = *(int *)(iVar4 + iVar15 * 0xc);
          } while (iVar15 != -1);
        }
      }
      uVar10 = func_0x10307b44(2);
      *(undefined4 *)(puVar9[0x56] + 0x5ec) = uVar10;
      uVar10 = func_0x10307b44(0xb);
      *(undefined4 *)(puVar9[0x56] + 0x5f0) = uVar10;
      *(float *)(puVar9[0x56] + 0x600) = (float)(int)puVar9[99] * _DAT_107c7a08;
      *(float *)(puVar9[0x56] + 0x604) = (float)(int)puVar9[0x7f] * _DAT_107c7a08;
      *(float *)(puVar9[0x56] + 0x634) = (float)(int)puVar9[0x3c];
      *(float *)(puVar9[0x56] + 0x638) = (float)(int)puVar9[0x3d];
      *(float *)(puVar9[0x56] + 0x63c) = (float)(int)puVar9[0x3e];
      *(float *)(puVar9[0x56] + 0x640) = (float)(int)puVar9[0x3f];
      *(float *)(puVar9[0x56] + 0x644) = (float)(int)puVar9[0x40];
      *(float *)(puVar9[0x56] + 0x648) = (float)(int)puVar9[0x41];
      if ((char)((uint)piVar11 >> 0x18) == '\0') {
        func_0x1030e732(puVar9[0x48],puVar9[0x49]);
      }
      cVar18 = (char)((uint)piVar11 >> 0x10);
      *(float *)(puVar9[0x56] + 0x5f8) = (float)*(double *)(puVar9 + 0x44);
      *(float *)(puVar9[0x56] + 0x5fc) = (float)*(double *)(puVar9 + 0x46);
      iVar8 = puVar9[0x56];
      if (*(char *)(*(int *)(iVar8 + 0x13f0) + 0x41c) == '\x01') {
        *(float *)(iVar8 + 0x1468) = *(float *)(iVar8 + 0x634) * *(float *)(iVar8 + 0x5fc);
        iVar8 = puVar9[0x56];
        *(float *)(iVar8 + 0x146c) = *(float *)(iVar8 + 0x63c) * *(float *)(iVar8 + 0x5fc);
        iVar8 = puVar9[0x56];
        fVar3 = *(float *)(iVar8 + 0x644);
      }
      else {
        *(float *)(iVar8 + 0x1468) = *(float *)(iVar8 + 0x638) * *(float *)(iVar8 + 0x5fc);
        iVar8 = puVar9[0x56];
        *(float *)(iVar8 + 0x146c) = *(float *)(iVar8 + 0x640) * *(float *)(iVar8 + 0x5fc);
        iVar8 = puVar9[0x56];
        fVar3 = *(float *)(iVar8 + 0x648);
      }
      *(float *)(iVar8 + 0x1470) = fVar3 * *(float *)(iVar8 + 0x5fc);
      sVar7 = *(short *)(puVar9 + 0x80);
      if ((((sVar7 == 1) || (sVar7 == 3)) || (sVar7 == 5)) || ((sVar7 == 7 || (sVar7 == 8)))) {
        func_0x1030e2c8();
        if (*(short *)(puVar9 + 0x80) == 7) {
          *(undefined4 *)(puVar9[0x56] + 0x578) = 9;
        }
        else {
          *(undefined4 *)(puVar9[0x56] + 0x578) = 8;
        }
        *(undefined4 *)(puVar9[0x56] + 0x588) = puVar9[0x56];
      }
      if ((*(int *)(puVar9[0x56] + 0x660) == 0) || ((short)unaff_ESI == 0)) {
        func_0x1030cd56(unaff_ESI,puVar20);
      }
      *(float *)(puVar9[0x56] + 0x16c0) = fStack_f0;
      *(int *)(puVar9[0x56] + 0x6b0) = (int)cVar18;
      uVar10 = func_0x1030554c(puVar9[0x31]);
      *(undefined4 *)(puVar9[0x56] + 0x1714) = uVar10;
      *(undefined4 *)(puVar9[0x56] + 0x171c) = puVar9[0x8d];
      uVar13 = *(uint *)(puVar9[0x56] + 0x1710);
      *(uint *)(puVar9[0x56] + 0x1710) = uVar13 ^ (puVar9[0x90] ^ uVar13) & 1;
    }
    if (_DAT_109d5e68 != 0) {
      iVar8 = *(int *)(*(int *)(_DAT_109d5e68 + 0x1a0) +
                      (*(int *)(_DAT_109d5e68 + 0x1a4) - 1U & *puVar20) * 4);
      if (iVar8 != -1) {
        iVar15 = *(int *)(_DAT_109d5e68 + 0x194);
        do {
          if (*(uint *)(iVar15 + 4 + iVar8 * 0xc) == *puVar20) {
            if (*(int *)(iVar15 + 8 + iVar8 * 0xc) != 0) {
              iVar8 = *(int *)(*(int *)(_DAT_109d5e68 + 0x1a0) +
                              (*(int *)(_DAT_109d5e68 + 0x1a4) - 1U & *puVar20) * 4);
              if (iVar8 == -1) goto LAB_10422f08;
              iVar15 = *(int *)(_DAT_109d5e68 + 0x194);
              goto LAB_10422ef0;
            }
            break;
          }
          iVar8 = *(int *)(iVar15 + iVar8 * 0xc);
        } while (iVar8 != -1);
      }
    }
    goto LAB_10422ea5;
  }
  if (aiStack_d4[0] == 0) {
    puVar9[2] = 0;
    puVar9[0x24] = 0;
    iVar8 = 0;
    if (0 < *(int *)(_DAT_109d5e68 + 0x198)) {
      do {
        iVar8 = iVar8 + 1;
      } while (iVar8 < *(int *)(_DAT_109d5e68 + 0x198));
    }
    if ((0 < *piVar1) && (_DAT_109d5e68 != 0)) {
      iVar8 = func_0x1030f3bc(piVar1);
      if (iVar8 != 0) {
        (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(iVar8);
        func_0x1030720c(piVar1);
      }
      uStack_104 = (undefined4 *)
                   (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(8,&UNK_10792bd0);
      if (uStack_104 == (undefined4 *)0x0) {
        uStack_104 = (undefined4 *)0x0;
      }
      else {
        *uStack_104 = 0;
        uStack_104[1] = 0;
      }
      if (uStack_104 != (undefined4 *)0x0) {
        uStack_104[1] = puVar9;
        *uStack_104 = 1;
      }
      func_0x1030cb1c(piVar1,&uStack_104);
    }
    iVar8 = 0;
    if (0 < *(int *)(_DAT_109d5e68 + 0x198)) {
      do {
        iVar8 = iVar8 + 1;
      } while (iVar8 < *(int *)(_DAT_109d5e68 + 0x198));
    }
    fStack_f4 = (float)aiStack_e0[0];
    fStack_f0 = (float)iStack_e8;
    fStack_ec = (float)iStack_e4;
    if (0 < (int)puStack_108) {
      if ((_DAT_109d5e68 != 0) &&
         (iVar8 = *(int *)(*(int *)(_DAT_109d5e68 + 0x1a0) +
                          (*(int *)(_DAT_109d5e68 + 0x1a4) - 1U & (uint)puStack_108) * 4),
         iVar8 != -1)) {
        iVar15 = *(int *)(_DAT_109d5e68 + 0x194);
        do {
          if (*(undefined4 **)(iVar15 + 4 + iVar8 * 0xc) == puStack_108) {
            if ((((*(int *)(iVar15 + 8 + iVar8 * 0xc) != 0) &&
                 (piVar11 = (int *)func_0x1030f3bc(&puStack_108), *piVar11 == 3)) &&
                (iVar8 = func_0x1030f3bc(&puStack_108), *(int *)(iVar8 + 4) != 0)) &&
               (iVar8 = func_0x1030f3bc(&puStack_108), *(int *)(iVar8 + 4) != 0)) {
              iVar8 = func_0x1030f3bc(&puStack_108);
              if (((iVar8 == 0) || (piVar11 = (int *)func_0x1030f3bc(&puStack_108), *piVar11 != 3))
                 || (iVar8 = func_0x1030f3bc(&puStack_108), *(int *)(iVar8 + 4) == 0)) {
                iVar8 = 0;
              }
              else {
                iVar8 = func_0x1030f3bc(&puStack_108);
                iVar8 = *(int *)(iVar8 + 4);
              }
              uStack_70 = 0;
              uStack_6c = 0;
              uStack_68 = 0x3f800000;
              pfVar14 = (float *)_RotateAngleAxis_FVector__QBE_AV1_HABV1__Z
                                           (auStack_50,
                                            *(uint *)(*(int *)(iVar8 + 4) + 0x1cc) & 0xffff,
                                            &uStack_70);
              iVar8 = *(int *)(iVar8 + 4);
              fStack_f4 = *pfVar14 + *(float *)(iVar8 + 0x1bc);
              fStack_f0 = pfVar14[1] + *(float *)(iVar8 + 0x1c0);
              fStack_ec = pfVar14[2] + *(float *)(iVar8 + 0x1c4) + _DAT_107c6b8c;
              goto LAB_10423105;
            }
            break;
          }
          iVar8 = *(int *)(iVar15 + iVar8 * 0xc);
        } while (iVar8 != -1);
      }
      _Logf_FOutputDevice__QAAXPBGZZ
                (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c7978);
      (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c7978);
    }
LAB_10423105:
    cVar19 = '\0';
    puVar9[0x56] = 0;
    func_0x1030218f();
    uStack_10 = 0;
    func_0x103012c1(aiStack_c4[2]);
    iVar8 = aiStack_d4[0];
    func_0x103012c1(aiStack_d4[0]);
    cVar18 = (char)((uint)iVar8 >> 0x10);
    func_0x103012c1(aiStack_d4[2]);
    iVar8 = aiStack_e0[0];
    func_0x103012c1(aiStack_e0[0]);
    iVar15 = (int)cVar19;
    func_0x103012c1();
    func_0x103012c1(aiStack_d4[0]);
    func_0x103012c1((int)cVar18);
    cVar18 = '\0';
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x34))
              (puVar9,unaff_ESI,puVar20,piVar1,0,aiStack_d4);
    if ((puVar9[0x56] != 0) &&
       (((sVar7 = *(short *)(puVar9 + 0x80), sVar7 == 1 || (sVar7 == 3)) ||
        ((sVar7 == 5 || ((sVar7 == 7 || (sVar7 == 8)))))))) {
      func_0x1030e2c8();
      if (*(short *)(puVar9 + 0x80) == 7) {
        *(undefined4 *)(puVar9[0x56] + 0x578) = 9;
      }
      else {
        *(undefined4 *)(puVar9[0x56] + 0x578) = 8;
      }
      *(undefined4 *)(puVar9[0x56] + 0x588) = puVar9[0x56];
    }
    if ((*(int *)(puVar9[0x56] + 0x660) == 0) || ((short)iVar15 == 0)) {
      func_0x1030cd56(iVar15,iVar8);
    }
    *(undefined4 *)(puVar9[0x56] + 0x16c0) = unaff_ESI;
    *(int *)(puVar9[0x56] + 0x6b0) = (int)cVar18;
    uVar10 = func_0x1030554c(puVar9[0x31]);
    *(undefined4 *)(puVar9[0x56] + 0x1714) = uVar10;
    *(undefined4 *)(puVar9[0x56] + 0x171c) = puVar9[0x8d];
    uVar13 = *(uint *)(puVar9[0x56] + 0x1710);
    *(uint *)(puVar9[0x56] + 0x1710) = uVar13 ^ (puVar9[0x90] ^ uVar13) & 1;
    uStack_48 = 0xffffffff;
    func_0x10307f3b();
  }
  goto LAB_10423407;
  while (iVar8 = *(int *)(iVar15 + iVar8 * 0xc), iVar8 != -1) {
LAB_10422ef0:
    if (*(uint *)(iVar15 + 4 + iVar8 * 0xc) == *puVar20) {
      piVar11 = *(int **)(iVar15 + 8 + iVar8 * 0xc);
      goto LAB_10422f0a;
    }
  }
LAB_10422f08:
  piVar11 = (int *)0x0;
LAB_10422f0a:
  if (*piVar11 == 1) {
    iVar8 = *(int *)(*(int *)(_DAT_109d5e68 + 0x1a0) +
                    (*(int *)(_DAT_109d5e68 + 0x1a4) - 1U & *puVar20) * 4);
    if (iVar8 != -1) {
      iVar15 = *(int *)(_DAT_109d5e68 + 0x194);
      do {
        if (*(uint *)(iVar15 + 4 + iVar8 * 0xc) == *puVar20) {
          iVar8 = *(int *)(iVar15 + 8 + iVar8 * 0xc);
          goto LAB_10422f46;
        }
        iVar8 = *(int *)(iVar15 + iVar8 * 0xc);
      } while (iVar8 != -1);
    }
    iVar8 = 0;
LAB_10422f46:
    if (*(int *)(iVar8 + 4) == 0) goto LAB_10422ea5;
    iVar8 = *(int *)(*(int *)(_DAT_109d5e68 + 0x1a0) +
                    (*(int *)(_DAT_109d5e68 + 0x1a4) - 1U & *puVar20) * 4);
    uVar10 = uRam00000004;
    if (iVar8 != -1) {
      iVar15 = *(int *)(_DAT_109d5e68 + 0x194);
      do {
        if (*(uint *)(iVar15 + 4 + iVar8 * 0xc) == *puVar20) {
          uVar10 = *(undefined4 *)(*(int *)(iVar15 + 8 + iVar8 * 0xc) + 4);
          break;
        }
        iVar8 = *(int *)(iVar15 + iVar8 * 0xc);
      } while (iVar8 != -1);
    }
  }
  else {
LAB_10422ea5:
    uVar10 = 0;
  }
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0xb0))(uVar10,0,0);
LAB_10423407:
  if (puVar9[0x56] != 0) {
    iVar8 = puVar9[0x8e];
    if (iVar8 == 0) {
      func_0x1030ae89(4);
      func_0x1030ae89(8);
    }
    else if (iVar8 == 1) {
      func_0x1030ae89(4);
      func_0x1030f5dd(8);
    }
    else if (iVar8 == 2) {
      func_0x1030ae89(8);
      func_0x1030f5dd(4);
    }
  }
  if (0 < (int)puVar9[0x75]) {
    func_0x103146af(puVar9[0x75],puVar9[0x76],puVar9[0x77],puVar9[0x78],puVar9[0x7c]);
  }
  if (0 < (short)iStack_100) {
    (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(iStack_fc);
  }
  if (aiStack_c4[0] != 0) {
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x69c))
              (puVar9[0x56],0,fStack_90,fStack_8c,fStack_88);
  }
  puVar6 = puStack_c8;
  puVar17 = puStack_d8;
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c78e0,*piVar1,
             puVar9 + 7,*puStack_c8,*puStack_d8,aiStack_e0[0],iStack_e8,iStack_e4);
  (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
            (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c78e0,*piVar1,puVar9 + 7,*puVar6,*puVar17,
             aiStack_e0[0],iStack_e8,iStack_e4);
  uVar10 = 0;
LAB_1042355a:
  *unaff_FS_OFFSET = uStack_18;
  return uVar10;
}

