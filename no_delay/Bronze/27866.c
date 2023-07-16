#include <stdio.h>

int main()
{
    char str[1000];
    char *ptr = str;
    scanf("%s", str);
    int i;
    scanf("%d", &i);
    printf("%c\n",*(ptr+i-1));
    return 0;
}