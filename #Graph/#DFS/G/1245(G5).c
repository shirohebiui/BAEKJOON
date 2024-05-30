#include <stdio.h>

short board[102][102]; char n, m;
char vis[102][102];
char FLAG;
char py, px;
char dy[8] = {0,1,-1,0, 1, 1, -1, -1};
char dx[8] = {1,0,0,-1, 1, -1, 1, -1};
void chk_lower(char y, char x, int h) {
    if(vis[y][x]) return;
    vis[y][x] = 1;
    for(char i=0; i<8; i++) {
        py = y+dy[i]; px = x+dx[i];
        if(board[py][px] <= h) {
            chk_lower(py, px, board[py][px]);
        }
    }
}

int high;
void dfs(char y, char x) {
    if(vis[y][x]) return;
    vis[y][x] = 1;
    for(char i=0; i<8; i++) {
        py = y+dy[i]; px = x+dx[i];
        if(board[py][px] < high) {
            chk_lower(py, px, board[py][px]);
        } else if(board[py][px] == high) {
            dfs(py, px);
        } else {
            FLAG = 1;
        }
    }
}

int f() {
    int cnt = 0;
    for(char i=1; i<=n; i++) {
        for(char j=1; j<=m; j++) {
            if(!vis[i][j]) {
                FLAG = 0;
                high = board[i][j];
                dfs(i,j);
                if(!FLAG) ++cnt;
            }
        }
    }
    return cnt;
}

void input() {
    scanf(" %hhd %hhd", &n, &m);
    for(char i=1; i<=n; i++) {
        for(char j=1; j<=m; j++) {
            scanf(" %hd", &board[i][j]);
        }
    }
}

void make_vis_wall() {
    for(char i=0; i<=n+1; i++) {
        vis[i][0] = 1;
        vis[i][m+1] = 1;
    }
    for(char j=0; j<=m+1; j++) {
        vis[0][j] = 1;
        vis[n+1][j] = 1;
    }
}

int main() {
    input();
    make_vis_wall();
    printf("%d\n", f());
}