#include <stdio.h>
int main(void) {
  unsigned int x = 0x87654321;
  unsigned int y, z;
  unsigned char *pz, *py;

  y = x;
  py = &y;
  py++;

  for(int i = 0; i < 3; i++){
    *py = 0;
    py++;
  }

  z = x;
  pz = &z;

  pz += 3;
  *pz = 0xFF;     

  printf("%08x %08x\n", y, z);
}