#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)



/*
dp[now_node][R] = weight[now_node][R]
FOR(adj : 인접노드전부) {
    dp[now_node][R] += max(dp[adj][G], dp[adj][B])
}
*/

#include <vector>
#define R 0
#define G 1
#define B 2
#define MAX_VSIZE 500001
typedef char s8;
vector<int> Graph[MAX_VSIZE];
int dp[MAX_VSIZE][3], vsize;
short weight[MAX_VSIZE][3];

bool vis[MAX_VSIZE];
int ret_adj_best_color(int vertex, s8 color) {
    if(dp[vertex][color] != 0) return dp[vertex][color];
    s8 r = color, g = (r+1)%3, b = (r+2)%3;
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
void dfs(int vertex, s8 color) {
    s8 r = color, g = (r+1)%3, b = (r+2)%3;
    print_color[vertex] = (dp[vertex][g] > dp[vertex][b] ? g : b);
    for(auto &adj:Graph[vertex]) {
        if(!vis[adj]) {
            vis[adj] = 1;
            dfs(adj, print_color[vertex]);
        }
    }
}

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
    FOR(i, 1, vsize+1) cin >> weight[i][R] >> weight[i][G] >> weight[i][B];

    //func

    vis[1] = 1;
    FOR(i, 0, 3) ret_adj_best_color(1, i); //dp

    //root color fix
    print_color[1] = (dp[1][R] > dp[1][G] ? R : G); print_color[1] = (dp[1][print_color[1]] > dp[1][B] ? print_color[1] : B);
    cout << dp[1][print_color[1]] << "\n"; //answer_1

    //dfs color finding
    vis[1] = 1;
    for(auto &adj:Graph[1]) {
        vis[adj] = 1;
        dfs(adj, print_color[1]);
    }

    //answer_2
    FOR(i, 1, vsize+1) {
        if(print_color[i] == R) cout << 'R';
        else if(print_color[i] == G) cout << 'G';
        else cout << 'B';
    }
    cout << "\n";

    return 0;
}