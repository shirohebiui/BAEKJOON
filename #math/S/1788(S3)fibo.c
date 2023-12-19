#include <stdio.h>
#include <stdlib.h>
#define mod 1000000000

unsigned long mem[1000001];

int main() {
    int n; scanf("%d", &n);
    int flag;
    if(n>0) flag = 1;
    else if(n==0) flag = 0;
    else if(abs(n)%2 == 0) flag = -1;

    mem[1] = 1;
    for(int i=0; i<abs(n); i++) {
        mem[i+2] = (mem[i] + mem[i+1])%mod;
        if(i+2 == n) break;
    }
    printf("%d\n%ld\n", flag, mem[abs(n)]);
    return 0;
}