#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    char s[3][9];
    cin >> s[0] >> s[1] >> s[2];
    int result;
    FOR(i, 0, 3) {
        if('0' <= s[i][0] && s[i][0] <= '9') {
            result = atoi(s[i]) + 3-i;
        }
    }
    if(result % 3 == 0) {
        if(result % 5 == 0) cout << "FizzBuzz\n";
        else cout << "Fizz\n";
    } else {
        if(result % 5 == 0) cout << "Buzz\n";
        else cout << result << "\n";
    }
    return 0;
}