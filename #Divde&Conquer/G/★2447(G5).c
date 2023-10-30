#include <stdio.h>
#include <string.h>
#define MAX 6562 //3^8 = 6561
char star[MAX][MAX];

void init_star(int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            star[i][j] = ' ';
        }
    }
    star[0][0] = '*'; star[0][1] = '*'; star[0][2] = '*';
    star[1][0] = '*'; star[1][1] = ' '; star[1][2] = '*';
    star[2][0] = '*'; star[2][1] = '*'; star[2][2] = '*';
}

void paint(int size) {
    for(int i=0; i<size; i++) {
        //1행
        memmove(&star[i][size], &star[i][0], size);
        memmove(&star[i][size+size], &star[i][0], size);

        //2행
        memmove(&star[i+size][0], &star[i][0], size);
        memmove(&star[i+size][size+size], &star[i][0], size);

        //3행
        memmove(&star[i+size+size][0], &star[i][0], size);
        memmove(&star[i+size+size][size], &star[i][0], size);
        memmove(&star[i+size+size][size+size], &star[i][0], size);
    }
}

void print_all_2D(char arr[][MAX], int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N;
    scanf("%d", &N);
    init_star(N);
    for(int i=3; i<N; i*=3) {
        paint(i);
    }
    print_all_2D(star, N, N);
    return 0;
}