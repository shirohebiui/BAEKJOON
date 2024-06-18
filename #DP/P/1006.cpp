#include <iostream>
using namespace std;

#define INF 99999

int n[10001][2], nsize, w;
int dp[10001][5];
/*
case0   case1   case2   case3   case4
o|o     o o     o o     o|o     o|o
---     ---     ---     ---      | 
o|o     o o     o|o     o o     o|o
*/


int best;
void test();
void dpchk() {
    for(int i=2; i<=nsize; i++) {
        // 0~4 -> 0
        dp[i][0] = 2+min(dp[i-1][0], min(dp[i-1][1], min(dp[i-1][2], min(dp[i-1][3], dp[i-1][4]))));
        
        // 0 -> 1
        if(w>=n[i-1][0]+n[i][0] && w>=n[i-1][1]+n[i][1]) dp[i][1] = dp[i-1][0];
        else dp[i][1] = INF;
        // 0,3 -> 2
        if(w>=n[i-1][0]+n[i][0]) dp[i][2] = 1+ min(dp[i-1][0], dp[i-1][3]);
        else dp[i][2] = INF;
        // 0,2 -> 3
        if(w>=n[i-1][1]+n[i][1]) dp[i][3] = 1+ min(dp[i-1][0], dp[i-1][2]);
        else dp[i][3] = INF;
        // 0~4 -> 4
        if(w>=n[i][0]+n[i][1]) dp[i][4] = 1+ min(dp[i-1][0], min(dp[i-1][1], min(dp[i-1][2], min(dp[i-1][3], dp[i-1][4]))));
        else dp[i][4] = INF;
    }
    for(int i=0; i<5; i++) {
        best = min(best,dp[nsize][i]);
    }
    // test();
}
void func() {
    int tail_0 = n[nsize][0], tail_1 = n[nsize][1];
    // xo
    // xo
    n[0][0] = INF;
    n[0][1] = INF;
    dp[1][0] = 2;
    dp[1][1] = INF;
    dp[1][2] = INF;
    dp[1][3] = INF;
    dp[1][4] = ((w>=n[1][0]+n[1][1]) ? 1 : INF);
    dpchk();
    // oo
    // xo
    n[0][0] = tail_0; n[nsize][0] = INF;
    n[0][1] = INF;
    dp[1][0] = 2;
    dp[1][1] = INF;
    dp[1][2] = ((w>=n[0][0]+n[1][0]) ? 1 : INF);
    dp[1][3] = INF;
    dp[1][4] = ((w>=n[1][0]+n[1][1]) ? 1 : INF);
    dpchk();

    // xo
    // oo
    n[nsize][0] = tail_0; n[0][0] = INF;
    n[0][1] = tail_1; n[nsize][1] = INF;
    dp[1][0] = 2;
    dp[1][1] = INF;
    dp[1][2] = INF;
    dp[1][3] = ((w>=n[0][1]+n[1][1]) ? 1 : INF);
    dp[1][4] = ((w>=n[1][0]+n[1][1]) ? 1 : INF);
    dpchk();

    // oo
    // oo
    n[0][0] = tail_0; n[nsize][0] = INF;
    n[0][1] = tail_1; n[nsize][1] = INF;
    dp[1][0] = 2;
    dp[1][1] = ((w>=n[0][0]+n[1][0] && w>=n[0][1]+n[1][1]) ? 0 : INF);
    dp[1][2] = ((w>=n[0][0]+n[1][0]) ? 1 : INF);
    dp[1][3] = ((w>=n[0][1]+n[1][1]) ? 1 : INF);
    dp[1][4] = ((w>=n[1][0]+n[1][1]) ? 1 : INF);
    dpchk();
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int tc; cin >> tc;
    while(tc--) {
        cin >> nsize >> w;
        for(int i=1; i<=nsize; i++) cin >> n[i][0];
        for(int i=1; i<=nsize; i++) cin >> n[i][1];
        best = INF;
        func();
        cout << best << "\n";
    }
    return 0;
}
void test() {
    cout << "DP--------------\n";
    for(int s=0; s<5; s++) {
        for(int i=1; i<=nsize; i++) {
            if(dp[i][s] == INF) cout << "- ";
            else cout << dp[i][s] << " ";
        }
        cout << "\n";
    }
    cout << "N MAP--------------\n";

    for(int i=0; i<=nsize; i++) {
        if(n[i][0] == INF) cout << "INF ";
        else cout << n[i][0] << " ";
    }
    cout << "\n";
    for(int i=0; i<=nsize; i++) {
        if(n[i][1] == INF) cout << "INF ";
        else cout << n[i][1] << " ";
    }
    cout << "\n";
    cout << "\n";
    cout << "\n";
}