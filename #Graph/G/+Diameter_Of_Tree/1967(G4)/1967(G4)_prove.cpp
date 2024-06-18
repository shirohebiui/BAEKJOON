#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)
/*
u-v가 지름일 경우
x에서 가장 먼 정점이 u, v가 나올것이고
u->v 혹은 v->u방향으로 dfs를 돌려서 지름을 구할 수 있음.
*/
struct node{
    short v; char cost;
};
#include <vector>
vector<vector<node> > G(10001); int vsize;

char vis[10001];
short end_point;
int len;
void dfs(short now, int dist) {
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
    vis[1] = 1;
    dfs(1, 0);
    memset(vis, 0x00, sizeof(vis));
    vis[end_point] = 1;
    dfs(end_point, 0);
    //answer
    cout << len << "\n";
    return 0;
}