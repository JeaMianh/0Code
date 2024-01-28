#include <stdio.h>
#include <math.h>

int main() {
    double deltaA, deltaB, num_1, num_2;
    double Delta;
    scanf("%lf %lf",&num_1, &num_2);
    deltaA = num_1*1.14/sqrt(5);
    deltaB = num_2/sqrt(3);
    Delta = sqrt(deltaA * deltaA + deltaB * deltaB); 
    printf("%.5f",Delta);
    return 0;
}