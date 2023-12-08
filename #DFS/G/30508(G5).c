//https://www.acmicpc.net/problem/30508
#include <stdio.h>
#include <string.h>
#define MAX 1000
int map[MAX][MAX];
int sum_y[MAX][MAX];
int sum_x[MAX][MAX];
int sum_size[MAX][MAX];
int N, M; //map size
int h, w; //shose size
void input_data();
void input_water_hole();
void dfs(int r, int c, int high);
int find_cnt();
int check_size(int r, int c);

void test();

int main() {
    input_data();
    input_water_hole(); //set 물빠질수있는곳 1
    printf("%d\n", find_cnt(h, w));
    return 0;
}

void input_data() {
    scanf(" %d %d", &N, &M);
    scanf(" %d %d", &h, &w);
    for(int row = 0; row < N; row++) {
        for(int col = 0; col < M; col++) {
            scanf(" %d", &map[row][col]);
        }
    }
}

void input_water_hole() {
    int hole_cnt; scanf(" %d", &hole_cnt);

    int row, col;
    while(hole_cnt--) {
        scanf(" %d %d", &row, &col);
        dfs(row-1, col-1, -1); //하수구로 부터 가능한 위치 탐색
    }
}

void dfs(int r, int c, int high) { //하수구위치부터 물이 빠질수있는 경우 검토
    if(r < 0 || r >= N || c < 0 || c >= M) return; //out of range
    if(sum_y[r][c] == 1) return; //이미 방문한곳(물이 빠짐이 증명된곳)

    if(map[r][c] >= high) { //같거나 높은칸에서만 물이 들어옴
        sum_y[r][c] = 1;    //물이 빠질수 있는 곳을 1로 표시한다.
        sum_x[r][c] = 1;
        dfs(r+1, c, map[r][c]);
        dfs(r-1, c, map[r][c]);
        dfs(r, c+1, map[r][c]);
        dfs(r, c-1, map[r][c]);
    }
}

int find_cnt() {
    int cnt = 0;
    for(int row = 0; row<N; row++) {
        for(int col = 0; col<M; col++) {
            if(sum_y[row][col]) sum_y[row][col] += sum_y[row-1][col];
            if(sum_x[row][col]) sum_x[row][col] += sum_x[row][col-1];
            if(sum_y[row][col] >= h && sum_x[row][col] >=w) {
                cnt += check_size(row, col);
            }
        }
    }
    return cnt;
}

int check_size(int r, int c) {
    for(int i=0; i<h; i++) {
        if(sum_x[r-i][c] < w) return 0;
    }
    for(int i=0; i<w; i++) {
        if(sum_y[r][c-i] < h) return 0;
    }
    return 1;
}

void test(int map[][MAX]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            printf(" %d", map[i][j]);
        }
        printf("\n");
    }
}