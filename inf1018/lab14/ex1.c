#include <stdio.h>

typedef union {
    float f;
    unsigned int i;
} U;

#define makefloat(s,e,f) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))
#define getsig(x)  ((x)>>31 & 1)
#define getexp(x)  ((x)>>23 & 0xff)
#define getfrac(x) ((x) & 0x7fffff)

float float2(float f) {
    U u;
    u.f = f;
    unsigned int s    = getsig(u.i);
    unsigned int e    = getexp(u.i);
    unsigned int frac = getfrac(u.i);

    if (e == 0xff)
        return f;

    if (e == 0) {
        frac <<= 1;
        if (frac & 0x800000) {
            e = 1;
            frac &= 0x7fffff;
        }
    } else {
        if (++e >= 0xff) {
            e    = 0xff;
            frac = 0;
        }
    }

    u.i = makefloat(s, e, frac);
    return u.f;
}

int main(){
    float casos[] = {0.0f, -0.0f, 1.0f, -1.0f, 0.5f, 3.14f,
                      1e38f, -1e38f, 1e-45f};
    int n = sizeof(casos) / sizeof(casos[0]);

    printf("%-15s  %-15s  %-15s\n");
    for (int k = 0; k < n; k++) {
        float x = casos[k];
        printf("%-15g  %-15g  %-15g\n", x, float2(x), x * 2.0f);
    }

    return 0;
}