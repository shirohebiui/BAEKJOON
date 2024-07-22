#include <iostream>
using namespace std;
#define FOR(val, s, e) for(int val=(s); val<(e); val++)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int main() {
    FAST_IO
    int a, b; cin >>a;
    cin >> b; a = min(a,b);
    cin >> b; a = min(a,b);
    int c, d; cin >> c;
    cin >> d; c = min(c,d);
    cout << a+c-50 << '\n';
    return 0;
}