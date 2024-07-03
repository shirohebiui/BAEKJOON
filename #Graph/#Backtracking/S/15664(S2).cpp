#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#include <algorithm>
int n, m, arr[8], output[8];
bool vis[8];
void dfs(int idx, int depth) {
	if(m == depth) {
		FOR(i, 0, m) cout << output[i] << " ";
		cout << "\n";
		return;
	}
	FOR(i, idx, n) {
		if(vis[i]) continue;
		vis[i] = 1;
		output[depth] = arr[i];
		dfs(i+1, depth+1);
		vis[i] = 0;
		while(i+1<n && arr[i] == arr[i+1]) i++;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	FOR(i, 0, n) cin >> arr[i];
	sort(arr, arr+n);
	dfs(0, 0);
    return 0;
}