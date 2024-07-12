#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#include <algorithm>
int arr[8], output[8], vsize, len;
void dfs(int idx,  int depth) {
    if(depth == len) {
        FOR(i, 0, len) cout << output[i] << " ";
        cout << "\n";
        return;
    }
    FOR(i, idx, vsize) {
        output[depth] = arr[i];
        dfs(i, depth+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> vsize >> len;
    FOR(i, 0, vsize) cin >> arr[i];
    sort(arr, arr+vsize);
    dfs(0, 0);
    return 0;
}