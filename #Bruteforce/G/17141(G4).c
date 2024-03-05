#include <stdio.h>
#include <string.h>
#define SIZE 51
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
char dy[4] = {0,1,-1,0};
char dx[4] = {1,0,0,-1};
char board[SIZE][SIZE]; int n, m;
char update[SIZE][SIZE];

void input();

static inline int isSafe(int y, int x) {
    return (y>=0 && y<n && x>=0 && x<n);
}

void nCr(int idx, int cnt);
typedef struct pos{
    char y, x;
}pos;
pos disease[10]; int size; //바이러스의 개수 M(1 ≤ M ≤ 10)
pos queue[2501];

void simul();
int best;
void bfs();
void test();

int main() {
    input();
    nCr(0,0);
    if(best < n*n+1) printf("%d\n", best-2);
    else printf("-1\n");
    return 0;
}

void input() {
    scanf("%d %d", &n, &m); best = n*n+1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf(" %hhd", &board[i][j]);
            if(board[i][j] == 1) board[i][j] = -1;
            else if(board[i][j] == 2) {
                board[i][j] = 0;
                disease[size].y = i; disease[size++].x = j;
            }
        }
    }
}

void nCr(int idx, int cnt) {
    if(cnt == m) {
        simul();
        return;
    }
    for(int i=idx; i<size; i++) {
        queue[cnt] = disease[i];
        nCr(i+1, cnt+1);
    }
}

void simul() {
    //init
    memmove(update, board, sizeof(board));
    for(int i=0; i<m; i++) update[queue[i].y][queue[i].x] = 1;
    // test();
    //simul
    bfs();
}
void bfs() {
    short time = 1, front = 0, rear = m , prear, i, j, py, px;
    while(front < rear) {
        prear = rear;
        while(front < prear) {
            for(i=0; i<4; i++) {
                py = queue[front].y+dy[i]; px = queue[front].x+dx[i];
                if(isSafe(py, px) && update[py][px] == 0) {
                    update[py][px] = time;
                    queue[rear].y = py; queue[rear++].x = px;
                }
            }
            front++;
        }
        time++;
        if(time >= best) return;
    }

    //chk valid
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(update[i][j] == 0) return;
        }
    }
    best = time;
}

void test() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j] == -1) printf(" - ");
            else printf("%2d ",board[i][j]);
        }
        printf("\t");
        for(int j=0; j<n; j++) {
            if(update[i][j] == -1) printf(" - ");
            else printf("%2d ",update[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}