#include <stdio.h>

int main()
{
    //printf("echo\n");
    long fix, var, price;
    // sum = fix + var*N
    scanf("%ld %ld %ld", &fix, &var, &price);
    long N=1;
    long sum, pay=price-var;
    if(var>=price) {
        printf("-1\n");
        return 0;
    } else {
        N = fix/(price-var)+1;
        printf("%ld\n", N);
    }
    return 0;
}