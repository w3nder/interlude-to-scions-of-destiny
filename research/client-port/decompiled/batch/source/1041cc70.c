
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_1041cc70(int param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  short *psVar6;
  undefined4 uVar7;
  short *psVar8;
  int iVar9;
  float *pfVar10;
  uint uVar11;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  int unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  char cVar12;
  undefined *puVar13;
  undefined4 uStack_1bc;
  undefined4 uStack_1b8;
  float fStack_1b4;
  undefined4 uStack_1b0;
  int iStack_1ac;
  int iStack_1a8;
  undefined4 uStack_1a4;
  uint uStack_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  int iStack_194;
  undefined4 uStack_190;
  int iStack_18c;
  undefined4 uStack_188;
  int iStack_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined4 uStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
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
  uint uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined1 auStack_e0 [4];
  undefined1 auStack_dc [12];
  undefined4 *apuStack_d0 [2];
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined1 auStack_b8 [4];
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 auStack_a0 [3];
  undefined1 auStack_94 [4];
  short asStack_90 [2];
  short asStack_8c [2];
  short asStack_88 [2];
  short asStack_84 [14];
  short asStack_68 [8];
  short asStack_58 [2];
  uint auStack_54 [7];
  undefined1 auStack_38 [20];
  undefined4 uStack_24;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &UNK_1075690b;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  iStack_1ac = 0;
  uStack_13c = 0;
  uStack_180 = 0;
  uStack_fc = 0;
  uStack_104 = 0;
  uStack_110 = 0;
  uStack_e8 = 0;
  auStack_54[0] = auStack_54[0] & 0xffff0000;
  asStack_84[0] = 0;
  uStack_178 = 0;
  func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c6e18,&uStack_f4,&uStack_1bc,
                  &uStack_1b0,&iStack_184,&iStack_18c,&iStack_194,&uStack_198,auStack_b8,&fStack_1b4
                  ,&iStack_1ac,&uStack_13c,&uStack_100,&uStack_e4,auStack_dc,&uStack_108,&uStack_ec,
                  &uStack_10c,&uStack_f0,&uStack_114,&uStack_120,&uStack_128,&uStack_a8,auStack_a0,
                  &uStack_19c,&uStack_188,&uStack_190,&uStack_e8,&uStack_110,&uStack_104,&uStack_fc,
                  &uStack_180,0x30,asStack_84,0x30,auStack_54,asStack_88,auStack_e0,&uStack_f8,
                  &uStack_170,&uStack_134,&uStack_168,&uStack_148,&uStack_160,&uStack_12c,
                  &uStack_140,&uStack_158,&uStack_130,&uStack_ac,&uStack_c4,&uStack_150,&uStack_138,
                  &uStack_174,&uStack_16c,&uStack_164,&uStack_15c,&uStack_154,&uStack_17c,
                  &uStack_14c,&uStack_bc,&uStack_144,&iStack_1ac,&uStack_178,&uStack_c8,
                  (int)&uStack_1b8 + 3,(int)&uStack_1b8 + 2,&uStack_c0,&uStack_b4);
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4eb4) = uStack_f4;
  *(float *)(*(int *)(param_1 + 0x48) + 0x4eb8) = uStack_1bc;
  *(int *)(*(int *)(param_1 + 0x48) + 0x4eec) = iStack_18c;
  *(int *)(*(int *)(param_1 + 0x48) + 0x4ef0) = iStack_194;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4ef4) = uStack_198;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4ef8) = uStack_168;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4efc) = uStack_148;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f00) = uStack_160;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f04) = uStack_12c;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f08) = uStack_140;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f0c) = uStack_158;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f10) = uStack_130;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f14) = uStack_ac;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f18) = uStack_c4;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f1c) = uStack_170;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f20) = uStack_134;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f24) = uStack_150;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f28) = uStack_138;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f2c) = uStack_174;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f30) = uStack_16c;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f34) = uStack_154;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f38) = uStack_14c;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f3c) = uStack_144;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f40) = uStack_164;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f44) = uStack_15c;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f4c) = uStack_bc;
  *(int *)(*(int *)(param_1 + 0x48) + 0x4f50) = iStack_1ac;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f48) = uStack_17c;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f58) = uStack_1b0;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f5c) = uStack_c8;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f60) = uStack_c0;
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f64) = uStack_b4;
  if (asStack_84[0] == 0) {
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x4e4))(1);
  }
  else {
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x4e4))(0);
  }
  if (_DAT_109d5e68 != 0) {
    iVar2 = func_0x1030f3bc(&stack0xfffffe40);
    if (iVar2 != 0) {
      piVar3 = (int *)func_0x1030f3bc(&stack0xfffffe40);
      if (*piVar3 == 1) {
        iVar2 = func_0x1030f3bc(&stack0xfffffe40);
        if (*(int *)(iVar2 + 4) != 0) {
          iVar2 = func_0x1030f3bc(&stack0xfffffe40);
          if (*(int *)(iVar2 + 4) != 0) {
            iVar2 = func_0x1030f3bc(&stack0xfffffe40);
            if (iVar2 == 0) {
LAB_1041d1a2:
              iVar2 = 0;
            }
            else {
              piVar3 = (int *)func_0x1030f3bc(&stack0xfffffe3c);
              if (*piVar3 != 1) goto LAB_1041d1a2;
              iVar2 = func_0x1030f3bc(&stack0xfffffe3c);
              if (*(int *)(iVar2 + 4) == 0) goto LAB_1041d1a2;
              iVar2 = func_0x1030f3bc(&stack0xfffffe3c);
              iVar2 = *(int *)(iVar2 + 4);
            }
            *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4eb8) = unaff_ESI;
            *(undefined4 *)(iVar2 + 0x90) = 0;
            *(undefined4 *)(iVar2 + 8) = 1;
            *(undefined4 *)(iVar2 + 0xc) = 1;
            *(int *)(iVar2 + 0x14) = (int)uStack_1b8 + -1000000;
            *(int *)(iVar2 + 0x10) = iStack_18c;
            *(undefined4 *)(iVar2 + 0xf0) = uStack_108;
            *(undefined4 *)(iVar2 + 0xf4) = uStack_ec;
            *(undefined4 *)(iVar2 + 0xf8) = uStack_e4;
            *(undefined4 *)(iVar2 + 0xfc) = uStack_110;
            *(undefined4 *)(iVar2 + 0x108) = uStack_f4;
            *(undefined4 *)(iVar2 + 0x10c) = uStack_114;
            *(undefined4 *)(iVar2 + 0x100) = uStack_f8;
            *(undefined4 *)(iVar2 + 0x104) = uStack_11c;
            *(undefined4 *)(iVar2 + 0x110) = uStack_130;
            *(undefined4 *)(iVar2 + 0x114) = uStack_12c;
            *(undefined4 *)(iVar2 + 0x118) = uStack_128;
            *(undefined4 *)(iVar2 + 0x11c) = uStack_124;
            *(float *)(iVar2 + 0x120) = (float)(double)CONCAT44(uStack_ac,uStack_b0);
            *(float *)(iVar2 + 0x124) = (float)(double)CONCAT44(uStack_a4,uStack_a8);
            *(undefined4 *)(iVar2 + 0xb0) = uStack_1a4;
            *(undefined4 *)(iVar2 + 0xb4) = uStack_198;
            *(undefined4 *)(iVar2 + 0xbc) = uStack_190;
            *(float *)(iVar2 + 0x18c) = fStack_1b4;
            *(undefined4 *)(iVar2 + 0x1fc) = uStack_144;
            *(undefined4 *)(iVar2 + 0xe8) = uStack_e8;
            *(uint *)(iVar2 + 0xec) = uStack_100;
            *(int *)(iVar2 + 0x180) = iStack_184;
            if (asStack_8c[0] == 0) {
              iVar5 = func_0x1030a083(iVar2 + 0x14);
              if (iVar5 != 0) {
                uVar4 = __DFString__QBEPBGXZ();
                func_0x10309930(uVar4);
                psVar6 = (short *)__DFString__QBEPBGXZ();
                if ((psVar6 == (short *)0x0) || (*psVar6 == 0)) {
                  *(undefined2 *)(*(int *)(param_1 + 0x48) + 0x4ebc) = 0;
                }
                else {
                  wcscpy(*(int *)(param_1 + 0x48) + 0x4ebc,psVar6);
                }
                *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f54) = 0;
              }
            }
            else {
              func_0x10309930(asStack_8c);
              if (asStack_88[0] == 0) {
                *(undefined2 *)(*(int *)(param_1 + 0x48) + 0x4ebc) = 0;
                *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f54) = 1;
              }
              else {
                wcscpy(*(int *)(param_1 + 0x48) + 0x4ebc,asStack_88);
                *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f54) = 1;
              }
            }
            if (asStack_58[0] == 0) {
              iVar5 = func_0x1030a083(iVar2 + 0x14);
              if (iVar5 != 0) {
                psVar6 = (short *)__DFString__QBEPBGXZ();
                goto LAB_1041d3de;
              }
            }
            else {
              psVar6 = asStack_58;
LAB_1041d3de:
              func_0x1030ebba(psVar6);
            }
            *(undefined4 *)(iVar2 + 0xdc) = uStack_174;
            *(undefined4 *)(iVar2 + 0xe0) = uStack_138;
            *(undefined4 *)(iVar2 + 0x78) = uStack_14c;
            *(undefined4 *)(iVar2 + 0x7c) = uStack_16c;
            *(undefined4 *)(iVar2 + 0x80) = uStack_130;
            *(undefined4 *)(iVar2 + 0x84) = uStack_164;
            *(undefined4 *)(iVar2 + 0x168) = uStack_144;
            *(undefined4 *)(iVar2 + 0x58) = uStack_15c;
            *(undefined4 *)(iVar2 + 0x5c) = uStack_134;
            *(undefined4 *)(iVar2 + 0x164) = uStack_154;
            *(undefined4 *)(iVar2 + 0x88) = uStack_13c;
            *(undefined4 *)(iVar2 + 0x174) = uStack_178;
            *(undefined4 *)(iVar2 + 0x17c) = uStack_170;
            *(undefined4 *)(iVar2 + 0x184) = uStack_168;
            *(undefined4 *)(iVar2 + 0x188) = uStack_160;
            *(undefined4 *)(iVar2 + 0x16c) = uStack_158;
            *(undefined4 *)(iVar2 + 0x180) = uStack_180;
            *(undefined4 *)(iVar2 + 0x170) = uStack_150;
            *(undefined4 *)(iVar2 + 0x178) = uStack_148;
            if (*(int *)(iVar2 + 0x158) != 0) {
              *(uint *)(*(int *)(iVar2 + 0x158) + 0x5e8) = ((int)uStack_1a0 < 1) - 1 & uStack_1a0;
              if (iStack_18c < 1) {
                *(undefined4 *)(*(int *)(iVar2 + 0x158) + 0x5ec) = 0;
              }
              else {
                *(int *)(*(int *)(iVar2 + 0x158) + 0x5ec) = iStack_18c;
              }
              if (iStack_194 < 1) {
                *(undefined4 *)(*(int *)(iVar2 + 0x158) + 0x5f0) = 0;
              }
              else {
                *(int *)(*(int *)(iVar2 + 0x158) + 0x5f0) = iStack_194;
              }
              *(float *)(*(int *)(iVar2 + 0x158) + 0x5f8) = (float)*(double *)(iVar2 + 0x110);
              *(float *)(*(int *)(iVar2 + 0x158) + 0x5fc) = (float)*(double *)(iVar2 + 0x118);
              iVar5 = *(int *)(iVar2 + 0x158);
              if (*(char *)(*(int *)(iVar5 + 0x13f0) + 0x41c) == '\x01') {
                fVar1 = *(float *)(iVar5 + 0x634);
              }
              else {
                fVar1 = *(float *)(iVar5 + 0x638);
              }
              *(float *)(iVar5 + 0x1468) = fVar1 * *(float *)(iVar5 + 0x5fc);
              *(undefined4 *)(*(int *)(iVar2 + 0x158) + 0x16c0) = uStack_17c;
              *(int *)(*(int *)(iVar2 + 0x158) + 0x6b0) = (int)uStack_1bc._3_1_;
              if (uStack_1bc._2_1_ == '\0') {
                func_0x1030ae89(4);
                func_0x1030ae89(8);
              }
              else if (uStack_1bc._2_1_ == '\x01') {
                func_0x1030ae89(4);
                func_0x1030f5dd(8);
              }
              else if (uStack_1bc._2_1_ == '\x02') {
                func_0x1030ae89(8);
                func_0x1030f5dd(4);
              }
            }
            goto LAB_1041dd0e;
          }
        }
      }
    }
  }
  if ((iStack_184 != 0) && (iStack_184 != 2)) goto LAB_1041dd0e;
  puVar13 = &UNK_107c6e04;
  uVar4 = 0x248;
  iVar2 = (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(0x248);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = func_0x10302d06();
  }
  *(int *)(iVar2 + 0x18) = unaff_EDI;
  *(int *)(*(int *)(param_1 + 0x48) + 0x4eb8) = unaff_EDI;
  *(undefined4 *)(iVar2 + 0x90) = 0;
  *(undefined4 *)(iVar2 + 8) = 1;
  *(undefined4 *)(iVar2 + 0xc) = 1;
  *(int *)(iVar2 + 0x14) = (int)uStack_1bc + -1000000;
  *(undefined4 *)(iVar2 + 0x10) = uStack_190;
  *(undefined4 *)(iVar2 + 0xf0) = uStack_10c;
  *(undefined4 *)(iVar2 + 0xf4) = uStack_f0;
  *(undefined4 *)(iVar2 + 0xf8) = uStack_e8;
  *(undefined4 *)(iVar2 + 0xfc) = uStack_114;
  psVar6 = (short *)(iVar2 + 0x14);
  *(undefined4 *)(iVar2 + 0x108) = uStack_f8;
  *(undefined4 *)(iVar2 + 0x10c) = uStack_118;
  *(undefined4 *)(iVar2 + 0x100) = uStack_fc;
  *(undefined4 *)(iVar2 + 0x104) = uStack_120;
  *(undefined4 *)(iVar2 + 0x110) = uStack_134;
  *(undefined4 *)(iVar2 + 0x114) = uStack_130;
  *(undefined4 *)(iVar2 + 0x118) = uStack_12c;
  *(undefined4 *)(iVar2 + 0x11c) = uStack_128;
  *(undefined4 *)(iVar2 + 0x110) = uStack_134;
  *(undefined4 *)(iVar2 + 0x114) = uStack_130;
  *(undefined4 *)(iVar2 + 0x118) = uStack_12c;
  *(undefined4 *)(iVar2 + 0x11c) = uStack_128;
  *(float *)(iVar2 + 0x120) = (float)(double)CONCAT44(uStack_b0,uStack_b4);
  *(float *)(iVar2 + 0x124) = (float)(double)CONCAT44(uStack_a8,uStack_ac);
  *(int *)(iVar2 + 0xb0) = iStack_1a8;
  *(undefined4 *)(iVar2 + 0xb4) = uStack_19c;
  *(int *)(iVar2 + 0xbc) = iStack_194;
  *(float *)(iVar2 + 0x18c) = uStack_1b8;
  *(undefined4 *)(iVar2 + 0x1fc) = uStack_148;
  *(undefined4 *)(iVar2 + 0xe8) = uStack_ec;
  *(undefined4 *)(iVar2 + 0xec) = uStack_104;
  if (asStack_90[0] == 0) {
    iVar5 = func_0x1030a083();
    if (iVar5 != 0) {
      uVar7 = __DFString__QBEPBGXZ();
      func_0x10309930(uVar7);
      psVar8 = (short *)__DFString__QBEPBGXZ();
      if ((psVar8 == (short *)0x0) || (*psVar8 == 0)) {
        *(undefined2 *)(*(int *)(param_1 + 0x48) + 0x4ebc) = 0;
      }
      else {
        wcscpy(*(int *)(param_1 + 0x48) + 0x4ebc,psVar8);
      }
      *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f54) = 0;
    }
  }
  else {
    psVar6 = asStack_90;
    func_0x10309930();
    func_0x1030833c(auStack_94);
    *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4f54) = 1;
  }
  if (asStack_68[0] == 0) {
    iVar5 = func_0x1030a083(iVar2 + 0x14);
    if (iVar5 != 0) {
      psVar8 = (short *)__DFString__QBEPBGXZ();
      goto LAB_1041d873;
    }
  }
  else {
    psVar8 = asStack_68;
LAB_1041d873:
    func_0x1030ebba(psVar8);
  }
  *(int *)(iVar2 + 0xdc) = iStack_184;
  *(undefined4 *)(iVar2 + 0xe0) = uStack_148;
  *(undefined4 *)(iVar2 + 0x78) = uStack_15c;
  *(undefined4 *)(iVar2 + 0x7c) = uStack_17c;
  *(undefined4 *)(iVar2 + 0x80) = uStack_140;
  *(undefined4 *)(iVar2 + 0x84) = uStack_174;
  *(undefined4 *)(iVar2 + 0x168) = uStack_154;
  *(undefined4 *)(iVar2 + 0x58) = uStack_16c;
  *(undefined4 *)(iVar2 + 0x5c) = uStack_144;
  *(undefined4 *)(iVar2 + 0x164) = uStack_164;
  *(undefined4 *)(iVar2 + 0x88) = uStack_14c;
  *(undefined4 *)(iVar2 + 0x174) = uStack_188;
  *(undefined4 *)(iVar2 + 0x17c) = uStack_180;
  *(undefined4 *)(iVar2 + 0x184) = uStack_178;
  *(undefined4 *)(iVar2 + 0x188) = uStack_170;
  *(undefined4 *)(iVar2 + 0x16c) = uStack_168;
  *(undefined4 *)(iVar2 + 0x180) = uStack_190;
  *(undefined4 *)(iVar2 + 0x170) = uStack_160;
  iVar5 = iVar2 + 0x18;
  *(undefined4 *)(iVar2 + 0x178) = uStack_158;
  if ((0 < *(int *)(iVar2 + 0x18)) && (_DAT_109d5e68 != 0)) {
    iVar9 = func_0x1030f3bc(iVar5);
    if (iVar9 != 0) {
      func_0x10306203(iVar9);
      func_0x1030720c(iVar5);
    }
    apuStack_d0[0] =
         (undefined4 *)(**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(8,&UNK_10792bd0)
    ;
    if (apuStack_d0[0] == (undefined4 *)0x0) {
      apuStack_d0[0] = (undefined4 *)0x0;
    }
    else {
      *apuStack_d0[0] = 0;
      apuStack_d0[0][1] = 0;
    }
    if (apuStack_d0[0] != (undefined4 *)0x0) {
      apuStack_d0[0][1] = iVar2;
      *apuStack_d0[0] = 1;
    }
    func_0x1030cb1c(iVar5,apuStack_d0);
  }
  uStack_1bc = (float)(int)uStack_1a0;
  uStack_1b8 = (float)iStack_1a8;
  fStack_1b4 = (float)iStack_1ac;
  if (0 < unaff_EDI) {
    if (_DAT_109d5e68 != 0) {
      iVar5 = func_0x1030f3bc(&stack0xfffffe38);
      if (iVar5 != 0) {
        piVar3 = (int *)func_0x1030f3bc(&stack0xfffffe38);
        if (*piVar3 == 3) {
          iVar5 = func_0x1030f3bc(&stack0xfffffe38);
          if (*(int *)(iVar5 + 4) != 0) {
            iVar5 = func_0x1030f3bc(&stack0xfffffe38);
            if (*(int *)(iVar5 + 4) != 0) {
              iVar5 = func_0x1030f3bc(&stack0xfffffe38);
              if (iVar5 == 0) {
LAB_1041da9f:
                iVar5 = 0;
              }
              else {
                piVar3 = (int *)func_0x1030f3bc(&stack0xfffffe38);
                if (*piVar3 != 3) goto LAB_1041da9f;
                iVar5 = func_0x1030f3bc(&stack0xfffffe38);
                if (*(int *)(iVar5 + 4) == 0) goto LAB_1041da9f;
                iVar5 = func_0x1030f3bc(&stack0xfffffe38);
                iVar5 = *(int *)(iVar5 + 4);
              }
              uStack_a8 = 0;
              uStack_a4 = 0;
              auStack_a0[0] = 0x3f800000;
              pfVar10 = (float *)_RotateAngleAxis_FVector__QBE_AV1_HABV1__Z
                                           (auStack_38,
                                            *(uint *)(*(int *)(iVar5 + 4) + 0x1cc) & 0xffff,
                                            &uStack_a8);
              iVar5 = *(int *)(iVar5 + 4);
              uStack_1bc = *pfVar10 + *(float *)(iVar5 + 0x1bc);
              uStack_1b8 = pfVar10[1] + *(float *)(iVar5 + 0x1c0);
              fStack_1b4 = pfVar10[2] + *(float *)(iVar5 + 0x1c4);
              goto LAB_1041db58;
            }
          }
        }
      }
    }
    _Logf_FOutputDevice__QAAXPBGZZ
              (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c6d80);
    (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
              (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c6d80);
  }
LAB_1041db58:
  *(undefined4 *)(iVar2 + 0x158) = 0;
  func_0x1030218f(10);
  uStack_24 = 0;
  func_0x103012c1();
  func_0x103012c1(uStack_12c);
  func_0x103012c1(uStack_124);
  func_0x103012c1(uStack_120);
  func_0x103012c1(iStack_1a8);
  func_0x103012c1((int)(char)(uStack_100 >> 0x18));
  uVar7 = uStack_e8;
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x19c))
            (iVar2,psVar6,uVar4,puVar13,uStack_e8,&uStack_108);
  if (*(int *)(iVar2 + 0x158) != 0) {
    *(uint *)(*(int *)(iVar2 + 0x158) + 0x5e8) = ((int)uStack_100 < 1) - 1 & uStack_100;
    if ((int)puVar13 < 1) {
      *(undefined4 *)(*(int *)(iVar2 + 0x158) + 0x5ec) = 0;
    }
    else {
      *(undefined **)(*(int *)(iVar2 + 0x158) + 0x5ec) = puVar13;
    }
    if ((int)psVar6 < 1) {
      *(undefined4 *)(*(int *)(iVar2 + 0x158) + 0x5f0) = 0;
    }
    else {
      *(short **)(*(int *)(iVar2 + 0x158) + 0x5f0) = psVar6;
    }
    *(undefined4 *)(*(int *)(iVar2 + 0x158) + 0x16c0) = unaff_EBX;
    cVar12 = (char)((uint)uVar7 >> 0x10);
    if (cVar12 == '\0') {
      func_0x1030ae89(4);
      func_0x1030ae89(8);
    }
    else if (cVar12 == '\x01') {
      func_0x1030ae89(4);
      func_0x1030f5dd(8);
    }
    else if (cVar12 == '\x02') {
      func_0x1030ae89(8);
      func_0x1030f5dd(4);
    }
  }
  auStack_54[0] = 0xffffffff;
  func_0x10307f3b();
LAB_1041dd0e:
  if ((iStack_184 == 0) || (iStack_184 == 2)) {
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x4dc))(uStack_f8);
  }
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c6cd0,unaff_EBX,
             fStack_1b4,uStack_188,uStack_190,uStack_198,uStack_19c);
  uVar11 = (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                     (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c6cd0,unaff_EBX,fStack_1b4,
                      uStack_188,uStack_190,uStack_198,uStack_19c);
  *unaff_FS_OFFSET = uStack_18;
  return uVar11 & 0xffffff00;
}

