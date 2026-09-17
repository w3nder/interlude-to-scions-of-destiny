
void __thiscall packet_10409980(int param_1,undefined4 param_2,int param_3,byte *param_4)

{
  byte bVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  
  if (param_3 == 1) {
    (**(code **)(**(int **)(param_1 + 0x48) + 0x68))
              (*(int **)(param_1 + 0x48),0x1087fb50,0xc0,param_2,1);
  }
  else if (param_3 == 2) {
    uVar4 = 0;
    pcVar2 = _GLog__3PAVFOutputDevice__A_exref;
    if (param_4 != (byte *)0x0) {
      iVar3 = 0x1f;
      do {
        bVar1 = param_4[iVar3];
        if (*(int *)pcVar2 != 0) {
          _Logf2_FOutputDevice__QAAXPBGZZ(*(int *)pcVar2,0x10882f60,iVar3,bVar1);
          pcVar2 = _GLog__3PAVFOutputDevice__A_exref;
        }
        iVar3 = iVar3 + -1;
        uVar4 = (uVar4 | bVar1 != 0) * 2;
      } while (0 < iVar3);
      uVar4 = uVar4 | *param_4;
    }
    if (*(int *)pcVar2 != 0) {
      _Logf2_FOutputDevice__QAAXPBGZZ(*(int *)pcVar2,0x10882f20,*param_4);
    }
    (**(code **)(**(int **)(param_1 + 0x48) + 0x68))
              (*(int **)(param_1 + 0x48),0x1087fa3c,0xc0,param_2,2,uVar4);
  }
  _Logf_FOutputDevice__QAAXPBGZZ(*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x10882ee4)
  ;
  return;
}

