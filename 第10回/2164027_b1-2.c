#include <stdio.h>

void func(int *n);

int main() {
    int a = 3;
    int *x = &a;
    printf("    a = %d, address = %p\n", a, &a);           /* (1) */
    func(x);
    printf("    a = %d, address = %p\n", a, &a);           /* duplicated from (1) */
    printf("a * 3 = %d, address = %p\n", a * 3, &a);   /* (3) */
}

void func(int *n) {
    int a = 1;
    printf("a * 3 = %d, address = %p\n", a * 3, &a);   /* (4) */
    *n *= 3;
    printf("a * 3 = %d, address = %p\n", *n, n);
}