#include <stdio.h>

int main()
{
    //printf("echo\n");
    int A, B;
    scanf("%d %d", &A, &B);
    if(A < B) {
        int tmp = A;
        A = B;
        B = tmp;
    }
    int origin_A = A, origin_B = B;
    while(A % B != 0) {
        int tmp = A % B;
        A = B;
        B = tmp;
    }

    printf("%d\n", B);
    printf("%d\n", origin_A * (origin_B/B));


    return 0;
}