#include <stdio.h>

struct X {
  int a;
  short b;
  int c;
};

void dump(struct X* p, int n) {
  unsigned char *p1 = (unsigned char*) p;

  while (n--) {
    printf("%p - %d\n", p1, *p1);
    p1++;
  }
}

int main(void) {
  struct X x;

  x.a = 1313;
  x.b = 193;
  x.c = 1310;

  dump(&x, sizeof(x));

  return 0;
}