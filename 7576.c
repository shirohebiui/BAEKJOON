#include <stdio.h>
#include <string.h>
/*

*/
int base[1000][1000]={0};
int arr[1000][2]={0};
int tmp[1000][2]={0};
int M,N;
int sub=0, max;
int count;
int flag = 1;
int sum_base()
{
    int sum = 0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            sum+=base[i][j];
    return sum+sub;
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
                sub++;
                //-1은 빈공간이므로 최종합계에 포함하지않는다.
                //-1의 갯수를 모아서 나중에 base배열을 합산할때 더해주자.
            }
        }
    }
    max = count;
}

void print_arr() //테스트용
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
            flag=1;
        }
        if(x+1<M && base[y][x+1] == 0)
        {
            //printf("%d, %d\n", y, x+1);
            base[y][x+1] = 1;
            tmp[count][0]=y;
            tmp[count][1]=x+1;
            count++;
            flag=1;
        }
        if(y-1>=0 && base[y-1][x] == 0)
        {
            //printf("%d, %d\n", y-1, x);
            base[y-1][x] = 1;
            tmp[count][0]=y-1;
            tmp[count][1]=x;
            count++;
            flag=1;
        }
        if(y+1<N && base[y+1][x] == 0)
        {
            //printf("%d, %d\n", y+1, x);
            base[y+1][x] = 1;
            tmp[count][0]=y+1;
            tmp[count][1]=x;
            count++;
            flag=1;
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
    int day = 0;
    input_array();
    int goal = M*N - sub; //목표
    //printf("goal %d sum %d\n", goal, sum_base());
    while(1)
    {
        if(sum_base() == goal)
        {
            //infect complete
            printf("%d\n", day);
            break;
        }
        else if(flag == 0) //플래그가 바뀌지않았다면 더이상 전염이 불가능하다는 뜻
        {
            //cant more infect
            printf("-1\n");
            break;
        }
        else
        {
            flag = 0;
            infect(); //전염
            day++;
        }
    }
    return 0;
}