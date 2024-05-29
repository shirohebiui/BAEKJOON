#include <stdio.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

int main() {
    int TestCase; scanf("%d", &TestCase);
    while(TestCase--) {
        int N; scanf(" %d", &N);
        int high = -1000000, low = 1000000;
        for(int i=0; i<N; i++) {
            int input; scanf(" %d", &input);
            high = max(high, input);
            low  = min(low, input);
        }
        printf("%d %d\n", low, high);
    }
    return 0;
}