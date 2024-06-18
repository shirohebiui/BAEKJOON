#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#include <cstring>
char cmd[201];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> cmd;
    int pos = 0;
    FOR(i, 0, strlen(cmd)) {
        if('A' <= cmd[i] && cmd[i] <= 'Z') while( (i+pos)%4 != 0 ) pos++;
    }
    cout << pos << "\n";
    return 0;
}