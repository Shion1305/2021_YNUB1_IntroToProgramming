#include<stdio.h>
#include<math.h>

double distance(double x, double y);

int main() {
    double x, y;
    printf("Input target coords...\n");
    printf("x: ");
    scanf("%lf", &x);
    printf("y: ");
    scanf("%lf", &y);
    //ask for input x,y
    printf("INPUT CONFIRMED... (%f,%f)\n", x, y);
    printf("DISTANCE FROM ORIGIN TO TARGET IS... %lf", distance(x, y));
}

double distance(double x, double y) {
    //calculate distance by √(x^2+y^2)
    return sqrt(pow(x, 2) + pow(y, 2));
}