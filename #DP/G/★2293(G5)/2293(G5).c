#include <stdio.h>

int find(int goal) {

}

int main() {
    int n, goal, coin[101], i, j;
    int dp[10001] = {0, };

    scanf("%d %d", &n, &goal);
    for(i=0;i<n;i++) {
        scanf("%d", &coin[i]);
    }

    dp[0] = 1;

    for(i=0; i<n; i++) {
        for(j=coin[i]; j<=goal; j++) {
            if(j>=coin[i])
                dp[j] += dp[j-coin[i]];
        }
    }

    /* for(i=0;i<=goal;i++)
        printf("%d ", dp[i]); */
    printf("%d\n", dp[goal]);

    return 0;
}