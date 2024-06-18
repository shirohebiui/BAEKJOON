#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

int dp[1000][3];
int f(int n) {
    dp[0][0] = 0; dp[1][0] = 1;
    dp[0][1] = 0; dp[1][1] = 1;
    dp[0][2] = 1; dp[1][2] = 1;
    FOR(i, 2, n) {
        dp[i][0] = (dp[i-2][0] + dp[i-2][1] + dp[i-2][2])%10007;
        dp[i][1] = (dp[i-2][0] + dp[i-2][1] + dp[i-2][2])%10007;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])%10007;
    }
    return (dp[n-1][0] + dp[n-1][1] + dp[n-1][2])%10007;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    cout << f(n) << "\n";

    return 0;
}