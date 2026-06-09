#include <stdio.h>

double foo(double a, int b);

struct X {
    int vi;
    double vd;
    struct X *next;
};
double pack(struct X *px);

struct X1 {
    int vi;
    float vf;
};
double pack1(struct X1 *px, int n);

int main(void) {
    double c = 32.4, d = -11.11111;
    int a = 3, b = -2;

    printf("ca = %lf\n", foo(c, a));
    printf("da = %lf\n", foo(d, a));
    printf("cb = %lf\n", foo(c, b));
    printf("db = %lf\n", foo(d, b));

    struct X n3 = {3, 2.0, NULL};
    struct X n2 = {2, 1.5, &n3};
    struct X n1 = {1, 1.0, &n2};
    printf("pack = %f\n", pack(&n1));

    struct X1 arr[] = {
        {1, 1.0f},
        {2, 1.5f},
        {3, 2.0f}
    };
    printf("pack1 = %f\n", pack1(arr, 3));

    return 0;
}