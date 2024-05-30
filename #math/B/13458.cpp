#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    long long n, a[1000001] = {0,}, b, c;
    long long ans = 0;
    cin >> n;
    while(n--) {
        cin >> a[n];
    }
    cin >> b >> c;
    while(a[++n]) {
        a[n] -= b; ans++;
        if(a[n] <= 0) continue;
        ans += a[n]/c;
        if(a[n]%c) ans++;
    }
    cout << ans << "\n";
    return 0;
}