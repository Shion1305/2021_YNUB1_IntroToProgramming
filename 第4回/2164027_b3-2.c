#include <stdio.h>

int main() {
    //ここで一応変数を宣言(?)
    int i = 6;
    printf("100以下の整数で、6で割り切れるが、5の倍数でない数は\n");
    for (; i <= 100; i+=6) {
        //5で割り切れない場合のみ出力。
        printf(i%5!=0?"%d ":"",i);
    }
    printf("\nです");
}