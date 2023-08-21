#include <stdio.h>
#include <string.h>
/*
길이가 짧은순 <- strlen
길아가 같은경우 사전순 <-
*/
char str[20000][51];
char tmp[51];
int arr[20000];
int arr_count=0;
int N;

int sort_dic(char *a, char *b)
{
    char *ptr_A = a;
    char *ptr_B = b;
    while(*ptr_A == *ptr_B)
    {
        ptr_A++;
        ptr_B++;
    }
    //  A가 사전순으로 후순위인가?
    //  O->1return , X->0return
    if(*ptr_A < *ptr_B)
        return 1;
    else
        return 0;
}
void sort(int i)
{
    for(;i+1<N;i++)
    {
        long length_A = strlen(str[i]);
        long length_B = strlen(str[i+1]);
        if(length_A<length_B)
        {
            //길이순 정렬
            memcpy(tmp, str[i], sizeof(char)*50);
            memcpy(str[i], str[i+1], sizeof(char)*50);
            memcpy(str[i+1], tmp, sizeof(char)*50);
        }
        else if(length_A==length_B)
        {
            //사전순 정렬
            int go = sort_dic(str[i], str[i+1]);
            if(go!=0)
            {
                memcpy(tmp, str[i], sizeof(char)*50);
                memcpy(str[i], str[i+1], sizeof(char)*50);
                memcpy(str[i+1], tmp, sizeof(char)*50);
            }
        }
        sort(i+1);
    }
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%s", str[i]);
    }
    sort(0);
    for(int i=N-1;i>0;i--)
    {
        if(strcmp(str[i], str[i-1]) == 0)
            printf("%s\n", str[--i]);
        else
            printf("%s\n", str[i]);
    }
    return 0;
}