#include <stdio.h>
#include <stdbool.h>
#define MAX 20
char board[MAX][MAX];
bool visited[1000];
int R,C, move;

void input(int row, int col) {
	for(int i=0; i<row; i++) {
		scanf("%s", board[i]);
	}
}

void dfs(int row, int col, int depth) {
if(row < R && row >= 0 && col < C && col >= 0) {
	if(visited[board[row][col]] == 0) {
		move = depth > move ? depth : move;
		visited[board[row][col]] = 1;
		dfs(row+1, col, depth+1);
		dfs(row-1, col, depth+1);
		dfs(row, col+1, depth+1);
		dfs(row, col-1, depth+1);
		visited[board[row][col]] = 0;
	}
}
}

int main() {
	scanf("%d %d", &R, &C);
	input(R, C);
	dfs(0,0,1);
	printf("%d\n", move);
	return 0;
}