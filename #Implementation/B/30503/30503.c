#include <stdio.h>
//https://www.acmicpc.net/problem/30503
//걸린시간 16분
long arr[1001]; // 1~1000

void input(int N);
void print(int Q);
int find(int l, int r, long k);
void del(int l, int r);

int main() {
    int N; scanf(" %d", &N);
    input(N);
    int Q; scanf(" %d", &Q);
    print(Q);
    return 0;
}

void input(int N) {
    for(int i=1; i<=N; i++) {
        scanf(" %ld", &arr[i]);
    }
}

void print(int Q) {
    int mod;
    int l, r;
    long k;
    while(Q--) {
        fflush(stdin);
        scanf(" %d", &mod);
        if(mod == 1) {
            scanf( "%d %d %ld", &l, &r, &k);
            printf("%d\n", find(l, r, k));
        } else {
            scanf( " %d %d", &l, &r);
            del(l, r);
        }
    }
}

int find(int l, int r, long k) {
    int kind = 0;
    for(int i=l; i<=r; i++) {
        if(arr[i] == k) kind++;
    }
    return kind;
}

void del(int l, int r) {
    for(int i=l; i<=r; i++) {
        arr[i] = 0;
    }
}