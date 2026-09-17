undefined4 __thiscall packet_10094100(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_18;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;

  iVar2 = param_2;
  puStack_c = &UNK_10186280;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  uStack_8 = 0;
  uVar5 = func_0x10171a14();
  uVar5 = func_0x10171a14(uVar5);
  func_0x100134b0(param_1[0x11] + -1,param_1[0x12] + -1,uVar5);
  iVar7 = param_1[0x11];
  iVar6 = param_1[0x12];
  *(int *)(param_2 + 0x38) = iVar7;
  *(int *)(param_2 + 0x3c) = iVar6;
  *(int *)(param_2 + 0x6c) = iVar7;
  *(undefined4 *)(param_2 + 0x58) = 0;
  *(undefined4 *)(param_2 + 0x54) = *(undefined4 *)(param_2 + 0x3c);
  iStack_18 = 0;
  param_2 = 0;
  iStack_2c = 0;
  do {
    if (param_1[0x3d] <= iStack_2c) {
      if (param_1[0x56] != 0) {
        iVar7 = func_0x10074500();
        for (param_2 = 0; param_2 < iVar7; param_2 = param_2 + 1) {
          func_0x10012f10(0xd7,param_2 * 0x1b + 8,0x1a,0x1a,0,0,0x1a,0x1a,param_1[0x56],0xff,1);
          if ((param_2 < param_1[0x40]) && (iVar6 = func_0x10151a40(), iVar6 != 0)) {
            uVar5 = func_0x10151a40();
            iVar6 = param_2 * 0x1b + 9;
            func_0x10012d70(0xd8,iVar6,0x18,0x18,uVar5,1,0xff);
            if (*(int *)(*(int *)(param_1[0x3f] + param_2 * 4) + 0x1b40) == 0) {
              uVar5 = func_0x1002b490(&UNK_101a62ac,1);
              func_0x10012f10(0xd9,iVar6,0x18,0x18,0,0,0x18,0x18,uVar5,0xff,1);
            }
          }
        }
      }
      *(undefined4 *)(iVar2 + 0x38) = 0;
      *(undefined4 *)(iVar2 + 0x3c) = 0;
      func_0x100134c0();
      *unaff_FS_OFFSET = uStack_10;
      return 1;
    }
    iVar7 = *(int *)(param_1[0x3c] + iStack_2c * 4);
    if (iVar7 != 0) {
      iVar6 = (**(code **)(*param_1 + 0x128))
                        (*(undefined4 *)(iVar7 + 0x1b30),*(undefined4 *)(iVar7 + 0x1b1c));
      bVar1 = false;
      switch(iVar6) {
      case 0:
        iStack_18 = 7;
        param_2 = 7;
        break;
      case 1:
        iStack_18 = 0x2e;
        param_2 = 7;
        break;
      case 2:
        iStack_18 = 0x55;
        param_2 = 7;
        break;
      case 3:
        iStack_18 = 0x82;
        param_2 = 7;
        break;
      case 4:
        iStack_18 = 0xa9;
        param_2 = 7;
        break;
      case 5:
        iStack_18 = 7;
        param_2 = 0x2d;
        break;
      case 6:
        iStack_18 = 0x2e;
        param_2 = 0x2d;
        break;
      case 7:
        iStack_18 = 0x55;
        param_2 = 0x2d;
        break;
      case 8:
        iStack_18 = 0x82;
        param_2 = 0x2d;
        break;
      case 9:
        iStack_18 = 0xa9;
        param_2 = 0x2d;
        break;
      case 10:
        iStack_18 = 7;
        param_2 = 0x53;
        break;
      case 0xb:
        iStack_18 = 0x2e;
        param_2 = 0x53;
        break;
      case 0xc:
        iStack_18 = 0x55;
        param_2 = 0x53;
        break;
      case 0xd:
        iStack_18 = 0x82;
        param_2 = 0x53;
        break;
      case 0xe:
        iStack_18 = 0xa9;
        param_2 = 0x53;
        break;
      case 0xf:
      case 0x10:
      case 0x11:
        bVar1 = true;
        break;
      default:
        goto LAB_10094731;
      }
      if (((*(int *)(iVar7 + 0x1b3c) == 6) || (*(int *)(iVar7 + 0x1b3c) == 10)) &&
         (param_1[0x58] != 0)) {
        iStack_18 = 7;
        param_2 = 0x2d;
code_r0x1009431a:
        uVar5 = func_0x10151a40();
        iVar7 = param_1[0x5e];
        func_0x10012f10(iStack_18,param_2,iVar7,iVar7,0,0,iVar7,iVar7,uVar5,0xff,1);
        iVar7 = func_0x1001e760();
        if (iVar7 == 0) {
          iVar6 = param_2 + -1;
          iVar8 = iStack_18 + -1;
          func_0x10012f10(iVar8,iVar6,0x22,0x22,0,0,0x22,0x22,param_1[0x52],0xff,1);
          iVar7 = param_1[0x53];
          uVar11 = 0x23;
          uVar10 = 0x23;
          uVar9 = 0x23;
          uVar5 = 0x23;
        }
        else {
          iVar7 = param_1[0x51];
          uVar11 = 0x22;
          uVar10 = 0x22;
          uVar9 = 0x22;
          uVar5 = 0x22;
          iVar6 = param_2 + -1;
          iVar8 = iStack_18 + -1;
        }
      }
      else {
        if (!bVar1) goto code_r0x1009431a;
        iVar8 = 0;
        iStack_20 = 0;
        iStack_28 = 0;
        iStack_24 = 0;
        if (*(short *)(iVar7 + 0x514) != 0) {
          iVar8 = func_0x10151a50();
        }
        if (*(short *)(iVar7 + 0x614) != 0) {
          iStack_20 = func_0x10005ca0();
        }
        if (*(short *)(iVar7 + 0x714) != 0) {
          iStack_28 = func_0x1014b810();
        }
        if (*(short *)(iVar7 + 0x814) != 0) {
          iStack_24 = func_0x1014b7f0();
        }
        if (iVar8 == 0) {
          iVar8 = func_0x10151a40();
          iVar7 = iVar8;
          iVar3 = iVar8;
          iVar4 = iVar8;
        }
        else {
          iVar7 = iVar8;
          iVar3 = iVar8;
          iVar4 = iVar8;
          if (iStack_20 != 0) {
            iVar4 = iStack_20;
            if (iStack_28 == 0) {
              iStack_24 = iStack_20;
              iStack_28 = iStack_20;
              iVar7 = iStack_28;
              iVar3 = iStack_24;
            }
            else {
              iVar7 = iStack_28;
              iVar3 = iStack_24;
              if (iStack_24 == 0) {
                iStack_24 = iStack_28;
                iVar3 = iStack_24;
              }
            }
          }
        }
        iStack_20 = iVar4;
        iStack_24 = iVar3;
        iStack_28 = iVar7;
        if (iVar6 == 0x10) {
          iVar7 = param_1[0x5e];
          func_0x10012f10(7,0x2d,iVar7,iVar7,0,0,iVar7,iVar7,iVar8,0xff,1);
          iVar7 = param_1[0x5e];
          func_0x10012f10(0x55,0x2d,iVar7,iVar7,0,0,iVar7,iVar7,iStack_20,0xff,1);
          iVar7 = param_1[0x5e];
          func_0x10012f10(0x55,0x2d,iVar7,iVar7,0,0,iVar7,iVar7,param_1[0x55],0xff,1);
          iVar7 = func_0x1001e760();
          if (iVar7 == 0) {
            func_0x10012f10(6,0x2c,0x22,0x22,0,0,0x22,0x22,param_1[0x52],0xff,1);
            iVar7 = param_1[0x53];
            uVar11 = 0x23;
            uVar10 = 0x23;
            uVar9 = 0x23;
            uVar5 = 0x23;
            iVar6 = 0x2c;
            iVar8 = 6;
          }
          else {
            iVar7 = param_1[0x51];
            uVar11 = 0x22;
            uVar10 = 0x22;
            uVar9 = 0x22;
            uVar5 = 0x22;
            iVar6 = 0x2c;
            iVar8 = 6;
          }
        }
        else {
          if (iVar6 == 0xf) {
            iVar7 = param_1[0x5e];
            func_0x10012f10(0x2e,0x2d,iVar7,iVar7,0,0,iVar7,iVar7,iVar8,0xff,1);
            iVar7 = param_1[0x5e];
            func_0x10012f10(0x2e,0x53,iVar7,iVar7,0,0,iVar7,iVar7,iStack_20,0xff,1);
            iVar7 = param_1[0x5e];
            iVar6 = param_1[0x55];
            uVar5 = 0x2e;
          }
          else {
            if (iVar6 != 0x11) goto LAB_10094731;
            iVar7 = param_1[0x5e];
            func_0x10012f10(0x2e,0x2d,iVar7,iVar7,0,0,iVar7,iVar7,iVar8,0xff,1);
            iVar7 = param_1[0x5e];
            func_0x10012f10(0x2e,0x53,iVar7,iVar7,0,0,iVar7,iVar7,iStack_20,0xff,1);
            iVar7 = param_1[0x5e];
            func_0x10012f10(0x2e,0x53,iVar7,iVar7,0,0,iVar7,iVar7,param_1[0x55],0xff,1);
            iVar7 = param_1[0x5e];
            func_0x10012f10(7,0x53,iVar7,iVar7,0,0,iVar7,iVar7,iStack_28,0xff,1);
            iVar7 = param_1[0x5e];
            func_0x10012f10(7,0x53,iVar7,iVar7,0,0,iVar7,iVar7,param_1[0x55],0xff,1);
            iVar7 = param_1[0x5e];
            func_0x10012f10(0x55,0x53,iVar7,iVar7,0,0,iVar7,iVar7,iStack_24,0xff,1);
            iVar7 = param_1[0x5e];
            iVar6 = param_1[0x55];
            uVar5 = 0x55;
          }
          func_0x10012f10(uVar5,0x53,iVar7,iVar7,0,0,iVar7,iVar7,iVar6,0xff,1);
          iVar7 = func_0x1001e760();
          if (iVar7 == 0) {
            func_0x10012f10(0x2d,0x2c,0x22,0x22,0,0,0x22,0x22,param_1[0x52],0xff,1);
            iVar7 = param_1[0x53];
            uVar11 = 0x23;
            uVar10 = 0x23;
            uVar9 = 0x23;
            uVar5 = 0x23;
            iVar6 = 0x2c;
            iVar8 = 0x2d;
          }
          else {
            iVar7 = param_1[0x51];
            uVar11 = 0x22;
            uVar10 = 0x22;
            uVar9 = 0x22;
            uVar5 = 0x22;
            iVar6 = 0x2c;
            iVar8 = 0x2d;
          }
        }
      }
      func_0x10012f10(iVar8,iVar6,uVar5,uVar9,0,0,uVar10,uVar11,iVar7,0xff,1);
    }
LAB_10094731:
    iStack_2c = iStack_2c + 1;
  } while( true );
}
