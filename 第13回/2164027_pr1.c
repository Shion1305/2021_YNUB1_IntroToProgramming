#include <stdio.h>

int main() {
    FILE *fp;
    int c;
    //specifying the file by its relative path:../file.txt
    //set mode as read
    fp = fopen("..\\file.txt", "r");
    //read until encountering EOF
    while ((c = fgetc(fp)) != EOF) {
//        printf("%c", c); also works
        putchar(c);
    }
    //release resource
    fclose(fp);
}