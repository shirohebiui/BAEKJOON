#include <stdio.h>
#define MAX 2500
#define SIZE 52
typedef char pt;

typedef struct pos{
    pt y, x;
    struct pos *next, *prev;
}pos;

pos *head, *tail;
pos nodes[MAX+2]; int size;

void init_dlist() {
    head = &nodes[MAX];
	tail = &nodes[MAX+1];
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
}

void insert_node(pt y, pt x) {
    pos *p = &nodes[size++];
    p->y = y; p->x = x;
    p->prev = tail->prev;
    p->next = tail;
    tail->prev->next = p;
    tail->prev = p;
}

char board[52][52]; pt n, m;
#define WATER -1

void input() {
    scanf("%hhd %hhd", &n, &m);
    for(pt y=1; y<=n; y++) {
        for(pt x=1; x<=m; x++) {
            char tile; scanf(" %c", &tile);
            if(tile == 'W') {
                board[y][x] = WATER;
            } else {
                board[y][x] = 0;
                insert_node(y, x);
            }
        }
    }
}

void make_wall() {
    for(pt y=1; y<=n; y++) {
        board[y][0] = WATER;
        board[y][m+1] = WATER;
    }
    for(pt x=1; x<=m; x++) {
        board[0][x] = WATER;
        board[n+1][x] = WATER;
    }
}

static inline void clear() {
    pos *p = head->next;
    while(p != tail) {
        board[p->y][p->x] = 0;
        p = p->next;
    }
}

pos queue[MAX];
int answer_bfs() {
    char dy[4] = {0,1,-1,0};
    char dx[4] = {1,0,0,-1};

    int best = 0;
    int front, rear, prear, len;
    int py, px;
    pos *p = head->next;
    while(p != tail) {
        front = rear = prear = len = 0;
        queue[rear].y = p->y; queue[rear++].x = p->x;
        clear();
        while(front < rear) {
            prear = rear;
            board[queue[front].y][queue[front].x] = 1;
            while(front < prear) {
                for(char i=0; i<4; i++) {
                    py = queue[front].y + dy[i]; px = queue[front].x + dx[i];
                    if(board[py][px] == 0 && board[py][px] != WATER) {
                        board[py][px] = 1;
                        queue[rear].y = py; queue[rear++].x = px;
                    }
                }
                ++front;
            }
            ++len;
        }
        best = best > len ? best : len;
        p = p->next;
    }
    return best;
}

int main() {
    init_dlist();
    input();
    make_wall();
    printf("%d\n", answer_bfs()-1);
    return 0;
}