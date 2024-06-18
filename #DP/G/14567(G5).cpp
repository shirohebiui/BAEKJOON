#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

int weight[1001];
#include <vector>
vector<vector<short>> G(1001);

int main() {
    //input
    int n, m; scanf("%d %d", &n, &m);
    while(m-->0) {
        short v, w; scanf(" %hd %hd", &v, &w);
        G[w].push_back(v);
    }
    FOR(i, 1, n+1) {
        weight[i] = 1;
        FOR(j, 0, G[i].size()) weight[i] = max(weight[i], 1+weight[G[i][j]]);
        printf("%d ", weight[i]);
    }
    printf("\n");
    return 0;
}