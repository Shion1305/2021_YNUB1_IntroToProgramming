#include<stdio.h>

int pow1(int x, int y);

int main() {
    int a, b;
    //ask for inputs
    printf("Input a,b in format aᵇ\n");
    printf("input a...");
    scanf("%d", &a);
    printf("input b...");
    scanf("%d", &b);
    printf("%d", pow1(a, b));
}

int pow1(int x, int y) {
    //reject unexpected input
    if (y < 0) {
        printf("ILLEGAL INPUT EXCEPTION");
        return 0;
    }
    if (y == 0) return 1;
    //calculate recursively
    return x * pow1(x, y - 1);
}