#include <stdio.h>
#define max(a,b) (a>b?a:b)
#define MAX 301

int stair[MAX];

unsigned long dp[MAX][2];

void bottom_top(int end) {
    dp[0][0] = stair[0];
    dp[0][1] = stair[0];
    dp[1][0] = stair[0]+stair[1];
    dp[1][1] = stair[1];
    for(int i=2; i<end; i++) {
        dp[i][0] = stair[i] + dp[i-1][1];
        dp[i][1] = stair[i] + max(dp[i-2][0], dp[i-2][1]);
        // printf("%ld %ld\n", dp[i][0], dp[i][1]);
    }
}

int main() {
    int end; scanf("%d", &end);
    for(int i=0; i<end; i++) {
        scanf(" %d", &stair[i]);
    }
    bottom_top(end);
    printf("%ld\n", max(dp[end-1][0], dp[end-1][1]));
    return 0;
}