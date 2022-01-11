#include <stdio.h>

void go();

int main() {
    go();
}

void go() {
    int t;
    printf("input the number... :");
    scanf("%d", &t);
    switch (t) {
        case 1:
        case 2:
            printf("%d です\n", t);
            break;
        default:
            printf("1 でも 2 でもありません\n");
    }
}
