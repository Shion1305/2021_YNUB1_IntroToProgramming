#include <stdio.h>
#include <stdlib.h>


/**
 * @param args number of arguments
 * @param fileN content of arguments
 * an example of arguments are as following
 * ../data1.txt ../data2.txt
 */
int main(int args, char *fileN[]) {
    //temporary stores a character read from source
    char tmp;
    /**
     * @b
     * 1    previous output is \n
     * 0    previous output is not \n
     */
    int b = 1;
    //reads all the files stated in arguments
    for (int i = 1; i < args; ++i) {
        FILE *fp = fopen(fileN[i], "r");
        //loop until all data is loaded
        while ((tmp = fgetc(fp)) != -1) {
            if (tmp == '\n') {
                //skip because it is a line with only \n
                if (b)continue;
                //handle state of b
                b = 1;
            } else b = 0;
            //print the target
            printf("%c", tmp);
        }
        fclose(fp);
        if (!b)printf("%c", '\n');
    }
    return 0;
}