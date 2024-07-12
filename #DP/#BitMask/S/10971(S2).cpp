#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#define MaxV 16 //MAX VSIZE
#define INF 0x7F7F7F7F
int vsize, cost[MaxV][MaxV], dp[MaxV][1<<16];

int all_vis;
int TSP(int now, int mask) {
    if(dp[now][mask]) return dp[now][mask];
    if(mask == all_vis) {
        if(cost[now][0]) return cost[now][0];
        else return INF;
    }
    int ret = INF;
    FOR(i, 0, vsize) {
        if(cost[now][i] && !(mask&(1<<i))) {
            ret = min(ret, TSP(i, mask|(1<<i)) + cost[now][i]);
        }
    }
    return dp[now][mask] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> vsize;
    all_vis = (1<<vsize) - 1;
    FOR(i, 0, vsize) {
        FOR(j, 0, vsize) {
            cin >> cost[i][j];
        }
    }
    cout << TSP(0,1) << "\n";
    return 0;
}