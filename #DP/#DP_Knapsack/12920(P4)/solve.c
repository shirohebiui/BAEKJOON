#include <stdio.h>
#define MAX_W 10001
#define MAX_ITEM 10001
#define max(a,b) (a > b ? a : b)

int DP[MAX_ITEM][MAX_W] = {0, };
int val[MAX_ITEM] = {0, };
int wt[MAX_ITEM] = {0, };
int rear = 0;

int knapsack(int W, int n) {
    for(int i=1; i<=n; i++) {
        for(int w=1; w<=W; w++) {
            if(wt[i-1] > w) {
                DP[i][w] = DP[i-1][w];
            } else {
                DP[i][w] = max(DP[i-1][w], DP[i-1][w-wt[i-1]] + val[i-1]);
            }
        }
    }
    return DP[n][W];
}

int main() {
    int Kind, W; scanf("%d %d", &Kind, &W);

    int w, v, cnt;
    for(int i=0; i<Kind; i++) {
        scanf("%d %d %d", &w, &v, &cnt);
        int t = 1; int exp = 1;
        while(exp <= cnt){
            if(w * t > W) break;
            wt[rear] = t*w;
            val[rear] = t*v;
            rear++;
            t = t<<1;
            exp += t;
        }
        exp -= t;
        exp = cnt - exp;
        if(exp > 0) {
            wt[rear] = exp*w;
            val[rear] = exp*v;
            rear++;
        }
    }
    printf("%d\n", knapsack(W, rear));
    return 0;
}