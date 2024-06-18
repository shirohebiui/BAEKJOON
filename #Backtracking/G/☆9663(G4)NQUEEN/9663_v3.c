#include <stdio.h>
#include <string.h>
#define MAX_SIZE 15
int visited[MAX_SIZE][MAX_SIZE];
int count = 0 , size;

void painting(int data[][MAX_SIZE], int y, int x) {
    int i;
    for(i=0; i<size; i++) {
        data[y][i] = 1;
    }
    for(i=0; i<size; i++) {
        data[i][x] = 1;
    }
    //+ +
    for(i=0;y+i<size && x+i<size;i++) {
        data[y+i][x+i] = 1;
    }
    //- -
    for(i=0;y-i>=0 && x-i>=0;i++) {
        data[y-i][x-i] = 1;
    }
    //+ -
    for(i=0;y+i<size && x-i>=0;i++) {
        data[y+i][x-i] = 1;
    }
    //- +
    for(i=0;y-i>=0 && x+i<size;i++) {
        data[y-i][x+i] = 1;
    }
}

int counting(int data[][MAX_SIZE]) {
    for(int i=0; i < size; i++) {
        for(int j=0; j < size; j++) {
            if(data[i][j]==0)
                return 0;
        }
    }
    return 1;
}

void print_data() {
    for(int i=0; i < size; i++) {
        for(int j=0; j < size; j++) {
            printf(" %d", visited[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int IsFULL() {
    int tmp[MAX_SIZE][MAX_SIZE];
    memmove(tmp, visited, 4 * MAX_SIZE * MAX_SIZE);
    for(int i=0; i < size; i++) {
        for(int j=0; j < size; j++) {
            if(visited[i][j] == 1)
                painting(tmp, i, j);
        }
    }
    if(counting(tmp)) {
        return 1;
    } else {
        return 0;
    }
}

int IsValid(int y, int x) {
    int i;
    for(i=0; i<size; i++) {
        if(visited[y][i])
            return 0;
    }
    for(i=0; i<size; i++) {
        if(visited[i][x])
            return 0;
    }
    //+ +
    for(i=0;y+i<size && x+i<size;i++) {
        if(visited[y+i][x+i])
            return 0;
    }
    //- -
    for(i=0;y-i>=0 && x-i>=0;i++) {
        if(visited[y-i][x-i])
            return 0;
    }
    //+ -
    for(i=0;y+i<size && x-i>=0;i++) {
        if(visited[y+i][x-i])
            return 0;
    }
    //- +
    for(i=0;y-i>=0 && x+i<size;i++) {
        if(visited[y-i][x+i])
            return 0;
    }

    //clear
    return 1;
}
void mapping(int y, int x, int obj) {
    if(obj==size) {
        if(IsFULL())
            count++;
        //print_data();
    } else if(obj < size) {
        for(int i=y; i < size; i++) {
            for(int j=0; j < size; j++) {
                if(IsValid(i, j) == 1 && visited[i][j] == 0) {
                    visited[i][j] = 1;
                    mapping(i, j, obj+1);
                    visited[i][j] = 0;
                }
            }
        }
    }
}
int main() {
    scanf("%d", &size);
    mapping(0,0,0);
    printf("%d\n", count);
    return 0;
}