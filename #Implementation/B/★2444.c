#include <stdio.h>
/*
for문을 잘...엮어서...
공백 / 좌측별 / 우측별
"  " / *** / **
이런식으로 한 줄을 3단계로 구별하여서 풀이했다.
*/
int main()
{
    int n;
    scanf("%d", &n);

    for(int i=0;i<n;i++)
    {
        for(int j=n-i;j>1;j--)
            printf(" ");
        for(int j=0;j<2*i+1;j++)
            printf("*");
        printf("\n");
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<n-i-1;j++)
            printf(" ");
        for(int j=0;j<2*i+1;j++)
            printf("*");
        printf("\n");
    }
}