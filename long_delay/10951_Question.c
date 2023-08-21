#include <stdio.h>
/*
1.실패
입력받는 값의 정의를 제대로 해야한다.
입력은 아무거나 들어올수있지만 이를 걸러 받아야하기떄문에
scanf의 반환값을 조건문에 넣어 해결을 시도해보려한다.
->해결

의문 :  \ 라는 값을 입력시 임의의 출력값이 무한히 출력된다 왜그럴까?
*/

int main()
{
    int a,b;
    while(1)
    {
        if(scanf("%d%d", &a, &b) == EOF)
            break;
        printf("%d\n", a + b);
        printf("%d %d\n", a, b);
        //fflush(stdin);
    }
    return 0;
}