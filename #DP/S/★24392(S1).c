#include <stdio.h>
#define MAX 1003
#define mod 1000000007

/*
연산마다 mod로 수를 낮춰줘 해결
*/

long map[MAX][MAX] = {0, };
int y, x;

void write_map() {
    for(int i=1; i<=y; i++) {
        for(int j=1; j<=x; j++) {
            scanf("%ld", &map[i][j]);
        }
    }
}

void print_map() {
    //test용도
    printf("---------------------------\n");
    for(int i=1; i<=y; i++) {
        for(int j=1; j<=x; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

void find_path(int pos_y) {
    for(int i=1; i<=x; i++) {
        if(map[pos_y][i])
            map[pos_y][i] = (map[pos_y-1][i-1] + map[pos_y-1][i] + map[pos_y-1][i+1])%mod;
    }
    if(pos_y<y)
        find_path(pos_y+1);
}

int main() {
    scanf("%d %d", &y, &x);
    write_map();
    //print_map();

    find_path(2);
    //print_map();

    long sum_path = 0;
    for(int i=1; i<=x; i++)
        sum_path += map[y][i] % mod;
    printf("%ld\n", sum_path%mod);
    return 0;
}