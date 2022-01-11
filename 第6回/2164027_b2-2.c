#include <stdio.h>

void go(),exec();

int main() {
    //面倒なので、1回で5回試行をできるようにする
    for (int i = 0; i < 5; ++i) {
        exec();
    }
}

void go(int t) {
    int out = 0;
    for (; t < 31;) {
        //tが30になるまで実行
        out += t++;
        //outに足すと同時にtに1を加える
    }
    printf("%d\n", out);
}

//下の関数は前問からの引用
void exec() {
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
    go(t);
}