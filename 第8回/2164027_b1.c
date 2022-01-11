#include<stdio.h>
void customPrint(char c, int x);
int main(){
    char in;
    int chNum;
    //collect input info
    printf("input character...");
    scanf("%c",&in);
    printf("number of char...");
    scanf("%d",&chNum);
    for (int i = 1; i <= chNum; ++i) {
        printf("%d",i%10);
    }
    //print 5 lines..
    for (int i = 0; i < 5; ++i) {
        customPrint(in,chNum);
    }
}
void customPrint(char c, int x){
    printf("\n");
    //recursively print the target char c for x times
    for (int i = 0; i < x; ++i) {
        printf("%c", c);
    }
}