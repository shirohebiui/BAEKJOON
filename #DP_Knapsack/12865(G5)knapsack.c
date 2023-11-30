#include <stdio.h>
#define MAX_W 100001
#define MAX_ITEM 101


int A[MAX_ITEM][MAX_W] = {0, };
int knapsack(int W, int *wt, int *val, int n) {
    for(int i=1; i<=n; i++) {
        for(int w=1; w<=W; w++) {
            if(wt[i-1] > w) {
                A[i][w] = A[i-1][w];
            } else {
                A[i][w] = A[i-1][w] > A[i-1][w-wt[i-1]] + val[i-1] ? A[i-1][w] : A[i-1][w-wt[i-1]] + val[i-1];
            }
        }
    }
    return A[n][W];
}

int main() {

    int val[MAX_ITEM] = {0, };// = {60, 100, 190, 120, 200, 150};
    int wt[MAX_ITEM] = {0, };// = {2, 5, 8, 4, 7, 6};
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++) {
        scanf("%d %d", &wt[i], &val[i]);
    }

    printf("%d\n", knapsack(K, wt, val, N));

    return 0;
}