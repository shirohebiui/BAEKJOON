#include <stdio.h>
#include <string.h>
/*

*/
int base[1000][1000]={0};
int arr[1000][2]={0};
int tmp[1000][2]={0};
int M,N;
int goal, max;
int count;

int goal_check()
{
    int sum = 0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            sum+=base[i][j];
    if(sum==goal)
        return 1;
    else
        return 0;
}

void input_array()
{
    count = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf("%d", &base[i][j]);
            
            if(base[i][j] == 1)
            {
                arr[count][0]=i; //y
                arr[count][1]=j; //x
                count++;
            }
            else if(base[i][j] == -1)
            {
                goal--;
                //-1은 빈공간이므로 최종합계에 포함하지않는다.
            }
        }
    }
    max = count;
}

void print_arr()
{
    printf("\n************\n");
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
            printf("%d ", base[i][j]);
        printf("\n");
    }
}

void infect()
{
    count = 0;
    for(int i=0;i<max;i++)
    {
        int x = arr[i][1];
        int y = arr[i][0];
        if(x-1>=0 && base[y][x-1] == 0)
        {
            //printf("%d, %d\n", y, x-1);
            base[y][x-1] = 1;
            tmp[count][0]=y;
            tmp[count][1]=x-1;
            count++;
        }
        if(x+1<M && base[y][x+1] == 0)
        {
            //printf("%d, %d\n", y, x+1);
            base[y][x+1] = 1;
            tmp[count][0]=y;
            tmp[count][1]=x+1;
            count++;
        }
        if(y-1>=0 && base[y-1][x] == 0)
        {
            //printf("%d, %d\n", y-1, x);
            base[y-1][x] = 1;
            tmp[count][0]=y-1;
            tmp[count][1]=x;
            count++;
        }
        if(y+1<N && base[y+1][x] == 0)
        {
            //printf("%d, %d\n", y+1, x);
            base[y+1][x] = 1;
            tmp[count][0]=y+1;
            tmp[count][1]=x;
            count++;
        }
    }
    max = count;
    //printf("max = %d\n", max);
    memcpy(arr, tmp, sizeof(int)*max*2);
}

int main()
{
    //1line input
    scanf("%d%d", &M, &N);
    goal = M*N; //목표
    int day = 0;
    input_array();
    while(1)
    {
        if(goal_check())
        {
            break;
        }
        else
        {
            infect(); //전염
            day++;
        }
    }
    printf("%d\n", day);
    return 0;
}