#include <iostream>
using namespace std;

#include <vector>
#include <queue>

char board[302][302]; int n, m;
typedef struct pos {
    int y, x, ice;
}pos;

vector<pos> v; int cnt;
vector<pos> out;

char dy[4] = {0,1,-1,0};
char dx[4] = {1,0,0,-1};


int vis[302][302], chk = 1;

int chk_ice() {
    int chain = 1;
    queue<pos> q;
    q.push(v[0]);
    while(!q.empty()) {
        pos p = q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            int py = p.y + dy[i], px = p.x + dx[i];
            if(board[py][px] && vis[py][px] != chk) {
                vis[py][px] = chk;
                q.push({py, px, 0});
                ++chain;
            }
        }
    }
    ++chk;
    return chain - 1;
}

void melting() {
    for(int i=0; i<cnt; i++) {
        for(int j=0; j<4; j++) {
            v[i].ice -= !board[v[i].y + dy[j]][v[i].x + dx[j]];
        }
        if(v[i].ice <= 0) {
            --cnt;
            out.push_back(v[i]);
            v.erase(v.begin() + i);
            --i;
        }
    }
    while(!out.empty()) {
        pos s = out.back();
        board[s.y][s.x] = 0;
        out.pop_back();
    }
}

void ans() {
    int time = 0;
    while(1) {
        melting();
        ++time;
        if(cnt != chk_ice() || cnt == 0) break;
    }
    if(cnt) cout << time << "\n";
    else cout << "0\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //input
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            int ice; cin >> ice;
            if(ice) {
                ++cnt;
                board[i][j] = 1;
                v.push_back({i,j,ice});
            }
        }
    }
    ans();
    return 0;
}