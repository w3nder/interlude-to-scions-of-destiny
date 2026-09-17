
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_103f17d0(void)

{
  uint uVar1;
  
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x1a0))();
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107bc9a4);
  uVar1 = (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                    (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107bc9a4);
  return uVar1 & 0xffffff00;
}

