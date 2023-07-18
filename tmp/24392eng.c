#include <stdio.h>
#include <stdlib.h>
/*
when arr[i][j], this sum of the lower 3 cells within the range of the array is sotred in arr[i][j] <- arr[i-1][j -1,0,+1]sum
then
010 -> 000
000 -> 000
The place where it is cut together will change to 0

010 -> 020
101 -> 101
The place connected together will change the number of possible cases.

If I search all the y-axix(n-2 ~ 0) for each floor and come up,
the number of cases will be written on the top line (y==0)

adding these together gives the total number of cases
*/

long long arr[1001][1001]={0};
int main()
{
    //data input
    int n,m;
    scanf("%d %d", &n, &m);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%lld", &arr[i][j]);

    long long sum=0;

    //x width = 1
    if(m==1)
    {
        for(int i=0;i<n;i++)
        {
            sum+=arr[i][0];
        }
        if(sum == n){
            sum = 1;
        }
        else{
            sum = 0;
        }
        printf("%lld\n", sum);
        return 0;
    }

    //y length = 1
    if(n==1)
    {
        for(int j=0;j<m;j++)
        {
            sum+=arr[0][j];
        }
        printf("%lld\n", sum);
        return 0;
    }

    //x, y >=2 case
    for(int i=n-2;i>=0;i--)
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==1)
            {
            if(j==0){        //left end
                arr[i][j] = arr[i+1][j]+arr[i+1][j+1];
            }else if(j==m){   //right end
                arr[i][j] = arr[i+1][j-1]+arr[i+1][j];
            }else{            //middle
                arr[i][j] = arr[i+1][j-1]+arr[i+1][j]+arr[i+1][j+1];
            }
            }
        }

    //test code
    /* printf("=============\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%ld ", arr[i][j]);
        }
        printf("\n");
    } */

    for(int j=0;j<m;j++)
        sum+=arr[0][j]%1000000007; //This value is the condition specified in the problem
    printf("%lld\n", sum);

    return 0;
}