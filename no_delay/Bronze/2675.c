#include <stdio.h>

int main()
{
    char s[21];
    char p[20*9];
    int count, loof;
    scanf("%d", &count);
    for(int c=0;c<count;c++)
    {
        scanf("%d %s", &loof, &s);
        int size = sizeof(s);
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<loof;j++)
            {
                p[loof*i + j] = s[i];
            }
        }
        printf("%s\n", p);
    }
    return 0;
}