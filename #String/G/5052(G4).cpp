#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#include <vector>
#include <cstring>
#include <algorithm>
struct Trie{
    bool end;
    Trie *next[10];
    //생성자
    Trie() : end(false) {
        memset(next, 0x00, sizeof(next));
    }

    void insert(const char *key) {
        Trie *now = this;
        while(*key != '\0') {
            int cur = *key - '0';
            if(now->next[cur] == NULL) now->next[cur] = new Trie();
            now = now->next[cur];
            key++;
        }
        now->end = 1;
        // if(*key == '\0') end = 1;
        // else {
        //     Trie *now = this;
        //     int cur = *key - '0';
        //     if(next[cur] == NULL) next[cur] = new Trie();
        //     next[cur]->insert(key+1);
        // }
    }

    //트라이에서 문자열 찾기
    bool find(const char *key) {
        if(*key == '\0') return true; //문자열 끝나는 위치 반환
        if(end == true) return false;
        int curr = *key - '0';
        if(next[curr] == NULL) return true;
        return next[curr]->find(key+1);
    }
    bool isValid(const char *key) {
        Trie *now = this;
        while(*key != '\0') {
            int cur = *key - '0';
            if(now->end == true) return false;
            if(now->next[cur] != NULL) now = now->next[cur];
            else return true;
            key++;
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc; cin >> tc;
    while(tc --> 0) {
        Trie *trie = new Trie();
        int n; cin >> n;
        vector<string> s(n);
        while(n --> 0) cin >> s[n];
        sort(s.begin(), s.end());
        
        bool flag = 1;
        for(const auto &i : s) {
            if(trie->isValid(i.c_str())) trie->insert(i.c_str());
            else {
                flag = 0; break;
            }
        }
        cout << (flag?"YES":"NO") << "\n";
    }
    return 0;
}