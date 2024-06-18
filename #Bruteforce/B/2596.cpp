#include <iostream>
#include <cstring>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

int b[6] = {1, 2, 4, 8, 16, 32};

char sign_c[8][8] = {
    {"000000A"},
    {"001111B"},
    {"010011C"},
    {"011100D"},
    {"100110E"},
    {"101001F"},
    {"110101G"},
    {"111010H"}
};
char gap[8];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int words; cin >> words;
    char msg[6*10 + 1]; cin >> msg; char *ptr = msg;
    char answer[11]; int idx = 0;
    while(*ptr != '\0') {
        memset(gap, 0x00, sizeof(gap));
        FOR(s, 0, 8) {
            FOR(i, 0, 6) {
                gap[s] += abs(sign_c[s][i] - *(ptr+i));
            }
        }
        bool flag = 1;
        FOR(s, 0, 8) {
            if(gap[s] <= 1) {
                answer[idx++] = sign_c[s][6];
                flag = 0;
                break;
            }
        }
        if(flag) {
            cout << idx+1 << "\n";
            return 0;
        }
        ptr += 6;
    }
    answer[idx] = '\0';
    cout << answer << "\n";
    return 0;
}