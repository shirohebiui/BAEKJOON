#include <iostream>
using namespace std;
#define SIZE 502
char board[SIZE][SIZE]; int n, m;
char vis[SIZE][SIZE];
void input() {
    scanf("%d %d", &n, &m);
    for(int y=1; y<=n; y++) {
        for(int x=1; x<=m; x++) {
            scanf(" %1hhd", &board[y][x]);
        }
    }
}

void init() {
    for(int y=0; y<=n+1; y++) {
        vis[y][m+1] = 1;
        vis[y][0] = 1;
    }
    for(int x=0; x<=m+1; x++) {
        vis[n+1][x] = 1;
        vis[0][x] = 1;
    }
}


char dy[4] = {0,1,-1,0};
char dx[4] = {1,0,0,-1};
int tsize, py, px;
static inline void dfs(short y, short x) {
    vis[y][x] = 1;
    ++tsize;
    for(int i=0; i<4; i++) {
        py = y+dy[i]; px = x+dx[i];
        if(!vis[py][px] && board[py][px]) dfs(py, px);
    }
}

int best, cnt;
void find() {
    for(int y=1; y<=n; y++) {
        for(int x=1; x<=m; x++) {
            if(!vis[y][x] && board[y][x]) {
                tsize = 0;
                ++cnt;
                dfs(y, x);
                best = max(best, tsize);
            }
        }
    }
}
int main(){
    input();
    init();
    find();
    cout << cnt << endl << best << endl;
	return 0;
}