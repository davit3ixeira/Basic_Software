#include <stdio.h>

int add (int a, int b, int c);
int fat (int n);
void foo (int a[], int n);

int main (void) {
    printf("%d\n", add(1,2,3));
    printf("%d\n", fat(5));
    int v[] = {1, 3, 0, 4, 5, 0, 1, 0, 0, 8}; 
    foo(v, 10);
    for(int i = 0; i < 8; i++){
        printf("%d\n", v[i]);       
    }
    return 0;
}