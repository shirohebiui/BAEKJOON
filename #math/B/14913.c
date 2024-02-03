#include <stdio.h>

int main() {
    int a, d, k; scanf("%d %d %d", &a, &d, &k);
    int n=0;
    if(a<k && d<=0) printf("X\n");
    else if(a>k && d>=0) printf("X\n");
    else if((k-a)%d == 0) printf("%d\n", 1+(k-a)/d);
    else printf("X\n");
    return 0;
}