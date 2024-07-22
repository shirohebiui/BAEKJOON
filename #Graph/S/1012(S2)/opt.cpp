#include <cstdio>
using namespace std;
#define isSafe(x, y) (y>=0 && y<n && x>=0 && x<m)
#define FOR(val, s, e) for(int val=(s); val<(e); val++)
#define NOW q[front]

struct pos{int x,y;};
int main() {
char board[50][50] = {0, }, dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
pos q[2500];
    int tc; scanf("%d ", &tc);
    int n, m, k, px, py , front, rear, res;
    while(tc--) {
        front = rear = res = 0;
        scanf("%d %d %d", &m, &n, &k);
        while(k--) {
            scanf("%d %d", &px, &py);
            board[px][py] = 1;
        }
        FOR(x, 0, m) {
            FOR(y, 0, n) {
                if(board[x][y]) {
                    //bfs start
                    board[x][y] = 0;
                    q[rear++] = {x,y}; res++;
                    while(front < rear) {
                        FOR(i, 0, 4) {
                            px = NOW.x + dx[i], py = NOW.y + dy[i];
                            if(isSafe(px, py) && board[px][py] == 1) {
                                board[px][py] = 0;
                                q[rear++] = {px,py};
                            }
                        }
                        front++;
                    }
                    //bfs end
                }
            }
        }
        printf("%d\n", res);
    }
}