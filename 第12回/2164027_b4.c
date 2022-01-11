#include <stdio.h>


//define struct person
typedef struct {
    char name[50];
    float gpa;
} person;

//define d[5] as an array of person
person d[5];

int main() {
    int max = 0;
    for (int i = 0; i < 5; ++i) {
        printf("No. %d\n", i + 1);
        printf("family name = ");
        scanf("%s", d[i].name);
        printf("GPA ( [ 0.0 to 5.0 ] ) = ");
        scanf("%f", &d[i].gpa);
        if (i > 0) {
            //update if gpa bigger than it in max index is found
            if (d[max].gpa < d[i].gpa)max = i;
        }
    }
    //print the result
    printf("\n%s : %f", d[max].name, d[max].gpa);
}