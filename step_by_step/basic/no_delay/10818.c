#include <stdio.h>
/*
백준의 int 는 2바이트로 추측
*/
int main()
{
    int N;
    long tmp;
    long max=-1000000;
    long min=1000000;
    scanf("%d", &N);
    for(int i=0; i<N-1; i++)
    {
        scanf("%ld ", &tmp);
        if(arr[i] < min)
            min=arr[i];
        if(arr[i] > max)
            max=arr[i];
    }
    scanf("%ld", &arr[N-1]);
    if(arr[i] < min)
        min=arr[i];
    if(arr[i] > max)
        max=arr[i];

    printf("%ld %ld\n",min, max);
}