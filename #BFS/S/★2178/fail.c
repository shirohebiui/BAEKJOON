#include <stdio.h>
#define abs(n) ((n)>0?(n):-(n))
#define min(a,b) (a<b?a:b)
#define MAX 101

void input_data();
int N, M;
char maze[MAX][MAX];
char visited[MAX][MAX];

void dfs(int r, int c, int move);
int best_move = 1e9; //INF
int IsNotValidPos(int r, int c);

int main() {
    input_data();
    dfs(0, 0, 1); //문제에서 첫좌표부터 move를 1주고시작함
    printf("%d\n", best_move);
    return 0;
}

void input_data() {
    scanf(" %d %d", &N, &M);
    for(int i=0; i<N; i++) {
        scanf("%s", maze[i]);
    }
}

void dfs(int r, int c, int move) {
    if(IsNotValidPos(r,c)) return;
    if(r == N-1 && c == M-1) {
        best_move = min(best_move, move);
        return;
    }
    if(move >= best_move) return;
    if((abs(N-1-r) + abs(M-1-c) + move) >= best_move) return;
    if(visited[r][c] == 0) {
        visited[r][c] = 1;
        dfs(r+1, c, move+1);
        dfs(r-1, c, move+1);
        dfs(r, c+1, move+1);
        dfs(r, c-1, move+1);
        visited[r][c] = 0;
    }
}

int IsNotValidPos(int r, int c) {
    if(maze[r][c] != '1') return 1;
    return (r<0 || r>=N || c<0 || c>=M);
}