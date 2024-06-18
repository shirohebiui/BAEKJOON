#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int tc; cin >> tc;
    while(tc --> 0) {
        string best_name; int best_cost = 0;
        int human_cnt; cin >> human_cnt;
        while(human_cnt --> 0) {
            string tmp; int cost;
            cin >> cost;
            if(cost > best_cost) {
                cin >> best_name;
                best_cost = cost;
            } else {
                cin >> tmp;
            }
        }
        cout << best_name << "\n";
    }
    return 0;
}