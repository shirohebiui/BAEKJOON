#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#include <cmath>
#include <iomanip>
#define MaxV 16 //MAX VSIZE
#define INF 0x7F7F7F7F
int vsize;
float cost[MaxV][MaxV], dp[MaxV][1<<16];

int all_vis;
float TSP(int now, int mask) {
    if(dp[now][mask]) return dp[now][mask];
    if(mask == all_vis) {
        if(cost[now][0]) return cost[now][0];
        else return INF;
    }
    float ret = INF;
    FOR(i, 0, vsize) {
        if(cost[now][i] && !(mask&(1<<i))) {
            ret = min(ret, TSP(i, mask|(1<<i)) + cost[now][i]);
        }
    }
    return dp[now][mask] = ret;
}
struct pos{int y, x;};
#define dist(p1, p2) sqrt(abs(p1.y-p2.y)*abs(p1.y-p2.y) + abs(p1.x-p2.x)*abs(p1.x-p2.x))
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> vsize;
    all_vis = (1<<vsize) - 1;
    pos p[MaxV];
    FOR(i, 0, vsize) {
        cin >> p[i].x >> p[i].y;
    }
    FOR(i, 0, vsize) {
        FOR(j, i, vsize) {
            cost[i][j] = cost[j][i] = dist(p[i], p[j]);
        }
    }
    cout << fixed << setprecision(7) << TSP(0,1) << "\n";
    return 0;
}