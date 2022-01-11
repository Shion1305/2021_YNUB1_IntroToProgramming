#include<stdio.h>

int go(int a, int b);

int main() {
    int a = 3, b = 4;
    printf("%d\n", go(a, b));

    printf("%d\n", go(-5, 2));
    printf("%d\n", go(1, 2));
    printf("%d\n", go(-5, 7));
}

int go(int a, int b) {
    return a * b > a + b ? a * b : a + b;
}