#include <stdio.h>
#include <string.h>
#define MAX_SIZE 15
int map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];
int count = 0 , size;

void print_map() {
    for(int i=0; i < size; i++) {
        for(int j=0; j < size; j++) {
            printf(" %d", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int IsValid(int y, int x) {
    int i;
    for(i=0; i<size; i++) {
        if(map[y][i])
            return 0;
    }
    for(i=0; i<size; i++) {
        if(map[i][x])
            return 0;
    }
    //+ +
    for(i=0;y+i<size && x+i<size;i++) {
        if(map[y+i][x+i])
            return 0;
    }
    //- -
    for(i=0;y-i>=0 && x-i>=0;i++) {
        if(map[y-i][x-i])
            return 0;
    }
    //+ -
    for(i=0;y+i<size && x-i>=0;i++) {
        if(map[y+i][x-i])
            return 0;
    }
    //- +
    for(i=0;y-i>=0 && x+i<size;i++) {
        if(map[y-i][x+i])
            return 0;
    }

    //clear
    return 1;
}

void n_queen(int round) {
    //printf("진입\n");
    if(round == size ) {
        //printf("count++\n");
        //print_map();
        count++;
    } else {
        for(int i=0; i < size; i++) {
            if( IsValid(round, i) ) {
                //printf("%d %d check\n", round, i);
                map[round][i] = 1;
                n_queen(round+1);
                map[round][i] = 0;
            }
        }
    }
    //print_map();
}

int main() {
    scanf("%d", &size);
    n_queen(0);
    printf("%d\n", count);
    return 0;
}