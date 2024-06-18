#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

int arr[9];
bool flag;
bool vis[9];
static inline int sum() {
    int res = 0;
    FOR(i, 0, 9) if(vis[i]) res += arr[i];
    return res;
}
void dfs(int idx, int cnt) {
    if(flag) return;
    if(cnt == 7) {
        if(sum() == 100) {
            FOR(i, 0, 9) if(vis[i]) cout << arr[i] << "\n";
            flag = 1; return;
        }
    }
    FOR(i, idx, 9) {
        if(!vis[i]) {
            vis[i] = 1;
            dfs(i+1, cnt+1);
            vis[i] = 0;
        }
    }
}

#include <algorithm>
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    FOR(i, 0, 9) cin >> arr[i];
    sort(arr, arr+9);
    dfs(0, 0);
    
    return 0;
}