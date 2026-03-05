#include <stdio.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %d\n", p1, *p1);
    p1++;
  }
}

int main (void) {
  int i = 9999;
  long i1 = 9999;
  short i2 = 9999;
  char i3 = 'a';
  char p[] = "A \n$";
  dump(p, sizeof(p));
  printf("\n");
  dump(&i, sizeof(i));
  printf("\n");
  dump(&i, sizeof(i1));
  printf("\n");
  dump(&i, sizeof(i2));
  printf("\n");
  dump(&i, sizeof(i3));
  return 0;
}
