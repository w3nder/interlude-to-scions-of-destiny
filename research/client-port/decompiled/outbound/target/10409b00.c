
void __fastcall packet_10409b00(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = _Top_L2ParamStack__QAEPAXXZ();
  uVar2 = _Top_L2ParamStack__QAEPAXXZ();
  uVar3 = _Top_L2ParamStack__QAEPAXXZ();
  (**(code **)(**(int **)(param_1 + 0x48) + 0x68))
            (*(int **)(param_1 + 0x48),0x1087fa3c,0xc5,uVar1,uVar2,uVar3);
  _Logf_FOutputDevice__QAAXPBGZZ(*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10882fd0)
  ;
  return;
}

