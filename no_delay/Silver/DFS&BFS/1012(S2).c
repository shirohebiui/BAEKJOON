#include <stdio.h>
#define MAX 51

int data[MAX][MAX];
int FLAG;

void input_data(int round) {
    int row, col;
    while(round--) {
        scanf("%d %d", &row, &col);
        data[row][col] = 1;
    }
}

void dfs(int row, int col) {
    if(row>=0 && col>=0 && row<51 && col<51) {
        if(data[row][col] == 1) {
            data[row][col] = 0;
            dfs(row+1, col);
            dfs(row-1, col);
            dfs(row, col-1);
            dfs(row, col+1);
            if(FLAG) FLAG = 0;
        }
    }
}

void print_map(int row, int col) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            printf("%d ", data[i][j]);
        }
    }
}

int find_need_bug(int row, int col) {
    int bug = 0;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++ ){
            if(data[i][j] == 1) {
                FLAG = 1;
                dfs(i, j);
                if(FLAG == 0) bug++;
            }
        }
    }
    return bug;
}

int queue[1000000];
int front, rear;

int main() {
    int test_case;
    scanf("%d", &test_case);

    while(test_case--) {
        int row, col, num_crop, bug=0;
        scanf("%d %d %d", &row, &col, &num_crop);
        input_data(num_crop);
        queue[rear++] = find_need_bug(row, col);
    }
    //printf("input ok\n");

    while(front < rear) {
        printf("%d\n", queue[front++]);
    }
    //printf("print ok\n");

    return 0;
}