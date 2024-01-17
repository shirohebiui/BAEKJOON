#include <stdio.h>

int memo[41][2];

int fib(int n) {
    for(int i=2; i<=n; i++) {
        memo[i][0] = memo[i-1][0] + memo[i-2][0];
        memo[i][1] = memo[i-1][1] + memo[i-2][1];
    }
}

int main() {
    memo[0][0] = 1;
    memo[1][1] = 1;

    int tc; scanf("%d", &tc);
    while(tc--) {
        int n; scanf(" %d", &n);
        fib(n);
        printf("%d %d\n", memo[n][0], memo[n][1]);
    }
    return 0;
}