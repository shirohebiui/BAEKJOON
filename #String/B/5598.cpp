#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

char str[1001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> str;
    char *ptr = str;
    while(*ptr != '\0') {
        *ptr -= 3;
        if(*ptr < 'A') *ptr += 26;
        ptr++;
    }
    cout << str;
    return 0;
}