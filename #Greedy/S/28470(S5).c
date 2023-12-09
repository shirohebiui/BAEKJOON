#include <stdio.h>

int N;
int A[100001];
int B[100001];
float K[100001];

void init_input() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf(" %d", &A[i]);
    }
    for(int i=0; i<N; i++) {
        scanf(" %d", &B[i]);
    }
    for(int i=0; i<N; i++) {
        scanf(" %f", &K[i]);
    }
}

long sum(int round) {
    if(round+1 < N) {
        if(K[round] >= 1) {
            return (A[round]*(int)(K[round]*10))/10 - B[round] + sum(round+1);
        } else {
            return  A[round] - (B[round]*(int)(K[round]*10))/10 + sum(round+1);
        }
    } else {
        if(K[round] >= 1) {
            return (A[round]*(int)(K[round]*10))/10 - B[round];
        } else {
            return A[round] - (B[round]*(int)(K[round]*10))/10;
        }
    }
}

int main() {
    init_input();
    long result = sum(0);
    printf("%ld\n", result);
    return 0;
}
