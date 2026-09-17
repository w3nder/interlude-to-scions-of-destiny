
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_1042ad50(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_3c [24];
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 auStack_1c [5];
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined1 *puStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  int iStack_8;
  
  uStack_c = 0x1080fd79;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  puStack_14 = &stack0xffffffb8;
  iStack_8 = 0;
  func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x1088a208,auStack_1c,&uStack_20,
                  &uStack_24,&uStack_15,&uStack_16,&uStack_17);
  piVar2 = (int *)0x0;
  if (_DAT_10b1f538 != 0) {
    iVar1 = func_0x1030d04e(auStack_1c);
    piVar2 = (int *)0x0;
    if (iVar1 != 0) {
      piVar2 = (int *)func_0x1030d04e(auStack_1c);
      if (*piVar2 == 1) {
        piVar2 = (int *)func_0x1030d04e(auStack_1c);
        if (piVar2[1] != 0) {
          piVar2 = (int *)func_0x1030d04e(auStack_1c);
          iVar1 = piVar2[1];
          if (iVar1 != 0) {
            __0L2ParamStack__QAE_H_Z(10);
            iStack_8._0_1_ = 1;
            _PushBack_L2ParamStack__QAEHPAX_Z(uStack_20);
            _PushBack_L2ParamStack__QAEHPAX_Z(uStack_24);
            _PushBack_L2ParamStack__QAEHPAX_Z(uStack_15);
            _PushBack_L2ParamStack__QAEHPAX_Z(uStack_16);
            _PushBack_L2ParamStack__QAEHPAX_Z(uStack_17);
            (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x728))
                      (*(undefined4 *)(iVar1 + 0x204),auStack_3c);
            _Logf_FOutputDevice__QAAXPBGZZ
                      (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x1088a1b0);
            iStack_8 = (uint)iStack_8._1_3_ << 8;
            piVar2 = (int *)__1L2ParamStack__QAE_XZ();
          }
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_10;
  return (uint)piVar2 & 0xffffff00;
}

