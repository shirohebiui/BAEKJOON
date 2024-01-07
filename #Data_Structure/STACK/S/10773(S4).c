#include <stdio.h>
int stack[100001], top = 1;

int main() {
    int TestCase; scanf(" %d", &TestCase);
    while(TestCase--) {
        int in; scanf(" %d", &in);
        if(in == 0) top--;
        else stack[top++] = in;
    }
    int sum = 0;
    for(int i=0; i<top; i++) sum += stack[i];
    printf("%d\n", sum);
    return 0;
}