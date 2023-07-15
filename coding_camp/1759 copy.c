#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char arr[6] = { 'a','t','c','i','s','w' };
char *A;
char **B;//[][R+1]
int count=0; //경우의수
int N, R; //input
void combination(int N, int R, int q)
{
	if (R == 0)
	{
		for (int i = q-1; i >= 0; i--)
		{
            B[count][i]=A[i];
		}
        count++;
	}
	else if (N < R)
	{
		return;
	}
	else
	{
		A[R - 1] = arr[N - 1];
		combination(N - 1, R - 1, q);
		combination(N - 1, R, q);
	}
}

int factorial(int num)
{
    int result = 1;
    //for(int i = num; i>0; --i)
    for (int i = 1; i <= num; ++i)
    {
        result = result * i;
    }
    return result;
}
int find_max(int n, int r)
{
    int a;
    a= factorial(n)/factorial(n-r);
    a/= factorial(r);
    return a;
}

void sort_char(){
    char tmp;
    for(int i=0;i<count;i++){
        for(int j=R; j>0; j--){
            for(int k=0; k+1<j; k++)
            {
            if(B[i][k]>B[i][k+1]){
                tmp = B[i][k];
                B[i][k] = B[i][k+1];
                B[i][k+1] = tmp;
            }
            }
        }
    }
}
int search(int k)
{
    char *ptr;
    int count = 0;
    ptr = strchr(B[k], 'a');
    while(ptr != NULL)
    {
        ptr = strchr(ptr+1, 'a');
        count++;
    }

    ptr = strchr(B[k], 'e');
    while(ptr != NULL)
    {
        ptr = strchr(ptr+1, 'e');
        count++;
    }

    ptr = strchr(B[k], 'i');
    while(ptr != NULL)
    {
        ptr = strchr(ptr+1, 'i');
        count++;
    }

    ptr = strchr(B[k], 'o');
    while(ptr != NULL)
    {
        ptr = strchr(ptr+1, 'o');
        count++;
    }

    ptr = strchr(B[k], 'u');
    while(ptr != NULL)
    {
        ptr = strchr(ptr+1, 'u');
        count++;
    }
    return count;
}

void sort_str(){
    char tmp[5]; //input size R
    for(int i=count;i>0;i--){
        for(int j=0;j+1<i;j++)
        {
            if(strcmp(B[j],B[j+1])>0)
            {
                strcpy(tmp, B[j]);
                strcpy(B[j], B[j+1]);
                strcpy(B[j+1], tmp);
            }
        }
    }
}

int main(void)
{
	N = 6;//input
	R = 4;//input
    scanf("%d %d", &R, &N);
    A=(char*)malloc(sizeof(char)*R);
    int max = find_max(N, R);
    B=(char**)malloc(sizeof(char)*(max+100));
    for(int i=0;i<max;i++)
        B[i]=(char*)malloc(sizeof(char)*(R+1));
	combination(N, R, R);
    int max_size = sizeof(B);
    printf("max = %d\n", max_size);
    
    sort_char();
    for(int i=0;i<count;i++)
        B[i][R]='\0'; //문자열로 만들기 위해 \0삽입
    sort_str();

    int sc;
    for(int i=0;i<count;i++)
    {
        sc = search(i);
        if(sc>=1 && sc<=R-2)
            printf("%s\n", B[i]);
    }
    free(A);
	return 0;
}