#include <stdio.h>
#define MAX 1001


void input();
int n, m;
int map[MAX][MAX];

void bfs(int y, int x);
int isSafe(int y, int x);
int queue[MAX*MAX][2], front, rear;
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int dist[MAX][MAX];

void print();

int main() {
    input();
    bfs(queue[front][0], queue[front][1]);
    print();
    return 0;
}

void input() {
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%1d", &map[i][j]);
            if(map[i][j] == 2) {
            queue[rear][0] = i;
            queue[rear][1] = j; rear++;
            }
        }
    }
}


void bfs(int y, int x) {
    int my, mx;
    while(front < rear) {
        y = queue[front][0];
        x = queue[front][1]; front++;
        for(int i=0; i<4; i++) {
            my = y + dy[i], mx = x + dx[i];
            if(isSafe(my,mx))
            if(map[my][mx] == 1 && dist[my][mx] == 0) {
                dist[my][mx] = dist[y][x] + 1;
                queue[rear][0] = my;
                queue[rear][1] = mx; rear++;
            }
        }
    }
}

int isSafe(int y, int x) {
    return (y>=0 && y<n && x>=0 && x<m);
}

void print() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j] == 1 && dist[i][j] == 0)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}
