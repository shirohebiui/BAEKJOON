#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

int dp[10001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;

    int max_t = 0;
    FOR(i, 1, n+1) {
        int adj; cin >> dp[i] >> adj;
        int long_work_t = 0;
        while(adj-->0) {
            int v; cin >> v;
            long_work_t = max(long_work_t, dp[v]);
        }
        dp[i] += long_work_t;
        max_t = max(max_t, dp[i]);
    }
    cout << max_t << "\n";
    return 0;
}