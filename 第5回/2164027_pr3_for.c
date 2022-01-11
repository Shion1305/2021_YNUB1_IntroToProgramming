#include <stdio.h>

int main() {
    int i = 0, i1 = 100, a = 0;
    while (i++ < i1) {
        //先に判定処理をしてから足す。
        a += i;
    }
    printf("%d", a);

    int r = 0;
    for (int j = 0; j++ < 100;) {
        //これも先に判定処理をしてから足す。
        r += j;
    }
    printf("%d", r);

    int r1 = 0, k = 0;
    do {
        r1 += ++k;
    } while (k < 100);
    //k=100となって足された後、!k<100となって終了する。
    printf("%d", r1);
}