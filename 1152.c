#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000001];
    fgets(str, 1000001, stdin);
    long word=0;
    long max = strlen(str);
    //printf("%ld\n", max);
    long tmp=0;
    while(tmp<max)
    {
        if(str[tmp] != ' ' && (str[tmp+1] == ' ' || str[tmp+1] == '\n'))
        {
            word++;
        }
        tmp++;
    }
    printf("%ld\n", word);
    return 0;
}