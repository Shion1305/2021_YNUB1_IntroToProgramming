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
    while(1){
        //ループさせる
        printf("input the number... :");
        scanf("%d", &t);
        if(t<11&&t>0){
            break;
        }
        //1~10でなければExceptionを表示して再度入力を求む。
        printf("IllegalInputException\n");
    }
    printf("%d\n",t);
}