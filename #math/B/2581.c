#include <stdio.h>

char arr[10000];

int solve(int M, int N);
int sum = 0, min = 1e9;

int main() {
    int M, N; scanf(" %d %d", &M, &N);
    solve(M, N);
    if(min != 1e9) printf("%d\n%d\n", sum, min);
    else           printf("-1\n");
    return 0;
}

int solve(int M, int N) {
    for(int i=2; i<=N; i++) {
        if(arr[i] == 0) {
            if(M <= i && i <= N) { // M <= i <= N
                sum += i;
                min = min < i ? min : i;
            }
            for(int j=i; j<=N; j+=i) {
                arr[j] = 1;
            }
        }
    }
}