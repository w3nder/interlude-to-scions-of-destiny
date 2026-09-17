
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10414290(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  undefined4 *unaff_FS_OFFSET;
  char cStack_4d;
  short asStack_4c [2];
  int iStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 auStack_1c [12];
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  uStack_8 = 0x1080ef99;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  __0L2ParamStack__QAE_H_Z(10);
  iVar3 = param_1;
  uStack_4 = 0;
  uVar1 = func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x1087ff44,&uStack_44,&uStack_40);
  switch(uStack_44) {
  case 1:
    func_0x103034e5(*(undefined4 *)(iVar3 + 0x48),uVar1,0x10885e68,&uStack_3c,&iStack_48,&uStack_38,
                    &uStack_34,&uStack_30,&param_1,asStack_4c);
    pcVar4 = _PushBack_L2ParamStack__QAEHPAX_Z_exref;
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_44);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_40);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_3c);
    _PushBack_L2ParamStack__QAEHPAX_Z(iStack_48);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_38);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_34);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_30);
    _PushBack_L2ParamStack__QAEHPAX_Z((int)(short)param_1);
    iVar3 = (int)asStack_4c[0];
    break;
  case 2:
    func_0x103034e5(*(undefined4 *)(iVar3 + 0x48),uVar1,0x10885e60,&uStack_2c,&uStack_28,&cStack_4d,
                    &iStack_48);
    pcVar4 = _PushBack_L2ParamStack__QAEHPAX_Z_exref;
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_44);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_40);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_2c);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_28);
    _PushBack_L2ParamStack__QAEHPAX_Z((int)cStack_4d);
    iVar3 = iStack_48;
    break;
  case 3:
    func_0x103034e5(*(undefined4 *)(iVar3 + 0x48),uVar1,0x1087ff44,&uStack_24,&iStack_48);
    pcVar4 = _PushBack_L2ParamStack__QAEHPAX_Z_exref;
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_44);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_40);
    uStack_3c = uStack_24;
    goto code_r0x104144cc;
  case 4:
    func_0x103034e5(*(undefined4 *)(iVar3 + 0x48),uVar1,0x1087ff44,&uStack_20,&iStack_48);
    pcVar4 = _PushBack_L2ParamStack__QAEHPAX_Z_exref;
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_44);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_40);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_20);
    iVar3 = iStack_48;
    break;
  case 5:
    func_0x103034e5(*(undefined4 *)(iVar3 + 0x48),uVar1,0x1087ff44,&uStack_3c,&iStack_48);
    pcVar4 = _PushBack_L2ParamStack__QAEHPAX_Z_exref;
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_44);
    _PushBack_L2ParamStack__QAEHPAX_Z(uStack_40);
code_r0x104144cc:
    (*pcVar4)(uStack_3c);
    iVar3 = iStack_48;
    break;
  default:
    goto LAB_104144de;
  }
  (*pcVar4)(iVar3);
LAB_104144de:
  (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2d4))(auStack_1c);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10885dd0,iStack_48,uStack_44)
  ;
  uStack_8 = 0xffffffff;
  uVar2 = __1L2ParamStack__QAE_XZ();
  *unaff_FS_OFFSET = uStack_10;
  return uVar2 & 0xffffff00;
}

