#include <stdio.h>

int main()
{
    int a,b;
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", a+b);
    }
    return 0;
}