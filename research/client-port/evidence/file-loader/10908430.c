
FArchive * __thiscall
FUN_10908430(void *this,HANDLE param_1,int param_2,uint param_3,wchar_t *param_4)

{
  HANDLE pvVar1;
  void *this_00;
  DWORD DVar2;
  FArchive *pFVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  ushort local_28;
  undefined1 local_26 [2];
  undefined1 local_24 [2];
  undefined2 local_22;
  void *local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_10921d09;
  local_10 = ExceptionList;
  local_14 = &stack0xffffffcc;
  ExceptionList = &local_10;
  local_1c = this;
  FArchive::FArchive(this);
  *(undefined ***)this = &PTR_LAB_10927e80;
  *(undefined4 *)((int)this + 0x1c) = 1;
  *(undefined4 *)((int)this + 0x10) = 1;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined1 *)((int)this + 0x44) = 0xac;
  local_8 = 1;
  this_00 = (void *)(**(code **)**(undefined4 **)GMalloc_exref)(0x454,L"WindowsFileReader");
  pvVar1 = param_1;
  if (this_00 == (void *)0x0) {
    pFVar3 = (FArchive *)0x0;
  }
  else {
    DVar2 = GetFileSize(param_1,(LPDWORD)0x0);
    pFVar3 = thunk_FUN_10908640(this_00,pvVar1,param_2,DVar2);
  }
  *(FArchive **)((int)this + 0x38) = pFVar3;
  if (pFVar3 != (FArchive *)0x0) {
    param_2 = 1;
    if (0x18 < param_3) {
      for (uVar6 = 0; uVar6 < 0xb; uVar6 = uVar6 + 1) {
        (**(code **)(**(int **)((int)this + 0x38) + 4))((int)&param_1 + 2,2);
        if (param_1._2_2_ != u_Lineage2Ver_109335e0[uVar6]) goto LAB_10908575;
      }
      if (param_2 != 0) {
        (**(code **)(**(int **)((int)this + 0x38) + 4))(&local_28,2);
        (**(code **)(**(int **)((int)this + 0x38) + 4))(local_26,2);
        (**(code **)(**(int **)((int)this + 0x38) + 4))(local_24,2);
        local_22 = 0;
        iVar4 = appAtoi(&local_28);
        *(int *)((int)this + 0x3c) = iVar4;
        *(undefined4 *)((int)this + 0x40) = 0x1c;
        if (iVar4 == 0x6f) {
          *(undefined1 *)((int)this + 0x44) = 0xac;
          ExceptionList = local_10;
          return this;
        }
        if (iVar4 == 0x79) {
          uVar5 = thunk_FUN_10904ca0(param_4);
          *(char *)((int)this + 0x44) = (char)uVar5;
          ExceptionList = local_10;
          return this;
        }
        *(undefined1 *)((int)this + 0x44) = 0;
        ExceptionList = local_10;
        return this;
      }
    }
LAB_10908575:
    (**(code **)(**(int **)((int)this + 0x38) + 0x3c))(0);
  }
  ExceptionList = local_10;
  return this;
}
