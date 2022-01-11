#include <stdio.h>

void go();

int main() {
    //面倒なので、1回で5回試行をできるようにする
    for (int i = 0; i < 5; ++i) {
        go();
    }
}

void go() {
    int t;
    printf("input the number... :");
    scanf("%d", &t);
    if (!(t % 2)) {
        printf("2の倍数です");
    }
    if (!(t % 3)) {
        printf("3の倍数です");
    }
    //2の倍数でも3の倍数でもなければ...
    if (t % 3 && t % 2){
        printf(" 2 の倍数でも 3 の倍数でもありません");
    }
    //\nは一番最後にprintしておけば条件分岐する必要が無いので楽。
    printf("\n");
}