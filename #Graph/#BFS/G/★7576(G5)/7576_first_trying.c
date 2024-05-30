#include <stdio.h>
#include <string.h>
/*
base에 초기상태를 받는다.
arr에 1로 된곳의 좌표를 받는다. 또한 1의 갯수를 카운트한다.
arr에서 1의 갯수만큼 아래내용을 반복을 한다.

+반복할내용+---------------------------------------------+
| base의 모든곳이 1이될경우(-1인곳제외) -> 반복그만        |
| arr에 저장된 좌표 x,y의 상하좌우를 탐색한다.             |
| 지정된범위내 & 0이 저장된곳을 1로 바꾼다.                |
| 1로 바꾼곳의 좌표를 tmp배열에 저장하고 갯수를 카운트한다. |
| arr에 tmp배열을 덮어씌운다(memcpy)                      |
| 변경이 1회 이상 일어날경우 flag를 1로 바꾼다.            |
| 반복할때마다 day+1을 한다.                              |
| flag가 0일경우(flag가 바뀌지않았음)->반복그만            |
+ ------------------------------------------------------+

*/
int base[1001][1001]={0};
int arr[1000000][2]={0};
int tmp[1000000][2]={0};
int M,N;
int sub=0, max;
int count;
int IsValid = 1;
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
        int y = arr[i][0];
        int x = arr[i][1];
        if(x-1>=0 && base[y][x-1] == 0)
        {
            //printf("%d, %d\n", y, x-1);
            base[y][x-1] = 1;
            tmp[count][0]=y;
            tmp[count][1]=x-1;
            count++;
            IsValid=1;
        }
        if(x+1<M && base[y][x+1] == 0)
        {
            //printf("%d, %d\n", y, x+1);
            base[y][x+1] = 1;
            tmp[count][0]=y;
            tmp[count][1]=x+1;
            count++;
            IsValid=1;
        }
        if(y-1>=0 && base[y-1][x] == 0)
        {
            //printf("%d, %d\n", y-1, x);
            base[y-1][x] = 1;
            tmp[count][0]=y-1;
            tmp[count][1]=x;
            count++;
            IsValid=1;
        }
        if(y+1<N && base[y+1][x] == 0)
        {
            //printf("%d, %d\n", y+1, x);
            base[y+1][x] = 1;
            tmp[count][0]=y+1;
            tmp[count][1]=x;
            count++;
            IsValid=1;
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
        else if(IsValid == 0) //플래그가 바뀌지않았다면 더이상 전염이 불가능하다는 뜻
        {
            //cant more infect
            printf("-1\n");
            break;
        }
        else
        {
            IsValid = 0;
            infect(); //전염
            //print_arr();
            day++;
        }
    }
    return 0;
}