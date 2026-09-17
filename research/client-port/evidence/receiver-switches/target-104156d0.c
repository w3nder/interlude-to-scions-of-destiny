
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_104156d0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined1 *puVar4;
  undefined1 auStack_674 [1024];
  undefined1 auStack_274 [512];
  undefined1 *apuStack_74 [2];
  undefined1 auStack_6c [20];
  undefined1 *puStack_58;
  undefined4 auStack_54 [2];
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined1 auStack_34 [16];
  short asStack_24 [2];
  short asStack_20 [2];
  undefined1 *puStack_1c;
  int iStack_18;
  undefined1 *puStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  uint uStack_8;

  uStack_c = 0x1080f0c2;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  puStack_14 = &stack0xfffff980;
  uStack_8 = 0;
  uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x1087ff8c,&uStack_38);
  uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1087ff8c,&iStack_4c);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10886388,uStack_38);
  iStack_18 = 0;
  do {
    if (iStack_4c <= iStack_18) {
      __0L2ParamStack__QAE_H_Z(10);
      uStack_8._0_1_ = 2;
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_38);
      (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x354))(auStack_6c,0,0,0);
      uStack_8 = (uint)uStack_8._1_3_ << 8;
      uVar3 = __1L2ParamStack__QAE_XZ();
      *unaff_FS_OFFSET = uStack_10;
      return uVar3 & 0xffffff00;
    }
    __0L2ParamStack__QAE_H_Z(10);
    uStack_8 = CONCAT31(uStack_8._1_3_,1);
    uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1087ff8c,&uStack_3c);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_3c);
    switch(uStack_3c) {
    case 0:
      uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x108847bc,0x400,auStack_674);
      puVar4 = auStack_674;
      break;
    case 1:
    case 2:
    case 3:
    case 5:
      uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1087ff8c,&puStack_1c);
      puVar4 = puStack_1c;
      break;
    case 4:
      uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1087ff44,auStack_54,
                              &puStack_58);
      _PushBack_L2ParamStack__QAEHPAX_Z(auStack_54[0]);
      puVar4 = puStack_58;
      break;
    case 6:
      uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x10886380,apuStack_74);
      puVar4 = apuStack_74[0];
      break;
    case 7:
      uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1087ff0c,&iStack_48,&iStack_44
                              ,&iStack_40);
      uVar2 = func_0x1031509b((float)iStack_48,(float)iStack_44,(float)iStack_40);
      _appStrcpy__YAPAGPAGPBG_Z(auStack_274,uVar2);
      puVar4 = auStack_274;
      break;
    case 8:
      uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x10886384,&puStack_1c,
                              asStack_20,asStack_24);
      _PushBack_L2ParamStack__QAEHPAX_Z(puStack_1c);
      _PushBack_L2ParamStack__QAEHPAX_Z((int)asStack_20[0]);
      puVar4 = (undefined1 *)(int)asStack_24[0];
      break;
    default:
      goto LAB_104158e0;
    }
    _PushBack_L2ParamStack__QAEHPAX_Z(puVar4);
LAB_104158e0:
    (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x350))(auStack_34);
    uStack_8 = uStack_8 & 0xffffff00;
    __1L2ParamStack__QAE_XZ();
    iStack_18 = iStack_18 + 1;
  } while( true );
}
