#include <stdio.h>

void dump(void *p, int n) {
    unsigned char *p1 = (unsigned char *)p;
    while (n--) {
        printf("%p - %02x\n", p1, *p1);
        p1++;
    }
}

struct X1 {
  char c1;
  int i;
  char c2;
};

struct X2 {
  long l;
  char c;
};

struct X3 {
  int i;
  char c1;
  char c2;
};

struct X4 {
  struct X2 x;
  char c;
};

struct X5 {
  char c1;
  char c2;
  char c3;
};

struct X6 {
  short s1;
  int i;
  char c[3];
  short s2;
};

union U1 {
  int i;
  char c[5];
};

union U2 {
  short s;
  char c[5];
};

int main() {

    struct X1 x1 = {0xa1, 0xb1b2b3b4, 0xc1};
    struct X2 x2 = {0xa1a2a3a4a5a6a7a8, 0xb1};
    struct X3 x3 = {0xa1a2a3a4, 0xb1, 0xc1};
    struct X4 x4 = {{0xa1a2a3a4a5a6a7a8, 0xb1}, 0xc1};
    struct X5 x5 = {0xa1, 0xb1, 0xc1};
    struct X6 x6 = {0xa1a2, 0xb1b2b3b4, {0xc1,0xc2,0xc3}, 0xd1d2};

    union U1 u1;
    union U2 u2;

    u1.i = 0xa1a2a3a4;
    u2.s = 0xb1b2;

    printf("X1 (%lu bytes)\n", sizeof(x1));
    dump(&x1, sizeof(x1));

    printf("\nX2 (%lu bytes)\n", sizeof(x2));
    dump(&x2, sizeof(x2));

    printf("\nX3 (%lu bytes)\n", sizeof(x3));
    dump(&x3, sizeof(x3));

    printf("\nX4 (%lu bytes)\n", sizeof(x4));
    dump(&x4, sizeof(x4));

    printf("\nX5 (%lu bytes)\n", sizeof(x5));
    dump(&x5, sizeof(x5));

    printf("\nX6 (%lu bytes)\n", sizeof(x6));
    dump(&x6, sizeof(x6));

    printf("\nU1 (%lu bytes)\n", sizeof(u1));
    dump(&u1, sizeof(u1));

    printf("\nU2 (%lu bytes)\n", sizeof(u2));
    dump(&u2, sizeof(u2));

    return 0;
}