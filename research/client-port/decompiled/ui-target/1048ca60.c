
void __thiscall packet_1048ca60(int param_1,undefined4 param_2)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_c = 0x10816110;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  uStack_8 = 0;
  (**(code **)(**(int **)(param_1 + 0x68) + 0x724))(param_2);
  *unaff_FS_OFFSET = uStack_10;
  return;
}

