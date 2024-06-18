#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

char board[100][100];
int n, m, jmp;
struct pos{
    int y, x;
};
static inline int isAdj(pos s1, pos s2) {
    return abs(abs(s1.y-s2.y) + abs(s1.x-s2.x)) <= jmp;
}
#include <vector>
vector<pos> v;

#include <queue>
int bfs() {
    if(board[n-1][m-1] != board[0][0]) return 0;
    queue<pos> q;
    q.push(v[0]); v.erase(v.begin());
    while(!q.empty()) {
        if(q.front().y == n-1 && q.front().x == m-1) return 1;
        int vsize = v.size();
        FOR(i, 0, vsize) {
            if(isAdj(q.front(), v[i])) {
                q.push(v[i]);
                v.erase(v.begin() + i);
                --vsize; --i;
            }
        }
        q.pop();
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    FOR(i, 0, n) FOR(j, 0, m) {
        cin >> board[i][j];
        if(board[i][j] == board[0][0]) v.push_back({i, j});
    }
    cin >> jmp;

    if(bfs()) {
        cout << "ALIVE\n";
    } else {
        cout << "DEAD\n";
    }
    return 0;
}