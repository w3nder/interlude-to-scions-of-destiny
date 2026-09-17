
void __fastcall packet_104706f0(int param_1)

{
  if (*(int **)(param_1 + 0x34) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x104706f9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x34) + 0x5a0))();
    return;
  }
  return;
}

