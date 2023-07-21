#include <stdio.h>
long count = 0;

int find(int N, int M) {
    if(N==1) {
        count += M;
    }
    if(N>1)
    for(int i=0; i<M; i++)
        find(N-1, i);
}


int main()
{
    int T;
    scanf("%d", &T);
    int N, M;
    while(T--) {
        scanf("%d%d", &N, &M);
        find(N, M);
        printf("%ld\n", count);
        count = 0;
    }
    return 0;
}