#include <stdio.h>
#include <string.h>
/*
https://www.acmicpc.net/problem/1152
*/
int main()
{
    char str[1000001];
    fgets(str, 1000001, stdin);
    long word=0;
    //str[max-1] = 개행문자
    //str[max-2] = 입력한문자
    //printf("%c\n", str[max-2]);
    long tmp=0;
    char *ptr= str;
    while(*ptr != NULL)
    {
        if(*ptr != ' ' && *ptr !='\n' && (*(ptr+1) == ' ' || *(ptr+1) == NULL || *(ptr+1) == '\n'))
        {
            word++;
            //printf("문자! %c\n", *(ptr));
        }
        ptr++;
    }
    printf("%ld\n", word);
    return 0;
}