#include <stdio.h>

int main()
{
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    int count[10] = {0, };
    long sum = A*B*C;
    int tmp;
    while(sum)
    {
        tmp = sum%10;
        count[tmp]++;
        sum /= 10;
    }
    for(int i=0; i<10; i++)
    {
        printf("%d\n", count[i]);
    }
    return 0;
}