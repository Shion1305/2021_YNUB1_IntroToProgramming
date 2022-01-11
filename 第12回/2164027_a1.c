#include <stdio.h>

#define n 231
//This is level up version of the answer.

int main() {
    //NO NEED SWITCHING IN THIS ANSWER.
    int out[] = {1, 1, 2, 3, 5, 8, 13};
    for (int i = 0; i < n; ++i) {
        //CHANGE OUTPUT BY SELECTING NUM IN ARRAY out[] BY SURPLUS OF i
        printf("%d ", out[i % 7]);
    }
}
