#include <stdio.h>

int find(int n);

int main() {
    int TestCase; scanf(" %d", &TestCase);
    while(TestCase--) {
        int cnt; scanf(" %d", &cnt);
        printf("%d\n", find(cnt));
    }
    return 0;
}

int find(int n) {
    int exp = 1;
    for(int i=0; i<n; i++) {
        exp = exp<<1;
    }
    return exp-1;
}