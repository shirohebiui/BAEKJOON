#include <stdio.h>
#define MAX 26

int data[MAX][MAX];
int house;

void input_data(int size) {
    char key[MAX];
    for(int i=0; i<size; i++) {
        scanf("%s", key);
        for(int j=0; j<size; j++) {
            data[i][j] = key[j] - '0';
        }
    }
}

void dfs(int row, int col, int size) {
    if(row>=0 && col>=0 && row<size && col<size) {
        if(data[row][col] == 1) {
            house++;
            data[row][col] = 0;
            dfs(row+1, col, size);
            dfs(row-1, col, size);
            dfs(row, col-1, size);
            dfs(row, col+1, size);
        }
    }
}

void print_map(int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            printf("%d", data[i][j]);
        }
        printf("\n");
    }
}

int queue[MAX*MAX];
int front, rear;

void find_and_stack(int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++ ){
            if(data[i][j] == 1) {
                house = 0;
                dfs(i, j, size);
                queue[rear++] = house;
            }
        }
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(int *data, int start, int end) {
    int left = start;
    int right = end;
    int pivot = data[(left + right)/2];

    while(left <= right) {
        if(data[left] < pivot) {
            left++;
        } else if(data[right] > pivot) {
            right--;
        } else {
            swap(&data[left++], &data[right--]);
        }
    }

    if(start < right) {
        sort(data, start, right);
    }
    if(end > left) {
        sort(data, left, end);
    }
}

int main() {
    int size;
    scanf("%d", &size);
    input_data(size);

    //printf("input ok\n");

    find_and_stack(size);

    //print_map(size);
    //printf("map print\n");

    printf("%d\n", rear);
    sort(queue, 0, rear-1);
    while(front < rear) {
        printf("%d\n", queue[front++]);
    }

    //printf("print ok\n");

    return 0;
}