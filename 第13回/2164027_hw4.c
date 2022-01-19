#include <stdio.h>


//declare proper arguments
//argv[1] contains name of source file
//argv[2] contains name of dest. file
int main(int args, char *argv[]) {
    FILE *fp, *fp1;
    int c, counter = 0;
    fp = fopen(argv[1], "r");
    //open stream to Coll_of_ES.txt for reading
    fp1 = fopen(argv[2], "w");
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