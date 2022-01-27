#include <stdio.h>
#include <stdlib.h>

int main(int args, char *fileN[]) {
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
        //temporary stores a character read from source
        char tmp;
        //indicates number of continuous spaces from last \n output
        int sp = 0;
        while ((tmp = fgetc(fp)) != -1) {
            if (tmp == '\n') {
                //skip as it is a line with only \n
                if (b)continue;
                //handle state of @b
                b = 1;
                //reset @b to ignore invalid output
                sp = 0;
            } else if (tmp == ' ' && b) {
                //store output because its validity is not determined
                sp++;
                continue;
            } else {
                for (int j = 0; j < sp; ++j) {
                    printf("%c", ' ');
                }
                sp = 0;
                b = 0;
            }
            //print the target
            printf("%c", tmp);
        }
        if (!b)printf("%c", '\n');
        fclose(fp);
    }
    return 0;
}