#include <stdio.h>
#include<string.h>

//本当はこのような宣言方法は好きではないが要件に含まれているので...
const double S = 4.3, A = 4.0, B = 3.0, C = 2.0, D = 1.0, E = 0;
//以下のように工夫した
double GP[6] = {S, A, B, C, D, E};
char GPName[][6] = {"A+", "A", "B", "C", "D", "E"};

int main() {
    double rGPA = 0;
    //いちいち変数を定義するのが大変めんどく感じたので以下で失礼する。
    int numUnit[6] = {10, 10, 8, 7, 0, 4}, tUnit = 0;
    printf("京都大学での GPA の算出\n");
    for (int i = 0; i < 6; i++) {
        //もしGPNameが空欄である場合にはスキップする
        if (strlen(GPName[i]) == 0) continue;
        printf("%s の単位数: %d\n", GPName[i], numUnit[i]);
    }
    for (int i = 0; i < 6; i++) {
        //GPの合計と単位の合計を求める
        rGPA += GP[i] * numUnit[i];
        tUnit += numUnit[i];
    }
    //結果を出力。
    printf("GPA = %f", rGPA /= tUnit);
    return 0;
}

