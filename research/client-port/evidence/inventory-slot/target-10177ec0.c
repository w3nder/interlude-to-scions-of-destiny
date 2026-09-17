/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall packet_10177ec0(int *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *unaff_FS_OFFSET;
  undefined4 uVar4;
  uint uStack_40;
  undefined1 auStack_30 [24];
  int iStack_18;
  undefined1 *puStack_14;
  int iStack_10;
  undefined *puStack_c;
  uint uStack_8;

  puStack_c = &UNK_10212cf4;
  iStack_10 = *unaff_FS_OFFSET;
  uStack_40 = _DAT_103554c4 ^ (uint)&stack0xfffffffc;
  puStack_14 = (undefined1 *)&uStack_40;
  *unaff_FS_OFFSET = (int)&iStack_10;
  iVar3 = 0;
  uStack_8 = 0;
  if (param_1[0xe2] == 0) {
    param_1[0x74] = 1;
    iVar1 = func_0x10176880(param_3 & 0xffff,param_3 >> 0x10);
    param_1[0x98] = iVar1;
    if ((-1 < iVar1) && (iVar1 < 0x14)) {
      for (; iStack_18 = iVar3, iVar3 < param_1[0x76]; iVar3 = iVar3 + 1) {
        iVar1 = *(int *)(param_1[0x75] + iVar3 * 4);
        iVar2 = (**(code **)(*param_1 + 500))
                          (*(undefined4 *)(iVar1 + 0x1e6c),*(undefined4 *)(iVar1 + 0x1e58));
        if (iVar2 == 0x10) {
          if (param_1[0x98] == 5) {
            __0L2ParamStack__QAE_H_Z(10);
            uStack_8 = CONCAT31(uStack_8._1_3_,1);
LAB_10177f82:
            uVar4 = *(undefined4 *)(iVar1 + 0x1e6c);
            goto LAB_10177f89;
          }
        }
        else if ((iVar2 == 0xf) || (iVar2 == 0x11)) {
          if (param_1[0x98] == 6) {
            __0L2ParamStack__QAE_H_Z(10);
            uStack_8 = CONCAT31(uStack_8._1_3_,2);
            _PushBack_L2ParamStack__QAEHPAX_Z(*(undefined4 *)(iVar1 + 0x1e6c));
            goto LAB_10177f96;
          }
        }
        else if (iVar2 == 0x12) {
          if (param_1[0x98] == 0) {
            __0L2ParamStack__QAE_H_Z(10);
            uStack_8 = CONCAT31(uStack_8._1_3_,3);
            _PushBack_L2ParamStack__QAEHPAX_Z(*(undefined4 *)(iVar1 + 0x1e6c));
LAB_10177f96:
            func_0x10142f70(auStack_30);
            uStack_8 = uStack_8 & 0xffffff00;
            __1L2ParamStack__QAE_XZ();
            break;
          }
        }
        else if (param_1[0x98] == iVar2) {
          __0L2ParamStack__QAE_H_Z(10);
          uStack_8 = CONCAT31(uStack_8._1_3_,4);
          if ((*(byte *)(iVar1 + 0x1e6c) & 6) == 0) {
            if ((*(byte *)(*(int *)(param_1[0x75] + iVar3 * 4) + 0x1e6c) & 0x30) == 0)
            goto LAB_10177f82;
            iVar3 = func_0x1014dd00();
            if (*(int *)(iVar3 + 0xa8) == *(int *)(iVar1 + 0x1e58)) {
              _PushBack_L2ParamStack__QAEHPAX_Z(0x10);
            }
            if (*(int *)(iVar3 + 0xac) == *(int *)(iVar1 + 0x1e58)) {
              uVar4 = 0x20;
              goto LAB_10177f89;
            }
          }
          else {
            iVar3 = func_0x1014dd00();
            if (*(int *)(iVar3 + 0x9c) == *(int *)(iVar1 + 0x1e58)) {
              _PushBack_L2ParamStack__QAEHPAX_Z(2);
            }
            if (*(int *)(iVar3 + 0xa0) == *(int *)(iVar1 + 0x1e58)) {
              uVar4 = 4;
LAB_10177f89:
              _PushBack_L2ParamStack__QAEHPAX_Z(uVar4);
            }
          }
          goto LAB_10177f96;
        }
      }
    }
    func_0x10176850();
    param_1[0x98] = -1;
    param_1[0x90] = 0;
  }
  *unaff_FS_OFFSET = iStack_10;
  return 1;
}
