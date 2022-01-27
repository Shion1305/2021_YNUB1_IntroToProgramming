#include <stdio.h>


#define file "../data3.txt"

typedef struct {
    char name[400];
    int score;
} person;

int main() {
    int dSize;
    //prepare file channel for the operation
    FILE *fp = fopen(file, "r");
    //acquire and repeat size of data
    fscanf(fp, "%d", &dSize);
    printf("人数: %d\n", dSize);
    fprintf(fp, "%d", dSize);
    person data[dSize];
    /**
     * Although defining struct is not a requirement,
     * this code stores the data as struct since
     * it is better when it comes to extend this code.
     */

    for (int i = 0; i < dSize; ++i) {
        fscanf(fp, "%s %d", &data[i].name, &data[i].score);
        //print each data in an appropriate format
        printf("No.%d\n", i + 1);
        printf("  名前；%s\n", data[i].name);
        printf("  点数：%d\n", data[i].score);
    }
    //show the ending message
    printf("Your information has been recorded to %s", file);
}