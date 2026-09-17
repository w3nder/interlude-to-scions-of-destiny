
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10410a70(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int iStack_188;
  undefined1 auStack_184 [16];
  undefined4 uStack_174;
  undefined4 uStack_170;
  int iStack_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined1 auStack_158 [4];
  int iStack_154;
  short asStack_150 [24];
  undefined1 auStack_120 [48];
  undefined1 auStack_f0 [4];
  undefined1 auStack_ec [4];
  undefined1 auStack_e8 [4];
  undefined1 auStack_e4 [4];
  undefined1 auStack_e0 [4];
  undefined1 auStack_dc [4];
  undefined1 auStack_d8 [4];
  undefined1 auStack_d4 [24];
  undefined1 auStack_bc [4];
  undefined1 auStack_b8 [48];
  undefined1 auStack_88 [12];
  undefined1 auStack_7c [16];
  undefined1 auStack_6c [48];
  undefined1 auStack_3c [48];
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  uStack_8 = 0x1080ec2c;
  *unaff_FS_OFFSET = &uStack_c;
  func_0x1030459d();
  uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x10885028,auStack_158,0x30,
                          auStack_3c,&iStack_154,&iStack_16c,0x30,asStack_150,0x30,auStack_120);
  if ((iStack_154 != 0) && (asStack_150[0] != 0)) {
    uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x10885018,auStack_d4,auStack_f0,
                            auStack_ec,auStack_e8,auStack_e4,auStack_e0,auStack_dc,auStack_d8,
                            auStack_bc,0x30,auStack_b8,auStack_88,auStack_7c);
  }
  if (iStack_16c == 0) {
    (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x514))(&iStack_154);
    (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x518))();
  }
  uVar2 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1087ff8c,&iStack_188);
  iVar4 = 0;
  uVar3 = uVar2;
  if (0 < iStack_188) {
    do {
      uVar3 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar3,0x1088500c,0x30,auStack_6c,
                              &uStack_168,&uStack_164,&uStack_15c,&uStack_160,&uStack_174,
                              &uStack_170);
      __0L2ParamStack__QAE_H_Z(10);
      uStack_4 = 0;
      _PushBack_L2ParamStack__QAEHPAX_Z(auStack_6c);
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_168);
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_164);
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_15c);
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_160);
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_174);
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_170);
      (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x51c))(auStack_184);
      uStack_4 = 0xffffffff;
      uVar2 = __1L2ParamStack__QAE_XZ();
      iVar4 = iVar4 + 1;
    } while (iVar4 < iStack_188);
  }
  *unaff_FS_OFFSET = uStack_c;
  return uVar2 & 0xffffff00;
}

