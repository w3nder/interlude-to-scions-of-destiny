
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10419e40(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 auStack_1c [12];
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  uStack_8 = 0x1080f4a9;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x1087ff0c,&uStack_24,&uStack_20,&param_1)
  ;
  __0L2ParamStack__QAE_H_Z(0x30);
  iVar2 = 0;
  uStack_4 = 0;
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_24);
  _PushBack_L2ParamStack__QAEHPAX_Z(uStack_20);
  do {
    uVar1 = param_1 & 1;
    _PushBack_L2ParamStack__QAEHPAX_Z(uVar1);
    param_1 = param_1 >> 1;
    if (*(int *)_GLog__3PAVFOutputDevice__A_exref != 0) {
      _Logf2_FOutputDevice__QAAXPBGZZ
                (*(undefined4 *)_GLog__3PAVFOutputDevice__A_exref,0x10887338,iVar2,uVar1);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x20);
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x638))(auStack_1c);
  _Logf_FOutputDevice__QAAXPBGZZ(*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x108872e8)
  ;
  uStack_8 = 0xffffffff;
  uVar1 = __1L2ParamStack__QAE_XZ();
  *unaff_FS_OFFSET = uStack_10;
  return uVar1 & 0xffffff00;
}

