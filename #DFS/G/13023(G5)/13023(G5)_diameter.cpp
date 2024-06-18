#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#define MAX_VSIZE 2000
#include <vector>
vector<vector<int> > G(MAX_VSIZE);
int len, end_point;
bool vis[MAX_VSIZE];
void dfs(int now, int dist) {
    if(len < dist) {
        len = dist;
        end_point = now;
    }
    if(len == 5) return;
    FOR(i, 0, G[now].size()) {
        if(!vis[G[now][i]]) {
            vis[G[now][i]] = 1;
            dfs(G[now][i], dist + 1);
            vis[G[now][i]] = 0;
        }
    }
}

void dfs_del(int now) {
    FOR(i, 0, G[now].size()) {
        if(!vis[G[now][i]]) {
            vis[G[now][i]] = 1;
            dfs_del(G[now][i]);
        }
    }
}

#include <cstring>
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int vsize, esize; cin >> vsize >> esize;
    int v, u;
    while(esize--) {
        cin >> v >> u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    FOR(i, 0, vsize) {
        if(!vis[i]) {
            vis[i] = 1;
            dfs(i, 1);
            vis[i] = 0;
            memset(vis, 0x00, sizeof(vis));
            vis[end_point] = 1;
            dfs(end_point, 1);
            if(len == 5) break;
            dfs_del(end_point);
        }
    }
    cout << bool(len == 5) << "\n";
    return 0;
}