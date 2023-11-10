#include <stdio.h>
#define MAX 500
int map[MAX][MAX];
int R,C;
long path;
//https://www.acmicpc.net/problem/1520
void input(int row, int col) {
	for(int i=0; i<row; i++) {
		for(int j=0; j<col; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}

void dfs(int row, int col, int prev) {
if(row == R-1 && col == C-1) {
	path++;
} else if(row < R && row >= 0 && col < C && col >= 0) {
	int cur = map[row][col];
	if(cur < prev ) {
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
	printf("%ld\n", path);
	// for(int i=0; i<R; i++) {
	// 	for(int j=0; j<C; j++) {
	// 		printf("%ld ", visited[i][j]);
	// 	}
	// 	printf("\n");
	// }
	return 0;
}