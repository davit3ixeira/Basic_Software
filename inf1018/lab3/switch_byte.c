#include <stdio.h>

unsigned char switch_byte(unsigned char x){
  unsigned char a, b;
  a = x/16;
  b = x%16;
  return b*16+a;
}

int main() {
  unsigned char a = switch_byte(0xAB);
  printf("%x\n", a);
  return 0;
}