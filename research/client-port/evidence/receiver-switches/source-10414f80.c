
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10414f80(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iStack_c;
  undefined1 auStack_8 [4];
  undefined4 uStack_4;

  iVar1 = param_1;
  uVar2 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107bde54,auStack_8,&iStack_c)
  ;
  if ((((_DAT_109d5e68 != 0) && (iVar3 = func_0x1030f3bc(auStack_8), iVar3 != 0)) &&
      (piVar4 = (int *)func_0x1030f3bc(auStack_8), *piVar4 == 1)) &&
     (iVar3 = func_0x1030f3bc(auStack_8), *(int *)(iVar3 + 4) != 0)) {
    iVar3 = func_0x1030f3bc(auStack_8);
    iVar3 = *(int *)(iVar3 + 4);
    if (iVar3 != 0) {
      while (0 < iStack_c) {
        iStack_c = iStack_c + -1;
        uVar2 = func_0x10305079(*(undefined4 *)(iVar1 + 0x48),uVar2,&UNK_107bde54,&uStack_4,&param_1
                               );
        switch(uStack_4) {
        case 0:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0xb8))(iVar3,param_1);
          break;
        case 1:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0xbc))(iVar3,param_1);
          break;
        case 2:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0xc0))(iVar3,param_1);
          break;
        case 3:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0xc4))(iVar3,param_1);
          break;
        case 4:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 200))(iVar3,param_1);
          break;
        case 5:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0xcc))(iVar3,param_1);
          break;
        case 6:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0xd0))(iVar3,param_1);
          break;
        case 7:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0xd4))(iVar3,param_1);
          break;
        case 8:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0xd8))(iVar3,param_1);
          break;
        case 9:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0xdc))(iVar3,param_1);
          break;
        case 10:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0xe0))(iVar3,param_1);
          break;
        case 0xb:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0xec))(iVar3,param_1);
          break;
        case 0xc:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0xf0))(iVar3,param_1);
          break;
        case 0xd:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0xf4))(iVar3,param_1);
          break;
        case 0xe:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0xf8))(iVar3,param_1);
          break;
        case 0xf:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0xfc))(iVar3,param_1);
          break;
        case 0x10:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x100))(iVar3,param_1);
          break;
        case 0x11:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x104))(iVar3,param_1);
          break;
        case 0x12:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x108))(iVar3,param_1);
          break;
        case 0x13:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x10c))(iVar3,param_1);
          break;
        case 0x14:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x110))(iVar3,param_1);
          break;
        case 0x15:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x114))(iVar3,param_1);
          break;
        case 0x16:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x118))(iVar3,param_1);
          break;
        case 0x17:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x11c))(iVar3,param_1);
          break;
        case 0x18:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x120))(iVar3,param_1);
          break;
        case 0x19:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x124))(iVar3,param_1);
          break;
        case 0x1a:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x128))(iVar3,param_1);
          break;
        case 0x1b:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 300))(iVar3,param_1);
          break;
        case 0x21:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0xe4))(iVar3,param_1);
          break;
        case 0x22:
          (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0xe8))(iVar3,param_1);
        }
      }
      iStack_c = iStack_c + -1;
    }
  }
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c5890,iStack_c);
  uVar5 = (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                    (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c5890,iStack_c);
  return uVar5 & 0xffffff00;
}
