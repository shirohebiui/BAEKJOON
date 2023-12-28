#include <stdio.h>
#define max(a,b) (a>b?a:b)

#define MAX_APP 101
#define MAX_COST 10001
#define min(a,b) (a<b?a:b)

int N, need, max_cost;
int cost[MAX_APP];
int mem[MAX_APP];

int DP[MAX_COST];
void knapsack() {
    for(int i=1; i<=N; i++) {
        for(int j=max_cost; j>=1; j--) {
            if(j-cost[i] >= 0)
                DP[j] = max(DP[j], DP[j-cost[i]] + mem[i]);
        }
    }
}

void test();
int main() {
    scanf("%d %d", &N, &need);
    for(int i=1; i<=N; i++) scanf(" %d", &mem[i]);
    for(int i=1; i<=N; i++) {
        scanf(" %d", &cost[i]);
        max_cost += cost[i];
    }
    for(int i=1; i<=N; i++) {
        if(cost[i] == 0) {
            need -= mem[i];
            mem[i] = 0;
        }
    }
    if(need <= 0) {
        printf("0\n");
        return 0;
    }
    knapsack();
    for(int i=1; i<=max_cost; i++) {
        if(DP[i] >= need) {
            printf("%d\n", i);
            return 0;
        }
    }
    
    test();
    return 0;
}

void test() {
    for(int i=1; i<=max_cost; i++) {
        printf("%d ", DP[i]);
    }
    printf("\n");
}