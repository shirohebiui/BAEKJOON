#include <stdio.h>
//https://www.acmicpc.net/problem/30502

char data[1001][2];
// 0:P 1:M
// -1 = X // 0 = ? // 1 = O
void input(int M);

int main() {
    int N, M; scanf(" %d %d", &N, &M); // 1 <= M <= 2N
    input(M);
    int min = 0, max = 0;
    for(int i=1; i<=N; i++) {
        if(       data[i][0] == 1 && data[i][1] == -1) { //식물 O 동물 X -> 식물 확정
            min++; max++;
        } else if(data[i][0] == 1 && data[i][1] == 0) {  //식물 O 동물 ? -> 몰라
            max++;
        } else if(data[i][0] == 0 && data[i][1] == 0) {  //식물 ? 동물 ? -> 몰라
            max++;
        } else if(data[i][0] == 0 && data[i][1] == -1) { //식물 ? 동물 X -> 몰라
            max++;
        }
    }
    printf("%d %d\n", min, max);
    return 0;
}

void input(int M) {
    int num, check;
    char mod;
    for(int i=1; i<=M; i++) {
        scanf(" %d %c %d", &num, &mod, &check);
        if(check == 1) {
            if(mod == 'P') data[num][0] = 1;
            else data[num][1] = 1;
        } else {
            if(mod == 'P') data[num][0] = -1;
            else data[num][1] = -1;
        }
    }
}