
void packet_10086ee0(void)

{
  int extraout_ECX;
  
  func_0x10086e70();
  if ((*(byte *)(extraout_ECX + 300) & 1) != 0) {
    *(undefined4 *)(*(int *)(extraout_ECX + 0xe8) + 0x298) = 1;
    *(undefined4 *)(*(int *)(extraout_ECX + 0x114) + 0x298) = 1;
  }
  if ((*(byte *)(extraout_ECX + 300) & 2) != 0) {
    *(undefined4 *)(*(int *)(extraout_ECX + 0xec) + 0x298) = 1;
    *(undefined4 *)(*(int *)(extraout_ECX + 0x114) + 0x298) = 1;
  }
  if ((*(byte *)(extraout_ECX + 300) & 4) != 0) {
    *(undefined4 *)(*(int *)(extraout_ECX + 0xf0) + 0x298) = 1;
    *(undefined4 *)(*(int *)(extraout_ECX + 0x114) + 0x298) = 1;
  }
  if ((*(byte *)(extraout_ECX + 300) & 8) != 0) {
    *(undefined4 *)(*(int *)(extraout_ECX + 0xf4) + 0x298) = 1;
    *(undefined4 *)(*(int *)(extraout_ECX + 0x114) + 0x298) = 1;
  }
  if ((*(byte *)(extraout_ECX + 0x12d) & 4) != 0) {
    *(undefined4 *)(*(int *)(extraout_ECX + 0xf8) + 0x298) = 1;
    *(undefined4 *)(*(int *)(extraout_ECX + 0x114) + 0x298) = 1;
  }
  if ((*(byte *)(extraout_ECX + 300) & 0x10) != 0) {
    *(undefined4 *)(*(int *)(extraout_ECX + 0xfc) + 0x298) = 1;
    *(undefined4 *)(*(int *)(extraout_ECX + 0x118) + 0x298) = 1;
  }
  if ((*(byte *)(extraout_ECX + 300) & 0x20) != 0) {
    *(undefined4 *)(*(int *)(extraout_ECX + 0x100) + 0x298) = 1;
    *(undefined4 *)(*(int *)(extraout_ECX + 0x118) + 0x298) = 1;
  }
  if ((*(byte *)(extraout_ECX + 300) & 0x40) != 0) {
    *(undefined4 *)(*(int *)(extraout_ECX + 0x104) + 0x298) = 1;
    *(undefined4 *)(*(int *)(extraout_ECX + 0x118) + 0x298) = 1;
  }
  if (*(char *)(extraout_ECX + 300) < '\0') {
    *(undefined4 *)(*(int *)(extraout_ECX + 0x108) + 0x298) = 1;
    *(undefined4 *)(*(int *)(extraout_ECX + 0x11c) + 0x298) = 1;
  }
  if ((*(byte *)(extraout_ECX + 0x12d) & 1) != 0) {
    *(undefined4 *)(*(int *)(extraout_ECX + 0x10c) + 0x298) = 1;
    *(undefined4 *)(*(int *)(extraout_ECX + 0x11c) + 0x298) = 1;
  }
  if ((*(byte *)(extraout_ECX + 0x12d) & 2) != 0) {
    *(undefined4 *)(*(int *)(extraout_ECX + 0x110) + 0x298) = 1;
    *(undefined4 *)(*(int *)(extraout_ECX + 0x11c) + 0x298) = 1;
  }
  return;
}

