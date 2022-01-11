#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

double cal(double x, double y);

int main() {
    //In this program, I did not set radius as required parameter.
    //Pi does not vary basis on radius parameter...
    double x, y, leng, pi;
    int tries = 10000000, counts = 0;
    for (int i = 0; i < tries; ++i) {
        //x,y should be 0<x<1
        x = (double) rand() / RAND_MAX;
        y = (double) rand() / RAND_MAX;
        leng = cal(x, y);
        if (leng <= 1.0) {
            ++counts;
        }
    }
    //calculate PI based on the result
    pi = (double) counts * 4 / tries;
    printf("π = %f", pi);
    return 0;
}

double cal(double x, double y) {
    //this is the program from b2
    return sqrt(pow(x, 2) + pow(y, 2));
}