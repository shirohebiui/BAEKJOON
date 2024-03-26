#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::map<std::string, int> h;
    std::vector<std::string> v;

    int n, m; std::cin >> n >> m;
    
    std::string str; 
    while(n--) {
        std::cin >> str;
        h[str]++;
    }
    while(m--) {
        std::cin >> str;
        if(h.find(str) != h.end()) {
            v.push_back(str);
        }
    }
    sort(v.begin(), v.end());
    std::cout << v.size() << "\n";
    for(int i=0; i<v.size(); i++) {
        std::cout << v[i] << "\n";
    }
    return 0;
}