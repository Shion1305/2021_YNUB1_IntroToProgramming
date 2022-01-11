#include <stdio.h>

long memory[2][60];
long max = 2;
//this variable is for faster calculating...

//the number of steps are counted with pointer c
long fibo(long n, long *c) {
    if (n == 1 || n == 2) {
        memory[1][n - 1] = 1;
        *c = 1;
        return 1;
        //returns 1 if n is 1 or 2 as its definition
    }
    if (n == max + 1) {
        max++;
        memory[0][n - 1] = fibo(n - 1, c) + fibo(n - 2, c);
        memory[1][n - 1] = memory[1][n - 2] + memory[1][n - 3] + 1;
    }
    *c = memory[1][n - 1];
    return memory[0][n - 1];
    //retrieve the value from previous result
    //returns the value of fibonacci number
}

int main() {
    printf(" n   FIBONACCI NUMBER        TOTAL STEPS\n");
    for (long i = 1; i < 70; ++i) {
        long c = 0;
        // c is for counting
        long x = fibo(i, &c);
        printf("%2ld   %16ld   %16ld\n", i, x, c);
    }
}