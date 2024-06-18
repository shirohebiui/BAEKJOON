#include <iostream>
using namespace std;

short dp[3][2];
short f(int n) {
    dp[0][0] = 0; dp[1][0] = 2;
    dp[0][1] = 1; dp[1][1] = 1;
    int a=2, b=1, c=0;
    while(n-->0) {
        dp[a][0] = (dp[c][0] + dp[c][1])*2%10007;
        dp[a][1] = (dp[b][0] + dp[b][1])%10007;
        a = (a+1)%3; b = (b+1)%3; c = (c+1)%3;
    }
    return (dp[a][0] + dp[a][1])%10007;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    cout << f(n) << "\n";

    return 0;
}