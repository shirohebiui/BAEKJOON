#include <stdio.h>

int main() {
    int c, k, p; scanf("%d %d %d", &c, &k, &p);
    int result = 0;
    for(int n=1; n<=c; n++) {
        result += k*n + p*n*n;
    }
    printf("%d\n", result);
    return 0;
}