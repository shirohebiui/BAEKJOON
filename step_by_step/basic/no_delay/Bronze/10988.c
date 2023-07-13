#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    scanf("%s", str);

    int len = strlen(str);
    //printf("%d\n", len);
    int count=1;
    for(int i=0;i<len/2;i++)
    {
        if(str[len-i-1] != str[i])
            count=0;
    }
    printf("%d\n", count);
    return 0;
}