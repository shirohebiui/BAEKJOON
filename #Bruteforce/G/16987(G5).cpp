#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#define mvs 300 //MAX VSIZE
typedef short s16;
s16 guard[mvs], weight[mvs], vsize, best;
void dfs(s16 idx, s16 broken) {
    // cout << idx << "\n";
    best = max(best, broken);
    if(idx >= vsize) return;
    if(guard[idx] <= 0) {
        dfs(idx+1, broken);
        return;
    }

    FOR(i, 0, vsize) {
        if(i == idx) continue;
        if(guard[i] > 0) {
            guard[i] -= weight[idx];
            guard[idx] -= weight[i];
            dfs(idx+1, (broken + (guard[i] <=0) + (guard[idx] <=0)));
            guard[i] += weight[idx];
            guard[idx] += weight[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //input
    cin >> vsize;
    FOR(i, 0, vsize) {
        cin >> guard[i] >> weight[i];
    }
    dfs(0, 0);
    cout << best << "\n";

    return 0;
}