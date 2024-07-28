#include <iostream>
using namespace std;
#define FOR(val, s_v, e_v) for(int val=(s_v); val<(e_v); val++)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int a1[100][100];
int main() {
    FAST_IO
    int n, m; cin >> n >> m;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin >> a1[i][j];
        }
    }
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            int tmp; cin >> tmp;
            cout << a1[i][j] + tmp << " ";
        }
        cout << '\n';
    }
    return 0;
}
