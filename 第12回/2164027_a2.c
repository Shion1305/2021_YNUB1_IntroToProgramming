#include <stdio.h>
#include <math.h>

typedef struct {
    int x, y, z;
} point;

//define struct point

double d(point p1, point p2);

int main() {
    point p1 = {2, 2, 2};
    point p2 = {0, 0, 0};
    //supposed to be 3.46
    printf("%f", d(p1, p2));
}

double d(point p1, point p2) {
    //calc difference of each coord param, power by 2, and sqrt the total
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}