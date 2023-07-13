#include <stdio.h>
/*
N이 1이상이므로 N이 1일때 min max둘다 같은값이다.
*/

int main()
{
    long N;
    scanf("%ld", &N);
    long X;
    long min;
    long max;
    scanf("%ld", &X);
    max = X;
    min = X;
    for (int i = 1; i < N; i++)
    {
        scanf("%ld", &X);
        if(X>max)
            max = X;
        else if(X<min)
            min = X;
    }
    
    printf("%ld %ld\n", min, max);
    return 0;
}