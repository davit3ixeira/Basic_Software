#include <ctype.h>
#include <stdio.h>

int string2num (char *s, int b) {
  int a = 0;
  for (; *s; s++){
    if(isdigit(*s)){
      a = a*b + (*s - '0');
    }
    else{
      a = a*b + (*s - 'A');
    }
  }
  return a;
}

int main (void) {
  /*
  printf("==> %d\n", string2num("1234"));
  printf("==> %d\n", string2num("1234") + 1);
  printf("==> %d\n", string2num("1234") + string2num("1"));
  */
  printf("%d\n", string2num("777", 8));
  printf("%d\n", string2num("777", 10));
  printf("%d\n", string2num("1A", 16));
  printf("%d\n", string2num("A09B", 16));
  return 0;
}