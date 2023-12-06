#include <stdio.h>
#define abs(n) ((n)>0?(n):-(n))
#define min(a,b) (a<b?a:b)
#define best visited[N-1][M-1]
#define MAX 101

void input_data();
int N, M;
unsigned char maze[MAX][MAX];
int visited[MAX][MAX];

void bfs(int r, int c);
int queue[100001][2], rear, front; //queue[0] = 0,0
int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};
int IsValidPos(int r, int c);

void test();

int main() {
    input_data();
    bfs(0, 0); //문제에서 첫좌표부터 move를 1주고시작함
    printf("%d\n", best);
    //test();
    return 0;
}

void input_data() {
    scanf(" %d %d", &N, &M);
    for(int i=0; i<N; i++) {
        scanf("%s", maze[i]);
    }
}

void bfs(int r, int c) {
    visited[r][c] = 1; rear = 1;
    int rr, cc;
    while(front < rear) {
        r = queue[front][0];
        c = queue[front][1]; front++;
        for(int i=0; i<4; i++) {
            rr = r + dr[i], cc = c + dc[i];
            if(IsValidPos(rr,cc))
            if(maze[rr][cc] == '1' && visited[rr][cc] == 0) {
                visited[rr][cc] = visited[r][c] + 1;
                queue[rear][0] = rr;
                queue[rear][1] = cc; rear++;
            }
        }
    }
}

int IsValidPos(int r, int c) {
    return (r>=0 && r<N && c>=0 && c<M);
}

void test() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            printf("%2d ", visited[i][j]);
        }
        printf("\n");
    }
}
