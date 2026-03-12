#include <stdio.h>

unsigned char switch_byte(unsigned char x) {
  a = (x << 4) | (x >> 4);
  return a;
}

int main(){

  printf("%02x\n", switch_byte(0xAB));

  return 0;
}