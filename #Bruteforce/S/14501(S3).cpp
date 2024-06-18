#include <iostream>
using namespace std;

int n, best;
int t[15], p[15];
void func(int idx, int cost) {
    if(idx > n) return;
    best = max(best, cost);
    if(idx == n) return;
    
    func(idx + t[idx], cost + p[idx]);
    func(idx + 1, cost);
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++) cin >> t[i] >> p[i];
    func(0, 0);
    cout << best << "\n";
    return 0;
}