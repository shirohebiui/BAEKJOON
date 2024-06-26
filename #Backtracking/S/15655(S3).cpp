#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)


#include <algorithm>
typedef short s16;
s16 n, m, arr[8], mem[8];
void print_arr() {
    FOR(i, 0, m) cout << mem[i] << " ";
    cout << "\n";
}
void dfs(s16 idx, s16 depth) {
    if(depth == m) {
        print_arr();
        return;
    }
    FOR(i, idx, n) {
        mem[depth] = arr[i];
        dfs(i+1, depth+1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    //input
    cin >> n >> m;
    FOR(i, 0, n) cin >> arr[i];
    sort(arr, arr+n);

    dfs(0, 0);
    return 0;
}