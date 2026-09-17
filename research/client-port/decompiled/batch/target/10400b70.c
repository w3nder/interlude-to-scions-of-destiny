
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_10400b70(void)

{
  uint uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_c = 0x1080e450;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  uStack_8 = 0;
  (**(code **)(**(int **)(_DAT_10b1f538 + 0x54) + 0x4e8))();
  uVar1 = _Logf_FOutputDevice__QAAXPBGZZ
                    (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,0x1087eac0);
  *unaff_FS_OFFSET = uStack_10;
  return uVar1 & 0xffffff00;
}

