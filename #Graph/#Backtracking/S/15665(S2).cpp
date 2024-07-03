#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#include <algorithm>
int n, m, arr[8], output[8];
bool vis[8][8];
void dfs(int idx, int depth) {
	if(m == depth) {
		FOR(i, 0, m) cout << output[i] << " ";
		cout << "\n";
		return;
	}
	FOR(i, 0, n) {
		if(vis[depth][i]) continue;
		vis[depth][i] = 1;
		output[depth] = arr[i];
		dfs(i, depth+1);
		vis[depth][i] = 0;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	FOR(i, 0, n) {
		cin >> arr[i];
		FOR(j, 0, n) {
			if(i==j) continue;
			if(arr[i] == arr[j]) {
				--n; --i;
				break;
			}
		}
	}
	sort(arr, arr+n);
	dfs(0, 0);
    return 0;
}