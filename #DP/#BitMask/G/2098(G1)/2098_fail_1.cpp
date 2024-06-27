#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#define MAX_VSIZE 16
char vis[MAX_VSIZE];
int G[MAX_VSIZE][MAX_VSIZE], vsize, weight, best = 1000000*16+1;

int start;
void dfs(int node, int depth) {
    if(depth == vsize && G[node][start] != 0) {
        best = min(best, weight + G[node][start]);
        return;
    }
    FOR(i, 0, vsize) {
        if(!vis[i] && G[node][i] != 0) {
            vis[i] = 1;
            weight += G[node][i];
            if(weight < best) dfs(i, depth+1);
            weight -= G[node][i];
            vis[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> vsize;
    FOR(i, 0, vsize) FOR(j, 0, vsize) cin >> G[i][j];
    for(;start < vsize; start++) {
        vis[start] = 1;
        dfs(start, 1);
        vis[start] = 0;
    }
    cout << best << "\n";
    return 0;
}