#include <stdio.h>
#define min(a,b) (a<b?a:b)
typedef unsigned long long u64;

u64 n, k;
u64 mem;

u64 answer(u64 low, u64 high) {
    if(low > high) return 0;
    u64 cnt = 0;
    u64 mid = (low+high)/2;
    for(int i=1; i<=n; i++) {
        cnt += min(n, mid/i);
        if(i > mid) break;
    }
    if(cnt < k) return answer(mid+1, high);
    mem = mid;
    return answer(low, mid-1);
}

int main() {
    scanf(" %lld %lld", &n, &k);
    answer(1, n*n);
    printf("%lld\n", mem);
    return 0;
}