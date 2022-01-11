#include <stdio.h>

int main()
{
    int i=1,n=100;
    while (i<=n){
        if(n%i==0)printf("%d ",i);
        //単純に、nがiで割り切れた時のみ出力する。
        i++;
    }
}