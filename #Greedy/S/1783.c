#include <stdio.h>

int main() {
    int N, M; scanf(" %d %d", &N, &M);
    int result;
    if(N==1) {          //한줄
        result = 1;
    } else if(N==2) {   //두줄
        if(M<=7) result = (M+1)/2; //1 + (M-1)/2
        else     result = 4;
    } else {            //세줄
        if(M<=4) result = M;
        else if(M<=6) result = 4;
        else result = 3 + M - 5;
    }
    printf("%d\n", result);
    return 0;
}