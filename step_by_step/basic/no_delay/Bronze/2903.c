#include <stdio.h>
/*
중앙이동 알고리즘?

*/
int main()
{
    int point = 2;
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++)
    {
        point = 2*point-1;
    }
    printf("%d\n", point*point);
    return 0;
}