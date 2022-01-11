#include <stdio.h>


int call_me(int count);

int main() {
    int c, n;
    do {
        printf("Call me!! (Press 1 to accept, 0 to reject.)\n");
        scanf("%d", &c);
        if (c == 1) {
            n = call_me(n);
        }
    } while (c != 0);
    printf("You've made %d call", n);
    printf((n == 1 ? "" : "s"));
    printf(" in total!!\n");
    return 0;
}

int call_me(int count) {
    printf("Thank! Your call was %d", ++count);
    //CHANGE ACTION DEPENDING ON VARIABLE "count"
    switch (count) {
        case 1:
            printf("st");
            break;
        case 2:
            printf("nd");
            break;
        case 3:
            printf("rd");
            break;
        default:
            printf("th");
    }
    printf(" time.\n");
    return count;
}