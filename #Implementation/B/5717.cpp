#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while(1) {
        int m, f; cin >> m >> f;
        if(!(m&&f)) return 0;
        cout << m+f << "\n";
    }
    return 0;
}