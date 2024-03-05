#include <stdio.h>
#define mod 10007

short table[1000];

int dp(int idx) {
    table[1] = 1;
    table[2] = 2;
    table[3] = 3;
    for(int i=4; i<=idx; i++) {
        table[i] = table[i-2] + table[i-1];
        table[i] %= mod;
    }
    return table[idx];
}

int main() {
    int idx; scanf(" %d", &idx);
    printf("%d\n", dp(idx));
    return 0;
}