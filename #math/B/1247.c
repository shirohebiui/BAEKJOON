#include <stdio.h>

int main() {
    int TestCase = 3;
    while(TestCase--) {
        __int128_t sum = 0;
        int N; scanf("%d", &N);
        while(N--) {
            long long tmp; scanf(" %lld", &tmp);
            sum += tmp;
        }
        if(sum < 0) printf("-\n");
        else if(sum > 0) printf("+\n");
        else    printf("0\n");
    }
    return 0;
}