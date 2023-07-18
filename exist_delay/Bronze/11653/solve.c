#include <stdio.h>
/*
https://www.acmicpc.net/problem/11653
소인수분해
소수라는거에 집착해서 소수를 구하려하면 시간초과에 걸린다.
2부터 나누다보면 자연스럽게 소수만 출력할 수 있다.
*/

int main()
{
    long N;
    long tmp=2;
    scanf("%ld", &N);
    while(1)
    {
        while(N%tmp == 0)
        {
            N = N/tmp;
            printf("%ld\n", tmp);
        }
        tmp++;
        if(N==1)
            break;
    }

    return 0;
}