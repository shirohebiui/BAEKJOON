#include <stdio.h>
#include <stdlib.h>
#define MAX 10000000
int data[MAX*2 + 1];

int main()
{
    int N; scanf("%d", &N);
    long num;
    while(N--) {
        scanf(" %ld", &num);
        data[num+MAX]++;
    }

    int M; scanf("%d", &M);
    while(M--) {
        scanf(" %ld", &num);
        printf("%d ", data[num+MAX]);
    }
    printf("\n");
	return 0;
}