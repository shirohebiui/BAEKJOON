#include <stdio.h>
#include <stdlib.h>

int main() {
    int TestCase; scanf("%d", &TestCase);
    while(TestCase--) {
        int input; scanf("%d", &input);
        if(abs(input)%2 == 0) printf("%d is even\n", input);
        else                  printf("%d is odd\n", input);
    }
    return 0;
}