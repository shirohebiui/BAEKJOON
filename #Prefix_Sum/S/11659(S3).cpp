#include <iostream>
using namespace std;
int sum[100001];

int main() {
    int n, k; scanf(" %d %d", &n, &k);
    for(int i=1; i<=n; i++) {
        scanf(" %d", &sum[i]);
        sum[i] += sum[i-1];
    }
    while(k--) {
        int start, end; scanf(" %d %d", &start, &end);
        printf("%d\n", sum[end]-sum[start-1]);
    }
    return 0;
}