#include <stdio.h>
#define MAX_W 10001
#define MAX_ITEM 10001
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)

int A[MAX_ITEM][MAX_W] = {0, };
int val[MAX_ITEM] = {0, };
int wt[MAX_ITEM] = {0, };
int rear = 0;

void test(int W, int n);

int knapsack(int W, int n) {
    for(int i=1; i<=n; i++) {
        for(int w=1; w<=W; w++) {
            if(wt[i-1] > w) {
                A[i][w] = A[i-1][w];
            } else {
                A[i][w] = max(A[i-1][w], A[i-1][w-wt[i-1]] + val[i-1]);
            }
        }
        //test(W, n);
    }
    return A[n][W];
}

int main() {
    int Kind, W; scanf("%d %d", &Kind, &W);

    int w, v, cnt;
    for(int i=0; i<Kind; i++) {
        scanf("%d %d %d", &w, &v, &cnt);
        // for(int j=0; cnt>0; j++){
		// 	int tmp = min(1<<j, cnt);
        //     wt[rear] = tmp*w;
        //     val[rear] = tmp*v;
        //     rear++;
        //     cnt -= tmp;
        // }
        int t = 1; int exp = 1;
        while(exp <= cnt){
            if(w * t > W) break;
            //printf("t %d\n", t);
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
    //printf("%d\n", rear);
    return 0;
}

void test(int W, int n) {
    printf("test\n");
    for(int i=1; i<=n; i++) {
        printf("%2d %2d:", wt[i-1], val[i-1]);
        for(int w=1; w<=W; w++) {
            printf(" %2d", A[i][w]);
        }
        printf("\n");
    }
}