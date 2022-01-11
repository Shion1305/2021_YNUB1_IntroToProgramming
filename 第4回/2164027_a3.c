#include <stdio.h>


int go(int target);

int main() {
    int target=2096;
    if (go(target)) {
        printf("うるう年です。");
        return 0;
    }
    printf("うるう年ではありません。");
    return 0;
}

int go(int target) {
    //4の倍数かつ、100の倍数で無いまたは400の倍数である時のみtrueを返す。
    if (target % 4 == 0 && (target % 100 != 0 || target % 400 == 0)) {
        return 1;
    }
    return 0;
}