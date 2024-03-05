#include <stdio.h>
#include <string.h>
#define SIZE 31

long long table[SIZE][SIZE];

long long dp(int n, int m) { //온전한알약, 반쪽알약
    if(table[n][m] != 0) return table[n][m];
    if(n == 0) {
        return table[n][m] = 1;
    } else if(m == 0) {
        return table[n][m] = dp(n-1, 1);
    } else {
        return table[n][m] = dp(n-1, m+1) + dp(n, m-1);
    }
}

int main() {
    while(1) {
        memset(table, 0x00, sizeof(table));
        int n; scanf(" %d", &n);
        if(n == 0) return 0;
        printf("%lld\n", dp(n, 0));
    }
    return 0;
}