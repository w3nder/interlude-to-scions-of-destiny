
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_1042fea0(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 *puStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 *puStack_20;
  undefined1 auStack_1c [12];
  undefined1 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  uint uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  uStack_8 = 0x1081016f;
  *unaff_FS_OFFSET = &uStack_c;
  func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x1087ff0c,&param_1,&puStack_2c,&uStack_24
                 );
  if (_DAT_10b1f538 != 0) {
    iVar1 = func_0x1030d04e(&param_1);
    if (iVar1 != 0) {
      piVar2 = (int *)func_0x1030d04e(&param_1);
      if (*piVar2 == 4) {
        iVar1 = func_0x1030d04e(&param_1);
        if (*(int *)(iVar1 + 4) != 0) {
          iVar1 = func_0x1030d04e(&param_1);
          if (*(int *)(iVar1 + 4) != 0) goto LAB_1043009e;
        }
      }
    }
  }
  __0L2ParamStack__QAE_H_Z(10);
  uStack_4 = 0;
  _PushBack_L2ParamStack__QAEHPAX_Z(param_1);
  _PushBack_L2ParamStack__QAEHPAX_Z(puStack_2c);
  uStack_28 = 0;
  iVar1 = (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x294))(auStack_1c,&uStack_28);
  if (iVar1 != 0) {
    puStack_20 = (undefined4 *)
                 (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(0x1c,0x10853a28);
    if (puStack_20 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puStack_20[2] = 0;
      puStack_20[1] = 0;
      puStack_20[6] = 0;
      *puStack_20 = 0xffffffff;
      puStack_20[3] = 0;
      puStack_20[4] = 0;
      puVar4 = puStack_20;
    }
    uStack_4 = uStack_4 & 0xffffff00;
    *puVar4 = 1;
    puVar4[1] = puStack_2c;
    puVar4[2] = param_1;
    puVar4[6] = uStack_28;
    puVar4[5] = uStack_24;
    if (_DAT_10b1f538 != 0) {
      iVar1 = func_0x1030d04e(&param_1);
      if (iVar1 != 0) {
        func_0x10314fc4(iVar1);
        func_0x10304a34(&stack0x00000000);
      }
      puStack_2c = (undefined4 *)
                   (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(8,0x10853a28);
      if (puStack_2c == (undefined4 *)0x0) {
        puStack_2c = (undefined4 *)0x0;
      }
      else {
        *puStack_2c = 0;
        puStack_2c[1] = 0;
      }
      uStack_10 = 0;
      if (puStack_2c != (undefined4 *)0x0) {
        puStack_2c[1] = puVar4;
        *puStack_2c = 4;
      }
      func_0x1030a60f(&uStack_8,&puStack_2c);
    }
  }
  uStack_4 = 0xffffffff;
  __1L2ParamStack__QAE_XZ();
LAB_1043009e:
  uVar3 = _Logf_FOutputDevice__QAAXPBGZZ
                    (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x1088a8a8,param_1,
                     puStack_2c);
  *unaff_FS_OFFSET = uStack_c;
  return uVar3 & 0xffffff00;
}

