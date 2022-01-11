#include <stdio.h>

int main() {
    int x=1;
    while(x<=50000){
        printf("%d ",&x);
    }
}

void calc(int *n) {
    *n *= 2;
}