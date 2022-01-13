#include <stdio.h>

int main() {
    FILE *fp;
    //stores temp data from fp
    char str[256];
    //specify the target file by its relative path
    fp = fopen("../data.txt", "r");
    //read data.txt line by line
    while (fgets(str, 256, fp) != NULL) {
        //if first the head character of a line is 'a'
        if (str[0] == 'a'){
            //print the character
            puts(str);
        }
    }
    //close resource
    fclose(fp);
}