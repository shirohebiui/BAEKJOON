#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#include <map>
map<string, int> m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int sale_book_cnt; cin >> sale_book_cnt;
    string str;
    while(sale_book_cnt--) {
        cin >> str;
        m[str]++;
    }
    int best = 0;
    for (const auto& pair : m) {
        if(pair.second > best) {
            str = pair.first;
            best = pair.second;
        } else if(pair.second == best) {
            if(str.compare(pair.first) > 0) {
                str = pair.first;
            }
        }
    }
    cout << str << "\n";
    return 0;
}