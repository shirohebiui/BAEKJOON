#include <stdio.h>

unsigned char map[100][100];

int main() {
    //input
    int H,W; scanf("%d %d", &H, &W);
    for(int i=0; i<H; i++) {
        scanf("%s", map[i]);
        for(int j=0; j<W; j++) {
            if(map[i][j] == '.') map[i][j] = 0;
            if(map[i][j] == 'c') map[i][j] = 1;
        }
    }
    //moving cloud
    for(int i=0; i<H; i++) {
        for(int j=0; j+1<W; j++) {
            if(map[i][j] && map[i][j+1] == 0) {
                map[i][j+1] += 1+map[i][j];
            }
        }
    }
    //print map
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            printf("%d ",map[i][j]-1);
        }
        printf("\n");
    }
    return 0;
}