#include <stdio.h>
#include <math.h>

double foo3(double *a, int n);

int main() {
    double array[] = {M_PI_2, M_PI_2, M_PI};
    int n = 3;
    double res = foo3(array, n);
    printf("foo3 result = %f\n", res);
    return 0;
}