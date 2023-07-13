#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    for(int i=N;i!=0;i-=4)
        printf("long ");
    printf("int\n");
    return 0;
}