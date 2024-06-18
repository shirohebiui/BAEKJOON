#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

struct node{
    short v; char cost;
};
#include <vector>
vector<vector<node> > G(10001); int vsize;

char vis[10001];
int dist[10001];
int best;
#include <queue>
void bfs(short node) {
    queue<short> q;
    q.push(node);
    while(!q.empty()) {
        int now = q.front();
        FOR(i, 0, G[now].size()) {
            int adj = G[now][i].v;
            if(!vis[adj]) {
                vis[adj] = 1;
                dist[adj] += dist[now] + G[now][i].cost;
                if(G[adj].size() != 1) q.push(adj);
            }
        }
        q.pop();
    }
}

#include <cstring>
vector<short> lnode; //leaf node
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //input
    cin >> vsize;
    FOR(i, 0, vsize-1) {
        int v, u, cost; cin >> v >> u >> cost;
        G[v].push_back({(short)(u), (char)cost});
        G[u].push_back({(short)(v), (char)cost});
    }

    //select leaf node
    FOR(i, 1, vsize+1) {
        // cout << "v : " << i << ", adj : " << G[i].size() << "\n";
        if(G[i].size() == 1) lnode.push_back(i);
    }

    //find best
    FOR(i, 0, lnode.size()) {
        memset(dist, 0x00, sizeof(dist));
        memset(vis, 0x00, sizeof(vis));
        vis[lnode[i]] = 1;
        bfs(lnode[i]);
        // cout << "dist :" << lnode[i] << "\n";
        // FOR(k, 0, vsize+1) {
        //     cout << dist[k] << " ";
        // }
        // cout << "\n";
        FOR(j, 0, lnode.size()) {
            best = max(dist[lnode[j]], best);
        }
    }

    //answer
    cout << best << "\n";
    return 0;
}