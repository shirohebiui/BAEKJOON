#include <iostream>
using namespace std;

#define FOR(start, end) for(int i=(start); i<=(end); ++i)
typedef struct pos{
    short x, y;
};
pos home;
pos node[101]; int nsize;

static inline int dist(pos start, pos end) {
    return abs(start.y - end.y) + abs(start.x - end.x);
}

#include <queue>
#include <cstring>
char vis[100];
void bfs(pos now) {
    queue<pos> q;
    q.push(home);
    while(!q.empty()) {
        pos now = q.front(); q.pop();
        FOR(0, nsize) {
            if(!vis[i] && dist(now, node[i]) < 1001) {
                vis[i] = 1;
                q.push(node[i]);
            }
        }
        if(vis[nsize]) {cout << "happy\n"; return;}
    }
    cout << "sad\n"; return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int tc; cin >> tc;
    while(tc--) {
        //init
        memset(vis, 0x00, sizeof(vis));
        //intput
        cin >> nsize;
        cin >> home.x >> home.y;
        FOR(0, nsize) {
            cin >> node[i].x >> node[i].y;
        }
        bfs(home);
    }
    return 0;
}