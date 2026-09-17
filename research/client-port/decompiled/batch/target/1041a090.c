
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_1041a090(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined1 *puVar4;
  undefined1 auStack_674 [1024];
  undefined1 auStack_274 [512];
  undefined1 *apuStack_74 [3];
  undefined1 auStack_68 [16];
  int iStack_58;
  undefined4 uStack_54;
  int iStack_50;
  undefined1 *puStack_4c;
  int iStack_48;
  undefined4 uStack_44;
  undefined1 *apuStack_40 [2];
  undefined4 uStack_38;
  int iStack_34;
  undefined1 auStack_30 [16];
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  undefined1 *puStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  uint uStack_8;
  
  uStack_c = 0x1080f4f2;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  puStack_14 = &stack0xfffff980;
  uStack_8 = 0;
  uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x1087ff8c,&uStack_20);
  uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1087ff8c,&iStack_48);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10886388,uStack_20);
  iStack_18 = 0;
  do {
    if (iStack_48 <= iStack_18) {
      func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1087ff44,&uStack_54,&uStack_38);
      __0L2ParamStack__QAE_H_Z(10);
      uStack_8._0_1_ = 2;
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_20);
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_54);
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_38);
      (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x660))(auStack_68);
      uStack_8 = (uint)uStack_8._1_3_ << 8;
      uVar3 = __1L2ParamStack__QAE_XZ();
      *unaff_FS_OFFSET = uStack_10;
      return uVar3 & 0xffffff00;
    }
    __0L2ParamStack__QAE_H_Z(10);
    uStack_8 = CONCAT31(uStack_8._1_3_,1);
    uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1087ff8c,&uStack_1c);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_1c);
    switch(uStack_1c) {
    case 0:
      uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x108847bc,0x400,auStack_674);
      puVar4 = auStack_674;
      break;
    case 1:
    case 2:
    case 3:
    case 5:
      uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1087ff8c,&puStack_4c);
      puVar4 = puStack_4c;
      break;
    case 4:
      uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1087ff44,&uStack_44,
                              apuStack_40);
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_44);
      puVar4 = apuStack_40[0];
      break;
    case 6:
      uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x10886380,apuStack_74);
      puVar4 = apuStack_74[0];
      break;
    case 7:
      uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1087ff0c,&iStack_34,&iStack_58
                              ,&iStack_50);
      uVar2 = func_0x1031509b((float)iStack_34,(float)iStack_58,(float)iStack_50);
      _appStrcpy__YAPAGPAGPBG_Z(auStack_274,uVar2);
      puVar4 = auStack_274;
      break;
    default:
      goto LAB_1041a262;
    }
    _PushBack_L2ParamStack__QAEHPAX_Z(puVar4);
LAB_1041a262:
    (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x350))(auStack_30);
    uStack_8 = uStack_8 & 0xffffff00;
    __1L2ParamStack__QAE_XZ();
    iStack_18 = iStack_18 + 1;
  } while( true );
}

