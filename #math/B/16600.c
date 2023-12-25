#include <stdio.h>
#include <math.h>

int main() {
    double input; scanf("%lf", &input);
    double edge = sqrt(input);
    printf("%.8lf\n", 4*edge);
    return 0;
}