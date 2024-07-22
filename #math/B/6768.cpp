#include <iostream>
using namespace std;
#define FOR(val, s, e) for(int val=(s); val<(e); val++)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


int main() {
    FAST_IO
    int n; cin >> n;
    if(n < 4) {cout << 0 << '\n'; return 0;}
    cout << ((n-1)*(n-2)*(n-3))/(3*2) << '\n';
    return 0;
}