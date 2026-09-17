
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall packet_103f6610(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = func_0x10303a12();
  (**(code **)(**(int **)(param_1 + 0x48) + 100))
            (*(int **)(param_1 + 0x48),&UNK_107bd788,0x24,uVar1);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107be4e4);
  (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
            (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107be4e4);
  return 1;
}

