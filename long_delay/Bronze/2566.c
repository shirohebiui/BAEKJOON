#include <stdio.h>
/*
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
이 들어올경우 max를 0으로초기화해서 모든 요소가 0일경우 if문을 만족시키는 곳이 없었다.
따라서 if문으로 조건을 달때 ==의 경우를 추가하거나 max를 -1로 초기화하면되겠다
max를 -1로 바꿔 해결했다.
*/
int main()
{
    int arr[9][9] = {0};
    int max=-1;
    int cal=0, low=0;
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            scanf("%d", &arr[i][j]);
            if(arr[i][j]>max)
            {
                max = arr[i][j];
                cal = i+1;
                low = j+1;
            }
        }
    printf("%d\n%d %d\n", max, cal, low);
    return 0;
}