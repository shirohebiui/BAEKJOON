#include <stdio.h>
#define MAX 21
int in[MAX];
char vis[MAX];

long long fact[MAX];
void init_factorial() {
    fact[0] = 1;
    for(int i=1; i<MAX; i++) {
        fact[i] = fact[i-1] * i;
    }
}

int main() {
    init_factorial();
    int n; scanf(" %d", &n);
    int mod; scanf(" %d", &mod);
    int x = n;
    int i;
    if(mod == 1) {
        long long seq; scanf(" %lld", &seq);
        while(x--) {
            for(i=1; i<=n; i++) {
                if(fact[x] >= seq) break;
                if(!vis[i]) {
                    seq -= fact[x];
                }
            }
            while(vis[i]) i++;
            vis[i] = 1;
            printf("%d ", i);
        }
        printf("\n");
    } else {
        for(int i=0; i<n; i++) scanf(" %d", &in[i]);
        long long sum = 0;
        int mul;
        for(i=0; i<n ;i++) {
            vis[in[i]] = 1;
            mul = 0;
            for(int j=1; j<in[i]; j++) if(!vis[j]) mul++;
            sum += mul * fact[--x];
        }
        printf("%lld\n", sum+1);
    }
    return 0;
}