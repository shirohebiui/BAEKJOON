#include <stdio.h>
#include <string.h>

int base[1001][1001]={0};
int tmp[1001][1001]={0};
int change[1001][1001];
int N, M, goal;
int day=0;
int sum=0;
int flag=1;
int x;

/*
메모리의 지역성에 따라 base[0][0], base[0][1]은 인접하고 base[0][0], base[1][0]은 인접하지 않을 가능성이 높으니
가로축으로 탐색하는 것이 메모리 지역성측면과 캐시친화력(워드단위)에서 좋아보인다.

1,-1은 탐색할 필요가없고 0인곳만 체크하면되니 저장된 값이 0인곳의 좌표만 넘겨주는 식으로 재귀를 하면 될것같다.
*/
void infect(int i, int j)
{
    int a=0,b=0;
    if(i>=0 && j>=0)
    {
        while(j>0 && base[i][j] != 0)
            j--;
        if(base[i][j]==0)
        {
            if(base[i-1][j] == 1 || base[i][j-1]==1 ||base[i+1][j] ==1 || base[i][j+1]==1)
            {
                flag = 1;
                sum++;
                tmp[i][j]=1;
            }
        }
        while(j>0 && base[i][j-1] != 0)
            j--;
        if(j>0)
            infect(i,j-1);
        else
            infect(i-1,M-1);
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
    printf("===============\n");
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
    //printf("%d %d %d\n", flag, sum, goal);
    return 0;
}