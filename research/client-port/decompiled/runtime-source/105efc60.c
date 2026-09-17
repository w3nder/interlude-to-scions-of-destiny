
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __thiscall packet_105efc60(int *param_1,uint *param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  uint auStack_d4 [3];
  int *piStack_c8;
  undefined4 *puStack_c4;
  int *piStack_c0;
  int *piStack_bc;
  int *piStack_b8;
  float fStack_b4;
  int iStack_b0;
  int iStack_ac;
  int *piStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  int iStack_98;
  undefined *puStack_94;
  undefined4 uStack_84;
  undefined4 uStack_80;
  int *piStack_7c;
  int *piStack_78;
  float fStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  float fStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  int iStack_54;
  int iStack_50;
  float fStack_4c;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_30;
  int iStack_2c;
  float fStack_28;
  undefined1 *puStack_20;
  int *piStack_18;
  undefined1 *puStack_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  int iStack_8;
  
  puStack_c = &UNK_10764179;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  puStack_14 = &stack0xffffff70;
  piStack_18 = (int *)param_1[0x39];
  iStack_8 = 0;
  puStack_94 = (undefined *)0x105efc9c;
  __0FString__QAE_XZ();
  iStack_8._0_1_ = 1;
  if (param_2 == (uint *)0x1) {
    puStack_94 = &UNK_108064a4;
  }
  else {
    if (param_2 != (uint *)0x2) goto LAB_105f014b;
    puStack_94 = &UNK_10806470;
  }
  iStack_98 = 0x105efcc6;
  __4FString__QAEAAV0_PBG_Z();
  puStack_94 = (undefined *)0x105efccf;
  uStack_a0 = __DFString__QBEPBGXZ();
  puStack_94 = (undefined *)0x0;
  iStack_98 = 0;
  uStack_9c = 0;
  uStack_a4 = 0;
  piStack_a8 = (int *)&_PrivateStaticClass_APawn__0VUClass__A;
  iStack_ac = 0x105efce3;
  puVar2 = (undefined4 *)_StaticLoadClass_UObject__SAPAVUClass__PAV2_PAV1_PBG2KPAVUPackageMap___Z();
  if (puVar2 != (undefined4 *)0x0) {
    iStack_98 = param_1[0x4fc];
    puStack_94 = (undefined *)0x0;
    uStack_9c = 0;
    uStack_a0 = 1;
    uStack_a4 = 0;
    iStack_b0 = param_1[0x72];
    iStack_ac = param_1[0x73];
    piStack_a8 = (int *)param_1[0x74];
    piStack_c0 = (int *)&piStack_bc;
    piVar1 = param_1 + 0x6f;
    piStack_bc = (int *)*piVar1;
    piStack_b8 = (int *)param_1[0x70];
    fStack_b4 = (float)param_1[0x71];
    puStack_20 = (undefined1 *)&piStack_c0;
    puStack_c4 = (undefined4 *)0x0;
    piStack_c8 = (int *)0x105efd45;
    __0FName__QAE_W4EName___Z();
    piStack_c8 = (int *)0x105efd51;
    puStack_c4 = puVar2;
    piVar3 = (int *)(**(code **)(*piStack_18 + 0xbc))();
    if (piVar3 != (int *)0x0) {
      iStack_30 = 0;
      uStack_9c = 0;
      iStack_2c = 0;
      iStack_98 = 0;
      fStack_28 = 1.0;
      puStack_94 = (undefined *)0x3f800000;
      *(undefined1 *)((int)piVar3 + 0xc2) = 4;
      uStack_a0 = 0;
      if (param_2 == (uint *)0x2) {
        uStack_a4 = 4;
      }
      else {
        uStack_a4 = 1;
      }
      piStack_a8 = (int *)0x105efda7;
      (**(code **)(*piVar3 + 0x1c0))();
      piVar3[0x177] = piVar3[0x177] | 4;
      piVar3[0x179] = param_3 + -1000000;
      piVar3[0x19] = piVar3[0x19] ^ (param_1[0x19] ^ piVar3[0x19]) & 0x20U;
      if ((param_2 == (uint *)0x1) || (param_4 != 0)) {
        iStack_30 = *piVar1;
        iStack_2c = param_1[0x70];
        fStack_28 = (float)param_1[0x71] + _DAT_107c6b8c;
        iStack_50 = param_1[0x70];
        iStack_54 = *piVar1;
        fStack_4c = (float)param_1[0x71];
        for (param_3 = 0; piVar1 = piStack_18, param_3 < 0x1e; param_3 = param_3 + 1) {
          iStack_b0 = piVar3[0xbc];
          fStack_28 = fStack_28 + _DAT_107d6eb0;
          fStack_4c = fStack_4c - _DAT_107d6eb0;
          fStack_b4 = 1.87774e-43;
          uStack_84 = 0;
          uStack_80 = 0;
          uStack_64 = 0;
          piStack_a8 = (int *)piVar3[0xbd];
          uStack_58 = 0;
          iStack_ac = piVar3[0xbc];
          piStack_b8 = &iStack_30;
          piStack_bc = &iStack_54;
          puStack_c4 = &uStack_84;
          piStack_7c = (int *)0x0;
          piStack_78 = (int *)0x0;
          fStack_74 = 0.0;
          uStack_70 = 0;
          uStack_6c = 0;
          uStack_68 = 0;
          fStack_60 = 1.0;
          uStack_5c = 0xffffffff;
          piStack_c8 = (int *)0x105f00d3;
          piStack_c0 = piVar3;
          iStack_48 = iStack_b0;
          iStack_44 = iStack_ac;
          iStack_40 = (int)piStack_a8;
          (**(code **)(*piStack_18 + 0xe0))();
          if (fStack_74 != _DAT_10791554) {
            if (fStack_60 * (float)_DAT_107cceb8 < _DAT_10805548) {
              fStack_74 = ((_DAT_10805544 + _DAT_10805548) * _DAT_10798638 -
                          fStack_60 * (float)_DAT_107cceb8) + fStack_74;
            }
            piStack_a8 = (int *)0x0;
            iStack_ac = 0;
            iStack_b0 = 0;
            piStack_bc = piStack_7c;
            piStack_b8 = piStack_78;
            fStack_b4 = fStack_74;
            puStack_c4 = (undefined4 *)0x105f013c;
            piStack_c0 = piVar3;
            (**(code **)(*piVar1 + 0xa4))();
            break;
          }
        }
      }
      *(int **)(param_1[0x4fc] + 0x3a8) = piVar3;
      piVar3[0x198] = (int)param_1;
      piVar3[0x4fc] = param_1[0x4fc];
      if (param_1[0x4fc] == *(int *)(**(int **)(*(int *)(_DAT_10b36bb4 + 0x58) + 0x38) + 0x3c)) {
        piStack_a8 = (int *)&_PrivateStaticClass_ALineagePlayerController__0VUClass__A;
        iStack_ac = 0x105efe2f;
        iVar4 = _IsA_UObject__QBEHPAVUClass___Z();
        if (iVar4 != 0) {
          iStack_ac = 0x105efe42;
          piStack_a8 = piVar3;
          (**(code **)(*(int *)param_1[0x4fc] + 0x368))();
        }
      }
      piVar3[0x500] = piVar3[0x500] | 0x10000000;
      *(undefined1 *)(piVar3 + 0x199) = param_2._0_1_;
      piVar3[0x19] = piVar3[0x19] ^ (param_1[0x19] ^ piVar3[0x19]) & 2U;
      piStack_a8 = (int *)0x1;
      param_1[0x85] = param_1[0x85] | 1;
      param_1[0xbe] = param_1[0xbe] & 0xfffffff3;
      iStack_54 = 0;
      fStack_b4 = 0.0;
      iStack_50 = 0;
      iStack_b0 = 0;
      fStack_4c = 1.0;
      iStack_ac = 0x3f800000;
      piStack_bc = (int *)0x105efec5;
      piStack_b8 = piVar3;
      (**(code **)(*param_1 + 0x164))();
      iStack_54 = 0;
      puStack_c4 = (undefined4 *)0x0;
      iStack_50 = 0;
      piStack_c0 = (int *)0x0;
      fStack_4c = 1.0;
      piStack_bc = (int *)0x3f800000;
      auStack_d4[2] = 0;
      auStack_d4[1] = 0x105efefd;
      piStack_c8 = piVar3;
      (**(code **)(*param_1 + 0x1c0))();
      auStack_d4[0] = param_1[0x197] | 1;
      auStack_d4[1] = 0;
      param_1[0x197] = auStack_d4[0];
      *(undefined1 *)(param_1 + 0x199) = param_2._0_1_;
      param_2 = auStack_d4;
      __0FName__QAE_PBGW4EFindName___Z(&UNK_107dd6fc,1);
      func_0x1030867f(param_1);
      iVar4 = param_1[0x41];
      if ((iVar4 != 0) &&
         (iVar5 = _IsA_UObject__QBEHPAVUClass___Z(&_PrivateStaticClass_USkeletalMesh__0VUClass__A),
         iVar5 != 0)) {
        fStack_4c = *(float *)(iVar4 + 0x98);
        iStack_54 = 0;
        param_1[0x7f] = 0;
        iStack_50 = 0;
        param_1[0x80] = 0;
        param_1[0x81] = (int)fStack_4c;
      }
      puVar2 = (undefined4 *)func_0x10309520(&param_2);
      (**(code **)(*piVar3 + 800))(0,*puVar2,param_1[0x17f],0,1,0);
      puVar2 = (undefined4 *)func_0x10309520(&param_2);
      (**(code **)(*param_1 + 800))(0,*puVar2,param_1[0x17f],0,1,0);
      iStack_8 = (uint)iStack_8._1_3_ << 8;
      __1FString__QAE_XZ();
      *unaff_FS_OFFSET = uStack_10;
      return piVar3;
    }
  }
LAB_105f014b:
  iStack_8 = (uint)iStack_8._1_3_ << 8;
  puStack_94 = (undefined *)0x105f0158;
  __1FString__QAE_XZ();
  *unaff_FS_OFFSET = uStack_10;
  return (int *)0x0;
}

