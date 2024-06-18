#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#include <cstring>
char mem[150];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int group_word = 0;

    int tc; cin >> tc;
    while(tc--) {
        memset(mem, 0x00, sizeof(mem));
        char str[101]; cin >> str;
        char *ptr = str;

        ++group_word;
        while(*ptr != '\0') {
            if(!mem[*ptr]) {
                mem[*ptr] = 1;
                while(*ptr == *(ptr+1)) ptr++;
                ptr++;
            } else {
                --group_word;
                break;
            }
        }
    }
    cout << group_word << "\n";
    return 0;
}