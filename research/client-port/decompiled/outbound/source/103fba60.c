
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall packet_103fba60(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = func_0x10303a12();
  uVar2 = func_0x10303a12();
  (**(code **)(**(int **)(param_1 + 0x48) + 100))
            (*(int **)(param_1 + 0x48),&UNK_107bd9e0,0xc5,uVar1,uVar2);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c0c90);
  (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
            (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c0c90);
  return;
}

