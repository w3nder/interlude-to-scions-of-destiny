
void __thiscall FUN_10909000(void *this,int param_1,int param_2)

{
  int iVar1;

  iVar1 = *(int *)((int)this + 0x3c);
  if (iVar1 < 0x7a) {
    if (iVar1 != 0x79) {
      if (iVar1 == 0) goto switchD_10909059_caseD_d3;
      if (iVar1 != 0x6f) {
        return;
      }
    }
    (**(code **)(**(int **)((int)this + 0x38) + 4))(param_1,param_2);
    iVar1 = 0;
    if (0 < param_2) {
      do {
        *(byte *)(iVar1 + param_1) = *(byte *)(iVar1 + param_1) ^ *(byte *)((int)this + 0x44);
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_2);
    }
  }
  else {
    switch(iVar1) {
    case 0xd3:
    case 0xd4:
    case 0x19b:
    case 0x19c:
    case 0x19d:
switchD_10909059_caseD_d3:
                    /* WARNING: Could not recover jumptable at 0x10909068. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)((int)this + 0x38) + 4))();
      return;
    }
  }
  return;
}
