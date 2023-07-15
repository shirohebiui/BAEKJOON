#include <stdio.h>
#include <stdlib.h>
/*
dzdz의 경우를 간과했다.
d를 확인후 z = 를 차례로 확인하는 과정속에 dz일 경우 글자당 count++를 하기위한 else문을 넣어줘 해결했다.
*/
int main()
{
    char str[100];
    int count=0;
    scanf("%s", str);
    char *ptr = str;
    while(*ptr != NULL)
    {
        if(*ptr=='c')
        {
            ptr++;
            if(*ptr=='=')
                ptr++;
            else if(*ptr=='-')
                ptr++;
        }
        else if(*ptr=='d')
        {
            ptr++;
            if(*ptr=='-')
                ptr++;
            else if(*ptr=='z')
            {
                ptr++;
                if(*ptr=='=')
                    ptr++;
                else
                    count++;
            }
        }
        else if(*ptr=='l')
        {
            ptr++;
            if(*ptr=='j')
                ptr++;
        }
        else if(*ptr=='n')
        {
            ptr++;
            if(*ptr=='j')
                ptr++;
        }
        else if(*ptr=='s')
        {
            ptr++;
            if(*ptr=='=')
                ptr++;
        }
        else if(*ptr=='z')
        {
            ptr++;
            if(*ptr=='=')
                ptr++;
        }
        else
        {
            ptr++;
        }
        count++;
    }
    printf("%d\n", count);
    return 0;
}