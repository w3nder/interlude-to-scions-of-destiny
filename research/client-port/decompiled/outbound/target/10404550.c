
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
packet_10404550(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (DAT_10b1f52c != '\0') {
    WaitForSingleObject(_DAT_10b1f524,10000);
    CloseHandle(_DAT_10b1f524);
  }
  DAT_10b1f52c = 0;
  iVar1 = **(int **)(param_1 + 0x48);
  piVar2 = *(int **)(_DAT_10c51044 + 0x70);
  uVar3 = func_0x107a6d9c(DAT_10b1f510,DAT_10b1f511,DAT_10b1f512,DAT_10b1f513,DAT_10b1f514,
                          DAT_10b1f515,DAT_10b1f516,DAT_10b1f517,DAT_10b1f518,DAT_10b1f519,
                          DAT_10b1f51a,DAT_10b1f51b,DAT_10b1f51c,DAT_10b1f51d,DAT_10b1f51e,
                          DAT_10b1f51f,DAT_10b1f520,DAT_10b1f521,DAT_10b1f522,DAT_10b1f523);
  uVar3 = (**(code **)(*piVar2 + 0x6c))(uVar3);
  (**(code **)(iVar1 + 0x68))
            (*(undefined4 *)(param_1 + 0x48),0x1087fe34,3,param_2 * 4,param_3,param_4,param_5,
             param_6,param_7,0x40,uVar3);
  _Logf_FOutputDevice__QAAXPBGZZ(*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x1087fdfc)
  ;
  return 1;
}

