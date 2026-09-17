
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
packet_103f5510(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7)

{
  (**(code **)(**(int **)(param_1 + 0x48) + 100))
            (*(int **)(param_1 + 0x48),&UNK_107bdcc4,3,param_2 << 2,param_3,param_4,param_5,param_6,
             param_7);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107bdc8c);
  (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
            (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107bdc8c);
  return 1;
}

