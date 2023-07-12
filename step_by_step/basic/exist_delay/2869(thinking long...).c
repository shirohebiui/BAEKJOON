#include <stdio.h>
#include <stdlib.h>
/*
V가 목표치
1day마다 +A, -B를 한다.
V에 도달하거나 초과하는것이 목표.
V+A, V-B를 반복하면 매우 비효율적으로 반복하기때문에 이를 간소화시켜서 정해진 시간안에 통과해야한다.

먼저 V=V-A를한다. 이따가 반복하는것을 통해 V를 넘으면 그 다음날에 +A를 할경우 본래 목표인 V를 넘기때문이다. 이 V-A를 통해 +A, -B과정에서 V를 초과하는 케이스를 배제한다.

* V<A 인경우를 제외한다.
if문으로 해당 케이스를 빼서 day 를 1로 출력한다.



V-A에 근사한 day를 구하기위해 day = V/(A-B)를 한다.(long형이기 때문에 소숫점은 버려진다.)
그리고 sum = day*(A-B)를 하면 sum에는 V에 최대한 근사한 값이 저장된다.
예를 들어 5 1 11이면
A=5, B=1
V=11-5=6
day = 6/(5-1) = 6/4 = 1
sum = 1*(5-1) = 4

*sum == V일 경우 이미 조건에 도달했기때문에 day+1을 출력한다.
*sum <V일 경우
sum = sum + A - B, day++ 반복한다. 이 연산직후 sum>=V이면 그 day+1이 우리가 원하는 원래 V를 달성한 day이다.


*/
int main()
{
    long A, B, V;
    scanf("%ld %ld %ld", &A, &B, &V);
    
    if(V<=A)
    {
        printf("1\n");
        return 0;
        exit(0);
    }
    V-=A;
    long day = V/(A-B);
    long sum = day*(A-B);
    if(sum<V)
    {
        while(1)
        {
            day++;
            sum+=A-B;
            if(sum>=V)
                break;
        }
        printf("%ld\n", day+1);
    }
    else if(sum == V)
    {
        printf("%ld\n", day+1);
    }
    return 0;
}