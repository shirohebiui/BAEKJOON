#include <stdio.h>
#define MAX 100

char dz[6] = {-1, 1,  0,  0, 0, 0};
char dx[6] = { 0, 0,  0, -1, 1, 0};
char dy[6] = { 0, 0, -1,  0, 0, 1};

typedef struct pos {
    char z, y, x;
}pos;

pos que[1000001]; int front, rear, day;

char board[MAX][MAX][MAX]; int m, n, h;

void test();

int isSafe(char z, char y, char x) {
    if(z < 0 || z >= h) return 0;
    if(y < 0 || y >= n) return 0;
    if(x < 0 || x >= m) return 0;
    return 1;
}

void bfs() {
    char flag = 1;
    while(flag) {
        flag = 0;
        int prear = rear;
        while(front < prear) {
            pos *p = &que[front++];
            for(int i=0; i<6; i++) {
                char pz = p->z + dz[i], py = p->y + dy[i], px = p->x + dx[i];
                if(isSafe(pz,py,px) && board[pz][py][px] == 0) {
                    board[pz][py][px] = 1;
                    que[rear].z = pz; que[rear].y = py; que[rear].x = px; //enqueue
                    rear++;
                    flag = 1;
                }
            }
        }
        if(flag) day++;
        // test();
    }
}

int IsComplete() {
    for(int z=0; z<h; z++) {
        for(int y=0; y<n; y++) {
            for(int x=0; x<m; x++) {
                if(board[z][y][x] == 0) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main() {
    //input
    scanf("%d %d %d", &m, &n, &h);
    for(int z=0; z<h; z++) {
        for(int y=0; y<n; y++) {
            for(int x=0; x<m; x++) {
                scanf(" %hhd", &board[z][y][x]);
                if(board[z][y][x] == 1) {
                    que[rear].z = z; que[rear].y = y; que[rear].x = x; //enqueue
                    rear++;
                }
            }
        }
    }
    //bfs
    bfs();

    //answer
    if(IsComplete()) {
        printf("%d\n", day);
    } else {
        printf("-1\n");
    }
	return 0;
}

void test() {
    printf("test day %d front %d, rear %d\n", day, front, rear);
    for(int z=0; z<h; z++) {
        for(int y=0; y<n; y++) {
            for(int x=0; x<m; x++) {
                printf("%d ", board[z][y][x]);
            }
            printf("\n");
        }
            printf("\n");
    }
}