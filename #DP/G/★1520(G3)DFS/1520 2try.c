#include <stdio.h>
#define MAX 502
int map[MAX][MAX];
int R,C;
long visited[MAX][MAX];
long path;
//https://www.acmicpc.net/problem/1520
void input(int row, int col) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            scanf("%d", &map[i+1][j+1]);
        }
    }
}


void dfs(int row, int col, int prev) {
if(row <= R && row > 0 && col <= C && col > 0) {
    int cur = map[row][col];
    if(cur < prev ) {
        if(visited[row][col]) {
            visited[0][0] *= 2;
            return;
        }
        visited[row][col]++;
        dfs(row+1, col, cur);
        dfs(row-1, col, cur);
        dfs(row, col+1, cur);
        dfs(row, col-1, cur);

    }
}
}

int main() {
    scanf("%d %d", &R, &C);
    input(R, C);
    dfs(0,0,map[0][0]+1);
    printf("%ld\n", visited[0][0]);
    // for(int i=0; i<R; i++) {
    // 	for(int j=0; j<C; j++) {
    // 		printf("%ld ", visited[i][j]);
    // 	}
    // 	printf("\n");
    // }
    return 0;
}