#include <stdio.h>
#include <math.h>

double foo2(float a, float b);

int main() {
    float a = M_PI_2;
    float b = M_PI;
    double res = foo2(a, b);
    printf("foo2(PI/2, PI) = %f\n", res);
    return 0;
}