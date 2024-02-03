#include <stdio.h>

char dy[4] = {-1,  0, 0, 1};
char dx[4] = { 0, -1, 1, 0};

typedef struct pos{
    short y, x;
}pos;

pos queue[1000001]; int front, rear;

int m, n;
char board[1001][1001]; int day;

static inline int isSafe(int y, int x) {
    if(y<0 || y>=n) return 0;
    if(x<0 || x>=m) return 0;
    if(board[y][x] == 0) return 1;
    return 0;
}

void bfs() {
    int prear, py, px, flag;
    while(front<rear) {
        flag = 0;
        prear = rear;
        while(front<prear) {
            for(int i=0; i<4; i++) {
                py = queue[front].y + dy[i]; px = queue[front].x + dx[i];
                if(isSafe(py, px)) {
                    flag = 1;
                    board[py][px] = 1;
                    queue[rear].y = py; queue[rear].x = px; rear++;
                }
            }
            front++;
        }
        if(flag) day++;
    }
}

int isComplete() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == 0) return 0;
        }
    }
    return 1;
}

int main(){
    scanf("%d %d", &m, &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf(" %hhd", &board[i][j]);
            if(board[i][j] == 1) {
                queue[rear].y = i; queue[rear].x = j; rear++;
            }
        }
    }
    bfs();
    if(isComplete()) printf("%d\n", day);
    else printf("-1\n");
    return 0;
}