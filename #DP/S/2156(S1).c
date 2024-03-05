#include <stdio.h>
#define max(a, b) (a>b?a:b)
int std[10000];
int N;

void input() {
    scanf("%d", &N);
    int i=N;
    while(i--) scanf(" %d", &std[i]);
}


int answer() {
int t1 = 999999;
int dp[10000];
int t2 = 999999;
    dp[0] = std[0];
    dp[1] = std[0] + std[1];
    dp[2] = std[2] + max(std[0], std[1]);
    for(int i=3; i<N; i++) {
        dp[i] = 0;
        dp[i] = max(dp[i], dp[i-1]); //???ox
        dp[i] = max(dp[i], std[i] + dp[i-2]); //??oxo
        dp[i] = max(dp[i], std[i] + std[i-1] + max(dp[i-3], dp[i-4])); //??xoo
    }
    return dp[N-1];
}

int main() {
    input();
    printf("%d\n", answer());
    return 0;
}