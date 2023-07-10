#include <stdio.h>

int main()
{
    int N, X;
    int arr[10000];
    scanf("%d %d", &N, &X);
    for(int i=0; i<N-1; i++)
        scanf("%d ", &arr[i]);
    scanf("%d", &arr[N-1]);

    for(int i=0;i<N;i++)
    {
        if(arr[i] < X)
            printf("%d ", arr[i]);
    }
    printf("\n");
}