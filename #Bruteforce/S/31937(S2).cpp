#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

char endstat[1001];
char stat[1001];

#include <vector>
struct msg{
    int time, start, end;
};
bool cmp_msg_time(const msg& a, const msg& b) {
    return a.time < b.time;
}
vector<msg> log;
vector<int> infect_pc;

#include <cstring>
int isOrigin(int origin) {
    memset(stat, 0x00, sizeof(stat));
    stat[origin] = 1;
    // cout << "\ntest origin : " << origin << "\n";
    for(const auto& s:log) {
        // cout << s.time << ": " << s.start << "->" << s.end << "\n";
        if(stat[s.start] == 1) {
            if(endstat[s.end] == 0) return 0;
            stat[s.end] = 1;
        }
    }
    return 1;
}

int statcmp(int cnt) {
    FOR(i, 1, cnt+1) {
        if(stat[i] != endstat[i]) return 0;
    }
    return 1;
}

#include <algorithm>
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    //input
    int pc_cnt, msg_cnt, infect_cnt;
    cin >> pc_cnt >> msg_cnt >> infect_cnt;
    FOR(i, 0, infect_cnt) {
        int num; cin >> num;
        endstat[num] = 1;
        infect_pc.push_back(num);
    }
    FOR(i, 0, msg_cnt) {
        int t, v, u; cin >> t >> v >> u;
        log.push_back({t, v, u});
    }
    //msg sorting order by time
    sort(log.begin(), log.end(), cmp_msg_time);

    //find
    for(const auto& pc:infect_pc) {
        if(isOrigin(pc) && statcmp(pc_cnt)) {
            cout << pc << "\n";
            return 0;
        }
    }
    return 0;
}