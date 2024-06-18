#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

int csize[6], n, t, p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    FOR(i, 0, 6) cin >> csize[i];
    cin >> t >> p;

    int ct = 0, cp = 0;
    FOR(i, 0, 6)  {
        ct += csize[i]/t + (csize[i]%t != 0);
        cp += csize[i];
    }
    cout << ct << "\n";
    cout << cp/p << " " << cp%p << "\n";
    return 0;
}