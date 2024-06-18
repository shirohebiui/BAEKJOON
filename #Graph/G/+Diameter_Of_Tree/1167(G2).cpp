#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

struct node{
    int v; short cost;
};
#include <vector>
#define MAX_VSIZE 100001
vector<vector<node> > G(MAX_VSIZE); int vsize;

char vis[MAX_VSIZE];
int end_point, len;
void dfs(int now, int dist) {
    if(len < dist) {
        len = dist;
        end_point = now;
    }
    FOR(i, 0, G[now].size()) {
        if(!vis[G[now][i].v]) {
            vis[G[now][i].v] = 1;
            dfs(G[now][i].v, dist + G[now][i].cost);
        }
    }
}

#include <cstring>
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //input
    cin >> vsize;
    FOR(i, 0, vsize-1) {
        int v, u, cost; cin >> v;
        while(1) {
            cin >> u;
            if(u == -1) break;
            cin >> cost;
            G[v].push_back({u, (short)cost});
            G[u].push_back({v, (short)cost});
        }
    }
    vis[1] = 1;
    dfs(1, 0);
    memset(vis, 0x00, sizeof(vis));
    vis[end_point] = 1;
    dfs(end_point, 0);
    //answer
    cout << len << "\n";
    return 0;
}