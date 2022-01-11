#include <stdio.h>

int main() {
    int d[8][8];
    int x=33;
    //initialization
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            d[i][j]=x++;
        }
    }
    for (int i = 0; i < 8; ++i) {
        //print the head part
        for (int j = 0; j < 8; ++j) {
            printf("%p ",&d[i][j]);
        }
        printf("\n");
        for (int j = 0; j < 8; ++j) {
            printf("%10d : %c ",d[i][j],d[i][j]);
        }
        printf("\n");
    }
}