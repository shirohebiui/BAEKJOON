#include <stdio.h>
#include <string.h>
#define min(a,b) (a<b?a:b)
char dy[4] = {0,1,-1,0};
char dx[4] = {1,0,0,-1};
char board[8][8]; int n, m, k; int wall = 3;
char update[8][8];

void input();

static inline int isSafe(int y, int x) {
    return (y>=0 && y<n && x>=0 && x<m);
}
void make_wall(int idx, int cnt);
int best = 999;

int safe_area();
void infect(int y, int x);
int ty, tx;
int dis;
char disease[64][2]; int rear;

int main() {
    input();
    make_wall(0, 0);
    printf("%d\n", k-best-wall);
    return 0;
}
void input() {
    scanf("%1d %1d", &n, &m); k = n*m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf(" %hhd", &board[i][j]);
            if(board[i][j] == 1) ++wall;
            else if(board[i][j] == 2) {
                ++wall;
                disease[rear][0] = i; disease[rear++][1] = j;
            }
        }
    }
}

void make_wall(int idx, int cnt) {
    if(cnt == 3) {
        int tmp = safe_area();
        best = min(best, tmp);
        return;
    }
    for(int i=idx; i<k; i++) {
        int py = i/m, px = i%m;
        if(board[py][px] == 0) {
            board[py][px] = 1;
            make_wall(i+1, cnt+1);
            board[py][px] = 0;
        }
    }
}

int safe_area() {
    memmove(update, board, sizeof(board));
    dis = 0;
    for(int i=0; i<rear; i++) {
        infect(disease[i][0], disease[i][1]);
    }
    return dis;
}

void infect(int y, int x) {
    if(dis >= best) return;
    for(int i=0; i<4; i++) {
        ty = y+dy[i], tx = x+dx[i];
        if(isSafe(ty, tx) && update[ty][tx] == 0) {
            update[ty][tx] = 2; ++dis;
            infect(ty, tx);
        }
    }
}