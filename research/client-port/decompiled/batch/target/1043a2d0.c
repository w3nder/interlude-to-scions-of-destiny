
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_1043a2d0(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uStack_18;
  undefined1 auStack_14 [4];
  undefined1 auStack_10 [4];
  undefined1 auStack_c [4];
  undefined1 auStack_8 [4];
  undefined1 auStack_4 [4];
  
  func_0x103034e5(*(undefined4 *)(param_1 + 0x48),param_2,0x108874cc,&param_1,&uStack_18,auStack_c,
                  auStack_10,auStack_14,auStack_8,auStack_4);
  piVar2 = (int *)0x0;
  if (_DAT_10b1f538 != (int *)0x0) {
    puVar6 = &param_1;
    iVar1 = func_0x1030d04e();
    piVar2 = (int *)0x0;
    if ((iVar1 != 0) &&
       (piVar5 = (int *)register0x00000010, piVar2 = (int *)func_0x1030d04e(), *piVar2 == 1)) {
      puVar4 = auStack_4;
      piVar2 = (int *)func_0x1030d04e();
      if (piVar2[1] != 0) {
        puVar3 = auStack_8;
        piVar2 = (int *)func_0x1030d04e();
        iVar1 = piVar2[1];
        if ((iVar1 != 0) && (piVar2 = piVar5, 0 < (int)piVar5)) {
          *(int **)(iVar1 + 0x284) = piVar5;
          *(undefined4 *)(iVar1 + 0x288) = unaff_EDI;
          *(undefined4 *)(iVar1 + 0x28c) = unaff_ESI;
          *(undefined4 **)(iVar1 + 0x290) = puVar6;
          func_0x10303df5(piVar5,unaff_EDI,unaff_ESI,puVar6,uStack_18,0x80000000);
          *(uint *)(iVar1 + 0x298) = *(uint *)(iVar1 + 0x294) >> 6 & 1;
          *(undefined1 **)(iVar1 + 0x2a0) = puVar3;
          *(undefined1 **)(iVar1 + 0x310) = puVar4;
          piVar2 = (int *)(**(code **)(*_DAT_10b1f538 + 0xc4))(0,unaff_ESI);
        }
      }
    }
  }
  return (uint)piVar2 & 0xffffff00;
}

