#include <stdio.h>

int main()
{
    int N, v, sum=0;
    int arr[220];
    scanf("%d", &N);
    for(int i=0; i<N-1; i++)
        scanf("%d ", &arr[i]);
    scanf("%d", &arr[N-1]);

    //찾으려는 값
    scanf("%d", &v);
    for(int i=0;i<N;i++)
    {
        if(arr[i] == v)
            sum++;
    }
    printf("%d\n", sum);
}