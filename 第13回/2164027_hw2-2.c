#include <stdio.h>

int main() {
    FILE *fp;
    int c, counter = 0;
    fp = fopen("../Coll_of_ES.txt", "r");
    printf("Coll_of_ES.txt :\n");
    while ((c = getc(fp)) != EOF) {
        putchar(c);
    }
    fclose(fp);
    return 0;
}