#include <stdio.h>

void Eratos(int *arr, int n) {
    int i, j;
    for(i=2; i<=n; i++) {
        for(j=i*2; j<=n; j+=i) {
            if(arr[j] == 0) { //저장하는 연산을 여러번 하지 않기위해
                arr[j] = 1;
                //printf("%d\n", i*j);
            }
        }
    }
}

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    int data[1000001] = {0, 1, };
    Eratos(data, N);
    /* for(int i=1; i<=N; i++)
        printf("%d :%d\n", i, data[i]); */
    for(int i=M; i<=N; i++) {
        if(data[i] == 0) {
            printf("%d\n", i);
        }
    }
    return 0;
}