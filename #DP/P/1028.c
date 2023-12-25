#include <stdio.h>
#define MAX 751
#define max(a,b) (a>b?a:b)

char board[MAX][MAX];
int N, M;

int right[MAX][MAX], left[MAX][MAX];
int best;

int isSafe(int y, int x) {
    return (y>=0 && y<=N && x>=0 && x<=M);
}

void sum_r(int y, int x) {
    if(right[y][x]) return; //이미 누적합 구한 곳은 제외
    right[y][x] = 1;
    while(isSafe(y+1,x+1)) {
        if(board[y+1][x+1])
            right[y+1][x+1] += right[y][x]+1;
        y++; x++;
    }
}

void sum_l(int y, int x) {
    if(left[y][x]) return;
    left[y][x] = 1;
    while(isSafe(y+1,x-1)) {
        if(board[y+1][x-1])
            left[y+1][x-1] += left[y][x]+1;
        y++; x--;
    }
}

void isShape(int y, int x) {
    int edge;
    for(int i=best; i<=right[y][x] && i<=left[y][x]; i++){
        edge=i-1;
        if(right[y-edge][x+edge] >= i && left[y-edge][x-edge] >= i) {
            best = max(i, best);
        }
    }
}

void test() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            printf("%d", left[i][j]);
        }
        printf("\n");
    }
        printf("\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            printf("%d", right[i][j]);
        }
        printf("\n");
    }
}

int main() {
    //input
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            scanf("%1d", &board[i][j]);
        }
    }
    //누적합
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(board[i][j]) {
                sum_l(i, j);
                sum_r(i, j);
            }
        }
    }
    //find best
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(left[i][j] > best && right[i][j] > best) {
                isShape(i,j);
            }
        }
    }
    // test();
    printf("%d\n", best);
    return 0;
}