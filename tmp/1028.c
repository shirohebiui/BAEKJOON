#include <stdio.h>
#include <stdlib.h>
char arr[800][800];
int R, C;

/*
https://www.acmicpc.net/problem/1028

주어진 공간 내에서 최대크기 = 1+2n <= min side
*/

void search(int i, int j, int depth, int ext) {
if(depth+ext == 0
) {
    if(arr[i+depth][j] != '0') {
        arr[i+depth][j] = depth;
    }
}
if(i + depth < R && j+depth < C && j-depth >= 0) {
    if(ext == 1) {
        if(arr[i+depth][j-depth] != '0' && arr[i+depth][j+depth] != '0') {
            search(i, j, depth+1, ext);
        }
        if(arr[i+depth][j-(depth-1)]!= '0' && arr[i+depth][j+(depth-1)] != '0') {
            saerch(i, j, depth, -1);
        }
    } else {
        if(arr[i+depth][j-(depth+ext)]!= '0' && arr[i+depth][j+(depth+ext)] != '0') {
            search(i, j, depth+1, ext-1);
        }
    }
}
}

int main()
{
    //printf("echo\n");
    scanf("%d%d", &R, &C);

    int MAX = R>C?(C%2?C/2+1:C/2):(R%2?R/2+1:R/2);
    MAX += 48; //48=ASCII 0
    //printf("%c\n", MAX);

    int flag = 1;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            scanf(" %c", &arr[i][j]);
            if(arr[i][j] == '1')
                flag = 0;
        }
    }
    if(flag) {
        printf("0\n");
        return 0;
    }

    //계산
    printf("*************************\n");
    int size = 48;
    



    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}