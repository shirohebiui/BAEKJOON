#include <stdio.h>
#include <string.h>
#define MAX 101
// 입력시 최대높이를 기록하고 
// level 1 - > 최대높이 까지각 level마다 dfs를 수행해보고
// area의 수를 찾아 리턴
// max_area의 최대치를 갱신하고
// 맵과 area를 초기화하고 반복
int data[MAX][MAX];
int data_b[MAX][MAX];
int size;
int level, area, max_level = 0;

void input_data() {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            scanf(" %d", &data[i][j]);
            data_b[i][j] = data[i][j];
            max_level = max_level > data[i][j] ? max_level : data[i][j];
        }
    }
}

void dfs(int row, int col) {
    if(row>=0 && col>=0 && row<size && col<size) {
        if(data[row][col] > level) {
            data[row][col] = 0;
            dfs(row+1, col);
            dfs(row-1, col);
            dfs(row, col-1);
            dfs(row, col+1);
        }
    }
}

void print_map() {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            printf("%d", data[i][j]);
        }
        printf("\n");
    }
}

void find() {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++ ){
            if(data[i][j] > level) {
                //printf("%d %d\n", i , j);
                area++;
                dfs(i, j);
            }
        }
    }
}

int main() {
    scanf("%d", &size);
    input_data();

    //printf("input ok\n");

    int max_area = 1;
    for(int i=1; i<max_level; i++) {
        area = 0;
        level = i;
        find();
        max_area = max_area > area ? max_area : area;
        // printf("area : %d, level : %d\n", area, i);
        // print_map();
        memcpy(data, data_b, sizeof(int) * MAX * MAX);
    }
    // level = 1;
    // find();
    // max_area = max_area > area ? max_area : area;

    printf("%d\n", max_area);

    return 0;
}