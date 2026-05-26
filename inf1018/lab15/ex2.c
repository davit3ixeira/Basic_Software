#include <stdio.h>
#include <math.h>

float foo1(float a, float b);

int main() {
    float a = M_PI_2;
    float b = 2.5f;
    float res = foo1(a, b);
    printf("foo1(PI/2, %f) = %f\n", b, res);
    return 0;
}