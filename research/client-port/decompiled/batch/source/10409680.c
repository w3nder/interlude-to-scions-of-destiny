
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10409680(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uStack_4;
  
  uVar1 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107bde54,&uStack_4,&param_1);
  uVar2 = malloc(0x20);
  func_0x10313ef3(uVar2,uVar1,0x20);
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x608))(uStack_4,param_1,uVar2);
  free(uVar2);
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c3c30);
  uVar3 = (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                    (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c3c30);
  return uVar3 & 0xffffff00;
}

