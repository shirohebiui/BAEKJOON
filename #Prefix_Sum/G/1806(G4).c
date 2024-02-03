#include <stdio.h>
#define MAX 100001
#define min(a,b) (a<b?a:b)

int sum[MAX];
//100,000,000
int main() {
    int N, S; scanf("%d %d", &N, &S); N++;
    for(int i=1; i<N; i++) {
        scanf(" %d", &sum[i]);
        sum[i] += sum[i-1];
    }
    // for(int i=1; i<N; i++) printf("%d ", sum[i]);
    // printf("\n");

    if(sum[N-1] < S) {printf("0\n"); return 0;}
    int std = 1, adj = 0;
    int best = 100000;
    while(std < N) {
        while(std < N && sum[std] - sum[adj] < S) std++;
        while(adj < std && sum[std] - sum[adj] >= S) adj++;
        adj--;
        // printf("%d[%d] - %d[%d] = %d\n", std, sum[std], adj, sum[adj], sum[std] - sum[adj]);
        best = min(best, std-adj);
        std++;
    }
    printf("%d\n", best);
    return 0;
}