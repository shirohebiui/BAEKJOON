#include <iostream>
using namespace std;

#include <algorithm>

int n, m;
int input[8];
char output[8];
char cnt[10000];
char BeUsed[8];
char vis[8][8][8][8][8][8][8][8];
void dfs(int c) {
    if(c == m) {
        if(vis[output[0]][output[1]][output[2]][output[3]][output[4]][output[5]][output[6]][output[7]]) return;
        vis[output[0]][output[1]][output[2]][output[3]][output[4]][output[5]][output[6]][output[7]] = 1;

        for(int i=0; i<m-1; i++) {
            cout << input[output[i]] << " ";
        }
        cout << input[output[m-1]] << "\n";
        return;
    }
    for(int i=0; i<n; i++) {
        if(BeUsed[i] < cnt[input[i]]) {
            BeUsed[i]++;
            output[c] = i;
            dfs(c+1);
            BeUsed[i]--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    int c = 0;
    for(int i=0; i<n; i++) {
        int in; cin >> in;
        if(cnt[in] == 0) input[c++] = in;
        cnt[in]++;
    }
    n = c;
    sort(input, input+n);
    dfs(0);
    return 0;
}