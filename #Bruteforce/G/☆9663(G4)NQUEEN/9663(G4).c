#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 15
int map[MAX_SIZE];
int count = 0 , size;

int IsValid(int y) {
    for(int i=0; i<y; i++) {
        if(map[y] == map[i] || abs_(map[y] - map[i]) == abs_(y - i))
            return 0;
    }
    return 1;
}

void n_queen(int y) {
    if(y == size ) {
        count++;
    } else {
        for(int x=0; x < size; x++) {
            map[y] = x;
            if( IsValid(y) ) {
                n_queen(y+1);
            }
        }
    }
}

int main() {
    scanf("%d", &size);
    n_queen(0);
    printf("%d\n", count);
    return 0;
}