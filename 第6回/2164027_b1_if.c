#include <stdio.h>

void go(int t);

int main() {
    for (int i = 0; i < 4; ++i) {
        go();
    }
}

void go() {
    int t;
    printf("input the number... :");
    scanf("%d", &t);
    if (t == 1 || t == 2) {
        printf("%d です\n", t);
    } else {
        printf("1 でも 2 でもありません\n");
    }
}
