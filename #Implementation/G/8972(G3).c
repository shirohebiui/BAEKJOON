#include <stdio.h>
#include <string.h>
#define MAX 101

#define UP '8'
#define UP_RIGHT '9'
#define RIGHT '6'
#define DOWN_RIGHT '3'
#define DOWN '2'
#define DOWN_LEFT '1'
#define LEFT '4'
#define UP_LEFT '7'

char board[MAX][MAX]; int N, M;
char update[MAX][MAX];

int me[2], crazy[MAX * MAX][2], rear;
char my_direct[101];

int isSafe(int y, int x);
char direct(int y1, int x1, int y2, int x2);
void move(int *y, int *x, char arrow);
void print_board();

int main() {
    //input
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            scanf(" %c", &board[i][j]);
            if(board[i][j] == 'I') {
                me[0] = i;
                me[1] = j;
            } else if(board[i][j] == 'R') {
                crazy[rear][0] = i;
                crazy[rear++][1] = j;
            }
        }
    }
    scanf(" %s", my_direct);

    //moving
    for(int i=0; i<strlen(my_direct); i++) {
        memset(update, 0x00, sizeof(update));
        move(&me[0], &me[1], my_direct[i]);
        if(board[me[0]][me[1]] == 'R') {
            printf("kraj %d\n", i+1);
            return 0;
        }
        for(int front=0; front<rear ;front++) {
            if(isSafe(crazy[front][0], crazy[front][1])) {
                move(&crazy[front][0], &crazy[front][1], direct(me[0], me[1], crazy[front][0], crazy[front][1]));
            }
        }
        if(update[me[0]][me[1]] != 'I') {
            printf("kraj %d\n", i+1);
            return 0;
        }
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(update[i][j] > 0) board[i][j] = update[i][j];
                else board[i][j] = 0;
            }
        }
        // printf("-------%d-------\n", i+1);
        // print_board();
    }
    //board
    print_board();
    return 0;

    //break

    return 0;
}
int isSafe(int y, int x) {
    return (y>=0 && y<=N && x>=0 && x<=M);
}

char direct(int y1, int x1, int y2, int x2) {
    int dy = y1-y2;
    int dx = x1-x2;
    if(dy == 0) {
        if(dx > 0) return RIGHT;
        return LEFT;
    }
    if(dx == 0) {
        if(dy < 0) return UP;
        return DOWN;
    }
    if(dy<0) {
        if(dx>0) return UP_RIGHT;
        return UP_LEFT;
    }
    if(dy>0) {
        if(dx>0) return DOWN_RIGHT;
        return DOWN_LEFT;
    }
    return -1;
}

void move(int *y, int *x, char arrow) {
    // printf("%d %d %c\n", *y, *x, arrow);
    if(board[*y][*x] == 0) {
        *y = -1; *x = -1;
        return;
    }
    char tmp = board[*y][*x];
    switch (arrow) {
        case RIGHT:
            if(!isSafe(*y,*x+1)) return;
            *x+=1;
            break;
        case LEFT:
            if(!isSafe(*y,*x-1)) return;
            *x-=1;
            break;
        case UP:
            if(!isSafe(*y-1,*x)) return;
            *y-=1;
            break;
        case DOWN:
            if(!isSafe(*y+1,*x)) return;
            *y+=1;
            break;
        case UP_RIGHT:
            if(!isSafe(*y-1,*x+1)) return;
            *y-=1; *x+=1;
            break;
        case UP_LEFT:
            if(!isSafe(*y-1,*x-1)) return;
            *y-=1; *x-=1;
            break;
        case DOWN_RIGHT:
            if(!isSafe(*y+1,*x+1)) return;
            *y+=1; *x+=1;
            break;
        case DOWN_LEFT:
            if(!isSafe(*y+1,*x-1)) return;
            *y+=1; *x-=1;
            break;
    }
    if(update[*y][*x] == 0) {
        update[*y][*x] = tmp;
    } else {
        update[*y][*x] = -1;
        *y = -1; *x = -1;
    }
    // printf("%d %d %d\n",*y, *x, update[*y][*x]);
}

void print_board() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(board[i][j] != 0) {
                printf("%c", board[i][j]);
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}