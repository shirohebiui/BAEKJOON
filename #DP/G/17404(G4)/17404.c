#include <stdio.h>
#define min(a, b) (a<b?a:b)
#define INF 1000
void test();
void input();

int house[1000]; //i%1000 0~999
int RGB[1000][3];
int DP[1000][3];
int N;

void dpfunc() { 
    for(int i=1; i<N; i++) {
        DP[i][0] = RGB[i][0] + min(DP[i-1][1], DP[i-1][2]); 
        //R consider prev GB
        DP[i][1] = RGB[i][1] + min(DP[i-1][0], DP[i-1][2]); 
        //G consider prev RB
        DP[i][2] = RGB[i][2] + min(DP[i-1][0], DP[i-1][1]); 
        //B consider prev RG
    }
}

int select() {
    int best = 1000*N;
    for(int select = 0; select < 3; select++) {
        DP[0][select] = RGB[0][select];
        DP[0][(select + 1) % 3] = INF;
        DP[0][(select + 2) % 3] = INF;
        dpfunc();
        //test();
        best = min(best, min(DP[N-1][(select + 1) % 3], DP[N-1][(select + 2) % 3]));
    }
    return best;
}

int main() {
    scanf("%d", &N);
    input();
    printf("%d\n", select());
    return 0;
}

void input() {
    for(int i=0; i<N; i++) {
        for(int color=0; color<3; color++) {
            scanf(" %d", &RGB[i][color]);
        }
    }
}

void test() {
    char ch[4] = "RGB";
    printf("-----test-----\n");
    for(int color=0; color<3; color++)
        printf("%2c  ", ch[color]);
    printf("\n");
    for(int i=0; i<N; i++) {
        for(int color=0; color<3; color++) {
            printf("%3d ", DP[i][color]);
        }
        printf("\n");
    }
    printf("\n");
}