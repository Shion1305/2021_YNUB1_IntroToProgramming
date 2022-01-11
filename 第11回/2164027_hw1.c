#include <stdio.h>

int main(void) {
    int data[16][16];
    for (int i = 1; i <= 16; ++i) {
        for (int j = 1; j <= 16; ++j) {
            data[i - 1][j - 1] = i * j;
            //配列に数値を代入する
        }
    }
    //一応配列にいれる処理と表示する処理は分離してコードを書いた
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            printf("%3d ", data[i][j]);
            //3文字に補正してデータを出力
        }
        printf("\n");
        //必要に応じて改行する
    }
}