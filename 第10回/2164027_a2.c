#include <stdio.h>

void swap(void **v, void **v1);

int main() {
    char a = '1', b = 'd';
    swap(&a, &b);
    printf("a: %c, b: %c", a, b);
}

void swap(void **v, void **v1) {
    void *x = *v1;
    *v1 = *v;
    *v = x;
}