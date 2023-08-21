#include <stdio.h>

long factorial(int num)
{
    long result = 1;
    for (int i = 1; i <= num; ++i)
    {
        result = result * i;
    }
    return result;
}

long combination(int n, int r)
{
    if(n<20) //이걸 정하는게 핵심
        return factorial(n)/(factorial(r) * factorial(n-r));
    else
        return combination(n-1, r-1) + combination(n-1, r);
}

int main()
{
    int T;
    scanf("%d", &T);
    int N, M;
    while(T--) {
        scanf("%d%d", &N, &M);
        printf("%ld\n", combination(M, N));
    }
    return 0;
}