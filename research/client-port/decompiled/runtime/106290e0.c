
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __thiscall
packet_106290e0(int *param_1,undefined1 *param_2,float param_3,int *param_4,int param_5,int param_6,
               float param_7)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_120 [4];
  undefined4 uStack_11c;
  undefined1 *puStack_118;
  int *piStack_114;
  int *piStack_110;
  int *piStack_10c;
  int iStack_108;
  int *piStack_104;
  int *piStack_100;
  int *piStack_fc;
  int iStack_f8;
  int *piStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  int iStack_e4;
  undefined4 *puStack_e0;
  undefined1 auStack_d0 [8];
  int iStack_c8;
  float fStack_c4;
  int *piStack_c0;
  float fStack_ac;
  undefined1 *puStack_a0;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined1 *puStack_78;
  undefined1 *puStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  int iStack_68;
  float fStack_64;
  int *piStack_60;
  int *piStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  int iStack_3c;
  int iStack_38;
  float fStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  int iStack_20;
  float fStack_1c;
  int iStack_c;
  int *piStack_8;
  
  uStack_6c = 0x10823209;
  uStack_70 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_70;
  puStack_74 = &stack0xffffff24;
  iStack_68 = 0;
  piVar1 = (int *)param_1[0x39];
  uStack_98 = 0;
  uStack_94 = 0;
  uStack_90 = 0;
  puStack_e0 = &uStack_98;
  iStack_e4 = 0x1062912e;
  iVar2 = __8FVector__QBEHABV0__Z();
  if (iVar2 != 0) {
    param_5 = param_1[0x6f];
    param_6 = param_1[0x70];
    param_7 = (float)param_1[0x71];
  }
  puStack_e0 = (undefined4 *)0x10629156;
  __0FString__QAE_XZ();
  iStack_68._0_1_ = 1;
  if (param_2 == (undefined1 *)0x1) {
    puStack_e0 = (undefined4 *)0x108d9b64;
LAB_10629177:
    iStack_e4 = 0x10629180;
    __4FString__QAEAAV0_PBG_Z();
    puStack_e0 = (undefined4 *)0x0;
    iStack_e4 = 0;
    uStack_e8 = 0;
    uStack_ec = 0x1062918f;
    uStack_ec = __DFString__QBEPBGXZ();
    uStack_f0 = 0;
    piStack_f4 = (int *)&_PrivateStaticClass_APawn__0VUClass__A;
    iStack_f8 = 0x1062919d;
    piStack_8 = (int *)_StaticLoadClass_UObject__SAPAVUClass__PAV2_PAV1_PBG2KPAVUPackageMap___Z();
    if (piStack_8 != (int *)0x0) {
      iVar2 = *piVar1;
      puStack_e0 = (undefined4 *)0x0;
      iStack_e4 = param_1[0x536];
      uStack_e8 = 0;
      uStack_ec = 1;
      uStack_f0 = 0;
      piStack_fc = (int *)param_1[0x72];
      iStack_f8 = param_1[0x73];
      piStack_f4 = (int *)param_1[0x74];
      iStack_108 = param_1[0x6f];
      piStack_104 = (int *)param_1[0x70];
      piStack_10c = (int *)param_1[0x71];
      puStack_a0 = (undefined1 *)&piStack_10c;
      piStack_110 = (int *)0x0;
      piStack_114 = (int *)0x1062920e;
      piStack_100 = piStack_10c;
      __0FName__QAE_W4EName___Z();
      piStack_110 = piStack_8;
      piStack_114 = (int *)0x10629218;
      piVar3 = (int *)(**(code **)(iVar2 + 0xc0))();
      if (piVar3 != (int *)0x0) {
        *(undefined1 *)((int)piVar3 + 0xc2) = 4;
        uStack_ec = 0;
        if (param_2 == (undefined1 *)0x2) {
          uStack_30 = 0;
          uStack_2c = 0;
          uStack_28 = 0x3f800000;
          uStack_f0 = 4;
        }
        else {
          uStack_58 = 0;
          uStack_54 = 0;
          uStack_50 = 0x3f800000;
          uStack_f0 = 1;
        }
        iStack_e4 = 0;
        uStack_e8 = 0;
        puStack_e0 = (undefined4 *)0x3f800000;
        piStack_f4 = (int *)0x1062927f;
        (**(code **)(*piVar3 + 0x1c8))();
        piVar3[0x1a5] = piVar3[0x1a5] | 4;
        piVar3[0x1a7] = (int)param_3 + -1000000;
        piVar3[0x19] = piVar3[0x19] ^ (param_1[0x19] ^ piVar3[0x19]) & 0x20U;
        if ((param_2 == (undefined1 *)0x1) || (param_4 != (int *)0x0)) {
          iStack_24 = param_5;
          iStack_20 = param_6;
          iStack_3c = param_5;
          iStack_38 = param_6;
          fStack_34 = param_7;
          fStack_1c = param_7 + (float)_DAT_1088afc8;
          for (iStack_c = 0; iStack_c < 0x1e; iStack_c = iStack_c + 1) {
            piStack_f4 = (int *)0x0;
            iStack_f8 = 0x3f800000;
            piStack_fc = (int *)0x106292fa;
            func_0x103048d6();
            fStack_1c = fStack_1c + (float)_DAT_1089d2f0;
            fStack_34 = fStack_34 - (float)_DAT_1089d2f0;
            param_3 = (float)piVar3[0xbc];
            param_4 = (int *)piVar3[0xbc];
            piStack_fc = (int *)piVar3[0xbd];
            iStack_108 = 0x86;
            piStack_10c = &iStack_24;
            piStack_110 = &iStack_3c;
            puStack_118 = auStack_d0;
            uStack_11c = 0x10629371;
            piStack_114 = piVar3;
            piStack_104 = (int *)param_3;
            piStack_100 = param_4;
            fStack_64 = param_3;
            piStack_60 = param_4;
            piStack_5c = piStack_fc;
            piStack_8 = piStack_fc;
            (**(code **)(*piVar1 + 0xe4))();
            if ((float)piStack_c0 != 0.0) {
              param_3 = fStack_ac * (float)_DAT_10891488;
              if (param_3 < (float)_DAT_10891478) {
                piStack_c0 = (int *)(((float)_DAT_10891468 - param_3) + (float)piStack_c0);
              }
              piStack_f4 = (int *)0x0;
              iStack_f8 = 0;
              piStack_fc = (int *)0x0;
              iStack_108 = iStack_c8;
              piStack_104 = (int *)fStack_c4;
              piStack_100 = piStack_c0;
              piStack_110 = (int *)0x106293db;
              piStack_10c = piVar3;
              (**(code **)(*piVar1 + 0xa8))();
              break;
            }
          }
        }
        *(int **)(param_1[0x536] + 0x3bc) = piVar3;
        piVar3[0x1c6] = (int)param_1;
        piVar3[0x536] = param_1[0x536];
        if (param_1[0x536] == *(int *)(**(int **)(*(int *)(_DAT_10c51044 + 0x54) + 0x38) + 0x3c)) {
          piStack_f4 = (int *)&_PrivateStaticClass_ALineagePlayerController__0VUClass__A;
          iStack_f8 = 0x10629422;
          iVar2 = _IsA_UObject__QBEHPAVUClass___Z();
          if (iVar2 != 0) {
            iStack_f8 = 0x10629437;
            piStack_f4 = piVar3;
            (**(code **)(*(int *)param_1[0x536] + 0x390))();
          }
        }
        *(undefined1 *)(piVar3 + 0x1c7) = param_2._0_1_;
        piVar3[0x53a] = piVar3[0x53a] | 0x10000000;
        piVar3[0x19] = piVar3[0x19] ^ (param_1[0x19] ^ piVar3[0x19]) & 2U;
        piVar3[0x5f4] = param_1[0x5f4];
        param_1[0x5f4] = 0;
        param_1[0x85] = param_1[0x85] | 1;
        param_1[0xbe] = param_1[0xbe] & 0xfffffffb;
        param_1[0xbe] = param_1[0xbe] & 0xfffffff7;
        uStack_4c = 0;
        uStack_48 = 0;
        uStack_44 = 0x3f800000;
        piStack_f4 = (int *)0x1;
        piStack_100 = (int *)0x0;
        piStack_fc = (int *)0x0;
        iStack_f8 = 0x3f800000;
        iStack_108 = 0x106294bb;
        piStack_104 = piVar3;
        (**(code **)(*param_1 + 0x16c))();
        uStack_8c = 0;
        uStack_88 = 0;
        uStack_84 = 0x3f800000;
        piStack_110 = (int *)0x0;
        piStack_10c = (int *)0x0;
        iStack_108 = 0x3f800000;
        puStack_118 = (undefined1 *)0x0;
        uStack_11c = 0x106294ed;
        piStack_114 = piVar3;
        (**(code **)(*param_1 + 0x1c8))();
        param_1[0x1c5] = param_1[0x1c5] | 1;
        *(undefined1 *)(param_1 + 0x1c7) = param_2._0_1_;
        uStack_11c = 0;
        param_2 = auStack_120;
        __0FName__QAE_PBGW4EFindName___Z(0x108a6640,1);
        func_0x10305f79(param_1);
        iVar2 = func_0x10312bca(param_1[0x41]);
        if (iVar2 != 0) {
          param_2 = *(undefined1 **)(iVar2 + 0x98);
          uStack_80 = 0;
          uStack_7c = 0;
          param_1[0x7f] = 0;
          param_1[0x80] = 0;
          param_1[0x81] = (int)param_2;
          puStack_78 = param_2;
        }
        iVar2 = *piVar3;
        puVar4 = (undefined4 *)func_0x10306ee2(&param_2);
        (**(code **)(iVar2 + 0x328))(0,*puVar4,param_1[0x1ad],0,1,0);
        iVar2 = *param_1;
        puVar4 = (undefined4 *)func_0x10306ee2(&param_2);
        (**(code **)(iVar2 + 0x328))(0,*puVar4,param_1[0x1ad],0,1,0);
        iStack_68 = (uint)iStack_68._1_3_ << 8;
        __1FString__QAE_XZ();
        goto code_r0x106295d7;
      }
    }
  }
  else if (param_2 == (undefined1 *)0x2) {
    puStack_e0 = (undefined4 *)0x108d9b30;
    goto LAB_10629177;
  }
  iStack_68 = (uint)iStack_68._1_3_ << 8;
  puStack_e0 = (undefined4 *)0x10629605;
  __1FString__QAE_XZ();
  piVar3 = (int *)0x0;
code_r0x106295d7:
  *unaff_FS_OFFSET = uStack_70;
  return piVar3;
}

