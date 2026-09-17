
void __fastcall packet_1048b7e0(int param_1)

{
  if (*(int *)(param_1 + 0x68) != 0) {
                    /* WARNING: Could not recover jumptable at 0x1048b7f1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x68) + 0x644))();
    return;
  }
  return;
}

