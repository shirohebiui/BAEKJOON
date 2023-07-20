#include <stdio.h>
/*
N*M 직사각형
정사각형찾기
외각부터 찾기
*/
int main()
{
    int N, M, MAX=1;
    char arr[51][51];
    scanf("%d%d", &N, &M);
    int side = N>M? M : N;
    for(int i=0; i<N; i++) {
        scanf("%s", arr[i]);
    }
    while(side) {
        for(int i=0; i+side<N; i++) {
            for(int j=0; j+side<M; j++) {
                if(arr[i][j] == arr[i+side][j] && arr[i+side][j] == arr[i][j+side] && arr[i][j+side] == arr[i+side][j+side]){
                    MAX = MAX<(side+1)?side+1 : MAX;
                    //printf("%d %d\n", i, j);
                }
            }
        }
        side--;
    }
    printf("%d\n", MAX*MAX);
    return 0;
}