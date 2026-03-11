#include <stdio.h>

int odd_ones(unsigned int x) {
  unsigned char *p;
  p = &x;
  int a = 0;

  for(; *p; p++){
    if(*p == 1){
        a++;
    }
  }

  return a - (a/2)*2;
}

int main() {
  printf("%x tem numero %s de bits\n",0x01010101,odd_ones(0x01010101) ? "impar":"par");
  printf("%x tem numero %s de bits\n",0x01030101,odd_ones(0x01030101) ? "impar":"par");
  return 0;
}