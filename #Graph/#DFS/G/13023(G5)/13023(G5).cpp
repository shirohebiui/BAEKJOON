#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#define MAX_VSIZE 2001
int parent[MAX_VSIZE], vsize, esize;
bool FLAG;
#include <vector>
vector<vector<int> > G(MAX_VSIZE);
bool vis[MAX_VSIZE];
void dfs(int vertex, int cnt) {
    if(FLAG) return;
    if(cnt == 5) {
        FLAG = 1; return;
    }
    FOR(i, 0, G[vertex].size()) {
        if(!vis[G[vertex][i]]) {
            vis[G[vertex][i]] = 1;
            dfs(G[vertex][i], cnt+1);
            vis[G[vertex][i]] = 0;
        }
    }
}

#include <cstring>
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int esize; cin >> vsize >> esize;
    while(esize--) {
        int v, u; cin >> v >> u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    FOR(i, 0, vsize) {
        vis[i] = 1;
        dfs(i, 1);
        vis[i] = 0;
        if(FLAG) break;
    }
    cout << FLAG << "\n";
    return 0;
}