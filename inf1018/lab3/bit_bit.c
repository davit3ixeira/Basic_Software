#include <stdio.h>

int main(){
  unsigned int x = 0x87654321;
  unsigned int y, z;

  y = x & 0xFF;

  z = x | 0xFF000000;

  printf("%08x %08x\n", y, z);

  return 0;
}