#include <iostream>
using namespace std;
typedef unsigned long  u32;
u32 sum[100001];

int main() {
    int n, k; scanf(" %d %d", &n, &k);
    for(int i=1; i<=n; i++) {
        scanf(" %ld", &sum[i]);
        sum[i] += sum[i-1];
    }
    while(k--) {
        int start, end; scanf(" %d %d", &start, &end);
        printf("%ld\n", sum[end]-sum[start-1]);
    }
    return 0;
}