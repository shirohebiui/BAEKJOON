#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

struct book{
    char *name; int cnt;
};
#include <vector>
#define PRIME 5381
vector< vector<book> > v(PRIME);
int strhash(char *str) {
    char *c = str;
    int p = PRIME;
    int mod = 100000;

    int hash_val = 0;
    int pow_p = 1;

    while(*c != '\0') {
        hash_val += (*c - 0x40) * p; //대문자0x60 소문자0x40
        hash_val %= mod;
        p *= PRIME; p %= mod;
        c++;
    }
    return hash_val % PRIME;
}

#include <cstring>
#include <cstdlib>
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int sale_book_cnt; cin >> sale_book_cnt;
    char str[51];
    while(sale_book_cnt--) {
        cin >> str;
        int key = strhash(str);
        int flag = 1;
        FOR(i, 0, v[key].size()) {
            if( strcmp(v[key][i].name, str) == 0) {
                v[key][i].cnt++;
                flag = 0;
                break;
            }
        }
        if(flag) {
            char *s = (char *)malloc(strlen(str)+1);
            memmove(s, str, strlen(str)+1);
            v[key].push_back({s, 0});
        }
    }
    char best_book[51]; memmove(best_book, str, strlen(str));
    int best_sale_cnt = -1;
    FOR(i, 0, PRIME) {
        FOR(j, 0, v[i].size()) {
            if(v[i][j].cnt > best_sale_cnt) {
                best_sale_cnt = v[i][j].cnt;
                memmove(best_book, v[i][j].name, 51);
            } else if(v[i][j].cnt == best_sale_cnt) {
                if(strcmp(best_book, v[i][j].name) > 0) memmove(best_book, v[i][j].name, 51);
                else if(strcmp(best_book, v[i][j].name) == 0) {
                    if(strlen(best_book) > strlen(v[i][j].name)) memmove(best_book, v[i][j].name, 51);
                }
            }
        }
    }
    cout << best_book << "\n";
    return 0;
}