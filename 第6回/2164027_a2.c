#include <stdio.h>


int sqrtFast(int *current, long *nL, long target);

int isPrime(int a);
int nextPrime(int x);
int sumDivisor(int x);

struct _primeData {
    int prime;
    int num;
};


int main() {
    printf("%d", sumDivisor(10));


//    int x, y;
//    printf("Input your 1st number...\n");
//    scanf("%d", &x);
//    while (x < 2) {
//        printf("IllegalInputError thrown. Try again.\n");
//    }
//    printf("Input your 1st number...\n");
//    scanf("%d", &y);
//    while (y < 2) {
//        printf("IllegalInputError thrown. Try again.\n");
//    }
//    //応用課題1を利用した内容は好きではないので、ここでは応用課題1の内容を無視して約数の総和を別のアルゴリズムによって求めます。
//    if(sumDivisor(x)-x== sumDivisor(y)-y){
//
//    }
}


//約数の合計を求めるプログラムである。
int sumDivisor(int x) {
    int size = 0;
    int prime[100000];
    int num[100000];
    int sum=1;


    int tmp = 2;
    while (x != 1) {
        if (x % tmp==0) {
            x /= tmp;
            if (size!=0&&tmp == prime[size - 1]) {
                num[size - 1]++;
            } else {
                //sizeを大きくするとともにprimeを記録する。
                prime[size++] = tmp;
                num[size] = 1;
            }
        } else {
            tmp= nextPrime(tmp);
        }
    }

    for (int i = 0; i < size; ++i) {
        int adder=1;
        for (int j = 0; j < num[i]; ++j) {
            adder*=prime[i];
        }
        sum+=adder;
    }
}

int nextPrime(int t) {
    if (t == 2)return 3;
    t += 2;
    //素数がでるまで2を足していく。
    while (!isPrime(t)) {
        t += 2;
    }
    return t;
}


//素数であるかどうかを判定する関数である。
int isPrime(int a) {
    int j;
    if (!(a % 2)) {
//        printf("素数ではありません\n");
        return 0;
    }
    int aS = 2;
    long nL = 9;
    while (sqrtFast(&aS, &nL, a)) {}
    if (a % 3 == 0) {
        //       printf("素数ではありません\n");
        return 0;
    }
    for (j = 7; j <= aS; j += 6) {
        if (a % j == 0 || a % (j + 4) == 0) {
            //printf("素数ではありません\n");
            return 0;
        }
    }
//    printf("素数です4_1\n");
    return 1;
}

int sqrtFast(int *current, long *nL, long target) {
    if (target > *nL) {
        ++*current;
        *nL += *current * 2;
        ++*nL;
        return 1;
    }
    return 0;
}


