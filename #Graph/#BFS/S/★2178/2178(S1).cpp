#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
#define SIZE 102
char board[SIZE][SIZE];
int n, m;
short vis[SIZE][SIZE];
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

int bfs() {
    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    vis[1][1] = 1;
    char dy[4] = {0,1,-1,0};
    char dx[4] = {1,0,0,-1};
    int py, px;
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        // cout << y << " " << x << " " << vis[y][x] << "\n";
        if(y==n && x==m) return vis[y][x];
        q.pop();
        for(int i=0; i<4; i++) {
            int py = y+dy[i], px = x+dx[i];
            if(vis[py][px] == 0 && board[py][px] == 1) {
                vis[py][px] = 1 + vis[y][x];
                q.push(make_pair(py, px));
            }
        }
    }
}
int main(){
    input();
    init();
    cout << bfs() << "\n";
	return 0;
}