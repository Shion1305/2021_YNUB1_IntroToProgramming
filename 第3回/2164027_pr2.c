#include<stdio.h>

int main() {
    int a = 2, b = 1, c = 4;
    if (a + b >= c || a * 2 < c)printf("%s", " 条件を満たしています \r\n");
    printf("%s", " case1 \r\n");
    a = 3, b = 4, c = 3;
    if (a + b >= c || a * 2 < c)printf("%s", " 条件を満たしています \r\n");
    printf("%s", " case2 \r\n");
    a = -1, b = 1, c = 3;
    if (a + b >= c || a * 2 < c)printf("%s", " 条件を満たしています \r\n");
    printf("%s", " case3 \r\n");
    a = 1, b = 3, c = 4;
    if (a + b >= c || a * 2 < c)printf("%s", " 条件を満たしています \r\n");
    printf("%s", " case4 \r\n");
    a = -1, b = -20, c = -5;
    if (a + b >= c || a * 2 < c)printf("%s", " 条件を満たしています \r\n");
}