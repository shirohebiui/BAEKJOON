#include <stdio.h>

int main()
{
    int x, n;
    int a,b;
    scanf("%d", &x);
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d", &a, &b);
        x-=a*b;
    }
    if(x==0)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}