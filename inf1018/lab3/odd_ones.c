#include <stdio.h>

int odd_ones(unsigned int x) {
  int c = 0;

  while (x) {
      c += x & 1;
      x >>= 1;
  }

  return c & 1;
}

int main(){

  printf("%x tem numero %s de bits\n",0x01010101,odd_ones(0x01010101) ? "impar":"par");
  printf("%x tem numero %s de bits\n",0x01030101,odd_ones(0x01030101) ? "impar":"par");
  
  return 0;
}