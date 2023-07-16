#include <stdio.h>
#include <string.h>

int base[1001][1001]={0};
int queue[1001][2];
int N, M;
int day=0;
int max;

/*
메모리의 지역성에 따라 base[0][0], base[0][1]은 인접하고 base[0][0], base[1][0]은 인접하지 않을 가능성이 높으니
가로축으로 탐색하는 것이 메모리 지역성측면과 캐시친화력(워드단위)에서 좋아보인다.

1인곳의 좌표를 queue에 저장한다.
queue에서 상하좌우 탐색후 0인곳을 1로바꾸고 그곳의 좌표를 저장한다.
*/

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

void infect(int i, int j)
{
    int count =0;
    for(int i=0;i<max;i++)
        printf("%d : %d, %d\n",i,queue[i][0], queue[i][1]);
    for(int i=0;i<max;i++)
    {
        int y= queue[i][0];
        int x= queue[i][1];
        if(base[y+1][x]==0 && y+1<N)
        {
            base[y+1][x]=1;
            queue[count][0]=y+1;
            queue[count++][1]=x;
        }
        if(base[y-1][x]==0 && y>0)
        {
            base[y-1][x]=1;
            queue[count][0]=y-1;
            queue[count++][1]=x;
        }
        if(base[y][x+1]==0 && x+1<M)
        {
            base[y][x+1]=1;
            queue[count][0]=y;
            queue[count++][1]=x+1;
        }
        if(base[y][x-1]==0 && x>0)
        {
            base[y][x-1]=1;
            queue[count][0]=y;
            queue[count++][1]=x-1;
        }
    }
    max = count;
    day++;
    all_print_arr();
    if(max!=0)
        infect(i, j);
}

void input_array()
{
    int count=0;
    int x;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf("%d", &x);
            if(x!=0)
            {
                base[i][j]=x;
                if(x==1)
                {
                    queue[count][0]=i;
                    queue[count++][1]=j;
                }
            }
        }
    }
    max = count;
}


int main()
{
    scanf("%d%d", &M, &N);
    input_array();
    infect(N-1,M-1);
    all_print_arr();
    int flag=1;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(base[i][j]==0)
                flag=0;
    if(flag)
        printf("%d\n", day);
    else
        printf("-1\n");
    //printf("%d %d %d\n", flag, );
    return 0;
}