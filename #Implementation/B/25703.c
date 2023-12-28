#include <stdio.h>

int main() {
    int N; scanf("%d", &N);
    printf("int a;\n");
    printf("int *ptr = &a;\n");
    if(N>=2)
        printf("int **ptr2 = &ptr;\n");
    if(N>=3)
    for(int i=2; i<N; i++) {
        printf("int ");
        for(int j=0; j<=i; j++) {
            printf("*");
        }
        printf("ptr%d = &ptr%d;\n",i+1, i);
    }
    return 0;
}