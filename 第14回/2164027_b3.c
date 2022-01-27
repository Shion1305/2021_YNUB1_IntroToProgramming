#include <stdio.h>

#define file "../data3.txt"

int main() {
    int dSize;
    //prepare file channel for the operation
    FILE *fp = fopen(file, "w");
    //acquire and repeat size of data
    scanf("%d", &dSize);
    printf("人数: %d\n", dSize);
    fprintf(fp, "%d\n", dSize);
    for (int i = 0; i < dSize; ++i) {
        char name[256];
        int score;
        printf("No.%d\n", i + 1);
        printf("  名前:");
        //acquire name data
        scanf("%s", name);
        printf("  点数:");
        //acquire score data
        scanf("%d", &score);
        //print the data to file channel
        fprintf(fp, "%s %d\n", name, score);
    }
    //show the ending message
    printf("Your information has been recorded to %s", file);
}