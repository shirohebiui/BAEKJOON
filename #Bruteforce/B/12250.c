#include <stdio.h>
#include <string.h>

int arr[1001];

int main() {
    int tc; scanf("%d", &tc);
    for(int round = 1; round <= tc; round++){
        int a, b, k; scanf(" %d %d %d", &a, &b, &k);
        memset(arr, 0x00, sizeof((a>b?a:b)*4));
        for(int i=0; i<a; i++) {
            for(int j=0; j<b; j++) {
                arr[i&j]++;
            }
        }
        while(k > 1) arr[0] += arr[--k];
        printf("Case #%d: %d\n", round, arr[0]);
    }
    return 0;
}
