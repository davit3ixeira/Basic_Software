#include <stdio.h>

typedef union {
    float f;
    unsigned int i;
} U;

#define makefloat(s,e,f) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))
#define getsig(x)  ((x)>>31 & 1)
#define getexp(x)  ((x)>>23 & 0xff)
#define getfrac(x) ((x) & 0x7fffff)

float int2float(int i) {
    U u;

    if (i == 0) {
        u.i = 0;
        return u.f;
    }

    unsigned int s = (i < 0) ? 1u : 0u;

    if (i == (int)0x80000000) {
        u.i = makefloat(1, 158, 0);
        return u.f;
    }

    unsigned int abs_val = s ? (unsigned int)(-i) : (unsigned int)i;

    int pos = 0;
    for (unsigned int tmp = abs_val; tmp > 1; tmp >>= 1)
        pos++;

    unsigned int e = (unsigned int)(pos + 127);

    unsigned int mantissa = abs_val ^ (1u << pos);

    unsigned int frac;
    if (pos <= 23)
        frac = mantissa << (23 - pos);
    else
        frac = mantissa >> (pos - 23);

    u.i = makefloat(s, e, frac & 0x7fffff);
    return u.f;
}

int main(){
    U u;
    int casos[] = {0, 1, -1, 2, -2, 127, -127, 255, 1000, -1000, 8388608, 16777216, 2147483647, 0x80000000};
    int n = sizeof(casos) / sizeof(casos[0]);

    printf("%-14s  %-10s  %-10s  %-10s\n");
    for (int k = 0; k < n; k++) {
        int v = casos[k];
        float conv = int2float(v);
        float ref = (float)v;

        u.f = conv;
        unsigned int bc = u.i;
        u.f = ref;
        unsigned int br = u.i;

        printf("%-14d  %08x    %08x    %s\n",
               v, bc, br, (bc == br) ? "OK" : "DIFERENTE*");
    }

    return 0;
}