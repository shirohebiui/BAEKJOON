#include <stdio.h>
#include <stdlib.h>
/*

*/
int main()
{
    
    int n,m;
    int arr[100][1000]={0};
    scanf("%d %d", &n, &m);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d", &arr[i][j]);
    
    return 0;
}