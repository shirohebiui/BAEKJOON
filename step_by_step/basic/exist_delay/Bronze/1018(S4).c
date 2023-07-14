#include <stdio.h>
/*
M*N크기의 보드에서 8*8만큼의 크기를 잘라내서 색을 칠해 보드로 쓸것이다.
가장 적은횟수로 색을 칠하는 경우를 구하는 문제다.

0,0이 B로 시작하는 체스판 arr_B과
0,0이 W로 시작하는 체스판 arr_W을 만들고 0으로 초기화한다.
그다음 각 체스판에서 색칠해야하는부분을 1로 저장한다.
그다음 i+8<N , j+8<M인 루프로 8*8의 크기로 arr_A, arr_B를 합산해서 모든 경우에서 합이 가장 적은 경우가 곧 색칠을 최소로 하여
체스판을 만들 수 있는 경우다. 그 수가 곧 답이다.
*/
int M,N;
int arr_W[50][51]={0};
int arr_B[50][51]={0};
int min=50*50; //50*50공간에서 가능한 최대수

void paint(int i, int j, char X)
{
    int col = i%2;
    int row = j%2;
    if(col == 0)    //짝수행
    {
        if(row==0)  //짝수열
        {
            if(X != 'W')
                arr_W[i][j]=1;
            else
                arr_B[i][j]=1;
        }
        else        //홀수열
        {
            if(X != 'B')
                arr_W[i][j]=1;
            else
                arr_B[i][j]=1;
        }
    }
    else            //홀수행
    {
        if(row==0)  //짝수열
        {
            if(X != 'B')
                arr_W[i][j]=1;
            else
                arr_B[i][j]=1;
        }
        else        //홀수열
        {
            if(X != 'W')
                arr_W[i][j]=1;
            else
                arr_B[i][j]=1;
        }
    }
}

void input()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M;j++)
        {
            char X;
            scanf(" %c", &X);
            paint(i, j, X);
        }
    }
}


int sum_arr(int arr[][51], int a, int b)
{
    int sum=0;
    for(int i=a;i<a+8;i++)
    {
        for(int j=b;j<b+8;j++)
        {
            sum+=arr[i][j];
        }
    }
    return sum;
}

int search_min()
{
    for(int i=0;i<N-7;i++) //이 부분 잘 생각했어야했다. 8*8이면 0,0만되는데 그냥 무지성으로 작성해버렸다!
    {
        for(int j=0;j<M-7;j++)
        {
            int tmp_W=sum_arr(arr_W,i,j);
            int tmp_B=sum_arr(arr_B,i,j);
            if(tmp_B<min)
                min=tmp_B;
            if(tmp_W<min)
                min=tmp_W;
        }
    }
    return min;
}

void all_print(int arr[][51]) //테스트용
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M;j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
void part_print(int arr[][51], int a, int b) //테스트용
{
    for(int i=a; i<a+8; i++)
    {
        for(int j=b; j<b+8;j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    scanf("%d %d", &N,&M);
    // 8<=N,M<=50
    input();
    printf("%d\n", search_min());
    return 0;
}
