#include <stdio.h>
#include <string.h>

char board[4002][4002];

int isSafe(int y, int x) {
    return (y<4002 && y>=0 && x<4002 && x>=0);
}

int main() {
    int len, loop; scanf("%d %d", &len, &loop);
    int py = 2000, px = 2000;
    while(len--) {
        char mv; scanf(" %c", &mv);
        if(mv == 'U') py++;
        else if(mv == 'D') py--;
        else if(mv == 'R') px++;
        else if(mv == 'L') px--;
        board[py][px] = 1;
    }
    int gy = 2000-py, gx= 2000-px;
    int y = 2000, x = 2000;
    int cnt = 0;
    while(loop--) {
        if(isSafe(y, x)) {
            if(board[y][x]) {
                printf("YES\n");
                return 0;
            }
            // cnt += board[y][x];
        } else {
            break;
        }
        y += gy; x+= gx;
    }
    printf("NO\n");
    return 0;
}