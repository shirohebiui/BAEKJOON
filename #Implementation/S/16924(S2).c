#include <stdio.h>
#define MAX 101
char board[MAX][MAX]; int N, M;
int queue[MAX*MAX][3], rear;
// 0 y 1 x 2 size

int isSafe(int y, int x, int size) {
    return (y-size > 0 && y+size <= N && x-size > 0 && x+size <= M);
}

int isValid(int y, int x, int size) {
    if(board[y+size][x] != '*') return 0;
    if(board[y-size][x] != '*') return 0;
    if(board[y][x+size] != '*') return 0;
    if(board[y][x-size] != '*') return 0;
    return 1;
}

void insert(int y, int x) {
    int size = 1;
    while(isSafe(y,x,size)) {
        if(isValid(y,x,size))
            size++;
        else break;
    }
    size--;
    if(size == 0) return;
    queue[rear][0] = y;
    queue[rear][1] = x;
    queue[rear][2] = size;
    rear++;
}

void painting(int y, int x, int size) {
    board[y][x] = '.';
    while(size) {
        board[y+size][x] = '.';
        board[y-size][x] = '.';
        board[y][x+size] = '.';
        board[y][x-size] = '.';
        size--;
    }
}

int main() {
    //input
    scanf("%d %d",&N, &M);
    for(int i=1; i<=N; i++) {
        scanf(" %s", &board[i][1]);
    }

    //find pos
    for(int i=2; i<N; i++) {
        for(int j=2; j<M; j++) {
            if(board[i][j] == '*') {
                insert(i, j);
            }
        }
    }

    //painting
    for(int i=0; i<rear; i++) {
        painting(queue[i][0], queue[i][1], queue[i][2]);
    }
    //check paint
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(board[i][j] == '*') {
                printf("-1\n");
                return 0;
            }
        }
    }

    //answer
    printf("%d\n", rear);
    for(int i=0; i<rear; i++) {
        printf("%d %d %d\n", queue[i][0], queue[i][1], queue[i][2]);
    }
    return 0;
}