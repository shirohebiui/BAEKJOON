#include <stdio.h>
#include <stdlib.h>
/*
arr[i][j]일때 배열의 범위내에서 하위3칸에합을 arr[i][j]에 저장한다.
그러면
010
000같이 끊긴곳은 0으로 바뀔것이고
010
101같이 연결된곳은 2로 가능한 경우의 수로 바뀔것이다.
이를 y축 (n-2 -> 0) x축(0 -> M)을 층마다 전부 탐색하며 올라오면 맨윗줄에는 경우의수들이 적혀있을것이고
이를 합산하면 총 경우의 수가 나올것이다.
*/
int main()
{
    
    int n,m;
    long arr[1000][1000]={0};
    scanf("%d %d", &n, &m);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%ld", &arr[i][j]);

    for(int i=n-2;i>=0;i--)
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==1)
            {
            if(j==0 && arr[i][j]==1)
                arr[i][j] = arr[i+1][j]+arr[i+1][j+1];
            else if(j==m)
                arr[i][j] = arr[i+1][j-1]+arr[i+1][j];
            else
                arr[i][j] = arr[i+1][j-1]+arr[i+1][j]+arr[i+1][j+1];
            }
        }

    /* printf("=============\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%ld ", arr[i][j]);
        }
        printf("\n");
    } */

    long sum=0;
    for(int j=0;j<m;j++)
        sum+=arr[0][j];
    printf("%ld\n", sum%1000000007);
    return 0;
}