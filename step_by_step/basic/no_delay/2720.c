#include <stdio.h>
/*
====문제====
거스름돈의 액수가 주어지면 리암이 줘야할 쿼터(Quarter, $0.25)의 개수, 다임(Dime, $0.10)의 개수,
니켈(Nickel, $0.05)의 개수, 페니(Penny, $0.01)의 개수를 구하는 프로그램을 작성하시오.

거스름돈은 항상 $5.00 이하이고, 손님이 받는 동전의 개수를 최소로 하려고 한다.
예를 들어, $1.24를 거슬러 주어야 한다면, 손님은 4쿼터, 2다임, 0니켈, 4페니를 받게 된다.
============
1line input T (test case)
2line~ input C (거스름돈, 센트 단위)
1달러 = 100센트

진법과 비슷하다 쿼터>다임>니켈>페니 순으로 각기 다른 진법으로 표현한다 생각하고 풀어보면되겠다.
C = C - 쿼터*X 25센트
C = C - 다임*X 10센트
C = C - 니켈*X 5센트
C = C - 페니*X 1센트
C == 0
이런식이 되면 되겠다.

*/
int main()
{
    int T;
    scanf("%d", &T);

    for(int i=0;i<T;i++)
    {
        int C;
        scanf("%d", &C);
        int Quarter=0, Dime=0, Nickel=0, Penny=0; //배열로 간소화가능하지만 가시성을 위해 일단 이렇게해놓고 풀겠다.
        while(C>=25)
        {
            C-=25;
            Quarter++;
        }
        while(C>=10)
        {
            C-=10;
            Dime++;
        }
        while(C>=5)
        {
            C-=5;
            Nickel++;
        }
        while(C!=0)
        {
            C-=1;
            Penny++;
        }

        printf("%d %d %d %d\n", Quarter, Dime, Nickel, Penny);
    }
    return 0;
}