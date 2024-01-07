#include <stdio.h>
#include <stdlib.h>
#define MAX 100001

long sum[MAX];

int main() {
    int N; scanf("%d", &N);
    int base[MAX];
    for(int i=1; i<=N; i++) {
        scanf(" %d", &base[i]);
        sum[i] = sum[i-1] + base[i];
    }
    int M; scanf(" %d", &M);

    int start, end;
    for(int i=0; i<M; i++) {
        scanf(" %d %d", &start, &end);
        if(start == end)     printf("%d\n", base[start]);
        else if(start < end) printf("%ld\n", sum[end]-sum[start-1]);
        else                 printf("%ld\n", sum[start]-sum[end-1]);
    }
    return 0;
}