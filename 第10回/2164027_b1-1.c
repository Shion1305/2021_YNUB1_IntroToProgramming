#include <stdio.h>

int func(int n);

int main() {
    int a = 3;
    printf("a = %d, address = %p\n", a, &a);           /* (1) */
    printf("a * 3 = %d, address = %p\n", func(a), &a); /* (2) */
    printf("a * 3 = %d, address = %p\n", a * 3, &a);   /* (3) */
}

int func(int n) {
    int a = 1;
    printf("a * 3 = %d, address = %p\n", a * 3, &a);   /* (4) */
    printf("n * 3 = %d, address = %p\n", n * 3, &n);
    return n * 3;
}