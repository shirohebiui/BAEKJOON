#include <stdio.h>

int main() {
    int N; scanf("%d", &N);
    unsigned int exp = 1;
    int R = 0;
    while(exp < N) exp = exp<<1;
    if(N & exp) R+=1;
    for(int i=1; exp>>i > 0; i++) {
        if(N & exp>>i) R += 1<<(i-1);
    }
    printf("%d\n", R);
    return 0;
}