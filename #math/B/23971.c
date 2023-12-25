#include <stdio.h>

int main() {
    int H, W; scanf(" %d %d", &H, &W);
    int N, M; scanf(" %d %d", &N, &M);
    int sum = W/(M+1);
    if(W%(M+1) != 0) sum++;
    if(H%(N+1) != 0)
        sum *= H/(N+1) + 1;
    else
        sum *= H/(N+1);
    printf("%d\n", sum);
    return 0;
}