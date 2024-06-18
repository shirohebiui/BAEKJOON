#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)
#define MAX 1005

unsigned char mem[MAX][3];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    if(n <= 2) {
        cout << 1 << "\n"; return 0;
    }
    mem[0][0] = 1; mem[0][1] = 1;
    int s1 = -1, s2 = 0, res = 1;
    FOR(k, 2, n) {
        s1 = (++s1) %3;
        s2 = (++s2) %3;
        res= (++res)%3;
        mem[0][res] = mem[0][s1] + mem[0][s2];
        FOR(i, 1, MAX) {
            mem[i][res] = mem[i][s1] + mem[i][s2];
            mem[i][res] += mem[i-1][res]/10;
            mem[i-1][res] %= 10;
        }
    }
    int i = MAX -1;
    while(mem[i][res] == 0) --i;
    while(i) cout << (int)mem[i--][res];
    cout << (int)mem[0][res] << "\n";
    return 0;
}