#include <iostream>
#include <algorithm>
#include <vector>

typedef struct otime {
    int start, end;
}otime;

bool cmp(otime &s1, otime &s2) {
    if(s1.end < s2.end) return 1;
    if(s1.end == s2.end && s1.start < s2.start) return 1;
    return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int n; std::cin >> n;
    std::vector<otime> v;
    otime s;
    for(int i=0; i<n; i++) {
        std::cin >> s.start >>s.end;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<n; i++) {
        std::cout << v[i].start << " " << v[i].end << "\n";
    }
    int end = v[0].end;
    int cnt = 0;
    for(int i=1; i<n; i++) {
        if(end <= v[i].start) {
            cnt++;
            end = v[i].end;
        }
    }
    std::cout << cnt+1 << "\n";
    
    return 0;
}