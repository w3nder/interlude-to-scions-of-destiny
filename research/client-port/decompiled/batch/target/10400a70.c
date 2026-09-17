
uint packet_10400a70(void)

{
  uint uVar1;
  uint *unaff_FS_OFFSET;
  undefined1 auStack_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (uint)auStack_10;
  *unaff_FS_OFFSET = uVar1;
  return uVar1 & 0xffffff00;
}

