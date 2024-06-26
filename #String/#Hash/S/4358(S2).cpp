#include <iostream>
#include <cstdio>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#include <map>
#include <cstring>
#include <algorithm>

int main() {
    map<string, int> m;
    string str;
    double range = 0;
    while(getline(cin, str)) {
        ++range;
        ++m[str];
    }
    for(auto &p:m) {
        printf("%s %.4f\n", p.first.c_str(), p.second/range*100);
    }
    return 0;
}