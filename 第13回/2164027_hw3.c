#include <stdio.h>

int main() {
    FILE *fp, *fp1;
    int c, counter = 0;
    fp = fopen("../Coll_of_ES.txt", "r");
    //open stream to Coll_of_ES.txt for reading
    fp1 = fopen("../copy1.txt", "w");
    //open stream to ../copy1.txt for writing
    printf("Coll_of_ES.txt :\n");
    while ((c = getc(fp)) != EOF) {
        putc(c, fp1);
        //print char one by one to fp1
    }
    //release resources
    fclose(fp);
    fclose(fp1);
    return 0;
}