#include <stdio.h>
#define swap(a,b) (a^=b^=a^=b)

int main() {
    int n[3]; scanf("%d %d %d", &n[0], &n[1], &n[2]);
    if(n[0] > n[1]) swap(n[0], n[1]);
    if(n[0] > n[2]) swap(n[0], n[2]);
    if(n[1] > n[2]) swap(n[1], n[2]);
    char c[3]; scanf(" %c %c %c", &c[0], &c[1], &c[2]);
    printf("%d %d %d\n", n[c[0]-'A'], n[c[1]-'A'], n[c[2]-'A']);
    return 0;
}