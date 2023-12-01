#include <stdio.h>
#include <string.h>
#define max(a,b) (a>b?a:b)
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define FIND_LV 10
typedef unsigned int u16;
size_t u16_size = sizeof(u16);
size_t mem_clear_size; //board clear size (func move)
size_t mem_line_size;  //cmp line size (func IsNotChange)
int i, j;

void input_board();
u16 board[FIND_LV+1][20][20];
//lv0=root lv1 lv2 lv3 .... board
int size;

void dfs(int direct, int lv);
int max_tmp; //dfs에서의 단계에 따른 max값
int final_max; //최종 max값

void move(int direct, int lv); //현재 단계에서 다음 단계로 넘기기
void move_up(int lv);
void move_down(int lv);
void move_left(int lv);
void move_right(int lv);
int cnt, next; //move함수에서 쓰는 변수들

int IsNotUsefull(int lv);
int IsNotChange(int lv);

int main() {
    input_board();
    dfs(UP   , 0);
    dfs(DOWN , 0);
    dfs(LEFT , 0);
    dfs(RIGHT, 0);
    printf("%d\n", 1<<final_max);
    return 0;
}

void input_board() {
    scanf(" %d", &size);
    mem_clear_size = size*u16_size*20;
    mem_line_size  = size*u16_size;
    int in, exp;
    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            scanf(" %d", &in);
            if(in) {
                exp = 0;
                while(in != 1<<exp) {
                    exp++;
                }
                board[0][i][j] = exp;
            }
            //in == 0 -> board[0][i][j] = 0;
            //이미 0으로 초기화된 상태이므로 불필요
        }
    }
}
void dfs(int direct, int lv) {
    if(lv == FIND_LV) return;
    if(IsNotChange(lv)) return;
    if(IsNotUsefull(lv)) return;
    
    move(direct, lv);
    dfs(UP   , lv+1);
    dfs(DOWN , lv+1);
    dfs(LEFT , lv+1);
    dfs(RIGHT, lv+1);
    //이전단계의 lv에서 상하좌우 이동을 다음단계 lv에 넘긴다.
}

void move(int direct, int lv) {
    next = lv+1;
    max_tmp = 0;
    memset(board[next], 0, mem_clear_size);
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
    final_max = max(final_max, max_tmp);
}

void move_up(int lv) {
    for(i=0; i<size; i++) {
        cnt = 0;
        for(j=0; j<size; j++) {
            if(board[lv][j][i] > 0) {
                if(cnt%2 == 0) { 
                    //빈칸
                    board[next][cnt/2][i] = board[lv][j][i];
                } else if(board[next][cnt/2][i] == board[lv][j][i]) {
                    //같은수
                    // board[next][cnt/2][i] += board[lv][j][i];
                    board[next][cnt/2][i]++;
                } else {
                    //다른수
                    cnt++;
                    board[next][cnt/2][i] = board[lv][j][i];
                }
                max_tmp = max(max_tmp, board[next][cnt/2][i]);
                cnt++;
            }
        }
    }
}
void move_down(int lv) {
    for(i=0; i<size; i++) {
        cnt = size*2 - 1;
        for(j=size-1; j>=0; j--) {
            if(board[lv][j][i] > 0) {
                if(cnt%2 == 1) { 
                    //빈칸
                    board[next][cnt/2][i] = board[lv][j][i];
                } else if(board[next][cnt/2][i] == board[lv][j][i]) {
                    //같은수
                    // board[next][cnt/2][i] += board[lv][j][i];
                    board[next][cnt/2][i]++;
                } else {
                    //다른수
                    cnt--;
                    board[next][cnt/2][i] = board[lv][j][i];
                }
                max_tmp = max(max_tmp, board[next][cnt/2][i]);
                cnt--;
            }
        }
    }
}
void move_left(int lv) {
    for(i=0; i<size; i++) {
        cnt = 0;
        for(j=0; j<size; j++) {
            if(board[lv][i][j] > 0) {
                if(cnt%2 == 0) { 
                    //빈칸
                    board[next][i][cnt/2] = board[lv][i][j];
                } else if(board[next][i][cnt/2] == board[lv][i][j]) {
                    //같은수
                    // board[next][i][cnt/2] += board[lv][i][j];
                    board[next][i][cnt/2]++;
                } else {
                    //다른수
                    cnt++;
                    board[next][i][cnt/2] = board[lv][i][j];
                }
                max_tmp = max(max_tmp, board[next][i][cnt/2]);
                cnt++;
            }
        }
    }
}
void move_right(int lv) {
    for(i=0; i<size; i++) {
        cnt = size*2 - 1;
        for(j=size-1; j>=0; j--) {
            if(board[lv][i][j] > 0) {
                if(cnt%2 == 1) { 
                    //빈칸
                    board[next][i][cnt/2] = board[lv][i][j];
                } else if(board[next][i][cnt/2] == board[lv][i][j]) {
                    //같은수
                    // board[next][i][cnt/2] += board[lv][i][j];
                    board[next][i][cnt/2]++;
                } else {
                    //다른수
                    cnt--;
                    board[next][i][cnt/2] = board[lv][i][j];
                }
                max_tmp = max(max_tmp, board[next][i][cnt/2]);
                cnt--;
            }
        }
    }
}

int IsNotUsefull(int lv) {
    if(lv == 0 ) return 0;
    //현재 2^6, 앞으로 3번더 움직일 수 있다면 2^9가 최대기대치 
    // int possible_mxbit = max_tmp<<(FIND_LV - lv);
    u16 possible_mxbit = max_tmp + (FIND_LV - lv);
    if(possible_mxbit <= final_max) return 1;
    return 0;
}

int IsNotChange(int lv) {
    if(lv == 0) return 0;
    for(i=0; i<size; i++)
        if(memcmp(&board[lv][i][0], &board[lv-1][i][0], mem_line_size)) return 0;
    return 1;
}

