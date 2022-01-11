#include <stdio.h>

void func(int *n1, int *n2, int *n3);

int main() {
    int x, y, z;
    for (int i = 1; i <= 100; ++i) {
        x = i;
        y = i;
        z = i;
        //use the pointer in the func
        func(&x, &y, &z);
        if (x && y && z) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void func(int *n1, int *n2, int *n3) {
    // calculate surplus of 2,3,5
    *n1 = *n1 % 2;
    *n2 = *n2 % 3;
    *n3 = *n3 % 5;
}