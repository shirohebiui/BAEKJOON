#include <stdio.h>
/*
오늘의 일기 브루트포스를 쓰는 문제를 풀었다.
컴퓨터는 한 10~100만정도이내의 처리량은 쉬운듯하다.
*/

int main()
{
    int N;
    scanf("%d", &N);

    long cnt = 666;
    while(N) {
        long tmp = cnt++;
        while(tmp > 600)
            if(tmp % 1000 == 666) {
                N--;
                break;
            } else {
                tmp/=10;
            }
    }
    printf("%ld\n", cnt-1);
    return 0;
}