
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall packet_105e4500(int param_1)

{
  uint *puVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  float fStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  float fStack_54;
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
  undefined1 auStack_20 [8];
  undefined4 *puStack_18;
  undefined1 *puStack_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  puStack_c = &UNK_10763f40;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  puStack_14 = &stack0xffffff7c;
  uStack_8 = 0;
  if (*(int *)(param_1 + 0x660) == 0) {
    *unaff_FS_OFFSET = uStack_10;
    return 0;
  }
  *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) & 0xffffffdf;
  *(int *)(*(int *)(param_1 + 0x13f0) + 0x3a8) = *(int *)(param_1 + 0x660);
  puVar4 = &stack0xffffff7c;
  if (*(int *)(param_1 + 0x13f0) ==
      *(int *)(**(int **)(*(int *)(_DAT_10b36bb4 + 0x58) + 0x38) + 0x3c)) {
    iVar5 = _IsA_UObject__QBEHPAVUClass___Z
                      (&_PrivateStaticClass_ALineagePlayerController__0VUClass__A);
    puVar4 = puStack_14;
    if (iVar5 != 0) {
      (**(code **)(**(int **)(param_1 + 0x13f0) + 0x368))(*(undefined4 *)(param_1 + 0x660));
      puVar4 = puStack_14;
    }
  }
  puStack_14 = puVar4;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0x3f800000;
  (**(code **)(**(int **)(param_1 + 0x660) + 0x1c0))(1,0,0,0,0x3f800000);
  *(uint *)(*(int *)(param_1 + 0x660) + 0x65c) =
       *(uint *)(*(int *)(param_1 + 0x660) + 0x65c) & 0xfffffffe;
  func_0x10313ee4(*(undefined4 *)(param_1 + 0x660));
  puVar1 = (uint *)(*(int *)(param_1 + 0x660) + 0x214);
  *puVar1 = *puVar1 & 0xfffffffe;
  puVar1 = (uint *)(*(int *)(param_1 + 0x660) + 0x2f8);
  *puVar1 = *puVar1 | 4;
  puVar1 = (uint *)(*(int *)(param_1 + 0x660) + 0x2f8);
  *puVar1 = *puVar1 | 8;
  *(undefined1 *)(*(int *)(param_1 + 0x660) + 0x664) = 0;
  piVar2 = *(int **)(param_1 + 0xe4);
  uStack_3c = *(undefined4 *)(param_1 + 0x1bc);
  uStack_38 = *(undefined4 *)(param_1 + 0x1c0);
  fStack_34 = *(float *)(param_1 + 0x1c4);
  uStack_48 = *(undefined4 *)(param_1 + 0x1bc);
  uStack_44 = *(undefined4 *)(param_1 + 0x1c0);
  fStack_40 = *(float *)(param_1 + 0x1c4);
  puStack_18 = (undefined4 *)func_0x10309520(auStack_20);
  (**(code **)(**(int **)(param_1 + 0x660) + 800))
            (0,*puStack_18,*(undefined4 *)(param_1 + 0x5fc),0,1,0);
  iVar5 = *(int *)(param_1 + 0x660);
  *(undefined4 *)(iVar5 + 0x1c8) = *(undefined4 *)(param_1 + 0x1c8);
  *(undefined4 *)(iVar5 + 0x1cc) = *(undefined4 *)(param_1 + 0x1cc);
  *(undefined4 *)(iVar5 + 0x1d0) = *(undefined4 *)(param_1 + 0x1d0);
  *(float *)(*(int *)(param_1 + 0x660) + 0x1634) = (float)*(int *)(param_1 + 0x1cc);
  puStack_18 = (undefined4 *)0x0;
  do {
    if (0x1d < (int)puStack_18) {
LAB_105e47eb:
      if (*(int *)_GLog__3PAVFOutputDevice__A_exref != 0) {
        _Logf2_FOutputDevice__QAAXPBGZZ
                  (*(int *)_GLog__3PAVFOutputDevice__A_exref,&UNK_10805c34,param_1);
      }
      (**(code **)(*piVar2 + 0xa8))(param_1,0);
      uVar3 = *(undefined4 *)(param_1 + 0x660);
      *unaff_FS_OFFSET = uStack_10;
      return uVar3;
    }
    iVar5 = *(int *)(param_1 + 0x660);
    fStack_34 = fStack_34 + _DAT_107d6eb0;
    uStack_78 = 0;
    uStack_74 = 0;
    uStack_58 = 0;
    uStack_4c = 0;
    fStack_40 = fStack_40 - _DAT_107d6eb0;
    uStack_70 = 0;
    uStack_6c = 0;
    fStack_68 = 0.0;
    uStack_64 = 0;
    uStack_60 = 0;
    uStack_5c = 0;
    fStack_54 = 1.0;
    uStack_50 = 0xffffffff;
    uStack_28 = *(undefined4 *)(iVar5 + 0x2f4);
    uStack_30 = *(undefined4 *)(iVar5 + 0x2f0);
    uStack_2c = *(undefined4 *)(iVar5 + 0x2f0);
    (**(code **)(*piVar2 + 0xe0))
              (&uStack_78,iVar5,&uStack_48,&uStack_3c,0x86,uStack_30,uStack_2c,uStack_28);
    if (fStack_68 != _DAT_10791554) {
      if (fStack_54 * (float)_DAT_107cceb8 < _DAT_10805548) {
        fStack_68 = ((_DAT_10805544 + _DAT_10805548) * _DAT_10798638 -
                    fStack_54 * (float)_DAT_107cceb8) + fStack_68;
      }
      (**(code **)(*piVar2 + 0xa4))
                (*(undefined4 *)(param_1 + 0x660),uStack_70,uStack_6c,fStack_68,0,0,0);
      goto LAB_105e47eb;
    }
    puStack_18 = (undefined4 *)((int)puStack_18 + 1);
  } while( true );
}

