#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); val++)
#define FAST_IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

int cmp(const int &s1, const int &s2) {
    return s1 > s2;
}

int main() {
    FAST_IO
    int arr[1000000], n, m;
    cin >> n >> m;
    FOR(i, 0, n) {
        cin >> arr[i];
    }
    sort(arr, arr+n, cmp);

    int len = 0, cnt = 0, idx = 0, h = arr[0];
    while(len < m) {
        h--;
        while(arr[idx] > h) {
            cnt++; idx++;
        }
        len += cnt;
    }
    cout << h << '\n';
    return 0;
}