
void __fastcall packet_10406040(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar1 = _Top_L2ParamStack__QAEPAXXZ();
  uVar2 = _Top_L2ParamStack__QAEPAXXZ();
  uVar3 = _Top_L2ParamStack__QAEPAXXZ();
  uVar4 = _Top_L2ParamStack__QAEPAXXZ();
  (**(code **)(**(int **)(param_1 + 0x48) + 0x68))
            (*(int **)(param_1 + 0x48),0x1087fa94,0x71,uVar1,uVar2,uVar3,uVar4);
  _Logf_FOutputDevice__QAAXPBGZZ(*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10880ee0)
  ;
  return;
}

