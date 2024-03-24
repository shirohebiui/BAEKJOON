#include <iostream>
#include <queue>
typedef char s8;
typedef short s16;
typedef int s32;
using namespace std;

#define SIZE 502
s8 board[SIZE][SIZE]; int n, m;
s8 vis[SIZE][SIZE];
void input() {
    scanf("%d %d", &n, &m);
    for(s16 y=1; y<=n; y++) {
        for(s16 x=1; x<=m; x++) {
            scanf(" %1hhd", &board[y][x]);
        }
    }
}

void init() {
    for(s16 y=0; y<=n+1; y++) {
        vis[y][m+1] = 1;
        vis[y][0] = 1;
    }
    for(s16 x=0; x<=m+1; x++) {
        vis[n+1][x] = 1;
        vis[0][x] = 1;
    }
}


s32 bfs(s16 y, s16 x) {
    s8 dy[4] = {0,1,-1,0};
    s8 dx[4] = {1,0,0,-1};
    s16 py, px;
    s32 tsize = 0;

    queue<pair<s16, s16>> q;
    q.push(make_pair(y, x));
    vis[y][x] = 1, ++tsize;
    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            py = y+dy[i], px = x+dx[i];
            if(!vis[py][px] && board[py][px]) {
                vis[py][px] = 1, ++tsize;
                q.push(make_pair(py, px));
            }
        }
    }
    return tsize;
}

s32 best, cnt;
void find() {
    for(s16 y=1; y<=n; y++) {
        for(s16 x=1; x<=m; x++) {
            if(!vis[y][x] && board[y][x]) {
                ++cnt;
                best = max(best, bfs(y,x));
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