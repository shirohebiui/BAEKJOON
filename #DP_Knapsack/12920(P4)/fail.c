#include <stdio.h>
#include <string.h>
#define MAX_W 10001
#define MAX_ITEM 10001
#define max(a,b) (a > b ? a : b)

/*
발상 진행하다 갯숫가 여러개면 wt, val을 고정후 갯수만큼 진행후 그 결과를 
i번째에 다시 붙여 결론을 가져온다.
*/

int A[MAX_ITEM][MAX_W] = {0, };

void test(int W, int n);
int sum(int *arr, int n);
int knapsack(int W, int *wt, int *val, int *cnt, int n) {
    int i, j;
    for(i=1; i<=n; i++) {
        for(j=i; j<i+cnt[i-1]; j++) {
            //printf("loop %d : %d\n", i, j-i);
            
            for(int w=1; w<=W; w++) {
                if(wt[i-1] > w) {
                    A[j][w] = A[j-1][w];
                } else {
                    A[j][w] = max(A[j-1][w], A[j-1][w-wt[i-1]] + val[i-1]);
                }
            }
            //test(W , n+ sum(cnt, W));
        }
        if(cnt[i-1] > 1)
            memmove(A[i], A[j-1], sizeof(int) * (W+1));
    }
    return A[n][W];
}

int main() {
    int val[MAX_ITEM] = {0, };
    int wt[MAX_ITEM] = {0, };
    int cnt[MAX_ITEM] = {0, };
    int N, K; scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++) {
        scanf("%d %d %d", &wt[i], &val[i], &cnt[i]);
    }

    printf("%d\n", knapsack(K, wt, val, cnt, N));
    //test(K, N);
    return 0;
}

void test(int W, int n) {
    printf("test\n");
    for(int i=1; i<=n; i++) {
        for(int w=1; w<=W; w++) {
            printf(" %d", A[i][w]);
        }
        printf("\n");
    }
}

int sum(int *arr, int n) {
    int result = 0;
    for(int i=0; i<n; i++) {
        result += arr[i];
    }
    return result;
}