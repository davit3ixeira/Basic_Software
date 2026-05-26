#include <stdio.h>

float foo(double a, float b);

int main() {
    double a = 5.0;
    float b = 3.0f;
    float res = foo(a, b);
    printf("foo(%f, %f) = %f\n", a, b, res);
    return 0;
}