#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
두 원의 관계를 묻는 문제이다.
합동일 경우 -1
원이 교접하지 않을 경우 0
원이 내접,외접할 경우 1
교접할경우 2
를 출력하면 되겠다. root를 구하는건 math라이브러리의 도움을 받자.
*/
int main()
{
    int T;
    scanf("%d", &T);
    for(int i=0; i<T; i++)
    {
    int x1, x2, y1, y2, r1, r2;
    scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
    double T = sqrt(abs_(x1-x2)*abs_(x1-x2)+abs_(y1-y2)*abs_(y1-y2));
    //printf("T: %d\n", T);
    if(x1==x2 && y1==y2 && r1==r2) //동접
        printf("-1\n");
    else if(x1==x2 && y1==y2 ) //동심원
        printf("0\n");
    else if(T>r1+r2) //외부 만나지않음
        printf("0\n");
    else if((T+r1<r2) || (T+r2<r1)) //내부 만나지않음
        printf("0\n");
    else if((T+r1 == r2) || (T+r2 == r1))//내접
        printf("1\n");
    else if(T==r1+r2) //외접
        printf("1\n");
    else if(T>0 && T<r1+r2) //교접
        printf("2\n");
    }
    return 0;
}