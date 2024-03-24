#include <iostream>
using namespace std;
typedef unsigned long  u32;

int main() {
    u32 n, k; cin >> n >> k;
    if(k>=n) {
        cout << 0 << endl;
        return 0;
    }

    u32 tmp = n, bit, cnt = k+1;
    while(cnt > k) {
        bit = 1; bit = bit<<31; cnt = 0;
        while(bit) {
            if(bit & tmp) cnt++;
            bit = bit >> 1;
        }
        tmp++;
    }
    cout << tmp-n-1 << endl;
    return 0;
}