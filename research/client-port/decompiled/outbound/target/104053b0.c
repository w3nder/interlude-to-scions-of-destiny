
undefined4 __fastcall packet_104053b0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = _Top_L2ParamStack__QAEPAXXZ();
  uVar2 = _Top_L2ParamStack__QAEPAXXZ();
  (**(code **)(**(int **)(param_1 + 0x48) + 0x68))
            (*(int **)(param_1 + 0x48),0x1087fb50,0x24,uVar1,uVar2);
  _Logf_FOutputDevice__QAAXPBGZZ(*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10880584)
  ;
  return 1;
}

