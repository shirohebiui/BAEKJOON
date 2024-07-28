#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define FOR(val, s_v, e_v) for(int val=(s_v); val<(e_v); val++)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


#define isSafe(y, x) (y>=0 && y<n && x>=0 && x<m)
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

char board[101][101];
int arr[10001], rear;
int n, m, k;
struct pos {int y, x;};
void bfs(pos now) {
    queue<pos> q;
    q.push(now);
    int rsize = 0;
    while(!q.empty()) {
        now = q.front(); q.pop();
        rsize++;
        FOR(i, 0, 4) {
            int py = now.y + dy[i], px = now.x +dx[i];
            if(isSafe(py, px) && !board[py][px]) {
                board[py][px] = 1;
                q.push({py, px});
            }
        }
    }
    arr[rear++] = rsize;
}

int main() {
    FAST_IO
    cin >> n >> m >> k;
    while(k--) {
        int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
        FOR(i, sy, ey) FOR(j, sx, ex) board[i][j] = 1;
    }
    int cnt = 0;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if(!board[i][j]) {
                board[i][j] = 1;
                bfs({i, j});
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    sort(arr, arr+rear);
    FOR(i, 0, rear) cout << arr[i] << ' ';

    return 0;
}
