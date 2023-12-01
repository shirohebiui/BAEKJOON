#include <stdio.h>
#include <string.h>
#define max(a,b) (a>b?a:b)
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int board[7][20][20];
//lv0=root lv1 lv2 lv3 lv4 lv5 board
int size, cnt;

int max_value = 0;

void move(int direct, int lv); //현재 단계에서 다음 단계로 넘기기
void move_up(int lv);
void move_down(int lv);
void move_left(int lv);
void move_right(int lv);

void dfs(int direct, int lv);
void find_max(); //최댓값찾기 max_value에 최대값갱신

void input_board();
void test(int lv);

int main() {
    scanf(" %d", &size);
    input_board();
    dfs(UP, 0);
    dfs(DOWN, 0);
    dfs(LEFT, 0);
    dfs(RIGHT, 0);
    printf("%d\n", max_value);
    return 0;
}



void dfs(int direct, int lv) {
    if(lv == 5) {   //마지막단계라면 큰수 찾아 리턴
        find_max();
        return;
    }
    
    memset(board[lv+1], 0, 20*20*sizeof(int));
    move(direct, lv);
    dfs(UP, lv+1);
    dfs(DOWN, lv+1);
    dfs(LEFT, lv+1);
    dfs(RIGHT, lv+1);
    //이전단계의 lv에서 상하좌우 이동을 다음단계 lv에 넘긴다.
}

void move(int direct, int lv) {
    switch (direct)
    {
    case UP:
        move_up(lv);
        break;
    case DOWN:
        move_down(lv);
        break;
    case LEFT:
        move_left(lv);
        break;
    case RIGHT:
        move_right(lv);
        break;
    default:
        break;
    }
}

void move_up(int lv) {
    for(int i=0; i<size; i++) {
        cnt = 0;
        for(int j=0; j<size; j++) {
            if(board[lv][j][i] > 0) {
                if(cnt%2 == 0) { 
                    //빈칸
                    board[lv+1][cnt/2][i] = board[lv][j][i];
                } else if(board[lv+1][cnt/2][i] == board[lv][j][i]) {
                    //같은수
                    board[lv+1][cnt/2][i] += board[lv][j][i];
                } else {
                    //다른수
                    cnt++;
                    board[lv+1][cnt/2][i] = board[lv][j][i];
                }
                cnt++;
            }
        }
    }
}
void move_down(int lv) {
    for(int i=0; i<size; i++) {
        cnt = size*2 - 1;
        for(int j=size-1; j>=0; j--) {
            if(board[lv][j][i] > 0) {
                if(cnt%2 == 1) { 
                    //빈칸
                    board[lv+1][cnt/2][i] = board[lv][j][i];
                } else if(board[lv+1][cnt/2][i] == board[lv][j][i]) {
                    //같은수
                    board[lv+1][cnt/2][i] += board[lv][j][i];
                } else {
                    //다른수
                    cnt--;
                    board[lv+1][cnt/2][i] = board[lv][j][i];
                }
                cnt--;
            }
        }
    }
}
void move_left(int lv) {
    for(int i=0; i<size; i++) {
        cnt = 0;
        for(int j=0; j<size; j++) {
            if(board[lv][i][j] > 0) {
                if(cnt%2 == 0) { 
                    //빈칸
                    board[lv+1][i][cnt/2] = board[lv][i][j];
                } else if(board[lv+1][i][cnt/2] == board[lv][i][j]) {
                    //같은수
                    board[lv+1][i][cnt/2] += board[lv][i][j];
                } else {
                    //다른수
                    cnt++;
                    board[lv+1][i][cnt/2] = board[lv][i][j];
                }
                cnt++;
            }
        }
    }
}
void move_right(int lv) {
    for(int i=0; i<size; i++) {
        cnt = size*2 - 1;
        for(int j=size-1; j>=0; j--) {
            if(board[lv][i][j] > 0) {
                if(cnt%2 == 1) { 
                    //빈칸
                    board[lv+1][i][cnt/2] = board[lv][i][j];
                } else if(board[lv+1][i][cnt/2] == board[lv][i][j]) {
                    //같은수
                    board[lv+1][i][cnt/2] += board[lv][i][j];
                } else {
                    //다른수
                    cnt--;
                    board[lv+1][i][cnt/2] = board[lv][i][j];
                }
                cnt--;
            }
        }
    }
}

void find_max(){
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            max_value = max(max_value, board[5][i][j]);
        }
    }
}

void input_board() {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            scanf(" %d", &board[0][i][j]);
        }
    }
}

void test(int lv) {
    printf("lv %d test\n", lv);
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            printf(" %2d", board[lv][i][j]);
        }
        printf("\n");
    }
}