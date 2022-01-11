#include <stdio.h>

int main() {
    char str1[] = "Shion";
    char str2[] = "Ichikawa";
    char str3[sizeof(str1) + sizeof(str2)];
    //generate necessary size of str3
    for (int i = 0; i < sizeof(str1) - 1; i++) {
        str3[i] = str1[i];
        //copy str1 to str3
    }
    str3[sizeof(str1) - 1] = ' ';
    for (int i = 0; i < sizeof(str2); i++) {
        str3[sizeof(str1) + i] = str2[i];
        //copy str2 to str3
    }
    //print all
    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s\n", str3);
}