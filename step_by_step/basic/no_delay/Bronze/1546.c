#include <stdio.h>

int main()
{
    int M=0; //자기 점수중 최대값
    int N;
    int arr[1000];
    scanf("%d\n", &N);
    for(int i=0;i<N;i++)
    {
        scanf("%d", &arr[i]);
        if(M<arr[i])
            M=arr[i];
    }
    
    // 점수/M *100
    float sum;
    for(int i=0;i<N;i++)
        sum += ((float)arr[i]/(float)M)*100;
    printf("%.4f\n",sum/N);
}