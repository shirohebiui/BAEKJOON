#include <stdio.h>

int main() {
    int TestCase; scanf("%d", &TestCase);
    while(TestCase--) {
        int A, B; scanf(" %d %d", &A, &B);
        int edge = 1;
        while(A>B*edge) edge++;
        printf("%ld\n", (long)edge*edge);
    }

    return 0;
}