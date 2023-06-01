#include <stdio.h>
#include <math.h>

double foo4(double* a, int n);

int main(void){
    double a[] ={M_PI_2, M_PI_2};
    printf("%f\n", foo4(a,2));
    return 0;
}