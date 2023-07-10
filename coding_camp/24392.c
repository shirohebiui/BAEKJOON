#include <stdio.h>
#include <stdlib.h>
int main()
{
    
    int n,m;
    int arr[100][1000]={0};
    scanf("%d %d", &n, &m);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d", &arr[i][j]);
    for(int a=1;a<n;a++)
    {
        for(int b=0;b<m;b++)
        {
        if(arr[a][b]==1)
        {
        if(b-1>=0 && b+1<m)//모두 배열존재
            arr[a][b]=arr[a-1][b-1]+arr[a-1][b]+arr[a-1][b+1];
        else if(b-1<0)//좌측 미존재
            arr[a][b]=arr[a-1][b]+arr[a-1][b+1];
        else if(b+1>m)//우측 미존재
            arr[a][b]=arr[a-1][b-1]+arr[a-1][b];
        }
        }
    }
    int sum=0;
    for(int i=0;i<m;i++)
    {
        sum+=arr[n-1][i];
    }
    printf("%d\n", sum);
    /*
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            printf("%d", arr[i][j]);
        printf("\n");
    }
    */
}