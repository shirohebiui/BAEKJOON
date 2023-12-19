#include <stdio.h>
#define mod 1000000007

long mem[1000001];

int main() {
    mem[0] = 0;
    mem[1] = 1;
    mem[2] = 1;
    int find; scanf("%d", &find);
    for(int i=0; i<find; i++) {
        mem[i+2] = (mem[i+1] + mem[i])%mod;
        if(i+2 == find) break;
    }
    printf("%ld\n", mem[find]);
    return 0;
}