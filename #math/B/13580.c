#include <stdio.h>
#include <stdlib.h>

int main() {
    int a,b,c; scanf("%d %d %d", &a, &b, &c);
    char doit = 'N';
    if(
        abs(a-b) == 0 || abs(a-c) == 0 || abs(b-c) == 0 ||
        abs(a+b-c)==0 || abs(a+c-b)==0 || abs(b+c-a) == 0
        ) doit = 'S';
    printf("%c\n", doit);
    return 0;
}