#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)
#define isSafe(y, x) (y<n && y>=0 && x<m && x>=0)

char board[9][9]; int n, m;

char num[10];
int best = -1;

void calc(int y, int x, int dy, int dx) {
    int idx = 0, py = y, px = x;
    if(dy == 0 && dx == 0) return;
    while(isSafe(py ,px)) {
        num[idx] = board[py][px];
        py += dy; px += dx; ++idx;
    }
    if(idx == 0) return;
    num[idx] = '\0';
    while(idx--) {
        int res = atoi(num);
        num[idx] = '\0';
        if(res < 0 && res <= best) continue;
        for(int k=0; k*k<=res; ++k) {
            if(k*k == res) {
                best = max(best, res);
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    FOR(i, 0, n) {
        cin >> board[i];
        FOR(s, 0, m) {
            FOR(k, 0, 9) if(k*k == board[i][s]-'0') best = max(best, board[i][s] - '0');
        }
    }
    FOR(y, 0, n) {
        FOR(x, 0, m) {
            FOR(i, -(n-1), n) {
                FOR(j, -(m-1), m) {
                    calc(y, x, i, j);
                }
            }
        }
    }
    cout << best << "\n";

    return 0;
}