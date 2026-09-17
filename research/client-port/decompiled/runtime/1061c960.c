
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
packet_1061c960(int param_1,undefined4 param_2,undefined4 param_3,float param_4)

{
  uint *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_9c [8];
  undefined4 uStack_94;
  undefined4 uStack_90;
  float fStack_8c;
  float fStack_78;
  undefined1 *puStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  float fStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  float fStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  float fStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_c;
  float fStack_8;
  
  uStack_64 = 0x10822fa0;
  uStack_68 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_68;
  puStack_6c = &stack0xffffff58;
  uStack_60 = 0;
  if (*(int *)(param_1 + 0x718) == 0) {
    uVar3 = 0;
  }
  else {
    uStack_54 = 0;
    uStack_50 = 0;
    uStack_4c = 0;
    iVar4 = __8FVector__QBEHABV0__Z(&uStack_54);
    if (iVar4 != 0) {
      param_2 = *(undefined4 *)(param_1 + 0x1bc);
      param_3 = *(undefined4 *)(param_1 + 0x1c0);
      param_4 = *(float *)(param_1 + 0x1c4);
    }
    *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) & 0xffffffdf;
    *(undefined4 *)(*(int *)(param_1 + 0x14d8) + 0x3bc) = *(undefined4 *)(param_1 + 0x718);
    if ((*(int *)(param_1 + 0x14d8) ==
         *(int *)(**(int **)(*(int *)(_DAT_10c51044 + 0x54) + 0x38) + 0x3c)) &&
       (iVar4 = _IsA_UObject__QBEHPAVUClass___Z
                          (&_PrivateStaticClass_ALineagePlayerController__0VUClass__A), iVar4 != 0))
    {
      (**(code **)(**(int **)(param_1 + 0x14d8) + 0x390))(*(undefined4 *)(param_1 + 0x718));
    }
    uStack_1c = 0;
    uStack_18 = 0;
    uStack_14 = 0x3f800000;
    (**(code **)(**(int **)(param_1 + 0x718) + 0x1c8))(1,0,0,0,0x3f800000);
    puVar1 = (uint *)(*(int *)(param_1 + 0x718) + 0x714);
    *puVar1 = *puVar1 & 0xfffffffe;
    func_0x10311f68(*(undefined4 *)(param_1 + 0x718));
    puVar1 = (uint *)(*(int *)(param_1 + 0x718) + 0x214);
    *puVar1 = *puVar1 & 0xfffffffe;
    puVar1 = (uint *)(*(int *)(param_1 + 0x718) + 0x2f8);
    *puVar1 = *puVar1 | 4;
    puVar1 = (uint *)(*(int *)(param_1 + 0x718) + 0x2f8);
    *puVar1 = *puVar1 | 8;
    *(undefined1 *)(*(int *)(param_1 + 0x718) + 0x71c) = 0;
    piVar2 = *(int **)(param_1 + 0xe4);
    func_0x103048d6(0x3f800000,0);
    uStack_3c = param_2;
    uStack_38 = param_3;
    fStack_34 = param_4;
    uStack_48 = param_2;
    uStack_44 = param_3;
    fStack_40 = param_4;
    iVar4 = **(int **)(param_1 + 0x718);
    puVar5 = (undefined4 *)func_0x10306ee2(&fStack_8);
    (**(code **)(iVar4 + 0x328))(0,*puVar5,*(undefined4 *)(param_1 + 0x6b4),0,1,0);
    iVar4 = *(int *)(param_1 + 0x718);
    *(undefined4 *)(iVar4 + 0x1c8) = *(undefined4 *)(param_1 + 0x1c8);
    *(undefined4 *)(iVar4 + 0x1cc) = *(undefined4 *)(param_1 + 0x1cc);
    *(undefined4 *)(iVar4 + 0x1d0) = *(undefined4 *)(param_1 + 0x1d0);
    *(undefined4 *)(*(int *)(param_1 + 0x718) + 0x1c8) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x718) + 0x1d0) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x718) + 0x32c) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x718) + 0x334) = 0;
    *(float *)(*(int *)(param_1 + 0x718) + 0x173c) = (float)*(int *)(param_1 + 0x1cc);
    for (iStack_c = 0; iStack_c < 0x1e; iStack_c = iStack_c + 1) {
      func_0x103048d6(0x3f800000,0);
      fStack_34 = fStack_34 + (float)_DAT_1089d2f0;
      fStack_40 = fStack_40 - (float)_DAT_1089d2f0;
      iVar4 = *(int *)(param_1 + 0x718);
      uStack_2c = *(undefined4 *)(iVar4 + 0x2f0);
      uStack_30 = *(undefined4 *)(iVar4 + 0x2f0);
      fStack_24 = *(float *)(iVar4 + 0x2f4);
      uStack_28 = uStack_30;
      uStack_20 = uStack_2c;
      fStack_8 = fStack_24;
      (**(code **)(*piVar2 + 0xe4))
                (auStack_9c,iVar4,&uStack_48,&uStack_3c,0x86,uStack_2c,uStack_30,fStack_24);
      if (fStack_8c != 0.0) {
        fStack_8 = fStack_78 * (float)_DAT_10891488;
        if (fStack_8 < (float)_DAT_10891478) {
          fStack_8c = ((float)_DAT_10891468 - fStack_8) + fStack_8c;
        }
        (**(code **)(*piVar2 + 0xa8))
                  (*(undefined4 *)(param_1 + 0x718),uStack_94,uStack_90,fStack_8c,0,0,0);
        break;
      }
    }
    if (*(int *)_GLog__3PAVFOutputDevice__A_exref != 0) {
      _Logf2_FOutputDevice__QAAXPBGZZ
                (*(undefined4 *)_GLog__3PAVFOutputDevice__A_exref,0x108d925c,param_1);
    }
    (**(code **)(*piVar2 + 0xac))(param_1,0);
    uVar3 = *(undefined4 *)(param_1 + 0x718);
  }
  *unaff_FS_OFFSET = uStack_68;
  return uVar3;
}

