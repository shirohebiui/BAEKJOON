#include <stdio.h>
#define mod 1234567891

long _pow(int n, int x){
    long res = 1;
    while(x--) {
        res *= n;
        res %= mod;
    }
    return res;
}

int main() {
    int len; scanf("%d", &len);
    char str[51]; scanf("%s", str);
    int sum = 0;
    for(int i=0; i<len; i++) {
        sum = (sum+(str[i]-0x60)*_pow(31,i))%mod;
    }
    printf("%d\n", sum%mod);
    return 0;
}