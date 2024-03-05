#include <stdio.h>

long pow(int x, int n) {
    long res = 1;
    while(n--) res *= x;
    return res;
}

int main() {
    while(1) {
        int b, n; scanf("%d %d", &b, &n);
        if(b+n == 0) return 0;
        int a = 1;
        while(pow(a,n) < b) a++;
        printf("%d\n", (b-pow(a-1,n) > pow(a,n) - b ? a : a-1));
    }
    return 0;
}
