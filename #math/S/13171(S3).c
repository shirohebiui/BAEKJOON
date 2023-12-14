#include <stdio.h>
#define mod 1000000007
typedef unsigned int u32;

void init_A(long a);
u32 A[65];
u32 find(long x);

int main() {
    long a, x; scanf("%ld %ld", &a, &x);
    init_A(a);
    printf("%d\n", find(x));
    return 0;
}

void init_A(long a) {
    A[1] = a%mod;
    for(int i=2; i<65; i++) {
        A[i] = ((long)A[i-1]* A[i-1] % mod);
        // printf("A[%d] = A^%d : %ld\n", i, 1<<(i-1), A[i]);
    }
}

u32 find(long x) {
    u32 exp = 1;
    u32 result = 1;
    while(x!=0) {
        if(x & 1) {
            // printf("A^%d : %ld\n", 1<<(exp-1), A[exp]);
            result = ((long)result * A[exp]) % mod;
        }
        x = x>>1;
        exp++;
    }
    return result;
}