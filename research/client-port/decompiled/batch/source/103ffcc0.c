
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint packet_103ffcc0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  int iVar3;
  int iVar4;
  int iVar5;
  int iStack_310;
  int iStack_30c;
  int iStack_308;
  int iStack_304;
  undefined4 uStack_300;
  undefined1 auStack_2fc [4];
  undefined1 auStack_2f8 [4];
  undefined4 uStack_2f4;
  undefined1 auStack_2f0 [4];
  undefined1 auStack_2ec [4];
  undefined1 auStack_2e8 [4];
  undefined1 auStack_2e4 [4];
  undefined1 auStack_2e0 [4];
  undefined1 auStack_2dc [4];
  undefined1 auStack_2d8 [4];
  undefined1 auStack_2d4 [4];
  undefined1 auStack_2d0 [4];
  undefined1 auStack_2cc [4];
  undefined1 auStack_2c8 [4];
  undefined1 auStack_2c4 [4];
  undefined1 auStack_2c0 [4];
  undefined1 auStack_2bc [4];
  undefined1 auStack_2b8 [4];
  undefined1 auStack_2b4 [4];
  undefined1 auStack_2b0 [4];
  undefined1 auStack_2ac [4];
  undefined1 auStack_2a8 [4];
  undefined1 auStack_2a4 [4];
  undefined1 auStack_2a0 [4];
  undefined1 auStack_29c [4];
  undefined1 auStack_298 [4];
  undefined1 auStack_294 [4];
  undefined1 auStack_290 [4];
  undefined1 auStack_28c [4];
  undefined1 auStack_288 [4];
  undefined1 auStack_284 [8];
  undefined1 auStack_27c [4];
  undefined1 auStack_278 [8];
  undefined1 auStack_270 [4];
  undefined1 auStack_26c [12];
  undefined4 uStack_260;
  undefined1 auStack_24c [48];
  undefined1 auStack_21c [4];
  undefined4 uStack_218;
  undefined1 auStack_214 [4];
  undefined1 auStack_210 [8];
  undefined1 auStack_208 [4];
  undefined1 auStack_204 [4];
  undefined1 auStack_200 [4];
  undefined1 auStack_1fc [4];
  undefined1 auStack_1f8 [4];
  undefined1 auStack_1f4 [8];
  undefined4 uStack_1ec;
  undefined4 uStack_1e4;
  undefined4 uStack_1d8;
  undefined1 auStack_1d4 [4];
  undefined1 auStack_1d0 [4];
  undefined1 auStack_1cc [4];
  undefined1 auStack_1c8 [4];
  undefined1 auStack_1c4 [4];
  undefined1 auStack_1c0 [4];
  undefined1 auStack_1bc [4];
  undefined1 auStack_1b8 [4];
  undefined1 auStack_1b4 [4];
  undefined1 auStack_1b0 [4];
  undefined1 auStack_1ac [4];
  undefined1 auStack_1a8 [4];
  undefined1 auStack_1a4 [4];
  undefined1 auStack_1a0 [4];
  undefined1 auStack_19c [8];
  undefined1 auStack_194 [316];
  undefined1 auStack_58 [56];
  undefined1 auStack_20 [32];
  
  iStack_310 = 0;
  iStack_30c = 0;
  iStack_304 = 0;
  iStack_308 = 0;
  func_0x10302d06();
  uVar1 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),param_2,&UNK_107c1ad8,0x30,auStack_24c,
                          auStack_28c,0x1e,auStack_20,auStack_294,auStack_29c,auStack_2a4,
                          &uStack_2f4,auStack_21c,auStack_214,auStack_2ac,auStack_2e4,&uStack_300,
                          auStack_2ec,auStack_284,auStack_278,auStack_2b4,auStack_2bc,auStack_210,
                          auStack_2c4,auStack_2cc,auStack_208,auStack_204,auStack_200,auStack_1fc,
                          auStack_1f8,auStack_1f4,auStack_2d4,auStack_2d8,auStack_288,auStack_2a8,
                          auStack_26c,auStack_2b0,auStack_290,auStack_2b8,auStack_2dc,auStack_2c0,
                          auStack_298,auStack_2c8,auStack_270,auStack_2d0,auStack_2a0,auStack_27c,
                          auStack_1d4,auStack_1d0,auStack_1cc,auStack_1c8,auStack_1c4,auStack_1c0,
                          auStack_1bc,auStack_1b8,auStack_1b4,auStack_1b0,auStack_1ac,auStack_1a8,
                          auStack_1a4,auStack_1a0,auStack_19c,auStack_194,auStack_2fc,&iStack_310);
  iVar4 = 0;
  if (0 < iStack_310) {
    uVar1 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),uVar1,&UNK_107bde9c,&iStack_30c);
    if (0 < iStack_30c) {
      iStack_310 = (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)
                             (iStack_30c,&UNK_107c1ab8);
      uVar1 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),uVar1,&UNK_107c1034,unaff_EBX,
                              iStack_310);
    }
    iStack_304 = (**(code **)**(undefined4 **)_GMalloc__3PAVFMalloc__A_exref)
                           (iStack_310 << 4,&UNK_107c1a90);
    iVar3 = 0;
    iVar4 = iStack_308;
    if (0 < iStack_310) {
      iVar5 = iStack_304 + 8;
      do {
        uVar1 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),uVar1,&UNK_107becec,iVar5 + -8,
                                iVar5 + -4,iVar5,iVar5 + 4);
        iVar3 = iVar3 + 1;
        iVar5 = iVar5 + 0x10;
        iVar4 = iStack_308;
      } while (iVar3 < iStack_310);
    }
  }
  uVar1 = func_0x10305079(*(undefined4 *)(param_1 + 0x48),uVar1,&UNK_107bde9c,auStack_58);
  func_0x10305079(*(undefined4 *)(param_1 + 0x48),uVar1,&UNK_107becec,auStack_2e0,auStack_2e8,
                  auStack_2f0,auStack_2f8);
  uStack_1d8 = 0;
  uStack_1ec = func_0x10740cb4();
  uStack_1e4 = func_0x10740cb4();
  uStack_218 = uStack_2f4;
  uStack_260 = 0;
  iVar3 = **(int **)(_DAT_109d5e68 + 0x54);
  uVar1 = func_0x10740cb4(iStack_30c,iVar4,iStack_310,iStack_304);
  uVar1 = func_0x10740cb4(uVar1);
  uVar1 = func_0x10740cb4(uVar1);
  (**(code **)(iVar3 + 0x250))(uVar1);
  if (iVar4 != 0) {
    (**(code **)(**(int **)_GMalloc__3PAVFMalloc__A_exref + 8))(iVar4);
  }
  _Logf_FOutputDevice__QAAXPBGZZ
            (*(undefined4 *)_GNetworkLog__3PAVFOutputDevice__A_exref,&UNK_107c1a40);
  (**(code **)(*__GL2Console__3PAVUL2ConsoleWnd__A + 0x2c0))
            (__GL2Console__3PAVUL2ConsoleWnd__A,2,&UNK_107c1a40);
  (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x5a8))(unaff_EBP);
  uVar2 = (**(code **)(**(int **)(_DAT_109d5e68 + 0x54) + 0x61c))
                    (uStack_300,iStack_308,iStack_310,unaff_EBP,1);
  return uVar2 & 0xffffff00;
}

