#include <stdio.h>
#define MAX 101

char tmp[MAX];
int RGB[MAX][MAX];
int RRB[MAX][MAX];

int size;

void input_data() {
    for(int i=0; i<size; i++) {
        scanf("%s", tmp);
        for(int j=0; j<size; j++) {
            if(tmp[j] == 'R') {
                RGB[i][j] = 1;
                RRB[i][j] = 1;
            } else if(tmp[j] == 'G') {
                RGB[i][j] = 2;
                RRB[i][j] = 1;
            } else if(tmp[j] == 'B') {
                RGB[i][j] = 3;
                RRB[i][j] = 2;
            }
        }
    }
}

void dfs(int data[][MAX], int i, int j, int key) {
    if(i>=0 && j>=0 && i<size && j<size) {
        if(data[i][j] == key) {
            data[i][j] = 0;
            dfs(data, i, j+1, key);
            dfs(data, i, j-1, key);
            dfs(data, i+1, j, key);
            dfs(data, i-1, j, key);
        }
    }
}

int COUNT_AREA(int data[][MAX]) {
    int count = 0;
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(data[i][j] == 1) {
                dfs(data, i, j, 1);
                count++;
            } else if(data[i][j] == 2) {
                dfs(data, i, j, 2);
                count++;
            } else if(data[i][j] == 3) {
                dfs(data, i, j, 3);
                count++;
            }
        }
    }
    return count;
}


int main() {
    scanf("%d", &size);
    input_data();

    printf("%d %d\n", COUNT_AREA(RGB), COUNT_AREA(RRB));

    return 0;
}