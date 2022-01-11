#include <stdio.h>

int main(void) {
    int data[10];
    int i, maxnum, max;
    for (i = 0; i < 10; i++) {
        printf("data[%d] = ", i);
        scanf("%d", &data[i]);
    }
    maxnum = 0;
    max = data[maxnum];
    for (int j = 0; j < 10; ++j) {
        if (data[j] >= max) {
            //update if the target value is equal or bigger than max value
            maxnum = j;
            max = data[maxnum];
            //update max value
        }
    }
    printf("Maxinum ==> data[%d]=%d\n", maxnum, data[maxnum]);
    return 0;
}