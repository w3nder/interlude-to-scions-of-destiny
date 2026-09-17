
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10414600(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_6c [24];
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  short asStack_20 [2];
  short asStack_1c [3];
  char cStack_15;
  undefined1 *puStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  uint uStack_8;
  
  uStack_c = 0x1080efb9;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  puStack_14 = &stack0xffffff88;
  uStack_8 = 0;
  (**(code **)(*(int *)_DAT_10b1f538[0x15] + 0x400))();
  uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x1087ff8c,&iStack_38);
  iStack_34 = 0;
  do {
    if (iStack_38 <= iStack_34) {
      (**(code **)(*_DAT_10b1f538 + 0x338))();
      uVar2 = _Logf_FOutputDevice__QAAXPBGZZ
                        (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10885ed0);
      *unaff_FS_OFFSET = uStack_10;
      return uVar2 & 0xffffff00;
    }
    __0L2ParamStack__QAE_H_Z(10);
    uStack_8 = CONCAT31(uStack_8._1_3_,1);
    uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1087ff44,&uStack_28,&uStack_2c);
    switch(uStack_28) {
    case 1:
      uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x10885e68,&iStack_30,&iStack_24
                              ,&uStack_3c,&uStack_40,&uStack_44,asStack_1c,asStack_20);
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_28);
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_2c);
      _PushBack_L2ParamStack__QAEHPAX_Z(iStack_30);
      _PushBack_L2ParamStack__QAEHPAX_Z(iStack_24);
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_3c);
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_40);
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_44);
      _PushBack_L2ParamStack__QAEHPAX_Z((int)asStack_1c[0]);
      iVar3 = (int)asStack_20[0];
      break;
    case 2:
      uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x10885e60,&uStack_48,&uStack_4c
                              ,&cStack_15,&iStack_24);
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_28);
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_2c);
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_48);
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_4c);
      iVar3 = (int)cStack_15;
      goto code_r0x10414840;
    case 3:
      uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1087ff44,&uStack_50,&iStack_24
                             );
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_28);
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_2c);
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_50);
      iVar3 = iStack_24;
      break;
    case 4:
      uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1087ff44,&uStack_54,&iStack_24
                             );
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_28);
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_2c);
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_54);
      iVar3 = iStack_24;
      break;
    case 5:
      uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),uVar1,0x1087ff44,&iStack_30,&iStack_24
                             );
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_28);
      _PushBack_L2ParamStack__QAEHPAX_Z(uStack_2c);
      iVar3 = iStack_30;
code_r0x10414840:
      _PushBack_L2ParamStack__QAEHPAX_Z(iVar3);
      iVar3 = iStack_24;
      break;
    default:
      goto LAB_1041484f;
    }
    _PushBack_L2ParamStack__QAEHPAX_Z(iVar3);
LAB_1041484f:
    (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2d4))(auStack_6c);
    uStack_8 = uStack_8 & 0xffffff00;
    __1L2ParamStack__QAE_XZ();
    iStack_34 = iStack_34 + 1;
  } while( true );
}

