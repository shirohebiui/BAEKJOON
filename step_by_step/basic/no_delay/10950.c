#include <stdio.h>

int main()
{
    int a,b;
    int k;
    scanf("%d", &k);
    for(int i=0;i<k;i++)
    {
    scanf("%d %d", &a, &b);
    printf("%d\n", a+b);

    }
    return 0;
}