#include <stdio.h>

int go_repetitive(int i);

int go_repetitive1(int i);

int go(int i);

int main() {
    for (int i = 5; i < 11; ++i) {
        printf("%d\n", go(i));
        printf("%d\n", go_repetitive(i));
        printf("%d\n", go_repetitive1(i));
    }
}

int go(int i) {
    int sum = 0;
    while (i > 0) {
        sum += i--;
    }
    return sum;
}

int go_repetitive(int i) {
    if (i > 1) return i + go_repetitive(i-1);
    return 1;
}

int go_repetitive1(int i) {
    if (!(i & 0x80000000)) {
        return i + go_repetitive(i-1);
    }
    return 0;
}