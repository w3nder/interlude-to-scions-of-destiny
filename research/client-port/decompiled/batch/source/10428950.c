
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10428950(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined1 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uStack_14;
  undefined1 auStack_10 [4];
  undefined1 auStack_c [4];
  undefined1 auStack_8 [4];
  undefined1 auStack_4 [4];
  
  func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c357c,&param_1,&uStack_14,
                  auStack_8,auStack_c,auStack_10,auStack_4);
  piVar2 = (int *)0x0;
  if (_DAT_109d5e68 != (int *)0x0) {
    puVar5 = &param_1;
    iVar1 = func_0x1030f3bc();
    piVar2 = (int *)0x0;
    if (iVar1 != 0) {
      piVar4 = (int *)register0x00000010;
      piVar2 = (int *)func_0x1030f3bc();
      if (*piVar2 == 1) {
        puVar3 = auStack_4;
        piVar2 = (int *)func_0x1030f3bc();
        if (piVar2[1] != 0) {
          piVar2 = (int *)func_0x1030f3bc(auStack_8);
          iVar1 = piVar2[1];
          if ((iVar1 != 0) && (piVar2 = piVar4, 0 < (int)piVar4)) {
            *(int **)(iVar1 + 0x1d4) = piVar4;
            *(undefined4 *)(iVar1 + 0x1d8) = unaff_ESI;
            *(undefined4 *)(iVar1 + 0x1dc) = unaff_EDI;
            *(undefined4 **)(iVar1 + 0x1e0) = puVar5;
            func_0x103146af(piVar4,unaff_ESI,unaff_EDI,puVar5,uStack_14);
            *(uint *)(iVar1 + 0x1e8) = *(uint *)(iVar1 + 0x1e4) >> 6 & 1;
            *(undefined1 **)(iVar1 + 0x1f0) = puVar3;
            piVar2 = (int *)(**(code **)(*_DAT_109d5e68 + 0xc0))(0,unaff_EDI);
          }
        }
      }
    }
  }
  return (uint)piVar2 & 0xffffff00;
}

