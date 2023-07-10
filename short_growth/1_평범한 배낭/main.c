#include <stdio.h>
#include <stdlib.h>
int N, K, dp[101][100001] = {0}, W[101], V[101], i, j, tmp=0;
int main()
{
    /*
    N개의 물건
    무게 W, 가치 V
    최대무게 K
    ->배낭에 넣을 수 있는 가치의 최댓값

    input
    first      = 물품의 수 + 최대무게 (N, K)
    2line over = 물품의 무게 + 가치 (W, V)
    */

    scanf("%d %d", &N, &K);
    for(i=1; i<=N;i++)
        scanf("%d %d", &W[i], &V[i]);
    
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=K;j++)
        {
            if(W[i]<=j)
            {
                dp[i][j] = V[i];
                tmp = W[i];
                dp[i][j] += dp[i-1][j-tmp];
                if(dp[i][j] < dp[i-1][j])
                    dp[i][j] = dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];

        }
    }
    printf("%d", dp[N][K]);
    return 0;
}