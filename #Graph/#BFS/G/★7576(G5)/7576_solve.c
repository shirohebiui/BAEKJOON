#include <stdio.h>
#include <string.h>
/*
첫 시도에서 거의 달라진게없다 그저 분할정복이라는 글을한번보고와서 함수를 다단계화 시킨것뿐.
달라진점은 1개다. memcpy의 대상이다.
1이 저장된 배열을 memcpy의 대상으로 삼아 FLAG를 건드리지 않을때까지(즉, 변경사항이 없을때까지)탐색을 반복했다.
start_point에 처음 input시 1이 저장된곳의 좌표를 기록한다음

#loop시작
이 start_point좌표에서 상하좌우를 탐색한다.
탐색한곳의 값이 0일경우 기준좌표의 값에서 +1한 값을넣는다.
그후 변경한 좌표를 tmp에 저장한다.
모든 변경을 마친뒤 tmp->start_point로 memcpy를 한다. + max=count로 max값도 업데이트한다.
FLAG의 변동을 환인한다.
#FLAG의 상태에따라 loop시작과 탈출 결정

*/
int base[1000][1000];
int start_point[1000000][2];
int tmp[1000000][2];
int N, M, MAX, count;
int FLAG=0;

void save_point(int y, int x)
{
    tmp[count][0]=y;
    tmp[count++][1]=x;
}
void change(int y, int x)
{
    int day = base[y][x]+1;
    if(base[y-1][x] == 0 && y>0)
    {
        base[y-1][x] = day;
        save_point(y-1,x);
        FLAG=0;
    }
    if(base[y+1][x] == 0 && y+1<N)
    {
        base[y+1][x] = day;
        save_point(y+1,x);
        FLAG=0;
    }
    if(base[y][x+1] == 0 && x+1<M)
    {
        base[y][x+1] = day;
        save_point(y,x+1);
        FLAG=0;
    }
    if(base[y][x-1] == 0 && x>0)
    {
        base[y][x-1] = day;
        save_point(y,x-1);
        FLAG=0;
    }
}
void loop()
{
    count = 0;
    for(int i=0; i<MAX; i++)
    {
        change(start_point[i][0], start_point[i][1]);
    }
    MAX=count;
    memcpy(start_point, tmp, sizeof(int)*MAX*2);
}

void input_array()
{
    count=0;
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
                    start_point[count][0]=i;
                    start_point[count++][1]=j;
                }
            }
        }
    }
    MAX = count;
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
    input_array();
    while(FLAG==0)
    {
        FLAG=1;
        loop();
    }
    //all_print_arr();
    int day=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(base[i][j] == -1)
            {
            }
            else if(base[i][j]==0)
            {
                j=M;
                i=N;
                day=0;
            }
            else if(base[i][j] > day)
            {
                day=base[i][j];
            }
        }
    }
    printf("%d\n", day-1);
    return 0;
}