#include <stdio.h>
#define min(a, b) (a<b?a:b)
#define INF 1000
void input();

int RGB[1000][3];
int DP[1000][3];
int N;

void dpfunc() {
    for(int i=0; i<N; i++) {
        DP[i][0] = RGB[i][0] + min(DP[i-1][1], DP[i-1][2]);
        //R consider prev G,B
        DP[i][1] = RGB[i][1] + min(DP[i-1][0], DP[i-1][2]);
        //G consider prev R,B
        DP[i][2] = RGB[i][2] + min(DP[i-1][0], DP[i-1][1]);
        //B consider prev R,G
    }
}

int main() {
    scanf("%d", &N);
    input();
    dpfunc();
    int best = min(DP[N-1][2], min(DP[N-1][0], DP[N-1][1]));
    printf("%d\n", best);
    return 0;
}

void input() {
    for(int i=0; i<N; i++) {
        for(int color=0; color<3; color++) {
            scanf(" %d", &RGB[i][color]);
        }
    }
}