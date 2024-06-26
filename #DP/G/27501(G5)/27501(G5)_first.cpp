#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#include <vector>
#include <cstring>
#define R 0
#define G 1
#define B 2
#define MAX_VSIZE 500001
vector<int> Graph[MAX_VSIZE];
int dp[MAX_VSIZE][3];
int weight[MAX_VSIZE][3];

int vsize;
char vis[MAX_VSIZE];
int ret_adj_best_color(int vertex, int color) {
    if(dp[vertex][color] != 0) return dp[vertex][color];
    int r = color, g = (r+1)%3, b = (r+2)%3;
    dp[vertex][r] = weight[vertex][r];
    for(auto &adj:Graph[vertex]) {
        if(!vis[adj]) {
            vis[adj] = 1;
            dp[vertex][r] += max(ret_adj_best_color(adj, g), ret_adj_best_color(adj, b));
            vis[adj] = 0;
        }
    }
    return dp[vertex][r];
}

char print_color[MAX_VSIZE];
void dfs(int vertex, int color) {
    int r = color, g = (r+1)%3, b = (r+2)%3;
    print_color[vertex] = (dp[vertex][g] > dp[vertex][b] ? g : b);
    for(auto &adj:Graph[vertex]) {
        if(!vis[adj]) {
            vis[adj] = 1;
            dfs(adj, print_color[vertex]);
        }
    }
}

char Not_root[MAX_VSIZE];

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    //input
    cin >> vsize;
    FOR(i, 0, vsize-1) {
        int v, u; cin >> v >> u;
        Graph[v].push_back(u);
        Graph[u].push_back(v);
    }
    FOR(i, 1, vsize+1) {
        cin >> weight[i][R] >> weight[i][G] >> weight[i][B];
    }

    //func
    FOR(i, 0, 3) {
        vis[1] = 1;
        ret_adj_best_color(1, i);
        memset(vis, 0x00, sizeof(vis));
    }
    print_color[1] = (dp[1][R] > dp[1][G] ? R : G); print_color[1] = (dp[1][print_color[1]] > dp[1][B] ? print_color[1] : B);
    cout << dp[1][print_color[1]] << "\n";
    vis[1] = 1;
    for(auto &adj:Graph[1]) {
        vis[adj] = 1;
        dfs(adj, print_color[1]);
    }
    FOR(i, 1, vsize+1) {
        if(print_color[i] == R) cout << 'R';
        else if(print_color[i] == G) cout << 'G';
        else cout << 'B';
    }
    cout << "\n";

    return 0;
}