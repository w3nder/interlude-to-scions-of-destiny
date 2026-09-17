
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall packet_103fb950(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  if ((param_3 == 1) || (param_3 == 2)) {
    (**(code **)(**(int **)(param_1 + 0x48) + 100))
              (*(int **)(param_1 + 0x48),&UNK_107bd9e0,0xc0,param_2,param_3);
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x48) + 100))
              (*(int **)(param_1 + 0x48),&UNK_107bdd78,0xc0,param_2,param_3,0x20,param_4);
  }
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c0c24);
  (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
            (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c0c24);
  return;
}

