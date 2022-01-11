#include <stdio.h>
#include <math.h>

struct p {
    char name[30];
    int age;
    double height;
    double weight;
    double bmi;
};
typedef struct p person;
//typedefを使ってめんどい表記を楽にする
int kuap(person *d);

int main(void) {
    //初期化する
    person data = {"Taro", 19, 1.65, 55.5};
    kuap(&data);
    //それぞれを出力する。
    printf("Name = %s\n", data.name);
    printf("Age = %d\n", data.age);
    printf("BMI = %f\n", data.bmi);
}

int kuap(person *d) {
    //ポインタで構造体の受け渡しを行う。
    d->bmi = d->weight / pow(d->height, 2);
    //アロー演算子を使って中身を書き換える。
}