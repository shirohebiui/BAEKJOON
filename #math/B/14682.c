#include <stdio.h>

int main() {
    int n, t; scanf("%d %d", &n, &t);
    unsigned long sum = n;
    while(t--) {
        n *= 10;
        sum += n;
    }
    printf("%ld\n", sum);
    return 0;
}