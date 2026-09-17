
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 packet_10426340(int param_1,undefined4 param_2)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  short *psVar6;
  short *psVar7;
  int iVar8;
  int iVar9;
  float *pfVar10;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  char cVar11;
  undefined *puVar12;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  float fStack_168;
  float afStack_164 [2];
  int iStack_15c;
  int iStack_158;
  uint uStack_154;
  int iStack_150;
  int iStack_14c;
  int iStack_148;
  undefined4 uStack_144;
  int iStack_140;
  undefined4 uStack_13c;
  int iStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  int iStack_128;
  undefined4 uStack_124;
  undefined1 auStack_120 [4];
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 *puStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 auStack_94 [2];
  short asStack_8c [2];
  short asStack_88 [2];
  undefined2 auStack_84 [18];
  short asStack_60 [2];
  short asStack_5c [4];
  undefined2 auStack_54 [4];
  undefined4 uStack_4c;
  undefined1 auStack_30 [20];
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &UNK_10756dab;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  uStack_124 = 0;
  iStack_140 = 0;
  iStack_128 = 0;
  uStack_118 = 0;
  uStack_11c = 0;
  uStack_110 = 0;
  uStack_e8 = 0;
  auStack_54[0] = 0;
  auStack_84[0] = 0;
  iStack_138 = 0;
  uStack_c0 = 0;
  uStack_bc = 0;
  puStack_b0 = (undefined4 *)0x0;
  uStack_ac = 0;
  uStack_130 = 0;
  afStack_164[0] = 0.0;
  uVar2 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c7e24,&uStack_170,
                          &uStack_154,&iStack_150,&uStack_12c,&uStack_134,&uStack_13c,auStack_94,
                          &fStack_168,&uStack_124,&iStack_140,&uStack_10c,&uStack_108,&uStack_104,
                          &uStack_114,&uStack_fc,&uStack_f4,auStack_120,&uStack_e0,&uStack_c8,
                          &uStack_d8,&uStack_b8,&uStack_d0,&iStack_14c,&iStack_148,&uStack_144,
                          &uStack_e8,&uStack_110,&uStack_11c,&uStack_118,&iStack_128,0x30,auStack_84
                          ,0x30,auStack_54,&iStack_138,&uStack_100,&uStack_ec);
  func_0x10305079(*(undefined4 *)(param_1 + 0x48),uVar2,&UNK_107c7e14,&uStack_130,&uStack_f8,
                  &uStack_e4,&uStack_f0,&uStack_dc,(int)&uStack_174 + 3,(int)&uStack_16c + 3,
                  &uStack_c0,&puStack_b0,afStack_164);
  if ((((_DAT_109d5e68 == 0) || (iVar3 = func_0x1030f3bc(&uStack_170), iVar3 == 0)) ||
      (piVar4 = (int *)func_0x1030f3bc(&uStack_170), *piVar4 != 1)) ||
     ((iVar3 = func_0x1030f3bc(&uStack_170), *(int *)(iVar3 + 4) == 0 ||
      (iVar3 = func_0x1030f3bc(&uStack_170), *(int *)(iVar3 + 4) == 0)))) {
    if ((iStack_128 != 0) && (iStack_128 != 2)) goto LAB_104270d3;
    puVar12 = &UNK_107c710c;
    iVar5 = 0x248;
    iVar3 = (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)();
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = func_0x10302d06();
    }
    *(undefined4 *)(iVar3 + 0x18) = unaff_EBX;
    *(undefined4 *)(iVar3 + 8) = 1;
    *(int *)(iVar3 + 0xc) = iStack_140;
    *(undefined4 *)(iVar3 + 0x90) = 0;
    *(int *)(iVar3 + 0x14) = iStack_15c + -1000000;
    *(int *)(iVar3 + 0x10) = iStack_158;
    *(undefined4 *)(iVar3 + 0xf0) = uStack_114;
    *(undefined4 *)(iVar3 + 0xf4) = uStack_110;
    *(undefined4 *)(iVar3 + 0xf8) = uStack_10c;
    *(undefined4 *)(iVar3 + 0xfc) = uStack_11c;
    psVar6 = (short *)(iVar3 + 0x14);
    *(undefined4 *)(iVar3 + 0x108) = uStack_104;
    *(undefined4 *)(iVar3 + 0x10c) = uStack_fc;
    *(int *)(iVar3 + 0x100) = iStack_128;
    *(undefined4 *)(iVar3 + 0x104) = uStack_e8;
    *(undefined4 *)(iVar3 + 0x110) = uStack_e0;
    *(undefined4 *)(iVar3 + 0x114) = uStack_dc;
    *(undefined4 *)(iVar3 + 0x118) = uStack_d0;
    *(undefined4 *)(iVar3 + 0x11c) = uStack_cc;
    *(float *)(iVar3 + 0x120) = (float)(double)CONCAT44(uStack_bc,uStack_c0);
    *(float *)(iVar3 + 0x124) = (float)(double)CONCAT44(uStack_d4,uStack_d8);
    *(uint *)(iVar3 + 0xb0) = uStack_154;
    *(int *)(iVar3 + 0xb4) = iStack_14c;
    *(int *)(iVar3 + 0xbc) = iStack_150;
    *(undefined4 *)(iVar3 + 0x18c) = uStack_12c;
    *(int *)(iVar3 + 0x1fc) = iStack_148;
    *(undefined4 *)(iVar3 + 0xe8) = uStack_108;
    *(undefined4 *)(iVar3 + 0xec) = uStack_f4;
    *(undefined4 *)(iVar3 + 0x1d4) = uStack_100;
    *(undefined4 *)(iVar3 + 0x1d8) = uStack_ec;
    *(undefined4 *)(iVar3 + 0x1dc) = uStack_f8;
    *(undefined4 *)(iVar3 + 0x1e0) = uStack_e4;
    if (asStack_8c[0] == 0) {
      iVar9 = func_0x1030a083();
      if (iVar9 != 0) {
        uVar2 = __DFString__QBEPBGXZ();
        func_0x10309930(uVar2);
        *(undefined4 *)(iVar3 + 0xe4) = *(undefined4 *)(iVar9 + 0x1c);
        *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f54) = 0;
      }
    }
    else {
      psVar6 = asStack_8c;
      func_0x10309930();
      *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f54) = 1;
    }
    if (asStack_60[0] == 0) {
      iVar9 = func_0x1030a083(iVar3 + 0x14);
      if (iVar9 != 0) {
        psVar7 = (short *)__DFString__QBEPBGXZ();
        goto LAB_10426c65;
      }
    }
    else {
      psVar7 = asStack_60;
LAB_10426c65:
      func_0x1030ebba(psVar7);
    }
    iVar9 = iVar3 + 0x18;
    *(undefined4 *)(iVar3 + 0x234) = uStack_170;
    if ((0 < *(int *)(iVar3 + 0x18)) && (_DAT_109d5e68 != 0)) {
      iVar8 = func_0x1030f3bc(iVar9);
      if (iVar8 != 0) {
        func_0x10306203(iVar8);
        func_0x1030720c(iVar9);
      }
      puStack_b0 = (undefined4 *)
                   (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(8,&UNK_10792bd0);
      if (puStack_b0 == (undefined4 *)0x0) {
        puStack_b0 = (undefined4 *)0x0;
      }
      else {
        *puStack_b0 = 0;
        puStack_b0[1] = 0;
      }
      if (puStack_b0 != (undefined4 *)0x0) {
        puStack_b0[1] = iVar3;
        *puStack_b0 = 1;
      }
      func_0x1030cb1c(iVar9,&puStack_b0);
    }
    uStack_16c = (float)iStack_138;
    fStack_168 = (float)iStack_140;
    afStack_164[0] = (float)iStack_148;
    if (0 < uStack_174) {
      if ((((_DAT_109d5e68 == 0) || (iVar9 = func_0x1030f3bc(&uStack_174), iVar9 == 0)) ||
          (piVar4 = (int *)func_0x1030f3bc(&uStack_174), *piVar4 != 3)) ||
         ((iVar9 = func_0x1030f3bc(&uStack_174), *(int *)(iVar9 + 4) == 0 ||
          (iVar9 = func_0x1030f3bc(&uStack_174), *(int *)(iVar9 + 4) == 0)))) {
        _Logf_FOutputDevice__QAAXPBGZZ
                  (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c7d90);
        (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                  (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c7d90);
      }
      else {
        iVar9 = func_0x1030f3bc(&uStack_174);
        if ((iVar9 == 0) ||
           ((piVar4 = (int *)func_0x1030f3bc(&uStack_174), *piVar4 != 3 ||
            (iVar9 = func_0x1030f3bc(&uStack_174), *(int *)(iVar9 + 4) == 0)))) {
          iVar9 = 0;
        }
        else {
          iVar9 = func_0x1030f3bc(&uStack_174);
          iVar9 = *(int *)(iVar9 + 4);
        }
        uStack_9c = 0;
        uStack_98 = 0;
        auStack_94[0] = 0x3f800000;
        pfVar10 = (float *)_RotateAngleAxis_FVector__QBE_AV1_HABV1__Z
                                     (auStack_30,*(uint *)(*(int *)(iVar9 + 4) + 0x1cc) & 0xffff,
                                      &uStack_9c);
        iVar9 = *(int *)(iVar9 + 4);
        uStack_16c = *pfVar10 + *(float *)(iVar9 + 0x1bc);
        fStack_168 = pfVar10[1] + *(float *)(iVar9 + 0x1c0);
        afStack_164[0] = pfVar10[2] + *(float *)(iVar9 + 0x1c4);
      }
    }
    *(undefined4 *)(iVar3 + 0x158) = 0;
    func_0x1030218f(10);
    uStack_1c = 0;
    func_0x103012c1(uStack_f8);
    uVar2 = uStack_124;
    func_0x103012c1(uStack_124);
    cVar11 = (char)((uint)uVar2 >> 0x18);
    func_0x103012c1(uStack_134);
    func_0x103012c1(uStack_134);
    func_0x103012c1();
    func_0x103012c1((int)cVar11);
    cVar11 = (char)((uint)&uStack_d0 >> 0x18);
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x19c))(iVar3,iVar5,puVar12,unaff_EDI,uStack_bc)
    ;
    if (*(int *)(iVar3 + 0x158) != 0) {
      *(uint *)(*(int *)(iVar3 + 0x158) + 0x5e8) = ((int)psVar6 < 1) - 1 & (uint)psVar6;
      if (iVar5 < 1) {
        *(undefined4 *)(*(int *)(iVar3 + 0x158) + 0x5ec) = 0;
      }
      else {
        *(int *)(*(int *)(iVar3 + 0x158) + 0x5ec) = iVar5;
      }
      if ((int)puVar12 < 1) {
        *(undefined4 *)(*(int *)(iVar3 + 0x158) + 0x5f0) = 0;
      }
      else {
        *(undefined **)(*(int *)(iVar3 + 0x158) + 0x5f0) = puVar12;
      }
      *(undefined4 *)(*(int *)(iVar3 + 0x158) + 0x16c0) = uStack_170;
      *(int *)(*(int *)(iVar3 + 0x158) + 0x6b0) = (int)(char)((uint)unaff_EDI >> 0x18);
      if (cVar11 == '\0') {
        func_0x1030ae89(4);
        func_0x1030ae89(8);
      }
      else if (cVar11 == '\x01') {
        func_0x1030ae89(4);
        func_0x1030f5dd(8);
      }
      else if (cVar11 == '\x02') {
        func_0x1030ae89(8);
        func_0x1030f5dd(4);
      }
      *(float *)(*(int *)(iVar3 + 0x158) + 0x2f0) = (float)(double)CONCAT44(uStack_f4,uStack_f8);
      *(float *)(*(int *)(iVar3 + 0x158) + 0x2f4) = (float)(double)CONCAT44(uStack_10c,uStack_110);
      *(float *)(*(int *)(iVar3 + 0x158) + 0x1750) = (float)(double)CONCAT44(uStack_fc,uStack_100);
      *(float *)(*(int *)(iVar3 + 0x158) + 0x1754) = (float)(double)CONCAT44(uStack_ec,uStack_f0);
      *(int *)(*(int *)(iVar3 + 0x158) + 0x171c) = iStack_148;
    }
    if (0 < *(int *)(iVar3 + 0x1d4)) {
      func_0x103146af(*(int *)(iVar3 + 0x1d4),*(undefined4 *)(iVar3 + 0x1d8),
                      *(undefined4 *)(iVar3 + 0x1dc),*(undefined4 *)(iVar3 + 0x1e0),0);
    }
    uStack_4c = 0xffffffff;
    func_0x10307f3b();
    goto LAB_104270d3;
  }
  iVar3 = func_0x1030f3bc(&uStack_170);
  if ((iVar3 == 0) ||
     ((piVar4 = (int *)func_0x1030f3bc(&uStack_174), *piVar4 != 1 ||
      (iVar3 = func_0x1030f3bc(&uStack_174), *(int *)(iVar3 + 4) == 0)))) {
    iVar3 = 0;
  }
  else {
    iVar3 = func_0x1030f3bc(&uStack_174);
    iVar3 = *(int *)(iVar3 + 4);
  }
  *(undefined4 *)(iVar3 + 8) = 1;
  *(undefined4 *)(iVar3 + 0xc) = uStack_13c;
  *(undefined4 *)(iVar3 + 0x90) = 0;
  *(int *)(iVar3 + 0x14) = iStack_158 + -1000000;
  *(uint *)(iVar3 + 0x10) = uStack_154;
  *(undefined4 *)(iVar3 + 0xf0) = uStack_110;
  *(undefined4 *)(iVar3 + 0xf4) = uStack_10c;
  *(undefined4 *)(iVar3 + 0xf8) = uStack_108;
  *(undefined4 *)(iVar3 + 0xfc) = uStack_118;
  *(undefined4 *)(iVar3 + 0x108) = uStack_100;
  *(undefined4 *)(iVar3 + 0x10c) = uStack_f8;
  *(undefined4 *)(iVar3 + 0x100) = uStack_124;
  *(undefined4 *)(iVar3 + 0x104) = uStack_e4;
  *(undefined4 *)(iVar3 + 0x110) = uStack_dc;
  *(undefined4 *)(iVar3 + 0x114) = uStack_d8;
  *(undefined4 *)(iVar3 + 0x118) = uStack_cc;
  *(undefined4 *)(iVar3 + 0x11c) = uStack_c8;
  *(float *)(iVar3 + 0x120) = (float)(double)CONCAT44(uStack_b8,uStack_bc);
  *(float *)(iVar3 + 0x124) = (float)(double)CONCAT44(uStack_d0,uStack_d4);
  *(int *)(iVar3 + 0xb0) = iStack_150;
  *(int *)(iVar3 + 0xb4) = iStack_148;
  *(int *)(iVar3 + 0xbc) = iStack_14c;
  *(int *)(iVar3 + 0x18c) = iStack_128;
  *(undefined4 *)(iVar3 + 0x1fc) = uStack_144;
  *(undefined4 *)(iVar3 + 0xe8) = uStack_104;
  *(undefined4 *)(iVar3 + 0xec) = uStack_f0;
  *(undefined4 *)(iVar3 + 0x1d4) = uStack_fc;
  *(undefined4 *)(iVar3 + 0x1d8) = uStack_e8;
  *(undefined4 *)(iVar3 + 0x1dc) = uStack_f4;
  *(undefined4 *)(iVar3 + 0x1e0) = uStack_e0;
  if (asStack_88[0] == 0) {
    iVar5 = func_0x1030a083(iVar3 + 0x14);
    if (iVar5 != 0) {
      uVar2 = __DFString__QBEPBGXZ();
      func_0x10309930(uVar2);
      *(undefined4 *)(iVar3 + 0xe4) = *(undefined4 *)(iVar5 + 0x1c);
      *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f54) = 0;
    }
  }
  else {
    func_0x10309930(asStack_88);
    *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f54) = 1;
  }
  if (asStack_5c[0] == 0) {
    iVar5 = func_0x1030a083(iVar3 + 0x14);
    if (iVar5 != 0) {
      psVar6 = (short *)__DFString__QBEPBGXZ();
      goto LAB_104267ee;
    }
  }
  else {
    psVar6 = asStack_5c;
LAB_104267ee:
    func_0x1030ebba(psVar6);
  }
  *(float *)(iVar3 + 0x234) = uStack_16c;
  if (*(int *)(iVar3 + 0x158) != 0) {
    *(uint *)(*(int *)(iVar3 + 0x158) + 0x5e8) = ((int)uStack_154 < 1) - 1 & uStack_154;
    if (iStack_150 < 1) {
      *(undefined4 *)(*(int *)(iVar3 + 0x158) + 0x5ec) = 0;
    }
    else {
      *(int *)(*(int *)(iVar3 + 0x158) + 0x5ec) = iStack_150;
    }
    if (iStack_14c < 1) {
      *(undefined4 *)(*(int *)(iVar3 + 0x158) + 0x5f0) = 0;
    }
    else {
      *(int *)(*(int *)(iVar3 + 0x158) + 0x5f0) = iStack_14c;
    }
    *(float *)(*(int *)(iVar3 + 0x158) + 0x5f8) = (float)*(double *)(iVar3 + 0x110);
    *(float *)(*(int *)(iVar3 + 0x158) + 0x5fc) = (float)*(double *)(iVar3 + 0x118);
    *(float *)(*(int *)(iVar3 + 0x158) + 0x634) = (float)*(int *)(iVar3 + 0xf0);
    *(float *)(*(int *)(iVar3 + 0x158) + 0x638) = (float)*(int *)(iVar3 + 0xf4);
    *(float *)(*(int *)(iVar3 + 0x158) + 0x63c) = (float)*(int *)(iVar3 + 0xf8);
    *(float *)(*(int *)(iVar3 + 0x158) + 0x640) = (float)*(int *)(iVar3 + 0xfc);
    iVar5 = *(int *)(iVar3 + 0x158);
    if (*(char *)(*(int *)(iVar5 + 0x13f0) + 0x41c) == '\x01') {
      *(float *)(iVar5 + 0x1468) = *(float *)(iVar5 + 0x634) * *(float *)(iVar5 + 0x5fc);
      iVar5 = *(int *)(iVar3 + 0x158);
      fVar1 = *(float *)(iVar5 + 0x63c);
    }
    else {
      *(float *)(iVar5 + 0x1468) = *(float *)(iVar5 + 0x638) * *(float *)(iVar5 + 0x5fc);
      iVar5 = *(int *)(iVar3 + 0x158);
      fVar1 = *(float *)(iVar5 + 0x640);
    }
    *(float *)(iVar5 + 0x146c) = fVar1 * *(float *)(iVar5 + 0x5fc);
    *(int *)(*(int *)(iVar3 + 0x158) + 0x16c0) = iStack_138;
    *(int *)(*(int *)(iVar3 + 0x158) + 0x6b0) = (int)(char)((uint)unaff_ESI >> 0x18);
    if (uStack_174._3_1_ == '\0') {
      func_0x1030ae89(4);
      func_0x1030ae89(8);
    }
    else if (uStack_174._3_1_ == '\x01') {
      func_0x1030ae89(4);
      func_0x1030f5dd(8);
    }
    else if (uStack_174._3_1_ == '\x02') {
      func_0x1030ae89(8);
      func_0x1030f5dd(4);
    }
    *(float *)(*(int *)(iVar3 + 0x158) + 0x2f0) = (float)(double)CONCAT44(uStack_bc,uStack_c0);
    *(float *)(*(int *)(iVar3 + 0x158) + 0x2f4) = (float)(double)CONCAT44(uStack_d4,uStack_d8);
    *(float *)(*(int *)(iVar3 + 0x158) + 0x1750) = (float)(double)CONCAT44(uStack_c4,uStack_c8);
    *(float *)(*(int *)(iVar3 + 0x158) + 0x1754) = (float)(double)CONCAT44(uStack_b4,uStack_b8);
    *(float *)(*(int *)(iVar3 + 0x158) + 0x171c) = uStack_16c;
  }
  if (0 < *(int *)(iVar3 + 0x1d4)) {
    func_0x103146af(*(int *)(iVar3 + 0x1d4),*(undefined4 *)(iVar3 + 0x1d8),
                    *(undefined4 *)(iVar3 + 0x1dc),*(undefined4 *)(iVar3 + 0x1e0),0);
  }
  func_0x10304d9a();
LAB_104270d3:
  if (-1 < (int)(uStack_154 - 1000000)) {
    _Logf_FOutputDevice__QAAXPBGZZ
              (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c7ce0,uStack_170,
               uStack_154,iStack_150,uStack_12c,uStack_134,uStack_13c);
    (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
              (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c7ce0,uStack_170,uStack_154,iStack_150,
               uStack_12c,uStack_134,uStack_13c);
    *unaff_FS_OFFSET = uStack_14;
    return 0;
  }
  func_0x10302720();
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x264))(2);
  *unaff_FS_OFFSET = uStack_18;
  return 1;
}

