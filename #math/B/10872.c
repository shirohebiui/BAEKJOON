#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int res = 1;
    while(n) res *= n--;
    printf("%d\n", res);
    return 0;
}