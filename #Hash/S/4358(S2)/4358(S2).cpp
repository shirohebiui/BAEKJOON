#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#include <vector>
#include <cstring>
#include <algorithm>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<string> v;
    string str;
    while(getline(cin, str)) {
        v.push_back(str);
    }
    char tmp[31]; memset(tmp, 0xFF, 31); v.push_back(tmp);
    sort(v.begin(), v.end());
    int all = v.size()-1;
    double cnt = 1;
    FOR(i, 0, all) {
        while(strcmp(&v[i][0], &v[i+1][0]) == 0) {
            ++cnt; ++i;
        }
        printf("%s %.4f\n", &v[i][0], cnt/all*100);
        cnt = 1;
    }
    return 0;
}