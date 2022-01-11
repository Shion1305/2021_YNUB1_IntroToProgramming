#include <stdio.h>

int main() {
    int x;
    scanf("%d",&x);
    while(x<2){
        printf("IllegalInputError thrown. Try again.\n");
    }
    for (int i = 1; i <= x / 2; ++i) {
        if(!(x%i)){
            printf("%d ",i);
        }
    }
}