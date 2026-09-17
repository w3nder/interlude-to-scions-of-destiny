
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 packet_1043a470(int param_1,undefined4 param_2)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  undefined4 *puVar8;
  float *pfVar9;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  char cStack_181;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined4 uStack_178;
  float fStack_174;
  float fStack_170;
  float afStack_16c [5];
  uint uStack_158;
  int iStack_154;
  int iStack_150;
  int iStack_14c;
  int iStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  int iStack_134;
  int iStack_130;
  int iStack_12c;
  undefined4 uStack_128;
  int iStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  int iStack_114;
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
  undefined1 auStack_d4 [12];
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined8 uStack_b0;
  double dStack_a8;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  short sStack_90;
  undefined2 uStack_8e;
  short asStack_8c [4];
  undefined2 auStack_84 [20];
  short asStack_5c [2];
  short asStack_58 [2];
  undefined2 auStack_54 [18];
  undefined1 auStack_30 [12];
  undefined4 uStack_24;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  uStack_10 = 0x10810aba;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  uStack_a0 = 0;
  uStack_9c = 0;
  dStack_a8 = 0.0;
  uStack_144 = 0;
  uStack_138 = 0;
  iStack_130 = 0;
  uStack_e0 = 0;
  uStack_f0 = 0;
  uStack_d8 = 0;
  uStack_f8 = 0;
  auStack_84[0] = 0;
  auStack_54[0] = 0;
  uStack_140 = 0;
  uStack_13c = 0;
  afStack_16c[0] = 0.0;
  uStack_128 = 0;
  uVar2 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x1088b5bc,&uStack_178,&iStack_12c
                          ,&iStack_134,&uStack_118,&uStack_120,&uStack_108,(int)&uStack_b0 + 4,
                          &fStack_170,&uStack_144,&uStack_138,&uStack_10c,&uStack_104,&uStack_110,
                          auStack_d4,&uStack_100,&uStack_11c,&uStack_f4,&iStack_114,&uStack_98,
                          &sStack_90,&uStack_c0,&uStack_b8,&iStack_150,&iStack_14c,&iStack_148,
                          &uStack_f8,&uStack_d8,&uStack_f0,&uStack_e0,&iStack_130,0x30,auStack_54,
                          0x30,auStack_84,&uStack_140,&uStack_ec,&iStack_124);
  func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar2,0x1088b5ac,&uStack_13c,&uStack_e4,&uStack_dc
                  ,&uStack_fc,&uStack_e8,&cStack_181,(int)&uStack_17c + 3,&uStack_a0,&dStack_a8,
                  afStack_16c,&uStack_128);
  if ((((_DAT_10b1f538 == 0) || (iVar3 = func_0x1030d04e(&uStack_178), iVar3 == 0)) ||
      (piVar4 = (int *)func_0x1030d04e(&uStack_178), *piVar4 != 1)) ||
     ((iVar3 = func_0x1030d04e(&uStack_178), *(int *)(iVar3 + 4) == 0 ||
      (iVar3 = func_0x1030d04e(&uStack_178), *(int *)(iVar3 + 4) == 0)))) {
    if ((iStack_130 != 0) && (iStack_130 != 2)) goto LAB_1043b270;
    iVar3 = (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(0x314,0x1088aa80);
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = func_0x10313449();
    }
    *(undefined4 *)(iVar3 + 0x18) = uStack_180;
    *(undefined4 *)(iVar3 + 8) = 1;
    *(int *)(iVar3 + 0xc) = iStack_148;
    *(undefined4 *)(iVar3 + 0x94) = 0;
    *(int *)(iVar3 + 0x14) = iStack_134 + -1000000;
    *(undefined4 *)(iVar3 + 0x10) = uStack_13c;
    *(int *)(iVar3 + 0x19c) = iStack_114;
    *(undefined4 *)(iVar3 + 0x1a0) = uStack_10c;
    *(undefined4 *)(iVar3 + 0x1a4) = uStack_118;
    *(undefined4 *)(iVar3 + 0x1a8) = uStack_dc;
    *(undefined4 *)(iVar3 + 0x1b4) = uStack_108;
    *(int *)(iVar3 + 0x1b8) = iStack_124;
    *(undefined4 *)(iVar3 + 0x1ac) = uStack_fc;
    *(undefined4 *)(iVar3 + 0x1b0) = uStack_11c;
    *(ulonglong *)(iVar3 + 0x1bc) = CONCAT44(uStack_94,uStack_98);
    *(ulonglong *)(iVar3 + 0x1c4) = CONCAT44(uStack_9c,uStack_a0);
    *(float *)(iVar3 + 0x1cc) = (float)(double)CONCAT44(uStack_c4,uStack_c8);
    *(float *)(iVar3 + 0x1d0) = (float)(double)CONCAT44(uStack_bc,uStack_c0);
    *(uint *)(iVar3 + 0xb4) = uStack_158;
    *(int *)(iVar3 + 0xb8) = iStack_150;
    *(int *)(iVar3 + 0xc0) = iStack_154;
    *(int *)(iVar3 + 0x23c) = iStack_14c;
    *(undefined4 *)(iVar3 + 0x2ac) = uStack_140;
    *(undefined4 *)(iVar3 + 0x194) = uStack_f4;
    *(int *)(iVar3 + 0x198) = iStack_12c;
    *(undefined4 *)(iVar3 + 0x284) = uStack_ec;
    *(undefined4 *)(iVar3 + 0x288) = uStack_e4;
    *(undefined4 *)(iVar3 + 0x28c) = uStack_104;
    *(undefined4 *)(iVar3 + 0x290) = uStack_f0;
    if (asStack_5c[0] == 0) {
      iVar5 = func_0x10307a77(iVar3 + 0x14);
      if (iVar5 != 0) {
        uVar2 = __DFString__QBEPBGXZ();
        func_0x103072f7(uVar2);
        *(undefined4 *)(iVar3 + 400) = *(undefined4 *)(iVar5 + 0x1c);
        *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x5010) = 0;
      }
    }
    else {
      func_0x103072f7(asStack_5c);
      *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x5010) = 1;
    }
    if (sStack_90 == 0) {
      iVar5 = func_0x10307a77(iVar3 + 0x14);
      if (iVar5 != 0) {
        psVar6 = (short *)__DFString__QBEPBGXZ();
        goto LAB_1043adfd;
      }
    }
    else {
      psVar6 = &sStack_90;
LAB_1043adfd:
      func_0x1030c82e(psVar6);
    }
    *(undefined4 *)(iVar3 + 0x2e8) = uStack_178;
    iVar5 = iVar3 + 0x18;
    if ((0 < *(int *)(iVar3 + 0x18)) && (_DAT_10b1f538 != 0)) {
      iVar7 = func_0x1030d04e(iVar5);
      if (iVar7 != 0) {
        func_0x10314fc4(iVar7);
        func_0x10304a34(iVar5);
      }
      puVar8 = (undefined4 *)
               (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(8,0x10853a28);
      if (puVar8 == (undefined4 *)0x0) {
        puVar8 = (undefined4 *)0x0;
      }
      else {
        *puVar8 = 0;
        puVar8[1] = 0;
      }
      uStack_24 = 0xffffffff;
      if (puVar8 != (undefined4 *)0x0) {
        puVar8[1] = iVar3;
        *puVar8 = 1;
      }
      func_0x1030a60f(iVar5,&stack0xfffffe74);
    }
    fStack_174 = (float)iStack_124;
    fStack_170 = (float)iStack_12c;
    afStack_16c[0] = (float)iStack_114;
    if (0 < uStack_17c) {
      if ((((_DAT_10b1f538 == 0) || (iVar5 = func_0x1030d04e(&uStack_17c), iVar5 == 0)) ||
          (piVar4 = (int *)func_0x1030d04e(&uStack_17c), *piVar4 != 3)) ||
         ((iVar5 = func_0x1030d04e(&uStack_17c), *(int *)(iVar5 + 4) == 0 ||
          (iVar5 = func_0x1030d04e(&uStack_17c), *(int *)(iVar5 + 4) == 0)))) {
        _Logf_FOutputDevice__QAAXPBGZZ
                  (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x1088b478);
      }
      else {
        iVar5 = func_0x1030d04e(&uStack_17c);
        if ((iVar5 == 0) ||
           ((piVar4 = (int *)func_0x1030d04e(&uStack_17c), *piVar4 != 3 ||
            (iVar5 = func_0x1030d04e(&uStack_17c), *(int *)(iVar5 + 4) == 0)))) {
          iVar5 = 0;
        }
        else {
          iVar5 = func_0x1030d04e(&uStack_17c);
          iVar5 = *(int *)(iVar5 + 4);
        }
        afStack_16c[1] = 0.0;
        afStack_16c[2] = 0.0;
        afStack_16c[3] = 1.0;
        pfVar9 = (float *)_RotateAngleAxis_FVector__QBE_AV1_HABV1__Z
                                    (auStack_30,*(uint *)(*(int *)(iVar5 + 4) + 0x1cc) & 0xffff,
                                     afStack_16c + 1);
        iVar5 = *(int *)(iVar5 + 4);
        fStack_174 = *(float *)(iVar5 + 0x1bc) + *pfVar9;
        fStack_170 = *(float *)(iVar5 + 0x1c0) + pfVar9[1];
        afStack_16c[0] = *(float *)(iVar5 + 0x1c4) + pfVar9[2];
      }
    }
    *(undefined4 *)(iVar3 + 0x204) = 0;
    __0L2ParamStack__QAE_H_Z(10);
    uStack_18 = 1;
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_104);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_e4);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_fc);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_ec);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_13c);
    _PushBack_L2ParamStack__QAEHPAX_Z((int)(char)((uint)unaff_EDI >> 0x18));
    _PushBack_L2ParamStack__QAEHPAX_Z(iStack_134);
    (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 600))
              (iVar3,fStack_174,fStack_170,afStack_16c[0],uStack_b8,&uStack_dc);
    if (*(int *)(iVar3 + 0x204) != 0) {
      if (iStack_150 < 1) {
        *(undefined4 *)(*(int *)(iVar3 + 0x204) + 0x6a0) = 0;
      }
      else {
        *(int *)(*(int *)(iVar3 + 0x204) + 0x6a0) = iStack_150;
      }
      if (iStack_14c < 1) {
        *(undefined4 *)(*(int *)(iVar3 + 0x204) + 0x6a4) = 0;
      }
      else {
        *(int *)(*(int *)(iVar3 + 0x204) + 0x6a4) = iStack_14c;
      }
      if (iStack_148 < 1) {
        *(undefined4 *)(*(int *)(iVar3 + 0x204) + 0x6a8) = 0;
      }
      else {
        *(int *)(*(int *)(iVar3 + 0x204) + 0x6a8) = iStack_148;
      }
      *(undefined4 *)(*(int *)(iVar3 + 0x204) + 0x17d0) = uStack_13c;
      *(int *)(*(int *)(iVar3 + 0x204) + 0x778) = (int)cStack_181;
      func_0x103022f7((int)uStack_17c._3_1_);
      *(float *)(*(int *)(iVar3 + 0x204) + 0x2f0) = (float)(double)CONCAT44(uStack_bc,uStack_c0);
      *(float *)(*(int *)(iVar3 + 0x204) + 0x2f4) = (float)(double)CONCAT44(uStack_b4,uStack_b8);
      *(float *)(*(int *)(iVar3 + 0x204) + 0x186c) = (float)(double)CONCAT44(uStack_9c,uStack_a0);
      fStack_174 = (float)dStack_a8;
      *(float *)(*(int *)(iVar3 + 0x204) + 0x1870) = fStack_174;
      *(float *)(*(int *)(iVar3 + 0x204) + 0x1830) = afStack_16c[0];
      if (*(int *)(iVar3 + 0x10) == 0) {
        func_0x1031428b(iVar3 + 0x18,&uStack_180);
        func_0x103095e8();
      }
    }
    if (0 < *(int *)(iVar3 + 0x284)) {
      func_0x10303df5(*(int *)(iVar3 + 0x284),*(undefined4 *)(iVar3 + 0x288),
                      *(undefined4 *)(iVar3 + 0x28c),*(undefined4 *)(iVar3 + 0x290),0,0x80000000);
    }
    uStack_c = 0xffffffff;
    __1L2ParamStack__QAE_XZ();
    goto LAB_1043b270;
  }
  iVar3 = func_0x1030d04e(&uStack_178);
  if ((iVar3 == 0) ||
     ((piVar4 = (int *)func_0x1030d04e(&uStack_17c), *piVar4 != 1 ||
      (iVar3 = func_0x1030d04e(&uStack_17c), *(int *)(iVar3 + 4) == 0)))) {
    iVar3 = 0;
  }
  else {
    iVar3 = func_0x1030d04e(&uStack_17c);
    iVar3 = *(int *)(iVar3 + 4);
  }
  *(undefined4 *)(iVar3 + 8) = 1;
  *(undefined4 *)(iVar3 + 0xc) = uStack_144;
  *(undefined4 *)(iVar3 + 0x94) = 0;
  *(int *)(iVar3 + 0x14) = iStack_130 + -1000000;
  *(undefined4 *)(iVar3 + 0x10) = uStack_138;
  *(undefined4 *)(iVar3 + 0x19c) = uStack_110;
  *(undefined4 *)(iVar3 + 0x1a0) = uStack_108;
  *(int *)(iVar3 + 0x1a4) = iStack_114;
  *(undefined4 *)(iVar3 + 0x1a8) = uStack_d8;
  *(undefined4 *)(iVar3 + 0x1b4) = uStack_104;
  *(undefined4 *)(iVar3 + 0x1b8) = uStack_120;
  *(undefined4 *)(iVar3 + 0x1ac) = uStack_f8;
  *(undefined4 *)(iVar3 + 0x1b0) = uStack_118;
  *(ulonglong *)(iVar3 + 0x1bc) = CONCAT26(uStack_8e,CONCAT24(sStack_90,uStack_94));
  *(ulonglong *)(iVar3 + 0x1c4) = CONCAT44(uStack_98,uStack_9c);
  *(float *)(iVar3 + 0x1cc) = (float)(double)CONCAT44(uStack_c0,uStack_c4);
  *(float *)(iVar3 + 0x1d0) = (float)(double)CONCAT44(uStack_b8,uStack_bc);
  *(int *)(iVar3 + 0xb4) = iStack_154;
  *(int *)(iVar3 + 0xb8) = iStack_14c;
  *(int *)(iVar3 + 0xc0) = iStack_150;
  *(int *)(iVar3 + 0x23c) = iStack_148;
  *(undefined4 *)(iVar3 + 0x2ac) = uStack_13c;
  *(undefined4 *)(iVar3 + 0x194) = uStack_f0;
  *(undefined4 *)(iVar3 + 0x198) = uStack_128;
  *(undefined4 *)(iVar3 + 0x284) = uStack_e8;
  *(undefined4 *)(iVar3 + 0x288) = uStack_e0;
  *(undefined4 *)(iVar3 + 0x28c) = uStack_100;
  *(undefined4 *)(iVar3 + 0x290) = uStack_ec;
  if (asStack_58[0] == 0) {
    iVar5 = func_0x10307a77(iVar3 + 0x14);
    if (iVar5 != 0) {
      uVar2 = __DFString__QBEPBGXZ();
      func_0x103072f7(uVar2);
      *(undefined4 *)(iVar3 + 400) = *(undefined4 *)(iVar5 + 0x1c);
      *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x5010) = 0;
    }
  }
  else {
    func_0x103072f7(asStack_58);
    *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x5010) = 1;
  }
  if (asStack_8c[0] == 0) {
    iVar5 = func_0x10307a77(iVar3 + 0x14);
    if (iVar5 != 0) {
      psVar6 = (short *)__DFString__QBEPBGXZ();
      goto LAB_1043a908;
    }
  }
  else {
    psVar6 = asStack_8c;
LAB_1043a908:
    func_0x1030c82e(psVar6);
  }
  *(float *)(iVar3 + 0x2e8) = fStack_174;
  if (*(int *)(iVar3 + 0x204) != 0) {
    *(uint *)(*(int *)(iVar3 + 0x204) + 0x6a0) = ((int)uStack_158 < 1) - 1 & uStack_158;
    if (iStack_154 < 1) {
      *(undefined4 *)(*(int *)(iVar3 + 0x204) + 0x6a4) = 0;
    }
    else {
      *(int *)(*(int *)(iVar3 + 0x204) + 0x6a4) = iStack_154;
    }
    if (iStack_150 < 1) {
      *(undefined4 *)(*(int *)(iVar3 + 0x204) + 0x6a8) = 0;
    }
    else {
      *(int *)(*(int *)(iVar3 + 0x204) + 0x6a8) = iStack_150;
    }
    *(float *)(*(int *)(iVar3 + 0x204) + 0x6b0) = (float)*(double *)(iVar3 + 0x1bc);
    *(float *)(*(int *)(iVar3 + 0x204) + 0x6b4) = (float)*(double *)(iVar3 + 0x1c4);
    *(float *)(*(int *)(iVar3 + 0x204) + 0x6ec) = (float)*(int *)(iVar3 + 0x19c);
    *(float *)(*(int *)(iVar3 + 0x204) + 0x6f0) = (float)*(int *)(iVar3 + 0x1a0);
    *(float *)(*(int *)(iVar3 + 0x204) + 0x6f4) = (float)*(int *)(iVar3 + 0x1a4);
    *(float *)(*(int *)(iVar3 + 0x204) + 0x6f8) = (float)*(int *)(iVar3 + 0x1a8);
    *(float *)(*(int *)(iVar3 + 0x204) + 0x6fc) = (float)*(int *)(iVar3 + 0x1ac);
    *(float *)(*(int *)(iVar3 + 0x204) + 0x700) = (float)*(int *)(iVar3 + 0x1b0);
    iVar5 = *(int *)(iVar3 + 0x204);
    if (*(char *)(*(int *)(iVar5 + 0x14d8) + 0x434) == '\x01') {
      *(float *)(iVar5 + 0x1550) = *(float *)(iVar5 + 0x6ec) * *(float *)(iVar5 + 0x6b4);
      iVar5 = *(int *)(iVar3 + 0x204);
      *(float *)(iVar5 + 0x1554) = *(float *)(iVar5 + 0x6f4) * *(float *)(iVar5 + 0x6b4);
      iVar5 = *(int *)(iVar3 + 0x204);
      fVar1 = *(float *)(iVar5 + 0x6fc);
    }
    else {
      *(float *)(iVar5 + 0x1550) = *(float *)(iVar5 + 0x6f0) * *(float *)(iVar5 + 0x6b4);
      iVar5 = *(int *)(iVar3 + 0x204);
      *(float *)(iVar5 + 0x1554) = *(float *)(iVar5 + 0x6f8) * *(float *)(iVar5 + 0x6b4);
      iVar5 = *(int *)(iVar3 + 0x204);
      fVar1 = *(float *)(iVar5 + 0x700);
    }
    *(float *)(iVar5 + 0x1558) = fVar1 * *(float *)(iVar5 + 0x6b4);
    *(undefined4 *)(*(int *)(iVar3 + 0x204) + 0x17d0) = uStack_144;
    *(int *)(*(int *)(iVar3 + 0x204) + 0x778) = (int)(char)((uint)unaff_ESI >> 0x18);
    func_0x103022f7((int)cStack_181);
    *(float *)(*(int *)(iVar3 + 0x204) + 0x2f0) = (float)(double)CONCAT44(uStack_c4,uStack_c8);
    *(float *)(*(int *)(iVar3 + 0x204) + 0x2f4) = (float)(double)CONCAT44(uStack_bc,uStack_c0);
    *(float *)(*(int *)(iVar3 + 0x204) + 0x186c) = (float)dStack_a8;
    *(float *)(*(int *)(iVar3 + 0x204) + 0x1870) = (float)uStack_b0;
    *(float *)(*(int *)(iVar3 + 0x204) + 0x1830) = fStack_174;
    if (iStack_130 == 0) {
      uVar2 = 1;
    }
    else {
      if (iStack_130 != 1) goto LAB_1043abad;
      uVar2 = 4;
    }
    afStack_16c[2] = 0.0;
    afStack_16c[3] = 0.0;
    afStack_16c[4] = 1.0;
    (**(code **)(**(int **)(iVar3 + 0x204) + 0x1c8))(uVar2,0,0,0,0x3f800000);
  }
LAB_1043abad:
  if (0 < *(int *)(iVar3 + 0x284)) {
    func_0x10303df5(*(int *)(iVar3 + 0x284),*(undefined4 *)(iVar3 + 0x288),
                    *(undefined4 *)(iVar3 + 0x28c),*(undefined4 *)(iVar3 + 0x290),0,0x80000000);
  }
  func_0x10314583();
LAB_1043b270:
  if ((-1 < iStack_12c + -0x3042) && (iStack_12c + -0x41d2 < 0)) {
    func_0x1031311f();
    (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x314))(2);
    *unaff_FS_OFFSET = uStack_18;
    return 1;
  }
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10852570,uStack_178,
             iStack_12c,iStack_134,uStack_118,uStack_120,uStack_108);
  *unaff_FS_OFFSET = uStack_14;
  return 0;
}

