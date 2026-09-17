
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall packet_103fb600(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = func_0x10303a12();
  uVar2 = func_0x10303a12();
  uVar3 = func_0x10303a12();
  (**(code **)(**(int **)(param_1 + 0x48) + 100))
            (*(int **)(param_1 + 0x48),&UNK_107bd8cc,0xa7,uVar1,uVar2,uVar3);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c0ac8);
  (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
            (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c0ac8);
  return;
}

