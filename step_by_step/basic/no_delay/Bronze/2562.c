#include <stdio.h>

int main()
{
    int arr[10];
    int num, max;
    scanf("%d", &arr[1]);
    num=1;
    max = arr[1];
    for(int i=2; i<10;i++)
    {
        scanf("%d", &arr[i]);
        if(max < arr[i])
        {
            max = arr[i];
            num = i;
        }
    }
    printf("%d\n%d\n", max, num);
    return 0;
}