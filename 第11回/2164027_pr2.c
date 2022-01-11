#include <stdio.h>

int main(void) {
    char str1[] = "abcdefghijklmn";
    char str2[] = "apx";
    char *cp1, *cp2;
    int found;

    cp2 = str2;
    while (*cp2 != '\0') {
        cp1 = str1;
        printf("%c : ", *cp2);
        found = 0;
        //variable to evaluate it is already found or not
        while (*cp1 != '\0' && !found) {
            //もう見つかっていた時は!foundでひっかからないようにする
            if (*cp1 == *cp2) {
                printf("found\n");
                found = 1;
                //普通ここはbreak使いたいでしょ...
                //空欄に無かったから避けたけれど
            }
            cp1++;
            //increment to move on
        }
        if (found == 0) {
            printf("not found\n");
            //in case the target character was not found
        }
        cp2++;
    }
    return 0;
}