#include <stdio.h>
#include <string.h>
#define MAX 501
int map[MAX][MAX];
int dp[MAX][MAX];
int R,C;
int add[4] = {0, 0, 1, -1};
//https://www.acmicpc.net/problem/1520
void input(int row, int col) {
    for(int i=1; i<=row; i++) {
        for(int j=1; j<=col; j++) {
            scanf("%d", &map[i][j]);
            dp[i][j] = -1;
        }
    }
}

void test_print() {
    printf("\n");
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            if(i == R && j == C) printf("%2c", 'G');
            else if(dp[i][j] == -1) printf("%2d ", 0);
            else printf("%2d ", dp[i][j]);
        }
        printf("\n");
    }
}

int dfs(int m, int n) {
    if(m == R && n== C) return 1; //바닥조건 (길 연결 성공)
    if(dp[m][n] != -1) return dp[m][n]; //이미 탐색한곳

    dp[m][n] = 0; //탐색한곳 표시, 연결여부를 모르니 아직 경우=0
    for(int t=0; t<4; t++) {
        int i = m + add[t];
        int j = n + add[3-t];
        if(i<=R && i>0 && j<=C && j>0) {
            if(map[i][j] < map[m][n]) { 
                dp[m][n] += dfs(i, j); //상하좌우 연결가능한곳의 경우 합하기
            }
        }
    }
    return dp[m][n];
}
int main() {
    scanf("%d %d", &R, &C);
    input(R, C);
    dfs(1,1);

    printf("%d\n", dfs(1,1));
    // test_print();
    return 0;
}