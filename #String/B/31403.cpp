#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#include <cstring>
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    char str[3][10];
    FOR(i, 0, 3) cin >> str[i];
    cout << atoi(str[0]) + atoi(str[1]) - atoi(str[2]) << "\n";
    cout << atoi(strcat(str[0], str[1])) - atoi(str[2]) << "\n";
    return 0;
}