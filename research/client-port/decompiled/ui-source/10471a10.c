
void __thiscall packet_10471a10(int param_1,undefined4 param_2)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  puStack_c = &UNK_1075a500;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  uStack_8 = 0;
  (**(code **)(**(int **)(param_1 + 0x34) + 0x660))(param_2);
  *unaff_FS_OFFSET = uStack_10;
  return;
}

