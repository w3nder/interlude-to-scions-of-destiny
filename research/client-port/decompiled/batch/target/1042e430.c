
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_1042e430(int param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  short *psVar6;
  int iVar7;
  float *pfVar8;
  float unaff_ESI;
  int iVar9;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  short *psStack_1e0;
  short *psStack_1dc;
  short *psStack_1d8;
  undefined4 *puStack_1d4;
  float fStack_1c4;
  undefined4 uStack_1c0;
  undefined1 auStack_1bc [4];
  undefined1 auStack_1b8 [4];
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  int iStack_1ac;
  uint uStack_1a8;
  undefined4 uStack_1a4;
  int iStack_1a0;
  undefined4 uStack_19c;
  int iStack_198;
  int iStack_194;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined4 uStack_178;
  int iStack_174;
  undefined4 uStack_170;
  int iStack_16c;
  undefined4 uStack_168;
  int iStack_164;
  short *psStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
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
  undefined1 auStack_f4 [4];
  undefined4 auStack_f0 [3];
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined1 auStack_d0 [8];
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined1 auStack_b0 [8];
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined1 auStack_94 [4];
  short asStack_90 [2];
  short asStack_8c [2];
  undefined1 auStack_88 [4];
  short asStack_84 [14];
  short asStack_68 [8];
  short asStack_58 [2];
  undefined2 auStack_54 [14];
  undefined1 auStack_38 [12];
  undefined4 uStack_2c;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  uStack_10 = 0x108100fa;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  puStack_1d4 = &uStack_bc;
  psStack_1d8 = (short *)&uStack_c8;
  psStack_1dc = (short *)(auStack_1bc + 2);
  psStack_1e0 = (short *)(auStack_1bc + 3);
  uStack_1b4 = 0;
  iStack_174 = 0;
  iStack_194 = 0;
  uStack_110 = 0;
  uStack_11c = 0;
  uStack_104 = 0;
  uStack_fc = 0;
  auStack_54[0] = 0;
  asStack_84[0] = 0;
  uStack_168 = 0;
  func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x1088a748,&uStack_108,&fStack_1c4,
                  &iStack_1a0,&uStack_148,&uStack_150,&uStack_158,&psStack_160,&uStack_dc,
                  auStack_1b8,&uStack_1b4,&iStack_174,&uStack_128,&uStack_124,auStack_f0,&uStack_114
                  ,&uStack_120,&uStack_100,&uStack_f8,&uStack_118,auStack_d0,&uStack_d8,&uStack_b8,
                  auStack_b0,&uStack_1a4,&uStack_190,&uStack_19c,&uStack_fc,&uStack_104,&uStack_11c,
                  &uStack_110,&iStack_194,0x30,asStack_84,0x30,auStack_54,auStack_88,auStack_f4,
                  &uStack_10c,&uStack_140,&uStack_138,&uStack_144,&uStack_184,&uStack_154,
                  &uStack_17c,&uStack_18c,&uStack_134,&uStack_130,&uStack_a0,&uStack_a8,&iStack_16c,
                  &uStack_14c,&iStack_164,&uStack_13c,&uStack_15c,&uStack_188,&uStack_180,
                  &iStack_198,&uStack_178,&uStack_c0,&uStack_170,&uStack_1b4,&uStack_168,&uStack_c4)
  ;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f64) = uStack_108;
  *(float *)(*(int *)(param_1 + 0x48) + 0x4f68) = fStack_1c4;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f9c) = uStack_150;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4fa0) = uStack_158;
  *(short **)(*(int *)(param_1 + 0x48) + 0x4fa4) = psStack_160;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4fa8) = uStack_144;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4fac) = uStack_184;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4fb0) = uStack_154;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4fb4) = uStack_17c;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4fb8) = uStack_18c;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4fbc) = uStack_134;
  iVar9 = *(int *)(param_1 + 0x48);
  *(undefined4 *)(iVar9 + 0x4fc0) = uStack_130;
  *(undefined4 *)(iVar9 + 0x4fc4) = uStack_12c;
  iVar9 = *(int *)(param_1 + 0x48);
  *(undefined4 *)(iVar9 + 0x4fc8) = uStack_a0;
  *(undefined4 *)(iVar9 + 0x4fcc) = uStack_9c;
  iVar9 = *(int *)(param_1 + 0x48);
  *(undefined4 *)(iVar9 + 0x4fd0) = uStack_a8;
  *(undefined4 *)(iVar9 + 0x4fd4) = uStack_a4;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4fd8) = uStack_140;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4fdc) = uStack_138;
  *(int *)(*(int *)(param_1 + 0x48) + 0x4fe0) = iStack_16c;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4fe4) = uStack_14c;
  *(int *)(*(int *)(param_1 + 0x48) + 0x4fe8) = iStack_164;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4fec) = uStack_13c;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4ff0) = uStack_180;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4ff4) = uStack_178;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4ff8) = uStack_170;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4ffc) = uStack_15c;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x5000) = uStack_188;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x5008) = uStack_c0;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x500c) = uStack_1b4;
  *(int *)(*(int *)(param_1 + 0x48) + 0x5004) = iStack_198;
  *(int *)(*(int *)(param_1 + 0x48) + 0x5014) = iStack_1a0;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x5018) = uStack_c4;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x501c) = uStack_c8;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x5020) = uStack_bc;
  if (asStack_84[0] == 0) {
    puStack_1d4 = (undefined4 *)0x1;
    psStack_1d8 = (short *)0x1042e8d5;
    (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x4fc))();
  }
  else {
    puStack_1d4 = (undefined4 *)0x0;
    psStack_1d8 = (short *)0x1042e8bf;
    (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x4fc))();
  }
  iVar9 = 0;
  if (_DAT_10b1f538 != 0) {
    psStack_1d8 = (short *)&stack0xfffffe38;
    psStack_1dc = (short *)0x1042e8f6;
    iVar2 = func_0x1030d04e();
    if (iVar2 != 0) {
      psStack_1d8 = (short *)&stack0xfffffe38;
      psStack_1dc = (short *)0x1042e90a;
      piVar3 = (int *)func_0x1030d04e();
      if (*piVar3 == 1) {
        psStack_1d8 = (short *)&stack0xfffffe38;
        psStack_1dc = (short *)0x1042e91f;
        iVar2 = func_0x1030d04e();
        if (*(int *)(iVar2 + 4) != 0) {
          psStack_1d8 = (short *)&stack0xfffffe38;
          psStack_1dc = (short *)0x1042e934;
          iVar2 = func_0x1030d04e();
          if (*(int *)(iVar2 + 4) != 0) {
            psStack_1d8 = (short *)&stack0xfffffe38;
            psStack_1dc = (short *)0x1042e949;
            iVar9 = func_0x1030d04e();
            if (iVar9 == 0) {
LAB_1042e980:
              iVar9 = 0;
            }
            else {
              psStack_1dc = (short *)&stack0xfffffe34;
              psStack_1e0 = (short *)0x1042e959;
              piVar3 = (int *)func_0x1030d04e();
              if (*piVar3 != 1) goto LAB_1042e980;
              psStack_1dc = (short *)&stack0xfffffe34;
              psStack_1e0 = (short *)0x1042e96a;
              iVar9 = func_0x1030d04e();
              if (*(int *)(iVar9 + 4) == 0) goto LAB_1042e980;
              psStack_1dc = (short *)&stack0xfffffe34;
              psStack_1e0 = (short *)0x1042e97b;
              iVar9 = func_0x1030d04e();
              iVar9 = *(int *)(iVar9 + 4);
            }
            *(float *)(*(int *)(param_1 + 0x48) + 0x4f68) = unaff_ESI;
            *(undefined4 *)(iVar9 + 0x94) = 0;
            *(undefined4 *)(iVar9 + 8) = 1;
            *(undefined4 *)(iVar9 + 0xc) = 1;
            *(uint *)(iVar9 + 0x14) = uStack_1a8 - 1000000;
            *(undefined4 *)(iVar9 + 0x10) = uStack_150;
            *(undefined4 *)(iVar9 + 0x19c) = uStack_130;
            *(undefined4 *)(iVar9 + 0x1a0) = uStack_12c;
            *(undefined4 *)(iVar9 + 0x1a4) = uStack_f8;
            psStack_1dc = (short *)(iVar9 + 0x14);
            *(undefined4 *)(iVar9 + 0x1a8) = uStack_11c;
            *(undefined4 *)(iVar9 + 0x1b4) = uStack_128;
            *(undefined4 *)(iVar9 + 0x1b8) = uStack_108;
            *(undefined4 *)(iVar9 + 0x1ac) = uStack_100;
            *(undefined4 *)(iVar9 + 0x1b0) = uStack_120;
            *(ulonglong *)(iVar9 + 0x1bc) = CONCAT44(uStack_dc,uStack_e0);
            *(ulonglong *)(iVar9 + 0x1c4) = CONCAT44(uStack_d4,uStack_d8);
            *(float *)(iVar9 + 0x1cc) = (float)(double)CONCAT44(uStack_bc,uStack_c0);
            *(float *)(iVar9 + 0x1d0) = (float)(double)CONCAT44(uStack_b4,uStack_b8);
            *(int *)(iVar9 + 0xb4) = iStack_1ac;
            *(undefined4 *)(iVar9 + 0xb8) = uStack_1a4;
            *(int *)(iVar9 + 0xc0) = iStack_198;
            *(undefined1 (*) [4])(iVar9 + 0x23c) = auStack_1bc;
            *(undefined4 *)(iVar9 + 0x2ac) = uStack_17c;
            *(undefined4 *)(iVar9 + 0x194) = uStack_fc;
            *(undefined4 *)(iVar9 + 0x198) = uStack_114;
            *(int *)(iVar9 + 0x230) = iStack_1a0;
            if (asStack_8c[0] == 0) {
              psStack_1e0 = (short *)0x1042eaf7;
              iVar2 = func_0x10307a77();
              if (iVar2 != 0) {
                psStack_1d8 = (short *)0x1042eb06;
                psStack_1d8 = (short *)__DFString__QBEPBGXZ();
                psStack_1dc = (short *)0x1042eb0e;
                func_0x103072f7();
                psStack_1dc = (short *)0x1042eb16;
                psStack_1dc = (short *)__DFString__QBEPBGXZ();
                psStack_1e0 = (short *)0x1042eb25;
                func_0x10305beb();
                *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x5010) = 0;
              }
            }
            else {
              psStack_1dc = asStack_8c;
              psStack_1e0 = (short *)0x1042eaca;
              func_0x103072f7();
              psStack_1e0 = asStack_90;
              func_0x10305beb();
              *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x5010) = 1;
            }
            if (asStack_58[0] == 0) {
              psStack_1d8 = (short *)(iVar9 + 0x14);
              psStack_1dc = (short *)0x1042eb56;
              iVar2 = func_0x10307a77();
              if (iVar2 != 0) {
                psStack_1d8 = (short *)0x1042eb63;
                psStack_1d8 = (short *)__DFString__QBEPBGXZ();
                goto LAB_1042eb63;
              }
            }
            else {
              psStack_1d8 = asStack_58;
LAB_1042eb63:
              psStack_1dc = (short *)0x1042eb6b;
              func_0x1030c82e();
            }
            *(undefined4 *)(iVar9 + 0x188) = uStack_144;
            *(undefined4 *)(iVar9 + 0x18c) = uStack_13c;
            *(undefined4 *)(iVar9 + 0x7c) = uStack_188;
            *(undefined4 *)(iVar9 + 0x80) = uStack_148;
            *(undefined4 *)(iVar9 + 0x84) = uStack_180;
            *(undefined4 *)(iVar9 + 0x88) = uStack_158;
            *(undefined4 *)(iVar9 + 0x218) = uStack_190;
            *(undefined4 *)(iVar9 + 0x58) = uStack_138;
            *(undefined4 *)(iVar9 + 0x5c) = uStack_134;
            *(undefined4 *)(iVar9 + 0x60) = uStack_130;
            *(undefined4 *)(iVar9 + 0x214) = uStack_170;
            *(undefined4 *)(iVar9 + 0x8c) = uStack_150;
            *(undefined4 *)(iVar9 + 0x224) = uStack_168;
            *(undefined4 *)(iVar9 + 0x22c) = uStack_140;
            *(short **)(iVar9 + 0x234) = psStack_160;
            *(undefined4 *)(iVar9 + 0x238) = uStack_18c;
            *(undefined4 *)(iVar9 + 0x21c) = uStack_184;
            *(undefined4 *)(iVar9 + 0x230) = uStack_19c;
            *(undefined4 *)(iVar9 + 0x220) = uStack_17c;
            *(int *)(iVar9 + 0x228) = iStack_174;
            if (*(int *)(iVar9 + 0x204) != 0) {
              *(uint *)(*(int *)(iVar9 + 0x204) + 0x6a0) = ((int)uStack_1a8 < 1) - 1 & uStack_1a8;
              if (iStack_194 < 1) {
                *(undefined4 *)(*(int *)(iVar9 + 0x204) + 0x6a4) = 0;
              }
              else {
                *(int *)(*(int *)(iVar9 + 0x204) + 0x6a4) = iStack_194;
              }
              if (iStack_1a0 < 1) {
                *(undefined4 *)(*(int *)(iVar9 + 0x204) + 0x6a8) = 0;
              }
              else {
                *(int *)(*(int *)(iVar9 + 0x204) + 0x6a8) = iStack_1a0;
              }
              *(float *)(*(int *)(iVar9 + 0x204) + 0x6b0) = (float)*(double *)(iVar9 + 0x1bc);
              fStack_1c4 = (float)*(double *)(iVar9 + 0x1c4);
              *(float *)(*(int *)(iVar9 + 0x204) + 0x6b4) = fStack_1c4;
              iVar2 = *(int *)(iVar9 + 0x204);
              if (*(char *)(*(int *)(iVar2 + 0x14d8) + 0x434) == '\x01') {
                fVar1 = *(float *)(iVar2 + 0x6ec);
              }
              else {
                fVar1 = *(float *)(iVar2 + 0x6f0);
              }
              *(float *)(iVar2 + 0x1550) = fVar1 * *(float *)(iVar2 + 0x6b4);
              *(int *)(*(int *)(iVar9 + 0x204) + 0x17d0) = iStack_16c;
              *(int *)(*(int *)(iVar9 + 0x204) + 0x778) = (int)uStack_1c0._3_1_;
              psStack_1d8 = (short *)(int)uStack_1c0._2_1_;
              psStack_1dc = (short *)0x1042ed38;
              func_0x103022f7();
            }
            goto LAB_1042ed3a;
          }
        }
      }
    }
  }
  if ((iStack_198 != 0) && (iStack_198 != 2)) goto LAB_1042ed3a;
  psStack_1d8 = (short *)0x1088a684;
  psStack_1dc = (short *)0x314;
  psStack_1e0 = (short *)0x1042edee;
  iVar9 = (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)();
  if (iVar9 == 0) {
    iVar9 = 0;
  }
  else {
    psStack_1e0 = (short *)0x1042edf9;
    iVar9 = func_0x10313449();
  }
  *(undefined4 *)(iVar9 + 0x18) = unaff_EDI;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f68) = unaff_EDI;
  *(undefined4 *)(iVar9 + 0x94) = 0;
  *(undefined4 *)(iVar9 + 8) = 1;
  *(undefined4 *)(iVar9 + 0xc) = 1;
  *(int *)(iVar9 + 0x14) = iStack_1ac + -1000000;
  *(undefined4 *)(iVar9 + 0x10) = uStack_154;
  *(undefined4 *)(iVar9 + 0x19c) = uStack_134;
  *(undefined4 *)(iVar9 + 0x1a0) = uStack_130;
  *(undefined4 *)(iVar9 + 0x1a4) = uStack_fc;
  psStack_1e0 = (short *)(iVar9 + 0x14);
  *(undefined4 *)(iVar9 + 0x1a8) = uStack_120;
  *(undefined4 *)(iVar9 + 0x1b4) = uStack_12c;
  *(undefined4 *)(iVar9 + 0x1b8) = uStack_10c;
  *(undefined4 *)(iVar9 + 0x1ac) = uStack_104;
  *(undefined4 *)(iVar9 + 0x1b0) = uStack_124;
  *(double *)(iVar9 + 0x1bc) = (double)(float)(double)CONCAT44(uStack_e0,uStack_e4);
  unaff_ESI = (float)(double)CONCAT44(uStack_d8,uStack_dc);
  *(double *)(iVar9 + 0x1c4) = (double)unaff_ESI;
  *(ulonglong *)(iVar9 + 0x1bc) = CONCAT44(uStack_e0,uStack_e4);
  *(ulonglong *)(iVar9 + 0x1c4) = CONCAT44(uStack_d8,uStack_dc);
  *(float *)(iVar9 + 0x1cc) = (float)(double)CONCAT44(uStack_c0,uStack_c4);
  *(float *)(iVar9 + 0x1d0) = (float)(double)CONCAT44(uStack_b8,uStack_bc);
  *(undefined4 *)(iVar9 + 0xb4) = uStack_1b0;
  *(uint *)(iVar9 + 0xb8) = uStack_1a8;
  *(undefined4 *)(iVar9 + 0xc0) = uStack_19c;
  *(float *)(iVar9 + 0x23c) = uStack_1c0;
  *(undefined4 *)(iVar9 + 0x2ac) = uStack_180;
  *(undefined4 *)(iVar9 + 0x194) = uStack_100;
  *(undefined4 *)(iVar9 + 0x198) = uStack_118;
  if (asStack_90[0] == 0) {
    iVar2 = func_0x10307a77();
    if (iVar2 != 0) {
      puStack_1d4 = (undefined4 *)(iVar2 + 4);
      uVar5 = __DFString__QBEPBGXZ();
      func_0x103072f7(uVar5);
      uVar5 = __DFString__QBEPBGXZ();
      func_0x10305beb(uVar5);
      *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x5010) = 0;
    }
  }
  else {
    psStack_1e0 = asStack_90;
    func_0x103072f7();
    func_0x10305beb(auStack_94);
    *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x5010) = 1;
  }
  if (asStack_68[0] == 0) {
    iVar2 = func_0x10307a77(iVar9 + 0x14);
    if (iVar2 != 0) {
      psVar6 = (short *)__DFString__QBEPBGXZ();
      goto LAB_1042f004;
    }
  }
  else {
    psVar6 = asStack_68;
LAB_1042f004:
    func_0x1030c82e(psVar6);
  }
  *(undefined4 *)(iVar9 + 0x188) = uStack_154;
  *(undefined4 *)(iVar9 + 0x18c) = uStack_14c;
  *(int *)(iVar9 + 0x7c) = iStack_198;
  *(undefined4 *)(iVar9 + 0x80) = uStack_158;
  *(undefined4 *)(iVar9 + 0x84) = uStack_190;
  *(undefined4 *)(iVar9 + 0x88) = uStack_168;
  *(int *)(iVar9 + 0x218) = iStack_1a0;
  *(undefined4 *)(iVar9 + 0x58) = uStack_148;
  *(undefined4 *)(iVar9 + 0x5c) = uStack_144;
  *(undefined4 *)(iVar9 + 0x60) = uStack_140;
  *(undefined4 *)(iVar9 + 0x214) = uStack_180;
  *(short **)(iVar9 + 0x8c) = psStack_160;
  *(undefined4 *)(iVar9 + 0x224) = uStack_178;
  *(undefined4 *)(iVar9 + 0x22c) = uStack_150;
  *(undefined4 *)(iVar9 + 0x234) = uStack_170;
  *(undefined4 *)(iVar9 + 0x238) = uStack_19c;
  *(int *)(iVar9 + 0x21c) = iStack_194;
  *(int *)(iVar9 + 0x230) = iStack_1ac;
  *(undefined4 *)(iVar9 + 0x220) = uStack_18c;
  iVar2 = iVar9 + 0x18;
  *(undefined4 *)(iVar9 + 0x228) = uStack_184;
  if ((0 < *(int *)(iVar9 + 0x18)) && (_DAT_10b1f538 != 0)) {
    iVar7 = func_0x1030d04e(iVar2);
    if (iVar7 != 0) {
      func_0x10314fc4(iVar7);
      func_0x10304a34(iVar2);
    }
    psStack_1e0 = (short *)(**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)
                                     (8,0x10853a28);
    if (psStack_1e0 == (short *)0x0) {
      psStack_1e0 = (short *)0x0;
    }
    else {
      psStack_1e0[0] = 0;
      psStack_1e0[1] = 0;
      psStack_1e0[2] = 0;
      psStack_1e0[3] = 0;
    }
    uStack_2c = 0xffffffff;
    if (psStack_1e0 != (short *)0x0) {
      *(int *)(psStack_1e0 + 2) = iVar9;
      psStack_1e0[0] = 1;
      psStack_1e0[1] = 0;
    }
    func_0x1030a60f(iVar2,&psStack_1e0);
  }
  fStack_1c4 = (float)iStack_164;
  uStack_1c0 = (float)iStack_16c;
  auStack_1bc = (undefined1  [4])(float)iStack_174;
  if (0 < (int)unaff_ESI) {
    if ((((_DAT_10b1f538 == 0) || (iVar2 = func_0x1030d04e(&stack0xfffffe34), iVar2 == 0)) ||
        (piVar3 = (int *)func_0x1030d04e(&stack0xfffffe34), *piVar3 != 3)) ||
       ((iVar2 = func_0x1030d04e(&stack0xfffffe34), *(int *)(iVar2 + 4) == 0 ||
        (iVar2 = func_0x1030d04e(&stack0xfffffe34), *(int *)(iVar2 + 4) == 0)))) {
      _Logf_FOutputDevice__QAAXPBGZZ
                (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x1088a600);
    }
    else {
      iVar2 = func_0x1030d04e(&stack0xfffffe34);
      if ((iVar2 == 0) ||
         ((piVar3 = (int *)func_0x1030d04e(&stack0xfffffe34), *piVar3 != 3 ||
          (iVar2 = func_0x1030d04e(&stack0xfffffe34), *(int *)(iVar2 + 4) == 0)))) {
        iVar2 = 0;
      }
      else {
        iVar2 = func_0x1030d04e(&stack0xfffffe34);
        iVar2 = *(int *)(iVar2 + 4);
      }
      uStack_a8 = 0;
      uStack_a4 = 0;
      uStack_a0 = 0x3f800000;
      pfVar8 = (float *)_RotateAngleAxis_FVector__QBE_AV1_HABV1__Z
                                  (auStack_38,*(uint *)(*(int *)(iVar2 + 4) + 0x1cc) & 0xffff,
                                   &uStack_a8);
      iVar2 = *(int *)(iVar2 + 4);
      fStack_1c4 = *pfVar8 + *(float *)(iVar2 + 0x1bc);
      uStack_1c0 = *(float *)(iVar2 + 0x1c0) + pfVar8[1];
      auStack_1bc = (undefined1  [4])(*(float *)(iVar2 + 0x1c4) + pfVar8[2]);
    }
  }
  *(undefined4 *)(iVar9 + 0x204) = 0;
  __0L2ParamStack__QAE_H_Z(10);
  uStack_20 = 1;
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_110);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_118);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_130);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_124);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_1a8);
  _PushBack_L2ParamStack__QAEHPAX_Z((int)(char)((uint)unaff_EDI >> 0x18));
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 600))
            (iVar9,fStack_1c4,uStack_1c0,auStack_1bc,auStack_f0[0],&uStack_100);
  if (*(int *)(iVar9 + 0x204) != 0) {
    *(uint *)(*(int *)(iVar9 + 0x204) + 0x6a0) = ((int)uStack_1a8 < 1) - 1 & uStack_1a8;
    if (iStack_194 < 1) {
      *(undefined4 *)(*(int *)(iVar9 + 0x204) + 0x6a4) = 0;
    }
    else {
      *(int *)(*(int *)(iVar9 + 0x204) + 0x6a4) = iStack_194;
    }
    if (iStack_1a0 < 1) {
      *(undefined4 *)(*(int *)(iVar9 + 0x204) + 0x6a8) = 0;
    }
    else {
      *(int *)(*(int *)(iVar9 + 0x204) + 0x6a8) = iStack_1a0;
    }
    *(int *)(*(int *)(iVar9 + 0x204) + 0x17d0) = iStack_16c;
    psStack_1d8 = (short *)(int)uStack_1c0._2_1_;
    psStack_1dc = (short *)0x1042f432;
    func_0x103022f7();
  }
  uStack_10 = 0xffffffff;
  psStack_1d8 = (short *)0x1042f44a;
  __1L2ParamStack__QAE_XZ();
LAB_1042ed3a:
  if ((iStack_198 == 0) || (iStack_198 == 2)) {
    psStack_1d8 = (short *)uStack_10c;
    psStack_1dc = (short *)0x1042ed61;
    (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x4f4))();
  }
  psStack_1dc = (short *)0x1042ed72;
  psStack_1d8 = (short *)iVar9;
  (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x6f4))();
  psStack_1dc = (short *)uStack_168;
  psStack_1e0 = psStack_160;
  uVar4 = _Logf_FOutputDevice__QAAXPBGZZ
                    (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x1088a698,unaff_ESI,
                     uStack_1a8,uStack_150,uStack_158);
  *unaff_FS_OFFSET = uStack_1c;
  return uVar4 & 0xffffff00;
}

