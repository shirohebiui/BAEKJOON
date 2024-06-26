#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#include <vector>
#include <cstring>
#include <map>
struct Trie{
    map<string, Trie*> next;
    void insert(vector<string>& obj, int idx) {
        if (idx == obj.size()) return;
        
        if(next.find(obj[idx]) == next.end())
            next[obj[idx]] = new Trie();
        next[obj[idx]]->insert(obj, idx+1);
    }
    
    void find(int depth) {
        for(auto &now : next) {
            FOR(i, 0, depth) cout << "--";
            cout << now.first << "\n";
            now.second->find(depth+1);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    Trie *trie = new Trie();
    int n; cin >> n;
    while(n-->0) {
        int k; cin >> k;
        vector<string> str(k);
        while(k--) {
            cin >> str[k];
        }
        trie->insert(v, 0);
    }
    trie->find(0);
    return 0;
}