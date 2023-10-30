#include <stdio.h>
/*
1/1
1/2 2/1
    3/1 2/2 1/3
            1/4 2/3 3/2 4/1
짝수일때와 홀수일때를 구별해서 위의 증가하는 규칙을 공식화한다음
횟수를 올릴때마다 count++ 해서 내가 원하는 번호일때 멈출수있게 조건문을 for문 안에 넣는다.
*/
int main()
{
    int X;
    scanf("%d", &X);

    int count=1;
    int i=2;
    if(X == 1)
    {
        printf("%d/%d\n", 1, 1);
    }
    else
    while(1)
    {
        if(i%2 == 0) //짝수일때
        {
            for(int j=1;j<=i;j++)
            {
                count++;
                if(count == X)
                {
                    printf("%d/%d\n",j, i+1-j);
                    break;
                }
            }
        }
        else //홀수일때
        {
            for(int j=1;j<=i;j++)
            {
                count++;
                if(count == X)
                {
                    printf("%d/%d\n", i+1-j, j);
                    break;
                }
            }
        }
        i++;
        if(count == X)
            break;
    }
    return 0;
}