
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10438df0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 *puStack_180;
  undefined4 *puStack_17c;
  int iStack_158;
  undefined4 uStack_154;
  undefined1 auStack_150 [16];
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined1 auStack_128 [4];
  int iStack_124;
  short sStack_120;
  undefined1 auStack_108 [48];
  undefined4 uStack_d8;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  uint uStack_bc;
  uint uStack_b8;
  undefined1 auStack_b4 [4];
  undefined4 uStack_b0;
  undefined1 auStack_ac [4];
  undefined1 auStack_a8 [4];
  undefined4 uStack_a4;
  undefined1 auStack_a0 [20];
  undefined4 uStack_8c;
  undefined1 auStack_88 [24];
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_58;
  int iStack_54;
  int iStack_50;
  undefined1 auStack_4c [16];
  undefined1 auStack_3c [32];
  undefined4 uStack_1c;
  undefined4 uStack_c;
  undefined4 uStack_8;
  int iStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  iStack_4 = -1;
  uStack_8 = 0x10810988;
  *unaff_FS_OFFSET = &uStack_c;
  func_0x1030459d();
  puStack_17c = (undefined4 *)0x30;
  puStack_180 = &uStack_154;
  uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x1088b210,auStack_128,&iStack_124
                         );
  if ((iStack_124 != 0) && (sStack_120 != 0)) {
    puStack_17c = (undefined4 *)auStack_4c;
    puStack_180 = &uStack_58;
    uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x10885018,&uStack_a4,&uStack_c0,
                            &iStack_54,&iStack_50,auStack_b4,&uStack_b0,auStack_ac,auStack_a8,
                            &uStack_8c,0x30,auStack_88);
    uStack_bc = (uint)(0 < iStack_54);
    puStack_17c = (undefined4 *)uStack_b0;
    uStack_b8 = (uint)(0 < iStack_50);
    puStack_180 = (undefined4 *)0x0;
    func_0x10303df5(iStack_124,uStack_a4,uStack_8c,uStack_58);
    __0L2ParamStack__QAE_H_Z(0x20);
    uStack_1c = 0;
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_13c);
    _PushBack_L2ParamStack__QAEHPAX_Z(unaff_EDI);
    _PushBack_L2ParamStack__QAEHPAX_Z(&uStack_138);
    _PushBack_L2ParamStack__QAEHPAX_Z(auStack_108);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_bc);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_d8);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_6c);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_68);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_cc);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_c8);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_c4);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_c0);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_a4);
    _PushBack_L2ParamStack__QAEHPAX_Z(auStack_a0);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_70);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_64);
    (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x328))(&puStack_180);
    uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1087ff8c,&stack0xfffffe8c);
    iVar3 = 0;
    if (0 < iStack_158) {
      do {
        puStack_17c = (undefined4 *)0xa;
        puStack_180 = (undefined4 *)0x1043907c;
        __0L2ParamStack__QAE_H_Z();
        iStack_4._0_1_ = 1;
        puStack_17c = (undefined4 *)uStack_154;
        puStack_180 = (undefined4 *)0x1043908f;
        _PushBack_L2ParamStack__QAEHPAX_Z();
        puStack_17c = &uStack_13c;
        puStack_180 = &uStack_140;
        uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1088500c,0x30,auStack_3c,
                                &uStack_130,&uStack_12c,&uStack_138,&uStack_134);
        puStack_17c = (undefined4 *)auStack_3c;
        puStack_180 = (undefined4 *)0x104390d9;
        _PushBack_L2ParamStack__QAEHPAX_Z();
        puStack_17c = (undefined4 *)uStack_130;
        puStack_180 = (undefined4 *)0x104390e4;
        _PushBack_L2ParamStack__QAEHPAX_Z();
        puStack_17c = (undefined4 *)uStack_12c;
        puStack_180 = (undefined4 *)0x104390ef;
        _PushBack_L2ParamStack__QAEHPAX_Z();
        puStack_17c = (undefined4 *)uStack_138;
        puStack_180 = (undefined4 *)0x104390fa;
        _PushBack_L2ParamStack__QAEHPAX_Z();
        puStack_17c = (undefined4 *)uStack_134;
        puStack_180 = (undefined4 *)0x10439105;
        _PushBack_L2ParamStack__QAEHPAX_Z();
        puStack_17c = (undefined4 *)uStack_140;
        puStack_180 = (undefined4 *)0x10439110;
        _PushBack_L2ParamStack__QAEHPAX_Z();
        puStack_17c = (undefined4 *)uStack_13c;
        puStack_180 = (undefined4 *)0x1043911b;
        _PushBack_L2ParamStack__QAEHPAX_Z();
        puStack_17c = (undefined4 *)auStack_150;
        puStack_180 = (undefined4 *)0x10439132;
        (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x348))();
        iStack_4 = (uint)iStack_4._1_3_ << 8;
        puStack_17c = (undefined4 *)0x10439144;
        __1L2ParamStack__QAE_XZ();
        iVar3 = iVar3 + 1;
      } while (iVar3 < iStack_158);
    }
    iStack_4 = -1;
    puStack_17c = (undefined4 *)0x10439166;
    __1L2ParamStack__QAE_XZ();
  }
  uVar2 = _Logf_FOutputDevice__QAAXPBGZZ();
  *unaff_FS_OFFSET = uStack_c;
  return uVar2 & 0xffffff00;
}

