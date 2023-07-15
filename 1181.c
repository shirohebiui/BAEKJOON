#include <stdio.h>
#include <string.h>
/*
길이가 짧은순 <- strlen
길아가 같은경우 사전순 <-
*/
char str[20000][50];
char tmp[50];
int arr[20000];
int arr_count=0;
int N;
void sort_len(int i)
{
    for(;i+1<N;i++)
    {
        if(strlen(str[i])<strlen(str[i+1]))
        {
            memcpy(tmp, str[i], sizeof(char)*50);
            memcpy(str[i], str[i+1], sizeof(char)*50);
            memcpy(str[i+1], tmp, sizeof(char)*50);
        }
        sort_len(i+1);
    }
}

void sort_dic(int i)
{
    for(;i+1<N;i++)
    {
        if(strlen(str[i])==strlen(str[i+1]))
        {
            int x=0;
            while(str[i][x]==str[i+1][x])
            {
                x++;
            }
            if(str[i][x]<str[i+1][x])
            {
                memcpy(tmp, str[i], sizeof(char)*50);
                memcpy(str[i], str[i+1], sizeof(char)*50);
                memcpy(str[i+1], tmp, sizeof(char)*50);
            }
        }
        sort_dic(i+1);
    }
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%s", str[i]);
    }
    sort_len(0);
    sort_dic(0);
    for(int i=N-1;i>0;i--)
    {
        if(strcmp(str[i], str[i-1]) == 0)
            printf("%s\n", str[--i]);
        else
            printf("%s\n", str[i]);
    }
    return 0;
}