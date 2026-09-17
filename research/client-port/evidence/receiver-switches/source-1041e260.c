
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_1041e260(int param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int unaff_EBX;
  int iStack_9c;
  int iStack_98;
  int iStack_94;
  int iStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  int iStack_7c;
  undefined4 uStack_78;
  undefined4 *puStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined1 auStack_68 [4];
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  short asStack_40 [2];
  short asStack_3c [2];
  undefined1 auStack_38 [52];

  func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c6f64,&iStack_98,&iStack_94,0x30,
                  auStack_38,&iStack_90,&uStack_84,&uStack_88,&uStack_8c,&uStack_4c,&uStack_70,
                  auStack_68,&uStack_48,asStack_40,&iStack_7c,&uStack_78,&puStack_74,&uStack_80);
  if ((((_DAT_109d5e68 == 0) || (iVar2 = func_0x1030f3bc(&iStack_98), iVar2 == 0)) ||
      (piVar3 = (int *)func_0x1030f3bc(&iStack_98), *piVar3 != 1)) ||
     ((iVar2 = func_0x1030f3bc(&iStack_98), *(int *)(iVar2 + 4) == 0 ||
      (iVar2 = func_0x1030f3bc(&iStack_98), *(int *)(iVar2 + 4) == 0)))) {
    iVar2 = (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(0x248,&UNK_107c6f38);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = func_0x10302d06();
    }
    piVar3 = (int *)(iVar2 + 0x18);
    *piVar3 = unaff_EBX;
    *(undefined4 *)(iVar2 + 8) = 1;
    *(undefined4 *)(iVar2 + 0x90) = 0;
    *(int *)(iVar2 + 0x14) = iStack_9c + -1000000;
    if (asStack_40[0] == 0) {
      iVar4 = func_0x1030a083((int *)(iVar2 + 0x14));
      if (iVar4 != 0) {
        uVar5 = __DFString__QBEPBGXZ();
        func_0x10309930(uVar5);
        *(undefined4 *)(iVar2 + 0xe4) = *(undefined4 *)(iVar4 + 0x1c);
      }
    }
    else {
      func_0x10309930(asStack_40);
    }
    *(int *)(iVar2 + 0x10) = iStack_9c;
    *(int *)(iVar2 + 0x118) = iStack_7c;
    *(undefined4 *)(iVar2 + 0x11c) = uStack_78;
    *(undefined4 *)(iVar2 + 0x114) = uStack_70;
    *(undefined4 **)(iVar2 + 0x110) = puStack_74;
    *(float *)(iVar2 + 0x120) = (float)(double)CONCAT44(uStack_50,uStack_54);
    *(float *)(iVar2 + 0x124) = (float)(double)CONCAT44(uStack_48,uStack_4c);
    *(undefined4 *)(iVar2 + 0x78) = uStack_88;
    *(undefined4 *)(iVar2 + 0x7c) = uStack_84;
    if ((0 < *piVar3) && (_DAT_109d5e68 != 0)) {
      iVar4 = func_0x1030f3bc(piVar3);
      if (iVar4 != 0) {
        func_0x10306203(iVar4);
        func_0x1030720c(piVar3);
      }
      puStack_74 = (undefined4 *)
                   (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)(8,&UNK_10792bd0);
      if (puStack_74 == (undefined4 *)0x0) {
        puStack_74 = (undefined4 *)0x0;
      }
      else {
        *puStack_74 = 0;
        puStack_74[1] = 0;
      }
      if (puStack_74 != (undefined4 *)0x0) {
        puStack_74[1] = iVar2;
        *puStack_74 = 1;
      }
      func_0x1030cb1c(piVar3,&puStack_74);
    }
    fStack_64 = (float)iStack_90;
    fStack_60 = (float)iStack_94;
    fStack_5c = (float)iStack_98;
    *(undefined4 *)(iVar2 + 0x158) = 0;
    (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x198))
              (iVar2,fStack_64,fStack_60,fStack_5c,uStack_58,uStack_80,uStack_8c);
  }
  else {
    iVar2 = func_0x1030f3bc(&iStack_98);
    if ((iVar2 == 0) ||
       ((piVar3 = (int *)func_0x1030f3bc(&iStack_9c), *piVar3 != 1 ||
        (iVar2 = func_0x1030f3bc(&iStack_9c), *(int *)(iVar2 + 4) == 0)))) {
      iVar2 = 0;
    }
    else {
      iVar2 = func_0x1030f3bc(&iStack_9c);
      iVar2 = *(int *)(iVar2 + 4);
    }
    *(undefined4 *)(iVar2 + 8) = 1;
    *(undefined4 *)(iVar2 + 0x90) = 0;
    *(int *)(iVar2 + 0x14) = iStack_98 + -1000000;
    if (asStack_3c[0] == 0) {
      iVar4 = func_0x1030a083((int *)(iVar2 + 0x14));
      if (iVar4 != 0) {
        uVar5 = __DFString__QBEPBGXZ();
        func_0x10309930(uVar5);
        *(undefined4 *)(iVar2 + 0xe4) = *(undefined4 *)(iVar4 + 0x1c);
      }
    }
    else {
      func_0x10309930(asStack_3c);
    }
    *(int *)(iVar2 + 0x10) = iStack_98;
    *(undefined4 **)(iVar2 + 0x11c) = puStack_74;
    *(undefined4 *)(iVar2 + 0x118) = uStack_78;
    *(undefined4 *)(iVar2 + 0x110) = uStack_70;
    *(undefined4 *)(iVar2 + 0x114) = uStack_6c;
    *(float *)(iVar2 + 0x120) = (float)(double)CONCAT44(uStack_4c,uStack_50);
    *(float *)(iVar2 + 0x124) = (float)(double)CONCAT44(uStack_44,uStack_48);
    *(undefined4 *)(iVar2 + 0x78) = uStack_84;
    *(undefined4 *)(iVar2 + 0x7c) = uStack_80;
    if (*(int *)(iVar2 + 0x158) != 0) {
      *(float *)(*(int *)(iVar2 + 0x158) + 0x5f8) = (float)*(double *)(iVar2 + 0x110);
      *(float *)(*(int *)(iVar2 + 0x158) + 0x5fc) = (float)*(double *)(iVar2 + 0x118);
      iVar2 = *(int *)(iVar2 + 0x158);
      if (*(char *)(*(int *)(iVar2 + 0x13f0) + 0x41c) == '\x01') {
        fVar1 = *(float *)(iVar2 + 0x634);
      }
      else {
        fVar1 = *(float *)(iVar2 + 0x638);
      }
      *(float *)(iVar2 + 0x1468) = fVar1 * *(float *)(iVar2 + 0x5fc);
      if (iStack_7c == 3) {
        switch(uStack_88) {
        case 0:
          func_0x1030cb53(3);
          break;
        case 1:
          func_0x1030cb53(1);
          break;
        case 2:
          func_0x1030cb53(2);
          break;
        case 3:
          func_0x1030cb53(0);
        }
      }
    }
  }
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c6e68,unaff_EBX,
             iStack_9c,iStack_98,uStack_8c,iStack_90,iStack_94);
  uVar6 = (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
                    (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c6e68,unaff_EBX,iStack_9c,
                     iStack_98,uStack_8c,iStack_90,iStack_94);
  return uVar6 & 0xffffff00;
}
