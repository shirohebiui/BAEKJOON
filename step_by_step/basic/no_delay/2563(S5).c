#include <stdio.h>
/*
max x 100
max y 100
일때 10^2의 정사각형의 색종이를 붙인후 색종이의 영역을 구하는 문제.

1line : 색종이수(100이하)
2line~ : 색종이의 위치 a, b -> a:y축으로부터 떨어진거리, b:x축으로부터 떨어진 거리
#색종이가 x,y>100이 되는 경우는 없음

이 문제를 처음보니 비효율적으로 예측되지만 100x100 이라는 한정된 공간에서의 시뮬레이션이니 이 100x100의 배열을 전부 0으로 초기화후
색종이의 범위로 지정된 배열의 요소만 1로 바꾸는 방법이 떠오른다. 바로 실행해보자.

1트 성공
*/
int main()
{
    int arr[101][101] ={0}; //0,0~100,100
    int pos[100][2];
    int N;
    scanf("%d", &N);

    for(int i=0;i<N;i++)
    {
        scanf("%d%d", &pos[i][0], &pos[i][1]); //좌표입력
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                arr[pos[i][0]+j][pos[i][1]+k] = 1;
            }
        }
    }
    
    int sum=0;
    for(int j=0;j<100;j++)
    {
        for(int k=0;k<100;k++)
        {
            //시각화
            //printf("%d ", arr[j][k]);
            sum+=arr[j][k];
        }
        //printf("\n");
    }
    printf("%d\n", sum);
    return 0;
}