/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall packet_10175bc0(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *unaff_FS_OFFSET;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;

  iVar2 = param_2;
  puStack_c = &UNK_10212ae0;
  iStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_10;
  uStack_8 = 0;
  uVar5 = func_0x101c19e0();
  uVar5 = func_0x101c19e0(uVar5);
  func_0x10021df0(param_1[0x20] + -1,param_1[0x21] + -1,uVar5);
  func_0x10002f40(param_1[0x20],param_1[0x21]);
  iStack_20 = 0;
  iStack_1c = 0;
  iVar6 = 0;
LAB_10175c50:
  do {
    while( true ) {
      if (param_1[0x76] <= iVar6) {
        if (param_1[0x8f] != 0) {
          iVar6 = func_0x1014e4a0();
          for (iStack_30 = 0; iStack_30 < iVar6; iStack_30 = iStack_30 + 1) {
            func_0x10021a00(0xd7,iStack_30 * 0x1b + 8,0x1a,0x1a,0,0,0x1a,0x1a,param_1[0x8f],0xff,1);
            if ((iStack_30 < param_1[0x79]) && (iVar8 = func_0x1002c970(), iVar8 != 0)) {
              iVar8 = iStack_30 * 0x1b + 9;
              uVar5 = func_0x1002c970(1,0xff);
              func_0x100218f0(0xd8,iVar8,0x18,0x18,uVar5);
              if (*(int *)(*(int *)(iStack_30 * 4 + param_1[0x78]) + 0x1e7c) == 0) {
                uVar5 = func_0x1003f630(&UNK_10237710,1,0xff,1);
                func_0x10021a00(0xd9,iVar8,0x18,0x18,0,0,0x18,0x18,uVar5);
              }
            }
          }
        }
        *(undefined4 *)(iVar2 + 0x38) = 0;
        *(undefined4 *)(iVar2 + 0x3c) = 0;
        func_0x100212e0();
        *unaff_FS_OFFSET = iStack_10;
        return 1;
      }
      iVar8 = *(int *)(param_1[0x75] + iVar6 * 4);
      if (iVar8 != 0) break;
LAB_10176340:
      iVar6 = iVar6 + 1;
    }
    iVar7 = (**(code **)(*param_1 + 500))
                      (*(undefined4 *)(iVar8 + 0x1e6c),*(undefined4 *)(iVar8 + 0x1e58));
    bVar1 = false;
    switch(iVar7) {
    case 0:
      iStack_20 = 7;
      iStack_1c = 7;
      break;
    case 1:
      iStack_20 = 0x2e;
      iStack_1c = 7;
      break;
    case 2:
      iStack_20 = 0x55;
      iStack_1c = 7;
      break;
    case 3:
      iStack_20 = 0x82;
      iStack_1c = 7;
      break;
    case 4:
      iStack_20 = 0xa9;
      iStack_1c = 7;
      break;
    case 5:
      iStack_20 = 7;
      iStack_1c = 0x2d;
      break;
    case 6:
      iStack_20 = 0x2e;
      iStack_1c = 0x2d;
      break;
    case 7:
      iStack_20 = 0x55;
      iStack_1c = 0x2d;
      break;
    case 8:
      iStack_20 = 0x82;
      iStack_1c = 0x2d;
      break;
    case 9:
      iStack_20 = 0xa9;
      iStack_1c = 0x2d;
      break;
    case 10:
      iStack_20 = 7;
      iStack_1c = 0x53;
      break;
    case 0xb:
      iStack_20 = 0x2e;
      iStack_1c = 0x53;
      break;
    case 0xc:
      iStack_20 = 0x55;
      iStack_1c = 0x53;
      break;
    case 0xd:
      iStack_20 = 0x82;
      iStack_1c = 0x53;
      break;
    case 0xe:
      iStack_20 = 0xa9;
      iStack_1c = 0x53;
      break;
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x12:
      bVar1 = true;
      break;
    default:
      goto LAB_10176340;
    }
    if (((*(int *)(iVar8 + 0x1e78) == 6) || (*(int *)(iVar8 + 0x1e78) == 10)) &&
       (param_1[0x91] != 0)) {
      iStack_20 = 7;
      iStack_1c = 0x2d;
code_r0x10175dde:
      iVar8 = param_1[0x97];
      uVar5 = func_0x1002c970(0xff,1);
      func_0x10021a00(iStack_20,iStack_1c,iVar8,iVar8,0,0,iVar8,iVar8,uVar5);
      iVar8 = func_0x1002cc60();
      if (iVar8 == 0) {
        func_0x10021a00(iStack_20 + -1,iStack_1c + -1,0x22,0x22,0,0,0x22,0x22,param_1[0x8b],0xff,1);
        func_0x10021a00(iStack_20 + -1,iStack_1c + -1,0x23,0x23,0,0,0x23,0x23,param_1[0x8c],0xff,1);
        iVar6 = iVar6 + 1;
      }
      else {
        func_0x10021a00(iStack_20 + -1,iStack_1c + -1,0x22,0x22,0,0,0x22,0x22,param_1[0x8a],0xff,1);
        iVar6 = iVar6 + 1;
      }
      goto LAB_10175c50;
    }
    if (!bVar1) goto code_r0x10175dde;
    iStack_28 = 0;
    iStack_24 = 0;
    iStack_2c = 0;
    param_2 = 0;
    if (*(short *)(iVar8 + 0x54c) != 0) {
      iStack_28 = func_0x10178820();
    }
    if (*(short *)(iVar8 + 0x64c) != 0) {
      iStack_24 = func_0x1002c980();
    }
    if (*(short *)(iVar8 + 0x74c) != 0) {
      iStack_2c = func_0x1002c990();
    }
    if (*(short *)(iVar8 + 0x84c) != 0) {
      param_2 = func_0x1002c9a0();
    }
    if (iStack_28 == 0) {
      iStack_28 = func_0x1002c970();
      iVar8 = iStack_28;
      iVar3 = iStack_28;
      iVar4 = iStack_28;
    }
    else {
      iVar8 = iStack_28;
      iVar3 = iStack_28;
      iVar4 = iStack_28;
      if (iStack_24 != 0) {
        iVar4 = iStack_24;
        if (iStack_2c == 0) {
          iStack_2c = iStack_24;
        }
        else {
          iVar8 = param_2;
          iVar3 = iStack_2c;
          if (param_2 != 0) goto code_r0x10175f72;
        }
        iVar8 = iStack_2c;
        iVar3 = iStack_2c;
      }
    }
code_r0x10175f72:
    iStack_24 = iVar4;
    iStack_2c = iVar3;
    param_2 = iVar8;
    if (iVar7 == 0x10) {
      iVar8 = param_1[0x97];
      func_0x10021a00(7,0x2d,iVar8,iVar8,0,0,iVar8,iVar8,iStack_28,0xff,1);
      iVar8 = param_1[0x97];
      func_0x10021a00(0x55,0x2d,iVar8,iVar8,0,0,iVar8,iVar8,iStack_24,0xff,1);
      iVar8 = param_1[0x97];
      func_0x10021a00(0x55,0x2d,iVar8,iVar8,0,0,iVar8,iVar8,param_1[0x8e],0xff,1);
      iVar8 = func_0x1002cc60();
      if (iVar8 == 0) {
        func_0x10021a00(6,0x2c,0x22,0x22,0,0,0x22,0x22,param_1[0x8b],0xff,1);
        iVar8 = param_1[0x8c];
        uVar12 = 0x23;
        uVar11 = 0x23;
        uVar10 = 0x23;
        uVar9 = 0x23;
        uVar5 = 0x2c;
      }
      else {
        iVar8 = param_1[0x8a];
        uVar12 = 0x22;
        uVar11 = 0x22;
        uVar10 = 0x22;
        uVar9 = 0x22;
        uVar5 = 0x2c;
      }
code_r0x10176337:
      func_0x10021a00(6,uVar5,uVar9,uVar10,0,0,uVar11,uVar12,iVar8,0xff,1);
      goto LAB_10176340;
    }
    if (iVar7 == 0xf) {
      iVar8 = param_1[0x97];
      func_0x10021a00(0x2e,0x2d,iVar8,iVar8,0,0,iVar8,iVar8,iStack_28,0xff,1);
      iVar8 = param_1[0x97];
      func_0x10021a00(0x2e,0x53,iVar8,iVar8,0,0,iVar8,iVar8,iStack_24,0xff,1);
      iVar8 = param_1[0x97];
      iVar7 = param_1[0x8e];
      uVar5 = 0x2e;
    }
    else {
      if (iVar7 != 0x11) {
        if (iVar7 != 0x12) goto LAB_10176340;
        iVar8 = param_1[0x97];
        func_0x10021a00(7,7,iVar8,iVar8,0,0,iVar8,iVar8,iStack_28,0xff,1);
        iVar8 = param_1[0x97];
        func_0x10021a00(0x55,7,iVar8,iVar8,0,0,iVar8,iVar8,iStack_24,0xff,1);
        iVar8 = param_1[0x97];
        func_0x10021a00(0x55,7,iVar8,iVar8,0,0,iVar8,iVar8,param_1[0x8e],0xff,1);
        iVar8 = func_0x1002cc60();
        if (iVar8 == 0) {
          func_0x10021a00(6,6,0x22,0x22,0,0,0x22,0x22,param_1[0x8b],0xff,1);
          iVar8 = param_1[0x8c];
          uVar12 = 0x23;
          uVar11 = 0x23;
          uVar10 = 0x23;
          uVar9 = 0x23;
        }
        else {
          iVar8 = param_1[0x8a];
          uVar12 = 0x22;
          uVar11 = 0x22;
          uVar10 = 0x22;
          uVar9 = 0x22;
        }
        uVar5 = 6;
        goto code_r0x10176337;
      }
      iVar8 = param_1[0x97];
      func_0x10021a00(0x2e,0x2d,iVar8,iVar8,0,0,iVar8,iVar8,iStack_28,0xff,1);
      iVar8 = param_1[0x97];
      func_0x10021a00(0x2e,0x53,iVar8,iVar8,0,0,iVar8,iVar8,iStack_24,0xff,1);
      iVar8 = param_1[0x97];
      func_0x10021a00(0x2e,0x53,iVar8,iVar8,0,0,iVar8,iVar8,param_1[0x8e],0xff,1);
      iVar8 = param_1[0x97];
      func_0x10021a00(7,0x53,iVar8,iVar8,0,0,iVar8,iVar8,iStack_2c,0xff,1);
      iVar8 = param_1[0x97];
      func_0x10021a00(7,0x53,iVar8,iVar8,0,0,iVar8,iVar8,param_1[0x8e],0xff,1);
      iVar8 = param_1[0x97];
      func_0x10021a00(0x55,0x53,iVar8,iVar8,0,0,iVar8,iVar8,param_2,0xff,1);
      iVar8 = param_1[0x97];
      iVar7 = param_1[0x8e];
      uVar5 = 0x55;
    }
    func_0x10021a00(uVar5,0x53,iVar8,iVar8,0,0,iVar8,iVar8,iVar7,0xff,1);
    iVar8 = func_0x1002cc60();
    if (iVar8 == 0) {
      func_0x10021a00(0x2d,0x2c,0x22,0x22,0,0,0x22,0x22,param_1[0x8b],0xff,1);
      func_0x10021a00(0x2d,0x2c,0x23,0x23,0,0,0x23,0x23,param_1[0x8c],0xff,1);
      iVar6 = iVar6 + 1;
    }
    else {
      func_0x10021a00(0x2d,0x2c,0x22,0x22,0,0,0x22,0x22,param_1[0x8a],0xff,1);
      iVar6 = iVar6 + 1;
    }
  } while( true );
}
