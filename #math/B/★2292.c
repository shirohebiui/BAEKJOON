#include <stdio.h>
/*
N==1일 경우를 체크하지 못하는 반복문이었다.
N==1인 경우까지 포함하는 식으로 바꾸기보다 그냥 시작시 조건문을 통해 처리했다.
*/
int main()
{
    long N;
    scanf("%ld", &N);
    int count = 0;
    long room = 1;
    if(N==1)
        printf("1\n");
    else
    {
    while(N>room)
    {
        room+=6*count++;
        //printf("%ld\n", room);
    }
    printf("%d\n", count);

    }
    return 0;
}