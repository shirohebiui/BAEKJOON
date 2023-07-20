#include <stdio.h>

int main()
{
    int N, tmp;
    scanf("%d", &N);
    tmp = N;
    while(N--)
        printf("%d\n", tmp - N);
    return 0;
}