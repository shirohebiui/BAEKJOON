#include <stdio.h>
#include <string.h>

int base[1001][1001]={0};
int tmp[1001][1001]={0};
int N, M, goal;
int day=0;
int sum=0;
int flag=1;
int x;
void infect(int i, int j)
{
    if(i>=0 && j>=0)
    {
        if(base[i][j]==0)
        {
            if(base[i-1][j] == 1 || base[i][j-1]==1 ||base[i+1][j] ==1 || base[i][j+1]==1)
            {
                flag = 1;
                sum++;
                tmp[i][j]=1;
            }
        }
        if(i>0)
            infect(i-1,j);
        else
            infect(N-1,j-1);
    }
    if(i==0 && j==0)
    {
        memcpy(base, tmp, sizeof(int)*1001*1001);
        day++;
    }
}

void input_array()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf("%d", &x);
            if(x!=0)
            {
                base[i][j]=x;
                tmp[i][j]=x;
                sum++;
            }
        }
    }
}

void all_print_arr() //테스트용
{
    printf("\n===============\n");
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
            printf("%d ", base[i][j]);
        printf("\n");
    }
}

int main()
{
    scanf("%d%d", &M, &N);
    goal=N*M;
    input_array();
    while(sum!=goal && flag==1)
    {
        flag=0;
        infect(N-1,M-1);
    }
    //all_print_arr();
    if(sum==goal)
        printf("%d\n", day);
    else
        printf("-1\n");
    return 0;
}