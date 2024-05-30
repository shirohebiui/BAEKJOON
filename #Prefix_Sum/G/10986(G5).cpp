#include <iostream>
typedef unsigned long u32;
int rem[1001];

u32 nC2(u32 n) {
    if(n==2) return 1;
    return n*(n-1)/2;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int n, m; std::cin >> n >> m;
    int in, psum = 0;
    while(n--) {
        std::cin >> in;
        psum = (in+psum)%m;
        rem[psum]++;
    }

    u32 cnt = rem[0];
    while(m--) {
        if(rem[m] >= 2) {
            cnt += nC2(rem[m]);
        }
    }
    std::cout << cnt << "\n";
    return 0;
}