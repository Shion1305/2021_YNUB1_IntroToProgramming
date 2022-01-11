#include <stdio.h>

void calc(int *n);

int main() {
    int x=1;
    //don't loop when x is over 50000
    while(x<=50000){
        printf("%d   ",x);
        calc(&x);
    }
}

//This function doubles the variable corresponds to address n;
void calc(int *n) {
    *n *= 2;
}