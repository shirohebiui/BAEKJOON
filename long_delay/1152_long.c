#include <stdio.h>
#include <string.h>
/*
https://www.acmicpc.net/problem/1152
개행문자를 탐색할 경우를 생각하지 못했다.
포인터가 개행문자를 가르키고있을경우를 고려하여 조건을 추가해 해결했다.
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
        if(*ptr != ' ' && *ptr !='\n') //지금 탐색하는 문자가 공백이나 개행문자가 아닌지
        if(*(ptr+1) == ' ' || *(ptr+1) == NULL || *(ptr+1) == '\n')//다음 문자가 개행이나 공백혹은 널포인터인지
        {
            word++;
            //printf("문자! %c\n", *(ptr));
        }
        ptr++;
    }
    printf("%ld\n", word);
    return 0;
}