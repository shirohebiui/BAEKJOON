#include <stdio.h>

long factorial_combination(int N, int R)
{
    long long result = 1;
    int i = R+1;
    int j = 1;
    long long tmp=j;
    while(1)
    {
        if(i < N+1)
            result *= i;
        if(j < N-R+1)
            tmp *= j;
        if(result % tmp == 0)
        {
            result /= tmp;
            tmp = 1;
        }
        if(!( i < N && j < N-R+1)) {
            break;
            result /= tmp;
        }
        i++; j++;
    }
    return result;
}

int main()
{
    int T;
    scanf("%d", &T);
    int N, M;
    while(T--) {
        scanf("%d%d", &N, &M);
        printf("%ld\n", factorial_combination(M, N));
    }
    return 0;
}